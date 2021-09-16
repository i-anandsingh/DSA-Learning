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

int ways = 0;

bool isValid(int i, int j, int n){
	 return i < n and i >= 0 and j < n and j >= 0;
}

bool isSafe(int row, int col, int n, vector<vector<bool>> &board){
	if(isValid(row-2, col-1, n) and board[row-2][col-1])
		return false;
	if(isValid(row-2, col+1, n) and board[row-2][col+1])
		return false;
	if(isValid(row-1, col-2, n) and board[row-1][col-2])
		return false;
	if(isValid(row-1, col+2, n) and board[row-1][col+2])
		return false;
	return true;
}

void display(int n, vector<vector<bool>> &b){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j])
				cout<<'K';
			else
				cout<<'.';
		}
		cout<<br;
	}
	cout<<"------------\n";
}

void nkights(int sr, int sc, int n, int placed, vector<vector<bool>> &board){
	if(placed == n){
		display(n, board);
		ways++;
		return;
	}
	for(int row = sr; row < n; row++){
		for(int col = ((row == sr) ? sc : 0); col < n; col++){
			if(isSafe(row, col, n, board) and !board[row][col]){
				board[row][col] = true;
				nkights(row, col+1, n, placed+1, board);
				board[row][col] = false;
			}
		}
	}
}
signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...
	int n;
	cin>>n;
	vector<vector<bool>> b(n, vector<bool> (n,0));
	nkights(0,0,n,0,b);
	cout<<ways<<br;
	return 0;
}