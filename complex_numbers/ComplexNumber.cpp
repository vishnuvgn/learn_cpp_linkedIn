#include "ComplexNumber.h"
#include <iostream>

ComplexNumber::ComplexNumber(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return ComplexNumber(real + other.real, imag + other.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    return ComplexNumber(real - other.real, imag - other.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    return ComplexNumber(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    return ComplexNumber(
        (real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag),
        (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag)
    );
}

void ComplexNumber::print() {
    std::cout << real << " ";
    if (imag >= 0) {
        std::cout << "+ " << imag << "i" << std::endl;
    }
    else {
        std::cout << "- " << -1 * imag << "i" << std::endl;
    }
}
