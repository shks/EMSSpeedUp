
int prevt = 0;
int t = 0;
int threshold = 5;
unsigned long _time;
unsigned long _interval;
unsigned long timerStart;

bool isMeasuring = false;
int LEDonCount = 0;

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);

  Serial.begin(9600); 
}

void loop()
{
  uint8_t data = (uint8_t)Serial.read();
  //Serial.println("Serial Read " + String(data));
  if (data == 'h') // check if incoming byte is header
  {
    //LED ON trigger delay 
    int _delay = 200 * (int(Serial.read())- 48) ;
    //delay(_delay);
    digitalWrite(12, HIGH);
    timerStart = millis();
    isMeasuring = true;
    if (Serial.available()) {
       Serial.read();
    }
  }

  t = 0;
  _interval = millis() - _time;
  _time = millis();
  //Serial.println(_interval);
  digitalWrite(8, HIGH);

  while (digitalRead(9) != HIGH) t++;

  digitalWrite(8, LOW);
  delay(1);

  // LED点灯
  if ( t > threshold ) {
    //digitalWrite(13, HIGH);
    LEDonCount = 1000;
    //Touch DETECT
    if(isMeasuring)
    {
      unsigned long reactionTime = millis() - timerStart;
      Serial.println(reactionTime);
      digitalWrite(12, LOW);
      isMeasuring = false;
    }
  }
  
  if(LEDonCount > 0)
  {
    digitalWrite(13, HIGH);
    LEDonCount --;
  }else{
    digitalWrite(13, LOW);
  }

}
