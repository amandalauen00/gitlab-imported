/** ***************************************************************************
* @file
*
* @mainpage Program 3 - The Game of Life
*
* @section course_section Course Information
*
* @author Amanda Lauen
*
* @date March 26, 2019
*
* @par Professor
*      Daniel De Castro
*
* @par Course
*      CSC150 - M002 - 12:00pm
*
* @par Location
       McLaury - Room 205
*
* @section program_section Program Information
* This program is a simplified Game of Life. Since the Game of Life is copyrighted,
* this is a parody called the Game of College Life.  Many of the rules remain the same as the original, but the
* individual squares are different. The game is much shorter and one player. Therefore, the goal is a
* high score. The square event section will describe the board contents.  The program is coded for a single
* player with the option of a time seed and user given seed. The user given seed is for debugging purposes.
*
* Before the user begins playing the game, the user must enter in their name, whether the game will be played with a time seed, a
* user generated seed, or a user generated seed with debug mode. The user then spins for their monthly salary. This is set for
* the remainder of the game. The user starts with $1,000 in funds. If the user spins once, they get $500 each payday.
* If the user spins 2 to 3 times. they get $1,000 each payday. If the user spins 4 to 5, they get 1,500 each payday.
* If a player spins 6 times, they get 2,000 each payday. The Initial configuration was completed in a function named initialization().
* The initialization function will print Welcome to the Game of College Life, and then ask for the type of seed
* (T for time, U for user defined, and D, for debug mode, case-insensitive. Debug mode only affect moving the player,
* and still need a user seed. Any other input should output Invalid option and then ask for input again.
* Then the program will ask for the player name, and then the program will output the spin value for their monthly salary.
*
* After the configuration is complete the game will start. For each player in turn, the main menu will output the player
* name, a line of =, the game board, then another line of =, the current funds, the current debt, and then
* 1) Spin, 2) Bet on Wheel, 3) Go to the Bank, 0) Quit, and their choice. These actions are done in the
* function main_menu(). The only valid options for the main menu are 1, 2, 3, and 0.  If another number is entered, the program
* will output an Invalid option, and then present the menu again. This action will repeat until the user to enters a valid
* number.  If option 1 is selected, the program will perform the Spin option. This option also ends the player’s turn when
* complete. If option 2 is selected, the program will perform the Bet on wheel option. If option 3 is selected, the program will
* perform the Borrow option (aka Go to Bank Option). The option 0 should end the game with Goodbye.
*
* The game is able to move with the spin option. This option will move the player and is done in the function move(). In this
* function, the program will spin the wheel and return a value within the range of 1 and 6. If the user is running in debug mode,
* the program will output Spin value: to collect the user input instead. This will update the user's location on the board.
* This action is done in a function called spin(). Then the program will move the player that number of spaces forward until the
* player is past the end of the board.  Once the new location is known, the program will apply the event(s) of the
* move. Applying the event is done in the function named square_events().
*
* When moving, there is one or more events. There are multiple kinds of events 1. Normal: the game either reward or penalize the player.
* If the penalty pushes the player into negative, the program will automatically go to the back an borrow enough 2,000 debt notes
* until the amount is met. 2. Player status: this affects some of the player's events later on. For example, get a dog. 3. Pay
* day: when the player land on or go past this square the user gets paid by salary from the beginning of the game.
* Since there are too many squares to fit inside one function, they are split up into separate functions. The first
* ten squares are found in square1_10(), the second ten in square11_20(), and so on. After finding the square, the program will
* output the event, and then apply the effect on the player.
*
* The board is printed out with the players on it in a single line. The board is stored in an array of up to 31 spaces. In a normal square
* it will output with a period. A status change is outputted with an S. A pay day is outputted with a P. A play is output with their
* number. So, the first player is output as a 1. If the user passes over a payday, it will also output
* You passed over X payday(s) so you receive $ monthly salary. It is possible to pass over one, so there is a
* calculation that adds the monthly salary so many times that the user goes over the payday option. If an item does not apply to your
* player due to their state, the program will output Avoided Event instead. For example, if the player does not have a dog, and
* lands on square 12, the program outputs Avoided Event. The board events output the associated text for each and perform the result
* If the player's spin value is a 0, it will output Reward: Birthday Party - gain $500 and add 500 to the player's current funds.
* If the player's spin value is a 1, the program will output Penalty: Buy Books - pay $500: and will subtract 500
* from the player's current funds. If the player's spin value is a 2, the program will output Reward: Aced your Midterm - gain $1,000
* and add 1,000 to the player's current funds. If the player's spin value is 3, it will output Penalty: Buy furniture - pay $2,000
* and 2000 dollars will be taken out of the player's current funds. If the player's spin value is 4, the program will output
* Penalty: Course Fees - Pay $700 and the current funds variable will add 700.  If the player spins the value 5, then the payday
* function will execute adding the amount stated at the beginning of the game to the player's current funds. If the player spins a 6,
* it will output Status: You got a dog and add a dog to the player's current info to use for later. If the player spins a 7, the
* program will output Reward: Lucky day - gain $2,000 and add 2000 to the player's current funds. If the player spins an 8, the
* program will output Reward: Sold a project to a company - add $10,000 and add 10000 to the current funds. If the player's
* spin value is 9, it will output Status: You got a cat and add a cat to the player information array to use for later.
* If the player spins a 10, the program will output Penalty: Interest due. Pay $100 for every $2,000 owed in debt and check
* if there is any debt.  If there is over or 2000 in debt, then the current funds will be subtracted by 100.  If not, then the program
* will output, Avoided event and move onto the next section. These selections are conducted in the function square_events0_10().
*
* In the final square_function, it takes care of squares 11 through 20. If the player spins an 11, it will output Reward: Grandma came to visit - gain $500
* and then the current funds will add 500. If the player spins a 12, then the program will output Penalty: If you own a dog, it chewed
* through the door – pay $700 and the program will check if the player has a dog. If so, then the current funds will be subtracted by 700.
* If not, then the program will output Avoided Event.  If the player spins a 13, then the Payday function will add the amount given at the
* beginning of the game to the current funds. If the player spins a 14, it will output Penalty: Mice found! Call an exterminator – pay $2,000
* and 2000 will be subtracted from the current funds variable. If the player spins a 15, the program will output Reward: Help friend move –
* gain $1,000 and then 1000 will be added to the current funds variable. If the player spins a 16, the program outputs Status: You got a cat
* and then add a cat to the player information array to use for later. If the player spins a 17, it will output Reward: won a new computer -
* gain $1,500 and add 1500 to the current funds variable. If the player spins an 18, the program will output Reward: Got a scholarship -
* gain $5,000 and add 5000 to the current funds variable. If the user's spin value is 19, then the Payday option will occur adding the
* pay_day_value determined at the beginning of the game to the current funds variable. And finally, if the player spins a 20,
* the program will output Penalty: Your computer crashed when you worked on your final paper - pay $3,500 and subtract 3500 from the current funds variable.
*
* The next function covers squares 21 through 30.  If the player spins the value 21, the program will output Penalty: Interest due. Pay
* $100 for every $2,000 owed in debt and the program will check if the current_debts variable is greater than or equal 2000. If so, then the program
* will take out 100 for each 2000. If not, then the program will output Avoided Event.  If the player spins the value 22. the program outputs
* Status: You got a dog. and the program will add 1 to the number of dogs located in the player_info array to use for later. If the player spins a
* 23, the program will execute the Payday option, adding the pay_day_value determined at the beginning of the game to the current funds variable.
* If the player's spin value is 24, it will output Penalty: Caught the flu - pay $1000 and subtract 1000 from the current funds variable. If the user
* spins a 25, the program will output Penalty: If you have a dog, take it to the vet - pay $300 and then the program will check to see if the user has a dog.
* If so, then 300 is subtracted from the current funds.  If not, then it will output Avoided Event. If the user's spin value is 26, the program will output
* Penalty: If you have a cat, take it to the vet - pay $300 and then the program will check to see if the player has a cat or not. If so, then 300
* is subtracted from the current funds.  If not, then the program outputs Avoided Event. If the user's spin value is 27, the program will output
* Reward: If you have a dog, it keeps you calm through final - gain $300 and then the program will check to see if the user has a dog. If so, then
* 300 is added to the current funds.  If not, then it will output Avoided Event. If the user's spin value is 28, it will output Reward: If you
* have a cat, it keeps you calm through final - gain $300 and then the program will check to see if the player has a cat or not. If so, then 300
* is added to the current funds. If not, then the program outputs Avoided Event. If the spin value is 29, the program will output Reward:
* Job offer - gain $5000 and then 5000 is added to the current funds variable. And finally if the player’s spin value is 30, the program
* will output Penalty: Final exam stress - pay $1000 and then 1000 is subtracted from the current funds variable. Any square after this
* output “Congratulations! You've graduated.
*
* The game ends when the player reaches past the end of the board and they graduate. When the player gets to the end of the board,
* the program will payback all debt at a rate of 2,500 per 2,000, and increase the function by $2,000 per pet. The program will then
* output the final score, and then end the game with Goodbye.  The calculation is all done in the function named end_game().
*
* If the player is short on money, or needs to repay debt, they can go to the bank via option 3 in the main menu.
* The bank menu will output Welcome to your bank, your current funds, your current debt, 1) Borrow, 2) Pay, 0) Exit,
* and then ask for the user’s choice. The numbers are formatted with 2 digits past the decimal point. The player can ask the back
* for money in increments of $2,000 or pay back the bank in $2000 increments. If the user inputs an amount not in these increments,
* the program will output Invalid amount. Need multiple of $2,000. In this function, asking for money will add the amount to
* the player's debt and money. Paying money subtracts the amount from the user's debt and money. The calculations are done in the
* function named bank_menu().
*
* A player may choose the bet on wheel option once per turn. If a player attempts to bet again, it will output:
* Extra bet not allowed in this turn. The player may place $1,000 on two numbers in the range [1, 6]. The wheel is then
* spun. If the spin is on that number, the player gains $10,000. It will then output You are betting against the wheel, and ask
* for the 2 numbers, the wheel will be spun, and the result will be outputted. The calculations are in the function named bet_on_wheel().
*
* The program will end after the end_game() function or when a 0 is entered at the main_menu() function.
*
* @section compiling_section Compiling and Usage
*
* @verbatim
  c:\> prog3.exe
  d:\> c:\bin\prog3.exe
  @endverbatim
*
* @section todo_bugs_modifications_section Todo, Bugs, and Modifications
*
* @bug None
*
* @todo None
*
***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>

using namespace std;
/**
* @brief Initial funds given to the player
*/
const int INITIAL_FUNDS = 1000;

