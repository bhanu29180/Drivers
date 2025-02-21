#include "PID_GS.h"

PID_GS_controller::PID_GS_controller(){
    dt = 0.0;
    Kp = 0.0;
    Ki = 0.0;
    Kd = 0.0;
    fc = 0.0;
    I_max = 0.0;
    u_max = 0.0;
    d_filter = false;
    e_k_1 = 0.0;
    P = 0.0;
    I = 0.0;
    D = 0.0;
    u = 0.0;
    u_ff = 0.0;
    start = true;
}

void PID_GS_controller::init(double dt_, double Kp_, double Ki_, double Kd_, double I_max_, double u_max_, bool d_filter_, double fc_){
    set_param(dt_, Kp_, Ki_, Kd_, I_max_, u_max_, d_filter_, fc_);
    start = true;
}

void PID_GS_controller::set_param(double dt_, double Kp_, double Ki_, double Kd_, double I_max_, double u_max_, bool d_filter_, double fc_){
    dt = dt_;
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    I_max = I_max_;
    u_max = u_max_;
    d_filter = d_filter_;
    fc = fc_;
    lpf.set_param(fc,dt);
}

double PID_GS_controller::update(double x_0, double x, double u_ff_, double op_cond_){
    update_gain(op_cond_);

    double e_k = x_0 - x;
    u_ff = u_ff_;
	
    P = Kp*e_k;
	
    I = I + Ki*e_k*dt;
	I = math_fun.saturate(I,-I_max,I_max);
	
    if(start == true){
		D = 0.0;
		start = false;
	}
	else{
		D = Kd*(e - e_pre)/dt;
	}

	if(d_filter_==true){
		lpf.cal_y(D);
		D = lpf.get_y();
	}
	e_k_1 = e_k;
	u = u_ff + P + I + D;
	u = math_fun.saturate(u,-u_max,u_max);
	return u;
}

void PID_GS_controller::reset(){
    e_k_1 = 0.0;
    P = 0.0;
    I = 0.0;
    D = 0.0;
    u = 0.0;
    u_ff = 0.0;
    start = true;
    lpf.reset();
}

void PID_GS_controller::merge(double u_k_1_){
}

void PID_GS_controller::set_gain_lookup_table(double* op_cond_arr_, double* Kp_arr_, double* Ki_arr_, double* Kd_arr_, uint16_t len_arr_){
    op_cond_arr = op_cond_arr_;
    Kp_arr = Kp_arr_;
    Ki_arr = Ki_arr_;
    Kd_arr = Kd_arr_;
    len_arr = len_arr_;
}

void PID_GS_controller::update_gain(double op_cond_){
    if(op_cond_<=op_cond_arr[0]){
        Kp = Kp_arr[0];
        Ki = Ki_arr[0];
        Kd = Kd_arr[0];
    }
    else if(op_cond_>=op_cond_arr[len_arr-1]){
        Kp = Kp_arr[len_arr-1];
        Ki = Ki_arr[len_arr-1];
        Kd = Kd_arr[len_arr-1];
    }
    else{
        uint16_t index_i = 0;

        for(uint16_t i=0;i<len_arr;i++){
            if (op_cond_>op_cond_arr[i]){
                index_i++;
            }
            else{
                break;
            }
        }

        Kp = interpolate(op_cond_, op_cond_arr[index_i], Kp_arr[index_i], op_cond_arr[index_i + 1], Kp_arr[index_i + 1]);
        Ki = interpolate(op_cond_, op_cond_arr[index_i], Ki_arr[index_i], op_cond_arr[index_i + 1], Ki_arr[index_i + 1]);
        Kd = interpolate(op_cond_, op_cond_arr[index_i], Kd_arr[index_i], op_cond_arr[index_i + 1], Kd_arr[index_i + 1]);
    }
}

void PID_GS_controller::set_dt(double dt_){
    dt = dt_;
    lpf.set_param(fc,dt);
}

void PID_GS_controller::set_Kp(double Kp_){
    Kp = Kp_;
}

void PID_GS_controller::set_Ki(double Ki_){
    Ki = Ki_;
}

void PID_GS_controller::set_Kd(double Kd_){
    Kd = Kd_;
}

void PID_GS_controller::set_I_max(double I_max_){
    I_max = I_max_;
}

void PID_GS_controller::set_u_max(double u_max_){
    u_max = u_max_;
}

void PID_GS_controller::set_d_filter(bool d_filter_){
    d_filter = d_filter_;
}

void PID_GS_controller::set_fc(double fc_){
    fc = fc_;
    lpf.set_param(fc,dt);
}

void PID_GS_controller::set_ff(double u_ff_){
    u_ff = u_ff_;
}

double PID_GS_controller::get_dt(){
    return dt;
}

double PID_GS_controller::get_Kp(){
    return Kp;
}

double PID_GS_controller::get_Ki(){
    return Ki;
}

double PID_GS_controller::get_Kd(){
    return Kd;
}

double PID_GS_controller::get_I_max(){
    return I_max;
}

double PID_GS_controller::get_u_max(){
    return u_max;
}

bool PID_GS_controller::get_d_filter(){
    return d_filter;
}

double PID_GS_controller::get_fc(){
    return fc;
}

double PID_GS_controller::get_ff(){
    return u_ff;
}

double PID_GS_controller::get_P(){
    return P;
}

double PID_GS_controller::get_I(){
    return I;
}

double PID_GS_controller::get_D(){
    return D;
}

double PID_GS_controller::get_u(){
    return u;
}

double PID_GS_controller::get_e_k_1(){
    return e_k_1;
}

double PID_GS_controller::interpolate(double x, double x1, double y1, double x2, double y2){
    return y1 + (x-x1)*(y2-y1)/(x2-x1);
}