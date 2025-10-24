import sys
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import tkinter as tk
from tkinter import messagebox
from math import sqrt
import time
import threading
import serial
import pandas as pd

csv_file = "/home/globalkorea/ros2_ws/src/globalkorea_usv_ros2/gkusv_driver/gkusv_driver/data/boat_control_setting.csv"

class ROS2Publisher(Node):
    def __init__(self):
        super().__init__('ui_publisher')
        # self.contol_publisher = self.create_publisher(String, '/xy_value_input', 10)
        self.save_publisher = self.create_publisher(String, '/xy_value_input', 10)

    # def publish_control(self, x, y):
    #     msg = String()
    #     msg.data = f"2,{x},{y}"
    #     self.contol_publisher.publish(msg)
    #     self.get_logger().info(f'Published: {msg.data}')

    def publish_save(self,boat_index, x, y):
        msg = String()
        # msg.data = f"1,{x},{y}"
        msg.data = f"{boat_index},{x},{y}"
        self.save_publisher.publish(msg)
        self.get_logger().info(f'Published: {msg.data}')

# def open_ser():
#     ser = serial.Serial("/dev/ttyACM0",9600)
#     return ser

# def convert_voltage(voltage):
#     new_voltage = int((voltage/5.0) * 255)
#     return max(0, min(255, new_voltage))


# def send_voltage_2_adu(ser, x, y):
#     x_voltage = convert_voltage(x)
#     y_voltage = convert_voltage(y)
#     # x_voltage = scale_value(x)
#     # y_voltage = scale_value(y)
#     command = f"{x_voltage},{y_voltage}\n"
#     if ser is not None:
#         ser.write(command.encode()) # 아두이노에 정보 전달
#     return command


