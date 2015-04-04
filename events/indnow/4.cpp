#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

const int MAX = 12;
int H, W;

void bfs(vector<int> init, map<vector<int>, int> &mp)
{
    queue<pair<int, vector<int>>> Q;
    Q.emplace(0, init);

    while (Q.size()) {
        auto v = Q.front(); Q.pop();
        int count = v.first;
        auto& p = v.second;
        if (count > MAX) continue;
        mp[p] = count;
        int zero = 0;
        while (p[zero]) zero++;
        vector<int> next;
        if (zero % W != 0) next.push_back(zero-1);
        if (zero % W != W-1) next.push_back(zero+1);
        if (zero >= W) next.push_back(zero-W);
        if (zero < W * (H-1)) next.push_back(zero+W);
        for (int n : next) {
            vector<int> np = p;
            swap(np[zero], np[n]);
            if (mp.count(np)) continue;
            Q.emplace(count+1, np);
        }
    }
}

int main()
{
    cin >> H >> W;
    vector<int> init(H*W), goal(H*W);
    loop (H*W, i) cin >> init[i];
    loop (H*W, i) goal[i] = i+1;
    goal[H*W-1] = 0;

    map<vector<int>, int> forward, backward;
    bfs(init, forward);
    bfs(goal, backward);

    int ans = 1<<29;
    for (auto&& p : forward) {
        auto& v = p.first;
        int count = p.second;
        if (backward.count(v)) {
            ans = min(ans, backward[v] + count);
        }
    }
    cout << ans << endl;
    return 0;
}
