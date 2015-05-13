// Solitaire.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdint.h>
using namespace std;
int myPow(int x, int p)
{
	if (p == 0) return 1;
	if (p == 1) return x;

	int tmp = myPow(x, p / 2);
	if (p % 2 == 0) return tmp * tmp;
	else return x * tmp * tmp;
}
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

bool present(vector<vector<pair<uint8_t, uint8_t> > > &liste, vector<pair<uint8_t, uint8_t> > &toto){
	for (auto a : liste)
		if (find(a.begin(), a.end(), toto.at(0)) != a.end() && find(a.begin(), a.end(), toto.at(1)) != a.end() && find(a.begin(), a.end(), toto.at(2)) != a.end() && find(a.begin(), a.end(), toto.at(3)) != a.end())
			return true;
	return false;
}

void ajoutercombinaison(vector<vector<pair<uint8_t, uint8_t> > > &toto, int i){
	int fin = toto.size() - 1;
	int debut = 0;
	cout << i << "  "<<fin << endl;
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
			for (int pieceacote = 0; pieceacote < 4; pieceacote++){
				if (piece!=pieceacote)
					if (nouvelleconfig1.at(pieceacote).first == nouvelleconfig1.at(piece).first&&nouvelleconfig1.at(pieceacote).second == nouvelleconfig1.at(piece).second)
						nouvelleconfig1.at(piece).first += 1;
			}
			if (!present(toto, nouvelleconfig1) && nouvelleconfig1.at(piece).first<9)
				toto.push_back(nouvelleconfig1);
			nouvelleconfig2.at(piece).first -= 1;
			for (int pieceacote = 0; pieceacote < 4; pieceacote++){
				if (piece != pieceacote)
					if (nouvelleconfig2.at(pieceacote).first == nouvelleconfig2.at(piece).first&&nouvelleconfig2.at(pieceacote).second == nouvelleconfig2.at(piece).second)
						nouvelleconfig2.at(piece).first -= 1;
					}
			if (!present(toto, nouvelleconfig2)&&nouvelleconfig2.at(piece).first>0)
				toto.push_back(nouvelleconfig2);
			nouvelleconfig3.at(piece).second += 1;
			for (int pieceacote = 0; pieceacote < 4; pieceacote++){
				if (piece != pieceacote)
					if (nouvelleconfig3.at(pieceacote).first == nouvelleconfig3.at(piece).first&&nouvelleconfig3.at(pieceacote).second == nouvelleconfig3.at(piece).second)
						nouvelleconfig3.at(piece).second += 1;
					}
			if (!present(toto, nouvelleconfig3) && nouvelleconfig3.at(piece).second<9)
			toto.push_back(nouvelleconfig3);
				nouvelleconfig4.at(piece).second -= 1;
			for (int pieceacote = 0; pieceacote < 4; pieceacote++){
				if (piece != pieceacote)
					if (nouvelleconfig4.at(pieceacote).first == nouvelleconfig4.at(piece).first&&nouvelleconfig4.at(pieceacote).second == nouvelleconfig4.at(piece).second)
						nouvelleconfig4.at(piece).second -= 1;
					}
			if (!present(toto, nouvelleconfig4) && nouvelleconfig4.at(piece).second>0)
				toto.push_back(nouvelleconfig4);
		}
	}
	cout << "Fini" << endl;
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
	for (int i = 1; i <= 8; i++){
		ajoutercombinaison(possibilite,i);
		//afficher(possibilite);
	}
    return 0;
}
