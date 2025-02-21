#ifndef CONTROL_SYSTEM_P
#define CONTROL_SYSTEM_P

#include "Math_functions.h"

class P_controller {
public:
	P_controller();
	void init(double Kp_, double u_max_);
	void set_param(double Kp_, double u_max_);
	double update(double x_0, double x);
	void reset();
	void set_Kp(double Kp_);
	void set_u_max(double u_max_);
	double get_Kp();
	double get_u_max();

private:
	Math_functions math_fun;
	double Kp = 0.0;
	double u_max = 9999999999;
};

#endif