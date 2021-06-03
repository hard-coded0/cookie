#ifndef NEWVAR_H
#define NEWVAR_H
#include <iostream>
#include <stdlib.h>

using namespace std;

// This creates a number and returns its memory address
size_t create_new_num(float val) {
    // Create the number in memory and save its address to pointer
    float *p = &val;

    // Save the address the pointer points to as a size_t
    size_t addr = (size_t)p;
    
    // Return the address
    return addr;
}

// This can retrieve a numbers value by using its mem address
float get_num(size_t addr) {
    // Initialize the number pointer and point it to the provided address
    float *pointer;
    pointer = (float *)addr;

    // Return the value of the number the pointer goes to
    return *pointer;
}

// This creates a new string
size_t create_new_str(string val) {
    // Initialize the pointer and point it the value of the val var
    string *p = &val;

    // Get the address of that pointer as a size_t
    size_t addr = (size_t)p;

    // Return the address of that pointer
    return addr;
}

// This can retrieve the value of a string
string get_str(size_t addr) {
    // This initializes the pointer and points it to the provided address
    string *p;
    p = (string *)addr;

    // This returns the value of the string
    return *p;
}

#endif