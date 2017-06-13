/* Blink without Delay
    Example. test LEDs and speaker
 */

const int led1 =  1;      // the number of the LED pin
const int led2 =  0;
const int speaker = 2;

// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 250;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(speaker, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set LEDS
    digitalWrite(led1, ledState);
    digitalWrite(led2, ledState);
    digitalWrite(speaker, ledState);
  }
}

