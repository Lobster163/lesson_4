#pragma once
#include <cassert> // для assert()
#include <iostream>
class ArrayInt
{
private:
    int m_length;
    int* m_data;
    void insertBefore(int value, int index);
    void sort(int* arr, int first, int last);
public:
    ArrayInt() : m_length(0), m_data(nullptr) { }
    ArrayInt(int length);
    ArrayInt(int length, int value);
    ~ArrayInt();
    void erase();
    int size();
    int& operator[](int index);    
    void push_back(int value);
    void pop_back();
    void pop_front();
    void sort();
    void print();
};
