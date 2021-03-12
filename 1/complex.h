// complex class definition
class Complex
{
    // declares complex number parts
    private:
      int real;
      int imag;

    // default init
    public:
       Complex();

    // creates new complex number
    public:
       Complex(int r, int i);

    // + Operator overloading
    Complex operator - (Complex c2) const;

    // - Operator overloading 
    Complex operator + (Complex c2) const;

    // multiply by constant 
    Complex operator * (int a) const;

    // calc abs method
    int absaluteValue() const;

    // output method
     void output() const; 
};