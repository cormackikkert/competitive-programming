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

const int BIG = 505;
ll tri [BIG+5][BIG+5] = {{0}};
ll dp [BIG+5][BIG+5] = {{ 0 }};

int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tri[1][1] = 1;
	FOR(y, 2, BIG + 1) {
		FOR(x, 1, BIG + 1) {
			tri[y][x] = tri[y-1][x-1] + tri[y-1][x];
			if (tri[y][x] >= 1e9+10) tri[y][x] = 0;
		}
	}
	// cout << "HERE" << endl;
	vll shortestPath (1e9+1);
	F0R(i, 1e9+1) shortestPath[i] = i;
	dp[1][1] = 1;
	FOR(y, 2, BIG+1) {
		FOR(x, 1, BIG+1) {
			// cout << y << " " << x << endl;
			dp[y][x] = tri[y][x] + max(dp[y-1][x-1], dp[y-1][x]);
			// cout << "YES " << dp[y][x] << endl; 
			if (dp[y][x] <= 1e9) shortestPath[dp[y][x]] = min(shortestPath[dp[y][x]], (ll) y);
		}
	}
	// cout << "HERE2" << endl;
	ll worst = 0;
	for (int x = 1e7; x <= 1e8; ++x) {
		ll best = shortestPath[x];
		for (int d = 0; d <= x; ++d) best = min(best, shortestPath[d] + shortestPath[x-d] - 1);
		worst = max(worst, best);
		if (worst > 500) break;
		// print(x, best); 
	}
	print(worst);
	// print(tri); 
	// print(dp);
}