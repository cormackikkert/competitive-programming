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

ll T;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vll arrA (N);
	F0R(i, N) cin >> arrA[i];
	vll arrB(N);
	F0R(i, N) cin >> arrB[i];

	sort(arrB.begin(), arrB.end());


	ll res = 0;

	FOR(i, 0, 30) {
		int count = 0;

		T = pow(2, i);

		vll A (N);
		F0R(i, N) A[i] = arrA[i] % (2 * T);

		vll B (N);
		F0R(i, N) B[i] = arrB[i] % (2 * T);

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int j = 0;
		int k = 0;
		int l = 0;

		for (int i = N - 1; i >= 0; --i) {
			while (j < N && B[j] + A[i] < T) ++j;
			while (k < N && B[k] + A[i] < 2 * T) ++k;
			while (l < N && B[l] + A[i] < 3 * T) ++l;
			count += k - j;
			count += N - l ;
		}

		if (count % 2) res |= (1 << i);
	}
	print(res);
}