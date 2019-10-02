
uint8_t temprature = 0;
uint8_t humidity = 0;
uint8_t lux = 0;
void setup() {
  Serial.begin(38400);
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available() > 0) {
    temprature = Serial.read();
    humidity = Serial.read();
    lux = Serial.read();
    Serial.print("Temprature: ");
    Serial.println(temprature);
    Serial.print("Humidity: ");
    Serial.println(humidity);
    Serial.print("Lux: ");
    Serial.println(lux);
    Serial.println("--");
  }
}
