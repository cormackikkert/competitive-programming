#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define REP(i, l, r) for (int i = (l); i != (r); (l)<(r)?++i:--i)
#define popcount __builtin_popcountll
 
const ll INF = 1LL<<60;
const int MOD = 1000000007;
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
}
 
template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}
 
template <typename A>
string to_string(A x[], int n) {
    string result = "{";
    REP(i, 0, n) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}
 
string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    REP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}
 
vector<int> getZ(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    REP(i, 1, n) {
        z[i] = max(0, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i;
            y = i+z[i];
            ++z[i];
        }
    }
    return z;
}
 
 
int powa(int base, int exp) {
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp>>1);
    val = val*val % MOD;
    if (exp&1) {
        val = val*base % MOD;
    }
    return val;
}

void solve() {
    int n; cin >> n;
    vector<int> types (n);
    vector<int> black (n);
    for (int i = 0; i < n; ++i) {
        int a, f; f= 1;
        cin >> a;
        --a;
        types[a] += 1;
        black[a] += f;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>> q;
    for (int i = 0; i < n; ++i) {
        q.push({types[i], black[i]});
    }

    int cur = 5000000;
    int tall = 0;
    int tblack = 0;
    while (!q.empty()) {
        pair<int, int> item = q.top();
        q.pop();
        if (item.first < cur) {
            cur = item.first;
            tall += item.first;
            tblack += item.second;
        } else {
            if (item.first != item.second && item.first > 0) {
                --item.first;
                q.push(item);
            } else if (item.first > 0) {
                --item.first; --item.second;
                q.push(item);
            } 
        }
    }

    cout << tall  << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q; cin >> q;
    for (int i = 0; i < q; ++i) solve();
}