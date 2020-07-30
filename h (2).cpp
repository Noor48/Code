#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
int main()
{
const int length = 5;
int array[length] = { 30, 50, 20, 10, 40 };
for (int startIndex = 0; startIndex < length - 1; ++startIndex)
{
// smallestIndex is the index of the smallest element
// Start by assuming the smallest element is the first element of this iteration
int smallestIndex = startIndex;
// Then look for a smaller element in the rest of the array
for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
{
// If we've found an element that is smaller than our previously found smallest
if (array[currentIndex] < array[smallestIndex])
// then keep track of it
smallestIndex = currentIndex;
}
std::swap(array[startIndex], array[smallestIndex]);
}
for (int index = 0; index < length; ++index)
std::cout << array[index] << ' ';
return 0;
}
