#ifndef FILTER_SRL
#define FILTER_SRL

template <typename T>
class SRL
{
    public:
        SRL();
        void init(T dt_, T dx_dt_min_, T dx_dt_max_);
        void set_param(T dt_, T dx_dt_min_, T dx_dt_max_);
        T update(T x_k);
        void reset();

        void set_dt(T dt_);
        void set_dx_dt_min(T dx_dt_min_);
        void set_dx_dt_max(T dx_dt_max_);
        T get_dt();
        T get_dx_dt_min();
        T get_dx_dt_max();

    private:
        T dt        = 0;
        T dx_dt_min = 0;
        T dx_dt_max = 0;

        T y_k_1     = 0;

        bool start      = true;
};

#include "SRL.tpp"

#endif