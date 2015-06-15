// PageHopping.cpp : main project file.
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int tableau[101][101];
bool oki[101];
vector<int> toto;

int min(int a, int b){
	if (a == -1 || b < a)
		return b;
	else
		return a;
}

void printtab(int nbcase){
	for (int i = 1; i <= nbcase; i++){
		for (int j = 1; j <= nbcase; j++){
			cout << " | " << tableau[i][j];
		}
		cout << endl;
	}
}
void set(){
	for (unsigned int i = 0; i < 101; i++){
		for (unsigned int j = 0; j < 101; j++)
			if (i != j)
				tableau[i][j] = -1;
			else tableau[i][i] = 0;
		oki[i] = false;
	}
}
int trouverpivot(vector<int> &toto, int nbcase, int casesortie){
	int mini, premierindice, bondice; bool trouve = false;
	for (int i = 0; i <= nbcase; i++){
		vector<int>::iterator it = std::find(toto.begin(), toto.end(), i);
		if (tableau[casesortie][i] != -1 && it == toto.end()){
			mini = (tableau[casesortie][i]);
			//cout << "Pivot :" << i << endl;
			premierindice = i;
			bondice = i;
			trouve = true;
			break;
		}
	}
	if (!trouve)
		return -1;
	for (int i = premierindice; i <= nbcase; i++){
		vector<int>::iterator it = find(toto.begin(), toto.end(), i);
		if (tableau[casesortie][i] < mini&&tableau[casesortie][i] != -1 && it == toto.end()){
			mini = (tableau[casesortie][i]);
			bondice = i;
		}
	}
	toto.push_back(bondice);
	return bondice;
}
void majtab(int nbcase, int casesortie){
	toto.clear();
	do{
		int indice = trouverpivot(toto, nbcase, casesortie);
		if (indice == -1)
			return;
		//cout<<"Indice"<<indice<<endl;
		//printtab(nbcase);
		//cout << "Pivot :" << indice << endl;
		for (unsigned int i = 1; i <= nbcase; i++){
			vector<int>::iterator it = find(toto.begin(), toto.end(), i);
			if (tableau[indice][i] != -1 && it == toto.end())
				tableau[casesortie][i] = min(tableau[casesortie][i], tableau[indice][i] + tableau[casesortie][indice]);
		}
	} while (toto.size() != nbcase);
}

int main()
{	
	int a, b,max=0,cas=0;
	while (scanf("%i %i", &a, &b) != -1){
		if (a == 0 && b == 0)
			break;
		cas++;
		set();
		while (a != 0 && b != 0){
			tableau[a][b] = 1;
			max = a;
			oki[a] = true;
			scanf("%i %i", &a, &b);
		}
		for (int i = 1; i <= max; i++)
			majtab(max, i);
		int sum = 0,total=0;
		for (int i = 1; i <= max; i++){
			if (oki[i])
				total++;
			for (int j = 1; j <= max; j++){
				if (tableau[i][j] > 0)
					sum += tableau[i][j];
			}
		}
		
		cout << "Case "<<cas<<": average length between pages = " << fixed << setprecision(3) <<(float) sum/(total*(total-1))<< " clicks " << endl;
		//printtab(max);
	}
	//cout << "toto";
	cout <<""<< endl;
    return 0;
}
