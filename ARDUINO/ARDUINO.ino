void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}



/*void loop()
{
 if(Serial.available())
  {
    char c = Serial.read();
    if(c == 't')
    {
    digitalWrite(13,HIGH);
    //Serial.write('t');
    Serial.println("Led Yandı");
    }
    else if(c == 'm')
    {
    digitalWrite(13,LOW);
    Serial.println("Led Söndü");
   // Serial.write('m');
    }
 }
  
  }*/

void loop() 
{
  if(Serial.available())
  {
    char c = Serial.read();
    if(c == 't')
    {
    digitalWrite(13,HIGH);
    Serial.write('t');
    Serial.println("Led Yandı");
    }
    else if(c == 'm')
    {
    digitalWrite(13,LOW);
    Serial.println("Led Söndü");
    Serial.write('m');
    }
  }
}
