#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>

using namespace std;

const double DISCOUNT = 0.10;
const double TAX = 0.06;

int main()
{
    char club_member = 'y';
    int items_purchased = 0;
    double member_discount = 0;
    double price = 0;
    double subtotal = 0;
    char tax_exempt = 'y';
    double total_bill = 0;
    double total_tax = 0;

    cout << endl << "SDSM&T TechMart" << endl;

    cout << endl << "Are you a club member (y/n): ";
    cin >> club_member;
    
    cout << "Are you taxed exempt (y/n): ";
    cin >> tax_exempt;
    

    cout << "Enter price: ";
    while (cin >> price)
    {
        items_purchased += 1;
        subtotal += price;
        cout << "Enter price: ";
    }

    if (club_member == 'y')
    {
        member_discount = -DISCOUNT * subtotal;
    }

    if (tax_exempt != 'y')
    {
        total_tax = TAX * subtotal;
    }
 
    total_bill = subtotal + member_discount + total_tax;
    cout << fixed << setprecision(2);
    cout << endl << "Items Purchased :  " << items_purchased;
    cout << endl << "Sub Total       $ " << subtotal;
    cout << endl << "Member Discount $ " << member_discount;
    cout << endl << "Tax             $ " << total_tax;
    cout << endl << "Total Bill      $ " << total_bill;
    cout << endl;
    
    
    return 0;
}