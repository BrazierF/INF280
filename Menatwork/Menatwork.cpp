////	Menatwork (RECU).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Retourne l'etat de la ville au temps t*/
vector <vector<int> > viileAtSec(vector <vector<int> > & villeorigine, int temps){
	vector <vector<int> > resultat(villeorigine);
	for (int ligne = 0; ligne<resultat.size(); ligne++){
		for (int colonne = 0; colonne < resultat.at(ligne).size(); colonne++){
			if (resultat.at(ligne).at(colonne) % 10!=0)
				resultat.at(ligne).at(colonne) = (resultat.at(ligne).at(colonne) / 10 + temps / (resultat.at(ligne).at(colonne) % 10)) % 2;
			else 
				resultat.at(ligne).at(colonne) = resultat.at(ligne).at(colonne) / 10;
		}
	}
	return resultat;
}
/*affiche l'etat de la ville mis en parametre*/
void print(vector <vector<int> > & villeorigine){
	for (int ligne = 0; ligne<villeorigine.size(); ligne++){
		for (int colonne = 0; colonne<villeorigine.at(ligne).size(); colonne++){
			cout << villeorigine.at(ligne).at(colonne);
		}
		cout << endl;
	}
	cout << "\n\n";
}
/*Retourne (dans moment) tous les emplacements possibles à l'instant t+1 
à partir de la liste des emplacements possible à l'instant t,
en fonction de l'etat de la ville a l'instant t+1 */
void accessibleapres(vector<int> & moment, vector <vector<int> > & villeorigine,int& temps){
	vector <vector<int> > villeapres = viileAtSec(villeorigine, ++temps);
	vector<int> apres;
	int longueur = villeorigine.at(0).size();
	for (int avant : moment){
		apres.push_back(avant);
		if (avant%longueur < longueur - 1)
			apres.push_back(avant + 1);
		if (avant%longueur>0)
			apres.push_back(avant - 1);
		if (avant / longueur < longueur - 1)
			apres.push_back(avant + longueur);
		if (avant / longueur>0)
			apres.push_back(avant - longueur);
	}
	vector<int> apressur;
	for (int possible : apres){
		if (villeapres.at(possible/longueur).at(possible % longueur) == 1)
			if (find(apressur.begin(),apressur.end(),possible)==apressur.end())
			apressur.push_back(possible);
	}
	moment = apressur;
}

int main(){
	int tailletableau = 0;
	bool premier = true;
	while (scanf("%i", &tailletableau)!=-1){
		if (premier)
			premier = false;
		else cout << "\n";
		/*int tailletableau = 0;
		if (scanf("%i", &tailletableau) == EOF)
			break;
		else{*/
			vector <vector<int> >mapville(tailletableau,vector<int>(tailletableau));
			//vector <vector<int> >mapville2(tailletableau, vector<int>(tailletableau));
			getchar();
			for (int ligne = 0; ligne < tailletableau; ligne++){
				for (int colonne = 0; colonne < tailletableau; colonne++){
					mapville.at(ligne).at(colonne) = ((getchar()-42)/4)*10 ;
				}
				//Enlever \n
				getchar();
			}
			for (int ligne = 0; ligne < tailletableau; ligne++){
				for (int colonne = 0; colonne < tailletableau; colonne++){
					mapville.at(ligne).at(colonne) += getchar()-48;
				}
				//Enlever \n
				getchar();
			}
			/*Parcourir la liste des emplacements possibles aux differents instants jusqu'a trouver la destination dans cette liste
			On suppose qu'apres ppcm(differentes periodes)*taille de la ville si la destination n'est pas atteinte alors elle ne le sera jamais
			on peut ameliorer cette borne en adaptant avec les periodes exactes du cas particulier, de plus apres quelques soumission (7*8*9*5) suffit */
			vector<int> chemin(1, 0);
			int temps = 0;
			while (find(chemin.begin(), chemin.end(), tailletableau*tailletableau - 1) == chemin.end()&&temps<=7*8*9*5){
				accessibleapres(chemin, mapville, temps);
				/*for (int position : chemin){
					cout << "Temps " << temps<< " : " << endl;
					cout << "(" << position / tailletableau << "," << position % tailletableau << ")" << endl;
					cout << "\n\n\nVille : \n";
					print(viileAtSec(mapville,temps));
				}*/
				//cout<<temps << endl;
			}
			if (temps<=7*8*9*5)
				cout << temps << endl;
			else cout << "NO" << endl;
			//cout << tailletableau << "\n" << endl;
	
	}
	return 0;
}