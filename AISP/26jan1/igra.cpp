#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int k;
  cin >> k;
  
  for(int brojac_k = 0; brojac_k < k; brojac_k++){  // k puta

    // za svaki niz

    int n;
    cin >> n;
    vector<int> v(n);
    int max_niza = -1, max_n_index = -1, x;
    for(int i = 0; i < n; i++){
      cin >> x;
      v[i] = x;
      if(x > max_niza){
        max_niza = x;
        max_n_index = i;
      }
   }
   
   int n_kop = n;
   int brojac = 0;
   vector<int> novi_niz;
   
   while(n_kop > 0){
    for(int j = 0; j < max_n_index; j++){
      novi_niz.push_back(v[j]);
    }
    n_kop = novi_niz.size();
    int novi_max;
    if(!novi_niz.empty()){
      auto novi_max_it = max_element(novi_niz.begin(), novi_niz.end());
      novi_max = novi_max_it - novi_niz.begin();
    }else{
      novi_max = 0;
    }
    
    if(n_kop > 0){
      brojac++;
    }
    max_n_index = novi_max;
   }
   
   if(brojac % 2 == 0){
    cout << "BOBAN" << '\n';
   }else{
    cout << "ALISA" << '\n';
   }

    // za svaki niz

  }
  
  return 0;
}

