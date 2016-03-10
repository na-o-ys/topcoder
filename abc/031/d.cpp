#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int k, n; cin >> k >> n;
    vector<string> V(n);
    vector<string> W(n);
    loop (n, i) cin >> V[i] >> W[i];

    loop (pow(3, k), i) {
        int p = i;
        vector<int> l(k);
        loop (k, j) {
            l[j] = (p % 3) + 1;
            p /= 3;
        }

        vector<string> ans(k);
        int ok = 1;
        loop (n, j) {
            int sum = 0;
            for (char c : V[j]) sum += l[c - '1'];
            if (sum != W[j].size()) {
                ok = 0;
                break;
            }

            int k = 0;
            for (char c : V[j]) {
                int idx = c - '1';
                int len = l[idx];
                auto t = W[j].substr(k, len);
                if (ans[idx].size() && t != ans[idx]) {
                    ok = 0;
                    break;
                }
                ans[idx] = t;
                k += len;
            }
        }
        if (ok) {
            for (auto s : ans) cout << s << endl;
            return 0;
        }
    }
    return 0;
}
