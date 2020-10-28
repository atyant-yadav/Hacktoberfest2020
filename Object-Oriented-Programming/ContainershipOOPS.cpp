#include<iostream>
#include<iomanip>
#include<string>
#include <bits/stdc++.h>
using namespace std; 
class staff
{
    protected:
        
    public:
    	int code;
        char name[50];
        void set_info(char *n,int c)
            {
                strcpy(name,n);
                code=c;
           }
};

// This class holds two pieces of educational information , namely , highest qualification in general education and
// highest professional qualification.
class education
{
    protected:
        
    public:
    	char quali[50];
        char profquali[50];
        void set_qualification(char *q)
		{
			strcpy(quali,q);
		}
		void set_profqualification(char *p)
		{
			strcpy(profquali,p);
		}
};
 
 //container class teacher. This class has a object of class education and staff
class teacher
{
	education ed;
	staff st;
    protected:
    char sub[50],publication[50];
    public:
    	void get_data(char *n, int c)
    	{
    		st.set_info(n,c);
		}
		void get_qualification(char *p, char *q)
		{
			ed.set_qualification(p);
			ed.set_profqualification(q);
		}
        void set_details(char *s,char *p)
        {
            strcpy(sub,s);
			strcpy(publication,p);
        }
    	void show()
        {
            cout<<"Name : "<<st.name<<endl;
            cout<<"Code : "<<st.code<<endl;
            cout<<"Subject : "<<sub<<endl;
            cout<<"Publication : "<<publication<<endl;
            cout<<"Highest Educational Qualification : "<<ed.quali<<endl;
        	cout<<"Highest Professional Qualification : "<<ed.profquali<<endl;
            cout<<endl;
        }
};
 
  //container class officer. This class has a object of class education and staff
class officer
{
	staff st;
	education ed;
    char grade[50];
    public:
    void get_data(char *n, int c)
    	{
    		st.set_info(n,c);
		}
	void get_qualification(char *p, char *q)
		{
			ed.set_qualification(p);
			ed.set_profqualification(q);
		}
	void set_details(char *g)
        {
        	strcpy(grade,g);
        }
        
    void show()
        {
            cout<<"Name : "<<st.name<<endl;
            cout<<"Code : "<<st.code<<endl;
            cout<<"Highest Educational Qualification : "<<ed.quali<<endl;
            cout<<"Highest Professional Qualification : "<<ed.profquali<<endl;
            cout<<endl;
        }
};
 
class typist
{
	staff st;
    protected:
        
    public:
    	float speed;
        void set_speed(float s)
        {
        	speed=s;
        }
};
 //container class regular. This class has a object of class typist and staff
class regular
{
	staff st;
	typist tp;
      protected:
           float wage;
       public:
       	void get_data(char *n, int c)
    	{
    		st.set_info(n,c);
		}
		void get_speed(float f)
		{
			tp.set_speed(f);
		}
          void set_wage(float w)
		  {
		  	wage=w;
		  }
          void show()
          {
          	cout<<"Name : "<<st.name<<endl;
            cout<<"Code : "<<st.code<<endl;
            cout<<"Speed : "<<tp.speed<<endl;
            cout<<"Wage : "<<wage<<endl;
            cout<<endl;
          }
};
//container class casual. This class has a object of class typist and staff
class causal
{
	staff st;
	typist tp;
       float wage;
        public:
        void get_data(char *n, int c)
    	{
    		st.set_info(n,c);
		}
		void get_speed(float f)
		{
			tp.set_speed(f);
		}
         void set_wage(float w){wage=w;}
         void show()
          {
          	cout<<"Name : "<<st.name<<endl;
            cout<<"Code : "<<st.code<<endl;
            cout<<"Speed : "<<tp.speed<<endl;
            cout<<"Wage : "<<wage<<endl;
            cout<<endl;
          }
 
};
 
int main()
{
        teacher t;   
		t.get_data("Manish Raj",600);
		t.set_details("Our deeds with OOPS"," DTU");
		t.get_qualification("Masters Computer Science", "Software Developer");
		
 
        officer o;
        o.get_data("Suraj Kumar",170);
        o.set_details("First class");
        o.get_qualification("PHD Data Science", "CEO Cybersecurity.inc");
 
        regular rt;
        rt.get_data("Rahul",456);
		rt.get_speed(97.1);
		rt.set_wage(17000);
 
        causal ct;
        ct.get_data("Sanyam",231);
    	ct.get_speed(65.9);
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
