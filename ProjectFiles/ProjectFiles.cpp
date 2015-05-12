// ProjectFiles.cpp : main project file.
//#include "stdafx.h"
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
		bool trouve = false;
		for (int i = 1; i <= nbtaches; i++){
			if (trouve)
				vecteurres.at(i).second.first = false;
			if(vecteurres.at(i).second.first)
				trouve = true;
		}
		bool encoreuntour = true,forcertour=false;
		while (encoreuntour){
			encoreuntour = false;
			int achangerdanscetour;
			for (int i = 1; i <= nbtaches; i++){
				forcertour = false;
				pair<int, pair<bool, vector<int> > > x = vecteurres.at(i);
				if (!x.second.first){
					encoreuntour = true;
					x.second.first = true;
					for (auto y : x.second.second){
						if (!vecteurres.at(y).second.first)
							x.second.first = false;
					}
					if (x.second.first){
						compteur++;
						vecteurres.at(i).first = compteur;
						vecteurres.at(i).second.first = true;
						achangerdanscetour = i;
						forcertour = true;
						break;
					}
				}
				if (forcertour)
					break;
			}
			/*for (auto afficher : vecteurres)
				cout << " | " << afficher.first;
			cout << endl;*/
		}
		//cout << endl;
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
