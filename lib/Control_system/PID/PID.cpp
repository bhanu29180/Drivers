#include "PID.h"

PID_controller::PID_controller(){
    dt = 0.0;
    Kp = 0.0;
    Ki = 0.0;
    Kd = 0.0;
    u_k_1 = 0.0;
    e_k_1 = 0.0;
    e_k_2 = 0.0;
    start = 0;
}

void PID_controller::init(double dt_, double Kp_, double Ki_, double Kd_, double u_k_1_, double u_max_){
    set_param(dt_, Kp_, Ki_, Kd_, u_k_1_, u_max_);
    start = 0;
}

void PID_controller::set_param(double dt_, double Kp_, double Ki_, double Kd_, double u_k_1_, double u_max_){
    dt = dt_;
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    u_k_1 = u_k_1_;
    u_max = u_max_;
}

double PID_controller::update(double x_0, double x) {
    double e_k = x_0 - x;
	double u_k = 0.0;
	if((start==0) || (start==1)){
		start++;
		u_k = u_k_1 + Kp * e_k;
	}
	else{
		u_k = u_k_1 + (Kp + Ki*dt + Kd/dt) * e_k - (Kp + 2.0*Kd/dt) * e_k_1 + (Kd / dt) * e_K_2;
	}
	u_k = math_fun.saturate(u_k, -u_max, u_max);
	u_k_1 = u_k;
	e_k_2 = e_k_1;
	e_k_1 = e_k;
	return u_k;
}

void PID_controller::reset(){
    u_k_1 = 0.0;
    e_k_1 = 0.0;
    e_k_2 = 0.0;
    start = 0;
}

void PID_controller::merge(double u_k_1_){
    u_k_1 = u_k_1_;
}

void PID_controller::set_dt(double dt_){
    dt = dt_;
}

void PID_controller::set_Kp(double Kp_){
    Kp = Kp_;
}

void PID_controller::set_Ki(double Ki_){
    Ki = Ki_;
}

void PID_controller::set_Kd(double Kd_){
    Kd = Kd_;
}

void PID_controller::set_u_0(double u_k_1_){
    u_k_1 = u_k_1_;
}

void PID_controller::set_u_max(double u_max_){
    u_max = u_max_;
}

double PID_controller::get_dt(){
    return dt;
}

double PID_controller::get_Kp(){
    return Kp;
}

double PID_controller::get_Ki(){
    return Ki;
}

double PID_controller::get_Kd(){
    return Kd;
}

double PID_controller::get_u_k_1(){
    return u_k_1;
}

double PID_controller::get_e_k_1(){
    return e_k_1;
}

double PID_controller::get_e_k_2(){
    return e_k_2;
}

double PID_controller::get_u_max(){
    return u_max;
}
