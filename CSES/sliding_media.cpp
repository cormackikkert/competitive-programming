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
	int N, K; cin >> N >> K;
	
	vector<pii> arr (N);
	F0R(i, N) {
		int x; cin >> x;
		arr[i] = {x, i};
	}

	vector<pii> temp (K);
	F0R(i, K) temp[i] = arr[i];
	sort(temp.begin(), temp.end());
	pii median = temp[(K-1)/2];
	
	cout << median.first << " ";

	set<pii> items;
	F0R(i, K) items.insert(arr[i]);

	for (int r = K; r < N; ++r) {
		int l = r - K;
		
		items.insert(arr[r]);

		if (arr[l] == median) {
			if (arr[r] > median) {
				// median moves up
				auto it = items.upper_bound(median);
				median = *it;
			} else {
				// median moves down
				auto it = items.lower_bound(median); --it;
				median = *it;
			}
		} else {
			if ((arr[l] <= median) == (arr[r] <= median)) {

			} else if ((arr[l] <= median) && (arr[r] > median)) {
				// median moves up
				auto it = items.upper_bound(median);
				median = *it;
			} else {
				// median moves down
				auto it = items.lower_bound(median); --it;
				median = *it;
			}
		}

		items.erase(items.find(arr[l]));

		cout << median.first << " ";
	}
	cout << endl;
}