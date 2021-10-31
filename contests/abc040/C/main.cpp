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

void solve(long long N, std::vector<long long> a)
{
    const LL INF = 1LL << 60;
    VLL dp(N, INF);
    dp[0] = 0;

    for (int i = 1; i < N; i++)
    {
        chmin(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
        if (i > 1)
            chmin(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[N - 1] << endl;
}

int main()
{
    long long N;
    std::scanf("%lld", &N);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++)
    {
        std::scanf("%lld", &a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
