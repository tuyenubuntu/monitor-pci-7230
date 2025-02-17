import sys

import os

import ctypes

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

def get_do_ID(pin):
    """Get input values."""
    do_state_id = lib.GetDOState_Line(ctypes.c_uint16(0),ctypes.c_uint16(pin))
    return do_state_id

def get_di_ID(pin):
    """Get input values."""
    di_state_id = lib.GetDOState_Line(ctypes.c_uint16(0),ctypes.c_uint16(pin))
    return di_state_id