#ifndef FILTER_MA_1
#define FILTER_MA_1

#include <stdint.h>
#include "../Constants/Constants.h"

template <typename T>
class MA
{
	public:
		MA();
        
		void init(T fc_, T dt_);
		void set_param(T fc_, T dt_);
		void set_x_arr(T* x_arr_, uint16_t len_arr_);
		T update(T x_k);
		void reset();

		void set_fc(T fc_);
		void set_dt(T dt_);
		void set_n(T n_);

		T get_fc();
		T get_dt();
		T get_n();

	private:
		T fc = 0.0;
        T n = 0.0;
		T dt = 0.0;

		T* x_arr;
        bool start = true;
};

#include "MA.tpp"

#endif