// Wifi.cpp : main project file.

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

bool founction(float intervalle, vector<int> &adresses,int nbspot){
	bool aubout = true;
	int adprems = adresses.at(0),spot=1;
	for (int adresse : adresses){
		if (adresse > adprems + intervalle){
			adprems = adresse;
			spot++;
		}
		if (spot > nbspot){
			aubout = false;
			break;
		}
	}
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
		vector<float> spot;
		for (int maison = 0; maison < nbmaison; maison++){
			int adresse;
			cin >> adresse;
			adresses.at(maison)=adresse;
		}
		sort(adresses.begin(), adresses.end());
		float intervalledicho=adresses.at(adresses.size()-1)-adresses.at(0);
		float milieu = intervalledicho / 2;
		bool gauche;
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
		cout << fixed<<setprecision(1)<<milieu/2<<endl;
	}
    return 0;
}
