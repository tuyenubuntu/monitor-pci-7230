import os
import json
from cryptography.fernet import Fernet

# Tạo key mã hóa (chỉ cần làm một lần)
def generate_key():
    return Fernet.generate_key()

# Lưu key mã hóa vào tệp
def save_key(key, filepath):
    with open(filepath, "wb") as key_file:
        key_file.write(key)

# Đọc key từ tệp
def load_key(filepath):
    with open(filepath, "rb") as key_file:
        return key_file.read()

# Mã hóa mật khẩu
def encrypt_password(password, key):
    f = Fernet(key)
    encrypted_password = f.encrypt(password.encode())
    return encrypted_password

# Giải mã mật khẩu
def decrypt_password(encrypted_password, key):
    f = Fernet(key)
    decrypted_password = f.decrypt(encrypted_password).decode()
    return decrypted_password

# Lưu thông tin đăng nhập vào tệp JSON trong thư mục người tạo
def save_login_info(creator, username, password, base_folder="login"):
    # Tạo thư mục chính nếu chưa tồn tại
    os.makedirs(base_folder, exist_ok=True)

    # Tạo thư mục riêng cho người tạo
    creator_folder = os.path.join(base_folder, creator)
    os.makedirs(creator_folder, exist_ok=True)

    # Đường dẫn tệp
    key_filepath = os.path.join(creator_folder, "key.key")
    login_info_filepath = os.path.join(creator_folder, "login_info.json")

    # Tạo key và mã hóa mật khẩu
    key = generate_key()
    save_key(key, key_filepath)
    encrypted_password = encrypt_password(password, key)

    # Lưu thông tin đăng nhập vào tệp JSON
    login_info = {
        "username": username,
        "password": encrypted_password.decode()  # Lưu mật khẩu đã mã hóa
    }

    with open(login_info_filepath, "w") as f:
        json.dump(login_info, f)

    print(f"Thông tin đăng nhập đã được lưu tại: {creator_folder}")

# Đọc thông tin đăng nhập từ tệp JSON
def load_login_info(creator, base_folder="login"):
    # Đường dẫn tệp
    creator_folder = os.path.join(base_folder, creator)
    key_filepath = os.path.join(creator_folder, "key.key")
    login_info_filepath = os.path.join(creator_folder, "login_info.json")

    # Kiểm tra nếu thư mục hoặc tệp không tồn tại
    if not os.path.exists(key_filepath) or not os.path.exists(login_info_filepath):
        print(f"Thông tin cho {creator} không tồn tại.")
        return None, None

    # Đọc key và thông tin đăng nhập
    key = load_key(key_filepath)
    with open(login_info_filepath, "r") as f:
        login_info = json.load(f)

    # Giải mã mật khẩu
    decrypted_password = decrypt_password(login_info["password"].encode(), key)

    return login_info["username"], decrypted_password


# Ví dụ sử dụng
if __name__ == "__main__":
    # Lưu thông tin đăng nhập
    creator = input("Nhập tên người tạo: ")
    username = input("Nhập tên người dùng: ")
    password = input("Nhập mật khẩu: ")

    save_login_info(creator, username, password)

    # Đọc thông tin đăng nhập
    username, password = load_login_info(creator)
    if username and password:
        print(f"Username: {username}")
        print(f"Password: {password}")

