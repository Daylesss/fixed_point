#include "fixed_point.h"
#include <iostream>
#include <typeinfo>

int main() {
    FixedPoint<12> a;
    FixedPoint<16> b;
    std::cin >> a >> b;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    // FixedPoint c {a - b};
    a *=b;
    std::cout << a << std::endl;

    // std::cin >> a;

    // std::cout << ((1 << 30) + (1 <<30)) << "\n";
}