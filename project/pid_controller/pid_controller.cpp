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

  double _kpi;
  double _kii;
  double _kdi;
  double _output_lim_maxi;
  double _output_lim_mini;

  double _new_delta_time;

  double _p_error;
  double _i_error;
  double _d_error;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * DONE: TODO: Initialize PID coefficients (and errors, if needed)
   **/
  double _kpi = Kpi;
  double _kii = Kii;
  double _kdi = Kdi;
  double _output_lim_maxi = output_lim_maxi;
  double _output_lim_mini = output_lim_mini;
}


void PID::UpdateError(double cte) {
   /**
   * DONE: TODO: Update PID errors based on cte.
   **/
   double _previous_p_error = cte;
   _p_error = cte;
   _d_error = cte -_previous_p_error;
   _i_error = _i_error + cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
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
   * TODO: Update the delta time with new value
   */
  _new_delta_time = new_delta_time;
  // FIXME: method should be returning a double. why?
  return new_delta_time;
}