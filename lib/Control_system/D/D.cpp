#include "D.h"

D_controller::D_controller() {
	dt = 0.0;
	e_k_1 = 0.0;
	Kd = 0.0;
	start = true;
}

void D_controller::init(double dt_, double Kd_, double u_max_) {
	set_param(dt_, Kd_, u_max_);
	start = true;
}

void D_controller::set_param(double dt_, double Kd_, double u_max_) {
	dt = dt_;
	Kd = Kd_;
	u_max = u_max_;
}

double D_controller::update(double x_0, double x) {
	double e_k = x_0 - x;
	double u_k = 0.0;
	if (start == true) {
		start = false;
		u_k = 0.0;
	}
	else {
		u_k = Kd * (e_k - e_k_1) / dt;
	}
	u_k = math_fun.saturate(u_k, -u_max, u_max);
	e_k_1 = e_k;
	return u_k;
}

void D_controller::reset() {
	e_k_1 = 0.0;
	start = true;
}

void D_controller::merge(double u_k_1_) {
}

void D_controller::set_dt(double dt_) {
	dt = dt_;
}

void D_controller::set_Kd(double Kd_) {
	Kd = Kd_;
}

double D_controller::get_dt() {
	return dt;
}

double D_controller::get_Kd() {
	return Kd;
}

double D_controller::get_e_k_1() {
	return e_k_1;
}