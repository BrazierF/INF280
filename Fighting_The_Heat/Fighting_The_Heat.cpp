// Fighting_The_Heat.cpp : main project file.

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> diagonale(bool sens, int nb, int nblignes, int nbcolonnes){
	vector<pair<int, int>> diagonale;
	if (!sens){
		if (nb < 0){
			for (int cas = 1; cas <= min(nb + nblignes + 1, min(nbcolonnes, nblignes)); cas++){
				diagonale.push_back(make_pair(-nb + cas - 2, cas - 1));
			}
		}
		else{
			for (int cas = 1; cas <= min(nbcolonnes - nb - 1, min(nbcolonnes, nblignes)); cas++){
				diagonale.push_back(make_pair(cas - 1, nb + cas));
			}
		}
	}
	else{
		if (nb < 0){
			for (int cas = 1; cas <= min(nb + nbcolonnes + 1, min(nbcolonnes, nblignes)); cas++){
				diagonale.push_back(make_pair(cas - 1, nb + nbcolonnes - cas + 1));
			}
		}
		else{
			for (int cas = 1; cas <= min(nblignes - nb - 1, min(nbcolonnes, nblignes)); cas++){
				diagonale.push_back(make_pair(nb + cas, nbcolonnes - cas));
			}
		}
	}
	/*cout << "Affichage : "<<nb<<" ";
	for (auto paire : diagonale){
	cout << "(" << paire.first<< "," << paire.second<< ") ";
	}
	cout << endl;*/
	return diagonale;
}

