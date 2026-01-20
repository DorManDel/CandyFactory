// Dor Mandel , ID : 315313825;
// Niv Badichi, ID : 207018904;
// -----------------------------------------------------------
#pragma once
// -----------------------------------------------------------
#include <iostream>
#include <string>
// -----------------------------------------------------------
#include "SugarSupplier.hpp"
#include "ChocolateSupplier.hpp"
// -----------------------------------------------------------
using std::string;
// -----------------------------------------------------------

class CandyMaker : public SugarSupplier , public ChocolateSupplier 
{
public:
    // Constructor: must initialize BOTH base classes
    /* Summary:
    Purpose: Initializes the CandyMaker using names for both the sugar and chocolate suppliers.
    Implementation Detail:
    Call the constructors of SugarSupplier and ChocolateSupplier with the given names.
    (Optional) If you want, store a char* for something like currentCandy that might be empty initially.*/
    CandyMaker(const string& suggarSupplierName , const string& ChocolateSupplierName) : SugarSupplier(suggarSupplierName), ChocolateSupplier(ChocolateSupplierName){}
    
     /* Added Default to Generate the destructor implementation right here
     use the default CompilerGenerated Destructor - no special Cleanup; */
    ~CandyMaker() = default;
    
    /* Summary:
    Purpose: Simulate the act of creating a candy using sugar and chocolate.
    Implementation Detail:
    Print a statement that references both sugar and chocolate suppliers, e.g.:
    "Using sugar from [getSugarName()] and chocolate from [getChocolateName()] to create [candyName]! 🍭".
    You do not necessarily need to store candyName, but you could if you want to track what candy was last made.*/
    void makeCandy(const string& candyName)
    {
        SugarSupplier::supplySugar();
        ChocolateSupplier::supplyChocolate();
        std::cout << " CandyMaker " << candyName << ": Mixing ingredients... 🍭"<< std::endl;
    }
};
