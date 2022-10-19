#include <iostream>
using namespace std;

void tower_of_hanoi(int n, char src, char help, char dest)
{
    // base case
    if (n == 0)
        return;
    // rec case
    tower_of_hanoi(n - 1, src, dest, help); //
    cout << "Taking disk " << n << " from " << src << " to " << dest << endl;
    tower_of_hanoi(n - 1, help, src, dest);
}

int main()
{
    int n;
    cin >> n;

    tower_of_hanoi(n, 'A', 'B', 'C');

    return 0;
}