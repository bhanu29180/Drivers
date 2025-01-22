#ifndef TFMINI_PLUS_H
#define TFMINI_PLUS_H

template <typename T_UART_bus>
class TFMini_plus
{
    public:
        TFMini_plus(T_UART_bus* uart_bus_);
        ~TFMini_plus();
        void init();
        void config();

    private:
        T_UART_bus* uart_bus;
};

template <typename T_UART_bus>
TFMini_plus<T_UART_bus>::TFMini_plus(T_UART_bus* uart_bus_)
{
}

template <typename T_UART_bus>
TFMini_plus<T_UART_bus>::~TFMini_plus()
{
}

template <typename T_UART_bus>
void TFMini_plus<T_UART_bus>::init()
{
}

template <typename T_UART_bus>
void TFMini_plus<T_UART_bus>::config()
{
}

#endif