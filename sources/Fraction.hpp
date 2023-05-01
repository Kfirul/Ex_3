#ifndef Fraction_HPP
#define Fraction_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ariel {
    class Fraction{
        int numerator;
        int denominator;

        int gcd(int num1, int num2) const;

        public:

        Fraction (int numerator,int denominator);
        Fraction();
        Fraction(float number);
        
        Fraction& operator++();
        Fraction& operator--();
        Fraction operator++(int);
        Fraction operator--(int);

        Fraction& operator= (const Fraction& other);    
        Fraction operator+ (Fraction& other) const;
        Fraction operator- (Fraction& other) const;
        Fraction operator* (Fraction& other) const;
        Fraction operator/ (Fraction& other) const;
        bool operator> (Fraction& other) const;
        bool operator< (Fraction& other) const;
        bool operator>= (Fraction& other) const;
        bool operator<= (Fraction& other) const; 
        bool operator== (Fraction& other) const; 
        bool operator!= (Fraction& other) const; 

        
        friend Fraction operator+ (float f11, const Fraction& f22);
        friend Fraction operator- (float f11, const Fraction& f22);
        friend Fraction operator* (float f11, const Fraction& f22);
        friend Fraction operator/ (float f11, const Fraction& f22);
        friend Fraction operator+ (const Fraction& f22, float f11);
        friend Fraction operator- (const Fraction& f22, float f11);
        friend Fraction operator* (const Fraction& f22, float f11);
        friend Fraction operator/ (const Fraction& f22, float f11);
        friend bool operator> (float f11, const Fraction& f22);
        friend bool operator< (float f11, const Fraction& f22);
        friend bool operator>= (float f11, const Fraction& f22);
        friend bool operator<= (float f11, const Fraction& f22);
        friend bool operator> (const Fraction& f22, float f11);
        friend bool operator< (const Fraction& f22, float f11);
        friend bool operator>= (const Fraction& f22, float f11);
        friend bool operator<= (const Fraction& f22, float f11);
    
        friend std::ostream &operator<<(std::ostream &os_, const Fraction &fraction);
        friend std::istream &operator>>(std::istream &is_, Fraction &fraction);

        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator);
        void setDenominator(int denominator); 
        };
}


#endif