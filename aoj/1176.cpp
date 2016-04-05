#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

struct State { int cnt, marg; };
bool operator>(const State& a, const State& b) {
    return tie(a.cnt, a.marg) > tie(b.cnt, b.marg);
}

int h, w;

int area(int hi, int hl, int wi, int wl, vector<vector<int>>& S) {
    if (hi > 0 && wi > 0) {
        return S[hi+hl-1][wi+wl-1] - S[hi+hl-1][wi-1] - S[hi-1][wi+wl-1] + S[hi-1][wi-1];
    }
    if (hi > 0) {
        return S[hi+hl-1][wi+wl-1] - S[hi-1][wi+wl-1];
    }
    if (wi > 0) {
        return S[hi+hl-1][wi+wl-1] - S[hi+hl-1][wi-1];
    }
    return S[hi+hl-1][wi+wl-1];
}

const int INF = 1<<29;
State dp[33][33][33][33];

int main()
{
    while (1) {
        fill(dp[0][0][0], dp[32][32][32]+33, State{ 0, 0 });
        int s; cin >> h >> w >> s;
        if (!h) break;

        vector<vector<int>> U(h, vector<int>(w));
        loop (h, i) loop (w, j) cin >> U[i][j];
        vector<vector<int>> S = U;
        loop (h, i) loop (w-1, j) S[i][j+1] += S[i][j];
        loop (w, j) loop (h-1, i) S[i+1][j] += S[i][j];
        int sum = S[h-1][w-1];

        for (int hl = 1; hl <= h; hl++) for (int wl = 1; wl <= w; wl++)
        loop (h, hi) loop (w, wi) {
            if (hi + hl > h || wi + wl > w) continue;

            State crr;
            int marg = s - (sum - area(hi, hl, wi, wl, S));
            if (marg >= 0) crr = { 1, marg };
            else crr = { 0, 0 };

            for (int i = 1; hi + i < h && hl - i > 0; i++) {
                auto a = dp[hi][i][wi][wl];
                auto b = dp[hi+i][hl-i][wi][wl];
                auto s = State{ a.cnt + b.cnt, min(a.marg, b.marg) };
                if (s > crr) crr = s;
            }
            for (int i = 1; wi + i < w && wl - i > 0; i++) {
                auto a = dp[hi][hl][wi][i];
                auto b = dp[hi][hl][wi+i][wl-i];
                auto s = State{ a.cnt + b.cnt, min(a.marg, b.marg) };
                if (s > crr) crr = s;
            }
            dp[hi][hl][wi][wl] = crr;
        }

        auto ans = dp[0][h][0][w];
        cout << ans.cnt << " " << ans.marg << endl;
    }
    return 0;
}
