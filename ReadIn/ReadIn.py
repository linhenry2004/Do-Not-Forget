import serial
import os
import time
ser = serial.Serial('/dev/cu.usbmodem141201', 9600)
os.getcwd()
file = open('samples.csv')
while True:
    line = file.readline()
    if not line:
        break
    ser.write(line.encode('utf-8'))
    time.sleep(3)
file.close
