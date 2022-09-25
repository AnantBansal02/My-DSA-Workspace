#include <bits/stdc++.h>
#define c(o) cout << x << endl
#define loop(i, m, n) for (ll i = m; i < n; i++)
#define ll long long
#define nl cout << endl
#define countDig(n) floor(log10(n)) + 1
using namespace std;

int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);

       string s;
       cout << "Enter the String :-" << endl;
       cin >> s;

       int x = s.length();

       ll count = 0;
       
       vector<int> v2;
       
       for (ll i = x - 1; i >= 0; i--)
       {
              v2.push_back(s[i]);
       }
       for (int i = 0; i < x; i++)
       {
              if (s[i] == v2[i])
              {
                     count++;
              }
       }
       if (count == x)
       {
              cout << "Given string is a Palindrome" << endl;
       }
       else
       {
              cout << "Given string is not a palindrome" << endl;
       }
       return 0;
}