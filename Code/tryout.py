import pyfirmata
import serial
import os
ser = serial.Serial('/dev/cu.usbmodem141201', 9600)
string = """#include <Stepper.h>
#define STEPS 200
Stepper stepper(STEPS, 11, 9, 10, 8);
void setup() {
	stepper.setSpeed(160);
}
void loop() {
	stepper.step(%s);
	delay(1000);
	stepper.step(%s);
	delay(1000);
}"""
num1 = 512
num2 = -512
str_list = string.split('\n')
str_list[7] = "	stepper.step(%s);" %num1
str_list[9] = "	stepper.step(%s);" %num2
string = "\n".join(str_list)
print(string)
ser.write(string.encode('utf-8'))
