#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

  int n, k;
  cin >> n >> k;
  
  /*
  vector<int> niz;
  unordered_set<int> x;
  
  x.push_back(n);
  
  int prvi_rez, druzi_rez, treci_rez;
  
  for(int i = 0; i < k; i++){
    prvi_rez = x.top();
    drugi_rez = 2 * x.top();
    treci_rez = 4 * x.top() - 3;
    
    niz.push_back(prvi_rez);
    niz.push_back(drugi_rez);
    niz.push_back(treci_rez);
    
    
  }
  */
  
  priority_queue<int, vector<int>, greater<int>> pq;  //prioritizuje najmanji
  pq.push(n);
  for(int i = 0; i < k; i++){
    int x = pq.top();
    pq.pop();
    cout << x << ' ';
    pq.push(2 * x);
    pq.push(4 * x - 3);
  }

  return 0;
}
