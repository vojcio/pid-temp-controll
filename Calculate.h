/* class which holds logic for thermostat */


#ifndef Calculate_h
#define Calculate_h

#include "Arduino.h"

class Calculate {
  public:
    Calculate(float*, float*, float, float, float);
    double compute();
    void begin(double, double);
  private:
    float *_temp;
    float *_setPoint;
    unsigned long _previousMillis;
    float _Kp;
    float _Ki;
    float _Kd;
    float lastTemp;
    float ITerm;
    double _Min, _Max;
};
#endif
