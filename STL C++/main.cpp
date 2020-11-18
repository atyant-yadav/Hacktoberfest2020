#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ofstream myfile;
double PortableWithVAT(int opt, double Pwater); //function to calculate the charge of portable water with VAT.
double PortableWOutVAT(double Pwater); //function to calculate the charge of portable water without VAT.
double WasteWithVAT(int opt, double Wwater); //function to calculate the charge of waste water with VAT.
double WasteWOutVAT(double Wwater); //function to calculate the charge of waste water without VAT.

int main()
{
    int redo=1; //flag for redoing the process
    string name;
    string plotnumber;
    string location;
    int option; //value of the option

    while (redo==1) //Loop for redoing bills if needed
    {
    double PortableWaterAmount=0,WasteWaterAmount=0,PortableCharge=0,WasteCharge=0; //initiatizing the variables
    double PortableWOVAT=0, WasteWOVAT=0, VATforWaste=0, VATforPortable=0;
    cout<<"What is the name of owner? (Name of owner or name of business.)"<<endl; //prompt to ask for name
    getline(cin,name);
    cout<<"Enter plot number."<<endl;  //prompt to ask for plot number
    getline(cin,plotnumber);
    cout<<"Enter location."<<endl; //prompt to ask for location
    getline(cin,location);
    cout<<"Please choose one of the following. (Choose a number for your option)"<<endl; //propmt to ask for which option
    cout<<"1. Domestic User"<<endl;
    cout<<"2. Domestic User (Not Connected to Sewage System)"<<endl;
    cout<<"3. Commercial/Industrial"<<endl;
    cin>>option;
    while ((option<1)||(option>3)) //ensures the option is a number which is 1, 2 or 3
    {
        cout<<"Please enter a number from 1 to 3."<<endl<<endl;
        cout<<"Please choose one of the following. (Choose a number for your option)"<<endl;
        cout<<"1. Domestic User"<<endl;
        cout<<"2. Domestic User (Not Connected to Sewage System)"<<endl;
        cout<<"3. Commercial/Industrial"<<endl;
        cin>>option;
    }
    cout<<"Enter amount of portable water used in kilo-liters.\n";  //prompt to ask the amount of portable water used
        cin>>PortableWaterAmount;
        while (PortableWaterAmount<0)
            {
             cout<<"Please enter a positive value"<<endl; //ensures the value entered is positive
             cin>>PortableWaterAmount;
        }
if (option!=2)  //amount of waste water not available for option 2
{
    cout<<"Enter amount of waste water used in kilo-liters.\n"; //prompt to ask the amount of waste water used
        cin>>WasteWaterAmount;
         while (WasteWaterAmount<0)
        {
            cout<<"Please enter a positve value"<<endl; //ensures the value entered is positive
            cin>>WasteWaterAmount;
        }
}
    switch (option) //switch for option
    {
        case 1: //option 1 for Domestic (Connected to the sewage system)
        {
            PortableCharge= PortableWithVAT(option,PortableWaterAmount); //Calculating the charge for portable water with VAT included using the function PortableWithVAT
            PortableWOVAT=PortableWOutVAT(PortableWaterAmount); //Calculating the charge for portable water with VAT included using the function PortableWOutVAT
            WasteCharge=WasteWithVAT(option, WasteWaterAmount); //Calculating the charge for waste water with VAT included using the function WasteWithVAT
            WasteWOVAT=WasteWOutVAT(WasteWaterAmount); //Calculating the charge for waste water with VAT included using the function WasteWOutVAT
            break;
        }
        case 2:
        {
           PortableCharge= PortableWithVAT(option,PortableWaterAmount); //Calculating the charge for portable water with VAT included using the function PortableWithVAT
            PortableWOVAT=PortableWOutVAT(PortableWaterAmount); //Calculating the charge for portable water with VAT included using the function PortableWOutVAT
            break;
        }
        case 3:
        {
           PortableCharge= PortableWithVAT(option,PortableWaterAmount); //Calculating the charge for portable water with VAT included using the function PortableWithVAT
            PortableWOVAT=PortableWOutVAT(PortableWaterAmount); //Calculating the charge for portable water with VAT included using the function PortableWOutVAT
            WasteCharge=WasteWithVAT(option, WasteWaterAmount); //Calculating the charge for waste water with VAT included using the function WasteWithVAT
            WasteWOVAT=WasteWOutVAT(WasteWaterAmount); //Calculating the charge for waste water with VAT included using the function WasteWOutVAT
            break;
        }
    }
VATforWaste= WasteCharge-WasteWOVAT; //The VAT calculated by finding the difference between the Charge with VAT and the charge without VAT.
VATforPortable=PortableCharge-PortableWOVAT; //ditto

    cout<<"The amount of portable water used in kl is: "<<PortableWaterAmount<<endl;           //The output in the console
    cout<<"The total cost of the portable water is: P"<<PortableWOVAT<<endl;
    cout<<"The VAT for the portable water is: P"<<VATforPortable<<endl;
    cout<<"The amount of waste water used in kl is: "<<WasteWaterAmount<<endl;
    cout<<"The total cost of the waste water is: P"<<WasteWOVAT<<endl;
    cout<<"The VAT for the waste water is: P"<<VATforWaste<<endl;
    cout <<"Total VAT: P"<<(VATforPortable+VATforWaste)<<endl;
    cout <<"Total Charge: P"<<(PortableCharge+WasteCharge)<<endl;
    myfile.open("Water Bill For Consumer.txt");
    myfile <<"*************Water Department of Botswana*************"<<endl;                //the output in a file "WaterBill For Consumer.txt"
    myfile <<"Name of Consumer: "<<name<<endl;
    myfile <<"Plot number: "<<plotnumber<<endl;
    myfile <<"Location: "<<location<<endl;
    myfile <<"Portable Water Used in kl: "<<PortableWaterAmount<<endl;
    myfile <<"Waste Water Used in kl: "<<WasteWaterAmount<<endl;
    myfile <<"Portable Water Cost: P"<<PortableWOVAT<<endl;
    myfile <<"Waste Water Cost: P"<<WasteWOVAT<<endl;
    myfile <<"VAT for Portable Water: P"<<VATforPortable<<endl;
    myfile <<"VAT for Waste Water: P"<<VATforWaste<<endl;
    myfile <<"Total VAT: P"<<(VATforPortable+VATforWaste)<<endl;
    myfile <<"Total Charge: P"<<(PortableCharge+WasteCharge)<<endl;
    myfile <<"******************************************************"<<endl;
    myfile.close();
    cout<<endl<<"Do you wish to write another bill? (Type in 1 for Yes and anykey for No)"<<endl; //prompt to ask if the user would like to make another bill
    cin>>redo;
        }
}

