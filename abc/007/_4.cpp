#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define multi_cin(n, array) loop(n,i){cin>>array[i];}
#define assign_if_smaller(var, val) if(var>val)var=val;
#define assign_if_larger(var, val) if(var<val)var=val;
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;
typedef unsigned long long ull;

ull calc(ull n)
{
  ull dp[2][2];
  dp[0][0] = 1;
  dp[0][1] = 1;

  int digits = 1;
  ull n_ = n;
  while ((n_ /= 10) != 0) digits++;

  loop(digits, i)
  {
    dp[(i+1)%2][0] = 0;
    dp[(i+1)%2][1] = 0;

    ull tmp = n;
    repeat(i) tmp /= 10;
    int m = tmp % 10;

    loop(10, j)
    {
      if (j == 4 || j == 9) continue;
      dp[(i+1)%2][0] += dp[i%2][0];

      if (j <= m)
      {
        dp[(i+1)%2][1] += dp[i%2][j == m ? 1 : 0];
      }
    }
  }

  return n - (dp[digits%2][1] - 1);
}

int main(int argc, char const* argv[])
{
  ull a, b; cin >> a >> b;
  cout << calc(b) - calc(a-1) << endl;
  
  return 0;
}
