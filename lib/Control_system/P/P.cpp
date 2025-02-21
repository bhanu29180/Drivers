#include "P.h"

P_controller::P_controller() {
	Kp = 0.0;
}

void P_controller::init(double Kp_, double u_max_) {
	set_param(Kp_, u_max_);
}

void P_controller::set_param(double Kp_, double u_max_) {
	Kp = Kp_;
	u_max = u_max_;
}

double P_controller::update(double x_0, double x) {
	return math_fun.saturate(Kp * (x_0 - x), -u_max, u_max);
}

void P_controller::reset() {
}

void P_controller::set_Kp(double Kp_) {
	Kp = Kp_;
}

void P_controller::set_u_max(double u_max_){
    u_max = u_max_;
}

double P_controller::get_Kp() {
	return Kp;
}

double P_controller::get_u_max(){
    return u_max;
}