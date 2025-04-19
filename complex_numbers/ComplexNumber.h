#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

class ComplexNumber {

    public:
        double real, imag;
        
        ComplexNumber(double real, double imag);
        
        ComplexNumber operator+(const ComplexNumber&) const;
        ComplexNumber operator-(const ComplexNumber&) const;
        ComplexNumber operator*(const ComplexNumber&) const;
        ComplexNumber operator/(const ComplexNumber&) const;
        void print();
        

};

#endif