int main()
{
	int nblignes, nbcolonnes, nbmots, nbcas;
	cin >> nbcas;
	/*for (int cas = 0; cas < nbcas; cas++){
		cin >> nblignes >> nbcolonnes;-*/
	while (scanf("%i","%i",&nblignes,&nbcolonnes)!=-1){
		cin >> nbmots;
		vector<string> dictionnaire(nbmots * 2, "");
		vector<string> diagNormale((nblignes + nbcolonnes - 1), "");
		vector<string> diagInverse((nblignes + nbcolonnes - 1), "");
		vector<string> grilleH(nblignes, "");
		vector<string> grilleV(nbcolonnes, "");
		vector<vector<bool>> marquage(nblignes, vector<bool>(nbcolonnes, false));
		for (int mot = 0; mot < nbmots; mot++){
			cin >> dictionnaire.at(mot);
		}
		for (int mot = 0; mot < nbmots; mot++){
			dictionnaire.at(nbmots + mot) = dictionnaire.at(mot);
			reverse(dictionnaire.at(nbmots + mot).begin(), dictionnaire.at(nbmots + mot).end());
		}
		for (int ligne = 0; ligne < nblignes; ligne++){
			cin >> grilleH.at(ligne);
		}
		for (int colonne = 0; colonne < nbcolonnes; colonne++){
			for (int ligne = 0; ligne < nblignes; ligne++){
				grilleV.at(colonne).push_back(grilleH.at(ligne).at(colonne));
			}
		}
		for (int mot = -nblignes; mot < nbcolonnes - 1; mot++){
			vector<pair<int, int>> lettresaprendre = diagonale(false, mot, nblignes, nbcolonnes);
			for (auto & paire : lettresaprendre){
				diagNormale.at(mot + nblignes).push_back(grilleH.at(paire.first).at(paire.second));
			}
		}
		for (int mot = -nbcolonnes; mot <nblignes - 1; mot++){
			vector<pair<int, int>> lettresaprendre = diagonale(true, mot, nblignes, nbcolonnes);
			for (auto & paire : lettresaprendre){
				diagInverse.at(mot + nbcolonnes).push_back(grilleH.at(paire.first).at(paire.second));
			}
		}
		for (int mot = 0; mot < nbmots; mot++){
			string motdico = dictionnaire.at(mot);
			for (int ligne = 0; ligne < nblignes; ligne++){
				string motligne = grilleH.at(ligne);
				size_t it = motligne.find(motdico);
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
						marquage.at(ligne).at(it + toto) = true;
					}
					it = motligne.find(motdico, it + 1);
				}
			}
			for (int colonne = 0; colonne < nbcolonnes; colonne++){
				string motcolonne = grilleV.at(colonne);
				size_t it = motcolonne.find(motdico);
				/*cout << it << endl;
				cout << (it == string::npos) << endl;
				cout << "Colonne " << motcolonne << endl;
				cout << "Dico " << motdico << endl;*/
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
						//cout << "(" << it + toto << "," << colonne << ") ";
						marquage.at(it + toto).at(colonne) = true;
					}
					it = motcolonne.find(motdico, it + 1);
				}
			}
			for (int nombre = -nblignes; nombre < nbcolonnes - 1; nombre++){
				//cout << "Alors " << nombre + nblignes << endl;
				string motdiag = diagNormale.at(nombre + nblignes);
				size_t it = motdiag.find(motdico);
				vector<pair<int, int>> lettresaprendre = diagonale(false, nombre, nblignes, nbcolonnes);
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
						marquage.at(lettresaprendre.at(it + toto).first).at(lettresaprendre.at(it + toto).second) = true;
					}
					it = motdiag.find(motdico, it + 1);
				}
			}
			for (int nombre = -nbcolonnes; nombre < nblignes - 1; nombre++){
				string motdiag = diagInverse.at(nombre + nbcolonnes);
				size_t it = motdiag.find(motdico);
				vector<pair<int, int>> lettresaprendre = diagonale(true, nombre, nblignes, nbcolonnes);
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
						marquage.at(lettresaprendre.at(it + toto).first).at(lettresaprendre.at(it + toto).second) = true;
					}
					it = motdiag.find(motdico, it + 1);
				}
			}
		}
		for (int mot = nbmots; mot < nbmots * 2; mot++){
			string motdico = dictionnaire.at(mot);
			for (int ligne = 0; ligne < nblignes; ligne++){
				string motligne = grilleH.at(ligne);
				size_t it = motligne.find(motdico);
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
						marquage.at(ligne).at(nbcolonnes - (it + 1 + toto)) = true;
					}
					it = motligne.find(motdico, it + 1);
				}
			}
			for (int colonne = 0; colonne < nbcolonnes; colonne++){
				string motcolonne = grilleV.at(colonne);
				size_t it = motcolonne.find(motdico);
				/*cout << it << endl;
				cout << (it == string::npos) << endl;
				cout << "Colonne " << motcolonne << endl;
				cout << "Dico " << motdico << endl;*/
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
						//cout << "(" << it + toto << "," << colonne << ") ";
						marquage.at(nblignes - (1 + it + toto)).at(colonne) = true;
					}
					it = motcolonne.find(motdico, it + 1);
				}
			}
			for (int nombre = -nblignes; nombre < nbcolonnes - 1; nombre++){
				//cout << "Alors " << nombre + nblignes << endl;
				string motdiag = diagNormale.at(nombre + nblignes);
				size_t it = motdiag.find(motdico);
				vector<pair<int, int>> lettresaprendre = diagonale(false, nombre, nblignes, nbcolonnes);
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
						marquage.at(lettresaprendre.at(lettresaprendre.size() - (it + 1 + toto)).first).at(lettresaprendre.at(lettresaprendre.size() - (it + 1 + toto)).second) = true;
					}
					it = motdiag.find(motdico, it + 1);
				}
			}
			for (int nombre = -nbcolonnes; nombre < nblignes - 1; nombre++){
				string motdiag = diagInverse.at(nombre + nbcolonnes);
				size_t it = motdiag.find(motdico);
				vector<pair<int, int>> lettresaprendre = diagonale(true, nombre, nblignes, nbcolonnes);
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
						marquage.at(lettresaprendre.at(lettresaprendre.size() - (it + 1 + toto)).first).at(lettresaprendre.at(lettresaprendre.size() - (it + 1 + toto)).second) = true;
					}
					it = motdiag.find(motdico, it + 1);
				}
			}
		}
		/*for (string toto : dictionnaire)
			cout << toto << endl;
		cout << "\n";
		for (string toto : diagNormale)
			cout << toto << endl;
		cout << "\n";
		for (string toto : diagInverse)
			cout << toto << endl;*/
		for (int ligne = 0; ligne < nblignes; ligne++){
			for (int colonne = 0; colonne < nbcolonnes; colonne++){
				if (!marquage.at(ligne).at(colonne)){
					cout << grilleH.at(ligne).at(colonne);
				}
			}
		}
		cout << "\n";
	}

	return 0;
}
