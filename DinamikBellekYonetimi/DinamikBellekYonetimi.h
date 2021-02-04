#include <iostream>
#include <vector>

using namespace std;

class DinamikBellekYonetimi
{
private:
	bool essizMi(vector<int>, int);
	bool sabitMi(int**, int);
	vector<pair<int, int>> minbul(int**, int, int);
	bool maxMi(int**, int, pair<int, int>);

public:
	DinamikBellekYonetimi();
	bool GizemliMatrixMi(int**, int, int);
	int SansliMatrisElemanlarinSayisi(int**, int, int);
};

