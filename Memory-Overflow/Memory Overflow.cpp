#include <iostream>
#include <string>

using namespace std;

int max(int a,int b){
    if(a>b)
        return a;
    else return b;
}

int main(){
    int nbcas;
    cin >>nbcas;
    for(int cas=0;cas<nbcas;cas++){
        int nbjours,memoire,compteur=0;
        string calend;
        //cout<<"Totot"<<endl;
        cin>>nbjours>>memoire>>calend;
        for(int pers=1;pers<nbjours;pers++){
            for(int jouravant=1;jouravant<=memoire;jouravant++){
                if(calend.at(max(pers-jouravant,0))==calend.at(pers)){
                    compteur++;
                    break;
                }
            }
        }
        cout<<"Case "<<cas+1<<": "<<compteur<<endl;
    }
    return 0;
}
