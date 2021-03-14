from tkinter import *
import time, serial
root = Tk()
root.geometry("720x720")

# previous_time = time.time()

arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.01)

x = 1
y = 1
previous_x = 0
previous_y = 0

def motion(event):
    global previous_time, x, y
    x,y = int(event.x/4)+1, int(event.y/4)+1
    # x, y = str(f"{int(event.x):03d}"), str(f"{int(event.y):03d}")
    # if time.time() - previous_time > 5:
        # previous_time = time.time()


def position_servo():
    global previous_x, previous_y
    print(x,y)
    if (previous_x != x) or (previous_y != y):
        arduino.write(bytes(str(f"{x} {y}"), 'utf-8'))
        previous_x, previous_y = x,y
    root.after(20, position_servo)


root.bind('<Motion>', motion)
root.after(500,position_servo)
root.mainloop()