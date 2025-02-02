# monitor-pci-7230

# PCI 7230 Input/Output Monitor

This application provides a GUI to monitor and control the input and output states of a PCI 7230 card. It includes features such as real-time input monitoring, output control, and user authentication for access control.

## Features

1. **Input Monitoring**:
   - Displays the real-time state of all 16 digital inputs (DI).
   - Uses color-coded labels: Green for `High` and Red for `Low`.
   - Descriptive labels for certain DI functions (e.g., "Laser completed", "Rework mode").

2. **Output Control**:
   - Allows toggling the state of all 16 digital outputs (DO).
   - Displays real-time state changes with color-coded labels.
   - Includes "Set All" and "Reset All" functionalities for batch control.

3. **Access Control**:
   - Users must log in with a password to access the application.
   - A secondary password prompt is required for toggling output states.

4. **GUI Features**:
   - Modern and responsive PyQt5-based interface.
   - Color-coded status indicators for better clarity.
   - Scrollable interface for ease of use on smaller screens.

## Prerequisites

- Python 3.6+
- PyQt5 library
- `cryptography` library for password encryption and decryption.
- PCI 7230 card and its corresponding library (`aiio.so`).

## Installation

1. Clone or download this repository.
2. Ensure the required libraries are installed:
   ```bash
   pip install PyQt5 cryptography
   ```
   
      ```bash
   pip install beautifulsoup4
   ```

      ```bash
   pip install lxml
   ```
3. Place the PCI 7230 library (`aiio.so`) in the root directory of the project.
4. Ensure the `cryptlog.py` module is available for handling encrypted passwords.

## Usage

1. **Running the Application**:
   Ubuntu os
   ```bash
   python app.py
   ```

   Windows os (just UI)
   ```bash
   python appw.py
   ```

2. **Login Process**:
   - Upon starting, a login window will appear.
   - Enter the admin password to access the main interface.

3. **Monitoring and Controlling**:
   - Monitor input states in real-time.
   - Grant permission to toggle outputs by clicking "Grant Permission" and entering the secondary password.
   - Use the "Set All" and "Reset All" buttons to control all outputs simultaneously.

4. **Password Management**:
   - Passwords are securely encrypted and stored.
   - Use the `cryptlog.py` utility to manage encrypted login credentials.
   - If you want to change password, use the `cryptlog.py`, follow;
   ```bash
   python cryptlog.py
   ```
   It is recommended that you enter creator and user  as "Admin"

## Files and Directories

- `main.py`: Main application file.
- `cryptlog.py`: Module for handling password encryption and decryption.
- `aiio.so`: PCI 7230 card library.
- `Shortcut/IO_COM.png`: Application icon.
- `login/Admin`: Directory containing encrypted admin credentials.

## Known Issues

1. Ensure `aiio.so` is compiled correctly and matches your system architecture.
2. For incorrect or missing password files, the application will display an error message.

## License

This application is provided under the MIT License. See `LICENSE` for more information.

## Acknowledgments

- PyQt5 for GUI development.
- `cryptography` for secure password handling.
- PCI 7230 card library for hardware interfacing.

## Contact

For issues or suggestions, please reach out via the GitHub repository or email the maintainer.

