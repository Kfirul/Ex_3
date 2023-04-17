#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;

TEST_CASE("Check binary operators"){
    Fraction f1(1,2);
    Fraction f2(1,3);
    Fraction f3(2,6);
    
    // Addition
    CHECK(f1 + f2 == Fraction(5,6));
    CHECK(f2 + f1 == Fraction(5,6));
    
    // Subtraction
    CHECK(f1 - f2 == Fraction(1,6));
    CHECK(f2 - f1 == Fraction(-1,6));
    
    // Multiplication
    CHECK(f1 * f2 == Fraction(1,6));
    CHECK(f2 * f1 == Fraction(1,6));
    
    // Division
    CHECK(f1 / f2 == Fraction(3,2));
    CHECK(f2 / f1 == Fraction(2,3));
    
    // Relational operators
    CHECK(f1 > f2 == true);
    CHECK(f2 > f1 == false);
    CHECK(f1 < f2 == false);
    CHECK(f2 < f1 == true);
    CHECK(f1 >= f3 == true);
    CHECK(f3 >= f1 == true);
    CHECK(f1 <= f3 == true);
    CHECK(f3 <= f1 == true);
    CHECK(f1 == f3 == true);
    CHECK(f1 != f2 == true);
    CHECK(f2 != f3 == false);
}


TEST_CASE("Check with float parameters"){
    Fraction f11(1,2);
    // Addition
    CHECK(f11 + 1.5 == Fraction(2,1));
    CHECK(1.5 + f11 == Fraction(2,1));

    // Subtraction
    CHECK(f11-0.25 == Fraction(1,4));

    // Multiplication
    CHECK(f11*2 == Fraction(1,1));
    CHECK(f11*0 == Fraction(0,1));
    CHECK(f11*0.25 == Fraction(1,8));

    // Division
    CHECK(f11/0.5 == Fraction(1,1));

    // Relational operators
    CHECK(f11>0.25 == true);
    CHECK(f11>=0.5 == true);
    CHECK(0.25>f11 == true);
    CHECK(0.5>=f11 == true);
    
    
}

TEST_CASE("Denominator cannot be zero") {
    
    CHECK_THROWS(Fraction(1,0));

}


