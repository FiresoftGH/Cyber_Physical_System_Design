# Find the distance between the object the usual way
# Using the output of the sensor (Time in )

# Max Distance = 800 cm
# Min Distance = 2.26 cm

import imp
import serial
from datetime import datetime
import time
import keyboard
import sys

compare_array = [0]
time_array = [0]

SampleTime = '500' # In milliseconds
speed_of_sound = 422 # Speed of sound in m/s calculated.
index = 0

with serial.Serial('COM8', 9600) as serArd:
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
            disData = ((float(myData) * 10**-6) * speed_of_sound) * 100
            compare_array.append(disData)
            time_array.append(float(rec_time[8:]))
            index += 1

            try:
                myData = float(myData)
                print(f"at time {rec_time} : {myData}")
                print(f"distance at {rec_time} : {disData}", "cm")
                diff_dis = compare_array[index] - compare_array[index - 1]
                diff_time = time_array[index] - time_array[index - 1]
                diff_speed = diff_dis / diff_time
                print("Speed is :", diff_speed, "cm/s") # Measured Manually
                if diff_speed > 0:
                    print("Moving Out")
                elif diff_speed < 0:
                    print("Moving In")
                elif diff_speed == 0:
                    print("No change")
            except:
                print("No data")