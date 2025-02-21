#ifndef CONTROL_SYSTEM_I
#define CONTROL_SYSTEM_I

#include "Math_functions.h"

class I_controller {
public:
	I_controller();
	void init(double dt_, double Ki_, double u_k_1_, double u_max_);
	void set_param(double dt_, double Ki_, double u_k_1_, double u_max_);
	double update(double x_0, double x);
	void reset();
	void merge(double u_k_1_);
	void set_dt(double dt_);
	void set_Ki(double Ki_);
	void set_u_0(double u_k_1_);
	void set_u_max(double u_max_);
	double get_dt();
	double get_Ki();
	double get_u_k_1();
	double get_u_max();

private:
	Math_functions math_fun;
	double dt = 0.0;
	double u_k_1 = 0.0;
	double Ki = 0.0;
	double u_max = 9999999999;
};

#endif