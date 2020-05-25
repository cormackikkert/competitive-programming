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
    vi arr (N);
    F0R(i, N) cin >> arr[i];
    int a = arr[0];
    F0R(i, N) a = min(a, arr[i]);
    ll total =0 ;
    F0R(i, N) {
        if ((arr[i] - a) % K != 0) {
            cout << -1 << endl;
            return 0;
        }
        total += (arr[i] - a) / K;
    }
    cout << total << endl;
}