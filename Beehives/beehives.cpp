////	Beehives (NON RECU)

#include <iostream>
#include <vector>;
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	/**Récupération des données (entrées) **/
    int nbinput;
    cin >> nbinput;
    for(int i =0; i<nbinput;i++){
        int nbarbres,croisement_debut,nbchemins,croisement_fin,compteur=1,src,dst;
        cin>>nbarbres>>nbchemins;
        vector<vector<int> > memoire(nbchemins+1,vector<int>());
        for(int chemin=1;chemin<=nbchemins;chemin++){
            cin>>src>>dst;
            memoire.at(src).push_back(dst);
            memoire.at(dst).push_back(src);
        }
        bool trouve=false,fin=false;
		vector<int> resultat;
		/**Les arbres sont les sommets d'un graphe et les chemins les aretes
		Je cherche à déterminer le cycle de longueur minimal pour cela je pars de chaque arete,
		je marque ses voisins je supprime les chemins parcourus de mon graphe (provisoire)
		et ainsi de suite avec les voisins suivants jusqu'à rencontrer un sommet marqué.
		On aurait alors trouve un cycle.
		En repetant cela à partir de tous les sommets, on pourra partir d'un sommet qui fait partie de ce cycle minimal
		et on trouve la longueur en additionnant l'indice de marquage des deux sommets consecutifs marques avec un chemin toujours existant entre les deux.
		**/
        for(int src=0;src<nbarbres;src++){
            dst=src;
			//En soi besoin que de 2 vector <int> avant et apres 
            vector<pair<int,vector<int> > > monreseau;
			vector<vector<int> > memoiretempo(memoire);
			vector<pair<int,bool>> marquage(nbarbres, make_pair(0,false));
            monreseau.push_back(make_pair(0,vector<int>(1,src)));
			marquage.at(src)=make_pair(0, true);
            int index=0;
			trouve=true;*/
            monreseau.push_back(make_pair(++index,vector<int>()));
			/*Sommets a distance 1 de la source src*/
			for (int voisin : memoiretempo.at(src))
				if (!marquage.at(voisin).second){
					monreseau.at(index).second.push_back(voisin);
					memoiretempo.at(voisin).erase(find(memoiretempo.at(voisin).begin(), memoiretempo.at(voisin).end(), src));
					marquage.at(voisin) =make_pair(index, true);
				}
            monreseau.push_back(make_pair(index+1,vector<int>()));
			bool findeboucle = false;
			/*Sommets a distance 2 de la source src*/
			for (int voisin : monreseau.at(index).second){
				for (int voisinduvoisin : memoiretempo.at(voisin)){
					if (!marquage.at(voisinduvoisin).second){
						monreseau.at(2).second.push_back(voisinduvoisin);
						memoiretempo.at(voisinduvoisin).erase(find(memoiretempo.at(voisinduvoisin).begin(), memoiretempo.at(voisinduvoisin).end(), voisin));
						marquage.at(voisinduvoisin) = make_pair(index + 1, true);
					}
					else {
						findeboucle = true;
						resultat.push_back(index + 1 + marquage.at(voisinduvoisin).first);
					}
				}
				if (findeboucle){
					trouve = true;
					break;
					
				}
			}
           /* Arriver  à un sommet deja marque */
            index++;
            while(!trouve){
                monreseau.push_back(make_pair(index+1,vector<int>()));
				for (int toto : monreseau.at(index).second){
					for (int voisindetoto : memoiretempo.at(toto)){
						if (!marquage.at(voisindetoto).second){
							monreseau.at(index + 1).second.push_back(voisindetoto);
							memoiretempo.at(voisindetoto).erase(find(memoiretempo.at(voisindetoto).begin(), memoiretempo.at(voisindetoto).end(), toto));
							marquage.at(voisindetoto) = make_pair(index + 1, true);
						}
						else {
							findeboucle = true;
							trouve = true;
							resultat.push_back(index + 1 + marquage.at(voisindetoto).first);
							//break;
						}
						
					}					
					if (findeboucle){
						break;
					}
				}	
                index++;
                if(index>=nbarbres){
                    trouve=true;
					fin = false;
                }     
            }      
        }
		cout << "Case "<<i+1<<": ";
		if (resultat.size() > 0){
			sort(resultat.begin(), resultat.end());
			cout << resultat.at(0) << endl;
			/*for (int toto : resultat)
				cout << toto << " | ";*/
		}
		else
			cout << "impossible " << endl;
    }
    return 0;
}
