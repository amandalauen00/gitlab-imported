#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793; // PI out to 15 digits
const double MOWINGCOST = .00275; // cost to mow per square foot
const double TRIMMINGCOST = .08; // cost to trim per linear foot

int main()
{
    double lot_width;
    double lot_length;
    double lot_area;
    cout << "Mowing Calculator" << endl;
    cout << "All dimensions are given in feet."<< endl << endl;
    
    cout << "Enter the dimensions of the lot, width and length: ";
    cin >> lot_width >> lot_length;
    
    double house_width;
    double house_length;
    double house_area;
    double house_perimeter;
    cout << "Enter the dimensions of the house, width and length: ";
    cin >> house_width >> house_length;

    double shed_length;
    double shed_area;
    double shed_perimeter;
    cout << "Enter the dimension of the shed, length: ";
    cin >> shed_length;
 
    double silo_radius;
    double silo_area;
    double silo_perimeter;
    cout << "Enter the radius of the silo: ";
    cin >> silo_radius;

    double gazebo_length;
    double gazebo_area;
    double gazebo_perimeter;
    cout << "Enter the dimension of the gazebo, length: ";
    cin >> gazebo_length;

    lot_area = lot_width * lot_length;
    house_area = house_width * house_length;
    house_perimeter = 2 * (house_width + house_length);
    shed_area = pow(shed_length, 2);
    shed_perimeter = 4 * shed_length;
    silo_area = PI * pow(silo_radius, 2);
    silo_perimeter = 2 * PI * silo_radius;
    gazebo_area = 2 * (1 + sqrt(2))*pow(gazebo_length, 2);
    gazebo_perimeter = 8 * gazebo_length;

    cout << endl << endl;
    cout << "Areas given in square feet" << endl;
    
    cout << fixed << setprecision(1);
    cout << "Base Lot Area :" << setw(10) << lot_area << endl;
    cout << "House area    :" << setw(10) << house_area << endl;
    cout << "Shed Area     :" << setw(10) << shed_area << endl;
    cout << "Silo area     :" << setw(10) << silo_area << endl;
    cout << "Gazebo area   :" << setw(10) << gazebo_area << endl;
    cout << "Mowing Area   :" << setw(10) << lot_area - house_area - shed_area - silo_area - gazebo_area << endl;
    cout << "Trimming Feet :" << setw(10) << house_perimeter + shed_perimeter + silo_perimeter + gazebo_perimeter << endl;
    cout << endl;
    cout << "Billing" << endl;
    cout << fixed << setprecision(2);
    cout << "Mowing Cost   $" << setw(10) << .00275 * (lot_area - house_area - shed_area - silo_area - gazebo_area) << endl;
    cout << "Trimming Cost $" << setw(10) << .08 * (house_perimeter + shed_perimeter + silo_perimeter + gazebo_perimeter) << endl;
    cout << "Total Bill    $" << setw(10) << (.00275 * (lot_area - house_area - shed_area - silo_area - gazebo_area)) + (.08 * (house_perimeter + shed_perimeter + silo_perimeter + gazebo_perimeter)) << endl;

    return 0;
}