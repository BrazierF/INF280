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
    int nbinput;
    cin >> nbinput;
    for(int i =0; i<nbinput;i++){
        int nbcroisement,croisement_debut,nbrues,croisement_fin,compteur=1;
        cin>>nbcroisement>>nbrues;
        vector<vector<int> > croisement(nbcroisement+1,vector<int>());
        for(int rue=1;rue<=nbrues;rue++){
            cin>>croisement_debut>>croisement_fin;
            croisement.at(croisement_debut).push_back(rue);
            croisement.at(croisement_fin).push_back(rue);
        }
        bool trouve =false;
        while (!trouve){
            vector<int> essai,nonconcluant;
            for(int jesaispas=1;jesaispas<compteur+1;jesaispas++){
                essai.push_back(jesaispas);
                //nonconcluant.insert(nonconcluant.end(),croisement.at(jesaispas).begin(),croisement.at(jesaispas).end());
                for(int poto :croisement.at(jesaispas))
                    nonconcluant.push_back(poto);
                //break;
            }
            sort(nonconcluant.begin(),nonconcluant.end());
            //if(cava(nonconcluant,nbrues)){
                for(int poto :nonconcluant)
                    cout<<poto<<"|";
                break;
            //}
            compteur++;
        }
        for(auto toto: croisement){
            for(int poto : toto)
                cout<<poto<<"|";
            cout<<"\n";
        }
    }
    return 0;
}
