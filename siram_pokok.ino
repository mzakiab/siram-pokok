/* 
 *  Projek nak siram pokok secara automatik - oleh 9W2KEY 2 Julai, 2020
 *  
 *  copy koding ini daripada website:
 *  https://www.instructables.com/id/Automatic-Garden-Watering-Device-Arduino/
 */

//This first section sets up our variables and initializes the LCD screen


int soil=0;
int Relay = 7;

int relay_level=60;

#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);
// the setup routine runs once when you press reset:

void setup() {

// initialize serial communication at 9600 bits per second:

Serial.begin(9600); // set up the LCD's number of columns and rows:

}

// the loop routine runs over and over again forever:

void loop() {

// read the input on analog pin 0:

int sensorValue = analogRead(A0);

sensorValue = constrain(sensorValue, 485, 1023);

// print out the value you read: Serial.println(sensorValue);

// initialize the digital pin as an output.

pinMode(Relay, OUTPUT);

//map the value to a percentage

soil = map(sensorValue, 485, 1023, 100, 0);

// print out the soil water percentage you calculated to the LCD Screen:

Serial.print(soil);

Serial.println(" %");

// set the cursor to column 0, line 1

// (note: line 1 is the second row, since counting begins with 0):
lcd.setBacklight(10);
lcd.begin(16, 2);

// Print a message to the LCD.

lcd.clear();

lcd.print("Ketepuan tanah :");

lcd.setCursor(0, 1);

// print the number of seconds since reset:

lcd.print(soil);

lcd.print (" % < 9W2KEY >");

// delay in between reads for stability

delay(2000); // asal 1000

if (soil < relay_level) {

digitalWrite(Relay, HIGH);

lcd.clear();

lcd.print("Proses menyiram!");

lcd.setCursor(0, 1);

lcd.print ("sila tunggu.....");

// turn the Relay on (HIGH is the voltage level)

delay(3000); // asal 60000
}
// wait for a minute
// asal tak de else
else{

digitalWrite(Relay, LOW);
}
// turn the LED off by making the voltage LOW

// delay(1000); // asal 60000

// wait for a minute

}
