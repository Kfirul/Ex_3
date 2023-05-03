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

        Fraction operator+ (const Fraction& other) const;
        Fraction operator- (const Fraction& other) const;
        Fraction operator* (const Fraction& other) const;
        Fraction operator/ (const Fraction& other) const;
        bool operator> (const Fraction& other) const;
        bool operator< (const Fraction& other) const;
        bool operator>= (const Fraction& other) const;
        bool operator<= (const Fraction& other) const; 
        bool operator== (const Fraction& other) const; 
        bool operator!= (const Fraction& other) const; 

        friend Fraction operator+ (const float& f11,const Fraction& f22);
        friend Fraction operator- (const float& f11,const Fraction& f22);
        friend Fraction operator* (const float& f11,const Fraction& f22);
        friend Fraction operator/ (const float& f11,const Fraction& f22);
        friend bool operator> (const float& f11,const Fraction& f22);
        friend bool operator< (const float& f11,const Fraction& f22);
        friend bool operator>= (const float& f11,const Fraction& f22);
        friend bool operator<= (const float& f11,const Fraction& f22);
        friend bool operator== (const float& f11,const Fraction& f22);
        friend bool operator!= (const float& f11,const Fraction& f22);


         Fraction operator+ (const float& f11) const;
         Fraction operator- (const float& f11) const;
         Fraction operator* (const float& f11) const;
         Fraction operator/ (const float& f11) const;
         bool operator> (const float& f11) const;
         bool operator< (const float& f11) const;
         bool operator>= (const float& f11) const;
         bool operator<= (const float& f11) const;
         bool operator== (const float& f11) const;
         bool operator!= (const float& f11) const;
    
        friend std::ostream &operator<<(std::ostream &os_, const Fraction &fraction);
        friend std::istream &operator>>(std::istream &input, Fraction &fraction);


        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator);
        void setDenominator(int denominator); 

        };

}
#endif