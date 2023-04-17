#ifndef Fraction_HPP
#define Fraction_HPP

#include <iostream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ariel{
    class Fraction{
        int numerator;
        int denominator;

        public:

        Fraction (int numerator,int denominator);

        Fraction& operator++();
        Fraction& operator--();
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

        friend bool operator== (const Fraction& f1, const Fraction& f2);
        friend Fraction operator+ (float f1, const Fraction& f2);
        friend Fraction operator- (float f1, const Fraction& f2);
        friend Fraction operator* (float f1, const Fraction& f2);
        friend Fraction operator/ (float f1, const Fraction& f2);
        friend Fraction operator+ (const Fraction& f2, float f1);
        friend Fraction operator- (const Fraction& f2, float f1);
        friend Fraction operator* (const Fraction& f2, float f1);
        friend Fraction operator/ (const Fraction& f2, float f1);
        friend bool operator> (float f1, const Fraction& f2);
        friend bool operator< (float f1, const Fraction& f2);
        friend bool operator>= (float f1, const Fraction& f2);
        friend bool operator<= (float f1, const Fraction& f2);
        friend bool operator> (const Fraction& f2, float f1);
        friend bool operator< (const Fraction& f2, float f1);
        friend bool operator>= (const Fraction& f2, float f1);
        friend bool operator<= (const Fraction& f2, float f1);
    
        std::ostream& operator<< (std::ostream& output, const Fraction& c);
        std::istream& operator>> (std::istream& input , Fraction& c); 

        int getNumerator();
        int getDenominator();
        void setNumerator(int numerator);
        void setDenominator(int denominator); 

        int gcd(int num1, int num2) const;
        int lcm(int num1, int num2) const;

        string toString();
        };
}

#endif