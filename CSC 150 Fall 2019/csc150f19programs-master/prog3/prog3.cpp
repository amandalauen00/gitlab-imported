/** ***************************************************************************
* @file
*
* @mainpage Program 3 - Converting Units
*
* @section course_section Course Information
*
* @author Amanda Lauen
*
* @date November 8th, 2019
*
* @par Professor
*      Kelly Corwin
*
* @par Course
*      CSC150 - M003 - 3:00pm
*
* @par Location
*      Classroom Building - Room 328
*
* @section program_section Program Information
*       The program begins with the program showing the main menu. The user has
*       a choice to pick 'T', 'D', 'V' or 'X' for temperature, distance, volume
*       , or exit. If the user selects the letter "t" case-insensitive, then
*      it leads to the temperature menu.  The temperature menu has three 
*      choices and allows the user to pick either Fahrenheit (F case 
*      insensitve), Celsius (C case insensitve), or returning back to the main 
*      menu. If the user picks F then the program will ask the user for a 
*      number and then call the approprite function to convert that number into
*      Celsius, and will return back to the main menu.  If the user chooses C, 
*      then the program will again ask the user for a number and then call the 
*      approprite function convert that into Fahrenheit.  If the user enters 
*       "x" case insensitive, then it will return back to the main menu. If the
*       user enters anything else, it will return back to the temperature menu.
*
*      If the user enters in "D" case insensitive, then the program leads to
*      the distance menu.  The distance menu has three choices and allows the
*      user to choose between Miles to Metric (M case insensitive), 
*      Kilometers to Imperial (I case insensitive), or x case insensivive which
*      brings the user back to the main menu function.  If the user selects M,
*      then the program will ask the user for a value to convert and then then
*      call the approprite function to convert the value into kilometers and 
*      meters and display it and return to the main menu function.  If the user
*      selects I, then the program will ask the user for a value to convert 
*      and then then call the approprite function to convert the value into 
*      imperical values of miles and feet and return the user back to the main 
*      menu.  If any other character value is entered, it will return back to 
*      the distance menu.
*
*     If the user enters "V" case insensitive, then the program leads to the 
*     volume menu. This will has the user to enter in a value to convert. If
*     the user enters "L" case insentive, the program will recognize that the
*     value is in liters and will go into the convert volume function for futher
*     conversions and will return the converted volume and associated symbol it
*     needs.  It will also return the user back to the main menu afterwards. 
*     If the user enters "G" case insentive, the program will recognize
*     that the value is in liters and will go into the convert volume function
*     for futher conversions and will return the converted volume and 
*     associated symbol it needs. It will also return the user back to the
*     main menu afterwards. If the user enters "Q" case insentive, the
*     program will recognize that the value is in liters and will go into the
*     convert_volume function for futher conversions and will return the 
*     converted volume and associated symbol it needs. It will also return
*     the user back to the main menu afterwards. If any other value is 
*     entered, then it will be an invalid option and will return back to the
*     volume conversion menu.
*
*     If any other selection is made by the user, then it will output an
*     invalid option statement and show the main menu again.
*
*     Return 0 means that the program worked.
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
* @bug Can't get functions to show up on Doxygen, just like other code
*
* @todo None
*
***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main();

//Function prototypes
void show_main_menu();
double celsius_to_fahrenheit(double temp_F, double temp_C);
double fahrenheit_to_celcius(double temp_F, double temp_C);
void miles_to_metric(double miles_value, double &metric_value, double &km_metric_value);
void km_to_imperial(double kilometer_value, double &imperical_value_miles, double &imperical_value_feet);
double convert_volume(double volume_value, char volume_selection, string &symbol);
void run_conversions(char &user_selection);
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This functions sets the initial user selection to 1 and starts the 
*       program by calling the run conversions function.  When all the 
*       conversions are done, this function will be called again and will
*       print the final message of "Goodbye!" to the user.  This function
*       returns 0 when it is successful.
*
* @returns 0 program ran successful.
*
***************************************************************************/
int main()
{
    //Initialize variables
    char user_selection = 1;
    cout << fixed << setprecision(4); 
    //Call run conversions to start program
    run_conversions(user_selection);

   //If the user asks to exit the program, goodbye statement
    cout << "Goodbye!" << endl;
    
    //Returns 0 when run successfully
    return 0;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      The show main menu function shows the user the initial main menu.
*      This menu comes up when a user hits "x" or "X" in any of the submenus.
*      This function does not return anything and has no parameters. It just
*      shows the main cout statements.
***************************************************************************/
void show_main_menu()
{
        //Output menu
        cout << "Unit Conversion Tool" << endl << endl;
        cout << "Main Menu: " << endl;
        cout << "--------------------" << endl;
        cout << "(T) Temperature" << endl;
        cout << "(D) Distance" << endl;
        cout << "(V) Volume" << endl;
        cout << "(X) Exit" << endl;
        cout << "Select the type of conversion: ";
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      This large function does all the conversions based on the selection the 
*      user makes.  If the user selects the letter "t" case-insensitive, then
*      it leads to the temperature menu.  The temperature menu has three 
*      choices and allows the user to pick either Fahrenheit (F case 
*      insensitve), Celsius (C case insensitve), or returning back to the main 
*      menu. If the user picks F then the program will ask the user for a 
*      number and then convert that number into Celsius, and will return back
*      to the main menu.  If the user chooses C, then the program will again 
*      ask the user for a number and convert that into Fahrenheit.  If the user
*      enters "x" case insensitive, then it will return back to the main menu.
*      If the user enters anytng else, it will return back to the temperature
*      menu.
*
*      If the user enters in "D" case insensitive, then the program leads to
*      the distance menu.  The distance menu has three choices and allows the
*      user to choose between Miles to Metric (M case insensitive), 
*      Kilometers to Imperial (I case insensitive), or x case insensivive which
*      brings the user back to the main menu function.  If the user selects M,
*      then the program will ask the user for a value to convert and then convert
*      the value into kilometers and meters and display it and return to the main
*      menu function.  If the user selects I, then the program will ask the user
*      for a value to convert and then convert the value into imperical values 
*      of miles and feet and return the user back to the main menu.  If any
*      other character value is entered, it will return back to the distance
*      menu.
*
*     If the user enters "V" case insensitive, then the program leads to the 
*     volume menu. This will has the user to enter in a value to convert. If
*     the user enters "L" case insentive, the program will recognize that the
*     value is in liters and will go into the convert volume function for futher
*     conversions and will return the converted volume and associated symbol it
*     needs.  It will also return the user back to the main menu afterwards. 
*     If the user enters "G" case insentive, the program will recognize
*     that the value is in liters and will go into the convert volume function
*     for futher conversions and will return the converted volume and 
*     associated symbol it needs. It will also return the user back to the
*     main menu afterwards. If the user enters "Q" case insentive, the
*     program will recognize that the value is in liters and will go into the
*     convert volume function for futher conversions and will return the 
*     converted volume and associated symbol it needs. It will also return
*     the user back to the main menu afterwards. If any other value is 
*     entered, then it will be an invalid option and will return back to the
*     volume conversion menu.
*
*     If any other selection is made by the user, then it will output an
*     invalid option statement and show the main menu again.
*
* @param[in,out]            user_selection     - Dictates what menu and 
*                                                conversion will be used.
***************************************************************************/
void run_conversions(char &user_selection)
{
    //while x is not entered at Main menu
    show_main_menu();
    //Ask the user for their selection
    cin >> user_selection;
    //While the user selection doesn't equal "x" or "X"
    while (user_selection != 'x' && user_selection != 'X')
    {
        //If the user enters "t" or "T"
        if ((user_selection == 'T') || (user_selection == 't'))
        {
            //Initialize variables
            char temp_selection = 1;
            double temp_C = 0;
            double temp_F = 0;
           //While all the options are false, the menu will come up and 
           //ask for a value
            while (temp_selection != 'F' && temp_selection != 'f' && temp_selection != 'C' 
                   && temp_selection != 'c' && temp_selection != 'X' && temp_selection != 'x')
            {
                cout << endl;
                //Output temperature menu
                cout << "Temperature conversion: " << endl;
                cout << "--------------------" << endl;
                cout << "(F) From Celsius to Fahrenheit" << endl;
                cout << "(C) From Fahrenheit to Celsius" << endl;
                cout << "(X) Back to main menu" << endl;
                //Ask for temperature selection
                cout << "Select the type of conversion: ";
                cin >> temp_selection;
                //If the user wants to convert from Celcius to Fahrenheit
                if ((temp_selection == 'F') || (temp_selection == 'f'))
                {
                    //Ask for the temperature in Celsius
                    cout << "Enter the temperature in Celsius: ";
                    cin >> temp_C;
                    //Call celsus_to_fahrenheit function
                    temp_F = celsius_to_fahrenheit(temp_F, temp_C);
                    //Output final result
                    cout << temp_C << " degrees Celsius is equivalent to "
                        << temp_F << " degrees Fahrenheit" << endl << endl;
                }
                //If the user wants to convert from Fahrenheit to Celcius
                else if ((temp_selection == 'C') || (temp_selection == 'c'))
                {
                    //Ask for the temperature in Fahrenheit
                    cout << "Enter the temperature in Fahrenheit: ";
                    cin >> temp_F;
                    //Call the fahrenheit_to_celcius function
                    temp_C = fahrenheit_to_celcius(temp_F, temp_C);
                    //Output final values
                    cout << temp_F << " degrees Fahrenheit is equivalent to "
                        << temp_C << " degrees Celsius" << endl << endl;
                }
                //If the temperature selection is 'x' or 'X'
                else if ((temp_selection == 'X') ||
                    (temp_selection == 'x'))
                {
                    cout << endl;
                }
                //If any option other than those is entered, error message
                else
                {
                    cout << "Invalid Option" << endl;

                }
            }
        }
        //If the user selected distance 'D' or 'd'
        else if ((user_selection == 'D') || (user_selection == 'd'))
        {
            //Initialize variables
            char distance_selection = 1;
            double miles_value;
            double kilometers_value;
            double imperical_value_miles;
            double imperical_value_feet;
            double metric_value;
            double km_metric_value;

            //While all the options are not true, the menu will ask for a unit
            while (distance_selection != 'M' && distance_selection != 'm' 
                  && distance_selection != 'I' && distance_selection != 'i' 
                  && distance_selection != 'X' && distance_selection != 'x')
            {
                cout << endl;
                //Display distance menu
                cout << "Distance conversion: " << endl;
                cout << "--------------------" << endl;
                cout << "(M) Miles to Metric" << endl;
                cout << "(I) Kilometers to Imperial" << endl;
                cout << "(X) Back to Main Menu" << endl;
                //Ask the user for which distance they want
                cout << "Select the type of conversion: ";
                cin >> distance_selection;
                //If the user wants to convert from miles to metric
                if ((distance_selection == 'M') || (distance_selection == 'm'))
                {
                    //Ask for miles value they wish to convert
                    cout << "Enter the distance in miles: ";
                    cin >> miles_value;
                    //Call miles_to_metric function
                    miles_to_metric(miles_value, metric_value, km_metric_value);
                    //Display results
                    cout << miles_value << " mi is equivalent to "
                        << km_metric_value << " km or " << metric_value << " m"
                        << endl << endl;
                }
                //If the user wants to convert from imperical to metric
                else if ((distance_selection == 'I') ||
                    (distance_selection == 'i'))
                {
                    //Ask the user for the kilometer value they wish to convert
                    cout << "Enter the distance in Kilometers: ";
                    cin >> kilometers_value;
                    //Call km_to_imperial function
                    km_to_imperial(kilometers_value, imperical_value_miles, imperical_value_feet);
                    //Display results
                    cout << kilometers_value << " Km is equivalent to "
                        << imperical_value_miles << " mi or "
                        << imperical_value_feet << " ft" << endl << endl;
                }
                //If the user wants to return to the main menu
                else if ((distance_selection == 'X') ||
                    (distance_selection == 'x'))
                {
                    cout << endl;
                }
                //If the user enters something out of range, error message
                else
                {
                    cout << "Invalid option" << endl;
                }
            }
        }
        //If the user chose Volume 'v' or 'V'
        else if ((user_selection == 'V') || (user_selection == 'v'))
        {
            //Initialize variables
            char volume_selection = 1;
            double volume_value;
            double converted_volume = 0;
            string symbol = "ut";

            //Display menu
            cout << endl;
            cout << "Volume conversion: " << endl;
            cout << "--------------------" << endl;
            //Ask user to enter the volume they wish to convert from
            cout << "Enter the volume to convert: ";
            cin >> volume_value;

            //While none of the options work, the menu will ask for a valid 
            //unit
            while (volume_selection != 'L' && volume_selection != 'l' && volume_selection != 'G'
                && volume_selection != 'g' && volume_selection != 'Q' && volume_selection != 'q')  
            {
                
               //Ask the user which unit they wish to convert from
                cout << "Select unit to convert from (L for liter, G for "
                    << "gallons, or Q for Quarters: ";
                cin >> volume_selection;
                //If converting from liters, then symbol turns to "l" and
                //calls the converted_volume function
                if ((volume_selection == 'L') || (volume_selection == 'l'))
                {
                    symbol = "l";
                    converted_volume = convert_volume(volume_value, volume_selection, symbol);
                }
                //If converting from gallons, then symbol turns to "gal" and
                //calls the converted_volume function
                if ((volume_selection == 'G') || (volume_selection == 'g'))
                {
                    symbol = "gal";
                    converted_volume = convert_volume(volume_value, volume_selection, symbol);
                }
                //If converting from quarts, then symbol turns to "qt" and
                //calls the converted_volume function
                if ((volume_selection == 'Q') || (volume_selection == 'q'))
                {
                    symbol = "qt";
                    converted_volume = convert_volume(volume_value, volume_selection, symbol);
                }

                      
            } 
            //Output results
            cout << "You have approximately " << converted_volume << " " << symbol
                << endl << endl;
        }
        //If any of the user selections were out of bounds, error message
        else
        {
            cout << "Invalid option" << endl << endl; 
        }
        //Call show_main_menu function and asks user to reenter a new selection
        show_main_menu();
        cin >> user_selection;
    }
    
}

/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      This function is the conversion factor for turing degrees 
*      Celsius to Fahrenheit.  This function takes in the previous two
*      numbers entered in by the user and converts Celcius value to 
*      Fahrenheit value. This function returns the temperature in Fahrenheit,
*      when it runs successfully.
*
* @returns temp_F to the run_conversions function when successful
*
* @param[in]            temp_F   - Holds the value of temperature in Fahrenheit
* @param[in]            temp_C   - Holds the value of temperature in Celcius
***************************************************************************/
double celsius_to_fahrenheit(double temp_F, double temp_C)
{
    //Temperature from Celsius to Fahrenheit equation
    temp_F = (temp_C * (9 / 5.0) + 32);
    //Return temp_F to the run_conversions function
    return temp_F;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      This function is the conversion factor for turing degrees
*      Fahrenheit to Celsius.  This function takes in the previous two
*      numbers entered in by the user and converts Fahrenheit value to
*      Celcius value. This function returns the temperature in Celcius,
*      when it runs successfully.
*
* @returns temp_C to the run_conversions function when successful
*
* @param[in]            temp_F   - Holds the value of temperature in Fahrenheit
* @param[in]            temp_C   - Holds the value of temperature in Celcius
***************************************************************************/
double fahrenheit_to_celcius(double temp_F, double temp_C)
{
    //Temperature from Fahrenheit to Celsius equation
    temp_C = ((temp_F - 32) * (5 / 9.0));
    //Return temp_C back to the run_conversions function
    return temp_C;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      This function is the conversion factor for turing miles to
*      metric.  This function takes in the previous two
*      numbers entered in by the user and converts miles value to
*      metric values. This function calulates both kilometers and meters.
*      This function feeds back to the run_conversions function and displays
*      the result to the user.
*
* @param[in]           miles_value      - Holds the miles value given by the 
*                                       user
* @param[in,out]       metric_value     - Holds the calulated value for meters
* @param[in,out]       km_metric_value  - Holds the calulated value for 
*                                       kilometers
***************************************************************************/
void miles_to_metric(double miles_value, double &metric_value, 
                     double &km_metric_value)
{
    //Distance from miles to metric value equation
    metric_value = (miles_value * 1609.34);
    //Distance from miles to kilo-metric value equation
    km_metric_value = (metric_value / 1000);
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      This function is the conversion factor for turning kilometers to
*      imperical values.  This function takes in the previous two
*      numbers entered in by the user and converts kilometer value to
*      imperical values. This function calulates both miles and feed.
*      This function feeds back to the run_conversions function and displays
*      the result to the user.
*
* @param[in]           kilometer_value           - Holds the kilometers value given by the
*                                                user
* @param[in,out]       imperical_value_miles     - Holds the calulated value for miles
* @param[in,out]       imperical_value_feet      - Holds the calulated value for
*                                                 kilometers

***************************************************************************/
void km_to_imperial(double kilometer_value, double &imperical_value_miles, 
                    double &imperical_value_feet)
{
    //Distance from kilometer values to imperical values in miles equation
    imperical_value_miles = (kilometer_value * 1000 * 5280) / (1609.34 * 5280);
    //Distance from kilometer values to imperical values in feet equation
    imperical_value_feet = imperical_value_miles * 5280;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      This function deterimines which volume conversion to do.  If the
*      volume selection is 'L' case insensitive, then the function will ask
*      the user for the unit for which they wish to convert to. If the unit is
*      "L", "G" or "Q" case insensitive, then conversions happen and return 
*      back to the run_conversions function and will output the result to the
*      user. If the volume selection is 'G' case insensitive, then the function
*      will ask the user for the unit for which they wish to convert to. If the
*      unit is "L", "G", or "Q" case insensitive, then conversions happen and 
*      return back to the run_conversions function and will output the result 
*      to the user. If the volume selection is 'Q' case insensitive, then the
*      function will ask the user for the unit for which they wish to convert 
*      to. If the unit is "L", "G", or "Q" case insensitive, then conversions 
*      happen and return back to the run_conversions function and will output 
*      the result to the user. Any other values entered in these seperature 
*      statements will reask the user for a valid conversion until two are 
*      found that are the same.
*
* @returns converted volume back to the run_conversions function when successful
* @returns
*
* @param[in]           volume_value           - Holds the volume value given by
*                                               the user
* @param[in]          volume_selection        - Holds the volume selection from
*                                               what the user selected in the
*                                               run_conversions function
* @param[in,out]      symbol                  - Changes the original symbol to
*                                               the newly converted symbol
***************************************************************************/
double convert_volume(double volume_value, char volume_selection, string &symbol)
{
    //Initialize local variables
    double liter_value = 0;
    double gallon_value = 0;
    double quarts_value = 0;
    double converted_volume = 0;
    char convert_choice = 'A';

    //If the volume is equal to liters case insensitive
    if ((volume_selection == 'L') || (volume_selection == 'l'))
    {
        //While all the correct options are false
        while (convert_choice != 'L' && convert_choice != 'l' && convert_choice != 'G'
            && convert_choice != 'g' && convert_choice != 'Q' && convert_choice != 'q')
        {
            //Ask user for the unit inwhich they want to convert to
            cout << "Select unit to convert to (L for liter, G for "
                << "gallons, or Q for Quarters: ";
            cin >> convert_choice;
        }

        //Liters to gallons conversion
        if ((convert_choice == 'G') || (convert_choice == 'g'))
        {
            gallon_value = volume_value / 4.546;
            converted_volume = gallon_value;
            symbol = "gal";
        }
        //Liters to quarts conversion
        else if ((convert_choice == 'Q') || (convert_choice == 'q'))
        {
            gallon_value = volume_value / 4.546;
            quarts_value = gallon_value / 0.25;
            converted_volume = quarts_value;
            symbol = "qt";
        }
        //Liters to liters conversion
        else if ((volume_selection == 'L') || (volume_selection == 'l'))
        {
            converted_volume = volume_value;
            symbol = "l";
        }

    }

    //If the volume selection is gallons case insensitive
    if ((volume_selection == 'G') || (volume_selection == 'g'))
    {
        //While all the correct options are false
        while (convert_choice != 'L' && convert_choice != 'l' && convert_choice != 'G'
            && convert_choice != 'g' && convert_choice != 'Q' && convert_choice != 'q')
        {
            //Ask the user for the unit in which they want to convert to
            cout << "Select unit to convert to (L for liter, G for "
                << "gallons, or Q for Quarters: ";
            cin >> convert_choice;
        }
        //Gallons to liters conversion
        if ((convert_choice == 'L') || (convert_choice == 'l'))
        {
            liter_value = volume_value * 4.546;
            converted_volume = liter_value;
            symbol = "l";
        }
        //Gallons to quarts conversion
        else if ((convert_choice == 'Q') || (convert_choice == 'q'))
        {
            quarts_value = volume_value * 0.25;
            converted_volume = quarts_value;
            symbol = "qt";
        }
        //Gallons to gallons conversion
        else if ((convert_choice == 'G') || (convert_choice == 'g'))
        {
            converted_volume = volume_value;
            symbol = "gal";
        }
    }

    //If the volume selection is quarts cse insensitive
    if ((volume_selection == 'Q') || (volume_selection == 'q'))
    {
        //While all the correct options are false
        while (convert_choice != 'L' && convert_choice != 'l' && convert_choice != 'G'
            && convert_choice != 'g' && convert_choice != 'Q' && convert_choice != 'q')
        {
            //Ask the user for the unit in which they want to convert to
            cout << "Select unit to convert to (L for liter, G for "
                << "gallons, or Q for Quarters: ";
            cin >> convert_choice;
        }
        //Quarts to liters conversion
        if ((convert_choice == 'L') || (convert_choice == 'l'))
        {
            gallon_value = volume_value / 0.25;
            liter_value = gallon_value / 4.546;
            converted_volume = liter_value;
            symbol = "l";
        }
        //Quarts to gallons conversion
        else if ((convert_choice == 'G') || (convert_choice == 'g'))
        {
            gallon_value = volume_value / 0.25;
            converted_volume = gallon_value;
            symbol = "gal";
        }
        //Quarts to quarts conversion
        else if ((convert_choice == 'Q') || (convert_choice == 'q'))
        {
            converted_volume = volume_value;
            symbol = "qt";
        }

    }

    //Returns converted_volume back to the run_conversions function
    return converted_volume;
}



