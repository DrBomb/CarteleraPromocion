void setup() {
  // put your setup code here, to run once:
  Serial2.begin(115200);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    Serial2.write(Serial.read());
  }

}
