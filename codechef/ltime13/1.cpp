#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;
const ull B = 100000007;

int main(int argc, char const* argv[])
{
    string S; cin >> S;
    int L = S.length();

    vector<vector<ull>> hash(L, vector<ull>(L));
    loop(L, i) hash[i][0] = S[i];
    loop(L, i) loop(L-1, j) {
        if (i+j+1 <= L-1) hash[i][j+1] = hash[i][j] * B + S[i+j+1];
        else hash[i][j+1] = 0;
    }

    // loop(L, i) {
    //     cout << "i: " << i << endl;
    //     loop(L, j) cout << "j: " << j << ", h: " << hash[i][j] << endl;
    // }

    int N; cin >> N;
    loop(N, k) {
        int l, p; cin >> l >> p;
        unordered_map<ull, int> mp;
        int ans = 0;
        // loop(L, i) if (hash[i][l-1]) {
        //     int c = ++mp[hash[i][l-1]];
        //     if (c == p) ans++;
        //     else if (c == p+1) ans--;
        // }
        vector<int> hs(L);
        loop(L, i) hs[i] = hash[i][l-1];
        sort(hs.begin(), hs.end());
        ull tmp = 0;
        int cnt = 0;
        for (ull v : hs) {
            if (v == 0) continue;
            if (v == tmp) cnt++;
            else {
                tmp = v;
                cnt = 1;
            }
            if (cnt == p) ans++;
            else if (cnt == p+1) ans--;
        }

        cout << ans << endl;
    }
    return 0;
}
