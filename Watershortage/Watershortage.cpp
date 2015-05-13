// Watershortage.cpp : main project file.

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	int nbinput, nbcistern;
	double base, hauteur, largeur, profondeur, volume, resultat;
	cin >> nbinput;
	for (int i = 0; i < nbinput; i++){
		cin >> nbcistern;
		vector<double> liste;
		vector<pair<double, vector<int> > > coop;
		vector<vector<double> > tailles(nbcistern, vector<double>());
		for (int compt = 0; compt < nbcistern; compt++){
			cin >> base >> hauteur >> largeur >> profondeur;
			liste.push_back(base);
			liste.push_back(base + hauteur);
			tailles.at(compt).push_back(base);
			tailles.at(compt).push_back(hauteur);
			tailles.at(compt).push_back(largeur);
			tailles.at(compt).push_back(profondeur);
		}
		cin >> volume;
		sort(liste.begin(), liste.end());
		for (double hauteur : liste){
			coop.push_back(pair<double, vector<int>>(hauteur, vector<int>()));
		}
		for (int k = 0; k < liste.size(); k++){
			double hauteur = coop.at(k).first;
			for (int l = 0; l < tailles.size(); l++)
				if (tailles.at(l).at(0) <= hauteur&&tailles.at(l).at(0) + tailles.at(l).at(1)>hauteur)
					coop.at(k).second.push_back(l);
		}
		for (int k = 0; k < coop.size()-1; k++){
			double hauteur = coop.at(k).first, surface = 0, volumetemp = 0;
			//cout << "Hauteur " << hauteur << endl;
			for (int a : coop.at(k).second)
				surface += tailles.at(a).at(2)*tailles.at(a).at(3);
			//cout << "Surface " << surface << endl;
			volumetemp = surface * (coop.at(k + 1).first - hauteur);
			if (volumetemp >= volume){
				resultat = hauteur + volume / surface;
				volume = 0;
				break;
			}
			volume -= volumetemp;
		}
		if (volume > 0)
			cout << "OVERFLOW" << endl;
		else
			cout <<fixed<<setprecision(2) << resultat << endl;
		if (i < nbinput - 1)
			cout << "\n";
	}
	return 0;
}