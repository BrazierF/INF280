// Morse_Match.cpp : main project file.
#include"stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string lettre(char a){
	switch (a){
	case 'A': return(".-");
	case 'B':return("-...");
	case 'C':return("-.-");
	case 'D':return("-..");
	case 'E':return(".");
	case 'F':return("..-.");
	case 'G':return("--.");
	case 'H':return("....");
	case 'I':return("..");
	case 'J':return(".---");
	case 'K':return("-.-");
	case 'L':return(".-..");
	case 'M':return("--");
	case 'N':return("-.");
	case 'O':return("---");
	case 'P':return(".--.");
	case 'Q':return("--.-");
	case 'R':return(".-.");
	case 'S':return("...");
	case 'T':return("-");
	case 'U':return("..-");
	case 'V':return("...-");
	case 'W':return(".--");
	case 'X':return("-..-");
	case 'Y':return("-.--");
	case 'Z':return("--..");
	default: return ("");
	}
	/*A = ".-"; B "-...";	C - . - .D - ..
E	.	F	..-.	G	--.	H	....
I	..	J	.---	K	-.-	L	.-..
M	--	N	-.	O	---	P	.--.
Q	--.-	R	.-.	S	...	T	-
U	..-	V	...-	W	.--	X	-..-
Y	-.--	Z	--..	*/ 	 	 	 
}

string mottomrs(string a){
	string b;
	for (unsigned int i = 0; i < a.size(); i++)
		b.append(lettre(a.at(i)));
	return b;
}
int main()
{
	int nombre,nbdico,compteur=0;
	string line,toto;
	getline(cin, line);
	nombre = atoi(line.c_str());
	//cout << nombre;
		for (int i = 0; i < nombre; i++){		
			getline(cin, line);
			getline(cin, line);
			//cout << "Copie ligne" << line << endl;
			getline(cin, toto);
			nbdico = atoi(toto.c_str());
			//cout << "NB dico : "<< nbdico << endl;
			for (int j = 0; j < nbdico; j++){
				getline(cin, toto);
				//cout << mottomrs(toto) << endl;
				if (line.find(mottomrs(toto)) != string::npos)
					compteur++;
			}
			cout << compteur<<"\n" << endl;
			compteur = 0;
		}
		
		//getline(cin, line);
    return 0;
}
