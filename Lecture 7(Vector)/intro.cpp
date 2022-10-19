#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    for (int i = 1; i <= 5; i++)
    {
        cout << "Inserting: " << i << " : ";
        v.push_back(i);
        cout << " Size: " << v.size() << ", Capacity: " << v.capacity() << endl;
    }

    // Vector Initialisation

    // 1st way
    vector<int> v1({1, 2, 3, 4, 5});

    // 2nd way
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(int);

    vector<int> v2(a, a + n);

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }

    cout << endl;

    for (auto x : v2)
    {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}