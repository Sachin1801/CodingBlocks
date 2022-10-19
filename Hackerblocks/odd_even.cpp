#include <iostream>
using namespace std;

void print(int n, int i)
{
    //base case 


    //rec case 
    if(i%2!=0)
    {
        cout<<i<<endl;
        print(n,i-2);
    }
    if(i%2==0)
    {
        int preserve = i;
        print(n,i-1);
    }
}

int main()
{
    int n;
    cin >> n;
    in = n;
    if (n > 1)
    {
        print(n,n);
    }
    else
    {
        cout << 1 << endl;
    }
    return 0;
}