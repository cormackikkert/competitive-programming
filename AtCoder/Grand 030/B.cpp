#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void print() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void print(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); print(ts...); 
	}
}

using namespace output;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll L, N; cin >> L >> N;
	vll arr (N);
	F0R(i, N) cin >> arr[i];

	vector<vector<vll>> dp (N, vector<vll> (N + 1, vll (2)));
	dp[0][1][1] = arr[0];
	dp[0][0][0] = L - arr[N-1];
	F0R(i, N-1) F0R(r, N) F0R(t, 2) {
		if (dp[i][r][t] == 0) continue;
		
		// get last pos
		ll last_pos = 0;
		ll rmost = r - 1;
		ll lmost = N - ((i+1) - r);
		last_pos = (t) ? ((rmost == -1) ? 0 : arr[rmost]) : ((lmost == N) ? 0 : arr[lmost]);
		
		ll d;
		d = 0;
		if (t == 0) {
			d = (L - last_pos) % L + arr[rmost + 1];
		} else {
			d = arr[rmost + 1] - last_pos;
		}

		dp[i+1][r+1][1] = max(dp[i+1][r+1][1], d + dp[i][r][t]);

		d = 0;
		if (t == 0) {
			d = last_pos - arr[lmost - 1];
		} else {
			d = last_pos + (L - arr[lmost - 1]);
		}
		dp[i+1][r][0]   = max(dp[i+1][r][0], d + dp[i][r][t]);
	}

	ll ans = 0;
	F0R(r, N) F0R(t, 2) {
		ans = max(ans, dp[N-1][r][t]);
	}
	print(ans);
}