//The method of calculating the charge (With or without VAT) is based on blocks. eg. The block ranging from 0-5kl will be charged a certain amout, whereas from
//5-15kl again will be charged another certain amount, and so on, up to the amount of water used.

double PortableWOutVAT(double Pwater) //function to calculate the charge for Portable water without VAT
{
    double Charge=0; //intializing charge
    const double XVATportable[5]={3.50,10.40,18.20,28.00,35.00}; //Values of XVATportable initialized and taken from the table
    if (Pwater>40)
    {
       Charge=((Pwater-40)*XVATportable[4])+(5*XVATportable[0])+(10*XVATportable[1])+(10*XVATportable[2])+(15*XVATportable[3]); //The amount water minus the lower boundary
        return Charge;                                                                                                          //then multiplied by the value associated
    }                                                                                                                           //with the range, and then added with the
        else if (Pwater>25)//ditto                                                                                              //remaining blocks with
        {                                                                                                                       //their respective charges.
            Charge=((Pwater-25)*XVATportable[3])+(5*XVATportable[0])+(10*XVATportable[1])+(10*XVATportable[2]);
            return Charge;
        }

    else if (Pwater>15)//ditto
        {
        Charge=((Pwater-15)*XVATportable[2])+(5*XVATportable[0])+(10*XVATportable[1]);
        return Charge;
        }

    else if (Pwater>5)//ditto
        {
        Charge=((Pwater-5)*XVATportable[1])+(5*XVATportable[0]);
        return Charge;
        }
    else
    return (Pwater*XVATportable[0]) ;//if the amount of water is less than 5kl, then the amount of water is directly mutliplied with the charge for range 0-5kl
}