int bank_menu(int player_info[]);
int bet_on_wheel(bool debug_mode, int player_info[], int spin_value, bool &no_bet_wheel);
int end_game(int player_info[]);
void initialization(bool &debug_mode, int player_info[],string &player_name);
int main_menu(bool debug_mode, int player_info[], char game_board[], string player_name, bool &no_bet_wheel, int spin_value);
int move(bool debug_mode, int player_info[], bool &no_bet_wheel, char game_board[], int spin_value);
int spin(bool debug_mode, bool &no_bet_wheel);
int square_events(int player_info[]);
int square0_10(int player_info[]);
int square11_20(int player_info[]);
int square21_30(int player_info[]);

/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function will allow the user to play the game of Life.  By entering in integers for the spin number,
*       the user will be able to collect a sum of money that they are able to bet, pay off debts, and accumulate
*       throughout the game.  If any other number is entered, an error message will apprear and redirect the user back
*       to the main menu. The program will keep executing until 0 is entered at the end.
*
* @returns 0 program ran successful.
*
***************************************************************************/
int main()
{
    int pay_day_number = 0;
    bool debug_mode = false;
    int player_info[10] = { 0 };
    player_info[0] = INITIAL_FUNDS;
    int spin_value = 0;
    int pay_day_value = 0;
    string player_name;
    bool no_bet_wheel = false;
    char game_board[31] = {'.','.','.','.','.','P','S','.','.','S','.','.','.','P','.','.','S','.','.'
        ,'P','.','.','S','P','.','.','.','.','.','.','.' };

    initialization(debug_mode, player_info, player_name);
    main_menu(debug_mode, player_info, game_board, player_name, no_bet_wheel, spin_value);

    return 0;
}

