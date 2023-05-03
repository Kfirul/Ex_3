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
            numerator = -numerator;
            denominator = -denominator;
    }    
    if(numerator == 0){
        this->numerator = 0;
        this->denominator = 1;
    }

    else{
    int GreatCommonDivider = gcd(numerator, denominator);
    this->numerator = numerator / GreatCommonDivider;
    this->denominator = denominator / GreatCommonDivider;
    }
}

Fraction :: Fraction(){
    this -> numerator = 0;
    this -> denominator = 1;
}

Fraction::Fraction(float num) {
    int num1 = num * 1000;
    int den1 = 1000;
    Fraction other = Fraction(num1, den1);
    this->numerator = other.getNumerator();
    this->denominator = other.getDenominator();
}

Fraction Fraction ::operator+(const Fraction& other) const
{
    long numCheck = (long(this -> numerator) * other.denominator) + (long(other.numerator) * this -> denominator);
    long denCheck = long(this->denominator) * other.denominator;
     if (numCheck > INT_MAX || denCheck > INT_MAX || numCheck < INT_MIN || denCheck< INT_MIN) {
            throw overflow_error("Error - overflow");
        
    }

    int denominator = this->denominator * other.denominator;
    int numerator = this->numerator * (denominator / this->denominator) + other.numerator * (denominator / other.denominator);
    return Fraction(numerator, denominator);
}

Fraction Fraction ::operator-(const Fraction& other) const
{
    long numCheck = (long(this -> numerator) * other.denominator) - (long(other.numerator) * this -> denominator);
    long denCheck = long(this->denominator) * other.denominator;
    if (numCheck > INT_MAX || denCheck > INT_MAX || numCheck < INT_MIN || denCheck< INT_MIN) {
            throw overflow_error("Error - overflow");
        
    }

    int num = (this-> numerator * other.getDenominator()) - (other.getNumerator() * this -> denominator);
    int den = this -> denominator * other.getDenominator();
    return Fraction(num, den);    
}

Fraction Fraction::operator*(const Fraction& other) const
{
    long numCheck = long(this->numerator) * other.numerator;
    long denCheck = long(this->denominator) * other.denominator;
    if (numCheck > INT_MAX || denCheck > INT_MAX || numCheck < INT_MIN || denCheck< INT_MIN) {
            throw overflow_error("Error - overflow");
        
    }

    int numerator = this->numerator * other.numerator;
    int denominator = this->denominator * other.denominator;
    return Fraction(numerator, denominator);
}

Fraction Fraction::operator/(const Fraction& other) const
{
    
    if (other.getNumerator() == 0)
        throw runtime_error("error : divide by zero");

    long numCheck = long(this->numerator) * other.denominator;
    long denCheck = long(this->denominator) * other.numerator;
    if (numCheck > INT_MAX || denCheck > INT_MAX || numCheck < INT_MIN || denCheck< INT_MIN) {
            throw overflow_error("Error - overflow");
        
    }

    int numerator = this->numerator * other.denominator;
    int denominator = this->denominator * other.numerator;
    return Fraction(numerator, denominator);
}

bool Fraction::operator>(const Fraction& other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 > num2;
}

bool Fraction::operator<(const Fraction& other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 < num2;
}

bool Fraction::operator>=(const Fraction& other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 >= num2;
}

bool Fraction::operator<=(const Fraction& other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 <= num2;
}

bool Fraction :: operator!=(const Fraction& other) const{
    return this->numerator!= other.numerator || this->denominator != other.denominator;
}

bool Fraction :: operator==(const Fraction &other) const{
    return this->numerator== other.numerator && this->denominator == other.denominator;
}

Fraction ariel :: operator+(const float& f1, const Fraction &f2)
{
    return (Fraction(f1)+f2);
}

Fraction ariel :: operator-(const float& f1,const Fraction &f2)
{
    return (Fraction(f1)-f2);
}

Fraction ariel :: operator*(const float& f1,const Fraction &f2)
{
    return (Fraction(f1)*f2);;
}

Fraction ariel :: operator/(const float& f1,const Fraction &f2)
{
    return (Fraction(f1)/f2);
}

bool ariel :: operator>(const float& f1,const Fraction &f2)
{
    return (Fraction(f1)>f2);
}

