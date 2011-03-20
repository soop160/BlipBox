#include "Animator.h"
#include "globals.h"

void FadeAnimator::tick(uint8_t counter){
  if(counter % prescaler == 0)
    blipbox.leds.fade(1);
}

void SignalAnimator::tick(uint8_t counter){
  // blink all leds
  if(signals){
    if(counter % 25 == 0){
      blipbox.leds.toggle();
      --signals;
    }
  }
// // blink one led
//   if(signals){
//     if(counter % 25 < 12){
//       blipbox.leds.setLed(0, 0, 0xff);
//     }else if(counter % 25 == 24){
//       --signals;
//     }else{
//       blipbox.leds.setLed(0, 0, 0);
//     }
//   }
}

void DotAnimator::tick(uint8_t counter){
  if(counter % 0xf == 0)
    blipbox.leds.fade(1);
  if(blipbox.keys.isPressed())
    blipbox.leds.setLed(blipbox.keys.getColumn(), blipbox.keys.getRow(), blipbox.config.brightness);
}

void CrossAnimator::tick(uint8_t counter){
  if(counter % 0xf == 0)
    blipbox.leds.fade(1);
  if(blipbox.keys.isPressed())
    blipbox.display.setCross(blipbox.keys.getColumn(), blipbox.keys.getRow(), blipbox.config.brightness);
}

void CrissAnimator::tick(uint8_t counter){
  if(counter % 0xf == 0)
    blipbox.leds.fade(1);
  if(blipbox.keys.isPressed())
    blipbox.display.setDiagonalCross(blipbox.keys.getColumn(), blipbox.keys.getRow(), blipbox.config.brightness);
}