double PortableWithVAT(int opt, double Pwater) //function to calculate the charge for Portable water with VAT
{
    const double IVATportable[5]={3.92,11.65,20.38,31.36,39.20};//Values of IVATportable initialized and taken from the table
    double Charge=0;//initializing Charge
   if (opt==3) //Paying VAT for first 5kL because they are Commercial/Industrial
   {
       if (Pwater>40)//same idea as function above
    {
       Charge=((Pwater-40)*IVATportable[4])+(5*IVATportable[0])+(10*IVATportable[1])+(10*IVATportable[2])+(15*IVATportable[3]);
        return Charge;
    }
        else if (Pwater>25)
        {
            Charge=((Pwater-25)*IVATportable[3])+(5*IVATportable[0])+(10*IVATportable[1])+(10*IVATportable[2]);
            return Charge;
        }
    else if (Pwater>15){
        Charge=((Pwater-15)*IVATportable[2])+(5*IVATportable[0])+(10*IVATportable[1]);
        return Charge;
    }
    else if (Pwater>5){
        Charge=((Pwater-5)*IVATportable[1])+(5*IVATportable[0]);
        return Charge;
    }
    else
    {
        Charge = Pwater*IVATportable[0];
        return Charge;
    }
   }
    else  // Domestic User not paying VAT for first 5kL
    {
    if (Pwater>40)
    {
       Charge=((Pwater-40)*IVATportable[4])+(5*3.50)+(10*IVATportable[1])+(10*IVATportable[2])+(15*IVATportable[3]);
        return Charge;
    }
    else if (Pwater>25)
        {
            Charge=((Pwater-25)*IVATportable[3])+(5*3.50)+(10*IVATportable[1])+(10*IVATportable[2]);
            return Charge;
        }
    else if (Pwater>15){
        Charge=((Pwater-15)*IVATportable[2])+(5*3.50)+(IVATportable[1]*10);
        return Charge;
    }
    else if (Pwater>5){
        Charge=((Pwater-5)*IVATportable[1])+(5*3.5);
        return Charge;
    }
    return (Pwater*3.5); //not paying with VAT since it is first 5kl
   }
}

double WasteWOutVAT(double Wwater) //function to calculate the charge for waste water without VAT
{
    double Charge=0;       //initializing charge
    const double XVATwaste[5]={0.65,2.60,3.90,5.20,6.50};       //Values of XVATwaste initialized and taken from the table
    if (Wwater>40)//ditto (same idea as the function above)
    {
       Charge=((Wwater-40)*XVATwaste[4])+(5*XVATwaste[0])+(10*XVATwaste[1])+(10*XVATwaste[2])+(15*XVATwaste[3]);
        return Charge;
    }
    else if (Wwater>25)
        {
            Charge=((Wwater-25)*XVATwaste[3])+(5*XVATwaste[0])+(10*XVATwaste[1])+(10*XVATwaste[2]);
            return Charge;
        }
    else if (Wwater>15){
        Charge=((Wwater-15)*XVATwaste[2])+(5*XVATwaste[0])+(10*XVATwaste[1]);
        return Charge;
    }
    else if (Wwater>5){
        Charge=((Wwater-5)*XVATwaste[1])+(5*XVATwaste[0]);
        return Charge;
    }
    else
    return (Wwater*XVATwaste[0]);
}

double WasteWithVAT(int opt, double Wwater) //function to calculate the charge for waste water with VAT
{
    double Charge=0;//initialzing charge
    const double IVATwaste[5]={0.73,2.91,4.37,5.82,7.28}; //Values of IVATwaste initialized and taken from the table
    if (opt==3) //Commercial/industrial will be charged with VAT even for first 5 kl
   {
   if (Wwater>40)//ditto (same idea as the function above)
    {
       Charge=((Wwater-40)*IVATwaste[4])+(5*IVATwaste[0])+(10*IVATwaste[1])+(10*IVATwaste[2])+(15*IVATwaste[3]);
        return Charge;
    }
        else if (Wwater>25)
        {
            Charge=((Wwater-25)*IVATwaste[3])+(5*IVATwaste[0])+(10*IVATwaste[1])+(10*IVATwaste[2]);
            return Charge;
        }
    else if (Wwater>15){
        Charge=((Wwater-15)*IVATwaste[2])+(5*IVATwaste[0])+(10*IVATwaste[1]);
        return Charge;
    }

    else if (Wwater>5){
        Charge=((Wwater-5)*IVATwaste[1])+(5*IVATwaste[0]);
        return Charge;
    }
    else
    return (Wwater*IVATwaste[0]);
}
else
if (Wwater>40) // for 5kL VAT free domestic customer
    {
       Charge=((Wwater-40)*IVATwaste[4])+(5*0.65)+(10*IVATwaste[1])+(10*IVATwaste[2])+(15*IVATwaste[3]);
        return Charge;
    }
    else if (Wwater>25)
        {
            Charge=((Wwater-25)*IVATwaste[3])+(5*0.65)+(10*IVATwaste[1])+(10*IVATwaste[2]);
            return Charge;
        }
    else if (Wwater>15){
        Charge=((Wwater-15)*IVATwaste[2])+(5*0.65)+(10*IVATwaste[1]);
        return Charge;
    }
    else if (Wwater>5){
        Charge=((Wwater-5)*IVATwaste[1])+(5*0.65);
        return Charge;
    }
    else
    return (Wwater*0.65);
}
