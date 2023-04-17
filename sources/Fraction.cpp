#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Fraction.hpp"

using namespace std;
using namespace ariel;

Fraction ::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
        throw invalid_argument("Denominator can't be zero.");
    ;
    int GreatCommonDivider = gcd(numerator, denominator);
    this->numerator = numerator / GreatCommonDivider;
    this->denominator = denominator / GreatCommonDivider;
}

Fraction Fraction ::operator+(Fraction &other) const
{
    int denominator = lcm(this->denominator, other.denominator);
    int numerator = this->numerator * (denominator / this->denominator) + other.numerator * (denominator / other.denominator);
    return Fraction(numerator, denominator);
}

Fraction Fraction ::operator-(Fraction &other) const
{
    int denominator = lcm(this->denominator, other.denominator);
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
    int lcm_den = lcm(denominator, other.denominator);
    int num1 = numerator * (lcm_den / denominator);
    int num2 = other.numerator * (lcm_den / other.denominator);
    return num1 > num2;
}

bool Fraction::operator<(Fraction &other) const
{
    int lcm_den = lcm(denominator, other.denominator);
    int num1 = numerator * (lcm_den / denominator);
    int num2 = other.numerator * (lcm_den / other.denominator);
    return num1 < num2;
}

bool Fraction::operator>=(Fraction &other) const
{
    int lcm_den = lcm(denominator, other.denominator);
    int num1 = numerator * (lcm_den / denominator);
    int num2 = other.numerator * (lcm_den / other.denominator);
    return num1 >= num2;
}

bool Fraction::operator<=(Fraction &other) const
{
    int lcm_den = lcm(denominator, other.denominator);
    int num1 = numerator * (lcm_den / denominator);
    int num2 = other.numerator * (lcm_den / other.denominator);
    return num1 <= num2;
}

Fraction &Fraction::operator=(const Fraction &other)
{
    if (this == &other)
    {
        return *this;
    }
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

bool ariel::operator>(float f1, const Fraction &f2)
{
    float f2_float = (float)f2.getNumerator() / f2.getDenominator();
    return f1 > f2_float;
}

bool ariel::operator<(float f1, const Fraction &f2)
{
    float f2_float = (float)f2.getNumerator() / f2.getDenominator();
    return f1 < f2_float;
}

bool ariel::operator>=(float f1, const Fraction &f2)
{
    float f2_float = (float)f2.getNumerator() / f2.getDenominator();
    return f1 >= f2_float;
}

bool ariel::operator<=(float f1, const Fraction &f2)
{
    float f2_float = (float)f2.getNumerator() / f2.getDenominator();
    return f1 <= f2_float;
}

bool ariel::operator>(const Fraction &f2, float f1)
{
    return f1>f2;
}

bool ariel::operator<(const Fraction &f2, float f1)
{
    return f1<f2;
}

bool ariel::operator>=(const Fraction &f2, float f1)
{
    return f1>=f2;
}

bool ariel::operator<=(const Fraction &f2, float f1)
{
    return f1<=f2;
}

bool ariel::operator==(const Fraction &f1, const Fraction &f2)
{
    return f1==f2;
}

Fraction ariel::operator+(float f1, const Fraction &f2)
{
    return Fraction(0, 1);
}

Fraction ariel::operator-(float f1, const Fraction &f2)
{
    return Fraction(0, 1);
}

Fraction ariel::operator*(float f1, const Fraction &f2)
{
    return Fraction(0, 1);
}

Fraction ariel::operator/(float f1, const Fraction &f2)
{
    return Fraction(0, 1);
}

Fraction ariel::operator+(const Fraction &f2, float f1)
{
    return Fraction(0, 1);
}

Fraction ariel::operator-(const Fraction &f2, float f1)
{
    return Fraction(0, 1);
}

Fraction ariel::operator*(const Fraction &f2, float f1)
{
    return Fraction(0, 1);
}

Fraction ariel::operator/(const Fraction &f2, float f1)
{
    return Fraction(0, 1);
}

std::ostream &ariel::operator<<(std::ostream &output, const Fraction &f)
{
    return output;
}

std::istream &ariel::operator>>(std::istream &input, const Fraction &f)
{
    return input;
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

int Fraction ::lcm(int num1, int num2) const
{
    return (num1 / gcd(num1, num2)) * num2;
}

Fraction &Fraction::operator++()
{
    this->numerator += this->denominator;
    return *this;
}

Fraction &Fraction ::operator--()
{
    this->numerator += this->denominator;
    return *this;
}

string Fraction ::toString()
{
    ostringstream oss;
    oss << this->numerator << "/" << this->denominator;
    return oss.str();
}

int Fraction::getNumerator()
{
    return this->numerator;
}

int Fraction::getDenominator()
{
    return this->denominator;
}

void Fraction::setNumerator(int nnumerator)
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
