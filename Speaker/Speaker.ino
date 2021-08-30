void setup() {
  pinMode(8, OUTPUT);
  for (int i = 0; i < 3; i++) {
  tone(8, 261, 100);
  delay(250);
  tone(8, 261, 100);
  delay(250);
  tone(8, 261, 100);
  delay(250);
  tone(8, 261, 300);
  delay(750);
}
}

void loop() {
}
