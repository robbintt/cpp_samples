#include "my_complex.h"

namespace my_complex {

  Complex::Complex(double r, double i) : real(r), imag(i) {}

  Complex& Complex::operator+=(const Complex& other) {
      real += other.real;
      imag += other.imag;
      return *this;
  }

  Complex& Complex::operator-=(const Complex& other) {
      real -= other.real;
      imag -= other.imag;
      return *this;
  }

  Complex& Complex::operator*=(const Complex& other) {
      double r = real * other.real - imag * other.imag;
      double i = real * other.imag + imag * other.real;
      real = r;
      imag = i;
      return *this;
  }

  Complex& Complex::operator/=(const Complex& other) {
      double denominator = other.real * other.real + other.imag * other.imag;
      double r = (real * other.real + imag * other.imag) / denominator;
      double i = (imag * other.real - real * other.imag) / denominator;
      real = r;
      imag = i;
      return *this;
  }

  Complex operator+(Complex a, const Complex& b) {
      return a += b;
  }

  Complex operator-(Complex a, const Complex& b) {
      return a -= b;
  }

  Complex operator*(Complex a, const Complex& b) {
      return a *= b;
  }

  Complex operator/(Complex a, const Complex& b) {
      return a /= b;
  }

  bool operator==(const Complex& a, const Complex& b) {
      return a.real == b.real && a.imag == b.imag;
  }

  bool operator!=(const Complex& a, const Complex& b) {
      return !(a == b);
  }

  std::ostream& operator<<(std::ostream& out, const Complex& c) {
      out << c.real << " + " << c.imag << "i";
      return out;
  }

} // namespace my_complex
