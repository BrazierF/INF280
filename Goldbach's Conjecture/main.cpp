
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <map>
using namespace std;
map<int, bool> mapp;



bool isprime(int a){
	if (a % 2 == 0){
		mapp.insert(pair<int, bool>(a, false));
		return false;
	}
	for (int i = 3; i*i <= a; i++)
		if (a%i == 0){
			mapp.insert(pair<int,bool>(a,false));
			return false;
		}
	mapp.insert(pair<int, bool>(a, true));
	return true;
}
bool isPrimev2(int a){
	std::map<int, bool>::iterator it = mapp.find(a);
	if (it != mapp.end())
		return it->second;
	else return(isprime(a));
}
void goldbach(int nombre){
	for (int i = 3; i < nombre; i++)
		if (isPrimev2(i))
			if (isPrimev2(nombre - i)){
				cout << nombre << " = " << i << " + " << nombre - i << endl;
				return;
			}
}
int main(){
	int nombre;
	cin >> nombre;
	while (nombre != 0){
		goldbach(nombre);
		cin >> nombre;
	}
}

