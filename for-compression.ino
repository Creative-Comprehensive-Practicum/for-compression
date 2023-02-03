namespace constants{
enum class PIN{
  PWM1 = 5,
  PWM2 = 6,
  PWM3 = 9,
  PWM4 = 10,

  LED1 = 11,
  LED2 = 12,
  LED3 = 13,

  COMPRESS_BUTTON,// NEED TO DECIDE PIN NUMBER
};

}

namespace globals{

}


void setup() {
  pinMode(static_cast<uint8_t>(constants::PIN::LED1), OUTPUT);
  pinMode(static_cast<uint8_t>(constants::PIN::LED2), OUTPUT);
  pinMode(static_cast<uint8_t>(constants::PIN::LED3), OUTPUT);
  pinMode(static_cast<uint8_t>(constants::PIN::COMPRESS_BUTTON), INPUT);

  digitalWrite(static_cast<uint8_t>(constants::PIN::LED3), HIGH);//check is moving
}

void loop() {
  if(digitalRead(static_cast<uint8_t> (constants::PIN::COMPRESS_BUTTON))){
    analogWrite(static_cast<uint8_t>(constants::PIN::PWM1), 255);//check direction of rotation
    delay(30000);//NEED TO MEASURE COMPRESSION TIME

    analogWrite(static_cast<uint8_t>(constants::PIN::PWM1), 0);
    delay(3000);//wait time

    analogWrite(static_cast<uint8_t>(constants::PIN::PWM2), 255);//check direction of rotation
    delay(30000);//NEED TO MEASURE COMPRESSION TIME
  }
}
