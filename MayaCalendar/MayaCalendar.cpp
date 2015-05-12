// MayaCalendar.cpp : main project file.

//#include "stdafx.h"
#include <iostream>
#include<string>
#include<vector>
int tableau[5] = { 144000, 7200, 360, 20, 1 };
int bezoutjour[2]= {40,-39};
using namespace std;
//ppcm(365,260)=18980
vector<string> split(string &toto, char lettre){
	string acouper = toto;
	unsigned int pos;
	vector<string>retour;
	pos = acouper.find(lettre);
	while ( pos!= string::npos){
		//cout << acouper << endl;
		retour.push_back(acouper.substr(0, pos));
		acouper.erase(0, pos+1);
		pos = acouper.find(lettre);
	}
	retour.push_back(acouper);
	return retour;
}
int convert(vector<int> nombre){
	int resultat = 0;
	for (int i = 0; i < 5; i++)
		resultat += nombre.at(i)*tableau[i];
	return resultat;
}
int debutmois(int a){
	if (a < 19)
		return (-42 + 20 * (a - 1));
	else return 323;
	
}
int convertnomennb(string &toto){
	if (toto.compare("Imix")==0)
		return 1;
	if (toto.compare("Ik") == 0)
		return 2;
	if (toto.compare("Akbal") == 0)
		return 3;
	if (toto.compare("Kan") == 0)
		return 4;
	if (toto.compare("Chikchan") == 0)
		return 5;
	if (toto.compare("Kimi") == 0)
		return 6;
	if (toto.compare("Manik") == 0)
		return 7;
	if (toto.compare("Lamat") == 0)
		return 8;
	if (toto.compare("Muluk") == 0)
		return 9;
	if (toto.compare("Ok") == 0)
		return 10;
	if (toto.compare("Chuen") == 0)
		return 11;
	if (toto.compare("Eb") == 0)
		return 12;
	if (toto.compare("Ben") == 0)
		return 13;
	if (toto.compare("Ix") == 0)
		return 14;
	if (toto.compare("Men") == 0)
		return 15;
	if (toto.compare("Kib") == 0)
		return 16;
	if (toto.compare("Kaban") == 0)
		return 17;
	if (toto.compare("Etznab") == 0)
		return 18;
	if (toto.compare("Kawak") == 0)
		return 19;
	if (toto.compare("Ajaw") == 0)
		return 20;
	if (toto.compare("Pohp") == 0)
		return 1;
	if (toto.compare("Wo") == 0)
		return 2;
	if (toto.compare("Sip") == 0)
		return 3;
	if (toto.compare("Zotz") == 0)
		return 4;
	if (toto.compare("Sek") == 0)
		return 5;
	if (toto.compare("Xul") == 0)
		return 6;
	if (toto.compare("Yaxkin") == 0)
		return 7;
	if (toto.compare("Mol") == 0)
		return 8;
	if (toto.compare("Chen") == 0)
		return 9;
	if (toto.compare("Yax") == 0)
		return 10;
	if (toto.compare("Sak") == 0)
		return 11;
	if (toto.compare("Keh") == 0)
		return 12;
	if (toto.compare("Mak") == 0)
		return 13;
	if (toto.compare("Kankin") == 0)
		return 14;
	if (toto.compare("Muan") == 0)
		return 15;
	if (toto.compare("Pax") == 0)
		return 16;
	if (toto.compare("Kayab") == 0)
		return 17;
	if (toto.compare("Kumku") == 0)
		return 18;
	if (toto.compare("Wayeb") == 0)
		return 19;
	return(-1);
}
int premieroccurence(vector<int> nombre){
	bool trouve = false;
	int resultat = 0; int possibilite = 0;
	vector<int> res, poss;
	resultat = (nombre.at(1)%20)*bezoutjour[1] + ((nombre.at(0)-9)%13)*bezoutjour[0];
	resultat = resultat % 260;
	if (resultat < 0)
		resultat = 260 + resultat;
	//cout << "Modulo 1 "<<resultat % 260 << " = " << nombre.at(1) << "mod 20 x (-39) + (" << nombre.at(0) << "-9) mod 13 * 40" << endl;
	possibilite = nombre.at(2) + debutmois(nombre.at(3))-1;
	//cout << "Modulo 2 "<<possibilite << endl;
	for (int i = 0; i<55; i++)
		poss.push_back(possibilite + 365 * i);
	for (int i = 0; i < 75; i++){
		for (int toto : poss)
			if (resultat + 260 * i == toto)
				return toto;
		res.push_back(resultat + 260 * i);
	}
	/*for (auto x : poss)
		cout << x << " | ";
	cout << endl;
	for (auto x : res)
		cout << x << " | ";
	cout << endl;*/
	return resultat;
}
void format(int a){
	cout << 8 + a / tableau[0]<<".";
	int aecrire =a;
	a -= (a / tableau[0])*tableau[0];
	cout << a/ tableau[1]<<".";
	a -= (a / tableau[1])*tableau[1];
	cout << a/ tableau[2] << ".";
	a -= (a / tableau[2])*tableau[2];
	cout << a/ tableau[3]<<".";
	a -= (a / tableau[3])*tableau[3];
	cout << a/ tableau[4] << endl;
}
int main()
{
	vector<string> output; int avant = 0;
	string toto; vector<int> nombre;
	int nbinput;
		cin >> nbinput;
		for (unsigned int j = 0; j < nbinput; j++){
			//nombre.clear();
			cin >> toto;
			output = split(toto, '.');
			/*nombre.push_back(atoi(output.at(0).c_str()));
			nombre.push_back(convertnomennb(output.at(1)));
			cin >> toto;
			/*output = split(toto, '.');
			nombre.push_back(atoi(output.at(0).c_str()));
			nombre.push_back(convertnomennb(output.at(1)));*/
			/*int resultat = premieroccurence(nombre);
			int compteur = 0;
			while (resultat / tableau[0] < 2){
				compteur++;
				format(resultat);
				resultat += 18980;
				if (compteur > 10)
					break;
			}
			if (j < nbinput - 1)
				cout << endl;*/
	}
    return 0;
}
