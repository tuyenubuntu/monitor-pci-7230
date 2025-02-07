import sys
from PyQt5.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QHBoxLayout, QPushButton, QLabel, QGridLayout, QLineEdit, QMessageBox, QDialog, QInputDialog, QDialogButtonBox
)
from PyQt5.QtCore import QTimer, Qt
from PyQt5.QtGui import QColor, QPainter, QIcon
import os
import cryptlog  # Import module cryptlog.py
from cryptography.fernet import Fernet
import ctypes
from bs4 import BeautifulSoup

# Load the library
lib_path = os.path.abspath("root_lib/monitor7230.so")
lib = ctypes.cdll.LoadLibrary(lib_path)

# Hàm kiểm tra input và output

def get_do():
    """Get input values."""
    do_state = lib.GetDOState(ctypes.c_uint16(0))
    return [(do_state >> i) & 1 for i in range(16)]
#do = get_do() # Output states

def set_do(port, val):
    do = get_do()[::-1] # Output states
    """Set output value for DO[port]."""
    do[-(port + 1)] = val
    dec = sum(do[i] * (2 ** (15 - i)) for i in range(len(do)))
    lib.SetDOState(ctypes.c_uint16(0), ctypes.c_uint32(dec))
    print (f"Digital Output {port} has been assigned : {val}")
    return "OK"

def get_di():
    """Get input values."""
    di_state = lib.GetDIState(ctypes.c_uint16(0))
    return [(di_state >> i) & 1 for i in range(16)]


def sync_do():
    """Synchronize the DO states from hardware."""
    global do
    do_state = lib.GetDOState(ctypes.c_uint16(0))
    do = [(do_state >> i) & 1 for i in range(16)]

#get config
def get_config(tag):
    """Get config group based on the tag name

    Args:
        tag (string): name of config group to be gotten

    Return:
        config (dict or None): config group values to be gotten
    """
    # Đọc file cấu hình XML
    with open('config/configuration.xml', 'r') as f:
        config_file = f.read()

    # Parse file XML
    config_data = BeautifulSoup(config_file, 'xml')
    size_config = {}
    di_config = {}
    do_config = {}

    if tag == "LOGIN":
        return config_data.find(tag)

    if tag == "IO":
        # Lấy các thẻ PORT trong DI
        for port in config_data.find('DI').find_all('PORT'):
            id_ = int(port['id'])
            function = port['function']
            di_config[id_] = function

        # Lấy các thẻ PORT trong DO
        for port in config_data.find('DO').find_all('PORT'):
            id_ = int(port['id'])
            function = port['function']
            do_config[id_] = function
        return di_config, do_config
    for child in config_data.find(tag):
        if child.name == None:
                continue
        if tag == "SIZE":
            size_config[child.name] = list([int(value)
                                        for value in child.string.split(",")])
    return size_config

#Enable for login by password or not
login_config = get_config("LOGIN")
enable_password = login_config.find("ENABLE_PASSWORD_LOGIN").string.lower() == 'true'
#label list DI and DO
di_functions, do_functions = get_config("IO")
#config window size
size_window = get_config("SIZE")
# login_window = size_window["LOGIN_WINDOW"]
# permission_window = size_window["PERMISSION_WINDOW"]
# monitor_window = size_window["MONITOR_WINDOW"]
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
        login_window = size_window["LOGIN_WINDOW"]
        self.main_app = main_app
        self.setWindowTitle("Login")
        self.setGeometry(login_window[0], login_window[1], login_window[2], login_window[3])

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

    def get_admin_password(self):
        """Retrieve Admin password from the encrypted file."""
        try:
            username, password, Warning_  = cryptlog.load_login_info('Admin')
            if password :
                return password
            if not password:
                return Warning_

        except Exception as e:
            QMessageBox.critical(self, "Error", f"Failed to retrieve password: {e}")
            return None
        
    def check_password(self):
        admin_password = self.get_admin_password()
        if not admin_password:
            QMessageBox.critical(self, self.get_admin_password())
            return  # Nếu không lấy được mật khẩu thì dừng lại
        
        # Kiểm tra mật khẩu nhập vào
        if self.password_input.text() == admin_password:
            self.main_app.show()
            self.close()
            print ("Wellcome!!!")
        else:
            print("Error", "Incorrect password!")
            QMessageBox.critical(self, "Error", "Incorrect password!")
            self.password_input.clear()


