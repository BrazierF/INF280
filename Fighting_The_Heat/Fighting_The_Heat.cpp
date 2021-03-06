// Fighting_The_Heat.cpp : main project file.
//ACCEPTED
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
J'ai pris la grille et l'ai enregistre dans differents tableaux de string
il y a 4 tableaux differents qui correspondent a la grille vue horizontalement, verticalement, et les 2 diagonales
Les mots a trouves sont stockes dans le dictionnaire et leurs inverses aussi.
Ensuite j'effectue un found sur les differents tableaux et marque les lettres qui sont dans les mots des dictionnaires.

La fonction diagonale fait la correspondance entre les indice de la grille initiale et le tableaux contenant les mot lus diagonalement
*/
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
    int nblignes, nbcolonnes, nbmots;//, nbcas;
    //bool premier =true;
    while (scanf("%i",&nblignes)!=-1){
        /*if(premier)
            premier=false;
        else cout<<endl;*/
        cin >>nbcolonnes >>nbmots;
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
        for (int mot = 0; mot < nbmots * 2; mot++){
			string motdico = dictionnaire.at(mot);
           //cout<<"Mot du dictionnaire : "<<motdico<<endl;
			for (int ligne = 0; ligne < nblignes; ligne++){
				string motligne = grilleH.at(ligne);
				size_t it = motligne.find(motdico);
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
                        //cout << "(" <<ligne<< "," <<  it + toto << ") ";
						marquage.at(ligne).at(it + toto) = true;
					}
					it = motligne.find(motdico, it + 1);
				}
			}
			for (int colonne = 0; colonne < nbcolonnes; colonne++){
				string motcolonne = grilleV.at(colonne);
				size_t it = motcolonne.find(motdico);
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
                        //cout << "(" << it + toto << "," << colonne << ") ";
						marquage.at(it + toto).at(colonne) = true;
					}
					it = motcolonne.find(motdico, it + 1);
				}
			}
			for (int nombre = -nblignes; nombre < nbcolonnes - 1; nombre++){
				string motdiag = diagNormale.at(nombre + nblignes);
				size_t it = motdiag.find(motdico);
				vector<pair<int, int>> lettresaprendre = diagonale(false, nombre, nblignes, nbcolonnes);
				while (it != string::npos){
					for (int toto = 0; toto < motdico.size(); toto++){
                        //cout << "(" << lettresaprendre.at(it + toto).first<< "," << lettresaprendre.at(it + toto).second<< ") ";
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
                        //cout << "(" << lettresaprendre.at(it + toto).first<< "," << lettresaprendre.at(it + toto).second<< ") ";
						marquage.at(lettresaprendre.at(it + toto).first).at(lettresaprendre.at(it + toto).second) = true;
					}
					it = motdiag.find(motdico, it + 1);
				}
			}
		}

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
