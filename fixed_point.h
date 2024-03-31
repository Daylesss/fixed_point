#ifndef FIXED_POINT_FIXED_POINT_H_
#define FIXED_POINT_FIXED_POINT_H_

#include <cstdint>
// #include <cmath>
// #include <stdexcept>
// #include <type_traits>

template<uint8_t exp = 16>
class FixedPoint {
    int32_t val{0};

    template<typename Numeric>
    FixedPoint ToFixed(Numeric num) {
        if typeid(num) == typeid(*this)
    }

    public:
        template<typename Numeric>
        explicit FixedPoint(Numeric _val) {
            val = static_cast<int32_t>(exp * _val)
        };

        template<uint8_t exp_>
        FixedPoint operator+=(FixedPoint<exp_> right){
            
        };

        template<uint8_t exp_>
        FixedPoint operator-=(FixedPoint<exp_> right){
            
        };

        template<uint8_t exp_>
        FixedPoint operator*=(FixedPoint<exp_> right){
            
        };

        template<uint8_t exp_>
        FixedPoint operator/=(FixedPoint<exp_> right){
            
        };

        template<uint8_t exp_>
        FixedPoint operator+(FixedPoint<exp_> right){
            
        };

        template<uint8_t exp_>
        FixedPoint operator-(FixedPoint<exp_> right){
            
        };

        template<uint8_t exp_>
        FixedPoint operator*(FixedPoint<exp_> right){
            
        };

        template<uint8_t exp_>
        FixedPoint operator/(FixedPoint<exp_> right){
            
        };


};

#endif