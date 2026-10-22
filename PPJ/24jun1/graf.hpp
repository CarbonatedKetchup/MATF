#ifndef GRAF
#define GRAF

#include<iostream>
#include <map>
#include <set>

using namespace std;

class Graf{
  private:
    map<int, set<int>> _graf;
    int _maxCvor;
  public:
    Graf() {};
    Graf(map<int, set<int>>& gr);
    
    void ispisiUsmereno() const;
    void ispisiNeusmereno() const;
    
    void obrisiCvor(int cvor);
    
    void ispisiSusede(int cvor) const;
    
    Graf* operator+(Graf& g) const;
    Graf* operator*(Graf& g) const;
    Graf* operator~() const;
};

int nadjiMaxCvor(map<int, set<int>>& graf);

#endif
