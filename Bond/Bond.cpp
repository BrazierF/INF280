// Bond.cpp : main project file.

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


/*
J'ai essaye d'utiliser de Dijkstra en arretant l'algorithme lorsque le pivot a déjà été un point de départ lors d'une execution anterieure
de l'algorithme cependant je n'arrive toujours pas etre sous le temps imparti.
*/
int main()
{
	bool premier = true;
	int nbrues, nbvilles,villeA,villeB,danger,src,dst,q;
	while (scanf("%i",&nbvilles)!=-1){
		if (premier)
			premier = false;
		else cout << endl;
		cin >> nbrues;
        vector<vector<pair<int, int> > > carte(nbvilles+1,vector<pair<int,int> > ());
        vector<bool> dejafait(nbvilles+1,false);
		for (int rue = 0; rue < nbrues; rue++){
			cin >> villeA >> villeB >> danger;
			carte.at(villeA).push_back(make_pair(danger,villeB));
			carte.at(villeB).push_back(make_pair(danger,villeA));
		}
		cin >> q;
        for (int j = 0; j < q; j++){
            cin >> src >> dst;
            vector<bool>marquage(nbvilles + 1, false);
            int nbmarques = 0,resultat;
			vector<pair<int, int> > distance;
            vector<pair<int, int> > distanceresultat;
			marquage.at(src) = true;
			nbmarques++;
            if(dejafait.at(src)){
                for(auto paire : carte.at(src)){
                    if(paire.second==dst){
                        resultat=paire.first;
                        //cout<<"Break"<<endl;
                    }
                }
            }else {
                if (dejafait.at(dst)){
                    for(auto paire : carte.at(dst)){
                        if(paire.second==src){
                            resultat=paire.first;
                            //cout<<"Break"<<endl;
                        }
                    }
                }
                else{
                    for (pair<int, int> voisin : carte.at(src)){
                        distance.push_back(voisin);
                    }
                    int prout =-1,toto = 0;
                    while (nbmarques < nbvilles){
                        //cout<<nbmarques<<endl;
                   // while(prout!=dst){
                        toto=1000000000;
                        pair<int, int> pivot;
                        //Premiere version pivot
                         sort(distance.begin(), distance.end());
                         for (pair<int, int> voisin : distance){
                            if (!marquage.at(voisin.second)){
                                pivot = voisin;
                                marquage.at(voisin.second) = true;
                                nbmarques++;
                                toto=pivot.first;
                                prout = pivot.second;
                                distanceresultat.push_back(pivot);
                                //cout<<"Pivot : "<<prout<<endl;
                                break;
                            }
                        }
                        if(dejafait.at(prout)){
                            for(auto paire : carte.at(prout)){
                                if(paire.second==dst){
                                    resultat=max(toto,paire.first);
                                }
                            }
                           // cout<<"Break"<<endl;
                            break;
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
                 }
            }
            if(nbmarques==nbvilles){
                carte.at(src).clear();
                for (int ville = 1; ville<nbvilles;ville++){
                    carte.at(src).push_back(distanceresultat.at(ville-1));
                    if(distanceresultat.at(ville-1).second==dst){
                        cout<<distanceresultat.at(ville-1).first<<endl;
                    }
                }
            }else{
                cout<<resultat<<endl;
            }
            dejafait.at(src)=true;
           // cout<<toto<<endl;
		}
    }
    //}
   // cout<<"Hello World"<<endl;
    return 0;
}
