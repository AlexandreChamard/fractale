
#ifndef FLOAT_HPP_
# define FLOAT_HPP_

# include <string>

# define NEG true
# define POS false

namespace math {
    class Float {
    public:
        Float() = default;
        Float(math::Float const&) = default;
        Float(std::string const&, int);
        math::Float &operator=(math::Float const&) = default;
        ~Float();

    private:
        int exp;
        int round;
        bool sign;
        std::string nb;
    };
}

#endif
