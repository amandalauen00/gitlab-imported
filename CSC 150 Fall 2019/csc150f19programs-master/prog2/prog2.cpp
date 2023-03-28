/** ***************************************************************************
* @file
*
* @mainpage Program 2 - Wave Analysis
*
* @section course_section Course Information
*
* @author Amanda Lauen
*
* @date October 11th, 2019
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
* This program allows the user to perform wave analysis based on the input 
* given by the user. The program starts by having the user enter a positive 
* number value. If it is a negative number or any other character or symbol 
* entered, there would be an error message prompting the user to start the 
* program again. Once a positive number value has been entered, the program 
* will ask the user to select the units they wish to put on the value. The only
* acceptable letters are H/h for Hertz, k/K for Kilohertz, T/t for Terahertz, 
* m/M for millimeters, or n/N for nanometers. If any other input is put in, 
* an error message will be outputted.
*
* If the user enters in H/h case insensitive, then the program will output to 
* the user that they have selected sound waves in Hertz. The program will run
* through the test of showing if the given value is within the correct range.  
* If not, then an error message will be printed. If the value is within 
* range, there will be extensive checks to see of the value qualifies for the 
* certain person/animal who could hear the sound. Each person/animal would be
* listed if they can hear that sound, if not they are not listed. The program 
* will then end with return 0.
*
* If the user enters in K/k case insensitive, then the program will output to 
* the user that they have selected sound waves in Kilohertz. The program will 
* run through the test of showing if the given value is within the correct 
* range. If not, then an error message will be printed. If the value is 
* within range, there will be extensive checks to see of the value qualifies 
* for the certain person/animal who could hear the sound. Each person/animal
* would be listed if they can hear that sound, if not they are not listed. The 
* program will then end with return 0.
*
* If the user enters T/t case insensitive, then the program will output to the 
* user that they have selected light waves in Terahertz. The program will run 
* through the test of showing if the given value is within the correct range.  
* If not, then an error message will be printed. If the value is within range, 
* there will be extensive checks to see of the value entered corresponds with 
* a light wave color. Only one color can be assigned to one value entered. 
* The program will then end with return 0.
*
* If the user enters N/n case insensitive, then the program will output to the 
* user that they have selected light waves in Nanometers. The program will run
* through the test of showing if the given value is within the correct range.  
* If not, then an error message will be printed. If the value is within 
* range, there will be extensive checks to see of the value entered corresponds
* with a light wave color. Only one color can be assigned to one value 
* entered. The program will then end with return 0.
*
* If the user enters m/M case insensitive, then the program will output to the 
* user that they have selected sound waves in Millimeters. The program will 
* run through the test of showing if the given value is within the correct 
* range. If not, then an error message will be printed. If the value is within 
* range, there will be extensive checks to see of the value qualifies for the 
* certain person/animal who could hear the sound. Each person/animal would be 
* listed if they can hear that sound, if not they are not listed. The program 
* will then end with return 0.
*
* The program will end with return 0 if it runs successfully.
*
* @section compiling_section Compiling and Usage
*
* @verbatim
  c:\> prog2.exe
  d:\> c:\bin\prog2.exe
  @endverbatim
*
* @section todo_bugs_modifications_section Todo, Bugs, and Modifications
*
* @bug Function header doesn't show up in Doxygen, just like last program.
*
* @todo None.
*
* <a href = "https://gitlab.mcs.sdsmt.edu/7452203/csc150f19programs
* /commits/master" target="_blank">The gitlab commit log</a>
*
***************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

/**
* @brief Speed of Sound constant for frequency equation
*/
const int SPEED_OF_SOUND = 343000;

/** ***************************************************************************
 * @author Amanda Lauen
 *
 * @par Description:
 *      This program allows the user to perform wave analysis based on the 
 *      information provided by the user. By the user entering in a positive
 *      number value and what unit they want to assign to the given value, the
 *      user will be able to see what animal/human can hear the wavelength via 
 *      Hertz, Kilohertz, or Terahertz or what color the wavelength is via
 *      millimeters or nanometers.  In anything ented is not within range, 
 *      it will show a seperate error message.  The program will return 0 if
 *      and can be exited with any key pressed on the keyboard.
 *
 * @returns 0 program ran successful.
 *
 ***************************************************************************/
