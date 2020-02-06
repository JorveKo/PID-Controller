#include "PID.h"
#include <iostream>
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {

  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  prev_cte = 0.0;
  first_cycle = true;

}

void PID::UpdateError(double cte) {

  if (first_cycle)
  {
   prev_cte = cte;
   first_cycle = false;
  }
  p_error = cte;
  i_error += cte;
  d_error = - prev_cte + cte;
  prev_cte = cte;
}

double PID::TotalError() {

  
  return ((-p_error) * Kp - i_error * Ki - d_error * Kd);  
}