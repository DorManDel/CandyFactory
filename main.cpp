#include <iostream>
// Include the headers for your classes:
// #include "SugarSupplier.h"
// #include "ChocolateSupplier.h"
// #include "CandyMaker.h"
// #include "CandyBox.h"

int main() {
    // 1. Create a CandyMaker with sugar and chocolate supplier names
    CandyMaker myCandyMaker("SugarCo", "ChocoDelight");

    // 2. Demonstrate supplySugar() and supplyChocolate()
    myCandyMaker.supplySugar();
    myCandyMaker.supplyChocolate();

    // 3. Make a candy
    myCandyMaker.makeCandy("Fudge Surprise");

    // 4. Create a CandyBox for storing candy names
    CandyBox<Candy> candyBox(5);

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
