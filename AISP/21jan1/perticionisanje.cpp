#include <iostream>
#include <vector>

#define M 1000000007

using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  vector<int> dp(n+1);
  dp[0] = 1;
  for(int i = 0; i <= n; i++){
    dp[i] = dp[i-1];
    if(i > 1 && v[i-1] + v[i-2] < 4){
      dp[i] = (dp[i] + dp[i-2]) % M;
    }
    if(i > 2 && v[i-1] + v[i-2] + v[i-3] < 4){
      dp[i] = (dp[i] + dp[i-3]) % M;
    }
  }
  
  cout << dp[n] << '\n';

  return 0;
}
