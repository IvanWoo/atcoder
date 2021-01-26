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

const string YES = "Yes";
const string NO = "No";

void solve(long long N, VLL t, VLL x, VLL y)
{
    bool flag = true;
    LL p_t = 0;
    LL p_x = 0;
    LL p_y = 0;
    forn(i, 0, N)
    {
        LL diff_t = t[i] - p_t;
        LL dis = abs(p_x - x[i]) + abs(p_y - y[i]);
        if (dis > diff_t)
        {
            flag = false;
            break;
        }
        else
        {
            if ((diff_t - dis) % 2 != 0)
            {
                flag = false;
                break;
            }
        }
        p_t = t[i];
        p_x = x[i];
        p_y = y[i];
    }
    cout << (flag ? YES : NO) << endl;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    VLL t(N);
    VLL x(N);
    VLL y(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &t[i]);
        scanf("%lld", &x[i]);
        scanf("%lld", &y[i]);
    }
    solve(N, std::move(t), std::move(x), std::move(y));
    return 0;
}
