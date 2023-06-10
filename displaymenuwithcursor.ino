#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const byte leftButtonPin = 7;         // Pin 7 for "left"  command
const byte rightButtonPin = 8;       // Pin 8 for "right" command
const byte enterButtonPin = 9;      // Pin 9 for "Enter" command



//Menu Arrays
String MenuOptions [] = {"Cucumber       ", "Lettuce         ", "Chive       ", "Battery        ","Power Off         "};
// Set the LCD address to 0x27 for a 16 chars and 2 line display

boolean buttonStateLeft = LOW;              // Button states for the "Left"  command
boolean lastButtonStateLeft = LOW;                
boolean currentButtonStateLeft  = LOW;
boolean buttonStateRight = LOW;            // Button states for the "Right"  command
boolean lastButtonStateRight = LOW;                
boolean currentButtonStateRight  = LOW; 
boolean buttonStateEnter = LOW;           // Button states for the "Enter"  command
boolean lastButtonStateEnter = LOW;
boolean currentButtonStateEnter  = LOW;                

template< typename T, size_t NumberOfSize > 
size_t MenuItemsSize(T (&) [NumberOfSize]){ return NumberOfSize; }
int numberOfMenuItems = MenuItemsSize(MenuOptions) - 1;
int currentMenuItem = 0;
int previousMenuItem = 1;
byte button_flag = 0;
unsigned long previousMillis = millis();



LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  pinMode(leftButtonPin, INPUT);      //  SETS THE leftPuttonPin AS AN INPUT
  pinMode(rightButtonPin, INPUT);    // SETS  THE rightButtonPin AS AN INPUT
  pinMode(enterButtonPin, INPUT);   // SETS THE  enterButtonPin AS AN INPUT
	// initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  for(int i = 0; i < 11; i ++){
    lcd.print(".");
    delay(300);
    lcd.setCursor(i,0);
  }
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("PLANTER-TRON 1.0");
  delay(4000);
  lcd.clear();
  lcd.print("Select an Option:");
}

void menuFunctions(int menu)  // Your menü functions
{
  lcd.clear();
  lcd.setCursor(0,0);

  if(menu == 1) {
    lcd.print("BROCCOLI SELECTED");
    lcd.setCursor(0,1);
    lcd.print("shit dont work bruh");
  }
  if(menu == 2) // example function for 2. menü item
  {
    lcd.print("LETTUCE SELECTED");
    lcd.setCursor(0,1);
    lcd.print("shit dont work bruh");
  }
  if(menu == 3)
  {
    lcd.print("CUCUMBER SELECTED");
    lcd.setCursor(0,1);
    lcd.print("shit dont work bruh");
  }
  if(menu == 4)
  {
    lcd.print("BATTERY SELECTED");
    lcd.setCursor(0,1);
    lcd.print("it dead bruh");
  }
    if(menu == 5)
  {
    lcd.print("exit");
    lcd.setCursor(0,1);
    lcd.print("cant even kys lol");
  }
  delay(10000);
}

void loop()
{
	lcd.setCursor(0,1);
  lcd.print(MenuOptions[currentMenuItem]);

  currentButtonStateLeft = digitalRead(leftButtonPin);
  currentButtonStateRight = digitalRead(rightButtonPin);
  currentButtonStateEnter = digitalRead(enterButtonPin);

    if (currentButtonStateRight != buttonStateRight){ // if left button is pressed
      buttonStateRight = currentButtonStateRight;
      currentMenuItem--;
      if(currentMenuItem < 0)
      {
        currentMenuItem = 0;
      }
    }

    if (currentButtonStateLeft != buttonStateLeft){ // if left button is pressed
      buttonStateLeft = currentButtonStateLeft;
      ++currentMenuItem;
      if(currentMenuItem > numberOfMenuItems ){
        currentMenuItem = numberOfMenuItems;
      }
    }

    if (currentButtonStateEnter != buttonStateEnter){ // if enter is pressed
      buttonStateEnter = currentButtonStateEnter;
      menuFunctions(currentMenuItem);
    }

  lastButtonStateLeft  = currentButtonStateLeft;       // resets the left button state to LOW
  lastButtonStateRight  = currentButtonStateRight;     // resets the right button state to LOW
  lastButtonStateEnter  = currentButtonStateEnter;     // resets the enter button state to LOW
  delay(400);
}