
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

std::vector<std::string> split(std::string str, std::string sep){
	char* cstr = const_cast<char*>(str.c_str());
	char* current;
	std::vector<std::string> arr;
	current = strtok(cstr, sep.c_str());
	while (current != NULL){
		arr.push_back(current);
		current = strtok(NULL, sep.c_str());
	}
	return arr;
}

bool estbon(vector<double> a, int intervalle){
for (unsigned int i = 0; i < a.size() - 1; i++)
	if (a.at(i + 1)-a.at(i) > intervalle/2)
		return false;
return true;
}


int main(){
	std::string toto;
	double nombre;
	vector<string> boum;
	vector<double> nombres;
	double max_size_H = 75.;
	double max_size_L = 100.;
	while (true){
		bool reponse = true;
		double intervalle;
		getline(cin, toto);
		nombres.clear();
		boum = split(toto, " ");
		for (unsigned int i = 0; i < boum.size(); i++){
			nombres.push_back(atof(boum.at(i).c_str()));
		}
		intervalle = nombres.at(2);
		if (nombres.at(0) == 0 && nombres.at(1)==0 && nombres.at(2) == 0)
			return 0;
		getline(cin, toto);
		nombres.clear();
		boum = split(toto, " ");
		for (unsigned int i = 0; i < boum.size(); i++){
			nombres.push_back(atof(boum.at(i).c_str()) - intervalle/2);
			nombres.push_back(atof(boum.at(i).c_str()) + intervalle / 2);
		}
		nombres.push_back(0.);
		nombres.push_back(max_size_H);
		sort(nombres.begin(), nombres.end());
		reponse = estbon(nombres, intervalle);
		getline(cin, toto);
		boum = split(toto, " ");
		nombres.clear();
		for (unsigned int i = 0; i < boum.size(); i++){
			nombres.push_back(atof(boum.at(i).c_str()) - intervalle / 2);
			nombres.push_back(atof(boum.at(i).c_str()) + intervalle / 2);
		}
		nombres.push_back(0.);
		nombres.push_back(max_size_L);
		sort(nombres.begin(), nombres.end());
		reponse = estbon(nombres, intervalle) && reponse;
		if (reponse)
			cout << "YES" << endl;
		else cout << "NO" <<endl;
	}
	
}