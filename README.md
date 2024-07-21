
# Gewächshaus


## Bentötigte Bauteile

- Arduino + Zubehör

- [Displays](https://www.amazon.de/MakerHawk-Anzeigemodul-Bildschirm-kompatibel-Mikrocontollern/dp/B07BDFXFRK/ref=sr_1_5?crid=26JO694EUDBJR&dib=eyJ2IjoiMSJ9.qhN9fmLFtGSf4nL71_NsIGHLWXPLamr6_TYwHejcZahnZKyb3SPwcqzzCuOQ_9S4mv-3kIrWumDJ4602eRrNXJnMDnGBCl9hPuIB3k9Vug9E6ghqspgtyN5V7d2CAvuQoQo8t9FdLjCejFEMOiIBMzHgq0FeTpi6q9euNRnJRCYbkrDmjWNYdzyaTb3MHIF43ZMdS9_yz6-BkPpxFbfI57cw2aGhnwkTjg2UUmhIpCQ.VNaGPGOFKlP4cV47bVAhU6Y8jTwAf-LCHkic7ha04fc&dib_tag=se&keywords=arduino%2Bdisplay%2Bi2c&qid=1720822650&sprefix=arduino%2Bdispl%2Caps%2C197&sr=8-5&th=1)

- [Temperatur & Luftfeuchtigkeit Sensor](https://www.amazon.de/AZDelivery-Temperatursensor-Luftfeuchtigkeitssensor-Platine-Arduino/dp/B078SVZB1X/ref=sr_1_3?crid=6M6FQL8PUZKQ&dib=eyJ2IjoiMSJ9.J-FR0IoZwnzinf-GYqv-VtQLvBqXhvbBnoHrCh8uspdZyGAw_xJrsXG47KISSqTzLVUXkEKWTYMqLcrLIo7VeqaAlkg8E8AkNfI5ldeh0V02WYcll_yl1MHNP2klNOud7R9whCrJfpNXgMjiaR7YmEMjZlkJhH8A2n8eCW4fRx0Wa63R03b9oUhqVSzGlG82CjCn5yNRdzcDPr3J33uxXLzlC7xN-WFd5K6tXmlhTXE.K-7-73mXKjiXvm6LHPq5xemtp-AK10a-eY0O1m-Rlz4&dib_tag=se&keywords=arduino+luftfeuchtigkeitssensor&qid=1720822733&sprefix=arduino+luft%2Caps%2C131&sr=8-3)

- [Controller](https://www.amazon.de/HALJIA-Simulieren-elektronische-Analog-Taste-Kompatibel/dp/B07QM7VBP1/ref=sr_1_2?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=3MDS4CP3HOO0U&dib=eyJ2IjoiMSJ9.wnCJrdjrSRpZg4lkMHbLjeTK7LCIsK6tC90xIt0b_8we0cPTt2KOp3CdUgm8PNv7DJ3Bu_PM3TUYQKzVV8URmj3hcwWhMtLOvBwUTlkd4fb1pXNSRlAgwzhs7DWXxp90KdTjGfDEVlR3ipamPTcqWUQr6AFMQ3Eq529GqxBV0BeazeBTN01aiR4j91cnuWAfiI4YZfREm61siAp3dYvpSRXPs02mM30JveGVX22PwyY.Y49H0WvN8yAVENbe1eq4ku3-OBx-60g9Y39_IykUUvs&dib_tag=se&keywords=arduino+5+key+keyboard&qid=1720822800&sprefix=arduino+5+key+keyboard%2Caps%2C86&sr=8-2)

- [Bewässerungssystem](https://www.amazon.de/WayinTop-Automatische-Bew%C3%A4sserung-Bew%C3%A4sserungssystem-Bodenfeuchtesensor/dp/B07TJQSHR2/ref=sr_1_6?crid=2DD1YCUW6QNXI&dib=eyJ2IjoiMSJ9.cYCCQ6lCzf_qstWXYhe7zPE1LSY64ynaQp7NXJM5lk2TVFfJDoDDhwHMxjrKV7Q1EnjdmyK1ZGYn3pDzOb9YeNX24LtIeAaK4VLWDGqt7WmOCaAlCosKVtMQTa6AjRcEmI4BxjO7lv7V601PZ8L-xMoNhJ1UrkONQ-t80hGMZkHDH57WP94KBIK7GT0ch-8-TDhyOi4WVW1MtEC4dpddBP-RgeY-t35kk88eUjJmBnadLf-nICpwNKjJDCGELUXIqlLk8Bi6S4y-R5D_e3DZtNGYn-SRWbRQIk5B4FbjCTI.tYU4MjNufdQlOVo6TwNYwHfSLtAkV6xNKjwDWruEs0s&dib_tag=se&keywords=arduino+bew%C3%A4sserung+kit&qid=1720822861&sprefix=arduino+bew%2Caps%2C182&sr=8-6)
## Infos

Die Anschlüsse

```C++

13 #define DHTPIN 2 // Anschluss für den Temperatur Sensor
...
20 int KeyPin = A0; // Anschluss für den Controller
...
39 int IN1 = 4; // Anschluss für den Bodenfeuchtigkeitssensor 1
40 int IN2 = 7; // Anschluss für denBodenfeuchtigkeitssensor 2
41 int IN3 = 11; // Anschluss für den Bodenfeuchtigkeitssensor 3 
42 int IN4 = 12; // Anschluss für den Bodenfeuchtigkeitssensor 4
43 int Pin1 = A1; // Anschluss 1 der Pumpensteuerung 
44 int Pin2 = A2; // Anschluss 2 der Pumpensteuerung
45 int Pin3 = A3; // Anschluss 3 der Pumpensteuerung
46 int Pin4 = A4; // Anschluss 4 der Pumpensteuerung
```

müssen je nach Anschluss verändert werden.
## Controller

Ersteinmal schließt man den Controller an:
```
OUT --> A0
VCC --> 5V
GND --> GND
```

Jede Taste auf dem Controller hat eigene Werte. Diese sind nicht auf jedem Controller identisch. Um die Werte herauszufinden kann man die [ezAnalogKeypad](https://www.arduino.cc/reference/en/libraries/ezanalogkeypad/) libary verwenden. Mit dieser kann man das **Calibration** example benutzen und so die Werte der jeweiligen Tasten bestimmen. Die Werte sind nicht eindeutig, weshalb man einen Puffer bestimmt. In der Regel nimmt man +10 und -10 von den Werten.
Mit ```Key_read = analogRead(KeyPin);``` erhält man die Werte in seinem eigenen Skript.
Durch if-Anweisungen weist man dann den Werten die jeweilige Taste zu:

```C++

  98 if (Key_read<10){
  99    Key_id="LEFT";}

  105 if (Key_read>140 and Key_read<150) {
  106   Key_id="UP";}

  129 if (Key_read>490 and Key_read<505){
  130   Key_id="RIGHT";}

  137 if (Key_read>320 and Key_read<330) {
  138   Key_id="DOWN";}
    
  166 if (Key_read>730 and Key_read<740) {
  167   Key_id="SELECT";}
```
## Display

Für das Display kann man die [Adafruit SSD1306](https://www.arduino.cc/reference/en/libraries/adafruit-ssd1306/) libary verwenden. Dazu benötigt man noch folgende libaries: [SPI](https://www.arduino.cc/reference/en/language/functions/communication/spi/) [WIRE](https://www.arduino.cc/reference/en/language/functions/communication/wire/)  und Optional noch [Adafruit GFX](https://www.arduino.cc/reference/en/libraries/adafruit-gfx-library/) mit dieser kann man verschiedene Schriftarten importieren.
 ```
 8 #include <Fonts/FreeSans9pt7b.h>
 ```

 Das Display schließt man nun folgendermaßen an:

```
GND --> GND
VCC --> 5V
SCL --> SCL
SDA --> SDA
```

Ebenfalls muss man die Höhe, die Breite und die Addresse des Displays angeben:
```
11 #define SCREEN_WIDTH 128 // Breite
12 #define SCREEN_HEIGHT 32 // Höhe
16 #define SCREEN_ADDRESS 0x3C // Addresse
```

Um nun ein Bild zu erzeugen nutzt man diese Befehle:
```
  display.clearDisplay(); // Display leeren (IMMER MACHEN BEI NEUEN SACHEN!!)
  display.setTextSize(1); // Legt die Textgröße fest
  display.setFont(&FreeSans9pt7b); // Legt die Schriftart fest.
  display.setCursor(0, 25); // Den Text Positonieren x-Achse ist vor dem Komma, und die y-Achse dahinter
  display.setTextColor(SSD1306_WHITE); // Legt die Schriftfarbe fest
  display.println("Beliebiger Text"); // Texte auf dem Display Anzeigen
  display.display(); // NIE VERGESSEN: Die eben genannten Sachen anzeigen lassen

```
## Temperatursensor

Für den Sensor kann man die [DHT](https://www.arduino.cc/reference/en/libraries/dht-sensor-library/) libary verwenden

Ersteinmal muss man den Sensor verbinden
```
+ --> 5V
OUT --> 2
- --> GND
```
Danach muss man den Anschluss und den Sensorentypen festlegen
```
#define DHTPIN 2 // Digitaler Pin 2
#define DHTTYPE DHT22 // Legt den Sensortyp fest
```

Nun kann man einfach die Werte mit den Befehlen ```dht.readHumidity();``` und ```dht.readTemperature();``` auslesen. 
## Bodenfeuchtigkeitssensor

So werden die 4 Sensoren angeschlossen:
```
GND --> GND
VCC --> 3.3V
AOUT --> A1/A2/A3/A4
```
Nun muss man die Anschlüsse noch im Code Festlegen:
```
43 int Pin1 = A1;
44 int Pin2 = A2;
45 int Pin3 = A3;
46 int Pin4 = A4;
```
Um die ausgelesenen Werte noch Abspeichern zu können, muss man Vier Variablen erstellen:
```
47 float value1 = 0;
48 float value2 = 0;
49 float value3 = 0;
50 float value4 = 0;
```

Jetzt kann man den Variablen die Werte zuweisen:
```
258 value1 = analogRead(Pin1);
259 value2 = analogRead(Pin2);
260 value3 = analogRead(Pin3);
261 value4 = analogRead(Pin4);
```

## Pumpe

Die Pumpen werden zuerst mit dem Relais verbunden. Dabei kommt ein Anschluss in den 5V Anschluss des Arduinos und der andere in das Relais. Ein Weiterer 5V Anschluss kommt nun direkt in das Relais.

Schließlich verbindet man das Relais noch mit dem Board:
```
GND --> GND
IN1 --> 4
IN2 --> 7
IN3 --> 11
IN4 --> 12
```

Jetzt kann man die Anschlüsse im Code festlegen:
```
37 int IN1 = 4;
38 int IN2 = 7;
39 int IN3 = 11;
40 int IN4 = 12;
```

Um nun die Pumpe zu steuern, wird erst überprüft, ob der Bodenfeuchtigkeitswert über dem Maximalwert liegt. Wenn das der Fall ist, wird die jeweilige Pumpe ausgelöst.

```

412 if (value1 > preSave1){
413     digitalWrite(IN1, LOW);
414 }
415 else {
416     digitalWrite(IN1, HIGH);
417 }
418 if (value2 > preSave2){
419     digitalWrite(IN2, LOW);
420 }
421 else {
422     digitalWrite(IN2, HIGH);
423 }
424 if (value3 > preSave3){
425     digitalWrite(IN3, LOW);
426 }
427 else {
428     digitalWrite(IN3, HIGH);
429 }
430 if (value4 > preSave4){
431     digitalWrite(IN4, LOW);
432 }
433 else {
434     digitalWrite(IN4, HIGH);
435 }
```
## Menü-funktion

Das Menü wird gesteuert, indem die menu_id variable erhöht/gesenkt wird, wenn man die UP/DOWN Taste drückt.
Drückt man nun Select so wird die passende Funktion zu der jeweiligen menu_id ausgewählt.
