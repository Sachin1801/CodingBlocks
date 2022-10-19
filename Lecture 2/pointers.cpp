#include <iostream>
using namespace std;

int main()
{
    int a = 100;
    int *ap = &a;
    char ch = 'A';
    char *chptr = &ch;
    float f = 1.11;
    float *fptr = &f;

    cout << ap << &a << endl;

    cout << chptr << " " << &ch << endl;

    cout << &f << " " << fptr << endl;
    return 0;
}