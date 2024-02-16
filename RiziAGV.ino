double dt=0, start;
float rate = 0.001;
void setup() {
  // put your setup code here, to run once:
  InitMotor();
  initPWM();
  SerialInit();
  start=millis();
  pinMode(LED_BUILTIN, OUTPUT);
   
}
int Data[2]={0,0};
//int mode=0,spd=0;
float yawRate=0,spd=0;
float cmdRate = millis();
float lstUpdate = millis();
float ledUpdate = millis();
void loop() {
  
  if ((millis()- cmdRate) >= 16){
  CmdVel(Data);
  cmdRate = millis();

  }
  
  spd= (1-rate)*spd + rate*Data[0];
  yawRate =(1-rate)*yawRate + rate*Data[1];
  
  drive((int)spd, (int)yawRate);
  
  dt=(millis()-start);
//  Serial.print(spd);
//  Serial.print("\t");  
//  Serial.print(yawRate);  
  Serial.print("\t\t");  
  Serial.println(dt);  
  start=millis();



//

}
