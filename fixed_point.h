#ifndef FIXED_POINT_FIXED_POINT_H_
#define FIXED_POINT_FIXED_POINT_H_

#include <iostream>
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include <type_traits>

template<uint8_t exp>
class FixedPoint {
    int32_t val;
    
    void check_size(int64_t value) const {
        if (value > static_cast<int64_t>(std::numeric_limits<int32_t>::max())) {
        throw std::overflow_error("FixedPoint overflow");
        }

        if (value < static_cast<int64_t>(std::numeric_limits<int32_t>::min())) {
        throw std::underflow_error("FixedPoint underflow");
        }
    }

    template<uint8_t exp_>
    int64_t lead_to_common_size(FixedPoint<exp_> to_common) const {
        int8_t dif = exp - exp_;
        if (dif > 0) {
            return (to_common.get_val() << dif);
        }
        else if (dif < 0) {
            return(to_common.get_val() >> abs(dif));
        };
        return to_common.get_val();
    } 

    public:
        int32_t get_val() const {
            return static_cast<int64_t>(val);
        };
        template<typename Numeric>
        void set_val(Numeric val_){
            val = static_cast<int32_t>(val_ * (1 << exp) + 0.5);
        };

        double as_double() const {
            double int_part = val / (1 << exp) * 1.0;
            double frac_part = (val % (1 << exp) * 1.0) / (1 << exp);
            return int_part + frac_part;
        };

        template<typename Numeric>
        explicit FixedPoint(Numeric val_) {
            if (abs(val_) > ((1 << (31 - exp)) -1)){
                throw std::overflow_error("Overflow in FixedPoint constructor");
            };
            set_val(val_);
        };

        explicit FixedPoint() {
            val = 0;
        };


        friend std::ostream& operator<<(std::ostream & out, FixedPoint& obj) {
            out << obj.as_double();
            return out;
        };

        friend std::ostream& operator>>(std::ostream & out, FixedPoint& obj) {
            out << obj.as_double();
            return out;
        };

        friend std::istream& operator<<(FixedPoint& obj, std::istream& in) {
            double val_;
            in >> val_;
            obj.set_val(val_);
            return in;
        };

        friend std::istream& operator>>(std::istream& in, FixedPoint& obj) {
            double val_;
            in >> val_;
            obj.set_val(val_);
            return in;
        };

        template<uint8_t exp_>
        FixedPoint& operator+=(FixedPoint<exp_> right) {
            int64_t res = val;
            int64_t right_val = lead_to_common_size(right);
            res += right_val;
            // int8_t dif = exp - exp_;
            // if (dif > 0) {
            //     res += (right.get_val() << dif);
            // }
            // else if (dif < 0) {
            //     res += (right.get_val() >> abs(dif));
            // }
            // else {
            //     res += right.get_val();
            // };
            check_size(res);
            val = res;
            return *this;
        };

        template<uint8_t exp_>
        FixedPoint operator+(FixedPoint<exp_> right) const {
            FixedPoint<exp> left = *this;
            left +=right;
            return left;
        };

        template<uint8_t exp_>
        FixedPoint& operator-=(FixedPoint<exp_> right) {
            int64_t res = val;
            int64_t right_val = lead_to_common_size(right);
            res -= right_val;
            // int8_t dif = exp - exp_;
            // if (dif > 0) {
            //     res -= (right.get_val() << dif);
            // }
            // else if (dif < 0) {
            //     res -= (right.get_val() >> abs(dif));
            // }
            // else {
            //     res -= right.get_val();
            // };
            check_size(res);
            val = res;
            return *this;
        };
        template<uint8_t exp_>
        FixedPoint operator-(FixedPoint<exp_> right) const {
            FixedPoint<exp> left = *this;
            left -=right;
            return left;
        };

        template<uint8_t exp1, >
        FixedPoint<> operator*=(FixedPoint<exp_> right){
            int64_t res = val;
            FixedPoint<16> a{21};
            return a;
        };

        // template<uint8_t exp_>
        // FixedPoint operator/=(FixedPoint<exp_> right){
            
        // };
};

#endif // FIXED_POINT_FIXED_POINT_H_