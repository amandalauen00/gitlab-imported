/*
CSC 150 Fall 2019
Lab 4 p1001
Amanda Lauen
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double pointAx;
double pointAy;
double pointBx;
double pointBy;
double distance_value;
double midpoint_value1;
double midpoint_value2;
double area_square;
double area_circle;
double length_sheep;
double width_sheep;
double sheep_area;
int square_fit;
int circle_fit;

int main()
{
    //Ask user for points Ax, Bx, Ay, and By
    cout << "Enter point A x value: ";
    cin >> pointAx;
    cout << "Enter point A y value: ";
    cin >> pointAy;
    cout << "Enter point B x value: ";
    cin >> pointBx;
    cout << "Enter point B y value: ";
    cin >> pointBy;
    
    // Calculate distance_value, midpoint_value, area of the square, 
    // and area of the circle between A and B.
    distance_value = sqrt(pow((pointAx - pointBx), 2.0) 
                     + (pow((pointAy - pointBy), 2.0)));
    midpoint_value1 = (pointAx + pointBx) / 2.0;
    midpoint_value2 = (pointAy + pointBy) / 2.0;
    area_square = pow(distance_value, 2.0) / 2.0;
    area_circle = M_PI * (pow((distance_value / 2.0), 2.0));

    // Output distance, midpoint, area of the square and area of the circle
    // between A and B.
    cout << fixed << showpoint << setprecision(2);
    cout << "The distance between A and B is " 
         << distance_value << "." << endl;
    cout << "The midpoint between A and B is (" << midpoint_value1 << ", " 
         << midpoint_value2 << ")" << "." << endl;
    cout << "The area of the square with AB as diagonal is " 
         << area_square << "." <<endl;
    cout << "The area of the circle with AB as diameter is " 
         << area_circle << "." << endl;

    //Ask the user for the length and width of the sheep
    cout << "Enter length of average sheep: ";
    cin >> length_sheep;
    cout << "Enter width of average sheep: ";
    cin >> width_sheep;

    //Calculare sheep area, and amounts to fit in a circle and square
    sheep_area = M_PI * (width_sheep /2.0) * (length_sheep / 2.0);
    square_fit = int(area_square / sheep_area);
    circle_fit = int(area_circle / sheep_area);

    //Output sheep are and amounts of sheep that can fit in the 
    //square or circle.
    cout << "Each sheep is approximately " << sheep_area 
         << " units in area." << endl;
    cout << "The square can fit approximately " << square_fit
         << " sheep " << endl << "and the circle can fit approximately "
         << circle_fit << " sheep." << endl;

    return 0;

}