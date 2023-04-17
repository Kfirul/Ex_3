#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;

TEST_CASE("Check binary operators"){
    Fraction f11(1,2);
    Fraction f12(1,3);
    Fraction f13(2,6);
    CHECK(f11+f12 == Fraction(5,6));
    CHECK(f11-f12 == Fraction(1,6));
    CHECK(f11*f12 == Fraction(1,6));
    CHECK(f11/f12 == Fraction(3,2));
    CHECK(f11>f12 == true);
    CHECK(f11>=f13 == true);
    
}

TEST_CASE("Check with float parameters"){
    Fraction f11(1,2);
    CHECK(f11 + 1.5 == Fraction(2,1));
    CHECK(1.5 + f11 == Fraction(2,1));
    CHECK(f11 + 1.5 == Fraction(2,1));
    CHECK(f11*2 == Fraction(1,1));
    CHECK(f11-0.25 == Fraction(1,4));
    CHECK(f11*0.25 == Fraction(1,8));
    CHECK(f11/0.5 == Fraction(1,1));
    CHECK(f11>0.25 == true);
    CHECK(f11>=0.5 == true);
    
}

TEST_CASE("Denominator cannot be zero") {
    
    CHECK_THROWS(Fraction(1,0));

}

TEST_CASE("")

