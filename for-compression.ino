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
  pinMode(static_cast<int>(constants::PIN::LED1), OUTPUT);
  pinMode(static_cast<int>(constants::PIN::LED2), OUTPUT);
  pinMode(static_cast<int>(constants::PIN::LED3), OUTPUT);

  digitalWrite(static_cast<int>(naga_constant::PIN::LED3), HIGH);//check is moving
}

void loop() {
  if(digitalRead(static_cast<int> (constants::PIN::COMPRESS_BUTTON))){
    analogWrite(constants::PIN::PWM1, 255);//check direction of rotation
    delay(30000);//NEED TO MEASURE COMPRESSION TIME

    analogWrite(constants::PIN::PWM1, 0);
    delay(3000);//wait time

    analogWrite(constants::PIN::PWM2, 255);//check direction of rotation
    delay(30000);//NEED TO MEASURE COMPRESSION TIME
  }
}
