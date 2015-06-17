//Tomato.cpp

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

int instructionsuivante(int a,vector<string> & prgm,vector<pair<int,int> > & loops,vector<pair<int,pair<int,int> > > & ifgos){
    if(a>=prgm.size())
        a=0;
    string cmd=prgm.at(a);
    stringstream s;
    switch(cmd.at(0)){
    case 'd':
        return -1;
        break;
    case 'i' :
        return (a+1);
        break;
    case 'j':{
        cmd=cmd.substr(4);
        cmd=cmd.substr(cmd.find_first_not_of(" \t"));
        //cout<<"Jump"<< atoi(cmd.c_str())-1<<endl;
        bool trouve = false;
        for(auto toto: ifgos){
            if(toto.first==a){
                if(loops.size()>1){
                    if(toto.second==loops.at(loops.size()-1)){
                        return(-2);
                    }else{
                        toto.second=loops.at(loops.size()-1);
                    }
                }else{
                    if(toto.second==make_pair(-1,-1)){
                        return(-2);
                    }else{
                        toto.second=make_pair(-1,-1);
                    }
                }
            trouve=true;
            break;
            }
        }
        if(!trouve){
            if(loops.size()!=0)
                ifgos.push_back(make_pair(a,loops.at(loops.size()-1)));
            else ifgos.push_back(make_pair(a,make_pair(-1,-1)));
        }
        return atoi(cmd.c_str())-1;
        break;
    }
    case 'l':{
        int nbfois,retour;
        s<<cmd;
        s>>cmd>>retour>>nbfois;
        if(nbfois>=2){
            if(loops.size()!=0){
                if(loops.at(loops.size()-1).first==a){
                    if(loops.at(loops.size()-1).second==1){
                        loops.pop_back();
                        retour=a+1;
                    }else{
                        loops.at(loops.size()-1).second--;
                    }
                }else {
                    loops.push_back(make_pair(a,nbfois-1));
                }
            }else{
                loops.push_back(make_pair(a,nbfois-1));
            }
        }else{
            retour = a+1;
        }
        return retour;
        break;
    }
    case 'p':{
          //cout<<"Pass"<<endl;
        return(a+1);
        break;
        }
    case 'D':
        return -1;
        break;
    case 'I' :
        return (a+1);
        break;
    case 'J':{
        cmd=cmd.substr(4);
        cmd=cmd.substr(cmd.find_first_not_of(" \t"));
        //cout<<"Jump"<< atoi(cmd.c_str())-1<<endl;
        bool trouve = false;
        for(auto toto: ifgos){
            if(toto.first==a){
                if(loops.size()>0){
                    if(toto.second==loops.at(loops.size()-1)){
                        return(-2);
                    }else{
                        toto.second=loops.at(loops.size()-1);
                    }
                }else{
                    if(toto.second==make_pair(-1,-1)){
                        return(-2);
                    }else{
                        toto.second=make_pair(-1,-1);
                    }
                }
            trouve=true;
            break;
            }
        }
        if(!trouve){
            if(loops.size()!=0)
                ifgos.push_back(make_pair(a,loops.at(loops.size()-1)));
            else ifgos.push_back(make_pair(a,make_pair(-1,-1)));
        }
        return atoi(cmd.c_str())-1;
        break;
    }
    case 'L':{
        int nbfois,retour;
        s<<cmd;
        s>>cmd>>retour>>nbfois;
        if(nbfois>=2){
            if(loops.size()>0){
                if(loops.at(loops.size()-1).first==a){
                    if(loops.at(loops.size()-1).second==1){
                        loops.pop_back();
                        retour=a+1;
                    }else{
                        loops.at(loops.size()-1).second--;
                    }
                }else {
                    loops.push_back(make_pair(a,nbfois-1));
                }
            }else{
                loops.push_back(make_pair(a,nbfois-1));
            }
        }else{
            retour = a+1;
        }
        return retour;
        break;
    }
    case 'P':{
          //cout<<"Pass"<<endl;
        return(a+1);
        break;
        }
    default :
        return (a+1);
        break;
    }
}

int main(){
    string ligne;
    while(!cin.eof()){
        vector<string> programme;
        vector<pair<int,int> > loops;
        vector<pair<int,pair<int,int> > > ifgos;
        getline(cin,ligne);
        /*ligne=ligne.substr(ligne.find_first_not_of(" \t"));
        programme.push_back(ligne);*/
        while(ligne.size()>0){
            ligne=ligne.substr(ligne.find_first_not_of(" \t"));
            programme.push_back(ligne);
            getline(cin,ligne);
        }
        /*for(string toto : programme)
            cout<<toto<<endl;
        cout<<"\n\n\n"<<endl;*/
        int instruction=0;
        int compt=0;
        while(instruction>=0){
            cout<<instruction+1<<" "<<programme.at(instruction)<<endl;
            instruction=instructionsuivante(instruction,programme,loops,ifgos);
            compt++;
        }
        if(instruction==-2)
            cout<<"Infinity"<<endl;
        cout <<compt<<endl;
    }
    return 0;
}
