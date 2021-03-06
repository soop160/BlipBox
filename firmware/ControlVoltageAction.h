#ifndef _CONTROL_VOLTAGE_ACTION_H_
#define _CONTROL_VOLTAGE_ACTION_H_

#include "Action.h"

class ControlVoltageAction : public MidiAction {
public:
  ControlVoltageAction();
  uint8_t cc;
  void on(float f);
  float getValue();
  uint8_t read(const uint8_t* data){
    cc = data[6];
    return MidiAction::read(data)+1;
  }
  uint8_t write(uint8_t* data){
    data[6] = cc;
    return MidiAction::write(data)+1;
  }
  void handle(MidiEvent& event);
  
};

#endif /* _CONTROL_VOLTAGE_ACTION_H_ */
