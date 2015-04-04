#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)

using namespace std;

int calc(vector<int> cup, int m)
{
    int cnt = 0;
    while (1) {
        int i = cnt%2, j = i+1;
        int p = 1;
        while (p <= max(cup[i], cup[j])) p <<= 1;
        p >>= 1;
        if (!p) break;
        cup[i] ^= p;
        cup[j] ^= p;
        cnt++;
        if (cnt > m) return cnt;
    }

    return cnt;
}

int main()
{
    while (1) {
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<int> cup(3);
        loop (3, i) {
            int c; cin >> c;
            while (c--) {
                int v; cin >> v;
                cup[i] |= 1 << v--;
            }
        }
        int ans = calc(cup, m);
        swap(cup[0], cup[2]);
        ans = min(ans, calc(cup, m));
        cout << (ans <= m ? ans : -1) << endl;
    }
    return 0;
}
