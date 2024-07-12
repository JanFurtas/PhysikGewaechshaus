
# Gewächshaus

Ein Smartes Gewächshaus mit steuerbaren Funktionen.

## Bentötigte Bauteile

- Arduino + Zubehör

- [Displays](https://www.amazon.de/MakerHawk-Anzeigemodul-Bildschirm-kompatibel-Mikrocontollern/dp/B07BDFXFRK/ref=sr_1_5?crid=26JO694EUDBJR&dib=eyJ2IjoiMSJ9.qhN9fmLFtGSf4nL71_NsIGHLWXPLamr6_TYwHejcZahnZKyb3SPwcqzzCuOQ_9S4mv-3kIrWumDJ4602eRrNXJnMDnGBCl9hPuIB3k9Vug9E6ghqspgtyN5V7d2CAvuQoQo8t9FdLjCejFEMOiIBMzHgq0FeTpi6q9euNRnJRCYbkrDmjWNYdzyaTb3MHIF43ZMdS9_yz6-BkPpxFbfI57cw2aGhnwkTjg2UUmhIpCQ.VNaGPGOFKlP4cV47bVAhU6Y8jTwAf-LCHkic7ha04fc&dib_tag=se&keywords=arduino%2Bdisplay%2Bi2c&qid=1720822650&sprefix=arduino%2Bdispl%2Caps%2C197&sr=8-5&th=1)

- [Temperatur & Luftfeuchtigkeit Sensor](https://www.amazon.de/AZDelivery-Temperatursensor-Luftfeuchtigkeitssensor-Platine-Arduino/dp/B078SVZB1X/ref=sr_1_3?crid=6M6FQL8PUZKQ&dib=eyJ2IjoiMSJ9.J-FR0IoZwnzinf-GYqv-VtQLvBqXhvbBnoHrCh8uspdZyGAw_xJrsXG47KISSqTzLVUXkEKWTYMqLcrLIo7VeqaAlkg8E8AkNfI5ldeh0V02WYcll_yl1MHNP2klNOud7R9whCrJfpNXgMjiaR7YmEMjZlkJhH8A2n8eCW4fRx0Wa63R03b9oUhqVSzGlG82CjCn5yNRdzcDPr3J33uxXLzlC7xN-WFd5K6tXmlhTXE.K-7-73mXKjiXvm6LHPq5xemtp-AK10a-eY0O1m-Rlz4&dib_tag=se&keywords=arduino+luftfeuchtigkeitssensor&qid=1720822733&sprefix=arduino+luft%2Caps%2C131&sr=8-3)

- [Controller](https://www.amazon.de/HALJIA-Simulieren-elektronische-Analog-Taste-Kompatibel/dp/B07QM7VBP1/ref=sr_1_2?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=3MDS4CP3HOO0U&dib=eyJ2IjoiMSJ9.wnCJrdjrSRpZg4lkMHbLjeTK7LCIsK6tC90xIt0b_8we0cPTt2KOp3CdUgm8PNv7DJ3Bu_PM3TUYQKzVV8URmj3hcwWhMtLOvBwUTlkd4fb1pXNSRlAgwzhs7DWXxp90KdTjGfDEVlR3ipamPTcqWUQr6AFMQ3Eq529GqxBV0BeazeBTN01aiR4j91cnuWAfiI4YZfREm61siAp3dYvpSRXPs02mM30JveGVX22PwyY.Y49H0WvN8yAVENbe1eq4ku3-OBx-60g9Y39_IykUUvs&dib_tag=se&keywords=arduino+5+key+keyboard&qid=1720822800&sprefix=arduino+5+key+keyboard%2Caps%2C86&sr=8-2)

- [Bewässerungssystem](https://www.amazon.de/WayinTop-Automatische-Bew%C3%A4sserung-Bew%C3%A4sserungssystem-Bodenfeuchtesensor/dp/B07TJQSHR2/ref=sr_1_6?crid=2DD1YCUW6QNXI&dib=eyJ2IjoiMSJ9.cYCCQ6lCzf_qstWXYhe7zPE1LSY64ynaQp7NXJM5lk2TVFfJDoDDhwHMxjrKV7Q1EnjdmyK1ZGYn3pDzOb9YeNX24LtIeAaK4VLWDGqt7WmOCaAlCosKVtMQTa6AjRcEmI4BxjO7lv7V601PZ8L-xMoNhJ1UrkONQ-t80hGMZkHDH57WP94KBIK7GT0ch-8-TDhyOi4WVW1MtEC4dpddBP-RgeY-t35kk88eUjJmBnadLf-nICpwNKjJDCGELUXIqlLk8Bi6S4y-R5D_e3DZtNGYn-SRWbRQIk5B4FbjCTI.tYU4MjNufdQlOVo6TwNYwHfSLtAkV6xNKjwDWruEs0s&dib_tag=se&keywords=arduino+bew%C3%A4sserung+kit&qid=1720822861&sprefix=arduino+bew%2Caps%2C182&sr=8-6)
## Infos

Die Anschlüsse

```C++

13 #define DHTPIN 2 //Digitaler Pin
...
20 int KeyPin = A0; //Analoger Pin
...
PUMPE 
```

müssen je nach Anschluss verändert werden.
## Controller

Jede Taste auf dem Controller hat eigene Werte. Diese sind nicht auf jedem Controller identisch. Um die Werte herauszufinden kann man die [ezAnalogKeypad](https://www.arduino.cc/reference/en/libraries/ezanalogkeypad/) libary verwenden. Mit dieser kann man das **Calibration** example benutzen und so die Werte der jeweiligen Tasten bestimmen. Die Werte sind nicht eindeutig, weshalb man einen Puffer bestimmt. In der Regel nimmt man +10 und -10 von den Werten.
Mit ```Key_read = analogRead(KeyPin);``` erhält man die Werte in seinem eigenen Skript.
Durch if-Anweisungen weist man dann den Werten die jeweilige Taste zu:

```C++

  if (Key_read<10){
    Key_id="LEFT";}

  if (Key_read>140 and Key_read<150) {
    Key_id="UP";}

  if (Key_read>490 and Key_read<505){
     Key_id="RIGHT";}

  if (Key_read>320 and Key_read<330) {
    Key_id="DOWN";}
    
  if (Key_read>730 and Key_read<740) {
    Key_id="SELECT";}
```