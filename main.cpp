// Dor Mandel , ID : 315313825;
// ========================================================================
// Compile: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o candyfactory
// Run: ./candyfactory
// ========================================================================

// -----------------------------------------------------------
#include <iostream>
// -----------------------------------------------------------
// Include the headers for your classes:
 #include "SugarSupplier.hpp"
 #include "ChocolateSupplier.hpp"
 #include "CandyMaker.hpp"
 #include "CandyBox.hpp"
// -----------------------------------------------------------

int main() {
    // 1. Create a CandyMaker with sugar and chocolate supplier names
    CandyMaker myCandyMaker("SugarCo", "ChocoDelight");

    // 2. Demonstrate supplySugar() and supplyChocolate()
    myCandyMaker.supplySugar();
    myCandyMaker.supplyChocolate();

    // 3. Make a candy
    myCandyMaker.makeCandy("Fudge Surprise");

    // 4. Create a CandyBox for storing candy names
    CandyBox<std::string> candyBox(5);

    // 5. Add items
    candyBox.addItem("SourLollipop");
    candyBox.addItem("MintChoco");
    candyBox.addItem("CaramelSwirl");

    // 6. Display contents
    std::cout << "Contents of CandyBox:" << std::endl;
    candyBox.displayItems();

    // 7. Remove an item and display again
    candyBox.removeItem(1); // removing "MintChoco"

    std::cout << "Contents of CandyBox after removal:" << std::endl;
    candyBox.displayItems();

    return 0;
}

/*
CandyMaker maker("SugarCo", "ChocoDelight");
maker.supplySugar();
maker.supplyChocolate();
maker.makeCandy("Fudge Surprise");

// The CandyBox
CandyBox<const char*> box(5);
box.addItem("SourLollipop");
box.addItem("MintChoco");
box.displayItems();
box.removeItem(1);
box.displayItems();
*/

/*
CandyMaker maker("SugarCo", "ChocoDelight");
maker.makeCandy();
*/

/*

                               ___                           
                              (   )                          
  .--.     .---.  ___ .-.   .-.| | ___  ___                  
 /    \   / .-, \(   )   \ /   \ |(   )(   )                 
|  .-. ; (__) ; | |  .-. .|  .-. | | |  | |                  
|  |(___)  .'`  | | |  | || |  | | | |  | |                  
|  |      / .'| | | |  | || |  | | | '  | |                  
|  | ___ | /  | | | |  | || |  | | '  `-' |                  
|  '(   ); |  ; | | |  | || '  | |  `.__. |                  
'  `-' | ' `-'  | | |  | |' `-'  /  ___ | |                  
 `.__,'  `.__.'_.(___)(___)`.__,'  (   )' |                  
                                    ; `-' '                  
                                     .__.'                   
  .-.                    ___                                 
 /    \                 (   )                                
 | .`. ;  .---.   .--.   | |_      .--.  ___ .-.   ___  ___  
 | |(___)/ .-, \ /    \ (   __)   /    \(   )   \ (   )(   ) 
 | |_   (__) ; ||  .-. ; | |     |  .-. ;| ' .-. ; | |  | |  
(   __)   .'`  ||  |(___)| | ___ | |  | ||  / (___)| |  | |  
 | |     / .'| ||  |     | |(   )| |  | || |       | '  | |  
 | |    | /  | ||  | ___ | | | | | |  | || |       '  `-' |  
 | |    ; |  ; ||  '(   )| ' | | | '  | || |        `.__. |  
 | |    ' `-'  |'  `-' | ' `-' ; '  `-' /| |        ___ | |  
(___)   `.__.'_. `.__,'   `.__.   `.__.'(___)      (   )' |  
                                                    ; `-' '  
                                                     .__.'   

*/