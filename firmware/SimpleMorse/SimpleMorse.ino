/**
   Send Morse while allowing other work to progress also; to demonstrate,
   send two Morse messages at the same time, one over the builtin status LED
   and the other over a speaker connected to digital pin 2.

   Speaker is connected to Pin 2
   LEDs are connected to Pin 0, Pin 1
*/

#include <morse.h>

#define PIN_LED1 0
#define PIN_LED2 1
#define PIN_SPEAKER 2

LEDMorseSender led1Sender(PIN_LED1);
//MorseSender *led2Sender;

SpeakerMorseSender speakerSender(
  PIN_SPEAKER,
  880,  // tone frequency
  110,  // carrier frequency
  20.5);  // wpm

void setup()
{
  led1Sender.setup();
  speakerSender.setup();

//  led2Sender = new LEDMorseSender(PIN_LED2);
//  led2Sender->setup();
//  led2Sender->setMessage(String("// digital ideation "));
//  led2Sender->startSending();

  led1Sender.setMessage(String("// digital ideation "));
  speakerSender.setMessage(String("// digital ideation "));

  led1Sender.startSending();
  speakerSender.startSending();

}

void loop()
{
  if (!led1Sender.continueSending())  {
    led1Sender.startSending();
  }
//  if (!led2Sender->continueSending())  {
//    led2Sender->startSending();
//  }
  if (!speakerSender.continueSending())  {
    speakerSender.startSending();
  }

}
