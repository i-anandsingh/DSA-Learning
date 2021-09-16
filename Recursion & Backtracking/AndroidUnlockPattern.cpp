// Problem Link :- https://leetcode.com/problems/android-unlock-patterns/
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

void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int helper(vector<vector<int>> &via, vector<bool> &vis, int curr, int remaining, string osf){
    if(remaining < 0)
        return 0;
    if(remaining == 0){
    	cout<<osf<<br;
        return 1;
    }
    vis[curr] = true;
    int res = 0;
    for(int i = 1; i <= 9; i++){
        if(!vis[i] and (via[curr][i] == 0 or vis[via[curr][i]]))
            res += helper(via, vis, i, remaining-1, osf+to_string(i));
    }
    vis[curr] = false;
    return res;
}

int unlock(int m, int n){
	vector<bool> vis(10, false);
    vector<vector<int>> via(10, vector<int> (10));
    int ways = 0;
    via[1][3] = via[3][1] = 2;
    via[1][7] = via[7][1] = 4;
    via[3][9] = via[9][3] = 6;
    via[7][9] = via[9][7] = 8;
    via[1][9] = via[9][1] = via[3][7] = via[7][3] = via[4][6] = via[6][4] = via[8][2] = via[2][8] = 5;
    for(int i = m; i <= n; i++){
        // ways += helper(via, vis, 1, i-1)*4;
        // ways += helper(via, vis, 2, i-1)*4;
        // ways += helper(via, vis, 5, i-1);
        for(int j = 1; j <= 9; j++){
        	ways += helper(via, vis, j, i-1, ""+to_string(j));
        }
    }
    return ways;
}

signed main(int32_t argc, char const *argv[]){
    file_i_o();
	//Write your code here...
	int m, n;
	cin>>m>>n;
	cout<<unlock(m, n)<<br;
	return 0;
}