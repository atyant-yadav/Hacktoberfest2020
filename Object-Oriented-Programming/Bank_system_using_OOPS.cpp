#include<iostream>

#include<stdio.h>

#include<conio.h>

#include<bits/stdc++.h>

using namespace std;

class bank {
    private:
        int ac_no, account;
    float balance;
    char name[20];
    public:
        void open(void);
    void deposit(int);
    void withdraw(int);
    void search(int);
    void display(void);
};
void bank::open(void) {
    cout << "\n ENTER YOUR NAME : ";
    cin >> name;
    cout << "\n ENTER YOUR ACCOUNT NUMBER AGAIN (MUST BE SAME AS ABOVE): ";
    cin >> account;
    cout << "\n ENTER THE AMOUNT OF MONEY AGAIN : ";
    cin >> balance;
    cout << "\n ACCOUNT CREATED SUCCESSFULLY !! \n";
}
void bank::deposit(int j) {
    int bnc;
    if (account == j) {
        cout << "\n ENTER THE AMOUNT OF MONEY : ";
        cin >> bnc;
        balance = balance + bnc;

        cout << "\n\n\t Balance updated !!! \n";
    }
}
void bank::withdraw(int k) {
    int blnc, p;

    cout << "\n YOUR CURRENT ACCOUNT BALANCE IS " << balance << "\n" << " ENTER AMOUNT OF MONEY YOU WANT TO WITHDRAW ";
    cin >> blnc;
    p = balance - blnc;
    if (p < 5001) {
        cout << "\n SORRY !!! THERE IS NOT ENOUGH MONEY IN YOUR ACCOUNT\n";
        cout << "\n IDLE BALANCE CANNOT BE LESS THAN 5001\n";
    } else if (p >= 5001) {
        cout << "\n\tYOUR REQUEST TO WITHDRAW MONEY HAS DONE\n\n";
        balance = p;
    }

}
void bank::display(void) {
    cout << "\n\n NAME : " << name << "\n\n ACCOUNT NO. " << account << "\n\n BALANCE : " <<
        balance << "\n\n";
}

void bank::search(int m) {
    if (account == m) {
        cout << "\n\n*******Account Holder's INFO*******";

        cout << "\n\n NAME : " << name << "\n\n ACCOUNT NO. " << account << "\n\n BALANCE : "

            <<
            balance << "\n\n";
        cout << "\n***************************************\n\n";
    }
}
int main() {
    int i, j, k, m, l, y = 0;
    bank b[20];
    int index;
    int count = 0;
    vector < int > v;
    do

    {
        cout << "\n PRESS 1 TO OPEN ACCOUNT \n\n" <<
		" PRESS 2 TO DEPOSIT AMOUNT \n\n" << 
		" PRESS 3 TO WITHDRAW MONEY\n\n"<<
		" PRESS 4 TO DISPLAY ALL ACCOUNTS\n\n"<<
		" PRESS 5 FOR ACCOUNT ENQUIRY\n\n"<<
		" PRESS 6 TO EXIT\n\n\t\n ";
        cout << " Your option......";
        cin >> index;
        system("cls");
        switch (index) {
        case 1: //opening account
        {
            int f = 0;
            int x;
            cout << "\n ENTER THE ACCOUNT NUMBER . ";
            cin >> x;
            for (int itr = 0; itr < v.size(); itr++) {
                if (v[itr] == x) {
                    cout << "\n This account already exist.\n\n";
                    f = 1;
                    break;
                }
            }
            if (f == 0) {
                int temp;

                cout << "\n ENTER THE AMOUNT OF MONEY : OPENING BALANCE MUST BE GREATER THAN 5000 ";
                cin >> temp;
                if (temp > 5000) {
                    b[count].open();
                    v.push_back(x);
                    count++;
                } else {

                    cout << "\n Cant open account. opening requires initial balance greater than 5000\n\n ";
                }
            }
            break;
        }
        case 2: {
            int l = 0;
            int flag = 0;
            cout << "\n ENTER YOUR ACCOUNT NO. "; //deposit amount
            cin >> j;
            for (l = 0; l < count; l++) {
                if (v[l] == j) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << "\n This account do not exist\n\n";
            else

                b[l].deposit(j);
            break;
        }
        case 3: {
            int l = 0;
            int flag = 0;
            cout << "\n ENTER YOUR ACCOUNT NO. "; //withdraw amount
            cin >> j;
            for (l = 0; l < count; l++) {
                if (v[l] == j) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << "\n This account do not exist\n\n";
            else
                b[l].withdraw(j);
            break;
        }
        case 4:
            for (i = 0; i < count; i++) { //display all option
                b[i].display();
            }
            break;
        case 5: {
            int l = 0;
            int flag = 0;
            cout << "\n ENTER YOUR ACCOUNT NO. "; //search particular amount
            cin >> j;
            for (l = 0; l < count; l++) {
                if (v[l] == j) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << "\n This account do not exist\n\n\n";
            else
                b[l].search(j);
            break;
        }
        case 6:
            break;
        default:
            cout << "\nYOU HAVE PRESSED THE WRONG KEY. PLEASE TRY AGAIN. \n\n\n";
            break;
        }
    } while (index != 6);
    return 0;
}
