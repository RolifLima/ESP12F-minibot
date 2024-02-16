#define MOTOR_LFT_SPD  3
#define MOTOR_RGT_SPD  10

#define MOTOR_LFT  5
#define MOTOR_RGT  6


#define DEBUG false
void initPWM(){
//fast PWM with OCR2A TOP 20Khz pin 3
TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
TCCR2B = _BV(WGM22) | _BV(CS21);
OCR2A = 100;  
//fast PWM with OCR1A TOP  20Khz pin 10
TCCR1A = _BV(COM1A0) | _BV(COM1B1) | _BV(WGM11) | _BV(WGM10);
TCCR1B =  _BV(WGM13) | _BV(WGM12) | _BV(CS10);
OCR1A = 800;

}
void writePWM_LFT(int value){//value 0-255
  value = (int)map(value, 0,255,0,100);
  OCR2B = value; 
//  Serial.print("\t");
//  Serial.print(value);
  
}
void writePWM_RGT(int value){// value 0-255
  value = (int)map(value, 0,255,0,800);
  OCR1B = value;
//  Serial.print("\t");
//  Serial.print(value);
}

void InitMotor(){
  pinMode(MOTOR_LFT,OUTPUT);
  pinMode(MOTOR_RGT,OUTPUT);
  pinMode(MOTOR_LFT_SPD,OUTPUT);
  pinMode(MOTOR_RGT_SPD,OUTPUT);
}

void drive(int spd,int yawRate){
  int spdV,yawV;
  spdV = abs(spd);//map(abs(spd), 0,100,0,255);
  yawV = abs(yawRate);//map(abs(yawRate), 0,100,0,255);
  
  
  bool RMotor,LMotor;
  int L_spd,R_spd;
  if (spd>0 && yawRate>=0){
    /*if(DEBUG){
      Serial.print(spd);
      Serial.println("fwd cclk turn");
    }*/
    
    L_spd = spdV + yawV;
    R_spd = spdV - yawV;
    
    RMotor = true;
    LMotor = true;
  }
  else if (spd>0 && yawRate<0){
    /*if(DEBUG){
      Serial.print(spd);
      Serial.println("fwd clk turn");
    }*/
    
    L_spd = spdV - yawV;
    R_spd = spdV + yawV;
    
    RMotor = true;
    LMotor = true;
  }
  else if (spd<0 && yawRate>=0){
    /*if(DEBUG){
      Serial.print(spd);
      Serial.println("back cclk turn");
    }*/
    
    L_spd = spdV + yawV;
    R_spd = spdV - yawV;
    
    RMotor = 0;
    LMotor = 0;
  }
  else if (spd<0 && yawRate<0){
    /*if(DEBUG){
      Serial.print(spd);
      Serial.println("back clk turn");
    }*/
    
    L_spd = spdV - yawV;
    R_spd = spdV + yawV;
    
    RMotor = 0;
    LMotor = 0;
  }
  else if (spd==0 && yawRate>0){
    /*if(DEBUG){
      Serial.print(spd);
      Serial.println("cclk turn");
    }*/
    
    L_spd =  yawV;
    R_spd =  yawV;
    RMotor = 0;
    LMotor = true;
    
  }
  else if (spd==0 && yawRate<0){
    /*if(DEBUG){
      Serial.print(spd);
      Serial.println("clk turn");
    }*/
    
    L_spd = yawV;
    R_spd = yawV;
    
    RMotor = true;
    LMotor = 0;
  }
  else{
    /*if(DEBUG){
      Serial.print(spd);
      Serial.println("break");
    }*/
    
    L_spd = 0;
    R_spd = 0;
    RMotor = 0;
    LMotor = 0;
  }
  
    if (L_spd>255)L_spd=255;
    if (R_spd>255)R_spd=255;
    if (L_spd<0)L_spd=0;
    if (R_spd<0)R_spd=0;
   
   
//  if(DEBUG){
//      Serial.print(L_spd);
//      Serial.print("\t");
//      Serial.print(R_spd);
//      Serial.print("\t");
//      Serial.print(LMotor);
//      Serial.print("\t");
//      Serial.print(RMotor);
//    }
//    
   
  digitalWrite(MOTOR_LFT,LMotor);
  digitalWrite(MOTOR_RGT,RMotor);
  
  writePWM_LFT(L_spd);
  writePWM_RGT(R_spd);
//  Serial.println();
}
