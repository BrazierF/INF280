// ConsecutiveOnes.cpp : main project file.

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include<utility>
#include <algorithm>
using namespace std;

void print(vector<vector<int> > & matrix, int nbdelignes, int nbdecolonnes){
	for (int ligne = 0; ligne < nbdelignes; ligne++){
		cout << matrix.at(ligne).at(0) << " \t| ";
		for (int colonne = 1; colonne <= nbdecolonnes; colonne++){
			cout << matrix.at(ligne).at(colonne);
		}
		cout << endl;
	}
	cout << "\n \n \n";
}

void resultat(vector<pair<int, int> > & couplesSur,int nbdecolonnes){
	sort(couplesSur.begin(), couplesSur.end());
	vector<int> resultat;
	int prochain,ancien=1;
	resultat.push_back(ancien);
	while (resultat.size() != nbdecolonnes){
		for (auto poto : couplesSur){
			if (poto.second == ancien){
				ancien = poto.first;
				poto = make_pair(0, 0);
				resultat.push_back(ancien);
		}
			else if (poto.first == ancien){
				ancien = poto.second;
				poto = make_pair(0, 0);
				resultat.push_back(ancien);
			}
		}
	}
	for (int koukou : resultat)
		cout << koukou - 1<<"\n";
}

int main()
{
	int nbdecas,nbdecolonnes,nbdelignes;
	cin >> nbdecas;
	for (int i = 0; i < nbdecas; i++){
		cin >> nbdelignes >> nbdecolonnes;
		vector<vector<int> > matrixorigine(nbdelignes, vector<int>(nbdecolonnes + 1));
		getchar();
		for (int ligne = 0; ligne < nbdelignes; ligne++){
			int nbevt = 0;
			for (int colonne = 1; colonne <= nbdecolonnes; colonne++){
				matrixorigine.at(ligne).at(colonne) = (int) getchar()-48;
				nbevt += matrixorigine.at(ligne).at(colonne);
			}
			matrixorigine.at(ligne).at(0) = nbevt;
			//Enlever \n
			getchar();
		}
		//Print matrix
		bool nonfini = true;
		//print(matrixorigine, nbdelignes, nbdecolonnes);
		vector<vector<int> > matrix(matrixorigine);
		vector<int> dejafait(1,1);
		vector<int> dansArbre(nbdecolonnes+1, 0);
		vector<pair<int, int> > couplesSurs;
		for (int ligne = 0; ligne < nbdelignes; ligne++){
			if (matrix.at(ligne).at(0) == 2){
				vector<int> toto;
				for (int colonne = 1; colonne <= nbdecolonnes; colonne++)
					if (matrix.at(ligne).at(colonne) == 1)
						toto.push_back(colonne);
				if (find(couplesSurs.begin(), couplesSurs.end(), make_pair(toto.at(0), toto.at(1))) == couplesSurs.end())
				{
					dansArbre.at(toto.at(0)) += 1;
					if (dansArbre.at(toto.at(0)) == 2){
						dejafait.push_back(toto.at(0));
						dansArbre.at(0)++;
					}
					dansArbre.at(toto.at(1)) += 1;
					if (dansArbre.at(toto.at(1)) == 2){
						dejafait.push_back(toto.at(1));
						dansArbre.at(0)++;
					}
					couplesSurs.push_back(make_pair(toto.at(0), toto.at(1)));
				}
			}
		}
		/*for (pair<int, int> paire : couplesSurs)
			cout << paire.first << " | " << paire.second << endl;
		cout << "\n \n";

		for (int sum : dansArbre)
			cout << sum << " | ";
		cout << "\n \n";*/
		//Un tour de manege
		for (int prout : dejafait){
			for (int ligne = 0; ligne < nbdelignes; ligne++){
				matrix.at(ligne).at(0) -= matrix.at(ligne).at(prout);
				if (dejafait.at(dejafait.size() - 1) != 1)
					matrix.at(ligne).at(prout) = 0;// matrix.at(ligne).at(dejafait.at(dejafait.size() - 1));
			}
		}
		dejafait.clear();
		//print(matrix, nbdelignes, nbdecolonnes);
		int debutanalyse = 2,cas=2,ligneintersection=1;
		while (dansArbre.at(0)<nbdecolonnes-2){
			for (int ligne = 0; ligne < nbdelignes; ligne++){
				if (matrix.at(ligne).at(0) == 2){
					vector<int> toto;
					for (int colonne = debutanalyse; colonne <= nbdecolonnes; colonne++)
						if (matrix.at(ligne).at(colonne) == 1)
							toto.push_back(colonne);
					if (find(couplesSurs.begin(), couplesSurs.end(), make_pair(toto.at(0), toto.at(1))) == couplesSurs.end())
					{
						dansArbre.at(toto.at(0)) += 1;
						if (dansArbre.at(toto.at(0)) == 2){
							dejafait.push_back(toto.at(0));
							dansArbre.at(0)++;
						}
						dansArbre.at(toto.at(1)) += 1;
						if (dansArbre.at(toto.at(1)) == 2){
							dejafait.push_back(toto.at(1));
							dansArbre.at(0)++;
						}
						couplesSurs.push_back(make_pair(toto.at(0), toto.at(1)));
					}
				}

				for (int prout : dejafait){
					ligneintersection = 0;
					for (int ligne = 0; ligne < nbdelignes; ligne++){
						matrix.at(ligne).at(0) -= matrix.at(ligne).at(prout);
						matrixorigine.at(ligne).at(0) -= matrixorigine.at(ligne).at(prout);
						if (dejafait.at(dejafait.size() - 1) != 1){
							matrix.at(ligne).at(prout) = 0;// matrix.at(ligne).at(dejafait.at(dejafait.size() - 1));
							matrixorigine.at(ligne).at(prout) = 0;
						}
					}
				}
			}
			/*for (pair<int, int> paire : couplesSurs)
				cout << paire.first << " | " << paire.second << endl;
			cout << "\n \n";*/
				if (dejafait.size() == 0){
					if (debutanalyse == 1){
						//Changement de matrix
						if (ligneintersection < nbdelignes)
							for (int ligne = 0; ligne < nbdelignes; ligne++){
								int nbevt = 0;
								for (int colonne = 1; colonne <= nbdecolonnes; colonne++){
									matrix.at(ligne).at(colonne) = matrixorigine.at(ligne).at(colonne)*matrixorigine.at(ligneintersection).at(colonne);
									nbevt += matrix.at(ligne).at(colonne);
								}
								matrix.at(ligne).at(0) = nbevt;
							}
						ligneintersection++;
					}
					else{ debutanalyse = 1; }
				}
				dejafait.clear();
				//print(matrix, nbdelignes, nbdecolonnes);
			}
		
			resultat(couplesSurs, nbdecolonnes);
			if (i < nbdecas-1)
				cout << "\n";
		/*for (pair<int, int> paire : couplesSurs)
			cout << paire.first << " | " << paire.second << endl;
		cout << "\n \n";*/
	}
	
    return 0;
}
