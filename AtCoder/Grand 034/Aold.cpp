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
		pr("{",x.first,", ",x.second,"}"); 
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
	int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
	string S; cin >> S;
	
	--A; --B; --C; --D;

	vector<bool> AR (N);
	vector<bool> BR (N);
	
	int c;
	c = A;
	AR[c] = true;
	while (true) {
		if (c + 1 < N && S[c+1] == '.') c += 1;
		else if (c + 2 < N && S[c+2] == '.') c += 2;
		else break;
		AR[c] = true;
	}
    
	c = B;
	BR[c] = true;
	while (true) {
		if (c + 1 < N && S[c+1] == '.') c += 1;
		else if (c + 2 < N && S[c+2] == '.') c += 2;
		else break;
		BR[c] = true;
	}
	
	if (!AR[C] || !BR[D]) {
		print("No");
		return 0;
	}

    print(S.substr(64130-1, 4));
    FOR(i, 64130-1, 64130+3) {
        cout << (AR[i] ? "1" : "0");
    }
    FOR(i, 64130-1, 64130+3) {
        cout << (BR[i] ? "1" : "0");
    }
    cout << endl;

	if ((A < B) != (C < D)) {
		bool canDo = false;
		FOR(i, max(0, max(A, B) - 1), min(C, D)) {
			if (S[i] == '.' && S[i+1] == '.' && S[i+2] == '.' && AR[i] && BR[i]) canDo = true;
            if (S[i] == '.' && S[i+1] == '.' && S[i+2] == '.' && (!AR[i] || !BR[i])) print("REE", i);
		}
		print(canDo ? "Yes" : "No");
	} else {	
		print("Yes");
	}
}
