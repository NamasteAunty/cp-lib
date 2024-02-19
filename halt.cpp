/* हर हर महादेव */

#include "bits/stdc++.h"

using namespace std;

static const auto IOSetup = [] {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << setprecision(15) << fixed;
	return nullptr;
}();

#ifdef LOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", debug(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template <class, class = void> struct is_readable : std::false_type {};
template <class T> struct is_readable<T, std::void_t<decltype(std::cin >> std::declval<T&>())>> : std::true_type {};
 
template <class, class = void> struct is_printable : std::false_type {};
template <class T> struct is_printable<T, std::void_t<decltype(std::cout << std::declval<T&>())>> : std::true_type {};
 
template <class, class = void> struct is_iterable : std::false_type {};
template <class T> struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>> : std::true_type {};
 
void read() {}
template <class T, class... U> void read(T &t, U &...u);
 
void read(double& d) { 
	string t; read(t); d = stod(t); 
}

void read(long double& d) { 
	string t; read(t); d = stold(t); 
}
 
template <class T, enable_if_t<is_readable<T>::value, bool> = true> void read(T &x) { 
	cin >> x; 
}
 
template <class T, class U> void read(pair<T, U> &p) { 
	read(p.first, p.second); 
}
 
template <class T, enable_if_t<is_iterable<T>::value && !is_readable<T>::value, bool> = true> void read(T &c) { 
	for (auto &x : c) read(x); 
}
 
template <class T, class... U >void read(T &t, U &...u) { 
	read(t); read(u...); 
}
 
template <class T, class... U> void out(ostream &os, const T &t, const U &...u);
template <class T, enable_if_t<is_printable<T>::value, bool> = true> void out(ostream &os, const T x) { 
	os << x; 
}
 
template <class T, class U> void out(ostream &os, const pair<T, U> p) { 
	if (&os == &cerr) out(os, '(', p.first, ", ", p.second, ')');
	else out(os, p.first, ' ', p.second);
}
 
template <typename... Ts> void out(ostream& os, const tuple<Ts...>& t) {
	if (&os == &cerr) os << '{';
	apply([&os](const auto&... args) {
		bool fst = true;
		((os << (fst ? "" : (&os == &cerr ? ", " : " ")) << args, fst = false), ...);
	}, t);
	if (&os == &cerr) os << '}';
}
 
template <class T, enable_if_t<is_iterable<T>::value && !is_printable<T>::value, bool> = true> void out(ostream& os, const T& v) {
	if (&os == &cerr) os << '{';
	bool fst = true;
	for (const auto& x : v) {
		if (!fst) os << (&os == &cerr ? ", " : " ");
		out(os, x);
		fst = false;
	}
	if (&os == &cerr) os << '}';
}
 
void out(ostream& os) { 
	os << ""; 
}

template <class H, class... T> void out(ostream& os, const H& h, const T&... t) { 
	out(os, h); out(os, t...); 
}
 
void write() {} 
template <class H, class... T> void write(const H& h, const T&...t) { 
	out(cout, h); write(t...); 
}
 
void print() { cout << '\n'; }
template <class H, class... T> void print(const H& h, const T&...t) { 
	out(cout, h); if (sizeof...(t)) out(cout, ' '); print(t...); 
}
 
void debug() { cerr << "]" << endl; }

template <class H, class... T> void debug(const H& h, const T&... t) { 
	out(cerr, h); if (sizeof...(t)) out(cerr, ", "); debug(t...);  
}
 
void flush() { cout.flush(); }

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define si(x) (i32)(x.size())

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

using pii = pair<i32, i32>;
using pll = pair<i64, i64>;

template <typename T> using vt = vector<T>;
template <typename T> using vvt = vt<vt<T>>;
template <typename T> using vvvt = vt<vvt<T>>;

void Yes(const bool b = true) { cout << (b ? "Yes\n" : "No\n"); }
void No() { cout << "No\n"; }
void YES(const bool b = true) { cout << (b ? "YES\n" : "NO\n"); }
void NO() { cout << "NO\n"; }

#define repnum(a, b, c, d, e, ...) e
#define rep(...)                    repnum(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define rep0(x)                     for (int rep_counter = 0; rep_counter <= (x); ++rep_counter)
#define rep1(i, x)                  for (int i = 0; i <= (x); ++i)
#define rep2(i, l, r)               for (int i = (l); i <= (r); ++i)
#define rep3(i, l, r, c)            for (int i = (l); i <= (r); i += (c))

#define pernum(a, b, c, d, e, ...) e
#define per(...)                    pernum(__VA_ARGS__, per3, per2, per1, per0)(__VA_ARGS__)
#define per0(x)                     for (int per_counter = (x); per_counter >= 0; --per_counter)
#define per1(i, x)                  for (int i = (x); i >= 0; --i)
#define per2(i, l, r)               for (int i = (r); i >= (l); --i)
#define per3(i, l, r, c)            for (int i = (r); i >= (l); i -= (c))

int d4x[4] = {-1, 0, 1, 0};
int d4y[4] = {0, -1, 0, 1};

template <class T> auto MAX(const T& a) { return *max_element(all(a)); }
template <class T> auto MIN(const T& a) { return *min_element(all(a)); }
template <class T, class S = i64> S SUM(const vt<T>& a) { return *sum_element(all(a)); }

template <class T> void mkuni(vt<T> &v) {
	sort(all(v)); v.erase(unique(all(v)), v.end());
}
 
template <class T> vt<int> sortidx(const vt<T> &a) {
	int n = si(a);
	vt<int> idx(n); iota(all(idx),0);
	sort(all(idx),[&](int i,int j){ return a[i] < a[j]; });
	return idx;
}
 
template <class T> vt<T> prefsum(const vt<T>& a) {
	int n = si(a);
	vt<T> psum(n + 1);
	for (int i = 1; i <= n; i++) psum[i] = psum[i - 1] + a[i - 1];
	return psum;
}
 
template <class T> vt<T> suffsum(const vt<T>& a) {
	int n = si(a);
	vt<T> ssum(n + 1);
	for (int i = n - 1; i >= 0; i--) ssum[i] = ssum[i + 1] + a[i];
	return ssum;
}

template <class A, class B> bool chmin(A& x, const B& y) { 
	if (x > y) { x = y; return true; } return false; 
}

template <class A, class B> bool chmax(A& x, const B& y) { 
	if (x < y) { x = y; return true; } return false; 
}

template <typename T, typename S> T cdiv(T x, S y) {
	assert(y);
	return (y < 0 ? cdiv(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y));
}

template <typename T, typename S> T fdiv(T x, S y) {
	assert(y);
	return (y < 0 ? fdiv(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0 : 1)));
}

template <typename T> T isqrt(T a) {
	T x = T(sqrt(a)) + 2; while (i64(1) * x * x > a) x--; return x;
}
 
void hal() {

}

int main() {
	int tc; cin >> tc;
	while (tc--) hal();
	return 0;
}
