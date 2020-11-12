#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool compare(string a,string b)//comparator defination
{
    if(a.length()==b.length())
        return a<b;

    return a.length()>b.length();
}
int main()
{
    // string initiasation.
    string s0;
    string s1("hello");
    string s2 ="hello world";
    string s3(s2);
    string s4=s3;
    char a[]={"abcde"};
    string s5(a);


    cout<<s0<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;
    //ckecking if a string is empty or not
    if (s0.empty())
    {
        cout<<"s0 is empty"<<endl;
    }


    //appending
    s0.append("i love c++");
    cout<<s0<<endl;
    s0+= " and python";
    cout<<s0<<endl;


    //Remove;
    cout<<s0.length()<<endl;
    s0.clear();
    cout<<s0.length()<<endl;


    //compare two strings

    s0="Apple";
    s1="Mango";
    cout<<s1.compare(s0)<<endl;//1
    cout<<s0.compare(s1)<<endl;//-1

    //overloaded operator
    if(s1>s0){
        cout<<"Mango is greater than s0"<<endl;
    }

    cout<<s1[0]<<endl;

    //find substrings
    string s="i want to have apple juice";
    int idx =s.find("apple");
    cout<<"apple is at "<<idx<<endl;


    //remove word from a string.
    string word ="apple";
    int len = word.length();
    cout<<s<<endl;
    s.erase(idx,len+1);
    cout<<s<<endl;

    //iterate over all the character in the string
    for(int i=0;i<s1.length();i++){
        cout<<s1[i]<<":";
    }
    cout<<endl;
    //iterators
    for(auto it = s.begin();it!=s.end();it++)
    {
        cout<<(*it)<<",";
    }
    cout<<endl;

    //for each loop
    for(auto c:s){
        cout<<c<<",";
    }
    
    int N;
    cin>>N;//taking no. of strings
    cin.get();

    string S[100];
    for(int i=0;i<N;i++)
    {
        getline(cin,S[i]);
    }
    cout<<endl;
    //sorting
    sort(S,S+N);
    for(int i=0;i<N;i++)
    {
        cout<<S[i]<<endl;
    }
    cout<<endl;
    //comparator
    sort(S,S+N,compare);
    for(int i=0;i<N;i++)
    {
        cout<<N[i]<<endl;
    }
    return 0;

}
