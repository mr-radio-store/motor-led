/*
Motor control with result on OLED

Wire connection

1. L298 & motor
IN1	8	Direction control
IN2	9	Direction control
EN A (or PWM)	10	Speed control (PWM)
GND	GND	Common ground
VCC	5V or external	Motor driver logic power
Motor A+ / OUT1	Motor Terminal	One motor wire
Motor A- / OUT2	Motor Terminal	Other motor wire

2. OLED Display Wiring (I2C)
Your code uses I2C via the Wire library, so connect accordingly:
OLED Pin	Arduino Pin	Notes
VCC	3.3V or 5V	Depending on your OLED module
GND	GND	Ground
SCL	A5 (Uno/Nano)	I2C Clock
SDA	A4 (Uno/Nano)	I2C Data
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Motor pins
const int in1 = 8;
const int in2 = 9;
const int enA = 10;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);

  // Start OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true); // Halt if display not found
  }

  display.clearDisplay();
  display.setTextSize(2);  // Increase font size
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Motor");
  display.println("Ready");
  display.display();
  delay(2000);
}

void loop() {
  // Forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);

  display.clearDisplay();
  display.setTextSize(2);  // Large text
  display.setCursor(0, 0);
  display.println("FORWARD");
  display.setCursor(0, 30);
  display.println("SPD:200");
  display.display();
  delay(4000);

  // Backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);

  display.clearDisplay();
  display.setTextSize(2);  // Large text
  display.setCursor(0, 0);
  display.println("BACKWARD");
  display.setCursor(0, 30);
  display.println("SPD:200");
  display.display();
  delay(4000);
}
