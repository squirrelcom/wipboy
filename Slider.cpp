#include <Arduino.h>
#include "Slider.h"

Slider::Slider(int pin, int range, int jitter)
{
  _pin = pin;
  _range = range;
  _jitter = jitter;
  _sliderPos = 0;
  _lastReading = 0;
  pinMode(pin, INPUT);
}

int Slider::hasChanged() {
  int reading = analogRead(_pin);
  if (reading - _jitter > _lastReading || reading + _jitter < _lastReading)
  {
    _lastReading = reading;
    reading = map(reading, 9, 924, 0, _range-1);
    if (_sliderPos != reading)
    {
      _sliderPos = reading;
      return 1;
    }
  }
  return 0;    
}

void Slider::setRange(int range) {
  _range = range;
}

int Slider::getPos()  {
  return _sliderPos;
}

int Slider::getRawPos() {
  return analogRead(_pin);
}

