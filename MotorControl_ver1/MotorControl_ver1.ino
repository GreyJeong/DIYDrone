void setup(){
  int currenttime=millis();
  pinMode (9, OUTPUT) ; //motor 1
  pinMode (10, OUTPUT) ; //motor 2
  TCCR1A = 0xA2 ;  // Set up mode 14, fast PWM with TOP=ICR1
  TCCR1B = 0x19 ;   // prescale is divide-by-1, so 2000 cycles = 125us
  ICR1  = 2000-1 ;    // counts from 0..1999 continuously
  OCR1A = 1999 ;  // min = 40, max = 1999;
  OCR1B = 1999 ; // min = 40, max = 1999;
  pinMode (5, OUTPUT) ; // motor 3
  TCCR0A = 0xA3 ;   //Set up mode fast PWM with TOP = OCR0A
  TCCR0B = 0x1A ;
  OCR0A = 249 ;  // set frequency at 8Khz
  OCR0B = 255 ;   // min = 3, max = 255
  pinMode (3, OUTPUT) ; // motor 4
  TCCR2A = 0xA3 ;   //Set up mode fast PWM with TOP = OCR0A
  TCCR2B = 0x1A ;
  OCR2A = 249 ;  // set frequency at 8Khz
  OCR2B = 255;   // min = 3, max = 255

  while(1)
  {
    if(millis()>currenttime+1000)
    break;
  }
  OCR1A=0;
  OCR1B=1999;
  OCR0B=1;
  OCR2B=0;
}

void motor_write1( float v)
{
    OCR1A=v*1999/255;
}


void motor_write2( float v)
{
    OCR1B=v*1999/255;
}


void motor_write3( float v)
{
    OCR0B=v;
}


void motor_write4( float v)
{
    OCR2B=v;
}

void motor_up()
{
  OCR0B+=1;
  OCR2B+=1;
  OCR1A=OCR2B*1999/255;
  OCR1B=OCR2B*1999/255;
}

void motor_down()
{
  OCR0B-=1;
  OCR2B-=1;
  OCR1A=OCR2B*1999/255;
  OCR1B=OCR2B*1999/255;
}

void loop(){
}
