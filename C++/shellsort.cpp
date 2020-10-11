#include <iostream>
#include <string.h>
using namespace std;
int nfah = 5;
int fahdata[5] = {30,15,25,17,33};

void fahtukar(int afah, int bfah)
{
	int tfah;
	tfah = fahdata[bfah];
	fahdata[bfah] = fahdata[afah];
	fahdata[afah] = tfah;
}

void fahtampil()
{
	for (int ifah=0; ifah<nfah; ifah++)
	{
		cout << fahdata[ifah] << "	";
	}
	cout << endl;
}

void fahshell_sort()
{
	int kfah, flagfah, ifah;
	kfah=0;
	flagfah=1;
	while(kfah <= nfah-2 && flagfah == 1)	{
		ifah = 0;
		flagfah = 0;
		while (ifah <= nfah-2-kfah)	{
			if (fahdata[ifah] > fahdata[ifah+1])	{
				flagfah = 1;
				fahtukar(ifah+1, ifah);
			}
			ifah++;
		}
		kfah++;
		fahtampil();
	}
	cout << endl;
}

int main()
{
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "    Selamat Datang Di Aplikasi    " << endl;
	cout << "            Shell  Sort           " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Nilai Awal                " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	fahtampil();
	cout << "Proses Shell Sort........" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	fahtampil();
	fahshell_sort();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "            TERIMA KASIH          " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cin.get();
}
