#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;

int main()
{
    int N; cin >> N;
    int a, b; cin >> a >> b;
    int K; cin >> K;
    vector<int> P(K);
    loop (K, i) cin >> P[i];

    int count[110] = {};
    for (int p : P) count[p]++;
    count[a]++, count[b]++;

    if (*max_element(count, count+110) < 2) {
        cout << "YES" << endl;;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}
