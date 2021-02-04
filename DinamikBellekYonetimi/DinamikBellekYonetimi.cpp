#include "DinamikBellekYonetimi.h"
DinamikBellekYonetimi::DinamikBellekYonetimi()
{}

bool DinamikBellekYonetimi::essizMi(vector<int> vIn, int n)
{
	for (int i = 0; i < n; i++)  //vekt�r�n i�inde ayn� say�dan var m� bak�l�r
	{
		for (int j = i + 1; j < n; j++)
		{
			if (vIn[i] == vIn[j])
			{
				return false;
			}
		}
	}
	return true; // e�er ifi sa�larsa true d�ner
}

bool DinamikBellekYonetimi::sabitMi(int** mIn, int n)
{
	int sabit = (n * (n * n + 1)) / 2;
	for (int i = 0; i < n; i++)
	{
		int toplamsatir = 0; //tek tek sat�r toplamlar�na bak�l�r
		int toplamsutun = 0; //tek tek sutun toplam�na bak�l�r
		for (int j = 0; j < n; j++)
		{
			toplamsatir += mIn[i][j];
			toplamsutun += mIn[j][i];
		}
		if (toplamsatir != sabit || toplamsutun != sabit)
		{
			return false;
		}
	}
	int toplamanakosegen = 0; // ana kosegen toplamlar�na bak�l�r
	int toplamikincilkosegen = 0; // ikincil kosegen toplamlar�na bak�l�r
	for (int i = 0; i < n; i++)
	{
		toplamanakosegen += mIn[i][i];
		toplamikincilkosegen += mIn[i][n - 1 - i];
	}
	if (toplamanakosegen != sabit || toplamikincilkosegen != sabit)
	{
		return false;
	}
	return true; // e�er t�m ifleri sa�larsa true d�ner

}


bool DinamikBellekYonetimi::GizemliMatrixMi(int** mat, int satir, int sutun)
{
	if (satir != sutun)
	{
		return 0;
	}
	int n2 = satir * satir;
	vector<int> v;
	for (int i = 0; i < satir; i++) // her say�y� vekt�re atar ve nkareden k���k m� bakar
	{
		for (int j = 0; j < sutun; j++)
		{
			if (1 <= mat[i][j] && n2 >= mat[i][j])
			{
				v.push_back(mat[i][j]);
			}
			else
			{
				return 0;
			}
		}
	}
	if (essizMi(v, satir * sutun) == false) // say�lar farkl� m�
	{
		return 0;
	}
	if (sabitMi(mat, satir) == false) // toplamlar m sabitine e�it mi
	{
		return 0;
	}
	return 1;
}

vector<pair<int, int>> DinamikBellekYonetimi::minbul(int** mat, int satir, int sutun)
{
	vector<pair<int, int>> v;
	for (int i = 0; i < satir; i++)
	{
		int minumumsatir = mat[0][i]; //tek tek sat�r toplamlar�na bak�l�r
		pair<int, int> p;
		p.first = 0;
		p.second = i;
		for (int j = 0; j < sutun; j++)
		{
			if (minumumsatir > mat[j][i])
			{
				int minumumsatir = mat[j][i]; //daha k����� bulunur
				p.first = j;
				p.second = i;
			}
		}
		v.push_back(p);

	}
	return v;
}

bool DinamikBellekYonetimi::maxMi(int** m, int sutun, pair<int, int> p)
{
	int max = m[p.first][p.second];
	for (int j = 0; j < sutun; j++)
	{
		if (max < m[p.first][j])
		{
			return false; // daha k����� varsa false d�ner
		}
	}
	return true; // bi �ey bulamazsa true d�ner
}


int DinamikBellekYonetimi::SansliMatrisElemanlarinSayisi(int** mat, int satir, int sutun)
{
	vector<int> v;
	for (int i = 0; i < satir; i++) // her say�y� vekt�re atar ve nkareden k���k m� bakar
	{
		for (int j = 0; j < sutun; j++)
		{
			v.push_back(mat[i][j]);
		}
	}
	if (essizMi(v, satir * sutun) == false) // say�lar farkl� m�
	{
		return 0;
	}
	vector<pair<int, int>> min = minbul(mat, satir, sutun); // sat�rlardaki buldu�u minumumlar�n konumlar�n� vekt�re atar

	int sayac = 0;

	for (int i = 0; i < min.size(); i++)// minumum say� kendi s�tununun max� m� diye bakar
	{
		if (maxMi(mat, sutun, min[i])) // e�er �yle bir say� varsa sayac� g�nceller
		{
			sayac += 1;
		}
	}
	return sayac;

}


