#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;

using namespace std;
typedef long long ll;
const int INF = 1<<29;

//vector<vector<int>> b(3, vector<int>(3));
//vector<vector<int>> c(3, vector<int>(3));

vector<int> dfs(vector<int> mv) {
    if (mv.size() == 9) {
        int B[3][3];
        int t = 0;
        for (int m : mv) {
            B[m/3][m%3] = t;
            t ^= 1;
        }
        HERE

        vector<int> sc = { 0, 0 };
        loop (2, i) loop (3, j) {
            sc[B[i][j] != B[i+1][j]] += b[i][j];
        }
        loop (3, i) loop (2, j) {
            sc[B[i][j] != B[i][j+1]] += c[i][j];
        }
        return sc;
    }
    HERE;

    int t = mv.size()%2;
    vector<int> sc = { -INF, -INF };
    loop (9, i) {
        for (int m : mv) if (m == i) continue;
        vector<int> mvv = mv;
        mvv.push_back(i);
        auto scc = dfs(mvv);
        if (sc[t] < scc[t]) sc = scc;
    }
    return sc;
}

int main()
{
    HERE
    //loop (3, i) loop (2, j) cin >> b[i][j];
    //loop (2, i) loop (3, j) cin >> c[i][j];
    //auto sc = dfs({});
    //cout << sc[0] << endl;
    //cout << sc[1] << endl;
}
