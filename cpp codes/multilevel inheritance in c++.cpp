#include<iostream>
using namespace std;
class student{    //creating a student class
protected:
    int rollno; // declaring protected member
public:
    void set_rollnumber(int r)  //creating public members
    {
        rollno = r;
    }
    void get_rollnumber(void)
    {
        cout<<"Your roll number is"<<rollno<<endl;
    }
};
class exam:public student{   //publicaly inheriting exam class from student class
protected:   // declaring protected members
    int maths;
    int physics;
public:   // creating public members of exam class
    void set_marks(float m,float p)
    {
        maths = m;
        physics = p;
    }
    void get_marks(void)
    {
        cout<<"Your marks in maths are "<<maths<<endl;
        cout<<"Your marks in physics are "<<physics<<endl;
    }
};
class result:public exam{   // declaring result class inheriting from exam class
public:
    void display_results()  // creating public members
    {
        cout<<"Your percentage is "<<(maths + physics)/2<<"%"<<endl;
    }
};
int main()
{
    result res; //creating object of result class
    res.set_rollnumber(200);  //accessing public member of the inherited class
    res.get_rollnumber();
    res.set_marks(100.0,99.2);
    res.get_marks();
    res.display_results(); // accessing member of result class
    return 0;
}
