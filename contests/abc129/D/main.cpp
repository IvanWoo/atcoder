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

// prefix sum in 4 directions
void solve(long long H, long long W, std::vector<std::string> S)
{
    VVLL L(H, VLL(W, 0));
    VVLL R(H, VLL(W, 0));
    VVLL U(H, VLL(W, 0));
    VVLL D(H, VLL(W, 0));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (S[i][j] == '#')
                continue;
            L[i][j] = 1;
            if (j >= 1)
                L[i][j] += L[i][j - 1];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = W - 1; j >= 0; j--)
        {
            if (S[i][j] == '#')
                continue;
            R[i][j] = 1;
            if (j < W - 1)
                R[i][j] += R[i][j + 1];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (S[i][j] == '#')
                continue;
            U[i][j] = 1;
            if (i >= 1)
                U[i][j] += U[i - 1][j];
        }
    }
    for (int i = H - 1; i >= 0; i--)
    {
        for (int j = 0; j < W; j++)
        {
            if (S[i][j] == '#')
                continue;
            D[i][j] = 1;
            if (i < H - 1)
                D[i][j] += D[i + 1][j];
        }
    }

    int res = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int val = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3;
            chmax(res, val);
        }
    }

    cout << res << endl;
}

int main()
{
    long long H;
    std::scanf("%lld", &H);
    long long W;
    std::scanf("%lld", &W);
    std::vector<std::string> S(H);
    for (int i = 0; i < H; i++)
    {
        std::cin >> S[i];
    }
    solve(H, W, std::move(S));
    return 0;
}