class ControlGUI:
    def __init__(self, root, ser, top_x, down_x, left_y, right_y, publish):
        self.ser = ser
        self.root = root
        self.publish = publish
        self.root.title("컨트롤러")

        # 최소 윈도우 크기 설정
        self.root.minsize(300, 300)
        
        # 초기 캔버스 크기 설정
        self.canvas_size = 500  # 기본 캔버스 크기
        
        # 메인 프레임 생성 및 설정
        self.main_frame = tk.Frame(root)
        self.main_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

        # 모드 선택 버튼 프레임
        self.button_frame = tk.Frame(self.main_frame)
        self.button_frame.pack(pady=5)

        # 토글 버튼 변수
        self.mode = tk.StringVar(value="joystick")

        # 토글 버튼 생성
        tk.Radiobutton(self.button_frame, text="조이스틱", variable=self.mode,
                       value="joystick", command=self.switch_mode).pack(side=tk.LEFT, padx=5)
        tk.Radiobutton(self.button_frame, text="버튼", variable=self.mode,
                       value="button", command=self.switch_mode).pack(side=tk.LEFT, padx=5)
        
        # 전압 설정 구간
        self.grid_size = 9
        self.top_x = top_x
        self.down_x = down_x
        self.left_y = left_y
        self.right_y = right_y
        self.create_settings_interface()

        # 캔버스를 담을 프레임 생성 (정사각형 유지를 위한 컨테이너)
        self.canvas_frame = tk.Frame(self.main_frame)
        self.canvas_frame.pack(expand=True)
        
        # 캔버스 생성 및 설정
        self.canvas = tk.Canvas(self.canvas_frame, bg='white', width=self.canvas_size, height=self.canvas_size)
        self.canvas.grid(row=0, column=0)

        # 좌표 범위 설정
        self.center_x = (self.top_x + self.down_x) / 2
        self.center_y = (self.left_y + self.right_y) / 2

        # 그리드 설정
        self.selected_button = None

        # 조이스틱 설정
        self.circle_radius_ratio = 0.04  # 캔버스 크기에 대한 비율
        self.circle_radius = int(self.canvas_size * self.circle_radius_ratio)
        self.current_x = self.center_x
        self.current_y = self.center_y
        self.stick_line = None
        self.circle = None

        # 좌표 표시 레이블
        self.coord_label = tk.Label(self.main_frame)
        self.coord_label.pack()

        # 애니메이션 제어 변수
        self.animation_thread = None
        self.is_returning = False

        # 리사이즈 이벤트 바인딩
        self.root.bind('<Configure>', self.on_window_resize)
        
        # 초기 모드 설정
        self.switch_mode()


   
    #------ 상하 좌우 설정 -----------------------
    def create_settings_interface(self):
        """설정 인터페이스를 생성하는 메서드"""
        # Settings Frame 생성
        self.settings_frame = tk.LabelFrame(self.main_frame, text="설정", padx=10, pady=5)
        self.settings_frame.pack(after=self.button_frame, padx=10, pady=5, fill="x")
        
        # 수평 배치를 위한 컨테이너 프레임
        container_frame = tk.Frame(self.settings_frame)
        container_frame.pack(fill="x", expand=True)

        tk.Label(self.settings_frame, text="Boat Index:").pack(side=tk.LEFT, padx=5)
        self.boat_index_var = tk.StringVar(value='1')
        self.boat_index_entry = tk.Entry(self.settings_frame, textvariable=self.boat_index_var, width=5)
        self.boat_index_entry.pack(side=tk.LEFT, padx=5)
        
        # Grid 설정
        grid_frame = tk.LabelFrame(container_frame, text="그리드 설정", padx=5, pady=5)
        grid_frame.pack(side=tk.LEFT, padx=5, pady=5, fill="both", expand=True)
        
        # Grid Size Input with Spinbox
        tk.Label(grid_frame, text="그리드 크기:").pack(side=tk.LEFT, padx=5)
        self.grid_size_var = tk.StringVar(value=str(self.grid_size))
        self.grid_size_spinbox = tk.Spinbox(
            grid_frame, 
            from_=3, 
            to=15,
            width=5,
            textvariable=self.grid_size_var,
            command=self.on_grid_size_change
        )
        self.grid_size_spinbox.pack(side=tk.LEFT, padx=5)
        
        # X 좌표 설정
        x_frame = tk.LabelFrame(container_frame, text="X축 설정", padx=5, pady=5)
        x_frame.pack(side=tk.LEFT, padx=5, pady=5, fill="both", expand=True)
        
        tk.Label(x_frame, text="상단 X:").grid(row=0, column=0, sticky="e", padx=5)
        self.top_x_entry = tk.Entry(x_frame, width=10)
        self.top_x_entry.grid(row=0, column=1, padx=5, pady=2)
        self.top_x_entry.insert(0, str(self.top_x))
        
        tk.Label(x_frame, text="하단 X:").grid(row=1, column=0, sticky="e", padx=5)
        self.down_x_entry = tk.Entry(x_frame, width=10)
        self.down_x_entry.grid(row=1, column=1, padx=5, pady=2)
        self.down_x_entry.insert(0, str(self.down_x))
        
        # Y 좌표 설정
        y_frame = tk.LabelFrame(container_frame, text="Y축 설정", padx=5, pady=5)
        y_frame.pack(side=tk.LEFT, padx=5, pady=5, fill="both", expand=True)
        
        tk.Label(y_frame, text="좌측 Y:").grid(row=0, column=0, sticky="e", padx=5)
        self.left_y_entry = tk.Entry(y_frame, width=10)
        self.left_y_entry.grid(row=0, column=1, padx=5, pady=2)
        self.left_y_entry.insert(0, str(self.left_y))
        
        tk.Label(y_frame, text="우측 Y:").grid(row=1, column=0, sticky="e", padx=5)
        self.right_y_entry = tk.Entry(y_frame, width=10)
        self.right_y_entry.grid(row=1, column=1, padx=5, pady=2)
        self.right_y_entry.insert(0, str(self.right_y))
        
        # Apply Button
        self.apply_button = tk.Button(self.settings_frame, text="적용", command=self.apply_settings)
        self.apply_button.pack(pady=5)

    def on_grid_size_change(self):
        """그리드 크기 변경 시 호출되는 메서드"""
        try:
            new_size = int(self.grid_size_var.get())
            if 3 <= new_size <= 15:  # 유효한 범위인지 확인
                self.grid_size = new_size
                self.switch_mode()  # 화면 갱신
        except ValueError:
            self.grid_size_var.set(str(self.grid_size))  # 잘못된 입력시 이전 값으로 복원

    def apply_settings(self):
        """설정값을 적용하는 메서드"""
        try:
            # 입력값 검증 및 적용
            new_grid_size = int(self.grid_size_var.get())
            new_top_x = float(self.top_x_entry.get())
            new_down_x = float(self.down_x_entry.get())
            new_left_y = float(self.left_y_entry.get())
            new_right_y = float(self.right_y_entry.get())
            
            # 값의 유효성 검사
            if not (3 <= new_grid_size <= 15):
                raise ValueError("그리드 크기는 3에서 15 사이여야 합니다")
            
            # 값 적용
            self.grid_size = new_grid_size
            self.top_x = new_top_x
            self.down_x = new_down_x
            self.left_y = new_left_y
            self.right_y = new_right_y
            
            # 중심점 재계산
            self.center_x = (self.top_x + self.down_x) / 2
            self.center_y = (self.left_y + self.right_y) / 2
            
            # 현재 모드에 따라 화면 갱신
            self.switch_mode()

            boat_index = int(self.boat_index_var.get())
            new_x_top = float(self.top_x)
            new_x_bottom = float(self.down_x)
            new_y_left = float(self.left_y)
            new_y_right = float(self.right_y)
            
            df = pd.read_csv(csv_file)
            if boat_index in df["boat_index"].values:
                df.loc[df["boat_index"] == boat_index, "x_top"] = new_x_top
                df.loc[df["boat_index"] == boat_index, "x_bottom"] = new_x_bottom
                df.loc[df["boat_index"] == boat_index, "y_left"] = new_y_left
                df.loc[df["boat_index"] == boat_index, "y_right"] = new_y_right
            else:
                new_row = {"boat_index": boat_index, "x_top": new_x_top, "x_bottom": new_x_bottom,
                           "y_left": new_y_left, "y_right": new_y_right}
                df = pd.concat([df, pd.DataFrame([new_row])], ignore_index=True)
            df.to_csv(csv_file, index=False)
            
            messagebox.showinfo("성공", "설정이 성공적으로 적용되었습니다!")
        except ValueError as e:
            messagebox.showerror("오류", "올바른 숫자를 입력해주세요!")
    #--------------------------------

    def on_window_resize(self, event):
        # 윈도우 크기가 변경될 때만 처리
        if event.widget == self.root:
            # 패딩을 고려한 가능한 크기 계산
            available_width = self.main_frame.winfo_width() - 20
            available_height = self.main_frame.winfo_height() - 60
            
            # 정사각형을 위해 더 작은 값 선택
            new_size = min(available_width, available_height)
            self.canvas_size = max(new_size, 300)  # 최소 300x300 보장
            
            # 캔버스 프레임 크기도 정사각형으로 설정
            self.canvas_frame.configure(width=self.canvas_size, height=self.canvas_size)
            # 프레임 크기 조정 허용
            self.canvas_frame.grid_propagate(False)
            
            # 캔버스 크기 업데이트
            self.canvas.configure(width=self.canvas_size, height=self.canvas_size)
                
            # 원의 반지름 업데이트
            self.circle_radius = int(self.canvas_size * self.circle_radius_ratio)

            # coord_label 폰트 크기 업데이트
            coord_font_size = min(20, int(self.canvas_size / 60))
            self.coord_label.config(font=('Arial', coord_font_size))
                
            # 현재 모드에 따라 화면 다시 그리기
            self.switch_mode()

            # 강제로 크기 업데이트
            self.canvas_frame.update_idletasks()

        

    def setup_joystick_mode(self):
        self.canvas.delete("all")
        self.draw_background()
        self.draw_joystick(self.current_x, self.current_y)
        self.canvas.bind('<B1-Motion>', self.on_drag)
        self.canvas.bind('<Button-1>', self.on_click)
        self.canvas.bind('<ButtonRelease-1>', self.on_release)

    def setup_button_mode(self):
        self.canvas.delete("all")
        self.canvas.unbind('<B1-Motion>')
        self.canvas.unbind('<Button-1>')
        self.canvas.unbind('<ButtonRelease-1>')

        button_width = self.canvas_size / self.grid_size
        button_height = self.canvas_size / self.grid_size
        
        # 폰트 크기 조정
        font_size = min(20, int(self.canvas_size / 70))

        center_i = self.grid_size // 2
        center_j = self.grid_size // 2

        # x축과 y축의 범위 계산 (top->down, left->right)
        x_step = (self.top_x - self.down_x) / (self.grid_size - 1)  # 10 → 0
        y_step = (self.right_y - self.left_y) / (self.grid_size - 1)  # 2 → 5

        for i in range(self.grid_size):  # i는 열 번호 (좌->우)
            for j in range(self.grid_size):  # j는 행 번호 (상->하)
                x1 = i * button_width
                y1 = j * button_height
                x2 = (i + 1) * button_width
                y2 = (j + 1) * button_height

                # 실제 x, y 좌표 계산
                # x값은 행(j)에 따라 변화 (위에서 아래로 10→0)
                coord_x = self.top_x - (j * x_step)
                # y값은 열(i)에 따라 변화 (왼쪽에서 오른쪽으로 2→5)
                coord_y = self.left_y + (i * y_step)

                # 정규화된 좌표 계산 (-2.5 ~ 2.5 범위)
                normalized_x = 2.5 - (j * 5.0 / (self.grid_size - 1))  # 위->아래로 2.5→-2.5
                normalized_y = -2.5 + (i * 5.0 / (self.grid_size - 1))  # 좌->우로 -2.5→2.5

                button_tag = f'button_{i}_{j}'
                fill_color = 'yellow' if (i == center_i and j == center_j) else 'lightgray'

                self.canvas.create_rectangle(
                    x1, y1, x2, y2,
                    fill=fill_color,
                    activefill='gray',
                    tags=button_tag
                )

                self.canvas.create_text(
                    (x1 + x2) / 2, (y1 + y2) / 2,
                    text=f'({coord_x:.1f}, {coord_y:.1f})\n({normalized_x:.1f}, {normalized_y:.1f})',
                    font=('Arial', font_size),
                    tags=(button_tag, f'text_{button_tag}')
                )

                self.canvas.tag_bind(
                    button_tag, 
                    '<Button-1>',
                    lambda e, x=coord_x, y=coord_y, nx=normalized_x, ny=normalized_y, tag=button_tag: self.on_grid_button_click(x, y, nx, ny, tag)
                )

        if not self.selected_button:
            self.selected_button = f'button_{center_i}_{center_j}'


    #---- 조이스틱 ---

    def scale_to_canvas(self, x, y):
        """실제 좌표를 캔버스 좌표로 변환"""
        # x축과 y축의 범위 계산
        x_range = self.top_x - self.down_x  # 10 - 0 = 10
        y_range = self.right_y - self.left_y  # 5 - 2 = 3
        
        # x 좌표 변환 (x가 10→0으로 갈 때 canvas는 0→height로)
        canvas_y = ((self.top_x - x) / x_range) * self.canvas_size
        
        # y 좌표 변환 (y가 2→5로 갈 때 canvas는 0→width로)
        canvas_x = ((y - self.left_y) / y_range) * self.canvas_size
        
        return canvas_x, canvas_y

    def scale_to_coordinates(self, canvas_x, canvas_y):
        """캔버스 좌표를 실제 좌표로 변환"""
        # x축과 y축의 범위 계산
        x_range = self.top_x - self.down_x  # 10 - 0 = 10
        y_range = self.right_y - self.left_y  # 5 - 2 = 3
        
        # y 좌표 변환 (canvas 0→height가 x 10→0에 대응)
        x = self.top_x - (canvas_y / self.canvas_size) * x_range
        
        # x 좌표 변환 (canvas 0→width가 y 2→5에 대응)
        y = self.left_y + (canvas_x / self.canvas_size) * y_range
        
        return x, y

    def draw_background(self):
        # 테두리 사각형
        self.canvas.create_rectangle(0, 0, self.canvas_size, self.canvas_size, outline='black')

        # 격자 그리기 (선택사항)
        steps = 10
        for i in range(steps + 1):
            # 수직선
            x = i * self.canvas_size / steps
            self.canvas.create_line(x, 0, x, self.canvas_size, fill='lightgray')
            # 수평선
            y = i * self.canvas_size / steps
            self.canvas.create_line(0, y, self.canvas_size, y, fill='lightgray')

        # 중심점 표시
        center_canvas_x, center_canvas_y = self.scale_to_canvas(self.center_x, self.center_y)
        self.canvas.create_oval(
            center_canvas_x - 5, center_canvas_y - 5,
            center_canvas_x + 5, center_canvas_y + 5,
            fill='gray'
        )

    def draw_joystick(self, x, y):
        # 현재 위치를 캔버스 좌표로 변환
        canvas_x, canvas_y = self.scale_to_canvas(x, y)
        # 중심점을 캔버스 좌표로 변환
        center_canvas_x, center_canvas_y = self.scale_to_canvas(self.center_x, self.center_y)

        # 기존 요소들 삭제
        if self.stick_line:
            self.canvas.delete(self.stick_line)
        if self.circle:
            self.canvas.delete(self.circle)

        # 중심점에서 현재 위치까지 선 그리기
        self.stick_line = self.canvas.create_line(
            center_canvas_x, center_canvas_y,
            canvas_x, canvas_y,
            width=max(1, int(self.canvas_size / 150)),
            fill='blue'
        )

        # 현재 위치에 원 그리기
        self.circle = self.canvas.create_oval(
            canvas_x - self.circle_radius,
            canvas_y - self.circle_radius,
            canvas_x + self.circle_radius,
            canvas_y + self.circle_radius,
            fill='red'
        )

        # 좌표 표시 업데이트
        normalized_x, normalized_y = self.get_normalized_coord(x, y)
        self.update_coordinates(x, y, normalized_x, normalized_y)
    #----------------

    def switch_mode(self):
        if self.mode.get() == "joystick":
            self.setup_joystick_mode()
        else:
            self.setup_button_mode()

    def get_normalized_coord(self, x, y):
        """
        실제 좌표를 정규화된 좌표(-2.5 ~ 2.5)로 변환
        사용자가 정의한 범위를 기준으로 정규화
        """
        # x 좌표 정규화
        x_min = min(self.top_x, self.down_x)
        x_max = max(self.top_x, self.down_x)
        x_normalized = -2.5 + ((x - x_min) / (x_max - x_min)) * 5.0

        # y 좌표 정규화
        y_min = min(self.left_y, self.right_y)
        y_max = max(self.left_y, self.right_y)
        y_normalized = -2.5 + ((y - y_min) / (y_max - y_min)) * 5.0
    
        return x_normalized, y_normalized


    def update_coordinates(self, x, y, nx=None, ny=None):
        if nx is None and ny is None:
            nx, ny = self.get_normalized_coord(x, y)

        self.coord_label.config(text=f"원본: ({x:.1f}, {y:.1f}), 정규화: ({nx:.1f}, {ny:.1f})")
        ####################################################
        #
        # cmd = send_voltage_2_adu(self.ser, x, y)
        # print(cmd)
        ####################################################
        self.publish.publish_save(self.boat_index_var.get(), nx, ny)
        # self.publish.publish_control(x, y)
        print(f"send_save:{self.boat_index_var.get()}, {nx},{ny}")
        # print(f"send_control:{x},{y}")

    def stop():
        self.publish.publish_save(self.boat_index_var.get(), 0, 0)
        # self.publish.publish_control(2.5, 2.5)

    def on_grid_button_click(self, x, y, nx, ny, button_tag):
        if self.selected_button:
            self.canvas.itemconfig(self.selected_button, fill='lightgray')
            self.canvas.itemconfig(f'text_{self.selected_button}', fill='black')

        self.canvas.itemconfig(button_tag, fill='yellow')
        self.canvas.itemconfig(f'text_{button_tag}', fill='blue')
        self.selected_button = button_tag

        self.update_coordinates(x, y, nx, ny)

    def on_drag(self, event):
        if self.is_returning:
            return

        # 이벤트 좌표를 캔버스에 상대적인 좌표로 변환
        canvas_x = self.canvas.winfo_pointerx() - self.canvas.winfo_rootx()
        canvas_y = self.canvas.winfo_pointery() - self.canvas.winfo_rooty()

        # 캔버스 범위로 제한
        canvas_x = max(0, min(self.canvas_size, canvas_x))
        canvas_y = max(0, min(self.canvas_size, canvas_y))

        x, y = self.scale_to_coordinates(canvas_x, canvas_y)
        x = max(min(self.down_x, self.top_x), min(max(self.down_x, self.top_x), x))
        y = max(min(self.right_y, self.left_y), min(max(self.right_y, self.left_y), y))

        self.current_x = x
        self.current_y = y
        self.draw_joystick(x, y)
        self.update_coordinates(x, y)

    def on_click(self, event):
        self.is_returning = False
        self.on_drag(event)

    def on_release(self, event):
        self.is_returning = True
        if self.animation_thread is None or not self.animation_thread.is_alive():
            self.animation_thread = threading.Thread(target=self.return_to_center)
            self.animation_thread.start()

    def return_to_center(self):
        steps = 20
        start_x = self.current_x
        start_y = self.current_y
        dx = (self.center_x - start_x) / steps
        dy = (self.center_y - start_y) / steps

        for i in range(steps):
            if not self.is_returning:
                break

            self.current_x = start_x + dx * (i + 1)
            self.current_y = start_y + dy * (i + 1)

            self.root.after(0, self.draw_joystick, self.current_x, self.current_y)
            self.root.after(0, self.update_coordinates, self.current_x, self.current_y)
            time.sleep(0.02)

        if self.is_returning:
            self.current_x = self.center_x
            self.current_y = self.center_y
            self.root.after(0, self.draw_joystick, self.current_x, self.current_y)
            self.root.after(0, self.update_coordinates, self.current_x, self.current_y)


def main(args=None):
    # ser = open_ser()
    ser = None
    # stop()
    rclpy.init()
    publisher = ROS2Publisher() 
    root = tk.Tk()
    app = ControlGUI(root, ser, 0,5, 0,5, publisher)
    root.mainloop()

if __name__ == "__main__":
    main()