// constants won't change. They're used here to set pin numbers:
const int SENSOR_PIN = 7;       // the Arduino's input pin that connects to the sensor's SIGNAL pin 
const int trigPin = 3;
const int echoPin = 2;

// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin
int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

long duration;
float distance;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR_PIN, INPUT);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // read the state of the the input pin:
  currentState = digitalRead(SENSOR_PIN);

    if(lastState == LOW && currentState == HIGH){
       Serial.println("The sensor is touched");
       RGB_color(0, 255, 255); // Cyan
       // Clears the trigPin
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
      // Calculating the distance
      distance= duration*0.034/2;
      // Prints the distance on the Serial Monitor
      String str1 = "Distance: ";
      String str2 = " cm";
      String dist = str1 + distance + str2;
      
      Serial.println(dist);  
    }
    else if(lastState == HIGH && currentState == LOW){
       Serial.println("The sensor is released");
       RGB_color(255, 0, 0);
    }
  // save the the last state
  lastState = currentState;
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}