#include <iostream>
#include <vector>

using namespace std;

int pec(int n, int k){
  if(n == 1) {
    return 0;
  }
  return (pec(n-1, k) + k) % n;
}

int main(){

  int n, k;
  cin >> n >> k;
  
  cout << pec(n, k) + 1 << endl;

  return 0;
}
