#include<iostream>
using namespace std;
string ones[] = {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen",
                    "sixteen","seventeen","eighteen","nineteen"};

string tens[] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

string numToWords(int number, string s){
    string result="";
    if(number>19){
        result += tens[number/10-2] + ones[number%10] + " "+s+" ";
    }
    else if(number<=19 && number>0){
        result += ones[number] + " " +s+" ";
    }
    return result;
}

string convert(int digit){
    string result="";
    result += numToWords((digit/1000000000), " arab");
    result += numToWords((digit%1000000000)/10000000, " crore");
    result += numToWords((digit%10000000)/100000, " lakhs");
    result += numToWords((digit%100000)/1000, " thousand");
    result += numToWords((digit%1000)/100, " hundred");
    result += numToWords((digit%100), "");
    return result;
}

int main(){
    int num;
    cin>>num;
    string res = convert(num);
    cout<<res<<endl;
    return 0;
}