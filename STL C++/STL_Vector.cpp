// Vector in STL
// Author: REET

/*
Array doesn't provide dynamic memory
allocation by default.
Also the size is mentioned first and can
not be changed later.
Vector comes at ease in this case because
in vector it increases its size as per
the requirement.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Vector[int data type]
    cout << "## Vector[int data type]" << endl;
    vector<int> v;     // {}
    v.push_back(1);    // {1}
    v.emplace_back(2); // {1, 2}
    cout << "First element of the vector is: " << v[0] << endl;
    cout << "Second element of the vector is: " << v[1] << endl;
    cout << endl;

    // Vector[pair(int, int) data type]
    cout << "## Vector[pair(int, int) data type]" << endl;
    vector<pair<int, int>> vp;
    vp.push_back({1, 2});
    vp.emplace_back(3, 4);
    // Don't need to use curly braces(only applicable if it is not pair of pair)
    cout << "The first element of the pair at Index [0] of vector is: " << vp[0].first << endl;
    cout << "The second element of the pair at Index [0] of vector is: " << vp[0].second << endl;
    cout << "The first element of the pair at Index [1] of vector is: " << vp[1].first << endl;
    cout << "The second element of the pair at Index [1] of vector is: " << vp[1].second << endl;
    cout << endl;

    // Vector of fixed size and same element
    vector<int> vf(5, 100); // {100, 100, 100, 100, 100}
    vector<int> vz(5);      // {0, 0, 0, 0, 0}
    // Generally initialized with zero but can take
    // garbage value depending upon the compiler
    vector<int> v1(5, 20); // {20, 20, 20, 20, 20}
    vector<int> v2(v1);    // {20, 20, 20, 20, 20}
    // Copies the element of v1 in v2

    // Iterator
    cout << "## Iterator" << endl;
    vector<int> vi = {10, 20, 30, 40, 50};
    vector<int>::iterator it1 = vi.begin();
    // .begin() points at first element{10}
    // vector<int>::iterator it2 = vi.end();
    // .end() points after the address of last element{NULL}
    // vector<int>::iterator it3 = vi.rbegin();
    // .rbegin() points at last element{50}
    // vector<int>::iterator it4 = vi.rend();
    // .rend() points before first element{NULL}
    // vector<int>::iterator it5 = vi.cbegin();
    // .cbegin() points at first element{10} iterator can't be changed later
    // vector<int>::iterator it6 = vi.cend();
    // .cbegin() points after the address of last element{NULL} and iterator can't be changed later.

    it1++;
    cout << "Second element of vector vi is: " << *(it1) << endl;
    it1 = it1 + 2;
    cout << "Fourth element of vector vi is: " << *(it1) << endl;
    cout << "Last element of vector vi is: " << vi.back() << endl;
    cout << endl;

    // Ways to print the element
    cout << "## Ways to print the element" << endl;
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    for (auto it = vi.begin(); it != vi.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    for (auto it : vi)
    {
        cout << it << " ";
    }
    cout << endl;
    for (int i = 0; i < vi.size(); i++)
    {
        cout << vi[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < vi.size(); i++)
    {
        cout << vi.at(i) << " ";
    }
    cout << endl;
    cout << endl;

    // erase() function
    cout << "## erase() function" << endl;
    // vi = {10, 20, 30, 40, 50}
    vi.erase(vi.begin() + 1);
    for (auto it : vi)
    {
        cout << it << " ";
    }
    cout << "\n";
    // To erase a range
    // vi is now = {10, 30, 40, 50}
    vi.erase(vi.begin(), vi.begin() + 2);
    // Last excluded
    // vi is now = {40, 50}
    for (auto it : vi)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    // Insert Function
    cout << "## Insert Function" << endl;
    vector<int> vin(2, 100);            // {100, 100}
    vin.insert(vin.begin(), 400);       // {400, 100, 100}
    vin.insert(vin.begin() + 1, 2, 75); // {400, 75, 75, 100, 100}
    vector<int> copy(2, 50);
    vin.insert(vin.begin(), copy.begin(), copy.end());
    // {50, 50, 400, 75, 75, 100, 100}
    for (auto it : vin)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    // size(), pop_back(), swap(), clear() functions
    cout << "size(), pop_back(), swap(), clear() functions" << endl;
    vin.pop_back();
    // {50, 50, 400, 75, 75, 100}
    cout << "vin: ";
    for (auto it : vin)
    {
        cout << it << " ";
    }
    cout << endl;
    vector<int> vin2 = {45, 646, 545, 3, 434, 4};
    cout << "vin2: ";
    for (auto it : vin2)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "Time to swap" << endl;
    cout << "Now vin: ";
    vin2.swap(vin);
    for (auto it : vin)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "Now vin2: ";
    for (auto it : vin)
    {
        cout << it << " ";
    }
    cout << endl;
    vin.clear();
    // Clears the entire vector
    cout << "1 for true 0 for false" << endl;
    cout << "Is vector vin empty?" << endl
         << vin.empty() << endl;
    cout << "Is vector vin2 empty?" << endl
         << vin2.empty() << endl;
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
## Vector[int data type]
First element of the vector is: 1
Second element of the vector is: 2
## Vector[pair(int, int) data type]
The first element of the pair at Index [0] of vector is: 1
The second element of the pair at Index [0] of vector is: 2
The first element of the pair at Index [1] of vector is: 3
The second element of the pair at Index [1] of vector is: 4
## Iterator
Second element of vector vi is: 20
Fourth element of vector vi is: 40
Last element of vector vi is: 50
## Ways to print the element
10 20 30 40 50 
10 20 30 40 50 
10 20 30 40 50 
10 20 30 40 50 
10 20 30 40 50 
## erase() function
10 30 40 50 
40 50 
## Insert Function
50 50 400 75 75 100 100 
size(), pop_back(), swap(), clear() functions
vin: 50 50 400 75 75 100 
vin2: 45 646 545 3 434 4 
Time to swap
Now vin: 45 646 545 3 434 4 
Now vin2: 45 646 545 3 434 4 
1 for true 0 for false
Is vector vin empty?
1
Is vector vin2 empty?
0
*/