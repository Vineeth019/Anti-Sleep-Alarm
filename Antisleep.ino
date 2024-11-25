#define Relay 13
#define buzzer A0
static const int sensorPin = 10;    // sensor input pin         
void setup() {
  Serial.begin(9600);                 // Initialise the serial monitor

  pinMode(sensorPin, INPUT);          // set sensorPin as input
  pinMode(Relay,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
// Function for reading the sensor state
void readSensorState() {

    // Read the digital value of the sensor (0/1)
    int SensorState = digitalRead(sensorPin);   
    Serial.print("SensorState: "); 
    Serial.println("SensorState:"); 

    // sensor is off means eye is open  
    if (SensorState == 0 ) {

      digitalWrite(Relay,HIGH);
      digitalWrite(buzzer,LOW);
      Serial.println("eye is open (0) ,motor is ON");
      delay(3000);
    }
    // sensor if on means eye is close
    if (SensorState == 1 ) {
      digitalWrite(Relay,LOW);
      digitalWrite(buzzer,HIGH);
      Serial.println("eye is close (1),motor is OFF");
    }    
  }
void loop() {

  readSensorState();           // read the sensor state
}
