// LeftLabyrinth.cpp : main project file.

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool entreeqn(vector<vector<bool>> & labyrinthe, pair<int, int> & casemnt){
	int compteur = 0;
	for (int i = 0; i < 4; i++){
		//cout << i << " | ";
		compteur=compteur << 1;
		//cout << "Compteur   "<<compteur << endl;*/
		if (labyrinthe.at(casemnt.first + ((-1 + 2 * (i / 2))*((i + 1) % 2))).at(casemnt.second + (i % 2 * (1 - 2 * (i / 2))))){
			compteur += 1;
		}
	}
		if (compteur == 5||compteur==10)
			return true;
		else 
			return false;
}


bool casesuivante(vector<vector<bool>> & labyrinthe, pair<int, int> & casemnt, int & direction,bool & arrivee){
	//cout << "Case (" << casemnt.first << "," << casemnt.second << ") Deplacement : "<< direction << endl;
	pair<int, int> caseapres;
	if (direction == 0)
		direction = 3;
	else
		direction = ((direction - 1) % 4);
	for (int i = 0; i < 4; i++){
		//cout << direction << " | ";
		if (labyrinthe.at(casemnt.first + ((-1 + 2 * (direction / 2))*((direction + 1) % 2))).at(casemnt.second + (direction % 2 * (1 - 2 * (direction / 2))))){
			//cout << endl;
			caseapres = make_pair(casemnt.first + ((-1 + 2 * (direction / 2))*((direction + 1) % 2)), casemnt.second + (direction % 2 * (1 - 2 * (direction / 2))));
			if (i == 3){
				casemnt = caseapres;
				return false;
			}
			break;
		}
		direction = (direction + 1) % 4;
	}
	int aregarder = (direction + 1) % 4;
	if (labyrinthe.at(caseapres.first + ((-1 + 2 * (aregarder / 2))*((aregarder + 1) % 2))).at(caseapres.second + (aregarder % 2 * (1 - 2 * (aregarder / 2))))
		&& labyrinthe.at(casemnt.first + ((-1 + 2 * (aregarder / 2))*((aregarder + 1) % 2))).at(casemnt.second + (aregarder % 2 * (1 - 2 * (aregarder / 2))))){
		arrivee = true;
	}
	casemnt=caseapres;
	return true;
}

int main()
{
	int nbcas,nblignes,nbcolonnes;
	cin >> nbcas;
	for (int cas = 0; cas < nbcas; cas++){
		cin >> nblignes >> nbcolonnes;
		//cout << nblignes << " " << nbcolonnes << endl;
		vector<vector<bool>> labyrinthe(nblignes+2, vector<bool>(nbcolonnes+2, false));
		char lettre;
		for (int ligne = 1; ligne <= nblignes; ligne++){
			for (int colonne = 1; colonne <= nbcolonnes; colonne++){
				cin >> lettre;
				if (lettre == '.'){
					labyrinthe.at(ligne).at(colonne) = true;
				}
				else{
					labyrinthe.at(ligne).at(colonne) = false;
				}
			}
		}
		pair<int, int> depart,entree;
		bool breakpt = false;
		for (int ligne = 1; ligne <= nblignes; ligne++){
			for (int colonne = 1; colonne <= nbcolonnes; colonne++){
				if (labyrinthe.at(ligne).at(colonne) == false){
					depart = make_pair(ligne, colonne-1);
					breakpt = true;
					break;
				}
			}
			if (breakpt){
				break;
			}
		}
		//A changer 
		//depart = make_pair(28,20);
		int deplacement = 2;
		pair<int, int> suivant(depart);
		bool arrivee = false;
		while (!entreeqn(labyrinthe, suivant)){
			casesuivante(labyrinthe, suivant, deplacement,arrivee);
		}
		entree = suivant;
		arrivee = false;
		while (!arrivee&&casesuivante(labyrinthe, suivant, deplacement, arrivee)){}
		//cout << "Case Entree (" << entree.first << "," << entree.second << ")" << endl;

		if (arrivee)
			cout << "YES" << endl;
			//cout << "Case Arrive (" << suivant.first << "," << suivant.second << ")" << endl;
		else
			cout << "NO" << endl;
		if (cas < nbcas - 1)
			cout << endl;
	}
    return 0;
}
