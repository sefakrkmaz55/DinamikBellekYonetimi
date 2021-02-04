#include "DinamikBellekYonetimi.h"
DinamikBellekYonetimi::DinamikBellekYonetimi()
{}

bool DinamikBellekYonetimi::essizMi(vector<int> vIn, int n)
{
	for (int i = 0; i < n; i++)  //vektörün içinde ayný sayýdan var mý bakýlýr
	{
		for (int j = i + 1; j < n; j++)
		{
			if (vIn[i] == vIn[j])
			{
				return false;
			}
		}
	}
	return true; // eðer ifi saðlarsa true döner
}

bool DinamikBellekYonetimi::sabitMi(int** mIn, int n)
{
	int sabit = (n * (n * n + 1)) / 2;
	for (int i = 0; i < n; i++)
	{
		int toplamsatir = 0; //tek tek satýr toplamlarýna bakýlýr
		int toplamsutun = 0; //tek tek sutun toplamýna bakýlýr
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
	int toplamanakosegen = 0; // ana kosegen toplamlarýna bakýlýr
	int toplamikincilkosegen = 0; // ikincil kosegen toplamlarýna bakýlýr
	for (int i = 0; i < n; i++)
	{
		toplamanakosegen += mIn[i][i];
		toplamikincilkosegen += mIn[i][n - 1 - i];
	}
	if (toplamanakosegen != sabit || toplamikincilkosegen != sabit)
	{
		return false;
	}
	return true; // eðer tüm ifleri saðlarsa true döner

}


bool DinamikBellekYonetimi::GizemliMatrixMi(int** mat, int satir, int sutun)
{
	if (satir != sutun)
	{
		return 0;
	}
	int n2 = satir * satir;
	vector<int> v;
	for (int i = 0; i < satir; i++) // her sayýyý vektöre atar ve nkareden küçük mü bakar
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
	if (essizMi(v, satir * sutun) == false) // sayýlar farklý mý
	{
		return 0;
	}
	if (sabitMi(mat, satir) == false) // toplamlar m sabitine eþit mi
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
		int minumumsatir = mat[0][i]; //tek tek satýr toplamlarýna bakýlýr
		pair<int, int> p;
		p.first = 0;
		p.second = i;
		for (int j = 0; j < sutun; j++)
		{
			if (minumumsatir > mat[j][i])
			{
				int minumumsatir = mat[j][i]; //daha küçüðü bulunur
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
			return false; // daha küçüðü varsa false döner
		}
	}
	return true; // bi þey bulamazsa true döner
}


int DinamikBellekYonetimi::SansliMatrisElemanlarinSayisi(int** mat, int satir, int sutun)
{
	vector<int> v;
	for (int i = 0; i < satir; i++) // her sayýyý vektöre atar ve nkareden küçük mü bakar
	{
		for (int j = 0; j < sutun; j++)
		{
			v.push_back(mat[i][j]);
		}
	}
	if (essizMi(v, satir * sutun) == false) // sayýlar farklý mý
	{
		return 0;
	}
	vector<pair<int, int>> min = minbul(mat, satir, sutun); // satýrlardaki bulduðu minumumlarýn konumlarýný vektöre atar

	int sayac = 0;

	for (int i = 0; i < min.size(); i++)// minumum sayý kendi sütununun maxý mý diye bakar
	{
		if (maxMi(mat, sutun, min[i])) // eðer öyle bir sayý varsa sayacý günceller
		{
			sayac += 1;
		}
	}
	return sayac;

}


