/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * DONE: TODO: Initialize PID coefficients (and errors, if needed)
   **/
  _kpi = Kpi;
  _kii = Kii;
  _kdi = Kdi;
  _output_lim_maxi = output_lim_maxi;
  _output_lim_mini = output_lim_mini;
  _p_error = 0.0;
  _i_error = 0.0;
  _d_error = 0.0;
  _new_delta_time = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * DONE: TODO: Update PID errors based on cte.
   **/
   double previous_p_error = _p_error;
   _p_error = cte;
   double dt = _new_delta_time;
   if (dt <= 0.0) {
     dt = 1.0;
   }
   _d_error = (cte - previous_p_error) / dt;
   _i_error = _i_error + cte * dt;
}

double PID::TotalError() {
   /**
   * DONE: TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control = (-_kpi * _p_error) - (_kii * _i_error) - (_kdi * _d_error);
    if (control > _output_lim_maxi) {
      control = _output_lim_maxi;
    } else if (control < _output_lim_mini) {
      control = _output_lim_mini;
    } 
   
   return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * DONE: TODO: Update the delta time with new value
   */
  _new_delta_time = new_delta_time;
  // NOTE: method should be returning a double. why? In main.cpp the return value is not used.
  return 0;
}
