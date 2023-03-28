#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>

using namespace std;

void getWallSize(double &wall_width, double &wall_height);
void getPhotoArragement(int &rows, int &columns);
void getPhotoSize(int curr_row, int curr_colmn, double &photo_width, double &photo_height);
void printResults(bool exceeded_width, double sum_height, double wall_height);

int main()
{
    double wall_height;
    double wall_width;
    int rows;
    int columns;
    double photo_width;
    double photo_height;
    bool exceeded_width = false;
    double sum_width = 0;
    double sum_height = 0;
    double max_height;

    getWallSize(wall_width, wall_height);
    getPhotoArragement(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            //For each photo
            getPhotoSize(i, j, photo_width, photo_height);
            sum_width += photo_width; 
            if (j == 0)
            {
                max_height = photo_height;
            }

            if (photo_height > max_height)
            {
                max_height = photo_height;
            }
        }
        //End of each row
        //For each row
        if (sum_width > wall_width)
        {
            exceeded_width = true;
        }
        
        sum_width = 0;
        sum_height += max_height;
    }
    printResults(exceeded_width, sum_height, wall_height);



    return 0;
}

void getWallSize(double &wall_width, double &wall_height)
{
    cout << "Enter wall width: ";
    cin >> wall_width;
    cout << "Enter wall height: ";
    cin >> wall_height;
}
void getPhotoArragement(int &rows, int &columns)
{
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;
}
void getPhotoSize(int curr_row, int curr_colmn, double &photo_width, double &photo_height)
{
    cout << "Enter width for photo in row " << curr_row << ", column " 
         << curr_colmn << ": ";
    cin >> photo_width;
    cout << "Enter height for photo in row " << curr_row << ", column " 
         << curr_colmn << ": ";
    cin >> photo_height;
}
void printResults(bool exceeded_width, double sum_height, double wall_height)
{
    if ((exceeded_width)|| (sum_height > wall_height))
    {
        cout << "Photo will not fit" << endl;
    }
    else
    {
        cout << "Photo will fit" << endl;
    }
}