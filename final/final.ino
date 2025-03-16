const int ledPin = 9;          // LED connected to digital pin 9
const int buttonPin = 2;       // Button connected to digital pin 2
const int sensorPin = 3;       // Flying Fish Distance Sensor connected to digital pin 3
const int lightPin = A0;

int sensorValue = 0;
int buttonState = 0;           // Variable to hold the button state
int sensorState = 0;           // Variable to hold the sensor state

void setup() {
  pinMode(ledPin, OUTPUT);     // Set the LED pin as an output
  pinMode(buttonPin, INPUT_PULLUP);   // Set the button pin as an input with internal pull-up resistor
  pinMode(sensorPin, INPUT);   // Set the sensor pin as an input

  Serial.begin(9600);          // Start the serial monitor for debugging (optional)
}

void loop() {
  // Read the state of the button and the sensor
  buttonState = digitalRead(buttonPin);
  sensorState = digitalRead(sensorPin);
  sensorValue = analogRead(lightPin);

  // Debugging output (optional)
  Serial.print("Sensor State: ");
  Serial.println(sensorState);
  Serial.print("Button State: ");
  Serial.println(buttonState);

  // Invert the buttonState to get a correct HIGH when the button is pressed
  // Since INPUT_PULLUP will read HIGH when not pressed and LOW when pressed


  if(sensorValue <= 500 && buttonState == LOW && sensorState == LOW){
    digitalWrite(ledPin, HIGH);  // Turn on the LED when both are HIGH simultaneously
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED if either condition is not met
  }

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  delay(100);  // Small delay for stability
}




