#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    const double SALES_TAX_RATE = 0.07;
    double discount = 0;
    string response;
    int num_pets;
    cout << "Do you have a pet (Y/N)? ";
    cin >> response;
    if (response == "y" || response == "Y")
    {
        string pet_name;
        cout << "What kind of pet? ";
        cin >> pet_name;

        cout << "How many? ";
        cin >> num_pets;
        if (pet_name == "cat")
        {
            if (num_pets > 5)
            {
                discount = 0.30;
            }
            else
            {
                discount = 0.25;
            }
        }
        else if (pet_name == "dog")
        {
            if (num_pets > 4)
            {
                discount = 0.20;
            }
            else
            {
                discount = 0.15;
            }
        }
        else
        {
            if (num_pets > 2)
            {
                discount = 0.10;
            }
            else
            {
                discount = 0.05;
            }
        }
    }

    double purchase_subtotal;
    cout << "Enter purchase subtotal: ";
    cin >> purchase_subtotal;

    double subtotal_discount;
    double final_total;
    cout << fixed << setprecision(2);
    subtotal_discount = purchase_subtotal - (purchase_subtotal * discount);
    cout << "Subtotal after discount: $" << subtotal_discount << endl;
    final_total = subtotal_discount + (subtotal_discount * SALES_TAX_RATE);
    cout << "Final total: $" << final_total << endl;

    return 0;
}