/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       The initialization function will determine which seed is being used in the program (T-Time), (U-User defined), or (D-Debug)
*       , collect the user's name, and determines the pay day value via the spin value either entered or given. Any other input should 
*       output Invalid option and then ask for input again. This function leads towards the main menu function and does not return anything.
*
* @param[in,out]        debug_mode     - Determines if the seed letter is in debug mode.
* @param[in,out]        player_info[]  - This is an array that holds the player info like current funds/debts, amount of pets, etc.   
* @param[in,out]        player_name    - This holds the player name and will be changed only in the initialization function.
*
***************************************************************************/
void initialization(bool &debug_mode, int player_info[], string &player_name)
{
    char seed_letter = 'F';
    int seed_number = 0;
    int spin_number = 0;
    cout << "Welcome to the Game of College Life" << endl << endl;
    while (seed_letter == 'F')
    {
        cout << "Seed for randomization (T)ime, (U)ser defined, (D)ebug mode: ";
        cin >> seed_letter;
        if (seed_letter == 'T' || seed_letter == 't')
        {
            srand(unsigned char(time(NULL)));
        }
        else if (seed_letter == 'U' || seed_letter == 'u')
        {
            cout << "Write a number for the seed: ";
            cin >> seed_number;
            srand(unsigned char(seed_number));
        }
        else if (seed_letter == 'D' || seed_letter == 'd')
        {
            debug_mode = true;
            cout << "Write a number for the seed: ";
            cin >> seed_number;
            srand(unsigned char(seed_number));
        }
        else
        {
            seed_letter = 'F';
            cout << "Invalid Option" << endl;
        }
    }
        spin_number = rand() % 6 + 1;
        cout << "Name of player 1? ";
        cin >> player_name;
        cout << "Spinning wheel for payment..." << spin_number << "..." << endl;
        if (spin_number == 1)
        {
            player_info[4] = 500;
            cout << "Your payment will be 500 on each payday" << endl;
        }
        else if (spin_number == 2 || spin_number == 3)
        {
            player_info[4] = 1000;
            cout << "Your payment will be 1000 on each payday" << endl;
        }
        else if (spin_number == 4 || spin_number == 5)
        {
            player_info[4] = 1500;
            cout << "Your payment will be 1500 on each payday" << endl;
        }
        else if (spin_number == 6)
        {
            player_info[4] = 2000;
            cout << "Your payment will be 2000 on each payday" << endl;
        }
        else
        {
            cout << "Invalid option" << endl;
        }
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function shows the complete game to the user. For each player in turn, the main menu will output the player
*       name, a line of =, the game board, then another line of =, the current funds, the current debt, and then 1) Spin, 2)
*       Bet on Wheel, 3) Go to the Bank, 0) Quit, and their choice. The only valid options for the main menu are 1, 2, 3, and 0.
*       If another number is entered, the program will output an Invalid option, and then present the menu again.
*       This action will repeat until the user to enters a valid number.  If option 1 is selected, the program will perform the
*       Spin option going to the Spin Function. This option also ends the player’s turn when complete. If option 2 is selected, 
*       the program will perform the Bet on wheel option which goes to the bet on wheel function. If option 3 is selected, the 
*       program will perform the Borrow option (aka Go to Bank Option) going towards the bank menu function. If the option 0 is selected,
        it will end the game with Goodbye and end the program entirely.
