char clen[8];
char c;
byte b;
int count = 0;
int index = 0;

// the setup routine runs once when you press reset:
void setup()  { 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);

} 

void loop()  { 
  //light up all the lights to check.
  if (count==0){
      for (int i=2; i <= 10; i++){
        digitalWrite(i,HIGH);
      delay(500);
      digitalWrite(i,LOW);
      Serial.println(i);
    }
  }
  count=1;


  while (Serial.available()>0){
    if(index < 8){
      c = Serial.read();
      clen[index]=c;
            
      if(c=='0'){
        digitalWrite(index+2,LOW);
      }
      
      if(c=='1'){
        digitalWrite(index+2,HIGH);
      }
      index++;
      
    }
    else if(index >= 8){
      break;
    }
    }
  
  index=0;

}
