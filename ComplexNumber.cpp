#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double realPart, double imagPart) {
    this->realPart = realPart;
    this->imagPart = imagPart;
}

ComplexNumber::ComplexNumber(const ComplexNumber& item) {
    this->realPart = item.realPart;
    this->imagPart = item.imagPart;
}

ComplexNumber::ComplexNumber(ComplexNumber&& item) {
    this->realPart = move(item.realPart);
    this->imagPart = move(item.imagPart);
}

double ComplexNumber::getReal() const {
    return this->realPart;
}

double ComplexNumber::getImag() const {
    return this->imagPart;
}

void ComplexNumber::setReal(double realPart) {
    this->realPart = realPart;
}

void ComplexNumber::setImag(double imagPart) {
    this->imagPart = imagPart;
}

ostream& operator<<(ostream& os, const ComplexNumber& comp) {
    os << to_string(comp.getReal()) + " + " + to_string(comp.getImag()) + " i";
    return os;
}

string ComplexNumber::toString() const {
    return to_string(this->realPart) + " + " + to_string(this->imagPart) + "i";
}

ComplexNumber ComplexNumber:: operator + (const ComplexNumber& num2) {
    return { realPart + num2.getReal(), imagPart + num2.getImag() };
}
ComplexNumber ComplexNumber:: operator - (const ComplexNumber& num2) {
    return { realPart - num2.getReal(), imagPart - num2.getImag() };
}
ComplexNumber ComplexNumber:: operator * (const ComplexNumber& num2) {
    return { realPart * num2.getReal() + imagPart * num2.getImag(), realPart * num2.getImag() + imagPart * num2.getReal() };
}
ComplexNumber ComplexNumber:: operator / (const ComplexNumber& num2) {
    try {
        return ComplexNumber((this->realPart * num2.getReal() + this->imagPart * num2.getImag()) / (num2.getReal() * num2.getReal() + num2.getImag() * num2.getImag()),
            (this->imagPart * num2.getReal() - this->realPart * num2.getImag()) / (num2.getReal() * num2.getReal() + num2.getImag() * num2.getImag()));
    }
    catch (exception&) {
        return { 0,0 };
    }
}

bool ComplexNumber::operator==(const ComplexNumber& other) {
    return getImag() == other.getImag() && getReal() == other.getReal();
}

ComplexNumber ComplexNumber::operator=(const ComplexNumber& other) {
    this->imagPart = other.getImag();
    this->realPart = other.getReal();
    return *this;
}

ComplexNumber ComplexNumber::operator=(ComplexNumber&& other) {
    this->imagPart = other.getImag();
    this->realPart = other.getReal();
    return *this;
}
