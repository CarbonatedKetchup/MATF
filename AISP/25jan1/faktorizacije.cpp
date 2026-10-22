#include <iostream>
#include <vector>

using namespace std;

void fact(int n, int start, vector<int> &current, vector<vector<int>> &result){
  if(n == 1){
    if(current.size() > 1){
      result.push_back(current);
    }
    return;
  }
  
  for(int d = start; d <= n; d++){
    if(n % d == 0){
      current.push_back(d);
      fact(n / d, d, current, result);
      current.pop_back();
    }
  }
}

int main(){

  int n;
  cin >> n;
  
  vector<vector<int>> result;
  vector<int> current;
  
  fact(n, 2, current, result);
  
  if(result.size() > 0){
    for(auto factors : result){
      for(int factor : factors){
        cout << factor << " ";
      }
      cout << '\n';
    }
  }else{
    cout << n << '\n';
  }

  return 0;
}
