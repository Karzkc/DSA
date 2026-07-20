// oops.cpp
// Simple, easy-to-understand examples demonstrating basic OOP concepts in C++

#include <iostream>
#include <cstring>
using namespace std;

// 1) Class & Object, Access Specifiers
class Person
{
public: // public members accessible from outside
    string name;

protected: // protected accessible in derived classes
    int age;

private: // private accessible only within this class
    string secret;

public:
    void setSecret(const string &s) { secret = s; }
    string getSecret() const { return secret; }
};

// 2) Encapsulation: bundling data + methods; using access control to hide internal state
class Encapsulated
{
private:
    int value;

public:
    void setValue(int v)
    {
        if (v >= 0)
            value = v;
    }
    int getValue() const { return value; }
};

// 3) Constructor & 4) 'this' pointer
class Point
{
public:
    int x, y;
    // Constructor
    Point(int x, int y)
    {
        // 'this' pointer disambiguates members from parameters
        this->x = x;
        this->y = y;
    }
};

// 5) Copy Constructor
class Buffer
{
public:
    char *data;
    size_t size;
    // Constructor
    Buffer(const char *s)
    {
        size = strlen(s) + 1;
        data = new char[size];
        strcpy(data, s);
    }
    // Copy constructor (deep copy)
    Buffer(const Buffer &other)
    {
        size = other.size;
        data = new char[size];
        strcpy(data, other.data);
    }
    // 7) Destructor
    ~Buffer() { delete[] data; }
};

// 6) Shallow vs Deep copy demonstration: if we rely on default copy, it's shallow (bad for owning pointers)

// 8) Inheritance & 9) Modes of Inheritance (public/protected/private)
class Animal
{
public:
    void eat() { cout << "Animal eats\n"; }
};

// public inheritance: is-a
class Dog : public Animal
{
public:
    void bark() { cout << "Dog barks\n"; }
};

// 10) Types of Inheritance: single, hierarchical, multilevel (examples kept small)
class A
{
public:
    void fa() { cout << "A\n"; }
};
class B : public A
{
}; // single
class C : public A
{
}; // hierarchical (A -> B and A -> C)
class D : public B
{
}; // multilevel (A -> B -> D)

// 11) Polymorphism: ability to treat objects of different classes through a common interface
// 12) Function Overloading (compile-time polymorphism)
class Math
{
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};

// 13) Function Overriding & 14) Virtual Function (runtime polymorphism)
class Base
{
public:
    virtual void show() { cout << "Base show\n"; }
};
class Derived : public Base
{
public:
    void show() override { cout << "Derived show\n"; }
};

// 15) Abstraction & 16) Abstract Class: providing interface without implementation
class Shape
{
public:
    virtual double area() const = 0; // pure virtual -> abstract
    virtual ~Shape() {}
};
class Rectangle : public Shape
{
    double w, h;

public:
    Rectangle(double w, double h) : w(w), h(h) {}
    double area() const override { return w * h; }
};

// 17) Static keyword: static member shared among all instances
class Counter
{
public:
    static int count;
    Counter() { ++count; }
};
int Counter::count = 0;

int main()
{
    // Class & Object
    Person p;
    p.name = "Alice";
    p.setSecret("likes cats");
    cout << "Person: " << p.name << ", secret: " << p.getSecret() << '\n';

    // Encapsulation
    Encapsulated e;
    e.setValue(10);
    cout << "Encapsulated value: " << e.getValue() << '\n';

    // Constructor and this
    Point pt(3, 4);
    cout << "Point: (" << pt.x << "," << pt.y << ")\n";

    // Copy constructor and deep copy
    Buffer b1("hello");
    Buffer b2 = b1; // uses copy constructor (deep copy)
    cout << "Buffer copy data: " << b2.data << '\n';

    // Inheritance
    Dog d;
    d.eat();
    d.bark();

    // Polymorphism: overloading
    Math m;
    cout << "add int: " << m.add(1, 2) << " add double: " << m.add(1.5, 2.5) << '\n';

    // Runtime polymorphism
    Base *b = new Derived();
    b->show(); // calls Derived::show because show is virtual
    delete b;

    // Abstraction
    Shape *r = new Rectangle(3, 4);
    cout << "Rectangle area: " << r->area() << '\n';
    delete r;

    // Static
    Counter c1, c2;
    cout << "Counter::count = " << Counter::count << '\n';

    return 0;
}
