#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define multi_cin(n, array) loop(n,i){cin>>array[i];}
#define assign_if_smaller(var, val) if(var>val)var=val;
#define assign_if_larger(var, val) if(var<val)var=val;
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;

int main(int argc, char const* argv[])
{
  string s;
  cin >> s;

  int status = 0;
  loop(s.size(), i) {
    switch (status) {
      case 0:
        if (s[i] == 'i' || s[i] == 'I') status = 1;
        break;
      case 1:
        if (s[i] == 'c' || s[i] == 'C') status = 2;
        break;
      case 2:
        if (s[i] == 't' || s[i] == 'T') status = 3;
        break;
    }
  }

  if (status == 3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
