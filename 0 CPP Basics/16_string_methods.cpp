#include <iostream>

int main()
{
    using namespace std;
    // length
    string name = "kartik";
    cout << name.length() << endl;

    // empty return if 0 char
    cout << name.empty() << endl;

    // clear
    name.clear();
    cout << name << endl;

    // append
    name.append("kk");
    cout << name << endl;

    // at - return the char at index
    cout << name.at(0) << endl;

    // insert
    name.insert(2, "is boss");
    cout << name << endl;

    // find
    std::cout << name.find("kk") << std::endl;

    // erase
    name.erase(0, 2);
    cout << name << endl;
    
    return 0;
}