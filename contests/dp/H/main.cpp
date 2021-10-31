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

const long long MOD = 1000000007;

void add(LL &a, LL b)
{
    a += b;
    a %= MOD;
}

void solve(long long H, long long W, std::vector<std::string> a)
{
    VVLL dp(H, VLL(W, 0));
    dp[0][0] = 1;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i + 1 < H && a[i + 1][j] == '.')
                add(dp[i + 1][j], dp[i][j]);
            if (j + 1 < W && a[i][j + 1] == '.')
                add(dp[i][j + 1], dp[i][j]);
        }
    }

    cout << dp[H - 1][W - 1] << endl;
}

int main()
{
    long long H;
    std::scanf("%lld", &H);
    long long W;
    std::scanf("%lld", &W);
    vector<string> a(H);
    for (int i = 0; i < H; i++)
    {
        std::cin >> a[i];
    }
    solve(H, W, std::move(a));
    return 0;
}
