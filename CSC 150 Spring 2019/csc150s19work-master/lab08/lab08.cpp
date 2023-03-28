#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

//write your function prototypes here
void get_inputs(double &input1, double &input2);
void convert_to_polar(double x, double y, double& length, double& angle);
void convert_to_cart(double length, double angle, double& x, double& y);

char get_menu_choice();
bool test_to_cart();
bool test_to_polar();

int main()
{
    // define your variables here
    double input1;
    double input2;
    double x = 0;
    double y = 0;
    double length = 0;
    double angle = 0;
    //test harness functions. These functions call your function, 
    //and check that the 
    //result is what is expected. If they are not, 
    //they will output a message saying they have failed.
    //you may not remove these
    bool fail = test_to_polar();

    //this short-circuits and skips the test if polar failed
    fail = fail || test_to_cart();
    if (fail)
    {
        cout << "Some of your functions are not passing\nThe requirements."
            << endl;
        return 1;
    }

    char choice = get_menu_choice();
    get_inputs(input1, input2);
    if (choice == 'C')
    {
        cout << fixed << setprecision(4);
        convert_to_polar(input1, input2, length, angle);
        cout << "length: " << length << " angle: " << angle;
    }
    else if (choice == 'P')
    {
        cout << fixed << setprecision(4);
        convert_to_cart(input1, input2, x, y);
        cout << "x: " << x << " y: " << y;
    }

    return 0;
}

// write your functions here above the test cases.

char get_menu_choice()
{
    char choice;
    cout << "Polar and Cartesian Coordinate Conversion" << endl;
    cout << "Convert (P)olar to Cartesian " << endl;
    cout << "Convert (C)artesian to Polar " << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return toupper(choice);
}

void get_inputs(double& input1, double& input2)
{
    cout << "Enter coordinates: ";
    cin >> input1 >> input2;
}

void convert_to_polar(double x, double y, double& length, double& angle)
{
    length = sqrt(pow(x, 2) + pow(y, 2));
    angle = atan(y / x);
}

void convert_to_cart(double length, double angle, double& x, double& y)
{
    x = length * cos(angle);
    y = length * sin(angle);
}

// You may not alter code below this line-------------------------------

bool test_to_cart()
{
    string result = "convertToCart test cases";
    bool fail = false;

    double length = 0, angle = 0, x = 0, y = 0, my_x, my_y;
    double tolerance = 0.001;

    //test len=13.7481 and angle 1.1592
    length = 13.7481;
    angle = 1.1592;
    my_x = 5.5002;
    my_y = 12.599;
    convert_to_cart(length, angle, x, y);
    if (abs(x - my_x) > tolerance)
    {
        result += "\n>>>>Test failed with length=" + to_string(length) + " angle="
            + to_string(angle) + ".\nThe x should be " + to_string(my_x) +
            ", instead it is " + to_string(x);
        fail = true;
    }
    if (abs(y - my_y) > tolerance)
    {
        result += "\n>>>>Test failed with length=" + to_string(length) + " angle="
            + to_string(angle) + ".\nThe x should be " + to_string(my_y)
            + ", instead it is " + to_string(y);
        fail = true;
    }

    //test len=26 and angle 0.79
    length = 26;
    angle = 0.79;
    my_x = 18.3;
    my_y = 18.47;
    convert_to_cart(length, angle, x, y);
    if (abs(x - my_x) > tolerance)
    {
        result += "\n>>>>Test failed with length=" + to_string(length) + " angle="
            + to_string(angle) + ".\nThe x should be " + to_string(my_x) +
            ", instead it is " + to_string(x);
        fail = true;
    }
    if (abs(y - my_y) > tolerance)
    {
        result += "\n>>>>Test failed with length=" + to_string(length) + " angle="
            + to_string(angle) + ".\nThe x should be " + to_string(my_y)
            + ", instead it is " + to_string(y);
        fail = true;
    }

    //test len=2044 and angle 0.02
    length = 2044;
    angle = 0.2;
    my_x = 2003.2561;
    my_y = 406.0801;
    convert_to_cart(length, angle, x, y);
    if (abs(x - my_x) > tolerance)
    {
        result += "\n>>>>Test failed with length=" + to_string(length) + " angle="
            + to_string(angle) + ".\nThe x should be " + to_string(my_x) +
            ", instead it is " + to_string(x);
        fail = true;
    }
    if (abs(y - my_y) > tolerance)
    {
        result += "\n>>>>Test failed with length=" + to_string(length) + " angle="
            + to_string(angle) + ".\nThe x should be " + to_string(my_y)
            + ", instead it is " + to_string(y);
        fail = true;
    }

    //something went wrong, explain what
    if (fail)
    {
        cout << result << endl;
    }

    return fail;

}
bool test_to_polar()
{
    string result = "convertToPolar test cases";
    bool fail = false;

    double x = 0, y = 0, length = 0, angle = 0, myLength, myAngle;
    double tolerance = 0.001;

    //test 100, 100
    x = 100;
    y = 100;
    myLength = sqrt(20000);
    myAngle = 3.14159 / 4.0;
    convert_to_polar(x, y, length, angle);
    if (abs(length - myLength) > tolerance)
    {
        result += "\n>>>>Test failed with x=" + to_string(x) + " y="
            + to_string(y) + ".\nThe length should be " + to_string(myLength)
            + ", instead it is " + to_string(length);
        fail = true;
    }
    if (abs(angle - myAngle) > tolerance)
    {
        result += "\n>>>>Test failed with x=" + to_string(x) + " y="
            + to_string(y) + ".\nThe angle should be  " + to_string(myAngle)
            + ", instead it is " + to_string(angle);
        fail = true;
    }

    //test 10.013, 100
    x = 10.013;
    y = 100;
    myLength = 100.5;
    myAngle = 1.471;
    convert_to_polar(x, y, length, angle);
    if (abs(length - myLength) > tolerance)
    {
        result += "\n>>>>Test failed with x=" + to_string(x) + " y="
            + to_string(y) + ".\nThe length should be " + to_string(myLength)
            + ", instead it is " + to_string(length);
        fail = true;
    }
    if (abs(angle - myAngle) > tolerance)
    {
        result += "\n>>>>Test failed with x=" + to_string(x) + " y="
            + to_string(y) + ".\nThe angle should be  " + to_string(myAngle)
            + ", instead it is " + to_string(angle);
        fail = true;
    }

    //test 2.7, y
    x = 2.7;
    y = 25;
    myLength = 25.145;
    myAngle = 1.4632;
    convert_to_polar(x, y, length, angle);
    if (abs(length - myLength) > tolerance)
    {
        result += "\n>>>>Test failed with x=" + to_string(x) + " y="
            + to_string(y) + ".\nThe length should be " + to_string(myLength)
            + ", instead it is " + to_string(length);
        fail = true;
    }
    if (abs(angle - myAngle) > tolerance)
    {
        result += "\n>>>>Test failed with x=" + to_string(x) + " y="
            + to_string(y) + ".\nThe angle should be  " + to_string(myAngle)
            + ", instead it is " + to_string(angle);
        fail = true;
    }

    //something went wrong, explain what
    if (fail)
    {
        cout << result << endl;
    }

    return fail;
}

