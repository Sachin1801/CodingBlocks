#include <iostream>
using namespace std;

class Vector
{
public:
    int *a;
    int cap;
    int cs;

    Vector(int s = 1)
    {
        cs = 0;
        a = new int[s];
        cap = s;
    }

    void push_back(int data)
    {
        if (cs == cap)
        {
            int *olda = a;
            a = new int[2 * cap];
            cap = 2 * cap;
            for (int i = 0; i < cap / 2; i++)
            {
                a[i] = olda[i];
            }
            delete[] olda;
        }
        a[cs++] = data;
    }

    void pop_back()
    {
        if (cs > 0)
            cs--;
    }

    bool empty()
    {
        return cs == 0;
    }

    int size()
    {
        return cs;
    }

    int capacity()
    {
        return cap;
    }

    void print()
    {
        for (int i = 0; i < cs; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    int operator[](int idx)
    {
        return a[idx];
    }
};

int main()
{
    Vector v;

    if (v.empty())
    {
        cout << "Vector is empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "size is: " << v.size() << '\n'
         << "Capacity is: " << v.capacity() << endl;

    v.print();
    if (v.empty())
    {
        cout << "Vector is empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }

    v.pop_back();

    cout << "size is: " << v.size() << '\n'
         << "Capacity is: " << v.capacity() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}