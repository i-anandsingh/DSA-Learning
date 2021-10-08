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

vector<int> d = {4,2,3,1,3};
int dp[1005][1005];
int mcm(int i, int j){
	if(i == j)	return 0;
	if(dp[i][j] != -1)	return dp[i][j];
	int result = inf;
	for(int k = i; k <= j-1; k++){
		result = min(result, mcm(i, k) + mcm(k+1, j) + d[i-1]*d[k]*d[j]);
	}
	return dp[i][j] = result;
}

int mcmBU(){
	int n = d.size();
	vector<vector<int>> dp(n, vector<int> (n, 0));
	for(int len = 3; len <= n; len++){
		for(int i = 1; i <= n-len+1; i++){
			int j = i+len-2;
			int cnt = INT_MAX;
			for(int k = i; k <= j-1; k++){
				cnt = min(cnt,dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j]);
			}
			dp[i][j] = cnt;
		}
	}
	return dp[1][n-1];
}
signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...
	memset(dp, -1, sizeof dp);
	// cout<<mcm(1, d.size()-1);
	cout<<mcmBU();
	return 0;
}