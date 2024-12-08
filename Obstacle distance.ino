int green = 3;
int red = 2;
int buzzer = 8;
int pingPin = 5;
long duration;
int inch, cm;

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // to clear the pingpin
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delay(2);
  
  // to trigger a echo signal
  digitalWrite(pingPin, HIGH);
  delay(5);
  digitalWrite(pingPin, LOW);
  
  // to recieve the return echo signal
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  // to convert milicecond to distance
  inch = duration*0.01375/2;
  cm = duration*0.035/2;
  
  // to trigger to led and buzzer
  if(cm < 200){
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else{
    digitalWrite(red, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(green, HIGH);
  }
  
  // to see on the serial monitor
 
  Serial.print("Distance in inch= ");
  Serial.println(inch);

  Serial.print("Distance in cm= ");
  Serial.println(cm);
  Serial.println();
  
}