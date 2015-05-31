////	Crime (RECU)

#include <iostream>
#include <vector>;
#include <algorithm>
using namespace std;


bool cava(vector<int> prout,int nbrue){
    if(prout.size()!=nbrue)
        return false;
    for(int i =0;i<nbrue;i++)
        if(prout.at(i)!=i+1)
            return false;
    return true;
}

int main(){
 
	int nbcroisement=0, nbrues=0;
	/*Recuperation des entrees
	(utilisation de scanf pour trouver la fin de l'entree)*/
	while (scanf("%i",&nbcroisement)!=-1){
		cin >> nbrues;
		int croisement_debut, croisement_fin, compteur = 1;
        vector<vector<int> > croisement(nbcroisement+1,vector<int>());
        for(int rue=1;rue<=nbrues;rue++){
            cin>>croisement_debut>>croisement_fin;
            croisement.at(croisement_debut).push_back(croisement_fin);
            croisement.at(croisement_fin).push_back(croisement_debut);
        }
		/*On parcourt le ou les graphe(s) qui constitue(nt) la ville (les rue sont les aretes et les croisements sont les sommets)
		Pour cela on part d'un sommet on le marque d'une couleur et on donne la couleur opposees a ses voisins si cela n'a pas ete fait
		sinon on verifie qu'il est bien marque de la bonne couleur,si la couleur n'est pas bonne on arrete, la reponse est : 'impossible'
		On recupere le minimum des sommets marque par une couleur et on repete cela a tous les graphes
		Enfin on additionne ces minimums.
		*/
		int nbcas = 0,noir=1,blanc=0,total=0;
		vector<int> lesanciens(1,1);
		vector<int> lesprochains;
		bool macouleur,echec=false;
		vector<pair<bool, bool> >marquage(nbcroisement + 1, make_pair(false, false));
		marquage.at(1) = make_pair(true, false);
		while (nbcas < nbcroisement){
			//si les anciens.size()==0 alors on a parcouru un graphe il faut passer au suivant
			//on cherche donc un sommet non marque dans l'algo
			if (lesanciens.size() == 0){
				for (int compt = 1; compt <= nbcroisement; compt++)
					if (!marquage.at(compt).first){
						lesanciens.push_back(compt);
						marquage.at(compt).first = true;
						break;
					}
					if (noir > blanc)
						total += blanc;
					else total += noir;
				//cout << "Total Provisoire :" << total << endl;
				noir = 1; blanc = 0;
			}
			for (int cas : lesanciens){
				macouleur = marquage.at(cas).second;
				bool prochainautrecouleur = false;
				//cout << cas << " Couleur :" << macouleur << endl;
				for (int prochain : croisement.at(cas)){
					//cout << "Prochain :" << prochain << endl;
					if (!marquage.at(prochain).first){
						prochainautrecouleur = true;
						lesprochains.push_back(prochain);
						//cout << prochain << "(" << !macouleur << ")\n";
						marquage.at(prochain) = make_pair(true, !macouleur);
						if (macouleur)
							noir++;
						else blanc++;				
					}
					else{
						if (marquage.at(prochain).second == macouleur){
							echec = true;
							//cout << "Bug" << endl;
						}
					}
				}
				//cout << "Cas traite " << nbcas;
				//cout << "\n\n\n\n";
				nbcas++;
				
			}
			if (echec){
				cout << "Impossible" << endl;
				break;
			}
			lesanciens = lesprochains;
			/*for (int oto : lesanciens)
				cout << oto << endl;
			cout << endl;*/
			//cout << "tailles anc." << lesanciens.size() << endl;
			lesprochains.clear();
		}
		/*if (aprendre.first)
			if (aprendre.second)
				total += blanc;
			else total += noir;
		else*/
			if (noir > blanc)
				total += blanc;
			else total += noir;
		//cout << "Total :" << total << endl;
		if(!echec)
			cout << total<<endl;
	}
    return 0;
}