int main()
{
    //Initialize varaibles
    int value;
    char units;
    int frequency_HZ;
    int frequency_KHz;
    int wavelength_nm;
    int frequency_THz;
    int wavelength_mm;
    
    cout << "Light and Sound Waves Analysis" << endl << endl;
    //Ask the user to enter a value
    cout << "Enter a value: ";
    cin >> value;

    //Determines if the market is greater than 0
    if (value > 0)
    {
        //Ask the user for the units that they wish for the value to be
        cout << "Select the units (H)z, (k)Hz, (T)Hz, (m)m, (n)m: ";
        cin >> units;

        //Determines if the unit is in Hertz
        if (units == 'H' || units == 'h')
        {
            cout << "You have selected Sound Waves" << endl;
            //Calculates the value of frequency in Hertz
            frequency_HZ = (SPEED_OF_SOUND) / (value);
            //Determines if the frequency is greater than -1
            if (frequency_HZ >= 15 && frequency_HZ <= 123000)
            {
                //Determines if humans can hear the value entered
                if (value >= 15 && value <= 15000)
                {
                    cout << "Humans can hear this sound" << endl;
                }
                //Determines if chickens can hear the value entered
                if (value >= 125 && value <= 2000)
                {
                    cout << "Chickens can hear this sound" << endl;
                }
                //Determines if elephants can hear the value entered
                if (value >= 17 && value <= 10500)
                {
                    cout << "Elephants can hear this sound" << endl;
                }
                //Determines if dogs can hear the value entered
                if (value >= 64 && value <= 44000)
                {
                    cout << "Dogs can hear this sound" << endl;
                }
                //Determines if gerbils can hear the value entered
                if (value >= 56 && value <= 60000)
                {
                    cout << "Gerbils can hear this sound" << endl;
                }
                //Determines if cats can hear the value entered
                if (value >= 55 && value <= 77000)
                {
                    cout << "Cats can hear this sound" << endl;
                }
                //Determines if little brown bats can hear the value entered
                if (value >= 10300 && value <= 115000)
                {
                    cout << "Little brown bats can hear this sound" << endl;
                }
                //Determines if beluga whales can hear the value entered
                if (value >= 1000 && value <= 123000)
                {
                    cout << "Beluga whales can hear this sound" << endl;
                }
            }
            //Determines if none of the animals are able hear the sound
            else
            {
                cout << "None of the selected animals can hear this sound" << endl;
            }       
        }

        //Determines of the unit is in Kilohertz
        else if (units == 'k' || units == 'K')
        {
            cout << "You have selected Sound Waves" << endl;
            //Assigns value entered to frequency in kilohertz
            frequency_KHz = value;
            //Convert Kilohertz to Hertz
            frequency_HZ = (frequency_KHz * 1000);
            if (frequency_HZ >= 15 && frequency_HZ <= 123000)
            {
                //Determines if humans can hear the value entered
                if (frequency_HZ >= 15 && frequency_HZ <= 15000)
                {
                    cout << "Humans can hear this sound" << endl;
                }
                //Determines if chickens can hear the value entered
                if (frequency_HZ >= 125 && frequency_HZ <= 2000)
                {
                    cout << "Chickens can hear this sound" << endl;
                }
                //Determines if elephants can hear the value entered
                if (frequency_HZ >= 17 && frequency_HZ <= 10500)
                {
                    cout << "Elephants can hear this sound" << endl;
                }
                //Determines if dogs can hear the value entered
                if (frequency_HZ >= 64 && frequency_HZ <= 44000)
                {
                    cout << "Dogs can hear this sound" << endl;
                }
                //Determines if gerbils can hear the value entered
                if (frequency_HZ >= 56 && frequency_HZ <= 60000)
                {
                    cout << "Gerbils can hear this sound" << endl;
                }
                //Determines if cats can hear the value entered
                if (frequency_HZ >= 55 && frequency_HZ <= 77000)
                {
                    cout << "Cats can hear this sound" << endl;
                }
                //Determines if little brown bats can hear the value entered
                if (frequency_HZ >= 10300 && frequency_HZ <= 115000)
                {
                    cout << "Little brown bats can hear this sound" << endl;
                }
                //Determines if beluga whales can hear the value entered
                if (frequency_HZ >= 1000 && frequency_HZ <= 123000)
                {
                    cout << "Beluga whales can hear this sound" << endl;
                }
            }
            //Determines if none of the animals are able hear the sound
            else
            {
                cout << "None of the selected animals can hear this sound" << endl;
            }
        }

        //Determine if the unit is Terahertz
        else if (units == 'T' || units == 't')
        {
            //Assign the value entered to frequency in teraHertz
            frequency_THz = value;
            cout << "You have selected Light Waves" << endl;
            //Determines if the value is within the requested range
            if (frequency_THz >= 420 && frequency_THz <= 790)
            {
                //Determines if the color is violet
                if (frequency_THz > 715 && frequency_THz <= 790)
                {
                    cout << "Color is Violet" << endl;
                }
                //Determines if the color is indigo
                else if (frequency_THz > 690 && frequency_THz <= 715)
                {
                    cout << "Color is Indigo" << endl;
                }
                //Determines if the color is blue
                else if (frequency_THz > 600 && frequency_THz <= 690)
                {
                    cout << "Color is Blue" << endl;
                }
                //Determines if the color is green
                else if (frequency_THz > 540 && frequency_THz <= 600)
                {
                    cout << "Color is Green" << endl;
                }
                //Determines if the color is yellow
                else if (frequency_THz > 510 && frequency_THz <= 540)
                {
                    cout << "Color is Yellow" << endl;
                }
                //Determines if the color is orange
                else if (frequency_THz > 480 && frequency_THz <= 715)
                {
                    cout << "Color is Orange" << endl;
                }
                //Determines if the color is red
                else if (frequency_THz > 420 && frequency_THz <= 480)
                {
                    cout << "Color is Red" << endl;
                }
            }
            //Option in case if the value is not in the given range
            else
            {
                cout << "This frequency is outside the visible light spectrum" << endl;
            }  
        }

        //Determines if the units are millimeters
        else if (units == 'm' || units == 'M')
        {
                cout << "You have selected Sound Waves" << endl;
                //Makes value become wavelength in millimeters
                wavelength_mm = value;
                //Determines if the wavelength in millimeters is within range
                if (wavelength_mm >= 15 && wavelength_mm <= 123000)
                {
                    //Calculates the frequency in Hertz
                    frequency_HZ = (SPEED_OF_SOUND) / wavelength_mm;
                    //Determines if humans can hear the value entered
                    if (frequency_HZ >= 15 && frequency_HZ <= 15000)
                    {
                        cout << "Humans can hear this sound" << endl;
                    }
                    //Determines if chickens can hear the value entered
                    if (frequency_HZ >= 125 && frequency_HZ <= 2000)
                    {
                        cout << "Chickens can hear this sound" << endl;
                    }
                    //Determines if elephants can hear the value entered
                    if (frequency_HZ >= 17 && frequency_HZ <= 10500)
                    {
                        cout << "Elephants can hear this sound" << endl;
                    }
                    //Determines if dogs can hear the value entered
                    if (frequency_HZ >= 64 && frequency_HZ <= 44000)
                    {
                        cout << "Dogs can hear this sound" << endl;
                    }
                    //Determines if gerbils can hear the value entered
                    if (frequency_HZ >= 56 && frequency_HZ <= 60000)
                    {
                        cout << "Gerbils can hear this sound" << endl;
                    }
                    //Determines if cats can hear the value entered
                    if (frequency_HZ >= 55 && frequency_HZ <= 77000)
                    {
                        cout << "Cats can hear this sound" << endl;
                    }
                    //Determines if little brown bats can hear the value entered
                    if (frequency_HZ >= 10300 && frequency_HZ <= 115000)
                    {
                        cout << "Little brown bats can hear this sound" << endl;
                    }
                    //Determines if beluga whales can hear the value entered
                    if (frequency_HZ >= 1000 && frequency_HZ <= 123000)
                    {
                        cout << "Beluga whales can hear this sound" << endl;
                    }
                }
                //Determines if none of the animals are able hear the sound
                else
                {
                    cout << "None of the selected animals can hear this sound" << endl;
                }
        }

        //Determines if the units are nanometers
        else if (units == 'n' || units == 'N')
        {
            cout << "You have selected Light Waves" << endl;
            //Assign the variable value to wavelength in nanometers
            wavelength_nm = value;
            //Determine if the wavelength in nanometers in within 
            //the given range
            if (wavelength_nm >= 380 && wavelength_nm <= 720)
            {
                //Determines if the wavelength color is violet
                if (wavelength_nm >= 380 && wavelength_nm <= 420)
                {
                    cout << "Color is Violet" << endl;
                }
                //Determines if the wavelength color is indigo
                else if (wavelength_nm > 420 && wavelength_nm <= 440)
                {
                    cout << "Color is Indigo" << endl;
                }
                //Determines if the wavelength color is blue
                else if (wavelength_nm > 440 && wavelength_nm <= 520)
                {
                    cout << "Color is Blue" << endl;
                }
                //Determines if the wavelength color is green
                else if (wavelength_nm > 520 && wavelength_nm <= 555)
                {
                    cout << "Color is Green" << endl;
                }
                //Determines if the wavelength color is yellow
                else if (wavelength_nm > 555 && wavelength_nm <= 590)
                {
                    cout << "Color is Yellow" << endl;
                }
                //Determines if the wavelength color is orange
                else if (wavelength_nm > 590 && wavelength_nm <= 625)
                {
                    cout << "Color is Orange" << endl;
                }
                //Determines if the wavelength color is red
                else if (wavelength_nm > 625 && wavelength_nm <= 720)
                {
                    cout << "Color is Red" << endl;
                }
            }
            //Determines if wavelength entered is outside the visible range
            else
            {
                cout << "This wavelength is outside the visible light spectrum" << endl;
            }
        }

        //Determines if the none of the unit selections are selected
        else
        {
            cout << "Invalid unit selection; please run program again" << endl;
        }
    }

    //Determines if the value entered is invalid
    else
    {
        cout << "Invalid value selection; please run program again" << endl;
    }


    //Ends program
    return 0;

}