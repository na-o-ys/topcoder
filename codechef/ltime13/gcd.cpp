#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int N; cin >> N;
    vector<int> a(N);
    vector<int> cnt(1000010);
    loop(N, i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    int M = max_element(a.begin(), a.end());

    vector<ll> comb(M+1);
    loop_from_to(2, M, i) {
        int c = 0;
        for (int j = i; j <= M; j += i) c += cnt[j];
        comb[i] = (long)c*(c-1)*(c-2)/6;
    }

    for (int i = M; i >= 2; i--) {
        for (int j = i; j <= M; j += i) comb[i] -= comb[j];
    }

    int ans = 0;
    b.push_back(P(gcd(a[0], a[1]), 1));
    loop_from_to(2, N-1, i) {
        for (auto v : b) {
            if (gcd(v.first, i) == 1) ans += v.second;
        }
        loop_from_to(0, i-1, j) {
            ;
        }
    }

    cout << ans << endl;
    return 0;
}
