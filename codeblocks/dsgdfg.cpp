#include <iostream>
using namespace std;

void f(int *p);

template <class T>
void g(T*p);

void h (std ::nullptr_t p);

int main()
{
    f(nullptr);
    g(nullptr);
    h(nullptr);
}
