#include "P.h"

template <typename T>
P_controller::P_controller() {
	Kp = 0.0;
}

template <typename T>
void P_controller::init(T Kp_, T u_max_) {
	set_param(Kp_, u_max_);
}

template <typename T>
void P_controller::set_param(T Kp_, T u_max_) {
	Kp = Kp_;
	u_max = u_max_;
}

template <typename T>
T P_controller::update(T x_0, T x) {
	return math_fun.saturate(Kp * (x_0 - x), -u_max, u_max);
}

template <typename T>
void P_controller::reset() {
}

template <typename T>
void P_controller::set_Kp(T Kp_) {
	Kp = Kp_;
}

template <typename T>
void P_controller::set_u_max(T u_max_){
    u_max = u_max_;
}

template <typename T>
T P_controller::get_Kp() {
	return Kp;
}

template <typename T>
T P_controller::get_u_max(){
    return u_max;
}