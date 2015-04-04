#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
typedef long long ll;
const ll MAX = 10000000000;

void Main(int n, int *a) {
    vector<int> dp[2][100000];

    loop(n, i) {
        int crr = i%2;
        int prev = (i+1)%2;
        loop(n, j) dp[crr][j] = vector<int>();
        loop(n, j) {
            if (dp[prev][j].size() == 0) continue;

            dp[crr][j] = dp[prev][j];
            int idx = ((ll)j + a[i]) % n;
            if (dp[prev][idx].size() == 0) { dp[crr][idx] = dp[prev][j]; dp[crr][idx].push_back(i); }
        }

        dp[crr][a[i]%n].push_back(i);

        if (dp[crr][0].size()) {
            cout << dp[crr][0].size() << endl;
            loop(dp[crr][0].size()-1, i) cout << dp[crr][0][i]+1 << " ";
            cout << dp[crr][0][dp[crr][0].size()-1]+1 << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(int argc, char const* argv[])
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n]; loop(n, i) cin >> a[i];
        Main(n, a);
    }
  return 0;
}
