#include "PD.h"

PD_controller::PD_controller() {
	dt = 0.0;
	e_k_1 = 0.0;
	Kp = 0.0;
	Kd = 0.0;
	start = true;
}

void PD_controller::init(double dt_, double Kp_, double Kd_, double u_max_) {
	set_param(dt_, Kp_, Kd_, u_max_);
	start = true;
}

void PD_controller::set_param(double dt_, double Kp_, double Kd_, double u_max_) {
	dt = dt_;
	Kp = Kp_;
	Kd = Kd_;
	u_max = u_max_;
}

double PD_controller::update(double x_0, double x) {
	double e_k = x_0 - x;
	double u_k = 0.0;
	if (start == true) {
		start = false;
		u_k = Kp * e_k;
	}
	else {
		u_k = (Kp + Kd/dt) * e_k - (Kd / dt) * e_k_1;
	}
	u_k = math_fun.saturate(u_k, -u_max, u_max);
	e_k_1 = e_k;
	return u_k;
}

void PD_controller::reset() {
	e_k_1 = 0.0;
	start = true;
}

void PD_controller::merge(double u_k_1_) {
}

void PD_controller::set_dt(double dt_) {
	dt = dt_;
}

void PD_controller::set_Kp(double Kp_) {
	Kp = Kp_;
}

void PD_controller::set_Kd(double Kd_) {
	Kd = Kd_;
}

void PD_controller::set_u_max(double u_max_){
    u_max = u_max_;
}

double PD_controller::get_dt() {
	return dt;
}

double PD_controller::get_Kp() {
	return Kp;
}

double PD_controller::get_Kd() {
	return Kd;
}

double PD_controller::get_e_k_1() {
	return e_k_1;
}

double PD_controller::get_u_max(){
    return u_max;
}
