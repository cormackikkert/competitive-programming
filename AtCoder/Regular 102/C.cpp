#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, K; cin >> N >> K;

    ll ans = 0;
    FOR(a, 1, N+1) {
        int off = K - (a % K);
        if (2 * off % K != 0) continue;
        ll res = (N - off) / K + 1;
        ans += res * res;    
    }
    cout << ans << endl;
}