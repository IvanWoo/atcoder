#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
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

const long long MOD = 1000000007;

// basically a fib sequence with broken steps
void solve(long long N, long long M, std::vector<long long> a)
{
    VLL dp(N + 1, 0);
    // broken steps
    set<LL> brokens;
    for (int i = 0; i < M; i++)
    {
        brokens.insert(a[i]);
    }

    dp[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        if (brokens.count(i))
            continue;
        if (!brokens.count(i - 1))
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
        if (i > 1 && !brokens.count(i - 2))
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
    cout << dp[N] << endl;
}

int main()
{
    long long N;
    std::scanf("%lld", &N);
    long long M;
    std::scanf("%lld", &M);
    std::vector<long long> a(M);
    for (int i = 0; i < M; i++)
    {
        std::scanf("%lld", &a[i]);
    }
    solve(N, M, std::move(a));
    return 0;
}
