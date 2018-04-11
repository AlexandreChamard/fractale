#include "float.hpp"

math::Float::Float(std::string const& nb, int round = 0) {

    this->sign = nb[0] == '-';
    int i = this->sign;

    if (!round) {
        round = nb.size() - i - 1;
    }
    this->nb.reserve(round);
    this->sign = nb[0] == '-';
}

/*
my_float_t *f = malloc(sizeof(my_float_t) + round);
int i = 0;

if (!f) {
    return (NULL);
}
set_float_to_zero(f, round);
f->sign = POS;
if (*str == '-') {
    f->sign = NEG;
    str++;
}
put_nb(f->nb, &str, &i, round);
f->exp = i;
if (*str == '.') {
    str++;
    put_nb(f->nb, &str, &i, round);
}
return (f);
*/
