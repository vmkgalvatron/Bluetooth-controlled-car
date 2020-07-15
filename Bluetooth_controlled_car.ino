
  #define dir11 2
  #define dir12 3
  #define dir21 4
  #define dir22 5
void setup() {
  Serial.begin(9600);
  pinMode(dir11,OUTPUT); 
  pinMode(dir12,OUTPUT);// put your setup code here, to run once:
pinMode(dir21,OUTPUT);
pinMode(dir22,OUTPUT);
}
void m1Forward()
{
  digitalWrite(dir11,HIGH);
  digitalWrite(dir12,LOW);
}
void m1Stop()
{
  digitalWrite(dir11,LOW);
  digitalWrite(dir12,LOW);
}
void m1Backward()
{
  digitalWrite(dir11,LOW);
  digitalWrite(dir12,HIGH);
}
void m2Forward()
{
  digitalWrite(dir21,HIGH);
 digitalWrite(dir22,LOW); 
}
void m2Stop()
{
  digitalWrite(dir21,LOW);
  digitalWrite(dir22,LOW);
}
void m2Backward()
{
  digitalWrite(dir21,LOW);
  digitalWrite(dir22,HIGH);
}

void loop() 
{
  while(Serial.available()==0);
  char val=Serial.read();
  Serial.print(val);

  if(val=='F')
  {
    Serial.println("Forward");
    m1Forward();
    m2Forward();
  }
  else if(val=='B')
  {
    
    Serial.println("Back");
    m1Backward();
    m2Backward();
  }
  else if(val=='R')
  {
    Serial.println("Right");
    m1Forward();
    m2Stop();
  }
  else if(val='L')
  {
    Serial.println("Left");
    m1Stop();
    m2Forward();
  }
  else
  {
    Serial.println("INVALID!!!!!!");
    m1Stop();
    m2Stop();
    
  }
  // put your main code here, to run repeatedly:

}
