#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    char ch;
    string password;
    string strength;
    double length_of_password = 0;
    int CHARACTER_POOL = 0;
    double entropy_bits;
    double password_entropy_bits;
    bool has_lower = false;
    bool has_upper = false;
    bool has_number = false;
    bool has_punct = false;

    cout << endl << "Enter your password/passphrase: ";
    cin >> ch;

    while (ch !='#')
    {
        password += ch;
        length_of_password += 1;

        if (islower(ch) && has_lower == false)
        {
           has_lower = true;
           CHARACTER_POOL += 26;
        }
       
        if (isupper(ch) && has_upper == false)
        {
           has_upper = true;
           CHARACTER_POOL += 26;
        }

        if (isdigit(ch) && has_number == false)
        {
            has_number = true;
            CHARACTER_POOL += 10;
        }
        
        if (ispunct(ch) && has_punct == false)
        {
            has_punct = true;
            CHARACTER_POOL += 32;
        }
        
        cin >> ch;
    }
    
    entropy_bits = log2(CHARACTER_POOL);
    password_entropy_bits = entropy_bits * length_of_password;

    if (password_entropy_bits <= 28)
    {
        strength = "Very weak";
    }
    else if (password_entropy_bits <= 35)
    {
        strength = "Weak";
    }
    else if (password_entropy_bits <= 59)
    {
        strength = "Reasonable";
    }
    else if (password_entropy_bits <= 127)
    {
        strength = "Strong";
    }
    else if (password_entropy_bits > 127)
    {
        strength = "Very strong";
    }

    cout << endl;
    cout << endl << "Password: " << password;
    cout << endl << "Character Pool: " << CHARACTER_POOL;
    cout << fixed << setprecision(1);
    cout << endl << "Entropy bits per character: " << entropy_bits;
    cout << endl << "Password entropy value: " << password_entropy_bits;
    cout << endl << "Password Strength: " << strength << endl;
    
    cout << endl << "Thanks for checking your password";
    cout << endl;

    
    return 0;
}
