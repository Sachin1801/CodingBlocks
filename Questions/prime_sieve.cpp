#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    // O(sqprt(N))
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isPrime2(int n)
{
    // O(sqprt(N/2))
    if (n != 2 and n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Prime Sieve
void primesieve(int n)
{
    bool *a = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = true;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == true)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                a[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (a[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    // if (isPrime2(n))
    //     cout << "Prime Number" << endl;

    // else
    //     cout << "Not Prime" << endl;

    primesieve(n);
    return 0;
}