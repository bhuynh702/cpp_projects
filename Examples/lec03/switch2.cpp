/*Title: switch2.cpp
Author: CMSC 202
Date: 9/6/2023
Description: This is practicing a more complicated switch statements in c++.
*/

#include <iostream> //This is the Standard Input / Output Streams Library
using namespace std; //This is the namespace for our code
const int max_income1 = 9325;
const int max_income2 = 37950;
const int max_income3 = 91900;
const int max_income4 = 191650;
const int max_income5 = 416700;
const int max_income6 = 418400;
const int max_income7 = 999999999;
const double base_income1 = 0.0;
const double base_income2 = 932.50;
const double base_income3 = 5226.25;
const double base_income4 = 18713.75;
const double base_income5 = 46643.75;
const double base_income6 = 120910.25;
const double base_income7 = 121505.25;
const double tax_income1 = 0.10;
const double tax_income2 = 0.15;
const double tax_income3 = 0.25;
const double tax_income4 = 0.28;
const double tax_income5 = 0.33;
const double tax_income6 = 0.35;
const double tax_income7 = 0.396;
int main () {
    double income = 0.0;
    double base = 0.0;
    double tax = 0.0;
    int bracket = 0;
    cout << "Single Taxable Income Tax Brackets and Rates, 2017" << endl;
    cout << "What was your taxable income for 2016?" << endl;
    cin >> income;
    
    if(income < max_income1)
        bracket = 1;
    else if (income < max_income2)
        bracket = 2;
    else if (income < max_income3)
        bracket = 3;
    else if (income < max_income4)
        bracket = 4;
    else if (income < max_income5)
        bracket = 5;
    else if (income < max_income6)
        bracket = 6;
    else
        bracket = 7;
    switch (bracket){
        case 1:
            tax = income * tax_income1;
            break;
        case 2:
            tax = base_income2 + (income - max_income1) * tax_income2;
            break;
        case 3:
            tax = base_income3 + (income - max_income2) * tax_income3;
            break;
        case 4:
            tax = base_income4 + (income - max_income3) * tax_income4;
            break;
        case 5:
            tax = base_income5 + (income - max_income4) * tax_income5;
            break;
        case 6:
            tax = base_income6 + (income - max_income5) * tax_income6;
            break;
        case 7:
            tax = base_income7 + (income - max_income6) * tax_income7;
            break;
        default:
            tax = 0;
    }
    cout << "Gross Income: " << income << endl;
    cout << "Tax: " << tax << endl;
    cout << "Income after tax: " << income - tax << endl;
  return 0;
}
