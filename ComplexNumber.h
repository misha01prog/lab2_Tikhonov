#pragma once
#include <iostream>
using namespace std;

enum struct Sign {
    SUM = '+',
    SUBSTRACT = '-',
    MULTIPLY = '*',
    DIVIDE = '/',
};

class ComplexNumber
{
public:
    ComplexNumber() = default;
    ComplexNumber(double realPart, double imagPart);
    ComplexNumber(const ComplexNumber& item);
    ComplexNumber(ComplexNumber&& item);

    double getReal() const;
    double getImag() const;

    void setReal(double value);
    void setImag(double value);

    ComplexNumber operator + (const ComplexNumber& num2);
    ComplexNumber operator - (const ComplexNumber& num2);
    ComplexNumber operator * (const ComplexNumber& num2);
    ComplexNumber operator / (const ComplexNumber& num2);

    string toString() const;

    bool operator==(const ComplexNumber& other);
    ComplexNumber operator=(const ComplexNumber& other);
    ComplexNumber operator=(ComplexNumber&& other);


private:
    double realPart = 0;
    double imagPart = 0;
};

ostream& operator<<(ostream& os, const ComplexNumber& num);
istream& operator>>(istream& is, const ComplexNumber& num);
