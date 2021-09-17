// Problem Link :- https://www.spoj.com/problems/MPILOT/
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

int n;
vector<int> cap(10005, 0);
vector<int> ass(10005, 0);
int dp[10005][5005];

int f(int i, int a, int c){
	if(i == n)	return 0;
	if(dp[i][a] != -1)	return dp[i][a];

	if(a == n/2){
		return dp[i][a] = f(i+1, a, c+1) + cap[i];
	} else if(a == c){
		return dp[i][a] = f(i+1, a+1, c) + ass[i];
	} else{
		return dp[i][a] = min(f(i+1, a, c+1) + cap[i], f(i+1, a+1, c) + ass[i]);
	}
}

int g(int i, int x){
	if(i == n)	return 0;
	if(dp[i][x] != -1)	return dp[i][x];
	if(x == n/2){
		return dp[i][x] = g(i+1, x) + cap[i];
	} else if(x == (i-x)){
		return dp[i][x] = g(i+1, x+1) + ass[i];
	} else{
		return dp[i][a] = min(g(i+1, x+1) + ass[i], g(i+1, x) + cap[i]);
	}
}

signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>cap[i]>>ass[i];
	}
	memset(dp, -1, sizeof dp);
	// cout<<f(1, 1, 0) + ass[0];
	cout<<g(1, 1) + ass[0];
	return 0;
}