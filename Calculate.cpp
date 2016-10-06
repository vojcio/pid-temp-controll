/* class which holds logic for thermostat */

#include "Arduino.h"
#include "calculate.h"


Calculate::Calculate(float* temp, float* setPoint, float Kp, float Ki, float Kd) {
  
  _temp = temp;
  _setPoint = setPoint;
  _previousMillis = 0;
  _Kp = Kp;
  _Ki = Ki;
  _Kd = Kd;
  double _Min;
  double _Max;
}

void Calculate::begin(double Min, double Max) {
   if(Min >= Max) return;
   _Min = Min;
   _Max = Max;
 
}

double Calculate::compute() {

      float error = *_setPoint - *_temp;
     ITerm += (_Ki * error);
     if(ITerm > _Max) ITerm = _Max;
     else if(ITerm < _Min) ITerm = _Min;
     double dInput = (*_temp - lastTemp);
     /*Compute PID Output*/
     double pid = _Kp * error + ITerm - _Kd * dInput;

     if(pid > _Max) pid = _Max;
      else if(pid < _Min) pid = _Min;

      lastTemp = *_temp;
/*
     Serial.print(pid);
     Serial.print(" = kp(");
     Serial.print(_Kp);
     Serial.print(") * error(");
     Serial.print(error);
      Serial.print(") + ITerm(");
     Serial.print(ITerm);
     Serial.print(") - _Kd(");
     Serial.print(_Kd);
     Serial.print(" * dInput(");
     Serial.print(dInput);
     Serial.print(")");
*/
     return pid;  
}



