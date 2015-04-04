#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
const int M = 1000001;

int main(int argc, char const* argv[])
{
    int t; cin >> t;
    vector<int> nums(M);
    for (int i = 2; i < M; i++) nums[i] = i;
    for (int i = 2; i*i < M; i++) if (nums[i]) for (int j = i*i; j < M; j += i) nums[j] = 0;
    vector<int> primes;
    for (int i = 2; i < M; i++) if (nums[i]) primes.push_back(i);
    while (t--) {
        int N; cin >> N;
        unordered_map<int, int> P;
        loop (N, i) {
            int a; cin >> a;
            int oa = a;
            for (int j = 0; j < primes.size() && primes[j] * primes[j] <= oa; j++) {
                int p = primes[j];
                if (a%p) continue;
                int cnt = 0;
                while (a%p == 0) {
                    a /= p;
                    cnt++;
                }
                if (!P.count(p)) P[p] = cnt;
                else P[p] = max(P[p], cnt);
            }
            if (a > 1 && !P.count(a)) P[a] = 1;
        }
        ll ans = 0;
        // for (auto p : P) cout << p.first << ": " << p.second << endl;
        for (auto p : P) ans += p.second;
        cout << ans << endl;
    }
    return 0;
}
