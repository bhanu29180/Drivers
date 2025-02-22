#ifndef FILTER_BPF_2_H
#define FILTER_BPF_2_H

#include "stdint.h"
#include "../Constants/Constants.h"

template <typename T>
class BPF_2
{
   public:
      BPF_2();
      void init(T f0_, T dt_);
      void set_param(T f0_, T dt_);
      T update(T x_k);
      void reset();

      void set_f0(T f0_);
      void set_dt(T dt_);
      T get_f0();
      T get_dt();
      T get_fs();

   private:
      T f0 = 0.0;
      T B = 0.0;
      T dt = 0.0;

      T lambda_1 = 0.0;
      T lambda_2 = 0.0;
      T lambda_3 = 0.0;
      T lambda_4 = 0.0;
      T lambda_5 = 0.0;

      T y_k_1 = 0.0;
      T y_k_2 = 0.0;

      T x_k_1 = 0.0;
      T x_k_2 = 0.0;

      uint8_t start_counter = 0;
};

#include "BPF_2.tpp"

#endif