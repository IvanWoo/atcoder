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

bool is_prime(LL n)
{
    if (n < 2)
    {
        return false;
    }
    forn(i, 2, (int)sqrt(n) + 1)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve(long long Q, std::vector<long long> l, std::vector<long long> r)
{
    LL lower = INT_MAX;
    LL upper = INT_MIN;
    forn(i, 0, Q)
    {
        chmin(lower, l.at(i));
        chmax(upper, r.at(i));
    }
    vector<bool> p(upper + 1, false);
    forn(i, lower - 1, upper + 1)
    {
        p.at(i) = is_prime(i);
    }
    VI prefix_sum(upper + 1, 0);
    forn(i, 0, upper + 1)
    {
        if (p.at(i) && p.at((i + 1) / 2))
        {
            prefix_sum.at(i) = 1;
        }
    }
    forn(i, 1, upper + 1)
    {
        prefix_sum.at(i) += prefix_sum.at(i - 1);
    }
    forn(i, 0, Q)
    {
        cout << prefix_sum.at(r.at(i)) - prefix_sum.at(l.at(i) - 1) << endl;
    }
}

int main()
{
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> l(Q);
    std::vector<long long> r(Q);
    for (int i = 0; i < Q; i++)
    {
        scanf("%lld", &l[i]);
        scanf("%lld", &r[i]);
    }
    solve(Q, std::move(l), std::move(r));
    return 0;
}
