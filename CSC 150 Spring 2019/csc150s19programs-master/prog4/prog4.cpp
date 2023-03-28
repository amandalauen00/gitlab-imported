#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <windows.h>

using namespace std;

/*
@brief The maximum width/height of an image
*/
const int MAX_SIZE = 50;

const int BLACK = 0;
const int DIM_BLUE = 1;
const int DIM_GREEN = 2;
const int DIM_CYAN = 3;
const int DIM_RED = 4;
const int DIM_MAGENTA = 5;
const int DIM_YELLOW = 6;
const int GREY = 7;
const int DIM_GREY = 8;
const int BLUE = 9;
const int GREEN = 10;
const int CYAN = 11;
const int RED = 12;
const int MAGENTA = 13;
const int YELLOW = 14;
const int WHITE = 15;

const int BACK = 0;
const int FORE = 1;

const char RANGE_ERR[] = "Out of Range Input";
const char TYPE_ERR[] = "File type not supported.";
const char BAR[] = "--------------------------";

void color_options();
int color_select();
void cout_color(int fColor, int bColor, const char text[]);
void cout_color(int fColor, int bColor, char letter);
//default1( … ) // make the map for command d1
//default2( … ) // make the map for command d2
void display(); //TO DO you will need to complete this
void edit_tiles(); //TO DO you will need to complete this
//get_extension( … )  //TO DO make the function return the extension of a file name
void grow_city(); //TO DO you will need to complete this
//load_file( … ) //TO DO load files starting here
void main_menu(); //TO DO you will need to complete this
//process_cammand_line( … )// TO DO process the command line
// save_file(..) //TO DO save files starting here
// tile_stats( .. );  //TO DO make the function find the number of tiles of a given type

int main()
{

    cout_color(WHITE, BLACK, "***Land Area Sim***");
    cout << endl;

    main_menu();

    cout << "\nGoodbye..." << endl;
    return 0;
}

void color_options()
{
    cout << endl;
    cout << "0 None (BLACK) | ";
    cout << "1 Ocean (D BLUE) | ";
    cout << "2 Forest (D GREEN) | ";
    cout << "3 Swamp (D CYAN)" << endl;
    cout << "4 Savana (D RED) | ";
    cout << "5 Marker (D MAGENTA) | ";
    cout << "6 Mountain (D YELLOW) | ";
    cout << "7 Road (GREY)" << endl;
    cout << "8 Rock (DARK GREY) | ";
    cout << "9 River (BLUE) | ";
    cout << "10 Plains (GREEN) | ";
    cout << "11 Marker (CYAN)" << endl;
    cout << "12 Lava (RED) | ";
    cout << "13 Marker (MAGENTA) | ";
    cout << "14 Sand (YELLOW) | ";
    cout << "15 Snow (WHITE)" << endl;
    cout << "-1 CANCEL" << endl;
    cout << BAR << endl;
}

//a helper function that will continue to ask for color input
//until a valid color is selected
//it then returns the color id
int color_select()
{
    int color = -2;
    while (color < -1 || color >15)
    {
        cin >> color;

        if (color < -1 || color >15)
        {
            cout << RANGE_ERR << endl;
            cout << "Retry: ";
        }
    }
    return color;
}

void display()
{
    //output title

    //if the map width is greater than 9
    //output first line of the header
        //for the entire width, 
            //if the current position is under 0, output ' '
            //otherwise output position / 10 with cout

    //output the second line of the header
        //for the entire width, output position %10 with cout

    //for each tile, use cout_color() to output its character and given background and foreground
        //at the beginning of each row, output the row number with width 2
}


//the edit tiles menu
void edit_tiles()
{

    cout << endl;
    cout << "1) Print Current Image" << endl;
    cout << "2) Change tile" << endl;
    cout << "0) Exit menu" << endl;
    cout << BAR << endl;
    cout << "Selection: ";

}


//grows a city if a plains tile is next to a city tile "X"
void grow_city()
{
    //TODO copy map so we don't use a new city tile


    //for each tile

       //if it is a plain or road

           //check all neighboring tiles (-1 to +1 along row and column)

               //if this neighbor is within bounds

                   //If the text marks the neighbor as a city
                        //mark the current tile in the map copy (not the neighbor) as a city
                        //and copy the foreground over


    //copy new city location and foreground colors to the original
}


//prints the main menu with some input validation
void main_menu()
{

    cout << endl;
    // TODO display(...);
    cout << "1) Load image \n";
    cout << "2) Change Title \n";
    cout << "3) Save image \n";
    cout << "4) Count tiles of type\n";
    cout << "5) Edit tiles\n";
    cout << "6) Grow Cities\n";
    cout << "0) Exit" << endl;
    cout << BAR << endl;
    cout << "Selection: ";

}

//Do NOT touch anything after this line--------------------------------------------

/** ****************************************************************************
* @par Description:
* Prints a character with the given background and foreground color.
*
* @param[in]      fColor - the foreground color id from 0-15
* @param[in]      bColor - the background color id from 0-15
* @param[in]      letter - the letter to print
//*****************************************************************************/
void cout_color(int fColor, int bColor, char letter)
{
    char text[2] = "";
    text[0] = letter;
    cout_color(fColor, bColor, text);
}

/** ****************************************************************************
* @par Description:
* Prints the with the given background and foreground color.
* No new line is added.
*
* @param[in]      fColor - the foreground color id from 0-15
* @param[in]      bColor - the background color id from 0-15
* @param[in]      text - the text to print
//*****************************************************************************/
void cout_color(int fColor, int bColor, const char text[])
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (fColor + (bColor * 16)));
    cout << text;

    //reset color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WHITE + (BLACK * 16)));
}
