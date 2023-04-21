#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Check constructor") {
    Fraction f11(1,2);
    Fraction f12(5,3);
   

    CHECK(f11.getNumerator() == 1);
    CHECK(f12.getNumerator() == 5);

    CHECK(f11.getDenominator() == 2);
    CHECK(f12.getDenominator() == 3); 

}

TEST_CASE("Check binary operators"){
    Fraction f1(1,2);
    Fraction f2(1,3);
    Fraction f3(2,6);
    Fraction f4 = f1+f2;
    Fraction f5= f1+f3;
    
    
    // Addition
    CHECK(f4 == Fraction(5,6));
    CHECK(f5 == Fraction(5,6));

    f4=f1 - f2;
    // f5 = f2 - f1;
    // Subtraction
    CHECK(f4 == Fraction(1,6));
    // CHECK(f5 == Fraction(-1,6));
    
    f4=f1 * f2;
    f5=f2 * f1;
    // Multiplication
    CHECK(f4 == Fraction(1,6));
    CHECK(f5 == Fraction(1,6));
    
    f4=f1 / f2;
    f5=f2 / f1;
    // Division
    CHECK(f4 == Fraction(3,2));
    CHECK(f5 == Fraction(2,3));
    
    // Relational operators
    CHECK(f1 > f2);
    CHECK(f2 > f1);
    CHECK(f1 < f2);
    CHECK(f2 < f1);
    CHECK(f1 >= f3);
    CHECK(f3 >= f1);
    CHECK(f1 <= f3);
    CHECK(f3 <= f1);
    CHECK(f1 == f3);
    CHECK(f1 != f2);
    CHECK(f2 != f3);
}


TEST_CASE("Check with float parameters"){
    Fraction f11(1,2);
    Fraction f12=f11 + 1.5;
    Fraction f13=1.5 + f11;
    // Addition
    CHECK(f12 == Fraction(2,1));
    CHECK(f13 == Fraction(2,1));

    f12=f11-0.25;
    // Subtraction
    CHECK(f12 == Fraction(1,4));

    f12=f11*2;
    f13=f11*0;
    Fraction f14=f11*0.25;
    // Multiplication
    CHECK(f12 == Fraction(1,1));
    CHECK(f13 == Fraction(0,1));
    CHECK(f14 == Fraction(1,8));

    f12=f11/0.5;
    // Division
    CHECK(f12 == Fraction(1,1));


    // Relational operators
    CHECK(f11>0.25);
    CHECK(f11>=0.5);
    CHECK(0.25>f11);
    CHECK(0.5>=f11);
    
    
}

TEST_CASE("Denominator cannot be zero") {
    
    CHECK_THROWS(Fraction(1,0));

}


