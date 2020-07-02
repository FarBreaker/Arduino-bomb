#include <Keypad.h>
#include <LiquidCrystal.h>

#define wires 3

//lcd section
LiquidCrystal lcd(7,6,5,4,3,2);

//keypad section
const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[ROWS] = {19,18,17,16};
byte colPins[COLS] = {15,14,12,13};
char keys[ROWS][COLS] = 
{
{'1','2','3','A'} ,
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'},
};
Keypad keypad = Keypad (makeKeymap(keys), rowPins, colPins, ROWS,COLS);

//opt section

int wire = 0;
byte signalPin = 11;
byte wirePin1 = 10;
byte wirePin2 = 9;
byte wirePin3 = 8;
unsigned long previousMillis = 0;
const long interval = 1000;
long totalTime = 1800;
long currentTime = totalTime;


void setup()
{
  
  pinMode(signalPin, OUTPUT);
  pinMode(wirePin1,INPUT);
  pinMode(wirePin2,INPUT);
  pinMode(wirePin3,INPUT);
  lcd.begin(16,2);
 // printSystem();
}

void loop()
{
  //var setup section
  char key = keypad.getKey();
  int wireSignal1 = digitalRead(wirePin1);
  int wireSignal2 = digitalRead(wirePin2);
  int wireSignal3 = digitalRead(wirePin3);
  
  if (key)
  {
    lcd.setCursor(0,1);
    lcd.print(key);
    buzz();
  }
  
  timer();
  
   if(wireSignal1 == LOW)
  {
   wire = 1;
  }
  else if(wireSignal2 == LOW)
  {
    wire = 2;
  }
  else if(wireSignal3 == LOW)
  {
    wire = 3;
  }
  else
  {
    wire =0;
  }
  
  switch(wire) //Wire detach code
  {
    case 0:
    
    break;
    case 1:
    
    break;
    case 2:
    
    break;
    case 3:
  
    break;
  }
}
void timer()
{
   unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    currentTime--;
  }
  lcd.setCursor(0,0);
  lcd.print(currentTime);
  
}

void buzz()
{
  digitalWrite(signalPin,HIGH);
  delay(20);
  digitalWrite(signalPin,LOW);
}

void printSystem()
{
lcd.print("   A.L.I.B.I.");
lcd.setCursor(0,1);
lcd.print("    Systems");
}
