#include <iostream>
#include <cstring>
using namespace std;

//////////////////////////////////// BLUEPRINT ///////////////////////////////////
class Car
{
private:
    int price;

public:
    // Data Members
    char *name;
    int model;
    int seats;
    static int cnt;
    const int tyres;
    /// DEFAULT METHODS
    ///////////////////////// 1. DEFAULT CONSTRUCTOR ///////////////////////////////
    Car() : tyres(4)
    {
        cnt++;
        cout << "Inside Default constructor\n";
        name = NULL;
    }

    // setters
    void setprice(int p)
    {
        if (p > 0)
        {
            price = p;
        }
        else
            price = 10000;
    }

    // getters
    int getprice()
    {
        return price;
    }

    ///////////////////////// 1.@DEFAULT CONSTRUCTOR ///////////////////////////////

    //////////////////// 2. Parameterized CONSTRUCTOR //////////////////////////////
    Car(char *n, int p, int s, int m) : tyres(4)
    {
        cnt++;
        cout << "Inside Parameterized constructor\n";
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        price = p;
        model = m;
        seats = s;
    }
    //////////////////// 2.@Parameterized CONSTRUCTOR //////////////////////////////

    //////////////////// 3. COPY CONSTRUCTOR //////////////////////////////
    Car(Car &X) : tyres(4)
    {
        cnt++;
        cout << "Inside Copy constructor\n";
        // name = X.name;
        name = new char[strlen(X.name) + 1];
        strcpy(name, X.name);
        price = X.price;
        model = X.model;
        seats = X.seats;
    }
    //////////////////// 3. @COPY CONSTRUCTOR //////////////////////////////

    //////////////////// 4. COPY ASSIGNMENT Operator ///////////////////////
    // C = B;
    // void operator=(Car &X) {
    // 	cout << "Inside Copy Assignment Operator\n";
    // 	strcpy(name, X.name);
    // 	price = X.price;
    // 	model = X.model;
    // 	seats = X.seats;
    // }
    //////////////////// 4. @COPY ASSIGNMENT Operator //////////////////////

    //////////////////// 5. DESTRUCTOR /////////////////////////////////////
    // Tilde: ~
    ~Car()
    {
        cout << "Destroying: " << name << '\n';
        cnt--;
    }
    //////////////////// 5. @DESTRUCTOR ////////////////////////////////////

    // Functions
    void print()
    {
        cout << "Name  : " << name << endl;
        cout << "Price : " << price << endl;
        cout << "Model : " << model << endl;
        cout << "Seats : " << seats << endl;
        cout << "Tyres : " << tyres << endl
             << endl;
    }

    // SetName
    // Setters
    void setName(char *n)
    {
        if (name != NULL)
        {
            delete[] name;
        }

        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    /////////////////////////////// OPERATOR OVERLOADING ///////////////////////////////////
    void operator+=(Car X)
    {
        cout << cnt << endl;
        char *oldname = name;

        name = new char[strlen(name) + strlen(X.name) + 1];
        strcpy(name, oldname);
        strcat(name, X.name);

        price += X.price;
        model += X.model;
        seats += X.seats;

        delete[] oldname;
    }
    ////////////////////////////// @OPERATOR OVERLOADING ///////////////////////////////////
};
/////////////////////////////////// !BLUEPRINT ///////////////////////////////////

int Car::cnt = 0;

int main()
{

    Car A; // A is an object of class Car
    // A.name = "BMW";
    // A.name[0] = 'B';
    // A.name[1] = 'M';
    // A.name[2] = 'W';
    // A.name[3] = '\0';
    // A.name = new char[4];
    // strcpy(A.name, "BMW");

    A.setName("BMW");

    A.setprice(-3000); // function banaya hua hai upar kyuki price ab pvt member kardiya
    A.seats = 4;
    A.model = 2018;

    // Car B("Audi", 500, 2, 2020);
    Car B = A;

    Car C = B;
    // Car C(B);

    // Copy Assignment Operator(=)
    // C = B;

    Car D = C;
    D.name[0] = 'T';

    D += A;

    A.print();
    B.print();
    C.print();
    D.print();

    cout << Car::cnt << endl;

    return 0;
}