*
* @returns 0 program ran successful.
*
* @param[in]            debug_mode     - Determines if the seed letter is in debug mode.
* @param[in,out]        player_info[]  - This is an array that holds the player info like current funds/debts, amount of pets, etc.
* @param[in]            player_name    - This holds the player name and will be changed only in the initialization function.
* @param[in,out]        game_board[]   - This is an array that holds the game board and all the spots it possesses.
* @param[in,out]        no_bet_wheel   - This determines if the player decides to either to bet on the wheel or not.
* @param[in]            spin_value     - This determines the spin value that helps the player know how much to move.
*
***************************************************************************/
int main_menu(bool debug_mode, int player_info[], char game_board[], string player_name, bool &no_bet_wheel, int spin_value)
{
    int choice_number = 0;
    while (choice_number != 100)
    {
        cout << endl << "Player 1: " << player_name << "'s turn" << endl;
        cout << "================================================" << endl;
        cout << "Game board : ";
        for (int i = 0; i < 31; i++)
        {
            cout << game_board[i];
        }
        cout << endl << "================================================" << endl;
        cout << "Current funds: $" << player_info[0] << ".00" << endl;
        cout << "Current Debt: $" << player_info[1] << ".00" << endl << endl;

        cout << "1) Spin" << endl;
        cout << "2) Bet on Wheel" << endl;
        cout << "3) Go to the Bank" << endl;
        cout << "0) Quit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice_number;
        if (choice_number == 1)
        {
            move(debug_mode, player_info, no_bet_wheel, game_board, spin_value);
            if (player_info[5] > 31)
            {
                choice_number = 100;
            }
        }
        else if (choice_number == 2)
        {
            bet_on_wheel(debug_mode, player_info, spin_value, no_bet_wheel);
        }
        else if (choice_number == 3)
        {
            bank_menu(player_info);
        }
        else if (choice_number == 0)
        {
            cout << endl;
            cout << "Goodbye!" << endl;
            choice_number = 100;
        }
        else
        {
            cout << "Invalid Option" << endl;

        }

    }
    return 0;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function will allow the player to spin the hypothetical wheel to get the value that they will be 
*       moving on the game board. In this function, the program will spin the wheel and return a value within the 
*       range of 1 and 6. If the user is running in debug mode, the program will output Spin value: to collect the 
*       user input instead. This will update the user's location on the board. THis function will reutn the spin value
*       to use as a part of the array player_info[5] to help the user keep track of their current position on the game
*       board.
*
* @returns spin_value program ran successful.
*
* @param[in]            debug_mode     - Determines if the seed letter is in debug mode.
* @param[in,out]        no_bet_wheel   - This determines if the player decides to either to bet on the wheel or not.
***************************************************************************/
int spin(bool debug_mode, bool &no_bet_wheel)
{
    int spin_value;
    no_bet_wheel = false;
    if (debug_mode == true)
    {
        cout << "Spin Value: ";
        cin >> spin_value;
    }
    else
    {
        spin_value = rand() % 6 + 1;
    }
    cout << "You spin the wheel and get..." << spin_value << endl;
    return spin_value;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function has the ability to move the player on the game board. By calling the spin function, the program will spin the wheel 
*       and return a value within the range of 1 and 6. If the user is running in debug mode, the program will output Spin value: 
*       to collect the user input instead. This will update the user's location on the board. Then the program will move the player 
*       that number of spaces forward until the player is past the end of the board. Once the new location is known, the program will 
*       apply the event(s) of the move via the square events functions.  After telling what spin value and event that took place to 
*       either increase or decrease the player info, it will then reutn back to the main menu function with the ending function of 
*       return 0.
*
* @returns 0 program ran successful.
*
* @param[in]            debug_mode     - Determines if the seed letter is in debug mode.
* @param[in,out]        player_info[]  - This is an array that holds the player info like current funds/debts, amount of pets, etc.
* @param[in,out]        game_board[]   - This is an array that holds the game board and all the spots it possesses.
* @param[in,out]        no_bet_wheel   - This determines if the player decides to either to bet on the wheel or not.
* @param[in]            spin_value     - This determines the spin value that helps the player know how much to move.
***************************************************************************/
int move(bool debug_mode, int player_info[], bool &no_bet_wheel, char game_board[], int spin_value)
{
    int move_value;
    int pay_day_spots_passed = 0;
    int old_position = 0;
    int borrowed_amount = 0;
    if (player_info[5] == 6 || player_info[5] == 14 || player_info[5] == 20 || player_info[5] == 24)
    {
        game_board[player_info[5]-1] = 'P';
    }
    else if (player_info[5] == 7 || player_info[5]== 10 || player_info[5] == 17 || player_info[5] == 23)
    {
        game_board[player_info[5]-1] = 'S';
    }
    else
    {
        if (player_info[5] > 0)
        {
            game_board[player_info[5] - 1] = '.';
        }
    }
    old_position = player_info[5];
    move_value = spin(debug_mode, no_bet_wheel);
    player_info[5] += move_value;
    if (player_info[5] > 0)
    {
        if (player_info[5] > 31)
        {
            game_board[30] = '1';
        }
        else
        {
            game_board[player_info[5] - 1] = '1';
        }
    }
    if (player_info[5] > 6 && old_position < 6)
    {
        pay_day_spots_passed += 1;
    }
    if (player_info[5] > 14 && old_position < 14)
    {
        pay_day_spots_passed += 1;
    }
    if (player_info[5] > 20 && old_position < 20)
    {
        pay_day_spots_passed += 1;
    }
    if (player_info[5] > 24 && old_position < 24)
    {
        pay_day_spots_passed += 1;
    }
    if (pay_day_spots_passed > 0)
    {
        player_info[0] += player_info[4] * pay_day_spots_passed;
        cout << "You passed over " << pay_day_spots_passed << " payday, so you recieve $" << player_info[4] * pay_day_spots_passed << endl;
    }
    square_events(player_info);
    if (player_info[0] < 0)
    {
        while (player_info[0] < 0)
        {
            borrowed_amount += 2000;
            player_info[1] += 2000;
            player_info[0] += 2000;  
        }
        cout << "You borrowed $" << borrowed_amount << ".00 from the bank." << endl;
    }
    if (player_info[5] > 31)
    {
        end_game(player_info);
        return 1;
    }
    return 0;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function determines which spot on the game board the player is and what action needs to be taken towards the player info arrays.
*       In this function When there is one or more events. There are multiple kinds of events 1. Normal: the game either reward or penalize 
*       the player. If the penalty pushes the player into negative, the program will automatically go to the back an borrow enough 2,000 debt 
*       notes until the amount is met. 2. Player status: this affects some of the player's events later on. For example, get a dog. 3. Pay
*       day: when the player land on or go past this square the user gets paid by salary from the beginning of the game. Since there are too 
*       many squares to fit inside one function, they are split up into separate functions. The first ten squares are found in square1_10(), 
*       the second ten in square11_20(), and so on. After finding the square, the program will output the event, and then apply the effect on 
*       the player.  This function runs through its other smaller functions then returns back to the main menu via return 0.
*
* @returns 0 program ran successful.
*
* @param[in,out]       player_info[]  - This is an array that holds the player info like current funds/debts, amount of pets, etc.
*
***************************************************************************/
int square_events(int player_info[])
{
    square0_10(player_info);
    square11_20(player_info);
    square21_30(player_info);
    return 0;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function is part one of the square events function.  This function takes care of spots 0 through 10.
*       All 10 options vary between a status change, penalty/rewards, and payday options whuch change the player info arrays.
*       These changes effect the overall result of the game to whether the player wins or loses.  This function ends and goes to
*       square_events11-20 or square_events21-30 if the player_info[5] function does not equal to values between 0 and 10.  If so,
*       then the event is carried through and returns back to the main menu via return 0.
*
* @returns 0 program ran successful.
*
* @param[in,out]       player_info[]  - This is an array that holds the player info like current funds/debts, amount of pets, etc.
*
***************************************************************************/
int square0_10(int player_info[])
{
    if (player_info[5]-1 == 0)
    {
        cout << "Reward: Birthday Party -- gain 500" << endl;
        player_info[0] += 500;
    }
    else if (player_info[5]-1 == 1)
    {
        cout << "Penalty: Buy Books -- pay 500" << endl;
        player_info[0] -= 500;
    }
    else if (player_info[5]-1 == 2)
    {
        cout << "Reward: Aced your Midterm -- gain 1000 " << endl;
        player_info[0] += 1000;
    }
    else if (player_info[5]-1 == 3)
    {
        cout << "Penalty: Buy furniture -- pay 2000 " << endl;
        player_info[0] -= 2000;
    }
    else if (player_info[5]-1 == 4)
    {
        cout << "Penalty: Course Fees --Pay 700 " << endl;
        player_info[0] -= 700;
    }
    else if (player_info[5]-1 == 5)
    {
        cout << "Payday" << endl;
        player_info[0] += player_info[4];
    }
    else if (player_info[5]-1 == 6)
    {
        cout << "Status: You got a dog" << endl;
        player_info[2] += 1;
    }
    else if (player_info[5]-1 == 7)
    {
        cout << "Reward: Lucky day -- gain 2000" << endl;
        player_info[0] += 2000;
    }
    else if (player_info[5]-1 == 8)
    {
        cout << "Reward: Sold a project to a company -- gain 10000" << endl;
        player_info[0] += 10000;
    }
    else if (player_info[5]-1 == 9)
    {
        cout << "Status: You got a cat" << endl;
        player_info[3] += 1;
    }
    else if (player_info[5]-1 == 10)
    {
        if (player_info[1] >= 2000)
        {
            cout << "Penalty: Interest due. Pay $100 for every $2,000 owed in debt -- pay ";
            player_info[0] -= (player_info[1] / 2000) * 100;
            cout << (player_info[1] / 2000) * 100;
            cout << endl;
        }
        else
        {
            cout << "Avoided event" << endl;
        }
    }
    return 0;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function is part two of the square events function.  This function takes care of spots 11 through 20.
*       All 10 options vary between a status change, penalty/rewards, and payday options whuch change the player info arrays.
*       These changes effect the overall result of the game to whether the player wins or loses.  This function ends and goes to
*       square_events21-30 if the player_info[5] function does not equal to values between 11 and 21.  If so,
*       then the event is carried through and returns back to the main menu via return 0.
*
* @returns 0 program ran successful.
*
* @param[in,out]       player_info[]  - This is an array that holds the player info like current funds/debts, amount of pets, etc.
*
***************************************************************************/
int square11_20(int player_info[])
{
    if (player_info[5]-1 == 11)
    {
        cout << "Reward: Grandma came to visit -- gain 500" << endl;
        player_info[0] += 500;
    }
    else if (player_info[5]-1 == 12)
    {
        if (player_info[2] > 0)
        {
            cout << "Penalty: If you own a dog, it chewed through the door -- pay 700" << endl;
            player_info[0] -= 700;
        }
        else
        {
            cout << "Avoided Event" << endl;
        }
    }
    else if (player_info[5]-1 == 13)
    {
        cout << "Payday" << endl;
        player_info[0] += player_info[4];
    }
    else if (player_info[5]-1 == 14)
    {
        cout << "Penalty: Mice found! Call an exterminator -- pay 2000" << endl;
        player_info[0] -= 2000;
    }
    else if (player_info[5]-1 == 15)
    {
        cout << "Reward: Help friend move -- gain 1000" << endl;
        player_info[0] += 1000;
    }
    else if (player_info[5]-1 == 16)
    {
        cout << "Status: You got a cat" << endl;
        player_info[3] += 1;
    }
    else if (player_info[5]-1 == 17)
    {
        cout << "Reward: Won a new computer -- gain 1500" << endl;
        player_info[0] += 1500;
    }
    else if (player_info[5]-1 == 18)
    {
        cout << "Reward: Got a scholarship -- gain 5000 " << endl;
        player_info[0] += 5000;
    }
    else if (player_info[5]-1 == 19)
    {
        cout << "Payday" << endl;
        player_info[0] += player_info[4];
    }
    else if (player_info[5]-1 == 20)
    {
        cout << "Penalty: Your computer crashed when you worked on your final paper -- pay 3500 " << endl;
        player_info[0] -= 3500;
    }
    return 0;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function is the last part of the square events function.This function takes care of spots 21 through 30.
*       All 10 options vary between a status change, penalty / rewards, and payday options whuch change the player info arrays.
*       These changes effect the overall result of the game to whether the player wins or loses. This function ends and goes to
*       the following definition about being greater than 31 and checks to see if the player_info[5] function does not equal to 
*       values between 21 and 30.  If not, then the event is carried through and returns back to the main menu via return 0.
*       If so, then the program will output Congratulations, you graduated and goes to the end game function to calculate the 
*       final results.
*
* @returns 0 program ran successful.
*
* @param[in,out]       player_info[]  - This is an array that holds the player info like current funds/debts, amount of pets, etc.
*
***************************************************************************/
int square21_30(int player_info[])
{
    if (player_info[5]-1 == 21)
    {
        if (player_info[1] >= 2000)
        {
            cout << "Penalty: Interest due. Pay $100 for every $2,000 owed in debt -- pay ";
            player_info[0] -= (player_info[1] / 2000) * 100;
            cout << (player_info[1] / 2000) * 100;
            cout << endl;
        }
        else
        {
            cout << "Avoided event" << endl;
        }
    }
    else if (player_info[5]-1 == 22)
    {
        cout << "Status: You got a dog." << endl;
        player_info[2] += 1;
    }
    else if (player_info[5]-1 == 23)
    {
        cout << "Payday" << endl;
        player_info[0] += player_info[4];
    }
    else if (player_info[5]-1 == 24)
    {
        cout << "Penalty: Caught the flu -- pay 1000" << endl;
        player_info[0] -= 1000;
    }
    else if (player_info[5]-1 == 25)
    {
        if (player_info[2] > 0)
        {
            cout << "Penalty: If you have a dog, take it to the vet -- pay 300" << endl;
            player_info[0] -= 300;

        }
        else
        {
            cout << "Avoided Event" << endl;
        }
    }
    else if (player_info[5]-1 == 26)
    { 
        if (player_info[3] > 0)
        {
            cout << "Penalty: If you have a cat, take it to the vet -- pay 300" << endl;
            player_info[0] -= 300;
        }
        else
        {
            cout << "Avoided event" << endl;
        }
    }
    else if (player_info[5]-1 == 27)
    {
        if (player_info[2] > 0)
        {
            cout << "Reward: If you have a dog, it keeps you calm through final -- gain 300" << endl;
            player_info[0] += 300;
        }
        else
        {
            cout << "Avoided event" << endl;
        }
    }
    else if (player_info[5]-1 == 28)
    {
        if (player_info[3] > 0)
        {
            cout << "Reward: If you have a cat, it keeps you calm through final -- gain 300 " << endl;
            player_info[0] += 300;
        }
        else
        {
            cout << "Avoided event" << endl;
        }
    }
    else if (player_info[5]-1 == 29)
    {
        cout << "Reward: Job offer -- gain 5000" << endl;
        player_info[0] += 5000;
    }
    else if (player_info[5]-1 == 30)
    {
        cout << "Penalty: Final exam stress -- pay 1000" << endl;
        player_info[0] -= 1000;
    }
    else if (player_info[5] > 31)
    {
        cout << "Congratulations! You've graduated!" << endl;
        cout << endl;
    }
    return 0;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function ends the game after the player reaches the end of the board and graduates. When the player gets to the 
*       end of the board, the program will payback all debt at a rate of 2,500 per 2,000, and increase the function by $2,000 
*       per pet. The program will then output the final score, and then end the program with Goodbye.
*
* @returns 0 program ran successful.
*
* @param[in,out]       player_info[]  - This is an array that holds the player info like current funds/debts, amount of pets, etc.
*
***************************************************************************/
int end_game(int player_info[])
{
    int final_amount = 0;
    int amount_pets = player_info[2] + player_info[3];
    int debt_refunds = (player_info[1]/2000) * 2500;
    cout << fixed << setprecision(2);
    final_amount = (amount_pets * 2000) + player_info[0] - debt_refunds;
    cout << "Calculating results for test" << endl;
    cout << "   Total = $" << final_amount << ".00" << endl;
    if (final_amount > 0)
    {
        cout << "Congratulations, you win!" << endl << endl;
    }
    else
    {
        cout << "You lost!" << endl << endl;
    }
    cout << "Goodbye" << endl;
    return 0;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function will output a seperate menu called the Bank Menu. The bank menu will output Welcome to your bank, the user's current funds,
*       the user's current debt, 1) Borrow, 2) Pay, 0) Exit, and then ask for the user’s choice. The numbers are formatted with 2 digits past the
*       decimal point. The player can ask the back for money in increments of $2,000 or pay back the bank in $2000 increments.
*       If the user inputs an amount not in these increments, the program will output Invalid amount. Need multiple of $2,000.
*       In this function, asking for money will add the amount to the player's debt and money. Paying money subtracts the amount from the
*       user's debt and money. This function will then go back to the main menu when 0 us entered.  
*
* @returns 0 program ran successful.
*
* @param[in,out]       player_info[]  - This is an array that holds the player info like current funds/debts, amount of pets, etc.
*
***************************************************************************/
int bank_menu(int player_info[])
{
    int bank_choice_num = 100;
    int borrow_amount = 1;
    int pay_value = 1;
    while (bank_choice_num != 0)
    {
        cout << "Welcome to your bank" << endl;
        cout << "   Your current funds are : $" << player_info[0] << ".00" << endl;
        cout << "   Your current debt is: $" << player_info[1] << ".00" << endl << endl;
        cout << "1) Borrow" << endl;
        cout << "2) Pay" << endl;
        cout << "0) Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> bank_choice_num;
        if (bank_choice_num == 1)
        {
            while (borrow_amount % 2000 != 0)
            {
                cout << "Enter value to borrow or 0 to exit (multiple of $2,000): ";
                cin >> borrow_amount;
                if (borrow_amount % 2000 == 0)
                {
                    player_info[0] += borrow_amount;
                    player_info[1] += borrow_amount;
                    cout << endl;
                }
                else
                {
                    cout << "Invalid amount.  Need multiple of 2000." << endl;
                }
            }
        }
        else if (bank_choice_num == 2)
        {
            while (pay_value % 2000 != 0)
            {
                cout << "Enter value to pay or 0 to exit (multiple of $2,000): ";
                cin >> pay_value;
                if (pay_value % 2000 == 0)
                {
                    player_info[0] -= pay_value;
                    player_info[1] -= pay_value;
                    cout << endl;
                }
                else
                {
                    cout << "Invalid amount.  Need multiple of 2000." << endl;
                }
            }
               
        }
        else if (bank_choice_num == 0)
        {
            return 0;
        }
        else
        {
            cout << "Invalid Option" << endl;
        }
    }
    return 0;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This function will allow the user to bet on the wheel.  A player may choose the bet on wheel option once per turn. 
*       If a player attempts to bet on the wheen again, it will output: Extra bet not allowed in this turn. The player may 
*       place $1,000 on two numbers in the range [1, 6]. The wheel is then spun. If the spin is on that number, the player gains 
*       $10,000. It will then output You are betting against the wheel, and ask for the 2 numbers, the wheel will be spun, and the 
*       result will be outputted. After this happens, the function will redirect back to the main menu function with the value return 0;
*
* @returns 0 program ran successful.
*
* @param[in]            debug_mode     - Determines if the seed letter is in debug mode.
* @param[in,out]        player_info[]  - This is an array that holds the player info like current funds/debts, amount of pets, etc.
* @param[in,out]        no_bet_wheel   - This determines if the player decides to either to bet on the wheel or not.
* @param[in]            spin_value     - This determines the spin value that helps the player know how much to move.
*
***************************************************************************/
int bet_on_wheel(bool debug_mode, int player_info[], int spin_value, bool &no_bet_wheel)
{
    int bet_choice_num1 = 0;
    int bet_choice_num2 = 0;
    if (no_bet_wheel == false)
    {
        cout << "You are betting against the wheel" << endl;
        cout << "Your bet is $1,000, you need to choose 2 numbers from 1 to 6." << endl;
        cout << "Choose number 1 : ";
        cin >> bet_choice_num1;
        cout << "Choose number 2 : ";
        cin >> bet_choice_num2;
        spin_value = spin(debug_mode, no_bet_wheel);
        if (spin_value >= bet_choice_num1 && spin_value <= bet_choice_num2)
        {
            cout << "YOU WIN! You receive $10,000" << endl;
            player_info[0] += 10000;
        }
        else
        {
            cout << "You lost your bet" << endl;
            player_info[0] -= 1000;
        }
        no_bet_wheel = true;
    }
    else
    {
        cout << "Extra bet not allowed in this turn." << endl;
    }
    return 0;
}