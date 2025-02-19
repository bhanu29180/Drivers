#include "iostream"
#include "../src/Vector2.h"

template <typename T>
void print(Vector2<T> v)
{
    std::cout << v.x << ", " << v.y << std::endl;
}

int main()
{
    std::cout << "---" << std::endl;
    std::cout << "TEST: Vector2" << std::endl;

    Vector2<float> v1(4,9);
    print(v1);
    // std::cout << v1.x << ", " << v1.y << std::endl;
    // std::cout << "---" << std::endl;
    // std::cout << typeid(v1).name() << ", " << typeid(v1.x).name() << ", " << typeid(v1.y).name() << std::endl;

    // std::cout << "---" << std::endl;

    Vector2<float> v2;
    print(v2);
    v2 = v1;
    v1.x = 6;
    print(v1);
    print(v2);
    print(v1 + v2);
    std::cout << "---" << std::endl;
    print(v1);
    print(v2);
    std::cout << "---" << std::endl;
    Vector2<float> v3 = Vector2<float>::normalize(v2);
    print(v3);
    std::cout << v2.y/v2.x << ", " << v3.y/v3.x << std::endl;

    return 0;
}