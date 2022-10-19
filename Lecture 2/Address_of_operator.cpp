#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int a = 20;
    float f = 100.12;
    char ch = 'A';

    cout << &f << endl;  // this with print the address of the floating variable
    cout << arr << endl; // this with print the address of the first bucket of the array
    cout << &a << endl;  // this will print address of a
    cout << &ch << endl;
    return 0;
}