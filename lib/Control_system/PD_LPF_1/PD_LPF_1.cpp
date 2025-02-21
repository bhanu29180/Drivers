#include "PD_LPF_1.h"

PD_LPF_1_controller::PD_LPF_1_controller() {
	dt = 0.0;
	e_k_1 = 0.0;
	Kd = 0.0;
	start = true;

	u_k_1 = 0.0;
	tau = 0.0;
}

void PD_LPF_1_controller::init(double dt_, double Kp_, double Kd_, double fc_, double u_max_) {
	set_param(dt_, Kp_, Kd_, fc_, u_max_);
	start = true;
}

void PD_LPF_1_controller::set_param(double dt_, double Kp_, double Kd_, double fc_, double u_max_) {
	dt = dt_;
	Kp = Kp_;
	Kd = Kd_;
	tau = 1.0/(math_2pi*fc_);
	u_max = u_max_;
}

double PD_LPF_1_controller::update(double x_0, double x) {
	double e_k = x_0 - x;
	double u_k = 0.0;
	if (start == true) {
		start = false;
		u_k = Kp * e_k;
	}
	else {
		u_k = (tau * u_k_1 + (Kp*(dt + tau) + Kd) * e_k - (Kp*tau + Kd) * e_k_1) / (tau + dt);
	}
	u_k = math_fun.saturate(u_k, -u_max, u_max);
	e_k_1 = e_k;
	u_k_1 = u_k;
	return u_k;
}

void PD_LPF_1_controller::reset() {
	e_k_1 = 0.0;
	start = true;
	u_k_1 = 0.0;
}

void PD_LPF_1_controller::merge(double u_k_1_) {
}

void PD_LPF_1_controller::set_dt(double dt_) {
	dt = dt_;
}

void PD_LPF_1_controller::set_Kp(double Kp_) {
	Kp = Kp_;
}

void PD_LPF_1_controller::set_Kd(double Kd_) {
	Kd = Kd_;
}

void PD_LPF_1_controller::set_fc(double fc_) {
	tau = 1.0/(math_2pi*fc_);
}

void PD_LPF_1_controller::set_u_max(double u_max_){
    u_max = u_max_;
}

double PD_LPF_1_controller::get_dt() {
	return dt;
}

double PD_LPF_1_controller::get_Kp() {
	return Kp;
}

double PD_LPF_1_controller::get_Kd() {
	return Kd;
}

double PD_LPF_1_controller::get_fc() {
	return 1.0/(math_2pi*tau);
}

double PD_LPF_1_controller::get_e_k_1() {
	return e_k_1;
}

double PD_LPF_1_controller::get_u_k_1() {
	return u_k_1;
}

double PID_controller::get_u_max(){
    return u_max;
}
