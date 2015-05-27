#include <iostream>
#include <vector>;
#include <algorithm>
#include <utility>
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
        bool trouve=false,fin=false;
        src=1;dst=1;
		vector<int> resultat;
        for(int src=0;src<nbarbres;src++){
            dst=src;
			//En soi besoin que de 2 vector <int> avant et apres 
            vector<pair<int,vector<int> > > monreseau;
			vector<vector<int> > memoiretempo(memoire);
			vector<pair<int,bool>> marquage(nbarbres, make_pair(0,false));
            monreseau.push_back(make_pair(0,vector<int>(1,src)));
			marquage.at(src)=make_pair(0, true);
            int index=0;
            /* if(find(monreseau.at(index).second.begin(),monreseau.at(index).second.end(),dst)!=monreseau.at(index).second.end())
            trouve=true;*/
            monreseau.push_back(make_pair(++index,vector<int>()));
            //monreseau.at(1).second.insert(monreseau.at(index+1).second.end(),memoire.at(src).begin(),memoire.at(src).end());
			for (int voisin : memoiretempo.at(src))
				if (!marquage.at(voisin).second){
					monreseau.at(index).second.push_back(voisin);
					memoiretempo.at(voisin).erase(find(memoiretempo.at(voisin).begin(), memoiretempo.at(voisin).end(), src));
					marquage.at(voisin) =make_pair(index, true);
				}
            /*cout<<"Iteration n:"<<index<<"  ";
            for(auto conseil:monreseau.at(0).second)
                cout<<conseil <<" | ";
            cout<<endl;
			cout << "Iteration n: (avt manip)" << index << "  ";
			for (auto conseil : monreseau.at(1).second)
				cout << conseil << " | ";
			cout << endl;*/
            monreseau.push_back(make_pair(index+1,vector<int>()));
			bool findeboucle = false;
			for (int voisin : monreseau.at(index).second){
				//cout << "Ici 1   "<< voisin<<" \n";
				for (int voisinduvoisin : memoiretempo.at(voisin)){
					//cout << "Ici 2" << voisinduvoisin << "\n";
					if (!marquage.at(voisinduvoisin).second){
						//cout << "Ici 3 \n";
						monreseau.at(2).second.push_back(voisinduvoisin);
						//cout << "Voisin "<<voisin<<"\nVosinduvoisin "<<voisinduvoisin<<endl;
						memoiretempo.at(voisinduvoisin).erase(find(memoiretempo.at(voisinduvoisin).begin(), memoiretempo.at(voisinduvoisin).end(), voisin));
						//cout << "Ici 3 \n";
						marquage.at(voisinduvoisin) = make_pair(index + 1, true);
					}
					else {
						findeboucle = true;
						resultat.push_back(index + 1 + marquage.at(voisinduvoisin).first);
						//break;
						/*cout << "Resultat BOREERK " << endl;
						for (int res : resultat)
							cout << res << " | ";*/
					}
				}
				if (findeboucle){
					trouve = true;
					break;
					
				}
			}
           /* cout<<"Iteration n:"<<index<<"  ";
           for(auto conseil:monreseau.at(1).second)
                cout<<conseil <<" | ";
            cout<<endl;*/
            index++;
            while(!trouve){
                //cout<<"Iteration n:"<<index<<"  ";
                monreseau.push_back(make_pair(index+1,vector<int>()));
				for (int toto : monreseau.at(index).second){
					for (int voisindetoto : memoiretempo.at(toto)){
						if (!marquage.at(voisindetoto).second){
							monreseau.at(index + 1).second.push_back(voisindetoto);
							memoiretempo.at(voisindetoto).erase(find(memoiretempo.at(voisindetoto).begin(), memoiretempo.at(voisindetoto).end(), toto));
							marquage.at(voisindetoto) = make_pair(index + 1, true);
						}
						else {
							findeboucle = true;
							trouve = true;
							resultat.push_back(index + 1 + marquage.at(voisindetoto).first);
							//break;
						}
						/*cout<<"Salut ";
					for(int prout:memoiretempo.at(toto)){
					cout<<prout<<"|";*/
					}
					/*
					cout<<endl;
						cout << toto << " | ";
					}*/
					if (findeboucle){
						break;
					}
				}
				//cout <<endl;
                index++;
                if(index>=nbarbres){
                    trouve=true;
					fin = false;
					//cout << "Erreur parce que <<index>=nbarbres" << endl;
                }
				
                
            }      
        }
		cout << "Case "<<i+1<<": ";
		if (resultat.size() > 0){
			sort(resultat.begin(), resultat.end());
			cout << resultat.at(0) << endl;
			/*for (int toto : resultat)
				cout << toto << " | ";*/
		}
		else
			cout << "impossible " << endl;
    }
    return 0;
}
