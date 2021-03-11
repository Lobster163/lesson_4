#include "include/punkt_1.h"

ArrayInt::ArrayInt(int length):m_length(length)
{
    assert(length >= 0);

    if (length > 0)
        m_data = new int[length];
    else
        m_data = nullptr;
}

ArrayInt::ArrayInt(int length, int value) :m_length(length)
{
    assert(length > 0);
    m_data = new int[length];

    for (int i = 0; i < length; ++i)
        m_data[i] = value;
}

ArrayInt::~ArrayInt(){ delete[] m_data; }

void ArrayInt::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int ArrayInt::size() { return m_length; }

int& ArrayInt::operator[](int index)
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

void ArrayInt::insertBefore(int value, int index)
{
    assert(index >= 0 && index <= m_length);

    int* data = new int[m_length + 1];

    for (int before = 0; before < index; ++before)
        data[before] = m_data[before];

    data[index] = value;

    for (int after = index; after < m_length; ++after)
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++m_length;
}

void ArrayInt::push_back(int value) { insertBefore(value, m_length); }

void ArrayInt::pop_back()
{
    int newSize = m_length - 1;
    int* data = new int[newSize];
    for (int before = 0; before < newSize; ++before)
        data[before] = m_data[before];
    delete[] m_data;
    m_data = data;
    --m_length;
}

void ArrayInt::pop_front()
{
    int newSize = m_length - 1;
    int* data = new int[newSize];
    for (int before = 1; before < m_length; ++before)
        data[before - 1] = m_data[before];
    delete[] m_data;
    m_data = data;
    --m_length;
}

int median(int* arr, int first, int last) {
    int result;
    int min, max;
    int middle = arr[(first + last) / 2];
    if (arr[first] > arr[middle]) {
        min = arr[middle];
        max = arr[first];
    }
    else {
        min = arr[first];
        max = arr[middle];
    }
    if (min > arr[last]) result = min;
    else if (arr[last] > max) result = max;
    else result = arr[last];

    if (result == arr[first]) return first;
    else if (result == arr[middle]) return middle;
    else return last;
}

void swapInt(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sortInserts(int* array, int first, int last) {
    int temp, pos, i;
    for (i = first + 1; i <= last; i++) {
        temp = array[i];
        pos = i - 1;
        while (pos >= first && array[pos] > temp) {
            array[pos + 1] = array[pos];
            pos = pos - 1;
        }
        array[pos + 1] = temp;
    }
}

int compare(const void* x1, const void* x2)
{
    return (*(int*)x1 - *(int*)x2);
}

void ArrayInt::sort()
{
    std::qsort(m_data, m_length,sizeof(int), compare); //30+sec
    //std::sort(&m_data[0], &m_data[m_length]); //~2min
    //sort(m_data, 0, m_length - 1);    //<1min
}

void ArrayInt::sort(int* arr, int first, int last)
{
    if (last - first > 10) {
        int med = median(arr, first, last);
        swapInt(&arr[med], &arr[(first + last) / 2]);
        int i = first;
        int j = last;
        int x = arr[(first + last) / 2];
        do {
            while (arr[i] < x) i++;
            while (arr[j] > x) j--;
            if (i <= j) {
                swapInt(&arr[i], &arr[j]);
                i++;
                j--;
            }
        } while (i <= j);

        sort(arr, i, last);
        sort(arr, first, j);
    }
    else {
        sortInserts(arr, first, last);
        return;
    }
}

void ArrayInt::print()
{
    for (int i = 0; i < m_length; ++i)
        std::cout << m_data[i] << " ";
    std::cout << std::endl;
}