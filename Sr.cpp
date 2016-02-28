#include <conio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	string s;
	cin >> s;
	vector<int> k;
	int x = 0;

	//-----splite input string on the base of ',' and turn it to the numbers that saved in vector-------
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ',')
		{
			k.push_back(x);
			x = 0;
		}
		else
		{
			x = x * 10 + (s[i]-'0');
		}
	}

	k.push_back(x);

	//------------

	sort(k.begin(),k.end());  //sort numbers


	//----find Q2-----
	double miane;
	if (k.size() % 2 == 0)
	{
		miane = (k[(k.size() / 2) - 1 ] + k[k.size() / 2]) / 2.0; // if the numbers are even median is this
	}
	else
	{
		miane = k[(k.size() / 2)];  //otherwise
	}


	//---find Q1------
	vector<int> l ;
	double Q1;
	for (int i = 0; i < k.size()/2; i++)
	{

		l.push_back(k[i]);         //push numbers before median in other vector to calculate Q1
	}

	 if (l.size() % 2 == 0)
	{
		Q1 = (l[(l.size() / 2) - 1] + l[l.size() / 2]) / 2.0; //if the numbers before median are even , q1 is this
	}
	else
	{
		Q1 = l[(l.size() / 2)];   //otherwise is this
	}

	//-----find Q3----
	 vector<int> m;
	 double Q3;
	 for (int i =ceil( k.size()/2.0 ); i < k.size(); i++)
	 {

		 m.push_back(k[i]);    //push numbers after median in other vector to calculate Q3
	 }

	 if (m.size() % 2 == 0)
	 {
		 Q3 = (m[(m.size() / 2) - 1] + m[m.size() / 2]) / 2.0;
	 }
	 else
	 {
		 Q3 = m[(m.size() / 2)];
	 }

	 //------find outlier---------
	 vector<int> outlier;
	 double IQR,t1,t2;
	 int cont = 0;
	 IQR = Q3 - Q1;
	 t1 = Q1 - 1.5*IQR;
	 t2 = Q3 + 1.5*IQR;

	 for (int i = 0; i < k.size(); i++) 
	 {
		 if (k[i] < t1)
		 {
			 outlier.push_back(k[i]);     //data less than q1-1.5*iqr
			 cont++;
		 }
	 }
	 for (int i = 0; i < k.size(); i++)
	 {
		 if (k[i] > t2)
		 {
			 outlier.push_back(k[i]);     //data more than q3+1.5*iqr
			 cont++;
		 }
	 }


	 //----outputs----

	cout << "MIN:" << k[0]<<endl;

	cout << "Q1:" << Q1 << " -- " << "Q2:" << miane << " -- " << "Q3:" << Q3 << endl;

	cout << "MAX:" << k[k.size()-1] << endl;

	if (cont == 0)
	{
		cout << "There is no outlier" << endl;
	}
	else
	{
		for (int i = 0; i < outlier.size(); i++)
		{
			cout << outlier[i] << endl;
		}
	}

	_getch();
	return 0;
}