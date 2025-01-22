import os
import json
from cryptography.fernet import Fernet

# Generate an encryption key (only needs to be done once)
def generate_key():
    return Fernet.generate_key()

# Save the encryption key to a file
def save_key(key, filepath):
    with open(filepath, "wb") as key_file:
        key_file.write(key)

# Load the key from a file
def load_key(filepath):
    with open(filepath, "rb") as key_file:
        return key_file.read()

# Encrypt a password
def encrypt_password(password, key):
    f = Fernet(key)
    encrypted_password = f.encrypt(password.encode())
    return encrypted_password

# Decrypt a password
def decrypt_password(encrypted_password, key):
    f = Fernet(key)
    decrypted_password = f.decrypt(encrypted_password).decode()
    return decrypted_password

# Save login information to a JSON file in the creator's folder
def save_login_info(creator, username, password, base_folder="login"):
    # Create the base folder if it doesn't exist
    os.makedirs(base_folder, exist_ok=True)

    # Create a folder for the creator
    creator_folder = os.path.join(base_folder, creator)
    os.makedirs(creator_folder, exist_ok=True)

    # File paths
    key_filepath = os.path.join(creator_folder, "key.key")
    login_info_filepath = os.path.join(creator_folder, "login_info.json")

    # Generate a key and encrypt the password
    key = generate_key()
    save_key(key, key_filepath)
    encrypted_password = encrypt_password(password, key)

    # Save login information to a JSON file
    login_info = {
        "username": username,
        "password": encrypted_password.decode()  # Store the encrypted password
    }

    with open(login_info_filepath, "w") as f:
        json.dump(login_info, f)

    print(f"Login information has been saved at: {creator_folder}")

# Load login information from a JSON file
def load_login_info(creator, base_folder="login"):
    # File paths
    creator_folder = os.path.join(base_folder, creator)
    key_filepath = os.path.join(creator_folder, "key.key")
    login_info_filepath = os.path.join(creator_folder, "login_info.json")

    # Check if the folder or file does not exist
    if not os.path.exists(key_filepath) or not os.path.exists(login_info_filepath):
        print(f"Information for {creator} does not exist.")
        return None, None

    # Load the key and login information
    key = load_key(key_filepath)
    with open(login_info_filepath, "r") as f:
        login_info = json.load(f)

    # Decrypt the password
    decrypted_password = decrypt_password(login_info["password"].encode(), key)

    return login_info["username"], decrypted_password

# Example usage
if __name__ == "__main__":
    # Save login information
    creator = input("Enter creator name: ")
    username = input("Enter username: ")
    password = input("Enter password: ")

    save_login_info(creator, username, password)

    # Load login information
    username, password = load_login_info(creator)
    if username and password:
        print(f"Username: {username}")
        print(f"Password: {password}")
