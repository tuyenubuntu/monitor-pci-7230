import sys
from PyQt5.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QHBoxLayout, QPushButton, QLabel, QGridLayout, QLineEdit, QMessageBox
)
from PyQt5.QtCore import QTimer, Qt
from PyQt5.QtGui import QColor, QPainter, QIcon
import os

# Giả lập hàm để không phụ thuộc vào aiio.so
def set_do(port, val):
    """Giả lập set output value cho DO[port]."""
    return "OK"

def get_di():
    """Giả lập input values."""
    return [0] * 16

class ColorLabel(QLabel):
    """Custom label to display colored square."""
    def __init__(self, color="red", parent=None):
        super().__init__(parent)
        self.color = color
        self.setFixedSize(30, 30)

    def set_color(self, color):
        """Update the color of the square."""
        self.color = color
        self.update()

    def paintEvent(self, event):
        """Custom paint event to draw the colored square."""
        painter = QPainter(self)
        painter.setBrush(QColor(self.color))
        painter.setPen(QColor(self.color))
        painter.drawRect(0, 0, self.width(), self.height())

class LoginWindow(QWidget):
    def __init__(self, main_app):
        super().__init__()
        self.main_app = main_app
        self.setWindowTitle("Login")
        self.setGeometry(800, 500, 400, 200)

        # Đặt biểu tượng cho cửa sổ
        icon_path = os.path.abspath("Shortcut/IO_COM.png")  # Đường dẫn đầy đủ tới icon
        if os.path.exists(icon_path):
            self.setWindowIcon(QIcon(icon_path))

        layout = QVBoxLayout()
        self.label = QLabel("Enter Password:")
        self.password_input = QLineEdit()
        self.password_input.setEchoMode(QLineEdit.Password)
        self.login_button = QPushButton("Login")
        
        # Kết nối nút login với chức năng check_password
        self.login_button.clicked.connect(self.check_password)

        # Kết nối sự kiện khi nhấn Enter trong QLineEdit
        self.password_input.returnPressed.connect(self.check_password)

        layout.addWidget(self.label)
        layout.addWidget(self.password_input)
        layout.addWidget(self.login_button)
        self.setLayout(layout)

    def check_password(self):
        if self.password_input.text() == "adlink":
            self.main_app.show()
            self.close()
        else:
            QMessageBox.critical(self, "Error", "Incorrect password!")
            self.password_input.clear()


