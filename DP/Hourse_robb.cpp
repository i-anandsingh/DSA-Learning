// Problem Link :- https://leetcode.com/problems/house-robber/
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

int dp[100];
int houseRobTD(int i, vector<int>& arr){
	if(i == 0)
		return arr[0];
	if(i == 1)
		return max(arr[1], arr[0]);
	if(dp[i] != -1)
		return dp[i];
	return dp[i] = max(houseRobTD(i-1, arr), arr[i] + houseRobTD(i-2, arr));
}

int houseRobBU(){
	vector<int> v(n-1, 0);
	v[0] = arr[0];
	v[1] = max(arr[0],arr[1]);; 
	for(int i = 2; i < n; i++)
		v[i] = max(v[i-1], arr[i]+v[i-2]);
	return v[n-1];
}

signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...

	return 0;
}