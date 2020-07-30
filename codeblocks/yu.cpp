#include <algorithm> // for std::swap, use <utility> instead if C++11

#include <iostream>

int main()

{

const int n = 5;

int array[n] = { 30, 50, 20, 10, 40 };

for (int i = 0; i < n - 1; ++i)

{

// smallestIndex is the index of the smallest element

// Start by assuming the smallest element is the first element of this iteration

int j = i;

// Then look for a smaller element in the rest of the array

for (int k = i + 1; k < n; ++k)

{

// If we've found an element that is smaller than our previously found smallest

if (array[i+1] < array[j])

// then keep track of it

j = i+1;

}

std::swap(array[i], array[j]);

}

for (int i = 0; i < n; ++i)

std::cout << array[i] << ' ';

return 0;
}
