#include <iostream>
#include <vector>

using namespace std;

static const vector<pair<int, int>> moves = {
  {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
  {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
};

void svi_potezi(vector<vector<int>> &v, int row, int col){
  const int n = v.size();
  
  for(auto move : moves){
    int new_row = row + move.first;
    int new_col = col + move.second;
    
    if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= n){
      continue;
    }
    if(v[new_row][new_col] != 0){
      continue;
    }
    
    v[new_row][new_col] = 2;
    svi_potezi(v, new_row, new_col);
  }
}

int main(){

  int n;
  cin >> n;
  
  vector<vector<int>> v(n, vector<int>(n));
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> v[i][j];
    }
  }
  
  svi_potezi(v, n-1, 0);
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << v[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
