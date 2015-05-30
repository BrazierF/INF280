// Bond.cpp : main project file.

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//for (int i = 0; i < 5; i++){
	bool premier = true;
	int nbrues, nbvilles,villeA,villeB,danger,src,dst,q;
	while (scanf("%i",&nbvilles)!=-1){
		if (premier)
			premier = false;
		else cout << endl;
		cin >> nbrues;
		//cin >> nbvilles >> nbrues;
		/*vector<bool>marquage(nbvilles+1, false);
		int nbmarques = 0;
		vector<pair<int, int> > distance;// (nbvilles, make_pair(0, 0));*/
		vector<vector<pair<int, int> > > carte(nbvilles+1,vector<pair<int,int> > ());
		for (int rue = 0; rue < nbrues; rue++){
			cin >> villeA >> villeB >> danger;
			carte.at(villeA).push_back(make_pair(danger,villeB));
			carte.at(villeB).push_back(make_pair(danger,villeA));
		}
		cin >> q;
		for (int j = 0; j < q; j++){
			cin >> src >> dst;
			vector<bool>marquage(nbvilles + 1, false);
			int nbmarques = 0;
			vector<pair<int, int> > distance;
			marquage.at(src) = true;
			nbmarques++;
			for (pair<int, int> voisin : carte.at(src)){
				distance.push_back(voisin);
			}
			while (nbmarques < nbvilles){
				sort(distance.begin(), distance.end());
				pair<int, int> pivot;
				for (pair<int, int> voisin : distance){
					if (!marquage.at(voisin.second)){
						pivot = voisin;
						marquage.at(voisin.second) = true;
						nbmarques++;
						break;
					}
				}
				for (pair<int, int> voisin : carte.at(pivot.second)){
					int distanceactuelle;
					for (auto prout : distance){
						if (prout.second == voisin.second){
							distanceactuelle = prout.first;
							break;
						}
					}
					if (!marquage.at(voisin.second)){
						distance.push_back(make_pair(min(distanceactuelle,max(pivot.first,voisin.first)),voisin.second));
					}
				}
			}
			for (auto fini : distance){
				if (fini.second == dst){
					cout << fini.first << endl;
					break;
				}
			}
		}
	}
   // cout<<"Hello World"<<endl;
    return 0;
}
