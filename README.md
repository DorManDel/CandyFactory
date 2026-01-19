# 🍬 The Candy Factory Challenge: Detailed Function Requirements 🍬

Welcome once again to our wonderful Candy Factory Challenge! Here, you’ll be diving into **multiple inheritance** and **templates** in C++. Below is an **explicit** breakdown of **each function** we expect you to implement. No need to guess—just follow the sweet instructions. 😁

## What are you going to do?
- **SugarSupplier**: Manages the supply of sugar. You’ll store a supplier name, dynamically allocate memory for it, and provide a function to simulate sugar being supplied.
- **ChocolateSupplier**: Manages the supply of chocolate. Similar to `SugarSupplier`, you store a name and simulate chocolate supply.
- **CandyMaker**: Inherits publicly from both `SugarSupplier` and `ChocolateSupplier`. This represents your main candy factory worker who relies on both sugar and chocolate to create candy.
- **CandyBox<T>**: A templated container class that can store items (either candy names or candy objects, depending on your design). You’ll use dynamic arrays and carefully handle memory to add, remove, and display items.

---

## 1. `SugarSupplier` Class

### **Constructor: `SugarSupplier(const char* supplierName)`**
- **Purpose**: Initializes the `SugarSupplier` object with a name for the supplier (e.g., `"SugarCo"`).
- **Implementation Detail**:  
  - Dynamically allocate memory to store the `supplierName` in a `char* sugarName` member.  
  - Copy the passed `supplierName` into that `char*`.

### **Getter: `const char* getSugarName() const`**
- **Purpose**: Returns the current sugar supplier name.
- **Implementation Detail**:  
  - Just returns the stored `char*`.  
  - Make sure it's a `const` function to indicate it doesn't modify member data.

### **Setter: `void setSugarName(const char* newName)`**
- **Purpose**: Updates the sugar supplier name with a new one.
- **Implementation Detail**:  
  - Free (delete[]) the currently allocated memory for `sugarName`.  
  - Dynamically allocate new memory for `newName` and copy it over.

### **Function: `void supplySugar()`**
- **Purpose**: Simulate the process of supplying sugar to the Candy Maker.
- **Implementation Detail**:  
  - Print a comedic statement like: `"[SugarName] is now supplying sugar! 🍬"`.  
  - This helps us verify that our `CandyMaker` can call sugar-supplying functionality.

---

## 2. `ChocolateSupplier` Class

### **Constructor: `ChocolateSupplier(const char* supplierName)`**
- **Purpose**: Initializes the `ChocolateSupplier` object with a name for the chocolate supplier (e.g., `"ChocoDelight"`).
- **Implementation Detail**:  
  - Dynamically allocate memory to store the `supplierName` in a `char* chocolateName` member.  
  - Copy the passed `supplierName` into that `char*`.

### **Getter: `const char* getChocolateName() const`**
- **Purpose**: Returns the current chocolate supplier name.
- **Implementation Detail**:  
  - Returns the stored `char*`.  
  - Mark as `const` to prevent unintended modifications.

### **Setter: `void setChocolateName(const char* newName)`**
- **Purpose**: Updates the chocolate supplier name with a new one.
- **Implementation Detail**:  
  - Delete the old memory.  
  - Dynamically allocate new space for `newName` and copy it over.

### **Function: `void supplyChocolate()`**
- **Purpose**: Simulate the process of supplying chocolate to the Candy Maker.
- **Implementation Detail**:  
  - Print something fun like: `"[ChocolateName] is now supplying chocolate! 🍫"`.

---

## 3. `CandyMaker` Class

**Inherits publicly from** `SugarSupplier` **and** `ChocolateSupplier`.

### **Constructor: `CandyMaker(const char* sugarSupplierName, const char* chocolateSupplierName)`**
- **Purpose**: Initializes the `CandyMaker` using names for both the sugar and chocolate suppliers.
- **Implementation Detail**:  
  - Call the constructors of `SugarSupplier` and `ChocolateSupplier` with the given names.  
  - (Optional) If you want, store a `char*` for something like `currentCandy` that might be empty initially.  

### **Function: `void makeCandy(const char* candyName)`**
- **Purpose**: Simulate the act of creating a candy using sugar and chocolate.
- **Implementation Detail**:  
  - Print a statement that references both sugar and chocolate suppliers, e.g.:  
    `"Using sugar from [getSugarName()] and chocolate from [getChocolateName()] to create [candyName]! 🍭"`.  
  - You **do not** necessarily need to store `candyName`, but you **could** if you want to track what candy was last made.

---

## 4. `CandyBox<T>` Template Class

A container class that uses **dynamic arrays** (no `std::vector`!) to store any type `T`.

### **Constructor: `CandyBox(int size)`**
- **Purpose**: Initializes the CandyBox with a given **capacity**.
- **Implementation Detail**:  
  - Dynamically allocate an array of type `T` of length `size`.  
  - Store it in `items`.  
  - Set `capacity = size` and `count = 0`.

### **Destructor: `~CandyBox()`**
- **Purpose**: Clean up allocated memory for `items`.
- **Implementation Detail**:  
  - Call `delete[]` on your `items` pointer.  
  - Set `items` to `nullptr` if you wish to be extra safe (though not strictly required).

### **Function: `bool addItem(const T& newItem)`**
- **Purpose**: Adds a new item to the CandyBox if there’s still room.
- **Implementation Detail**:  
  - Check if `count < capacity`. If not, return `false`.  
  - Otherwise, store `newItem` in `items[count]`, increment `count`, and return `true`.

### **Function: `bool removeItem(int index)`**
- **Purpose**: Removes an item at the given `index`, if valid.
- **Implementation Detail**:  
  - Check if `index` is in range (`0 <= index < count`). If invalid, return `false`.  
  - Shift items left to fill the gap—**or** simply replace the removed item with the last item in the array and decrement `count`. Implementation is up to you as long as it’s consistent.  
  - Return `true` if successfully removed.

### **Function: `void displayItems() const`**
- **Purpose**: Print out the items currently in the box.
- **Implementation Detail**:  
  - Iterate from `0` to `count - 1`.  
  - Print each item. If `T` is a `char*`, just `std::cout << items[i] << std::endl;`. If `T` is a custom type, handle accordingly.

---

## 🍭 Putting It All Together in `main.cpp`

Your `main.cpp` should:
1. Create a `CandyMaker` using two supplier names (for `SugarSupplier` and `ChocolateSupplier`).  
2. Call `supplySugar()` and `supplyChocolate()`.  
3. Call `makeCandy()` with a test candy name.  
4. Create a `CandyBox<const char*>` (or any other type you prefer) with a certain capacity.  
5. Add items, display them, remove one item, and display again to show it all works.

**Example Flow**:
```cpp
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
```