bool ariel :: operator<(const float& f1,const Fraction &f2)
{
    return (Fraction(f1)<f2);
}

bool ariel ::operator>=(const float& f1,const Fraction &f2)
{
    return (Fraction(f1)>=f2);
}

bool ariel :: operator<=(const float& f1,const Fraction &f2)
{
    return (Fraction(f1)<=f2);
}

bool ariel :: operator==(const float& f1,const Fraction &f2)
{
    Fraction other =Fraction(f1);
    return (other==f2);
}

bool ariel :: operator!=(const float& f1,const Fraction &f2)
{
    Fraction other =Fraction(f1);
    return (other!=f2);
}

Fraction Fraction::operator+ (const float& floatNum) const {
    Fraction other = Fraction(floatNum);
    int num = (this->getNumerator() * other.getDenominator()) + (other.getNumerator() * this->getDenominator());
    int den = this->getDenominator() * other.getDenominator();
    return Fraction(num, den);
}

Fraction Fraction::operator- (const float& floatNum) const {
    Fraction other = Fraction(floatNum);
    int num = (this->getNumerator() * other.getDenominator()) - (other.getNumerator() * this->getDenominator());
    int den = this->getDenominator() * other.getDenominator();
    return Fraction(num, den);
}

Fraction Fraction::operator* (const float& floatNum) const {
    Fraction other = Fraction(floatNum);
    int num = this->getNumerator() * other.getNumerator() ;
    int den = this->getDenominator() * other.getDenominator();
    return Fraction(num, den);
}

Fraction Fraction::operator/ (const float& floatNum) const {
    Fraction other = Fraction(floatNum);
    int num = (this->getNumerator() * other.getDenominator());
    int den = this->getDenominator() * other.getNumerator();

    if (other.getNumerator() == 0)
        throw std::runtime_error("error : divide by zero");
        
    return Fraction(num, den);
}

bool Fraction :: operator>(const float& floatNum) const
{
    Fraction other = Fraction(floatNum);
    return *this > other;
}

bool Fraction :: operator<(const float& floatNum) const
{
    Fraction other = Fraction(floatNum);
    return *this < other;
}

bool Fraction :: operator>=(const float& floatNum) const
{
    Fraction other = Fraction(floatNum);
    return *this >= other;
}

bool Fraction :: operator<=(const float& floatNum) const
{
    Fraction other = Fraction(floatNum);
    return *this <= other;
}

bool Fraction :: operator==(const float& floatNum) const
{
    Fraction other = Fraction(floatNum);
    return (*this == other);
}

bool Fraction :: operator!=(const float& floatNum) const
{
    Fraction other = Fraction(floatNum);
    return (*this != other);
}

std::ostream& ariel :: operator<<(ostream &output, const Fraction &fraction) {
    
    return (output << fraction.getNumerator() << '/' << fraction.getDenominator());
}

std::istream& ariel :: operator>>(istream &input, Fraction &obj) {
    input >> obj.numerator >> obj.denominator;
    if(!input)  throw runtime_error("error : invalid input");
    if (obj.denominator < 0) {
            obj.numerator = -obj.numerator;
            obj.denominator = -obj.denominator;
    }  
    if (obj.denominator == 0)
        throw runtime_error("Denominator can't be zero.");  

    if (obj.numerator == 0)
        obj.denominator =1;

    return input;
    
}
    
int Fraction ::gcd(int num1, int num2) const
{
    num1 = abs(num1);
    num2 = abs(num2);

    // if (num1 < num2)
    // {
    //     int temp = num1;
    //     num1 = num2;
    //     num2 = temp;
    // }

    if (num2 == 0)
        return num1;
    return gcd(num2, num1 % num2);
}

Fraction& Fraction ::operator++(){
    this ->numerator += this ->denominator;
    return *this;
    
}

Fraction Fraction::operator++(int) { 
    Fraction temp(*this);
    this->numerator += this->denominator;
    return temp; 
}

Fraction &Fraction ::operator--()
{
    this->numerator -= this->denominator;
    return *this;
}

Fraction Fraction::operator--(int) { 
    Fraction temp(*this);
    this->numerator -= this->denominator;
    return temp;
        
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

