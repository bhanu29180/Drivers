#ifndef CONTROL_SYSTEM_D
#define CONTROL_SYSTEM_D

#include "Math_functions.h"

class D_controller {
public:
	D_controller();
	void init(double dt_, double Kd_, double u_max_);
	void set_param(double dt_, double Kd_, double u_max_);
	double update(double x_0, double x);
	void reset();
	void merge(double u_k_1_);
	void set_dt(double dt_);
	void set_Kd(double Kd_);
	void set_u_max(double u_max_);
	double get_dt();
	double get_Kd();
	double get_e_k_1();
	double get_u_max();

private:
	Math_functions math_fun;
	double dt = 0.0;
	double e_k_1 = 0.0;
	double Kd = 0.0;
	bool start = true;
	double u_max = 9999999999;
};

#endif