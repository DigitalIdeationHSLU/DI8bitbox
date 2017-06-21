/**
   Send Morse while allowing other work to progress also; to demonstrate,
   send two Morse messages at the same time, one over the builtin status LED
   and the other over a speaker connected to digital pin 2.

   Speaker is connected to Pin 2
   LEDs are connected to Pin 0, Pin 1
*/

#include <morse.h>

#define PIN_LED 0
#define PIN_SPEAKER 2

LEDMorseSender ledSender(PIN_LED1);
SpeakerMorseSender speakerSender(
  PIN_SPEAKER,
  880,  // tone frequency
  110,  // carrier frequency
  20.5);  // wpm

void setup()
{
  ledSender.setup();
  speakerSender.setup();

  ledSender.setMessage(String("// digital ideation "));
  speakerSender.setMessage(String("// digital ideation "));

  ledSender.startSending();
  speakerSender.startSending();

}

void loop()
{
  if (!ledSender.continueSending())  {
    ledSender.startSending();
  }
  if (!speakerSender.continueSending())  {
    speakerSender.startSending();
  }
}
