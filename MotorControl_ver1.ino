void motor_initialize() {
  // put your setup code here, to run once:
  pinMode (9, OUTPUT) ;
  pinMode (10, OUTPUT) ;
  TCCR1A = 0xA2 ;  // Set up mode 14, fast PWM with TOP=ICR1
  TCCR1B = 0x19 ;   // prescale is divide-by-1, so 2000 cycles = 125us
  ICR1  = 2000-1 ;    // counts from 0..1999 continuously
  OCR1A = 1500-1 ;  // set PWM duty
  OCR1B = 1500-1 ;
  pinMode (5, OUTPUT) ;
  TCCR0A = 0xA3 ;   //Set up mode fast PWM with TOP = OCR0A
  TCCR0B = 0x1A ;
  OCR0A = 249 ;  // set frequency at 8Khz
  OCR0B = 0 ;   // min = 3, max = 255
  pinMode (3, OUTPUT) ;
  TCCR2A = 0xA3 ;   //Set up mode fast PWM with TOP = OCR0A
  TCCR2B = 0x1A ;
  OCR2A = 249 ;  // set frequency at 8Khz
  OCR2B = 0 ;   // min = 3, max = 255
}

void motor_activate(int command)
{
      
}
