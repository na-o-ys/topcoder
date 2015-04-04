#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
using TPL = tuple<ll, int, int>;

int main()
{
    int H, W, T;
    cin >> H >> W >> T;
    vector<string> S(H);
    loop (H, i) cin >> S[i];
    int sh, sw, gh, gw;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (S[h][w] == 'S') sh = h, sw = w;
            if (S[h][w] == 'G') gh = h, gw = w;
        }
    }

    int left = 1, right = 1000000001;
    while (right - left > 1) {
        ll B = (left + right) / 2;
        int d[5] = { -1, 0, 1, 0, -1 };
        ll time[13][13];
        fill(time[0], time[12]+13, -1);

        priority_queue<TPL, vector<TPL>, greater<TPL>> Q;
        Q.emplace(0, sh, sw);
        while (Q.size()) {
            TPL p = Q.top();
            Q.pop();

            ll t = get<0>(p), h = get<1>(p), w = get<2>(p);
            time[h][w] = t;
            loop (4, i) {
                int nh = h+d[i], nw = w+d[i+1];
                if (nh < 0 || nh >= H || nw < 0 || nw >= W || time[nh][nw] >= 0) continue;
                if (S[nh][nw] == '#') {
                    Q.emplace(t + B, nh, nw);
                } else {
                    Q.emplace(t + 1, nh, nw);
                }
            }
        }
        ll t = time[gh][gw];
        if (t <= (ll)T) {
            left = B;
        } else {
            right = B;
        }
    }

    cout << right-1 << endl;
    return 0;
}
