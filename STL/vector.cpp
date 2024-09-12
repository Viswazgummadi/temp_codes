#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);
    vec.emplace_back(5);
    vec.insert(vec.end(), {1, 2, 3, 3, 2, 1});
    vec.insert(vec.begin(), {1, 2, 3, 3, 2, 1});

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " "; // Output each element of the vector
    }
    cout << endl;

    cout << vec[0] << endl;
    cout << vec.at(1) << endl;

    vec.pop_back();

    vec.erase(vec.begin() + 2); // Removes the third element

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " "; // Output each element of the vector
    }
    cout << endl;
    

    vec.clear();

    cout << vec.size() << endl;
    cout << vec.capacity() << endl;


}