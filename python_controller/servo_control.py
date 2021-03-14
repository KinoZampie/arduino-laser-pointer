import serial
import time

arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1)

while True:
    inp = input("Servo Position (0-180):")
    arduino.write(bytes(inp, 'utf-8'))