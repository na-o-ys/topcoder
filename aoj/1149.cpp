#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
//typedef pair<int, int> P;
typedef struct { int w, d; } P;

int main()
{
    while (1) {
        int n, w, d; cin >> n >> w >> d;
        if (!w) break;
        vector<P> C = {{ w, d }};

        loop (n, i) {
            int p, s; cin >> p >> s;
            P c = C[p-1];
            C.erase(C.begin()+p-1);
            vector<P> cs;
            s %= c.w + c.d;
            if (s < c.w) cs = {{ s, c.d }, { c.w-s, c.d }};
            else cs = {{ c.w, s-c.w }, { c.w, c.d-(s-c.w) }};
            if (cs[0].w*cs[0].d > cs[1].w*cs[1].d) swap(cs[0], cs[1]);
            C.insert(C.end(), all(cs));
        }

        vector<int> area;
        for (P c : C) area.push_back(c.w * c.d);
        sort(all(area));
        cout << area[0];
        loop (area.size()-1, i) cout << " " << area[i+1];
        cout << endl;
    }
    return 0;
}
