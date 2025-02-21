#include "I.h"

I_controller::I_controller() {
	dt = 0.0;
	u_k_1 = 0.0;
	Ki = 0.0;
}

void I_controller::init(double dt_, double Ki_, double u_k_1_, double u_max_) {
	set_param(dt_, Ki_, u_k_1_, u_max_);
}

void I_controller::set_param(double dt_, double Ki_, double u_k_1_, double u_max_) {
	dt = dt_;
	Ki = Ki_;
	u_k_1 = u_k_1_;
	u_max = u_max_;
}

double I_controller::update(double x_0, double x) {
	double e_k = x_0 - x;
	double u_k = u_k_1 + Ki * dt * e_k;
	u_k = math_fun.saturate(u_k, -u_max, u_max);
	u_k_1 = u_k;
	return u_k;
}

void I_controller::reset() {
	u_k_1 = 0.0;
}

void I_controller::merge(double u_k_1_) {
	u_k_1 = u_k_1_;
}

void I_controller::set_dt(double dt_) {
	dt = dt_;
}

void I_controller::set_Ki(double Ki_) {
	Ki = Ki_;
}

void I_controller::set_u_0(double u_k_1_) {
	u_k_1 = u_k_1_;
}

void I_controller::set_u_max(double u_max_) {
	u_max = u_max_;
}

double I_controller::get_dt() {
	return dt;
}

double I_controller::get_Ki() {
	return Ki;
}

double I_controller::get_u_k_1() {
	return u_k_1;
}

double I_controller::get_u_max() {
	return u_max;
}