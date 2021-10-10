// Problem Link :- https://codeforces.com/problemset/problem/429/B
/* By- Anand Singh */    
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define getFast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define br "\n"
#define inf 1e18
#define pi 3.1415926535897
#define mp make_pair
#define int long long int
#define ld long double
#define mid(l,r)  (l+(r-l)/2)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define ub(x, k)    upper_bound((x).begin(), (x).end(), k);
#define lb(x, k)    lower_bound((x).begin(), (x).end(), k);
#define loop(i, a, x)    for(int i = (a); i <= (x); i++)
#define bpc(n)    __builtin_popcount(x)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
typedef vector<bool>    vb;
typedef vector<int>    vi;
typedef pair<int, int>    pii;
typedef vector<pii>    vp;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

int calWork(vector<vector<int>> &v, int n, int m){
	vector<vector<int>> f(n+2, vector<int> (m+2, 0));
	vector<vector<int>> g(n+2, vector<int> (m+2, 0));
	vector<vector<int>> h(n+2, vector<int> (m+2, 0));
	vector<vector<int>> a(n+2, vector<int> (m+2, 0));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			f[i][j] = max(f[i-1][j], f[i][j-1]) + v[i][j];
		}
	}

	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			g[i][j] = max(g[i+1][j], g[i][j+1]) + v[i][j];
		}
	}

	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			h[i][j] = max(h[i+1][j], h[i][j-1]) + v[i][j];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			a[i][j] = max(a[i][j+1], a[i-1][j]) + v[i][j];
		}
	}

	int ans = -inf;
	for(int i = 2; i < n; i++){
		for(int j = 2; j < m; j++){
			ans = max(ans, f[i][j-1] + g[i][j+1] + h[i+1][j] + a[i-1][j]);
			ans = max(ans, f[i-1][j] + g[i+1][j] + h[i][j-1] + a[i][j+1]);
		}
	}
	return ans;
}

signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...
	int n, m;
	cin>>n>>m;
	vector<vector<int>> v(n+1, vector<int> (m+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin>>v[i][j];
		}
	}
	cout<<calWork(v, n ,m);
	return 0;
}