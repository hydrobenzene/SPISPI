SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

char MOSI_L[1];
char MISO_L[1];

void setup() {
  pinMode(D1, OUTPUT);
  Serial.begin(9600);
  SPI.setClockSpeed(1, MHZ);
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.begin(SPI_MODE_MASTER, D5);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  MOSI_L[0] = Serial.read();
  if(Serial.read() == '0'){
    // Carry the Message Along
    digitalWrite(D1, LOW);
    SPI.transfer(MOSI_L, MISO_L, 1, NULL);
    digitalWrite(D1, HIGH);
  }
  if(Serial.read() == '1'){
    // Carry the Message Along
    digitalWrite(D1, LOW);
    SPI.transfer(MOSI_L, MISO_L, 1, NULL);
    digitalWrite(D1, HIGH);
  }
  else if(Serial.read() == '?'){
    // Carry the Message Along and get a response
    digitalWrite(D1, LOW);
    SPI.transfer(MOSI_L, MISO_L, 1, NULL);
    digitalWrite(D1, HIGH);
    Serial.println(String(MISO_L[0]));
  }
}