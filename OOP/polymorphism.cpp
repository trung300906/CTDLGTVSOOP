#if 0
// C++ Program to demonstrate
// the Virtual Function
#include <iostream>
using namespace std;

// Declaring a Base class
class base
{

public:
    // virtual function
    virtual void display()
    {
        cout << "Called virtual Base Class function"
             << "\n\n";
    }

    virtual void print()
    {
        cout << "Called base print function"
             << "\n\n";
    }
};

// Declaring a Child Class
class child : public base
{

public:
    void display() override
    {
        cout << "Called child Display Function"
             << "\n\n";
    }

    void print() override
    {
        cout << "Called child print Function"
             << "\n\n";
    }
};

class posterity : private child
{

public:
    
    using base::display;
    using base::print;
    using child::display;
    using child::print;
    
    /*using display;
    using print;*/
    void display()
    {
        cout << "from posterity function display" << "\n\n";
    }
    void print()
    {
        cout << "from posterity function print" << "\n\n";
    }
};
int main()
{
    // Create a reference of class base
    base *base_1;
    child child_1;
    base_1 = &child_1;
    // This will call the virtual function
    base_1->display();
    // This will call the non-virtual function
    (*base_1).print(); // same as base->print();
    /*
    foo->bar() is the same as (*foo).bar().

    The parenthesizes above are necessary because of the binding strength of the * and . operators.

    *foo.bar() wouldn't work because Dot (.) operator is evaluated first (see operator precedence)

    The Dot (.) operator can't be overloaded, arrow (->) operator can be overloaded.

    The Dot (.) operator can't be applied to pointers.
    */
    base base_2;
    (&base_2)->display(); // because -> same as *class_name so if have &base-> same as *&class_name. or class_name
    base_2.print();
}
#endif
#if 0
// C++ program for function overriding with data members
#include <bits/stdc++.h>
using namespace std;

//  base class declaration.
class Animal
{
public:
    string color = "Black";
};

// inheriting Animal class.
class Dog : public Animal
{
public:
    string color = "Grey";
};

// Driver code
int main(void)
{
    Animal d = Dog(); // accessing the field by reference
                      // variable which refers to derived
    cout << d.color << endl;
    Dog dd;
    cout << dd.color << endl;
}
#endif
#if 1
#include <iostream>
using namespace std;

class Demo
{
    int a, b;

public:
    Demo() // default constructor
    {
        cout << "Default Constructor" << endl;
    }
    Demo(int a, int b) : a(a), b(b) // parameterised constructor
    {
        cout << "parameterized constructor -values " << a << " " << b << endl;
    }
} instance;

int main()
{
    Demo obj(1, 2);
    return 0;
}

#endif