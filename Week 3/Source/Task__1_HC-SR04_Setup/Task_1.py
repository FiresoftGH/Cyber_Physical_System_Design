import imp
import serial
from datetime import datetime
import time
import keyboard

SampleTime = '500' # In milliseconds

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
            try:
                myData = float(myData)
                print(f"raw data at {rec_time} : {myData}")
            except:
                print("No data")