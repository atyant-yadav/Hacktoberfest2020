#include <iostream>
#include <queue>
 
using namespace std;
 
void printVec(vect <int> vect)
{
    vector <int> vec = vect;
    for(auto i = vec.begin(); i != vec.end(); i++)
    {
      cout<< i <<" ";
    }
    cout << '\n';
}
 
int main()
{
    vector <int> vec;
    vec.push_back(100);
    vec.push_back(110);
    vec.push_back(120);
 
    cout << "The queue contents are : ";
    printVec(vec);
 
    cout << "\nvec.size() : " << vec.size();
    cout << "\nvec.begin() : " << vec.begin();
    cout << "\nvec.end() : " << vec.end();
 
    cout << "\nvec.empty() : ";
    cout<<vec.empty()<<endl;
 
    //print vector using iterators
    count<<"Using iterators : ";
    for(auto i = vec.begin(); i != vec.end(); i++)
    {
      cout<< i <<" ";
    }
    return 0;
}
