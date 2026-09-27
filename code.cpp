/*
 Student Name: Ibrahim Quraishi
 Assignment: Homework Assignment 1
 Program Description: This program calculates the total cost of a project, determines the remaining budget, and computes the average cost of each component.
 */

#include <iostream>
#include <string>
#include <iomanip>    
#include <limits>    
#include <cstdint>   

using namespace std;

int main() {
    

    cout << "==========================================================" << endl;
    cout << "Welcome to the Project Calculator Program!" << endl;
    cout << "By: Ibrahim Quraishi" << endl;
    cout << "This program calculates the amount of money your project" << endl;
    cout << "will cost, how much money you will have left over, and" << endl;
    cout << "the average cost of each component for your project." << endl;
    cout << "==========================================================" << endl << endl;

    string projectName;
    double budget = 0.0;           
    int numComponents = 0;          
    int price = 0;                
    int totalCostInt = 0;           
    double remainingBudget = 0.0;
    double faultyAverage = 0.0;     
    double correctAverage = 0.0;    
    const int MAX_COMPONENTS = 100; 

 
    cout << "What's the name of your project? ";
    cin >> projectName;
    
    cout << "Enter your total budget: $";
    cin >> budget;
    
    cout << "Enter the number of components needed for your project: ";
    cin >> numComponents;
    
 
    if (numComponents > MAX_COMPONENTS || numComponents <= 0) {
        cout << "Invalid number of components! Maximum is " << MAX_COMPONENTS << "." << endl;
        return 0;
    }
    
    cout << endl;
    
    
    for (int i = 1; i <= numComponents; i++) {
        cout << "Enter the price for component #" << i << " (whole numbers only): $";
        cin >> price;
        totalCostInt = totalCostInt + price; 
    }

    
    // Demonstrate integer division error
    // Because totalCostInt and numComponents are both integers, C++ chops off the decimal!
    faultyAverage = totalCostInt / numComponents;
    
    // Use static_cast to fix the integer division
    // We temporarily turn totalCostInt into a double so we get a true decimal average
    correctAverage = static_cast<double>(totalCostInt) / numComponents;
    
 
    remainingBudget = budget - totalCostInt;


    cout << endl;
    cout << "--- Data Type Information (Behind the Scenes) ---" << endl;
    // Using sizeof
    cout << "Size of a double in memory: " << sizeof(double) << " bytes." << endl;
    // Using numeric_limits
    cout << "The maximum value an 'int' can hold is: " << numeric_limits<int>::max() << endl;
    cout << "-------------------------------------------------" << endl << endl;


    cout << fixed << setprecision(2);
    
    cout << "========================================" << endl;
    cout << "          PROJECT FINAL REPORT          " << endl;
    cout << "========================================" << endl;
    

    cout << left << setw(25) << "Project Name:" << projectName << endl;
    cout << left << setw(25) << "Starting Budget:" << "$" << budget << endl;
    cout << left << setw(25) << "Number of Components:" << numComponents << endl;
    cout << left << setw(25) << "Total Cost:" << "$" << static_cast<double>(totalCostInt) << endl;
    cout << left << setw(25) << "Remaining Budget:" << "$" << remainingBudget << endl;
    
    cout << "----------------------------------------" << endl;
    
    
    cout << left << setw(25) << "Average Cost (Wrong):" << "$" << faultyAverage << " <-- (Decimal lost due to int division)" << endl;
    cout << left << setw(25) << "Average Cost (Correct):" << "$" << correctAverage << endl;
    cout << "========================================" << endl;

    return 0; // End of program
}
