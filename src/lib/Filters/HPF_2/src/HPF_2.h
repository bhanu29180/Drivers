#ifndef FILTER_HPF_2_H
#define FILTER_HPF_2_H

#include <stdint.h>
#include "../Constants/Constants.h"

template <typename T>
class HPF_2
{
   public:
      HPF_2();
      void init(T fc_, T dt_);
      void set_param(T fc_, T dt_);
      T update(T x_k);
      void reset();

      void set_fc(T fc_);
      void set_dt(T dt_);
      T get_fc();
      T get_dt();
      T get_fs();

   private:
      T fc = 0.0;
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

#include "HPF_2.tpp"

#endif