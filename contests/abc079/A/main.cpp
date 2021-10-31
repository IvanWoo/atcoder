#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto const &it: a) cout << it << ' ';
#define DEBUGVV(a) for(auto const &it: a) { DEBUGV(it); cout << endl; };
#define CEIL(a, b) (a + b - 1) / b
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// clang-format on

const string YES = "Yes";
const string NO = "No";

void solve(long long N)
{
    string str = to_string(N);
    char prev = str[0];
    int counter = 1;
    int max = 1;
    for (int i = 1; i < 4; i++)
    {
        if (str[i] == prev)
        {
            counter += 1;
            chmax(max, counter);
        }
        else
        {
            prev = str[i];
            counter = 1;
        }
    }
    cout << (max >= 3 ? YES : NO) << endl;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    solve(N);
    return 0;
}