class PasswordDialog(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        permission_window = size_window["PERMISSION_WINDOW"]
        self.setWindowTitle("Password Required")
        self.setGeometry(permission_window[0], permission_window[1], permission_window[2], permission_window[3])

        layout = QVBoxLayout()

        self.label = QLabel("Enter password to grant permission:")
        layout.addWidget(self.label)

        self.password_input = QLineEdit()
        self.password_input.setEchoMode(QLineEdit.Password)  # Chế độ mật khẩu
        layout.addWidget(self.password_input)

        self.buttons = QDialogButtonBox(QDialogButtonBox.Ok | QDialogButtonBox.Cancel)
        self.buttons.accepted.connect(self.accept)
        self.buttons.rejected.connect(self.reject)
        layout.addWidget(self.buttons)

        self.setLayout(layout)

    def get_password(self):
        return self.password_input.text()


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

        # Thêm nút cấp quyền
        self.permission_button = QPushButton("Grant Permission")
        self.permission_button.setStyleSheet("font-size: 14px; padding: 5px;")
        self.permission_button.clicked.connect(self.request_permission)
        explain_layout.addWidget(self.permission_button)

        # Thêm nút Set All và Reset All
        self.set_all_button = QPushButton("Set All")
        self.set_all_button.setStyleSheet("font-size: 14px; padding: 5px;")
        self.set_all_button.clicked.connect(self.set_all)
        self.set_all_button.setEnabled(False)  # Disabled initially
        explain_layout.addWidget(self.set_all_button)

        self.reset_all_button = QPushButton("Reset All")
        self.reset_all_button.setStyleSheet("font-size: 14px; padding: 5px;")
        self.reset_all_button.clicked.connect(self.reset_all)
        self.reset_all_button.setEnabled(False)  # Disabled initially
        explain_layout.addWidget(self.reset_all_button)

        # Đặt widget này vào góc phải trên cùng của cửa sổ
        self.layout.addWidget(explain_widget, alignment=Qt.AlignRight | Qt.AlignTop)

        # Tạo container cho DI và DO
        container_widget = QWidget()
        container_layout = QVBoxLayout(container_widget)
        
        # Thêm Input display vào container
        self.input_labels = []
        input_layout = QGridLayout()
        input_layout.setSpacing(10)

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
        
        #enabling resize
        # self.setGeometry(400, 300, 1850, 650)
        monitor_window = size_window["MONITOR_WINDOW"]
        self.setGeometry(monitor_window[0], monitor_window[1], monitor_window[2], monitor_window[3])

        # Biến flag để kiểm tra quyền
        self.has_permission = False

    def request_permission(self):
        """Yêu cầu cấp quyền bằng cách hiển thị cửa sổ yêu cầu mật khẩu."""
        dialog = PasswordDialog(self)
        if dialog.exec_() == QDialog.Accepted:
            password = dialog.get_password()
            # Lấy mật khẩu từ tệp mã hóa
            password_per = LoginWindow(QWidget)
            admin_password = password_per.get_admin_password()
            if password == admin_password:
                self.has_permission = True
                print ("Permission Granted", "You now have permission to toggle outputs.")
                QMessageBox.information(self, "Permission Granted", "You now have permission to toggle outputs.")
                self.set_all_button.setEnabled(True)
                self.reset_all_button.setEnabled(True)
            else:
                self.has_permission = False
                print ("Access Denied", "Incorrect password! You cannot toggle outputs.")
                QMessageBox.critical(self, "Access Denied", "Incorrect password! You cannot toggle outputs.")


    def update_inputs(self):
        """Update input states."""
        di = get_di()
        for i, state in enumerate(di):
            color = "green" if state == 1 else "red"
            self.input_labels[i].set_color(color)

        # Update DO (outputs) - kiểm tra trạng thái thực tế
        do = get_do()
        #print (do)
        for i, state in enumerate(do):
            color = "green" if state == 1 else "red"
            self.output_labels[i].set_color(color)
            self.output_buttons[i].setChecked(bool(state))
            self.output_buttons[i].setText("Reset" if state else "Set")

    def toggle_output(self, port, state, button):
        #sync_do()
        """Toggle output state only if the user has permission."""
        if not self.has_permission:
            QMessageBox.warning(self, "Permission Denied", "You do not have permission to toggle this output.")
            button.setChecked(False)
            return
        
        set_do(port, int(state))
        color = "green" if state else "red"
        self.output_labels[port].set_color(color)
        button.setText("Reset" if state else "Set")  # Đổi text trên nút

    def set_all(self):
        """Set all outputs."""
        if not self.has_permission:
            QMessageBox.warning(self, "Permission Denied", "You do not have permission to toggle all outputs.")
            return
        for i in range(16):
            self.toggle_output(i, True, self.output_buttons[i])  # Set tất cả output

    def reset_all(self):
        """Reset all outputs."""
        if not self.has_permission:
            QMessageBox.warning(self, "Permission Denied", "You do not have permission to reset all outputs.")
            return
        for i in range(16):
            self.toggle_output(i, False, self.output_buttons[i])  # Reset tất cả output


if __name__ == "__main__":
    app = QApplication(sys.argv)
    
    # Create main app and login window
    main_window = MonitorApp()
    if enable_password:
        login_window = LoginWindow(main_window)
        login_window.show()
    else:
        print ("Wellcome!!!")
        main_window.show()
    
    sys.exit(app.exec_())
