// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
#include "DHT.h" // Temp Sensor
#include <SPI.h> // Display
#include <Wire.h> // Display
#include <Adafruit_GFX.h> // Display
#include <Adafruit_SSD1306.h> // Display
#include <Fonts/FreeSans9pt7b.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


int KeyPin = A0;
int Key_read;
String Key_id;
int Previous_Key=1023;
int menu_id = 0;
int select = 0;
int statMenuId = 0;
int groundHumidity = 0;
int row = 1;
int preSave = 0;
int preSave1 = 0;
int preSave2 = 0;
int preSave3 = 0;


//Pin 1 zu 5V
//Pin 2 zu Digital 2
//Pin 3 zu GND

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
  }
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

}

void loop() {
  keys();
  menuSelect();
}

// Kontroller einstellungen

void keys(){

  Key_read = analogRead(KeyPin);
  if (Key_read<10) {
    Key_id="LEFT";
    select = 0;
    preSave = 0;
  }


  if (Key_read>140 and Key_read<150) {
    Key_id="UP";
    if (select == 0){
    menu_id = menu_id-1;}
    statMenuId = statMenuId-1;
    if (menu_id == 2 and select == 1){
      groundHumidity = groundHumidity+1;}
    if (menu_id == 3 and select == 1 and preSave == 0){
      row = row-1;
      if (row < 1) row = 3;
      if (row > 3) row = 1;}
    if (row == 1 and preSave == 1){
      preSave1 = preSave1+1;
    }
    if (row == 2 and preSave == 1){
      preSave2 = preSave2+1;
    }
    if (row == 3 and preSave == 1){
      preSave3 = preSave3+1;
    }
    }


  if (Key_read>490 and Key_read<505){
     Key_id="RIGHT";
    if(menu_id == 3 and select == 1){
      preSave = 1;}
  }


  if (Key_read>320 and Key_read<330) {
    Key_id="DOWN";
    if (select == 0){
      menu_id = menu_id+1;}
    statMenuId = statMenuId+1;
    if (menu_id == 2 and select == 1){
      groundHumidity = groundHumidity+1;
      if (groundHumidity < 0) groundHumidity = 0;}
        if (menu_id == 3 and select == 1 and preSave == 0){
        row = row+1;
        if (row < 1) row = 3;
        if (row > 3) row = 1;
      }
    if (row == 1 and preSave == 1 and preSave1>0){
      preSave1 = preSave1-1;
      if (preSave1<0) preSave1 = 0;
    }
    if (row == 2 and preSave == 1 and preSave2>0){
      preSave2 = preSave2-1;
      if (preSave3<0) preSave2 = 0;
    }
    if (row == 3 and preSave == 1 and preSave3>0){
      preSave3 = preSave3-1;
      if (preSave3<0) preSave3 = 0;
    }
    }
    
  if (Key_read>730 and Key_read<740) {
    Key_id="SELECT";
    select = 1;
  }

  delay(110);

  if (menu_id < 0) menu_id=4;
  if (menu_id > 4) menu_id=0;
  if (statMenuId <1) statMenuId=3;
  if (statMenuId >3) statMenuId=1;
  if (Key_read!=Previous_Key and Key_read<1000){
    Serial.println(Key_id);
    Serial.println(menu_id);
    Serial.println(select);
    Serial.println(statMenuId);
    Serial.println(row);
  }
}

// Menüs

void mainMenu(){
  switch(menu_id){
    case 0:
      startMenu();
      break;
    case 1: 
      statMenu();
      break;
    case 2:
      manualSettings();
      break;
    case 3:
      preSettings();
      break;
    case 4:
      code();
      break;
  }
}

void startMenu(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 25);
  display.setTextColor(SSD1306_WHITE);
  display.setFont(&FreeSans9pt7b);
  display.println("Astraphysiker");
  display.display();
}
void statMenu(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 25);
  display.setFont(&FreeSans9pt7b);
  display.setTextColor(SSD1306_WHITE);
  display.println("Statistiken");
  display.display();
}

void manualSettings(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 25);
  display.setFont(&FreeSans9pt7b);
  display.setTextColor(SSD1306_WHITE);
  display.println("Einstellungen");
  display.display();
}

void preSettings(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(0, 25);
  display.setTextColor(SSD1306_WHITE);
  display.println("Modus");
  display.display();
}


void code(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(0, 25);
  display.setTextColor(SSD1306_WHITE);
  display.println("Code");
  display.display();
}



void menuSelect(){
  if (select == 0){
    mainMenu();
  }
  else if (menu_id == 1 and select == 1){
    stats();
  }
  else if (menu_id == 2 and select ==1){
    settings();
  }
  else if (menu_id == 3 and select == 1){
    modes();
  }
  else if (menu_id == 4 and select == 1){
    codeLink();
  }
}


// Funktionen & Sensoren

void stats(){
  // Luftfeuchtigkeit
  float humidity = dht.readHumidity();
  // Temp in °C
  float temp = dht.readTemperature();

  switch(statMenuId){
    case 1:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 8);
      display.setFont();
      display.println("Luftfeuchtigkeit: ");
      display.print(humidity);
      display.println("%");
      display.display();
      break;
    case 2:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 8);
      display.setFont();
      display.print("Temperatur: ");
      display.print(temp);
      display.println("C");
      display.display();
      break;
    case 3:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 8);
      display.setFont();
      display.println("Bodenfeuchtigkeit: ");
      display.print("Coming");
      display.println("C");
      display.display();    
      break;

  }
}

void settings(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 8);
  display.setFont();
  display.println("Bodenfeuchtigkeit: ");
  display.println(groundHumidity);
  display.display();    
}

void modes(){


  if (row == 1 and preSave == 0){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.setCursor(0, 8);
    display.setFont();
    display.println("Voreinstellung 1");
    display.setTextColor(SSD1306_WHITE);
    display.println("Voreinstellung 2");
    display.println("Voreinstellung 3");
    display.display();
  }

  if (row == 2 and preSave == 0){
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 8);
    display.setFont();
    display.setTextColor(SSD1306_WHITE);
    display.println("Voreinstellung 1");
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.println("Voreinstellung 2");
    display.setTextColor(SSD1306_WHITE);
    display.println("Voreinstellung 3");
    display.display();
  }

  if (row == 3 and preSave == 0){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.setCursor(0, 8);
    display.setFont();
    display.setTextColor(SSD1306_WHITE);
    display.println("Voreinstellung 1");
    display.println("Voreinstellung 2");
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.println("Voreinstellung 3");
    display.display();
  }



  if (row == 1 and preSave == 1){
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 8);
    display.setFont();
    display.setTextColor(SSD1306_WHITE);
    display.println("Bodenfeuchtigkeit:");
    display.println(preSave1);
    display.display();  
  }

  if (row == 2 and preSave == 1){
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 8);
    display.setFont();
    display.setTextColor(SSD1306_WHITE);
    display.println("Bodenfeuchtigkeit:");
    display.println(preSave2);
    display.display();  
  }

  if (row == 3 and preSave == 1){
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 8);
    display.setFont();
    display.setTextColor(SSD1306_WHITE);
    display.println("Bodenfeuchtigkeit:");
    display.println(preSave3);
    display.display();  
  }
}

void codeLink(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 5);
  display.setFont();
  display.setTextColor(SSD1306_WHITE);
  display.println("https://github.com/");
  display.println("JanFurtas/");
  display.println("PhysikGewaechshaus");
  display.display();
}