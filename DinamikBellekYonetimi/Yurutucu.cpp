#include "DinamikBellekYonetimi.h"
#include <iostream>
using namespace std;

int main()
{
	/*Gİzemli ve şanslı matrisler için boyut istedik*/
	int satir1, satir2, sutun1, sutun2;
	cout << "Satir giriniz: ";
	cin >> satir1;
	cout << endl;

	cout << "Sutun giriniz: ";
	cin >> sutun1;
	cout << endl;

	cout << "Satir giriniz: ";
	cin >> satir2;
	cout << endl;

	cout << "Sutun giriniz: ";
	cin >> sutun2;
	cout << endl;

	DinamikBellekYonetimi d;//DinamikBellekYonetimi sınıfını tanımladık 

	int** matris1 = new int* [256];
	for (int i = 0; i < 256; ++i)
	{
		matris1[i] = new int[256];
	}

	int** matris2 = new int* [256];
	for (int i = 0; i < 256; ++i)
	{
		matris2[i] = new int[256];
	}


	for (int i = 0; i < sutun1; i++)
	{
		for (int j = 0; j < satir1; j++)
		{
			cout << "Eleman Giriniz: ";
			int a;
			cin >> a;
			matris1[j][i] = a;
			cout << endl;
		}
	}
	cout << "ilk matrix: " << endl; // matrix yazdırılır
	for (int i = 0; i < sutun1; i++)
	{
		for (int j = 0; j < satir1; j++)
		{
			cout << matris1[j][i] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < sutun2; i++)
	{
		for (int j = 0; j < satir2; j++)
		{
			cout << "Eleman Giriniz: ";
			int a;
			cin >> a;
			matris2[j][i] = a;
			cout << endl;
		}
	}
	cout << "ikinci matrix: " << endl;  // matrix yazdırılır
	for (int i = 0; i < sutun2; i++)
	{
		for (int j = 0; j < satir2; j++)
		{
			cout << matris2[j][i] << " ";
		}
		cout << endl;
	}

	bool gizemli = d.GizemliMatrixMi(matris1, satir1, sutun1);
	if (gizemli == true)
	{
		cout << "ilk Matrix gizemlidir..." << endl;
	}
	else
	{
		cout << "ilk Matrix gizemli değildir..." << endl;
	}
	cout << endl;
	int sansli = d.SansliMatrisElemanlarinSayisi(matris2, satir2, sutun2);

	cout << sansli << " tane sayi sansli..." << endl;

	return 0;
}