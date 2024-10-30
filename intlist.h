// intlist.h
// Linked list header file

#ifndef INTLIST_H
#define INTLIST_H

class IntList
{
public:
    // Constructor and 3 methods already done in intlist.cpp (NO CHANGE):
    IntList();              // constructor
    void append(int value); // append value at end of list
    void print() const;     // print values separate by ' '
    int count() const;      // return count of values

    // Destructor, copy constructor and 6 other METHODS YOU MUST
    // IMPLEMENT IN intlist.cpp (NO CHANGE HERE):
    ~IntList();                     // Destructor
    IntList(const IntList &source); // Copy constructor (deep copy)
    int sum() const;                // Sum of all values
    bool contains(int value) const; // True if value in list
    int max() const;                // Maximum value
    double average() const;         // Average of all values
    void insertFirst(int value);    // Insert new first value

    IntList &operator=(const IntList &source); // Overloaded  (NO CHANGE)

private:
    // (Optional) You can add some private helper functions here.
    void copy(const IntList &source);
    void clear();

    // Definition of Node structure (DO NOT CHANGE)
    struct Node
    {
        int info;
        Node *next;
    };

    Node *first; // Pointer to first node (DO NOT CHANGE)
};

#endif // INTLIST_H
