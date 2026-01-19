// Dor Mandel , ID : 315313825;
// -----------------------------------------------------------
#pragma once
// -----------------------------------------------------------
#include <iostream>
#include <string>
// -----------------------------------------------------------
using std::string;
// -----------------------------------------------------------

class ChocolateSupplier
{
private:
    string _chocolateName;
public:
    /* Summary:
    Purpose: Initializes the ChocolateSupplier object with a name for the chocolate supplier (e.g., "ChocoDelight").
    Implementation Detail:
    Dynamically allocate memory to store the supplierName in a char* chocolateName member.
    Copy the passed supplierName into that char*.*/
    ChocolateSupplier(const string& supplierName) : _chocolateName(supplierName){}

    ~ChocolateSupplier(){};

    /* Summary:
    Purpose: Returns the current chocolate supplier name.
    Implementation Detail:
    Returns the stored char*.
    Mark as const to prevent unintended modifications*/
    inline const string& getChocolateName() const {return _chocolateName;}

    /* Summary:
    Purpose: Updates the chocolate supplier name with a new one.
    Implementation Detail:
    Delete the old memory.
    Dynamically allocate new space for newName and copy it over.*/
    inline void setChocolateName(const string& newName){_chocolateName = newName;}
    
    /* Summary:
    Purpose: Simulate the process of supplying chocolate to the Candy Maker.
    Implementation Detail:
    Print something fun like: "[ChocolateName] is now supplying chocolate! 🍫".*/
    void supplyChocolate() const {std::cout<<"["<< _chocolateName << "] is now supplying chocolate! 🍫"<<std::endl;}
};
