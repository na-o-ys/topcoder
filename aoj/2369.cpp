#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

string s;
int i;

int cat()
{
    if (i == s.length()) return 1;
    if (s[i] != 'm') return 1;
    i++;
    if (!cat() || i == s.length() || s[i] != 'e') return 0;
    i++;
    if (!cat() || i == s.length() || s[i] != 'w') return 0;
    i++;
    return 1;
}

int main()
{
    cin >> s; i = 0;
    cout << (cat() && i == s.length() ? "Cat" : "Rabbit") << endl;
    return 0;
}
