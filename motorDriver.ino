/*
#define MOTOR_EN_LFT  10
#define MOTOR_EN_RGT  11

#define MOTOR_LFT_FWD  3
#define MOTOR_LFT_BCK  5
#define MOTOR_RGT_FWD  6
#define MOTOR_RGT_BCK  9

#define DEBUG true

void InitMotor(){
  pinMode(MOTOR_LFT_FWD,OUTPUT);
  pinMode(MOTOR_LFT_BCK,OUTPUT);
  pinMode(MOTOR_RGT_FWD,OUTPUT);
  pinMode(MOTOR_RGT_BCK,OUTPUT);
  
  pinMode(MOTOR_EN_LFT,OUTPUT);
  pinMode(MOTOR_EN_RGT,OUTPUT);
}

void drive(int spd,int mode){

  switch (mode){
  case 0:
    Break();
    if(DEBUG){
      Serial.println("break");
    }
    break;
  
  case 1:
    Forward(spd);
    if(DEBUG){
      Serial.print(spd);
      Serial.println("fwd");
    }
    break;
  case 2:
    Backward(spd);
    if(DEBUG){
      Serial.print(spd);
      Serial.println("bck");
    }
    break;
  case 3:
    Turn_clk(spd);
    if(DEBUG){
      Serial.print(spd);
      Serial.println("clk");
    }
    break;
  case 4:
    Turn_cclk(spd);
    if(DEBUG){
      Serial.print(spd);
      Serial.println("cclk");
    }
    break;
  default:
    Break();
    if(DEBUG){
      Serial.println("break");
    }
    break; 
  }
}

void Turn_clk (int spd){
  spd = map(spd, 0,100,10,255);
  EN_LFT(true);
  EN_RGT(true);
  analogWrite(MOTOR_LFT_FWD,spd);
  analogWrite(MOTOR_LFT_BCK,0);
  analogWrite(MOTOR_RGT_FWD,spd);
  analogWrite(MOTOR_RGT_BCK,0);
}

void Turn_cclk (int spd){
  spd = map(spd, 0,100,10,255);
  EN_LFT(true);
  EN_RGT(true);
  analogWrite(MOTOR_LFT_FWD,0);
  analogWrite(MOTOR_LFT_BCK,spd);
  analogWrite(MOTOR_RGT_FWD,0);
  analogWrite(MOTOR_RGT_BCK,spd);
}

void Forward(int spd){
  spd = map(spd, 0,100,10,255);
  EN_LFT(true);
  EN_RGT(true);
  analogWrite(MOTOR_LFT_FWD,0);
  analogWrite(MOTOR_LFT_BCK,spd);
  analogWrite(MOTOR_RGT_FWD,spd);
  analogWrite(MOTOR_RGT_BCK,0);
}

void Backward (int spd){
  spd = map(spd, 0,100,10,255);
  EN_LFT(true);
  EN_RGT(true);
  analogWrite(MOTOR_LFT_FWD,spd);
  analogWrite(MOTOR_LFT_BCK,0);
  analogWrite(MOTOR_RGT_FWD,0);
  analogWrite(MOTOR_RGT_BCK,spd);
}


void Break(){
  EN_LFT(false);
  EN_RGT(false);
  analogWrite(MOTOR_LFT_FWD,0);
  analogWrite(MOTOR_LFT_BCK,0);
  analogWrite(MOTOR_RGT_FWD,0);
  analogWrite(MOTOR_RGT_BCK,0);
}

void EN_LFT(bool state){
  if (state)
  {
    digitalWrite(MOTOR_EN_LFT,true);
  }
  else
  {
    digitalWrite(MOTOR_EN_LFT,false);
  }
}
void EN_RGT(bool state){
  if (state)
  {
    digitalWrite(MOTOR_EN_RGT,true);
  }
  else
  {
    digitalWrite(MOTOR_EN_RGT,false);
  }
}
*/
