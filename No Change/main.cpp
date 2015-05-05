#include <iostream>
#include <list>
//#include<string>
using namespace std;

void adem(int montant, list<int> b){
	int paye = 0, prix,compt,compteurmax=100000;
	for (list<int> ::iterator it = b.begin(); it != b.end(); ++it){
		prix = *it; compt = 0;
		while (paye < montant && compt<compteurmax){
			paye += prix;
			compt++;
			//cout << "Payé :" << paye << endl;
		}
		if (paye == montant){
			cout << "YES\n" << endl;
			return;
		}
		paye -= prix;
		compt--;
		compteurmax = compt;
	}
	cout << "NO\n"<<endl;
}


int main(){
	int nbinput,nbpiece,montant;
	cin >> nbinput;
	for (int i = 0; i < nbinput; i++){
		cin >> montant;
		cin >> nbpiece;
		list<int> pieces;
		for (int j = 0; j < nbpiece; j++){
			int a;
			cin >> a;
			pieces.push_back(a);
			cout << a;
		}
		adem(montant, pieces);
	}
	/*while (true){
		string stop;
		getline(cin, stop);
		if (stop.compare("stop") == 0)
			return 0;
	}*/
}