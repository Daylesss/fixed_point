#include "fixed_point.h"
#include <iostream>
#include <typeinfo>

int main() {
    FixedPoint<16> a;
    FixedPoint<16> b;
    std::cin >> a >> b;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    a/=b;
    // FixedPoint c {a * b};
    // c = a + b;
    std::cout << a << std::endl;
}