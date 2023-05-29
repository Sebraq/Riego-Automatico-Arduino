#include <Servo.h>
class Info {
private:
  int Gled, Rled, TempSensor, Humidity, servoPin = 5;
  Servo myServo;
public:
  void Mode(int Gled, int Rled) {  //param: GreenLed,RedLed,DHT11 Sensor.
    Serial.begin(9600);
    pinMode(Gled, OUTPUT);
    pinMode(Rled, OUTPUT);
    pinMode(9,OUTPUT);
    digitalWrite(Rled, LOW);
    digitalWrite(Gled, LOW);
    myServo.write(0);
    pinMode(4, OUTPUT);
    //pinMode(TempSensor, INPUT);
  }
  int SensorTemp() {
    delay(1000);
    Humidity = analogRead(A0);
    Serial.println(Humidity);
    return Humidity;
  }
  void LEDS(int Gled, int Rled) {
    int read = SensorTemp();
    if (read >= 850) {
      digitalWrite(Rled, HIGH);
      digitalWrite(Gled, LOW);
    } else if (read < 850) {
      digitalWrite(Rled, LOW);
      digitalWrite(Gled, HIGH);
    }
  }
  void bomba() {
    int read = SensorTemp();
    if (read >= 850) {
      digitalWrite(9, HIGH);
      digitalWrite(4, HIGH);

    } else if (read < 850) {
      digitalWrite(9, LOW);
      digitalWrite(4, LOW);
    }
  }
};