// Wifi.cpp : main project file.
//ACCEPTED
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
/*
J'opere par dichotomie, sur la distance maximale D entre deux maisons couverte par le spot le plus proche
On commence par la premiere maison de la rue, on met un spot a D/2 et a partir de la maison situee au dela de D apres la premiere maison
on remet un autre spot a D/2 apres celle -ci
soit on n'a pas assez de spot wifi et il fauta augmenter cette distance
soit on a reussi a couvrir toutes les maison avec cette distance alors celle ci est trop grande et on la diminue
On arrete lorsque l'intervalle de la dichotomie est plus petit que .1
*/
bool founction(float intervalle, vector<int> &adresses,int nbspot){
	bool aubout = true;
	int adprems = adresses.at(0),spot=1;
    //cout<<adprems+intervalle/2<<endl;
	for (int adresse : adresses){
		if (adresse > adprems + intervalle){
			adprems = adresse;
            //cout<<adprems+intervalle/2<<endl;
			spot++;
		}
		if (spot > nbspot){
			aubout = false;
			break;
		}
	}
    //cout<<"\n\n";
	return aubout;
}

int main()
{
	int nbcas;
	cin >> nbcas;
	for (int cas = 0; cas < nbcas; cas++){
		int nbwifispot, nbmaison;
		cin >> nbwifispot >> nbmaison;
		//cout << "Ici";
		vector<int>adresses(nbmaison);
		for (int maison = 0; maison < nbmaison; maison++){
			int adresse;
			cin >> adresse;
			adresses.at(maison)=adresse;
		}
		sort(adresses.begin(), adresses.end());
		float intervalledicho=adresses.at(adresses.size()-1)-adresses.at(0);
		float milieu = intervalledicho / 2;
		bool gauche;
        if(nbwifispot>=nbmaison)
            milieu=0;
        else{
            while (intervalledicho > .1){
                gauche=founction(milieu, adresses, nbwifispot);
                intervalledicho -= intervalledicho / 2;
                if (gauche){
                    milieu = milieu - intervalledicho;
                }
                else{
                    milieu = milieu + intervalledicho;
                }
            }
        }
		cout << fixed<<setprecision(1)<<milieu/2<<endl;
	}
    return 0;
}
