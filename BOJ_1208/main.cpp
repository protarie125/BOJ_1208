#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll N, S;
vi as, bs;
map<ll, ll> sa, sb;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> N >> S;
	as = vi(N / 2);
	bs = vi(N - as.size());

	for (auto&& x : as) {
		cin >> x;
	}
	for (auto&& x : bs) {
		cin >> x;
	}

	const auto ma = 1 << as.size();
	const auto mb = 1 << bs.size();

	for (auto i = 1LL; i <= ma; ++i) {
		auto sum = 0LL;
		for (auto j = 0LL; j < as.size(); ++j) {
			if (i & (1LL << j)) {
				sum += as[j];
			}
		}
		sa[sum] += 1;
	}

	for (auto i = 1LL; i <= mb; ++i) {
		auto sum = 0LL;
		for (auto j = 0LL; j < bs.size(); ++j) {
			if (i & (1LL << j)) {
				sum += bs[j];
			}
		}
		sb[sum] += 1;
	}

	auto ans = ll{ 0 };
	for (const auto& [k, v] : sa) {
		ans += v * sb[S - k];
	}

	if (0 == S) {
		--ans;
	}

	cout << ans;

	return 0;
}