#ifndef CONTROL_SYSTEM_PID_S
#define CONTROL_SYSTEM_PID_S

#include "Math_functions.h"
#include "Filter_LPF_1.h"

class PID_S_controller{
	public:
		PID_S_controller();

		void init(double dt_, double Kp_, double T_i_, double T_d_, double I_max_, double u_max_, bool d_filter_=false, double fc_=10.0);
		void set_param(double dt_, double Kp_, double T_i_, double T_d_, double I_max_, double u_max_, bool d_filter_=false, double fc_=10.0);
		double update(double x_0, double x, double u_ff_=0.0);
		void reset();
		void merge(double u_k_1_);

		void set_dt(double dt_);
		void set_Kp(double Kp_);
		void set_T_i(double T_i_);
		void set_T_d(double T_d_);
		void set_I_max(double I_max_);
		void set_u_max(double u_max_);
		void set_d_filter(bool d_filter_);
        void set_fc(double fc_);
		void set_ff(double u_ff_);

        double get_dt();
        double get_Kp();
        double get_T_i();
        double get_T_d();
        double get_I_max();
        double get_u_max();
        bool get_d_filter();
        double get_fc();
        double get_ff();

		double get_P();
		double get_I();
		double get_D();
		double get_u();
		double get_e_k_1();

	private:
		LPF_filter lpf;
		Math_functions math_fun;
		
		double dt = 0.0;
		double Kp = 0.0;
		double T_i = 0.0;
		double T_d = 0.0;
		double I_max = 0.0;
		double u_max = 0.0;
		bool d_filter = false;
        double fc = 0.0;

		double e_k_1 = 0.0;
		double P = 0.0;
		double I = 0.0;
		double D = 0.0;
		double u = 0.0;
		double u_ff = 0.0;

		bool start = true;
};

#endif