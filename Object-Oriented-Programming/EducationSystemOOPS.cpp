#include<iostream>
#include<iomanip>
#include<string>
#include <bits/stdc++.h>
using namespace std; 
class staff
{
    protected:
        int code;
        char name[50];
    public:
        void set_info(char *n,int c)
            {
                strcpy(name,n);
                code=c;
           }
};

// This class holds two pieces of educational information , namely , highest qualification in general education and
// highest professional qualification.
class education:public staff
{
    protected:
        char quali[50];
        char profquali[50];
    public:
        void set_qualification(char *q)
		{
			strcpy(quali,q);
		}
		void set_profqualification(char *p)
		{
			strcpy(profquali,p);
		}
};
 
class teacher : public education
{
    protected:
    char sub[50],publication[50];
    public:
        void set_details(char *s,char *p)
        {
            strcpy(sub,s);
			strcpy(publication,p);
        }
    	void show()
        {
            cout<<"Name : "<<name<<endl;
            cout<<"Code : "<<code<<endl;
            cout<<"Subject : "<<sub<<endl;
            cout<<"Publication : "<<publication<<endl;
            cout<<"Highest Educational Qualification : "<<quali<<endl;
            cout<<"Highest Professional Qualification : "<<profquali<<endl;
            cout<<endl;
        }
};
 
class officer:public education
{
    char grade[50];
    public:
	void set_details(char *g)
        {
        	strcpy(grade,g);
        }
        
    void show()
        {
            cout<<"Name : "<<name<<endl;
            cout<<"Code : "<<code<<endl;
            cout<<"Highest Educational Qualification : "<<quali<<endl;
            cout<<"Highest Professional Qualification : "<<profquali<<endl;
            cout<<endl;
        }
};
 
class typist: public staff
{
    protected:
        float speed;
    public:
        void set_speed(float s)
        {
        	speed=s;
        }
};
class regular:public typist
{
      protected:
           float wage;
       public:
          void set_wage(float w)
		  {
		  	wage=w;
		  }
          void show()
          {
          	cout<<"Name : "<<name<<endl;
            cout<<"Code : "<<code<<endl;
            cout<<"Speed : "<<speed<<endl;
            cout<<"Wage : "<<wage<<endl;
            cout<<endl;
          }
};
class causal:public typist
{
       float wage;
        public:
         void set_wage(float w){wage=w;}
         void show()
          {
          	cout<<"Name : "<<name<<endl;
            cout<<"Code : "<<code<<endl;
            cout<<"Speed : "<<speed<<endl;
            cout<<"Wage : "<<wage<<endl;
            cout<<endl;
          }
 
};
 
int main()
{
        teacher t;   
		t.set_info("Manish Raj",600);
		t.set_details("Our deeds with OOPS"," DTU");
		t.set_qualification("Masters Computer Science");
		t.set_profqualification("Software Developer");
 
        officer o;
        o.set_info("Suraj Kumar",170);
        o.set_details("First class");
    	o.set_qualification("PHD Data Science");
    	o.set_profqualification("CEO Cybersecurity.inc");
 
        regular rt;
        rt.set_info("Rahul",456);
		rt.set_speed(97.1);
		rt.set_wage(17000);
 
        causal ct;
        ct.set_info("Sanyam",231);
    	ct.set_speed(65.9);
        ct.set_wage(11000);
 
        cout<<"Details :: Teacher: "<<endl;
        t.show();
 
        cout<<"Details :: Officer:"<<endl;
        o.show();
 
        cout<<"Details :: Regular Typist:"<<endl;
        rt.show();
        cout<<"Details :: Casual Typist:"<<endl;
        ct.show();
 
       return 0;
}
