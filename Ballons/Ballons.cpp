//Ballons.cpp
//WRONG ANSWER

#include <utility>
#include<iostream>
#include<algorithm>
#include<vector>
#include <math.h>
#include <iomanip>

using namespace std;

int factorielle[]= {1,2,6,24,120,720};
//normV retourne la distance euclidienne enntre 2 pts
float normV(int x, int y,int z,int a,int b,int c){
    //cout<<pow(x-a,2.0)<<" + "<<pow(y-b,2.0)<<" + "<<pow(c-z,2.0) <<" = "<<sqrt(pow(x-a,2.0)+pow(y-b,2.0)+pow(c-z,2.0))<<endl;
    return sqrt(pow(x-a,2.0)+pow(y-b,2.0)+pow(c-z,2.0));
}

/*Apres la recupération des données,je filtre les points qui ne sont pas dans la boite
 * ensuite grace a la fonction nextpermutation je gonfle les ballons dans l'ordre de la permutation jusqu'a ce qu'il touche un bord
 * ou un autre ballon grace a la fonction min, cependant il semble que mon implementation soit mauvaise
 */
int main(){

    int nbcas=0,nbballons;
    while(true){
        /*if(nbcas!=0)
            cout<<"\n";*/
        nbcas++;
        int xA,xB,yA,yB,zA,zB,x,y,z,vrainbballons=0;
        cin>>nbballons;
        if(nbballons==0)
            break;
        cin>>xA>>yA>>zA>>xB>>yB>>zB;
        if(xA>xB){
            x=xA;
            xA=xB;
            xB=x;
        }
        if(yA>yB){
            y=yA;
            yA=yB;
            yB=y;
        }
        if(zA>zB){
            z=zA;
            zA=zB;
            zB=z;
        }
        vector<vector<int>> ballonscoord;
        vector<float> rayons;
        for(int ballon=0;ballon<nbballons;ballon++){
            cin>>x>>y>>z;
            if((x>xA&&y>yA&&z>zA)&&(x<xB&&x<yB&&z<zB)){
                vrainbballons++;
                ballonscoord.push_back(vector<int>());
                ballonscoord.at(ballonscoord.size()-1).push_back(x);
                ballonscoord.at(ballonscoord.size()-1).push_back(y);
                ballonscoord.at(ballonscoord.size()-1).push_back(z);
                rayons.push_back(0);
            }
        }
        vector<int> perm(vrainbballons,0);
        for(int ballon=0;ballon<vrainbballons;ballon++){
            perm.at(ballon)=ballon;
        }
        int afaire = factorielle[vrainbballons-1];
        float volumemax=(xB-xA)*(yB-yA)*(zB-zA);
        //cout<<"Volume totale : "<<volumemax<<endl;
        //cout<<vrainbballons<<"! = "<<afaire<<endl;
        for(int permutation = 0;permutation<afaire;permutation++){
            /*cout<<"Permutation "<<permutation+1<<endl;
            for(int toto : perm)
                cout<<toto<<" | ";
            cout<<endl;*/
            for(int ballon=0;ballon<vrainbballons;ballon++){
                float rayon;
                x=ballonscoord.at(perm.at(ballon)).at(0);y=ballonscoord.at(perm.at(ballon)).at(1);z=ballonscoord.at(perm.at(ballon)).at(2);
                rayon = min(x-xA,y-yA);
                rayon = min(rayon,(float)z-zA);
                rayon = min(rayon,(float)xB-x);
                rayon = min(rayon,(float)yB-y);
                rayon = min(rayon,(float)zB -z);
                //cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
                //cout<<"Rayon 1 :("<<perm.at(ballon)<<") ="<<rayon<<endl;
                for(int ballon2=0;ballon2<ballon;ballon2++){
                    //cout<<"Distance   : "<<normV(x,y,z,ballonscoord.at(perm.at(ballon2)).at(0),ballonscoord.at(perm.at(ballon2)).at(1),ballonscoord.at(perm.at(ballon2)).at(2))<<endl;
                    rayon=min(normV(x,y,z,ballonscoord.at(perm.at(ballon2)).at(0),ballonscoord.at(perm.at(ballon2)).at(1),ballonscoord.at(perm.at(ballon2)).at(2))-rayons.at(perm.at(ballon2)),rayon);
                }
                 //cout<<"Rayon 2 :("<<perm.at(ballon)<<") ="<<rayon<<endl;
                if(rayon<=0){
                    rayons.at(perm.at(ballon))=0;
                }else {
                    rayons.at(perm.at(ballon))=rayon;
                }

            }
            float volume = (xB-xA)*(yB-yA)*(zB-zA);
            for(float & toto : rayons){
                //cout<<"Volume a enlever"<<4*pow(toto,3.0)/3*3.14159265359<<endl;
                volume-=4*pow(toto,3.0)/3*3.14159265359;
                toto=0.;
            }
            //cout<<sqrt(2)<<endl;
            if(volumemax>volume)
                volumemax=volume;
            //cout<<"\n\n\n";
            next_permutation(perm.begin(),perm.end());
        }
        cout<<"Box "<<fixed<<setprecision(0)<<nbcas<<": "<<volumemax<<"\n"<<endl;
    }
    return 0;
}
