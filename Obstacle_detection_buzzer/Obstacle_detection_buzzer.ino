int const ledPinc=11;
int const buzzer = 2;
int const trigger = 4; //"trigger" sends an ultrasonic wave that gets reflected by any object on its path.
int const echo = 3; //"echo" recieves the wave that gets reflected and calculates the time travelled by it.

void setup()

{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT); // specifying inputs and outputs
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(ledPinc,OUTPUT);
}

void loop() // basic idea is creating a loop that takes input and gives output again and again
{
  int dist, time1;
  digitalWrite(trigger, HIGH); // sends an ultrasonic wave
  delay(1);
  digitalWrite(trigger, LOW);
  time1 = pulseIn(echo, HIGH);//recieves the reflected wave and calulates time interval
  dist = (time1/2)/29.1;    // provided in ultrasonic sensor datasheet
  Serial.print(dist);-
  Serial.print("     ");
     if (dist <= 25 && dist >= 0) {
      digitalWrite(ledPinc, HIGH);// turns on the led
      digitalWrite(buzzer, LOW); // buzzer buzzes when output= LOW (in datasheet)
      
    } else {
      digitalWrite(ledPinc, LOW);
      digitalWrite(buzzer, HIGH);
    }
    delay(50); // A 50ms delay that ensures no object is missed but also makes our system efficient.
}
