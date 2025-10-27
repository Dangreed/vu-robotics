#define force_sensor A0
#define LED_RED 11
#define LED_ORANGE 10
#define LED_YELLOW 9
#define LED_GREEN 6
#define LED_BLUE 5
#define BUTTON 2

#define RED_MIN 350
#define ORANGE_MIN 450
#define YELLOW_MIN 650
#define GREEN_MIN 800
#define BLUE_MIN 940
#define MAX_FORCE 960

int force_sensor_value;
int button_state = 0;
bool reached_max = false;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  force_sensor_value = analogRead(force_sensor);
  button_state = digitalRead(BUTTON);
  //Serial.println(force_sensor_value);
  Serial.println(button_state);
  
  if (button_state == HIGH) {
  	reached_max = false;
  }
  
  if (force_sensor_value >= MAX_FORCE) {
  	reached_max = true;
  }
  
  if (reached_max) {
    digitalWrite(LED_BLUE, LOW);
  	digitalWrite(LED_RED, HIGH);
    delay(100);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_ORANGE, HIGH);
    delay(100);
    digitalWrite(LED_ORANGE, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    delay(100);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, HIGH);
    delay(100);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, HIGH);
  }
  else {
    digitalWrite(LED_RED, force_sensor_value/RED_MIN * 255);
    digitalWrite(LED_ORANGE, force_sensor_value/ORANGE_MIN * 255);
    digitalWrite(LED_YELLOW, force_sensor_value/YELLOW_MIN * 255);
    digitalWrite(LED_GREEN, force_sensor_value/GREEN_MIN * 255);
    digitalWrite(LED_BLUE, force_sensor_value/BLUE_MIN * 255);
  }
  
  //delay(10);
}