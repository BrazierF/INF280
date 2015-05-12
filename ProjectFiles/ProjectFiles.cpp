// ProjectFiles.cpp : main project file.
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <utility>


using namespace std;

int main()
{
	int nbinput, nbtaches, nbdependances,numtache,nbdeptache,tachedep,compteur =0;
	cin >> nbinput;
	//cout << nbinput;
	for (int i = 0; i < nbinput; i++){
		compteur = 0;
		cin >> nbtaches >> nbdependances;
		//cout << nbtaches << nbdependances;
		vector<pair<int, pair<bool, vector<int> > > > vecteurres(nbtaches + 1, pair<int, pair<bool, vector<int> > >(0, pair<bool, vector<int> >(true, vector<int>())));
		for (int j = 0; j < nbdependances; j++){
			cin >> numtache >> nbdeptache;
			//cout << "Num tache" << numtache << nbdeptache;
			vecteurres.at(numtache).second.first = false;
			for (int k = 0; k < nbdeptache; k++){
				cin >> tachedep;
				//cout << "Tache dep" << tachedep;
				vecteurres.at(numtache).second.second.push_back(tachedep);
			}
		}	
		bool encoreuntour = true;
		while (encoreuntour){
			encoreuntour = false;
			vector<int> achangerdanscetour;
			for (int i = 1; i <= nbtaches; i++){
				pair<int, pair<bool, vector<int> > > x = vecteurres.at(i);
				if (!x.second.first){
					encoreuntour = true;
					x.second.first = true;
					for (auto y : x.second.second){
						if (!vecteurres.at(y).second.first)
							x.second.first = false;
					}
					if (x.second.first){
						x.second.first = false;
						achangerdanscetour.push_back(i);
					}
				}
			}
			compteur++;
			for (auto nb : achangerdanscetour){
				vecteurres.at(nb).first = compteur;
				vecteurres.at(nb).second.first = true;
			}
			for (auto afficher : vecteurres)
				cout << " | " << afficher.first;
			cout << endl;
		}
		cout << endl;
		for (int bon = 0; bon <= compteur; bon++)
			for (int toto = 1; toto <= nbtaches; toto++)
				if (vecteurres.at(toto).first == bon)
					cout << toto << " ";
		cout << endl;
		if (i < nbinput - 1)
			cout << "\n";
	}
    return 0;
}
