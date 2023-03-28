#include "gpio.h"
#include "..\catch.hpp"

TEST_CASE("Adjustment of 0")
{
    int gpio = 881638791;
    int answer = gpio;

    accelGPIO( gpio, 0 );
    REQUIRE( gpio == answer );
}
TEST_CASE ("Adding 4")
{
    int gpio = 69338117;
    int answer = 70386693;
    
    accelGPIO (gpio, 4);
    REQUIRE ( gpio == answer );
}
TEST_CASE ("Adding 1")
{
    int gpio = 36807185;
    int answer = 37069329;
    
    accelGPIO ( gpio, 1);
    REQUIRE ( gpio == answer );
}
TEST_CASE ("Decreasing the value till 0")
{
    int gpio = 39363654;
    int answer = 37790790;
    
    accelGPIO ( gpio, -6);
    REQUIRE ( gpio == answer );
}

TEST_CASE ("Increase till exactly 15")
{
    int gpio = 1078233155;
    int answer = 1081903171;
    
    accelGPIO ( gpio, 14);
    REQUIRE ( gpio == answer );
}

TEST_CASE ("Decrease to a negative and store 0 into GPIO integer")
{
    int gpio = 89793809;
    int answer = 88220945;
    
    accelGPIO ( gpio, -16);
    REQUIRE ( gpio == answer );
}

TEST_CASE ("Increase till greater than 15 and store 15 in GPIO integer")
{
    int gpio = 171131458;
    int answer = 171917890;
    
    accelGPIO ( gpio, 7);
    REQUIRE ( gpio == answer );
}

TEST_CASE ("Subtracting 5")
{
    int gpio = 22806564;
    int answer = 21495844;
    
    accelGPIO ( gpio, -5);
    REQUIRE ( gpio == answer );
}
TEST_CASE ("Subtracting 9")
{
    int gpio = 544376884;
    int answer = 542017588;
    
    accelGPIO ( gpio, -9);
    REQUIRE ( gpio == answer );
}