class MonitorApp(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("PCI 7230 Input/Output Monitor")

        # Đặt biểu tượng cho cửa sổ
        icon_path = os.path.abspath("Shortcut/IO_COM.png")  # Đường dẫn đầy đủ tới icon
        if os.path.exists(icon_path):
            self.setWindowIcon(QIcon(icon_path))

        self.layout = QVBoxLayout(self)  # Dùng một layout chính

        # Thêm ô màu giải thích trạng thái
        explain_widget = QWidget(self)  # Widget cố định cho phần giải thích
        explain_layout = QHBoxLayout(explain_widget)
        explain_layout.setContentsMargins(0, 0, 0, 0)  # Loại bỏ lề
        explain_layout.setSpacing(5)  # Khoảng cách nhỏ giữa các thành phần

        # Ô màu xanh (High)
        high_label = ColorLabel("green")
        high_text = QLabel("High")
        high_text.setStyleSheet("font-size: 14px; padding: 2px;")
        explain_layout.addWidget(high_label)
        explain_layout.addWidget(high_text)

        # Ô màu đỏ (Low)
        low_label = ColorLabel("red")
        low_text = QLabel("Low")
        low_text.setStyleSheet("font-size: 14px; padding: 2px;")
        explain_layout.addWidget(low_label)
        explain_layout.addWidget(low_text)

        # Đặt widget này vào góc phải trên cùng của cửa sổ
        self.layout.addWidget(explain_widget, alignment=Qt.AlignRight | Qt.AlignTop)

        # Tạo container cho DI và DO
        container_widget = QWidget()
        container_layout = QVBoxLayout(container_widget)
        
        # Thêm Input display vào container
        self.input_labels = []
        input_layout = QGridLayout()
        input_layout.setSpacing(10)

        # Mapping chức năng cho từng DI
        di_functions = {
            0: "Laser completed",
            2: "Rework mode"
        }

        for i in range(16):
            row_layout = QHBoxLayout()

            # Giảm lề của hàng
            row_layout.setContentsMargins(0, 0, 0, 0)
            row_layout.setSpacing(2)  # Khoảng cách giữa các widget trong hàng

            # Màu trạng thái
            color_label = ColorLabel("red")
            self.input_labels.append(color_label)
            row_layout.addWidget(color_label)

            # Gắn nhãn chức năng
            function_name = di_functions.get(i, "Reserve")
            text_label = QLabel(f"DI[{i}] | {function_name}")
            text_label.setStyleSheet("font-size: 14px; padding: 5px;")
            row_layout.addWidget(text_label)

            input_layout.addLayout(row_layout, i // 4, i % 4)
        container_layout.addLayout(input_layout)

        # Thêm Output control vào container
        self.output_labels = []
        self.output_buttons = []
        output_layout = QGridLayout()
        output_layout.setSpacing(10)

        # Mapping chức năng cho từng DO
        do_functions = {
            0: "Green light",
            2: "Red light",
            4: "Sent signal to Laser",
            8: "Confirm"
        }

        for i in range(16):
            row_layout = QHBoxLayout()

            # Giảm lề của hàng
            row_layout.setContentsMargins(0, 0, 0, 0)
            row_layout.setSpacing(2)  # Khoảng cách giữa các widget trong hàng

            # Màu trạng thái
            color_label = ColorLabel("red")
            self.output_labels.append(color_label)
            row_layout.addWidget(color_label)

            # Gắn nhãn chức năng
            function_name = do_functions.get(i, "Reserve")
            text_label = QLabel(f"DO[{i}] | {function_name}")
            text_label.setStyleSheet("font-size: 14px; padding: 5px;")
            row_layout.addWidget(text_label)

            # Nút điều khiển
            button = QPushButton("Set")
            button.setCheckable(True)
            button.setFixedWidth(60)  # Thu nhỏ chiều rộng của nút
            button.clicked.connect(lambda checked, port=i, btn=button: self.toggle_output(port, checked, btn))
            self.output_buttons.append(button)
            row_layout.addWidget(button)

            output_layout.addLayout(row_layout, i // 4, i % 4)
        container_layout.addLayout(output_layout)

        # Sử dụng QScrollArea nếu cần cuộn
        from PyQt5.QtWidgets import QScrollArea
        scroll_area = QScrollArea()
        scroll_area.setWidget(container_widget)
        scroll_area.setWidgetResizable(True)

        # Thêm QScrollArea vào layout chính
        self.layout.addWidget(scroll_area)

        # Set layout cho cửa sổ chính
        self.setLayout(self.layout)

        # Timer chỉ cập nhật DI
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_inputs)
        self.timer.start(500)  # Update every 500ms
        
        #enanled resize
        self.setGeometry(400, 300, 1200, 500)




    def update_inputs(self):
        """Update input states."""
        di = get_di()
        for i, state in enumerate(di):
            color = "green" if state == 1 else "red"
            self.input_labels[i].set_color(color)

    def toggle_output(self, port, state, button):
        """Toggle output state."""
        set_do(port, int(state))
        color = "green" if state else "red"
        self.output_labels[port].set_color(color)
        button.setText("Reset" if state else "Set")  # Đổi text trên nút

if __name__ == "__main__":
    app = QApplication(sys.argv)
    
    # Create main app and login window
    main_window = MonitorApp()
    login_window = LoginWindow(main_window)
    login_window.show()
    
    sys.exit(app.exec_())
