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
		vector<int> resultat;
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
		for (int z = 1; z <= nbtaches; z++){
			if (trouve)
				vecteurres.at(z).second.first = false;
			if (vecteurres.at(z).second.first){
				trouve = true;
				resultat.push_back(z);
			}
		}
		bool encoreuntour = true,forcertour=false;
		while (encoreuntour){
			encoreuntour = false;
			int achangerdanscetour;
			for (int m = 1; m <= nbtaches; m++){
				forcertour = false;
				pair<int, pair<bool, vector<int> > > x = vecteurres.at(m);
				if (!x.second.first){
					encoreuntour = true;
					x.second.first = true;
					for (auto y : x.second.second){
						if (!vecteurres.at(y).second.first)
							x.second.first = false;
					}
					if (x.second.first){
						compteur++;
						vecteurres.at(m).first = compteur;
						vecteurres.at(m).second.first = true;
						achangerdanscetour = m;
						resultat.push_back(m);
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
		/*for (int bon = 0; bon < compteur; bon++)
			for (int toto = 1; toto <= nbtaches; toto++)
				if (vecteurres.at(toto).first == bon){
					cout << toto;
					if (compteur == nbtaches - 1)
						cout << " ";
				}
		cout << endl;*/
		for (int prout = 0; prout < resultat.size() - 1; prout++)
			cout << resultat.at(prout)<<" ";
		cout << resultat.at(resultat.size() - 1)<<endl;
		if (i < nbinput - 1)
			cout << "\n";
	}
    return 0;
}
