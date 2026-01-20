// Dor Mandel , ID : 315313825;
// Niv Badichi, ID : 207018904;
// -----------------------------------------------------------
#pragma once
// -----------------------------------------------------------
#include <iostream>
#include <string>
// -----------------------------------------------------------
using std::string;
// -----------------------------------------------------------
// const char* != const string&(ref): i used string instead;

class SugarSupplier
{
private:
    string _sugarName;
public:
    /* Summary:
    Purpose: Initializes the SugarSupplier object with a name for the supplier (e.g., "SugarCo").
    Implementation Detail:
    Dynamically allocate memory to store the supplierName in a char* sugarName member.
    Copy the passed supplierName into that char*.*/
    SugarSupplier(const string& supplierName) : _sugarName(supplierName){}
  
    ~SugarSupplier(){};

    /* Summary: 
    Purpose: Returns the current sugar supplier name.
    Implementation Detail:
    Just returns the stored char*.
    Make sure it's a const function to indicate it doesn't modify member data.*/
    inline const string getSugarName() const { return _sugarName;}   

    /* Summary:
    Purpose: Updates the sugar supplier name with a new one.
    Implementation Detail:
    Free (delete[]) the currently allocated memory for sugarName.
    Dynamically allocate new memory for newName and copy it over.*/
    inline void setSugarName(const string& newName){_sugarName = newName;}

    /* Summary: 
    Purpose: Simulate the process of supplying sugar to the Candy Maker.
    Implementation Detail:
    Print a comedic statement like: "[SugarName] is now supplying sugar! 🍬".
    This helps us verify that our CandyMaker can call sugar-supplying functionality.*/
    inline void supplySugar() const {std::cout<<"["<< _sugarName << "] is now supplying sugar! 🍬"<<std::endl;}
};


