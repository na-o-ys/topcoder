#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int n; string s;
    cin >> n >> s;
    vector<int> q(30);

    for (int i = 0; i < n; i++) {
        s[i] -= '0';
        for (int j = 2; j <= s[i]; ++j) {
            int jj = j;
            while (jj %2 == 0) ++q[2], jj/=2;
            while(jj%3==0)++q[3],jj/=3;
            while(jj%5==0)++q[5],jj/=5;
            while(jj%7==0)++q[7],jj/=7;
        }
    }

    int q7=q[7];
    q[5] -= q7, q[3] -= 2*q7, q[2] -= 4*q7;
    int q5 = q[5];
    q[3] -= q5, q[2] -= 3 * q5;
    int q3 = q[3];
    q[2] -= q3;
    int q2 = q[2];
    for (int i = 0; i < q7; i++) cout << 7;
    for (int i = 0; i < q5; i++) cout << 5;
    loop (q3, i) cout << 3;
    loop (q2, i) cout <<2;
    cout << endl;
    return 0;
}
