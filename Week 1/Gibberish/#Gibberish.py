#Gibberish
import serial
import sys
LED_flag = False
with serial.Serial('COM5',9600,timeout=1) as serArd:
    print(f"The Arduino board is connect through {serArd.port}")
    while True:
        try:
            con_val = input(f"Enter 1 for turn on LED and 0 for turn off LED and Enter 2 for SURPRISE! : ")
            while con_val not in ['0','1','2','q',]:
                print(f"Please enter 1 or 0 !")
                con_val = input(f"Enter 1 for turn on LED and 0 for turn off LED : ")
            print(f'You entered {con_val}')
            if (serArd.writable() and con_val != 'q'):
                serArd.write(con_val.encode())
                myData = serArd.readline().decode()
                print(myData)

            if con_val == 'q':
                print('Program is stopped')
                break

        except serial.SerialException as er:
            print(er)
        except KeyboardInterrupt:
            sys.exit(0)
