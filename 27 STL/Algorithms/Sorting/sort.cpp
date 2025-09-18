#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec = {10, 45, 25, 66, 20, 44, 30, 56, 40, 50};
    sort(vec.begin(), vec.end()); // sort ascendingly
    cout << "Vector elements ascending: ";
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end(), greater<int>()); // sort descending
    cout << "Vector elements ascending: ";
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}