void motor_initialize(){
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
  OCR0B = 249 ;   // min = 4, max = 249
  pinMode (3, OUTPUT) ; // motor 4
  TCCR2A = 0xA3 ;   //Set up mode fast PWM with TOP = OCR0A
  TCCR2B = 0x1A ;
  OCR2A = 249 ;  // set frequency at 8Khz
  OCR2B = 249 ;   // min = 4, max = 249

  delay(1000);

  OCR1A=0; //9 pin, min = 40, max = 1999
  OCR1B=0; //10 pin min = 40, max = 1999
  OCR0B=0; //5 pin, min = 4, max = 249
  OCR2B=0; //3 pin, min = 4, max = 249
}

void motor_all_stop()
{
  OCR1A=0; //9 pin, min = 40, max = 1999
  OCR1B=0; //10 pin min = 40, max = 1999
  OCR0B=0; //5 pin, min = 4, max = 249
  OCR2B=0; //3 pin, min = 4, max = 249
  delay(1000);
}

void motor1_write( double v)
{
  if (v < 5)
  return ;
  OCR1A = (v - 4) * 1959/249 + 40;  //This line mean 
                                   //(value - 8Tmin) * (16Tmax - 16Tmin) / (8Tmax - 8Tmin) + 16Tmin
}


void motor2_write( double v)
{
  if (v < 5)
  return ;
  OCR1B = (v - 4) * 1959/249 + 40;//This line mean 
                                 //(value - 8Tmin) * (16Tmax - 16Tmin) / (8Tmax - 8Tmin) + 16Tmin
}


void motor4_write( double v)
{
  if (v < 5)
  return ;
  OCR0B = v;
}


void motor3_write( double v)
{
  if (v < 5)
  return ;
  OCR2B = v;
}
void motor_up()
{
  OCR1A += 8;
  OCR1B += 8;
  OCR0B += 1;
  OCR2B += 1;
}

void motor_down()
{
  OCR1A -= 8;
  OCR1B -= 8;
  OCR0B -= 1;
  OCR2B -= 1;
}

void motor_up3()
{
  OCR2B += 1;
}


void motor_up5()
{
  OCR0B += 1;
}

void motor_up9()
{
  OCR1A += 1;
}

void motor_up10()
{
  OCR1B += 1;
}
