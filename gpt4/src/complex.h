#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

namespace my_complex {

  class Complex {
  public:
      double real;
      double imag;

      Complex(double r = 0.0, double i = 0.0);

      Complex& operator+=(const Complex& other);
      Complex& operator-=(const Complex& other);
      Complex& operator*=(const Complex& other);
      Complex& operator/=(const Complex& other);
  };

  Complex operator+(Complex a, const Complex& b);
  Complex operator-(Complex a, const Complex& b);
  Complex operator*(Complex a, const Complex& b);
  Complex operator/(Complex a, const Complex& b);

  bool operator==(const Complex& a, const Complex& b);
  bool operator!=(const Complex& a, const Complex& b);

  std::ostream& operator<<(std::ostream& out, const Complex& c);

} // namespace my_complex

#endif // COMPLEX_H
