#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// complex class
class Complex
{
    // declares complex number parts
    private:
      int real;
      int imag;

    // default init
    public:
       Complex(): real(0), imag(0){ }

    // creates new complex number
    public:
       Complex(int r, int i){
           this->real = r;
           this->imag = i;
       }


       // + Operator overloading
       Complex operator - (Complex c2)
       {
           Complex temp;
           temp.real = this->real - c2.real;
           temp.imag = this->imag - c2.imag;

           return temp;
       }

       // - Operator overloading
       Complex operator + (Complex c2)
       {
           Complex temp;
           temp.real = this->real + c2.real;
           temp.imag = this->imag + c2.imag;

           return temp;
       }

       // multiply by constant 
       Complex operator * (int a){
            return  Complex(this->real * a, this->imag * a);
       }

       // calc abs
       int absaluteValue(){
           return sqrt(this->real* this->real + this->imag * this->imag);
       }

       // print complex number
       void output()
       {
           if(imag < 0)
               cout << "Output Complex number: "<< this->real << this->imag << "i \n";
           else
               cout << "Output Complex number: " << this->real << "+" << this->imag << "i \n";
       }
};

