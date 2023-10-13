int ledPin   = 5;               // Pin where the LED is hooked up
int inputPin = 19;               // Pin where teh Radar Sensor is hooked up
int motion   = 0;               // State of motion
int bandera_Mov=0;

void setup() {
  pinMode(ledPin, OUTPUT);      // Declare the LED pin as output
  pinMode(inputPin, INPUT);     // Declare the sensor pin as input 
  Serial.begin(9600);
};


void loop() {
  motion = digitalRead(inputPin);  // Read the input pin
  
  if (motion == HIGH && bandera_Mov==0) { 
    digitalWrite(ledPin, HIGH);   // Turn on the LED
    bandera_Mov=1;
    Serial.println("Motion Detected!");
    delay(4000);
  } else if (motion == LOW && bandera_Mov==1) {
    digitalWrite(ledPin, LOW && bandera_Mov==1);    // Turn off the LED
    Serial.println("No Motion Detected!");
    bandera_Mov=0;
    delay(4000);
  };

  delay(1000);
};
