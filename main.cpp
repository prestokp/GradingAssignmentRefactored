//Kirk Preston
//06/23/19
//Programming Fundamentals 1

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//global variables that are constants
const int NUM_ASSIGNMENT = 3;
const int GRADE_NUMBER = 3;

//Function prototypes, allows us to name them in any order and call them in any order

string getStudentName();
void getAssignment(string assignmentName[], int size);
void getGrades(int grades[], string assignmentName[], int size);
double getAverage(int grades[], int size);
void displayAverage(string studentName, string assignmentNames[], int grades[], double gradeAverage, int size);

//starts the program
int main() {

    //this code block defines all of the variables that will be used throughout the program
    double gradeAverage;
    string studentName;
    string assignmentName[NUM_ASSIGNMENT];
    int grades[GRADE_NUMBER];

    //function calls that call the function definitions below main that carry out their respective instructions
    studentName = getStudentName();
    getAssignment(assignmentName, NUM_ASSIGNMENT);
    getGrades(grades, assignmentName, GRADE_NUMBER);
    gradeAverage = getAverage(grades, NUM_ASSIGNMENT);
    displayAverage(studentName, assignmentName, grades, gradeAverage, NUM_ASSIGNMENT);

    return 0;
}

//Function definition for getStudentName
//takes in a string of the students name, returns that students name, that's the purpose of this function

string getStudentName (){
    string studentName;
    cout << "What is your first and last name: ";
    getline(cin, studentName);
    cout << endl;
    return studentName;
    //one line code to get the entire line: getline(cin, studentName);
}

//Function definition for getting the assignment names
//the purpose of this function is to return all assignment names from the assignment array
//Array allows for an easier/efficient way to collect multiple assignment names

void getAssignment(string assignmentName[], int size){

    //Captures the name of the assignment via getline
    //names can have spaces in their strings which can affect the capture when using a regular cin method
    cout << "\nEnter the names of the " << size
        << " assignments to be graded.\n";

    cout << "Enter assignment name 1: ";
    getline(cin, assignmentName[0]);

    cout << "Enter assignment name 2: ";
    getline(cin, assignmentName[1]);

    cout << "Enter assignment name 3: ";
    getline(cin, assignmentName[2]);

    cout << endl << endl;

}
//Function definition for getting the assignment grades
//the purpose of this function is to return all grades from the grades array
//Array allows for an easier/efficient way to collect multiple integer grades


void getGrades(int grades[], string assignmentName[], int size){

    cout << "\nNow enter the grades of the " << NUM_ASSIGNMENT
        << " assignments.\n";

    cout << "Enter grade for " << assignmentName[0]
         << " : ";                                      //These are the iostreams that prompt the user to enter their grades in
    cin >> grades[0];                                   //The grades must be entered in as integers, needs a more descriptive prompt

    cout << "Enter grade for " << assignmentName[1]
         << " : ";                                      //grades is an array so simply changing the indices refers to a different
                                                        //integer
    cin >> grades[1];

    cout << "Enter grade for " << assignmentName[2]
         << " : ";
    cin >> grades[2];

    cout << endl << endl;

}

//This function definition has the averaging mathematical expression
//the purpose of this function is to take all grades and average them by the number of grades present
//integration of the constant into the expression allows for easier adjustments to the program to account for more grades


double getAverage(int grades[], int size){

    double gradeAverage;
    gradeAverage =  (grades[0] + grades[1] + static_cast<double>(grades[2])) / size;
    return gradeAverage;

    //Average expression, static type cast
    //as extra redundancy to ensure the data type gets converted to a double
    //Dividing by the global constant allows us to only have to change the variable value in one location
}


//This function definition displays the grade average, the grades, assignment, and student name

void displayAverage(string studentName, string assignmentName[], int grades[], double gradeAverages, int size){
    cout << "The average for " << studentName << " is " << fixed << showpoint << setprecision(1)
    << getAverage(grades, size)
         << endl;

    //when array solution is implemented the output variable will
    //simply be studentName

    //table header
    cout << "\nHere are your grades: " << endl;


    //formats the output so that it appears orderly and in columns
    cout << setw(25) << assignmentName[0] << ": " << setw(4) << right << grades[0] << endl;
    cout << setw(25) << assignmentName[1] << ": " << setw(4) << right << grades[1] << endl;
    cout << setw(25) << assignmentName[2] << ": " << setw(4) << right << grades[2] << endl;
    cout << endl << endl;

    cout << endl << endl;
    cout << "Thank you for playing. ";
}

//Github Push Test