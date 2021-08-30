#include <Stepper.h>
#define STEPS 200
Stepper stepper1(STEPS, 11, 9, 10, 8);
Stepper stepper2(STEPS, 7, 5, 6, 4);
void setup() {
  stepper1.setSpeed(160);
  stepper2.setSpeed(160);
}
void loop() {
  simul(2048);
  delay(1000);
}
void simul (int x) {
  bool positive = x > 0;
  if (positive){
    int i = 0;
    while (i < x){
      stepper1.step(-1);
      stepper2.step(1);
      i++;
    }
  }
  if (!positive){
    int i = x;
    while (i > 0){
      stepper1.step(-1);
      stepper2.step(-1);
      i--;
    }
  }
}
