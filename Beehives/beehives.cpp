#include <iostream>
#include <vector>;
#include <algorithm>
using namespace std;

int main(){
    int nbinput;
    cin >> nbinput;
    for(int i =0; i<nbinput;i++){
        int nbarbres,croisement_debut,nbchemins,croisement_fin,compteur=1,src,dst;
        cin>>nbarbres>>nbchemins;
        vector<vector<int> > memoire(nbchemins+1,vector<int>());
        for(int chemin=1;chemin<=nbchemins;chemin++){
            cin>>src>>dst;
            memoire.at(src).push_back(dst);
            memoire.at(dst).push_back(src);
        }
        bool trouve=false;
        src=1;dst=1;
        for(int src=0;src<nbarbres;src++){
            dst=src;
            vector<pair<int,vector<int> > > monreseau;
            monreseau.push_back(make_pair(0,vector<int>(1,src)));
            int index=0;
            /* if(find(monreseau.at(index).second.begin(),monreseau.at(index).second.end(),dst)!=monreseau.at(index).second.end())
            trouve=true;*/
            monreseau.push_back(make_pair(index+1,vector<int>()));
            monreseau.at(1).second.insert(monreseau.at(index+1).second.end(),memoire.at(src).begin(),memoire.at(src).end());
            cout<<"Iteration n:"<<index<<"  ";
            for(auto conseil:monreseau.at(0).second)
                cout<<conseil <<" | ";
            cout<<endl;
            index++;
            monreseau.push_back(make_pair(index+1,vector<int>()));
            for(int voisin : monreseau.at(1).second)
                for(int voisinduvoisin : memoire.at(voisin))
                    if(voisinduvoisin!=src)
                        monreseau.at(2).second.push_back(voisinduvoisin);
            cout<<"Iteration n:"<<index<<"  ";
            for(auto conseil:monreseau.at(1).second)
                cout<<conseil <<" | ";
            cout<<endl;
            index++;
            while(!trouve){
                cout<<"Iteration n:"<<index<<"  ";
                monreseau.push_back(make_pair(index+1,vector<int>()));
                for(int toto:monreseau.at(index).second){
                    monreseau.at(index+1).second.insert(monreseau.at(index+1).second.end(),memoire.at(toto).begin(),memoire.at(toto).end());
                    /*cout<<"Salut ";
                for(int prout:memoire.at(toto)){
                    cout<<prout<<"|";
                }
                cout<<endl;*/
                    cout<<toto<<" | ";
                }
                cout<<endl;
                index++;
                if(find(monreseau.at(index).second.begin(),monreseau.at(index).second.end(),dst)!=monreseau.at(index).second.end()){
                    cout<<"Trouve a l'indice "<<index <<" parce que <<find(monreseau.at(index).second.begin(),monreseau.at(index).second.end(),dst)!=monreseau.at(index).second.end()";
                    trouve=true;
                }
                if(index>=nbarbres){
                    trouve=true;
                }
                cout<<"Trouve a l'indice "<<index <<" parce que <<index>=nbarbres"<<endl;
            }
            //cout<<src<<" "<<dst<<" "<< index-1<<endl;
            cout<<"Iteration n:"<<index<<"  ";
            for(int toto:monreseau.at(index).second)
                cout<<toto<<" | ";
            cout<<endl;
        }
        if(i<nbinput-1)
            cout<<"\n";

    }
    return 0;
}
