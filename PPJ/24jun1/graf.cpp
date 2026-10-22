using namespace std;

#include "graf.hpp"

////////////////////////////////////////////////////

Graf(map<int, set<int>>& gr){
  _graf = gr;
  _maxCvor = nadjiMaxCvor(gr);
}

void ispisiUsmereno() const{
  for(int i = 1; i <= _maxCvor; i++){
    for(int j = 1; j <= _maxCvor; j++){
      if((_graf.find(i) != _graf.end()) && (_graf[i].find(j) != _graf[i].end())){
        cout << "1 ";
      }else{
        cout << "0 ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void ispisiNeusmereno() const{
  for(int i = 1; i <= _maxCvor; i++){
    for(int j = 1; j <= _maxCvor; j++){
      if((_graf.find(i) != _graf.end()) && (_graf.find(j) != _graf.end()) && 
          ((_graf[i].find(j) != _graf[i].end()) || _graf[j].find(i) != _graf[j].end())){
        cout << "1 ";
      }else{
        cout << "0 ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void obrisiCvor(int cvor){
  _graf.erase(cvor);
  for(auto par : _graf){
    par.second.erase(cvor);
  }
  _maxCvor = nadjiMaxCvor(_graf);
}

void ispisiSusede(int cvor) const{
  if(_graf.find(cvor) != _graf.end()){
    cout << "[";
    int i = 0;
    for(int sused : _graf[cvor]){
      if(i == _graf[cvor].size() - 1){
        cout << sused;
      }else{
        cout << sused << ", ";
      }
      i++;
    }
    cout << "]" << endl;
  }else{
    cout << "Cvor " << cvor << " ne postoji u grafu :(" << endl;
  }
}

Graf* operator+(Graf& g) const{
  Graf novi(*this);
  
  for(auto& par : g._graf){
    int cvor = par.first;
    auto& susedi = par.second;
    for(int sused : susedi){
      novi._graf[cvor].insert(sused);
    }
  }
  
  novi._maxCvor = nadjiMaxCvor(novi._graf);
  return novi
}

Graf* operator*(Graf& g) const{
  Graf novi();
  
  for(auto& par : _graf){
    int cvor = par.first;
    if(g._graf.find(cvor) != g._graf.end()){
      novi._graf[cvor];
      for(int sused : par.second){
        if(g._graf[cvor].find(sused) != g._graf[cvor].end()){
          novi._graf[cvor].insert(sused);
        }
      }
    }
  }
  
  novi._maxCvor = nadjiMaxCvor(novi._graf);
  return novi
}

Graf* operator~() const{
  Graf novi();
  
  for(auto& par : _graf){
    int cvor = par.first;
    novi._graf[cvor];
    auto& susedi = par.second;
    for(auto& par2 : _graf){
      int i = par2.first;
      if(susedi.find(i) != susedi.end()){
        novi._graf[cvor].insert(i);
      }
    }
  }
  
  novi._maxCvor = nadjiMaxCvor(novi._graf);
  return novi
}

////////////////////////////////////////////////////

int nadjiMaxCvor(map<int, set<int>>& graf){
  return graf.empty() ? 0 : graf.rbegin()->first;
}
