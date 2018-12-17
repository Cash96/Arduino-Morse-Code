const int ledPin = 13;
//const int dotDelay = 200;

char alph_num[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', 
                  '1', '2', '3', '4','5', '6', '7', '8' , '9' };

char* m_code[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",         // S-Z
  "-----", ".----", "..---", "...--", "....-", ".....", "-....",    // 0-9
  "--...", "---..", "----."
};
              
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


  void dotOrdash(char code[], int delayDot)
{

  int code_size = strlen(code);
  int delayDash = delayDot * 3;
  
  for(int k = 0; k < code_size; k++)
    {
      digitalWrite(ledPin, HIGH);
      if(code[k] == '.')
      {
        Serial.println(delayDot);
        delay(delayDot);
      }
      else
      {
        Serial.println(delayDash);
        delay(delayDash);
      }
      digitalWrite(ledPin, LOW);
      delay(delayDot);
      
      
    }
}

void loop() {
  // loops through each char in string
  // send letter and delay into dotOrdash
  
  int dotDelay = 200;
  char ch;
  
  while(Serial.available() > 0)
  {
    ch = Serial.read();
    
    for(int i = 0; i < 36; i++)
    {
      if(ch == alph_num[i])
      {
        dotOrdash(m_code[i], dotDelay);
      }
      else if(ch == ' ')
      {
        Serial.print(1000);
        delay(1000);
        break;
        
      }
    }
  }
}
