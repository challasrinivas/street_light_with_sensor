  /***** SMART STREET LIGHT USING SENSOR WITH AUTO INTENSITY LIGHT CONTROL *******/
 
#include <LiquidCrystal.h>
LiquidCrystallcd(8, 9, 10, 11, 12, 13); 
int inPin = 7; //irsensor
int ldr = A0;
int led=3; 
int value1 =0;  //ldr sensor value
int count=0;
//int sensorValue = 0;
int reading;
void setup()           
// put your setup code here, to run once:
  {
pinMode(inPin, INPUT);
pinMode(led,OUTPUT);
digitalWrite(led,LOW);

lcd.begin(16,2); lcd.clear();
lcd.setCursor(0,0);lcd.print("  SMART STREET ");
lcd.setCursor(0,1);lcd.print(" AUTO INTENSITY ");
delay(2000);

Serial.begin(9600);
Serial.println("******** SMART STREET LIGHT USING SENSOR WITH AUTO INTENSITY LIGHT CONTROL *********");
delay(2000);

  }

void loop()
// put your main code here, to run repeatedly:
  {
lcd.clear();
lcd.setCursor(0,0);lcd.print("  SMART STREET ");
lcd.setCursor(0,1);lcd.print(" AUTO INTENSITY ");
delay(2000);
Checkldrcondition();
Checkircondition();
  }

void Checkldrcondition()
  {

    value1 = analogRead(ldr);
    value1= constrain(value1,400,500);
    value1 = map(value1,400,500,255,0);
    Serial.print(" LIGHT VALUE: ");
    Serial.println(value1);
    Serial.println(analogRead(ldr));
    analogWrite(led, value1);
    delay(1000);


if (value1==0)
    {
      
    }
else if (value1>0 && value1<100)
    {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("LIGHT IS DIM");
lcd.setCursor(0,1);
lcd.print("   MEDIUM   ");          
delay(2000);
Serial.println("LIGHT IS DIM (MEDIUM)");
    }
else if (value1>100 && value1<200)
    {
lcd.clear();
digitalWrite(led,LOW);
lcd.setCursor(0,1);
lcd.print("LIGHT IS OFF  ");
delay(2000);
Serial.println("INTENSITY IS HIGH");
    }
else
    {
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" LIGHT IS ON ");
lcd.setCursor(0,1);
lcd.print(" LOW LIGHT ");
delay(2000);
Serial.println("LIGHT IS EXTREME");
    }
    }

void Checkircondition() 
  {
reading = digitalRead(inPin);
      {
if(reading == LOW)
              {
digitalWrite(led,HIGH);
count+=1;

lcd.clear(); 
lcd.setCursor(0,0);lcd.print("LIGHT ON");
lcd.setCursor(0,1);lcd.print("VEHICLE IN");

Serial.print(" TOTAL NUMBER OF VEHICLES PASSED THROUGH THE ROAD: ");   
Serial.println(count);
delay(3000);
              }
else
              {
              }
      }
  }




