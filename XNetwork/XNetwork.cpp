////	XNetwork (RECU)

#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main(){
	/*Recuperer les entrees*/
    int nb,nbinput,id,swag,monami,src,dst;
    cin>>nbinput;
    for(int i=0;i<nbinput;i++){
        cin>>nb;
        vector<pair<int,vector<int> > > monreseau;
        vector<vector< int> > memoire (nb,vector<int>());
        bool trouve=false;
        for(int bf=0;bf<nb;bf++){
            cin>>id>>swag;
            for(int amis=0;amis<swag;amis++){
                cin>>monami;
                memoire.at(id).push_back(monami);
            }
        }
        cin>>src>>dst;
        monreseau.push_back(make_pair(0,vector<int>(1,src)));
        int index=0;
        if(find(monreseau.at(index).second.begin(),monreseau.at(index).second.end(),dst)!=monreseau.at(index).second.end())
            trouve=true;
		/*Parcourir les amis des amis et ainsi de suite jusqu'a trouver la destination
		Noter le nombre d'iteration qui sera la distance source-destination
		*/
        while(!trouve){
            //cout<<"Iteration n:"<<index<<"  ";
            monreseau.push_back(make_pair(index+1,vector<int>()));
            for(int toto:monreseau.at(index).second){
                monreseau.at(index+1).second.insert(monreseau.at(index+1).second.end(),memoire.at(toto).begin(),memoire.at(toto).end());
                //cout<<"Salut ";
                /*for(int prout:memoire.at(toto)){
                   cout<<prout<<"|";
                 }
                cout<<endl;
                cout<<toto<<" | ";*/
            }
           // cout<<endl;
            index++;
            if(find(monreseau.at(index).second.begin(),monreseau.at(index).second.end(),dst)!=monreseau.at(index).second.end())
                trouve=true;
        }
        cout<<src<<" "<<dst<<" "<< index-1<<endl;
        if(i<nbinput-1)
            cout<<"\n";
    }
}
