import imp
import serial
from datetime import datetime
import time
import keyboard
import sys

SampleTime = '500' # In milliseconds
speed_of_sound = 211 # Speed of sound in m/s calculated.

with serial.Serial('COM6', 9600) as serArd:
    print(f"Arduino board is connect through {serArd.port}")
    time.sleep(2)
    serArd.reset_input_buffer()

    if (serArd.writable()):
        serArd.write(SampleTime.encode())
        print(serArd.readline().decode().rstrip())

    while not keyboard.is_pressed('q'):
        if (serArd.inWaiting() > 0):
            print(serArd.readline())
            rec_time = datetime.now().strftime('%H:%M:%S.%f')
            myData = serArd.readline().decode().rstrip()
            disData = ((int(myData) * 10**-6) * speed_of_sound) * 100
            try:
                myData = float(myData)
                print(f"at time {rec_time} : {myData}")
                print(f"distance at {rec_time} : {disData}", "cm")
            except:
                print("No data")