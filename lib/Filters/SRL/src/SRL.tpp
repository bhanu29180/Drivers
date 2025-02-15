#include "SRL.h"

template <typename T>
SRL<T>::SRL()
{
    T dt = 0;
    T dx_dt_max = 0;
    T y_k_1 = 0;
    bool start = false;
}

template <typename T>
void SRL<T>::init(T dt_, T dx_dt_min_, T dx_dt_max_)
{
    set_param(dt_, dx_dt_min_, dx_dt_max_);
}

template <typename T>
void SRL<T>::set_param(T dt_, T dx_dt_min_, T dx_dt_max_)
{
    dt = dt_;
    dx_dt_min = dx_dt_min_;
    dx_dt_max = dx_dt_max_;
}

template <typename T>
T SRL<T>::update(T x_k)
{
    T y_k = 0.0;
    if(start==true)
{
        start = false;
        y_k = x_k;
    }
    else{
        if(x_k > (y_k_1 + dx_dt_max*dt))
{
            y_k = y_k_1 + dx_dt_max*dt;
        }
        else if(x_k < (y_k_1 + dx_dt_min*dt))
{
            y_k = y_k_1 + dx_dt_min*dt;
        }
        else{
            y_k = x_k;
        }
    }
    
    y_k_1 = y_k;
    
    return y_k;
}

template <typename T>
void SRL<T>::reset()
{
    T y_k = 0.0;
    T y_k_1 = 0.0;
    bool start = true;
}

template <typename T>
void SRL<T>::set_dt(T dt_)
{
    dt = dt_;
}

template <typename T>
void SRL<T>::set_dx_dt_min(T dx_dt_min_)
{
    dx_dt_min = dx_dt_min_;
}

template <typename T>
void SRL<T>::set_dx_dt_max(T dx_dt_max_)
{
    dx_dt_max = dx_dt_max_;
}

template <typename T>
T SRL<T>::get_dt()
{
    return dt;
}

template <typename T>
T SRL<T>::get_dx_dt_min()
{
    return dx_dt_min;
}

template <typename T>
T SRL<T>::get_dx_dt_max()
{
    return dx_dt_max;
}
