// Problem Link :- https://www.codechef.com/INOIPRAC/problems/INOI1301
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



signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...
	int n, k;
	cin>>n>>k;
	vector<int> arr(n+1);
	loop(i, 1, n){
		cin>>arr[i];
	}
	vector<int> front(n+1, 0);
	vector<int> back(n+1, 0);
	front[k+1] = arr[k+1];
	for(int i = k + 2; i <= n; i++){
		front[i] = max(front[i-1], front[i-2]) + arr[i];
	}
	back[1] = arr[1];
	back[2] = arr[1] + arr[2];
	for(int i = 3; i <= n; i++){
		back[i] = max(back[i-1], back[i-2]) + arr[i];
	}

	int res = -inf;
	for(int i = k; i <= n; i++){
		res = max(res, front[i] + back[i] - arr[i]);
	}
	cout<<res<<br;
	return 0;
}