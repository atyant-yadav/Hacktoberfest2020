using namespace std; 
  
int main() 
{ 
    vector<int> v; 
  
    for (int i = 1; i <= 5; i++) 
        v.push_back(i); 
  
    cout << "Output of begin and end: "; 
    for (auto itr = v.begin(); itr != v.end(); itr++) 
        cout << *itr << " "; 
  
    cout << "\nOutput of cbegin and cend: "; 
    for (auto itr = v.cbegin(); itr != v.cend(); itr++) 
        cout << *itr << " "; 
  
    cout << "\nOutput of rbegin and rend: "; 
    for (auto i = v.rbegin(); i != v.rend(); i++) 
        cout << *ir << " "; 
  
    cout << "\nOutput of crbegin and crend : "; 
    for (auto i = v.crbegin(); i != v.crend(); i++) 
        cout << *ir << " "; 
  return 0;
    }
