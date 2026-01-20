#include <iostream>
#include <string>
#include <limits> // For stress testing limits
#include "SugarSupplier.hpp"
#include "ChocolateSupplier.hpp"
#include "CandyMaker.hpp"
#include "CandyBox.hpp"

// --- 1. Custom Object to Test Constructor/Destructor/Copying logic ---
struct ComplexCandy {
    std::string name;
    double price;
    int calories;

    // Default Constructor (Required for 'new T[]')
    ComplexCandy() : name("Generic"), price(0.0), calories(0) {}

    // Parameterized Constructor
    ComplexCandy(std::string n, double p, int c) : name(n), price(p), calories(c) {}

    // Overload << so CandyBox can display it
    friend std::ostream& operator<<(std::ostream& os, const ComplexCandy& c) {
        os << "[Candy: " << c.name << " | $" << c.price << " | " << c.calories << "kcal]";
        return os;
    }
};

void testEdgeCases() {
    std::cout << "\n=== TEST 1: EDGE CASES & BAD INPUT ===" << std::endl;
    CandyBox<int> box(2); // Start small

    // 1. Removing from empty box (if count is 0)
    std::cout << "[Action] Removing from empty box (Index 0)..." << std::endl;
    // Note: Your removeAt throws if index >= count. If count is 0, index 0 is invalid.
    bool result = box.removeItem(0); 
    if (!result) std::cout << "-> PASS: Correctly blocked removal from empty box." << std::endl;

    // 2. Add some items
    box.addItem(10);
    box.addItem(20);

    // 3. Negative Index
    std::cout << "[Action] Removing Index -5..." << std::endl;
    result = box.removeItem(-5);
    if (!result) std::cout << "-> PASS: Correctly blocked negative index." << std::endl;

    // 4. Out of Bounds Index
    std::cout << "[Action] Removing Index 100 (Count is 2)..." << std::endl;
    result = box.removeItem(100);
    if (!result) std::cout << "-> PASS: Correctly blocked out-of-bounds index." << std::endl;
}

void testDifferentTypes() {
    std::cout << "\n=== TEST 2: DIFFERENT TYPES ===" << std::endl;

    // 1. Strings (Standard)
    std::cout << "--- Testing std::string ---" << std::endl;
    CandyBox<std::string> stringBox(2);
    stringBox.addItem("GummyBear");
    stringBox.addItem("JellyBean");
    stringBox.displayItems();

    // 2. Raw Pointers (const char*) - The tricky one!
    // This works for string literals (stored in static memory).
    std::cout << "--- Testing const char* (Raw Pointers) ---" << std::endl;
    CandyBox<const char*> charBox(2);
    charBox.addItem("RawCharPointer1");
    charBox.addItem("RawCharPointer2");
    charBox.displayItems();

    // 3. Custom Complex Objects
    // This proves your array correctly copies entire objects, not just pointers.
    std::cout << "--- Testing Custom ComplexCandy Objects ---" << std::endl;
    CandyBox<ComplexCandy> objectBox(2);
    objectBox.addItem(ComplexCandy("LuxuryTruffle", 12.99, 400));
    objectBox.addItem(ComplexCandy("DietAir", 0.00, 0));
    objectBox.addItem(ComplexCandy("MegaBar", 5.50, 1200)); // Triggers Resize
    objectBox.displayItems();
}

void stressTest() {
    std::cout << "\n=== TEST 3: STRESS TEST (MEMORY) ===" << std::endl;
    CandyBox<int> stressBox(2); 
    
    // 50,000 items ensures your resize() function runs ~15-16 times 
    // (2 -> 4 -> 8 ... -> 65536)
    int limit = 50000; 

    std::cout << "[Stress] Adding " << limit << " integers..." << std::endl;
    for(int i = 0; i < limit; i++) {
        stressBox.addItem(i);
    }
    std::cout << "-> PASS: Added " << limit << " items without crashing." << std::endl;

    std::cout << "[Stress] Removing 5,000 items from the FRONT..." << std::endl;
    // Removing from index 0 is O(N). Doing this 5000 times is computationally heavy.
    // If your shift logic is wrong, this will segfault.
    for(int i = 0; i < 5000; i++) {
        stressBox.removeItem(0); 
    }
    std::cout << "-> PASS: Shifted massive array 5000 times successfully." << std::endl;
}

int main() {
    try {
        testEdgeCases();
        testDifferentTypes();
        stressTest();
        std::cout << "\n\n[SUCCESS] ALL ROBUSTNESS TESTS COMPLETED!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\n[CRITICAL FAILURE] Uncaught exception in main: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}