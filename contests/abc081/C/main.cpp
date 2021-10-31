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

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

void solve(LL N, LL K, VLL A)
{
    VLL counter(N + 1, 0);
    forn(i, 0, N)
    {
        counter[A[i]] += 1;
    }
    sort(all(counter), [](auto a, auto b)
         { return a > b; });
    LL res = 0;
    forn(i, K, N)
    {
        res += counter[i];
    }
    cout << res << endl;
}

int main()
{
    LL N;
    scanf("%lld", &N);
    LL K;
    scanf("%lld", &K);
    VLL A(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    solve(N, K, A);
    return 0;
}
