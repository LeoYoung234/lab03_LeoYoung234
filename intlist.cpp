// intlist.cpp
// Implements class IntList
// Leonardo Young 10/30/24

#include "intlist.h"

#include <iostream>
using std::cout;

// Copy constructor
IntList::IntList(const IntList &source)
{
    copy(source);
}

// Destructor deletes all nodes
IntList::~IntList()
{
    clear();
}

// Return sum of values in list
int IntList::sum() const
{
    Node *curr = first;
    int sum = 0;
    while (curr != nullptr)
    {
        sum += curr->info;
        curr = curr->next;
    }
    return sum;
}

// Returns true if value is in the list; false if not
bool IntList::contains(int value) const
{
    Node *curr = first;
    while (curr != nullptr)
    {
        if (curr->info == value)
            return true;
        curr = curr->next;
    }
    return false;
}

// Returns maximum value in list, or 0 if empty list
int IntList::max() const
{
    if (first == nullptr)
        return 0;
    int biggest = first->info;
    Node *curr = first->next;
    while (curr != nullptr)
    {
        if (curr->info > biggest)
            biggest = curr->info;
        curr = curr->next;
    }
    return biggest;
}

// Returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const
{
    if (first == nullptr)
        return 0.0;
    Node *curr = first;
    int count = 0;
    while (curr != nullptr)
    {
        count += 1;
        curr = curr->next;
    }
    return static_cast<double>(sum()) / count;
}

// Inserts value as new node at beginning of list
void IntList::insertFirst(int value)
{
    first = new Node{value, first};
}

// Assignment operator should copy the list from the source
// to this list, deleting/replacing any existing nodes
IntList &IntList::operator=(const IntList &source)
{
    if (this != &source)
    {
        clear();
        copy(source);
    }
    return *this;
}

// copy helper
void IntList::copy(const IntList &source)
{
    if (!source.first)
    {
        first = nullptr;
    }
    else
    {
        first = new Node{source.first->info, nullptr};

        Node *curr = first;
        Node *sourceCurr = source.first->next;
        while (sourceCurr)
        {
            curr->next = new Node{sourceCurr->info, nullptr};
            curr = curr->next;
            sourceCurr = sourceCurr->next;
        }
    }
};

// clear helper
void IntList::clear()
{
    Node *curr = first;
    while (curr != nullptr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    first = nullptr;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// Constructor sets up empty list
IntList::IntList() : first(nullptr) {}

// Append value at end of list
void IntList::append(int value)
{
    if (first == nullptr)
    { // Empty list
        first = new Node;
        first->info = value;
        first->next = nullptr;
    }
    else
    {
        Node *n = first;
        while (n->next) // Not last node yet
            n = n->next;

        n->next = new Node;
        n->next->info = value;
        n->next->next = nullptr;
    }
}

// Print values enclose in [], separated by spaces
void IntList::print() const
{
    Node *n = first;
    cout << '[';
    while (n)
    {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// Return count of values
int IntList::count() const
{
    int result = 0;
    Node *n = first;
    while (n)
    {
        ++result;
        n = n->next;
    }

    return result;
}
