#include "FixedPoint.h"
#include <iostream>
#include <typeinfo>

int main() {
    // uint8_t size1, size2;
    // std::cin >> size1 >> size2; 
    FixedPoint<12> a;
    FixedPoint<18> b;
    std::cin >> a >> b;
    std::cout <<"input values:  " << a << " " << b << std::endl;
    std::cout << a << " += " << b << "=>" << (a+=b) << std::endl;
    std::cout << a << " -= " << b << "=>" << (a-=b) << std::endl;
    std::cout << a << " *= " << b << " => " << (a*=b) << std::endl;
    std::cout << a << " /= " << b << " => " << (a/=b) << std::endl;
}