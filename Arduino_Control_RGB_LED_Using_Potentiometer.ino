//viral science
//RGB LED
//https://www.youtube.com/watch?v=me1RfWensQE&list=PLUWZpHJMEu-Dv5Va5AmPeZH-E8-v9038u&index=145
//https://www.viralsciencecreativity.com/post/arduino-control-rgb-led-using-potentiometer
#define redPin 9 // Pin for the red RGB led pin
#define greenPin 10 // Pin for the green RGB led pin
#define bluePin 11 // Pin for the blue RGB led pin

#define potPin_red A2 // declare pin for the potentiometer for the red LED
#define potPin_green A1 // declare pin for the potentiometer for the green LED
#define potPin_blue A0 // declare pin for the potentiometer for the blue LED

// declare variable to store the read value from the potentiometer which controls the LEDs
int readValue_red, readValue_green, readValue_blue;

// declare variable to send to the LEDs
int writeValue_red, writeValue_green, writeValue_blue;
 
void setup()
{
  //Serial setup
  Serial.println("-= HC-05 Bluetooth RGB LED =-");
  Serial.begin(9600);
 
  pinMode(potPin_red, INPUT);
  pinMode(potPin_green, INPUT);
  pinMode(potPin_blue, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
/*
  setColor(255, 0, 0);
  delay(500);
  setColor(0, 255, 0);
  delay(500);
  setColor(0, 0, 255);
  delay(500);
  setColor(255, 255, 255);
*/
}
void loop() {
  readValue_red = analogRead(potPin_red);
  readValue_green = analogRead(potPin_green);
  readValue_blue = analogRead(potPin_blue);
 
  writeValue_red =  map(readValue_red, 0, 1023, 0, 255);
  writeValue_green = map(readValue_green, 0, 1023, 0, 255);
  writeValue_blue = map(readValue_blue, 0, 1023, 0, 255);

  setColor(writeValue_red, writeValue_green, writeValue_blue);

  Serial.print("Red: ");
  Serial.print(writeValue_red);
  Serial.print(", Green: ");
  Serial.print(writeValue_green);
  Serial.print(", Blue: ");
  Serial.print(writeValue_blue);
  Serial.println();
  delay(500);
}
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
