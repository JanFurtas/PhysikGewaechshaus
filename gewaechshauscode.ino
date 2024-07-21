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
int preSave1 = 500;
int preSave2 = 500;
int preSave3 = 500;
int preSave4 = 500;
// Watering
int IN1 = 4;
int IN2 = 7;
int IN3 = 11;
int IN4 = 12;
int Pin1 = A1;
int Pin2 = A2;
int Pin3 = A3;
int Pin4 = A4;
float value1 = 0;
float value2 = 0;
float value3 = 0;
float value4 = 0;



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

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);
  pinMode(Pin3, INPUT);
  pinMode(Pin4, INPUT);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(500);
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
    if (menu_id == 1 and select == 1 and preSave == 0){
      row = row-1;
      if (row < 1) row = 4;
      if (row > 4) row = 1;
    if (row == 1 and preSave == 1){
      preSave1 = preSave1+1;
    }
    if (row == 2 and preSave == 1){
      preSave2 = preSave2+1;
    }
    if (row == 3 and preSave == 1){
      preSave3 = preSave3+1;
    }
    if (row == 4 and preSave == 1){
      preSave4 = preSave4+1;
    }
  }
  }

  if (Key_read>490 and Key_read<505){
     Key_id="RIGHT";
    if(menu_id == 1 and select == 1){
      preSave = 1;}
    
  }


  if (Key_read>310 and Key_read<340) {
    Key_id="DOWN";
    if (select == 0){
      menu_id = menu_id+1;}
    statMenuId = statMenuId+1;

    if (menu_id == 1 and select == 1 and preSave == 0){
      row = row+1;}
    if (row < 1) row = 4;
    if (row > 4) row = 1;
    if (row == 1 and preSave == 1 and preSave1>0){
      preSave1 = preSave1-1;
      if (preSave1<0) preSave1 = 0;
    }
    if (row == 2 and preSave == 1 and preSave2>0){
      preSave2 = preSave2-1;
      if (preSave2<0) preSave2 = 0;
    }
    if (row == 3 and preSave == 1 and preSave3>0){
      preSave3 = preSave3-1;
      if (preSave3<0) preSave3 = 0;
    }
    if (row == 4 and preSave == 1 and preSave4>0){
      preSave4 = preSave4-1;
      if (preSave4<0) preSave4 = 0;
    }
    
    }
    
  if (Key_read>730 and Key_read<740) {
    Key_id="SELECT";
    select = 1;
  }


  if (menu_id < 0) menu_id=2;
  if (menu_id > 2) menu_id=0;
  if (statMenuId <1) statMenuId=3;
  if (statMenuId >3) statMenuId=1;
  if (Key_read!=Previous_Key and Key_read<1000){
    Serial.println(Key_id);
    Serial.println(menu_id);
    Serial.println(select);
    Serial.println(statMenuId);
    Serial.println(row);
    Serial.println(selectGroundHumidity);
  }
  delay(120);
}

// Menüs

void mainMenu(){
  switch(menu_id){
    case 0: 
      statMenu();
      break;
    case 1:
      preSettings();
      break;
    case 2:
      code();
      break;
  }
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
  else if (menu_id == 0 and select == 1){
    stats();
  }
  else if (menu_id == 1 and select == 1){
    modes();
  }
  else if (menu_id == 2 and select == 1){
    codeLink();
  }
}


// Funktionen & Sensoren

void stats(){
  // Luftfeuchtigkeit
  float humidity = dht.readHumidity();
  // Temp in °C
  float temp = dht.readTemperature();
  
  value1 = analogRead(Pin1);
  value2 = analogRead(Pin2);
  value3 = analogRead(Pin3);
  value4 = analogRead(Pin4);

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
      display.print("Bodenfeuchte: ");
      display.println(value1);
      display.println(value2);
      display.println(value3);
      display.println(value4);
      display.display();    
      break;

  }
}


void modes(){
  value1 = analogRead(Pin1);
  value2 = analogRead(Pin2);
  value3 = analogRead(Pin3);
  value4 = analogRead(Pin4);


  if (row == 1 and preSave == 0){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.setCursor(0, 8);
    display.setFont();
    display.println("Pumpe 1");
    display.setTextColor(SSD1306_WHITE);
    display.println("Pumpe 2");
    display.println("Pumpe 3");
    display.display();
  }

  if (row == 2 and preSave == 0){
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 8);
    display.setFont();
    display.setTextColor(SSD1306_WHITE);
    display.println("Pumpe 1");
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.println("Pumpe 2");
    display.setTextColor(SSD1306_WHITE);
    display.println("Pumpe 3");
    display.display();
  }

  if (row == 3 and preSave == 0){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.setCursor(0, 8);
    display.setFont();
    display.setTextColor(SSD1306_WHITE);
    display.println("Pumpe 1");
    display.println("Pumpe 2");
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.println("Pumpe 3");
    display.setTextColor(SSD1306_WHITE);
    display.display();
  }

  if (row == 4 and preSave == 0){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.setCursor(0, 8);
    display.setFont();
    display.setTextColor(SSD1306_WHITE);
    display.println("Pumpe 2");
    display.println("Pumpe 3");
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.println("Pumpe 4");
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
  
  if (row == 4 and preSave == 1){
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 8);
    display.setFont();
    display.setTextColor(SSD1306_WHITE);
    display.println("Bodenfeuchtigkeit:");
    display.println(preSave4);
    display.display();  
  }

  if (value1 > preSave1){
    digitalWrite(IN1, LOW);
  }
  else {
    digitalWrite(IN1, HIGH);
  }
  if (value2 > preSave2){
    digitalWrite(IN2, LOW);
  }
  else {
    digitalWrite(IN2, HIGH);
  }
  if (value3 > preSave3){
    digitalWrite(IN3, LOW);
  }
  else {
    digitalWrite(IN3, HIGH);
  }
  if (value4 > preSave4){
    digitalWrite(IN4, LOW);
  }
  else {
    digitalWrite(IN4, HIGH);
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






