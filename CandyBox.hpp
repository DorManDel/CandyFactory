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

/*
CandyBox<T>:TEMPLATE:
---------------------
-DynamicArr
-capacity: MAX_ITEMS
-count: CURRENT_ITEMS
-addItem / removeItem / displayItems
*** implementing vector ish without vector ***
*/

template <typename T>
class CandyBox
{
private:
    T* _items;
    int _capacity;
    int _count;

public:
    /* Summary:
    Purpose: Initializes the CandyBox with a given capacity.
    Implementation Detail:
    Dynamically allocate an array of type T of length size.
    Store it in items.
    Set capacity = size and count = 0. */
    CandyBox(int size) : _items(nullptr), _capacity(size), _count(0)
    {
        if(_capacity < 1) { _capacity = 1;}
        _items = new T[_capacity];
    }
    /* Summary:
    Purpose: Clean up allocated memory for items.
    Implementation Detail:
    Call delete[] on your items pointer.
    Set items to nullptr if you wish to be extra safe (though not strictly required).*/
    ~CandyBox(){ delete[] _items ; _items = nullptr; }

    /* Summary:
    Adds a new item to the CandyBox if there’s still room.
    Implementation Detail:
    Check if count < capacity. If not, return false.
    Otherwise, store newItem in items[count], increment count, and return true. */
    bool addItem(const T& newItem)
    {
        if(_count >= _capacity) return false;
        _items[_count] = newItem;
        _count++;
        return true;
    }

    /* Summary: 
    Purpose: Removes an item at the given index, if valid.
    Implementation Detail:
    Check if index is in range (0 <= index < count). If invalid, return false.
    Shift items left to fill the gap—or simply replace the removed item with the last item in the array and decrement count. Implementation is up to you as long as it’s consistent.
    Return true if successfully removed.*/
    bool removeItem(int index)
    {
        if(index < 0 || index >= _count) return false;
        for (int i = index; i < _count; i++)
            {_items[i] = _items[i+1];}
        _count--;
        return true;
    }
    
    /* Summary:
    Purpose: Print out the items currently in the box.
    Implementation Detail:
    Iterate from 0 to count - 1.
    Print each item. If T is a char*, just std::cout << items[i] << std::endl;. If T is a custom type, handle accordingly.*/
    void displayItems() const 
    {
        using namespace std;
        for(int i = 0 ; i < _count ; i++)
        cout<< _items[i] << endl;
    }

    // ------------------------------------------------------
    // Helpers:
    int getCount() const { return _count;}
    int getCapacity() const { return _capacity;}
    
    //CopyConstructor:
    CandyBox(const CandyBox& other) : _items(nullptr), _capacity(other._capacity),_count(other._count)
    {*this = other;}
    
    //CopyOperator:
    CandyBox& operator=(const CandyBox& other)
    {
        if(this == &other) return *this;
        delete[] _items;

        _capacity = other._capacity;
        _count = other._count;
        
        // CopyConstructorLike
        _items = new T[_capacity];
        for(int i = 0; i < _count ; i++)
            _items[i] = other._items[i];

        return *this;
    }
};

