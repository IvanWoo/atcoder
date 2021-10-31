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

const string YES = "Yes";
const string NO = "No";

void solve(long long A, long long B, std::string S)
{
    bool ans = S.size() == (A + B + 1);
    forn(i, 0, S.size())
    {
        if (i == A)
        {
            if (S[i] != '-')
            {
                ans = false;
            }
        }
        else
        {
            if (!isdigit(S[i]))
            {
                ans = false;
            }
        }
    }
    cout << (ans ? YES : NO) << endl;
}

int main()
{
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    std::string S;
    std::cin >> S;
    solve(A, B, S);
    return 0;
}
