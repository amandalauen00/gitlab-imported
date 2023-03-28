#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

const double XBOX = 250;
const double PLAYSTATION = 400;
const double NINTENDO = 300;
const double DISK = 25;
const double GAME = 35;

int main()
{
    string entered_name;
    double og_computer_value;
    int age_computer;
    double phone_value;
    double printer_value;
    string response;
    int num_consoles = 0;
    double consoles_subtotal = 0;
    int total_games;
    int total_disks;
    double games_disks_ratio;
    int games_disks_total;
    double other_tech_subtotal;
    double games_disks_subtotal;
    double computer_subtotal;
    double estimated_tech_worth;

    cout << "Welcome to the Dorm Room Calculator!" << endl << endl;

    cout << "Please enter your name: ";
    cin >> entered_name;

    cout << "Please enter the value of your computer when purchased: ";
    cin >> og_computer_value;
    
    cout << "Please enter the age of your computer: ";
    cin >> age_computer;

    cout << "Please enter the value of your phone: ";
    cin >> phone_value;

    cout << "Please enter the value of your printer: ";
    cin >> printer_value;

    cout << "Do you have a XBox (y to add): ";
    cin >> response;
    if (response == "y")
    {
        num_consoles = num_consoles + 1;
        consoles_subtotal = XBOX + consoles_subtotal;
    }
    
    cout << "Do you have a Playstation (y to add): ";
    cin >> response;
    if (response == "y")
    {
        num_consoles = num_consoles + 1;
        consoles_subtotal = PLAYSTATION + consoles_subtotal;
    }

    cout << "Do you have a Nintendo (y to add): ";
    cin >> response;
    if (response == "y")
    {
        num_consoles = num_consoles + 1;
        consoles_subtotal = NINTENDO + consoles_subtotal;
    }

    cout << "Please enter the total number of console games: ";
    cin >> total_games;

    cout << "Please enter the number of other computer or dvd disks: ";
    cin >> total_disks;

    computer_subtotal = pow(0.8, age_computer)* og_computer_value;
    games_disks_ratio = double (total_games) / double (total_disks);
    games_disks_total = total_games + total_disks;
    other_tech_subtotal = phone_value + printer_value;
    games_disks_subtotal = ((GAME * total_games) + (DISK * total_disks));
    consoles_subtotal = consoles_subtotal;
    estimated_tech_worth = computer_subtotal + consoles_subtotal + phone_value + printer_value;

    cout << fixed << setprecision(2);
    cout << endl << entered_name << "..." << endl;
    cout << "You have " << games_disks_ratio << " ratio of games to disks. " << endl;
    cout << "You have " << games_disks_total << " games and disks. " << endl;
    cout << "You have " << num_consoles << " consoles." << endl;
    cout << "Other tech subtotals:.........$" << other_tech_subtotal << endl;
    cout << "Games/disks subtotal:.........$" << games_disks_subtotal << endl;
    cout << "Computer subtotal:............$" << computer_subtotal << endl;
    cout << "Consoles subtotal:............$" << consoles_subtotal << endl;

    cout << "------------------------------------------------------------" << endl;
    cout << "The estimated tech worth in your room is $" << estimated_tech_worth << endl << endl;
    cout << "Thank you for using the calculator!" << endl;

    return 0;
}