#include <assert.h>
double SquareRoot(double y){
    const double EPS = 1.e-8;
    double x = y, err;
    assert(y >= 0);
    while((x * x - y) > EPS)
        x = (x + y / x) / 2;
    return x;
}