
// Mice.cpp : main project file.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tableau[101][101];
vector<int> toto;
int min(int a, int b){
    if (a == -1 || b < a)
        return b;
    else
        return a;
}
void printtab(int nbcase){
    for (int i = 1; i <= nbcase; i++){
        for (int j = 1; j <= nbcase; j++){
            cout << " | " << tableau[i][j];
        }
        cout << endl;
    }
}
void set(){
    for (unsigned int i = 0; i < 101; i++)
        for (unsigned int j = 0; j < 101; j++)
            if (i!=j)
            tableau[i][j] = -1;
            else tableau[i][i] = 0;
}
int trouverpivot(vector<int> &toto, int nbcase, int casesortie){
    int mini, premierindice, bondice;bool trouve=false;
    for (int i = 0; i <= nbcase; i++){
        vector<int>::iterator it = std::find(toto.begin(), toto.end(), i);
        if (tableau[i][casesortie] != -1 && it == toto.end()){
            mini = (tableau[i][casesortie]);
            //cout << "Pivot :" << i << endl;
            premierindice = i;
            bondice = i;
            trouve=true;
            break;
        }
    }
    if(!trouve)
        return -1;
    for (int i = premierindice; i <= nbcase; i++){
        vector<int>::iterator it = find(toto.begin(), toto.end(), i);
        if (tableau[i][casesortie] < mini&&tableau[i][casesortie] != -1 && it == toto.end()){
            mini = (tableau[i][casesortie]);
            bondice = i;
        }
    }
    toto.push_back(bondice);
    return bondice;
}
void majtab(int nbcase,int casesortie){
    toto.clear();
    do{
        int indice = trouverpivot(toto, nbcase, casesortie);
        if(indice==-1)
            return;
        //cout<<"Indice"<<indice<<endl;
       // printtab(nbcase);
        //cout << "Pivot :" << indice << endl;
        for (unsigned int i = 1; i <= nbcase; i++){
            vector<int>::iterator it = find(toto.begin(), toto.end(), i);
            if (tableau[i][indice] != -1 && it == toto.end())
                tableau[i][casesortie] = min(tableau[i][casesortie],tableau[i][indice] + tableau[indice][casesortie]);
        }
    } while (toto.size() != nbcase);
}



int resultab(int temps,int nbcase,int casesortie){
    int compteur = 0;
    for (int i = 1; i <= nbcase; i++)
        if (tableau[i][casesortie] <= temps&&tableau[i][casesortie]>=0)
            compteur++;
    return compteur;
}
int main()
{
    int nbcase, casesortie, temps, nbconne, nbinput,src,dst,lng;
    cin >> nbinput;
    for (unsigned int i = 0; i < nbinput; i++){
        set();
        cin >> nbcase >> casesortie >> temps >> nbconne;
        //cout<< nbcase<<casesortie<<temps<<nbconne;
        for (unsigned j = 0; j < nbconne; j++){
            cin >> src >> dst >> lng;
            tableau[src][dst] = lng;
        }
        majtab(nbcase,casesortie);
       // printtab(nbcase);
        cout << resultab(temps, nbcase, casesortie)<<endl;
        if(i!=nbinput-1)
            cout<<"\n";
    }
    return 0;
}
