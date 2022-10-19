#include <iostream>
using namespace std;

char keys[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

string contacts[100] = {
    "VARUN", "KARTIK", "SACHIN", "AMAN", "YUVRAAJ", "LEO"};

void phone(char out[], char in[], int i, int j)
{
    // base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        string x(out);
        for (int i = 0; i < 6; i++)
        {
            if (x == contacts[i])
            {
                cout << x << endl;
            }
        }

        return;
    }

    // rec case
    int temp = in[i] - '0';

    for (int k = 0; keys[temp][k] != '\0'; k++)
    {
        out[j] = keys[temp][k];
        phone(out, in, i + 1, j + 1);
    }
}

int main()
{
    char in[100];
    cin >> in;
    char out[100];

    phone(out, in, 0, 0);
    return 0;
}