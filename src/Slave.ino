SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

bool activated = false;
char MOSI_L[1];
char MISO_L[1];



void setup()
{
  pinMode(D1, OUTPUT);
  pinMode(D2, INPUT);
  SPI1.setBitOrder(MSBFIRST);
  SPI1.setDataMode(SPI_MODE0);
  SPI1.onSelect(toggle(mode));
  SPI1.begin(SPI_MODE_SLAVE, D6);
}   

void loop(){
    if(activated){
        activated = false;
        SPI1.transfer(MOSI_L, MISO_L, 1, NULL);
        if(MISO_L[0] = '0') digitalWrite(D1, LOW);
        if(MISO_L[0] = '1') digitalWrite(D1, HIGH);
        if(MISO_L[0] = '0'){
            MOSI_L[0] = digitalRead(D5);
            SPI1.transfer(MOSI_L, MISO_L, 1, NULL);
        } 
    }
}


void toggle(uint8_t mode){
    activated = mode;
}
