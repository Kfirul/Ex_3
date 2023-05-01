#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <climits>
#include "Fraction.hpp"

using namespace std;
using namespace ariel;

Fraction ::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
        throw invalid_argument("Denominator can't be zero.");

    if (denominator < 0) {
            numerator = -1 * numerator;
            denominator = abs(denominator);
    }    
    
    int GreatCommonDivider = gcd(numerator, denominator);
    this->numerator = numerator / GreatCommonDivider;
    this->denominator = denominator / GreatCommonDivider;
}

Fraction :: Fraction(){
    this -> numerator = 0;
    this -> denominator = 1;
}

Fraction::Fraction(float numerator) {
    this -> numerator = round (numerator*1000);
    this -> denominator = 1000;
    
    if (denominator < 0) {
            numerator = -1 * numerator;
            denominator = abs(denominator);
    }    

    int GreatCommonDivider = gcd(numerator, denominator);
    this->numerator = numerator / GreatCommonDivider;
    this->denominator = denominator / GreatCommonDivider;
}

Fraction Fraction ::operator+(Fraction &other) const
{
    int denominator = this->denominator * other.denominator;
    int numerator = this->numerator * (denominator / this->denominator) + other.numerator * (denominator / other.denominator);
    return Fraction(numerator, denominator);
}


Fraction Fraction ::operator-(Fraction &other) const
{
    int denominator = this->denominator* other.denominator;
    int numerator = this->numerator * (denominator / this->denominator) - other.numerator * (denominator / other.denominator);
    return Fraction(numerator, denominator);
}

Fraction Fraction::operator*(Fraction &other) const
{
    int numerator = this->numerator * other.numerator;
    int denominator = this->denominator * other.denominator;
    return Fraction(numerator, denominator);
}

Fraction Fraction::operator/(Fraction &other) const
{
    int numerator = this->numerator * other.denominator;
    int denominator = this->denominator * other.numerator;
    return Fraction(numerator, denominator);
}

bool Fraction::operator>(Fraction &other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 > num2;
}

bool Fraction::operator<(Fraction &other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 < num2;
}

bool Fraction::operator>=(Fraction &other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 >= num2;
}

bool Fraction::operator<=(Fraction &other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 <= num2;
}

bool Fraction :: operator!=(Fraction &other) const{
    return this->numerator!= other.numerator || this->denominator != other.denominator;
}

bool Fraction :: operator==(Fraction &other) const{
    return this->numerator== other.numerator && this->denominator == other.denominator;
}

Fraction ariel :: operator+(float f1, Fraction &f2)
{
    return (Fraction(f1)+f2);
}

Fraction ariel :: operator-(float f1, Fraction &f2)
{
    return (Fraction(f1)-f2);
}

Fraction ariel :: operator*(float f1, Fraction &f2)
{
    return (Fraction(f1)*f2);;
}

Fraction ariel :: operator/(float f1, Fraction &f2)
{
    return (Fraction(f1)/f2);
}

bool ariel :: operator>(float f1, Fraction &f2)
{
    return (Fraction(f1)>f2);
}

bool ariel :: operator<(float f1, Fraction &f2)
{
    return (Fraction(f1)<f2);
}

bool ariel ::operator>=(float f1, Fraction &f2)
{
    return (Fraction(f1)>=f2);
}

bool ariel :: operator<=(float f1, Fraction &f2)
{
    return (Fraction(f1)<=f2);
}

Fraction Fraction::operator+ (float floatNum) {
    Fraction other = Fraction(floatNum);
    int num = (this->getNumerator() * other.getDenominator()) + (other.getNumerator() * this->getDenominator());
    int den = this->getDenominator() * other.getDenominator();
    return Fraction(num, den);
}

Fraction Fraction::operator- (float floatNum) {
    Fraction other = Fraction(floatNum);
    int num = (this->getNumerator() * other.getDenominator()) - (other.getNumerator() * this->getDenominator());
    int den = this->getDenominator() * other.getDenominator();
    return Fraction(num, den);
}

Fraction Fraction::operator* (float floatNum) {
    Fraction other = Fraction(floatNum);
    int num = this->getNumerator() * other.getNumerator() ;
    int den = this->getDenominator() * other.getDenominator();
    return Fraction(num, den);
}

Fraction Fraction::operator/ (float floatNum) {
    Fraction other = Fraction(floatNum);
    int num = (this->getNumerator() * other.getDenominator());
    int den = this->getDenominator() * other.getNumerator();
    return Fraction(num, den);
}

bool Fraction :: operator>(float floatNum)
{
    Fraction other = Fraction(floatNum);
    return *this > other;
}

bool Fraction :: operator<(float floatNum)
{
    Fraction other = Fraction(floatNum);
    return *this < other;
}

bool Fraction :: operator>=(float floatNum)
{
    Fraction other = Fraction(floatNum);
    return *this >= other;
}

bool Fraction :: operator<=(float floatNum)
{
    Fraction other = Fraction(floatNum);
    return *this <= other;
}

std::ostream& ariel :: operator<<(ostream &output, const Fraction &fraction) {
    return (output << fraction.getNumerator() << '/' << fraction.getDenominator());
}

std::istream& ariel :: operator>>(istream & in, Fraction &fraction) {
    std:: string input;
    in >> input;
    return in;
}

int Fraction ::gcd(int num1, int num2) const
{
    if (num1 < num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    if (num2 == 0)
        return num1;
    return gcd(num2, num1 % num2);
}

Fraction& Fraction ::operator++(){
    this ->numerator += this ->denominator;
    return *this;
    
}

Fraction Fraction::operator++(int) { 

    return Fraction(1, 2); 
}

Fraction &Fraction ::operator--()
{
    this->numerator += this->denominator;
    return *this;
}

Fraction Fraction::operator--(int) { 
     
    return Fraction(1, 2);
        
}

int Fraction::getNumerator() const
{
    return this->numerator;
}

int Fraction::getDenominator() const
{
    return this->denominator;
}

void Fraction::setNumerator(int numerator) 
{
    this->numerator = numerator;
}

void Fraction::setDenominator(int denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("Denominator can't be zero.");
    }
    this->denominator = denominator;
}
;

