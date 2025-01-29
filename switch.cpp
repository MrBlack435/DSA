#include <iostream>
using namespace std;

int main()
{
    int marks;
    cout << "Enter your marks:";
    cin >> marks;

    // Take the input from the user

    // This is a Ternary Operation.
    // To print Grade from A to F
    char grade = (marks >= 90) ? 'A' : (marks >= 80) ? 'B'
                                   : (marks >= 70)   ? 'C'
                                   : (marks >= 60)   ? 'D'
                                                     : 'F';
    cout << "Your grade is " << grade;
    // This is a Switch Case.
    // To print statement.
    switch (grade)
    {
    case 'A':
        cout << "Excellent work!,";
        break;

    case 'B':
        cout << "Well Done!, ";
        break;

    case 'C':
        cout << "Good Job!,  ";
        break;

    case 'D':
        cout << "You Passed!, ";
        break;

    case 'F':
        cout << "Sorry, You Failed, ";
        break;
    };

    // This is an if-else case.
    // To check eligibility for next level.

    if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D')
    {
        cout << "You are eligible for the next round, ";
    }
    else
    {
        cout << "Please try again next time, ";
    }
}