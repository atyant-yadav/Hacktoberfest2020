/*This program calculates your body mass index and informs you whether you are obese,overweight,normal or underweight.
For accurate results,please enter your mass(kg) and height(m), respectively ,each on a different line.*/

#include <iostream >
using namespace std;

int main(){
   long double mass ;
   long double height ;
   long double bmi ;

   cin >>mass ;
   cin>>height ;

   bmi =mass /(height *height ) ;

   if (bmi <=25){
       if (bmi >=18.5){
          cout <<"Your Body Mass Index is:" <<bmi <<endl ;
          cout <<"You are normal."<<endl ;
       }
       else {
          cout <<"Your Body Mass Index is:" <<bmi<<endl ;
          cout <<"You are underweight ."<<endl ;
       }
   }

   else {
      if (bmi <=30) {
         cout <<"Your Body Mass Index is:" <<bmi<<endl ;
         cout <<"You are overweight."<<endl ;
      }
      else {
         cout <<"Your Body Mass Index is:"<<bmi<<endl ;
         cout <<"You are obese ." <<endl ;
      }
   }
   return 0;
}
