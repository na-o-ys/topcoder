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

int main(int argc, char const* argv[])
{
  int t; cin>>t;
  while(t--){
    int n,m,k;// cin>>n>>m>>k;
    scanf("%d %d %d", &n, &m, &k);

    int a[n];// multi_cin(n, a);
    loop(n,i) scanf("%d",&(a[i]));
    int b[n][m];
    int point = 0;
    loop(n,i) loop(m,j) {
      // cin>>b[i][j];
      scanf("%d",&(b[i][j]));
    }

    // main
    vector<int> rewards;
    loop(n,i) {
      int max_reward = 0;
      loop(m,j) {
        int c;// cin>>c;
        scanf("%d",&c);
        int reward = b[i][j] - c - b[i][a[i]-1];
        assign_if_larger(max_reward, reward);
      }

      if (max_reward != 0) rewards.push_back(max_reward);
      point += b[i][a[i]-1];
    }

    sort(rewards.begin(), rewards.end(), greater<int>());

    each(r,rewards) {
      if(k--) point += *r;
      else break;
    }

    cout << point << endl;
  }
  return 0;
}
