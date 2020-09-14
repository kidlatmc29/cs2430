// Example of creating a class and overloading an operator
// 9-14-2020

#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(int r = 0, int i = 0)
        : real(r), imag(i) {}

    Complex operator+(Complex const &y)
    {
        Complex res;
        res.real = real + y.real;
        res.imag = imag + y.imag;
        return res;
    }

private:
    int real, imag;
};

int main()
{
    Complex x(5, 3), y(4, 6);
    Complex z = x + y;
}