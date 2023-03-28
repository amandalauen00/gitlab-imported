/*
CSC 150 Fall 2019
Lab 11 p1008
Amanda Lauen
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Function Definitions
void getGrades(int user_grade_input, int exam_scores[]);
double calcAvg(int exam_scores[], int user_grade_input);
void findMinMax(int exam_scores[], int user_grade_input, int &max, int &min);

int main()
{
    //Declare variables
    int exam_scores[25];
    double average;
    int min;
    int max;
    int user_input;

    //Show opening message and ask for how many grades
    cout << "There is space for 25 grades available." << endl;
    cout << "How many grades to analyze? ";
    cin >> user_input;

    //Call function getGrades
    getGrades(user_input, exam_scores);

    //Calculate average by calling calcAvg function
    average = calcAvg(exam_scores, user_input);

    //Find both the max and min by calling findMinMax function
    findMinMax(exam_scores, user_input, max, min);

    //Show the average, min, and max of the data points presented
    cout << fixed << setprecision(2);
    cout << endl;
    cout << "Average: " << average << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    
     
    return 0;
}

//This function gets the grade values from the user until it 
// reaches the amount given in main
void getGrades(int user_grade_input, int exam_scores[])
{
    int i;
    cout << "Enter grades: ";
    for (i = 0; i < user_grade_input; i++)
    {
        cin >> exam_scores[i];
    }

}

//This function calculates the average of the exam scores and 
// returns it back to main
double calcAvg(int exam_scores[], int user_grade_input)
{
    double avg;
    int total_exam_scores = 0;
    int i;
    cout << fixed << setprecision(2);
    for (i = 0; i < user_grade_input; i++)
    {
        total_exam_scores += exam_scores[i]; 
    }
    avg = ((double) total_exam_scores / (double) user_grade_input);
    return avg;
}

//This function finds the max and min values within the data set and 
// passes it back to the main function
void findMinMax(int exam_scores[], int user_input_value, int &max, int &min)
{
    int i;
    int minSoFar = exam_scores[0];
    int maxSoFar = exam_scores[0];
    
    for (i = 0; i < user_input_value; i++)
    {
        if (exam_scores[i] > maxSoFar)
        {
            maxSoFar = exam_scores[i];

        }
        if (exam_scores[i] < minSoFar)
        {
            minSoFar = exam_scores[i];
            
        }
    }
    max = maxSoFar;
    min = minSoFar;
    
}
