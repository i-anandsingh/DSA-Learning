// Problem Link :- 
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

vector<int> wt;
vector<int> c;
int dp[105][100005];

// constraints :- n <= 10^2, W <= 10^5, wi <= W, ci <= 10
// TC :- O(nW) SC :- O(nW)
int knapsackTD(int i, int W, int n){
	if(i == n)	return 0;
	if(W <= 0)	return 0;

	if(dp[i][W] != -1)	return dp[i][W];
	// pick
	int f1 = 0;
	if(wt[i] <= W){
		f1 = c[i] + knapsackTD(i+1, W-wt[i], n);
	}
	// not pick
	int f2 = knapsackTD(i+1, W, n);
	return dp[i][W] = max(f1, f2);
}

// TC :- O(nW) SC :- O(nW)
int knapsackBU(int W, int n){
	vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= W; j++){
			dp[i][j] = dp[i-1][j];
			if(wt[i] <= j){
				dp[i][j] = max(dp[i][j], c[i] + dp[i-1][j-wt[i]]);
			}
		}
	}
	return dp[n][W];
}

// TC :- O(nW) SC :- O(W)
int knapsackBUBetter(int W, int n){
	vector<int> dp1(W+1, 0);
	vector<int> dp2(W+1, 0);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= W; j++){
			//dp[i][j] = dp[i-1][j]
			dp2[j] = dp1[j];
			if(wt[i] <= j){
				dp2[j] = max(dp1[j], c[i] + dp1[j-wt[i]]);
			}
		}
		dp1 = dp2;
		dp2.clear();
	}
	return dp1[W];
}
// all the above approaches will work for the above given constraint

signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...
	memset(dp, -1, sizeof dp);
	int n, W;
	cin>>n>>W;
	wt.pb(0);	// when BU
	c.pb(0);	// when BU
	for(int i = 0; i < n; i++){
		int w, cost;
		cin>>w>>cost;
		wt.pb(w);
		c.pb(cost);
	}
	// cout<<knapsackTD(0, W, n);
	// cout<<knapsackBU(W, n);
	cout<<knapsackBUBetter(W, n);
	return 0;
}