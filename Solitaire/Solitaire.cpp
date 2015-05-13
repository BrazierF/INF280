// Solitaire.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdint.h>
using namespace std;
void afficherconfiguration(vector<pair<uint8_t,uint8_t> > toto){
	if (toto.size() <= 4){
		for (int j = 0; j <= 8; j++)
			cout << j << "\t |";
		cout << endl;
		for (int i = 1; i <= 8; i++){
			cout << i << "\t |";
			for (int j = 1; j <= 8; j++){
				if ((toto.at(0).first == i&&toto.at(0).second == j) || (toto.at(1).first == i&&toto.at(1).second == j) || (toto.at(2).first == i&&toto.at(2).second == j) || (toto.at(3).first == i&&toto.at(3).second == j))
					cout << "  X";
				cout << "\t |";
			}
			cout << endl;
		}
	}
	cout << "\n \n\n\n";
}
void afficher(vector<vector<pair<uint8_t, uint8_t> > > &toto){
	for (auto vecteur : toto)
		afficherconfiguration(vecteur);
}
void ajoutercombinaison(vector<vector<pair<uint8_t, uint8_t> > > &toto, int i){
	int fin = toto.size() - 1;
	int debut = fin - 1 - 2 ^ i;
	vector<pair<uint8_t, uint8_t> > config;
	for (int compteur = debut; compteur<= fin; compteur++){
		config = vector<pair<uint8_t, uint8_t> >(toto.at(compteur));
		for (int piece = 0; piece < 4; piece++)
		{
			vector<pair<uint8_t, uint8_t> > nouvelleconfig1(config);
			vector<pair<uint8_t, uint8_t> > nouvelleconfig2(config);
			vector<pair<uint8_t, uint8_t> > nouvelleconfig3(config);
			vector<pair<uint8_t, uint8_t> > nouvelleconfig4(config);
			nouvelleconfig1.at(piece).first += 1;
			toto.push_back(nouvelleconfig1);
			nouvelleconfig2.at(piece).first -= 1;
			toto.push_back(nouvelleconfig2);
			nouvelleconfig3.at(piece).second += 1;
			toto.push_back(nouvelleconfig3);
			nouvelleconfig4.at(piece).second -= 1;
			toto.push_back(nouvelleconfig4);
		}
	}

}
int main()
{
	uint8_t x, y;
	vector<pair<uint8_t, uint8_t> > configurationinitiale(4, pair<uint8_t, uint8_t>(0, 0));
	vector<pair<uint8_t, uint8_t> > configurationfinale(4, pair<uint8_t, uint8_t>(0, 0));
	vector<vector<pair<uint8_t, uint8_t> > > possibilite;
	for (int i = 0; i < 4; i++){
		cin >> x >> y;
		x -= 48; y -= 48;
		configurationinitiale.at(i) = pair<uint8_t, uint8_t>(x, y);
	}for (int i = 0; i < 4; i++){
		cin >> x >> y;
		x -= 48; y -= 48;
		configurationfinale.at(i) = pair<uint8_t, uint8_t>(x, y);
	}
	possibilite.push_back(configurationinitiale);
	for (int i = 1; i <= 1; i++){
		ajoutercombinaison(possibilite,i);
		afficher(possibilite);
	}
    return 0;
}
