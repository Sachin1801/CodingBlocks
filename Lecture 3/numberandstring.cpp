#include <iostream>
using namespace std;

int main()
{
    char ch;
    cin >> ch;

    cin.get();
    char arr[100];

    cin.getline(arr, 100);
    cout << ch << endl;
    cout << arr << endl;
    return 0;
}