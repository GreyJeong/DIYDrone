int speakerPin = 8;

void speaker_initialize() {
  pinMode(speakerPin, OUTPUT);
  speaker_activate(GOOD);
}

void speaker_activate(char command)
{
  int sound = 500;
  int duration = 1000;
  
  switch(command){
   
    case GOOD :
      sound = 500;
      for(int i=0; i<4; i++)
      {
        tone(speakerPin, sound, duration);
        sound += 500;
        delay(duration * 1.30);  
      }
      break;

    case START : 
      sound = 1000;
      tone(speakerPin, sound, duration);
      break;

    case EXIT : 
      sound = 2000;
      for(int i=0; i<4; i++)
      {
        tone(speakerPin, sound, duration);
        sound -= 500;
        delay(duration * 1.30);
      }
      break;
 
    case ERROR1 :
      
      break;

    case ERROR2 : 
     
      break;

    case ERROR3 :
      
      break;
  
  }
}
