#define BaudRate 115200

int SerialData1=0;
int SerialData2=0;
//bool data1=false,data2=false;
bool ledState = LOW;

void SerialInit(){
  Serial.begin(BaudRate);
 
}

void CmdVel(int Data[2])
{
  
  if (Serial.available()){
    char tempdata = Serial.read();
    Serial.print("ok1");
    while(tempdata!='s' && Serial.available()){
      tempdata = Serial.read();  
      Serial.print("ok2");
    }
    SerialData1 = Serial.parseInt();
    Serial.print("o3");
    while (tempdata !='y'  && Serial.available()){
      tempdata = Serial.read();  
    }
    
    SerialData2 = Serial.parseInt();
    
    lstUpdate = millis();
  }
  
  if (millis()-lstUpdate>2000)
  {
    Data[0]=0;
    Data[1]=0;
  }
  else
  {
    if (millis()-ledUpdate>1000)
    {
      ledUpdate = millis();
      if (ledState == LOW) 
      {
          ledState = HIGH;
      }
      else 
      {
          ledState = LOW;
      }
      digitalWrite(LED_BUILTIN,ledState);
    }
    
    Data[0] = SerialData1;
    Data[1] = SerialData2;
   
  }
//  else 
//  {
//    Data[0]=50;
//    Data[1]=0;
//  }
//Data[0]=-50;
//Data[1]=0;
}
