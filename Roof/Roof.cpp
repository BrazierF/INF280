// Roof.cpp : main project file.

//#include "stdafx.h"
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int nbcas, nbmorceaux;
	cin >> nbcas;
	for (int cas = 0; cas < nbcas; cas++){
		vector<pair<int, vector<int> > > utile;
		cin >> nbmorceaux;
		vector<int> abscisses;
		vector < pair<int, int> > noncouvert(1, make_pair(0, 1000000));
		vector<vector<int> >morc(nbmorceaux, vector<int>());
		vector<bool> marquage(nbmorceaux, true);
		int totaleau=0;
		int xA, xB, yA, yB;
		for (int morceau = 0; morceau < nbmorceaux; morceau++){
			cin >> xA >> yA >> xB >> yB;
			morc.at(morceau).push_back(xA);
			morc.at(morceau).push_back(yA);
			morc.at(morceau).push_back(xB);
			morc.at(morceau).push_back(yB);
			morc.at(morceau).push_back(yB - yA);
			morc.at(morceau).push_back(0);
			if (find(abscisses.begin(), abscisses.end(), xA) == abscisses.end()){
				abscisses.push_back(xA);
			}if (find(abscisses.begin(), abscisses.end(), xB) == abscisses.end()){
				abscisses.push_back(xB);
			}
			sort(abscisses.begin(), abscisses.end());
		}
		for (int haute : abscisses)
			utile.push_back(make_pair(haute, vector<int>()));
		for (int cherche = 0; cherche < nbmorceaux; cherche++){
			for (auto & pair : utile){
				if (pair.first >= morc.at(cherche).at(0) && pair.first < morc.at(cherche).at(2)){
					pair.second.push_back(cherche);
				}
			}
				float hauteurdeenbas = 0; int lebon; bool toto = false;
				//cout << "Je cherche celui en dessous de : " << cherche << endl;
				//cout << "Mon point le plus bas est ";
				if (morc.at(cherche).at(4) < 0){
					//cout << morc.at(cherche).at(3) << endl;
					for (int enbasdecheche = 0; enbasdecheche < nbmorceaux; enbasdecheche++){
						if (enbasdecheche != cherche){
							if (morc.at(cherche).at(2) <= morc.at(enbasdecheche).at(2) && morc.at(cherche).at(2) >= morc.at(enbasdecheche).at(0)){
								float haut = (float)morc.at(enbasdecheche).at(4) / ((morc.at(enbasdecheche).at(2) - (morc.at(enbasdecheche).at(0))))*(morc.at(cherche).at(2) - morc.at(enbasdecheche).at(0)) + morc.at(enbasdecheche).at(1);
								//cout << "En desssous ou dessus de mon point le plus bas passe le toit " << enbasdecheche << " à la hauteur " << haut << endl;
								/*cout << "Calcul de la hauteur de endessous \nCoefficient directeur : " << (float)morc.at(enbasdecheche).at(4) / ((morc.at(enbasdecheche).at(2) - (morc.at(enbasdecheche).at(0))))*(morc.at(cherche).at(2) - morc.at(enbasdecheche).at(0));
								cout << "Coordonnees : " << (morc.at(cherche).at(2) - morc.at(enbasdecheche).at(0)) << endl;
								cout << "Absisse a l'ordonnee : " << +morc.at(enbasdecheche).at(1) << endl;*/
								if (haut>hauteurdeenbas&&haut < morc.at(cherche).at(3)){
									hauteurdeenbas = haut;
									lebon = enbasdecheche;
									toto = true;
								}
							}
						}
					}
				}
				else{
					//cout << morc.at(cherche).at(1) << endl;
					for (int enbasdecheche = 0; enbasdecheche < nbmorceaux; enbasdecheche++){
						if (enbasdecheche != cherche){
							if (morc.at(cherche).at(0) <= morc.at(enbasdecheche).at(2) && morc.at(cherche).at(0) >= morc.at(enbasdecheche).at(0)){
								float haut = (float)morc.at(enbasdecheche).at(4) / ((morc.at(enbasdecheche).at(2) - (morc.at(enbasdecheche).at(0))))*(morc.at(cherche).at(0) - morc.at(enbasdecheche).at(0)) + morc.at(enbasdecheche).at(1);
								//cout << "En desssous ou dessus de mon point le plus bas passe le toit " << enbasdecheche << " à la hauteur " << haut << endl;
								/*cout << "Calcul de la hauteur de endessous \nCoefficient directeur : " << (float)morc.at(enbasdecheche).at(4) / ((morc.at(enbasdecheche).at(2) - (morc.at(enbasdecheche).at(0))))*(morc.at(cherche).at(0) - morc.at(enbasdecheche).at(0));
								cout << "Coordonnees : " << (morc.at(cherche).at(0) - morc.at(enbasdecheche).at(0)) << endl;
								cout << "Absisse a l'ordonnee : " << +morc.at(enbasdecheche).at(1) << endl;*/
								if (haut>hauteurdeenbas&&haut < morc.at(cherche).at(1)){
									hauteurdeenbas = haut;
									lebon = enbasdecheche;
									toto = true;
								}
							}
						}
					}
				}
				if (toto){
					morc.at(cherche).push_back(lebon);
					marquage.at(lebon) = false;
		}
				
			}
			
	/*	for (auto toto : utile){
			cout << "Hauteur" << toto.first << " : ";
			for (auto prout : toto.second){
				cout << prout << " ";
			}
			cout << endl;
		}*/
		int ancien = 0,ancienbonindice=0;
		bool premier=true;
		for (auto & essai : utile){
			int hauteurmax = 0, bonindice = 0;
			for (auto & possible : essai.second){
				if (morc.at(possible).at(1) > hauteurmax){
					hauteurmax = morc.at(possible).at(1);
					bonindice = possible;
				}
			}
			if (!premier){
			morc.at(ancienbonindice).at(5) += essai.first - ancien;
			totaleau += essai.first - ancien;
			//cout << "morc.at("<<ancienbonindice<<").at(5) += "<<essai.first - ancien<< endl;
			}
			else{ premier = false; }
			ancienbonindice = bonindice;

			if (essai.second.size() != 0){
				essai.second.clear();
				essai.second.push_back(bonindice);
			}
			else{ premier = true; }
			ancien = essai.first;
			
		}
		int eauausol = 0;
		for (int bouffe = 0; bouffe < nbmorceaux; bouffe++){
			morc.at(bouffe).at(0) = 0;
		}
		while (eauausol < totaleau){
			for (int bouffe = 0; bouffe < nbmorceaux; bouffe++){
				morc.at(bouffe).at(0) += morc.at(bouffe).at(5);
				if (morc.at(bouffe).size() == 7){
					morc.at(morc.at(bouffe).at(6)).at(5) += morc.at(bouffe).at(5);
				}
				else{
					eauausol += morc.at(bouffe).at(5);
				}
				morc.at(bouffe).at(5) = 0;
			}
		}
		/*int prout = 0;
		for (auto salut : morc){
			cout << "Toit n " << prout << " : ";
			for (auto waw : salut){
				cout << waw << "|";
			}
			cout << endl;
			prout++;
		}
		for (auto toto : utile){
			cout << "Hauteur" << toto.first << " : ";
			for (auto prout : toto.second){
				cout << prout << " ";
			}
			cout << endl;
		}
		cout << "Taille : " << utile.size()<<"\n\n\n"<<endl;*/
		//cout << "Resultat : " << endl;
		for (auto salut : morc){
			cout << salut.at(0) << endl;
		}
		if (cas < nbcas - 1){
			cout << endl;
		}
	}
    return 0;
}