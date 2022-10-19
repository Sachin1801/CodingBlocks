#include <iostream>
using namespace std;

void print_subsequences(char in[], char out[], int i, int j)
{
    // base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        if (out[0] == '\0')
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << out << endl;
        }
        return;
    }

    // rec case
    // include the char
    out[j] = in[i];
    print_subsequences(in, out, i + 1, j + 1);

    // exclude the current char
    print_subsequences(in, out, i + 1, j);
}

int main()
{
    char a[100];
    cin >> a;
    char out[100];
    print_subsequences(a, out, 0, 0);

    return 0;
}