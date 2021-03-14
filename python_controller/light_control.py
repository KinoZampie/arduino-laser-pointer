import serial
import time

arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1)

while True:
    inp = input("Enter a value:")
    arduino.write(bytes(inp, 'utf-8'))
    time.sleep(2)
    # data=arduino.readline()
    # print(str(data))