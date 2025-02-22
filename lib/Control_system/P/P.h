#ifndef CONTROL_SYSTEM_P
#define CONTROL_SYSTEM_P

#include "../../Math_lite/Utility/Math_functions.h"

template <typename T>
class P_controller {
public:
	P_controller();
	void init(T Kp_, T u_max_);
	void set_param(T Kp_, T u_max_);
	T update(T x_0, T x);
	void reset();
	void set_Kp(T Kp_);
	void set_u_max(T u_max_);
	T get_Kp();
	T get_u_max();

private:
	Math_functions math_fun;
	T Kp = 0.0;
	T u_max = 9999999999;
};

#include "P.tpp"

#endif