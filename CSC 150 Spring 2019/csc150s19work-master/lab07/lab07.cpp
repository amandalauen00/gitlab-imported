#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int band_value(string color);
bool valid_color(string color, int band);

int main()
{
    string color_band1;
    string color_band2;
    string color_band3;
    double ohms = 0;

    cout << "Enter your three color bands: ";
    cin >> color_band1;
    cin >> color_band2;
    cin >> color_band3;

    if (valid_color(color_band1, 1) == false)
    {
        cout << "Your first color (" << color_band1 << ") is invalid." << endl;
        return 0;
    }
    else if (valid_color(color_band2, 2) == false)
    {
        cout << "Your second color (" << color_band2 << ") is invalid." << endl;
        return 0;
    }
    else if (valid_color(color_band3, 3) == false)
    {
        cout << "Your third color (" << color_band3 << ") is invalid." << endl;
        return 0;
    }
    
    cout << fixed << setprecision(3);
    ohms = (10 * band_value(color_band1) + band_value(color_band2)) * pow(10, band_value(color_band3));
    cout << "Resistor: " << ohms << " Ohms" << endl;
}

int band_value(string color)
{
    if (color == "brown")
    {
        return 1;
    }
    else if (color == "red")
    {
        return 2;
    }
    else if (color == "orange")
    {
        return 3;
    }
    else if (color == "yellow")
    {
        return 4;
    }
    else if (color == "green")
    {
        return 5;
    }
    else if (color == "blue")
    {
        return 6;
    }
    else if (color == "violet")
    {
        return 7;
    }
    else if (color == "grey")
    {
        return 8;
    }
    else if (color == "white")
    {
        return 9;
    }
    else if (color == "black")
    {
        return 0;
    }
    else if (color == "gold")
    {
        return -1;
    }
    else if (color == "silver")
    {
        return -2;
    }
    
    return 100;
}

bool valid_color(string color, int band)
{
    if (color == "black" && band == 1)
    {
        return false;
    }
    if (color == "brown" || color == "black" || color == "red" || color == "orange" ||  color == "yellow" ||  color == "green" ||  color == "blue" || color == "violet" || color == "grey" || color == "white")
    {
        return true;
    }
    if (band == 3 && (color == "gold" || color == "silver"))
    {
        return true;
    }
    return false;
} 