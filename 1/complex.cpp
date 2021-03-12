#include <iostream>
#include <cmath>
#include <vector>
#include "complex.h"

using namespace std;

// no arg constructor
Complex::Complex(){
    imag = 0;
    real = 0;
}

// two arg constructor
Complex::Complex(int r, int i)
{
    real = r;
    imag = i;
};

// + Operator overloading
Complex Complex::operator - (Complex c2) const
{
    Complex temp;
    temp.real = this->real - c2.real;
    temp.imag = this->imag - c2.imag;

    return temp;
}

// - Operator overloading
Complex Complex::operator + (Complex c2) const
{
    Complex temp;
    temp.real = this->real + c2.real;
    temp.imag = this->imag + c2.imag;

    return temp;
}

// multiply by constant 
Complex Complex::operator * (int a) const
{
        return  Complex(this->real * a, this->imag * a);
}

// calc abs
int Complex::absaluteValue() const
{
    return sqrt(this->real* this->real + this->imag * this->imag);
}

// print complex number
void Complex::output() const
{
    if(imag < 0)
        cout << "Output Complex number: "<< this->real << this->imag << "i \n";
    else
        cout << "Output Complex number: " << this->real << "+" << this->imag << "i \n";
}


