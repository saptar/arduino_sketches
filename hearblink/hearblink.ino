// Define these at the top of your sketch.
#define LEDBLINK_PIN_BLUE    11    // I/O pin connected to the LED.
#define LEDBLINK_PIN_GREEN    12    // I/O pin connected to the LED.
#define LEDBLINK_PIN_RED    13    // I/O pin connected to the LED.
#define LEDBLINK_MS     500  // Blink rate (in milliseconds).

int ledColorPin[3] = {LEDBLINK_PIN_RED, LEDBLINK_PIN_GREEN, LEDBLINK_PIN_BLUE};
int i = 0;

void setup()
{
  // For ledBlink(), set LEDBLINK_PIN to output.
  pinMode(LEDBLINK_PIN_BLUE, OUTPUT);
  pinMode(LEDBLINK_PIN_GREEN, OUTPUT);
  pinMode(LEDBLINK_PIN_RED, OUTPUT);

}

void loop()
{
  // Blink the LED to let the user know we are still alive.

  ledBlink();

  // Do something. 
}

//
// LED Heartbeat routine by Allen C. Huffman (www.appleause.com)
//
void ledBlink()
{
  static unsigned int  ledStatus = LOW;  // Last set LED mode.
  static unsigned long ledBlinkTime = 0; // LED blink time.


  // LED blinking heartbeat. Yes, we are alive.
  // For explanation, see:
  // http://playground.arduino.cc/Code/TimingRollover
  if ( (long)(millis()-ledBlinkTime) >= 0 )
  {
    // Toggle LED.
    ledStatus = (ledStatus==HIGH ? LOW : HIGH);

    if(i > 2) {
      i = 0;
    }

    digitalWrite(ledColorPin[i], ledStatus);

    if(ledStatus == LOW) {
      i++;
    }

    // Reset "next time to toggle" time.
    ledBlinkTime = millis()+LEDBLINK_MS;
  }
} // End of ledBlink()
