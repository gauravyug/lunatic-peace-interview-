/*	ANKAM NIKHIL */
#include <bits/stdc++.h>
 
#define ull unsigned long long
#define ll long long int
#define MAX 10010
#define mod 1000000007 
#define isc(n) scanf("%d", &n) 
#define lsc(n) scanf("%lld", &n)
#define usc(n) scanf("%llu", &n)
#define REP(i, s, e) for(int i=s;i<=e;i++)
#define RREP(i, s, e) for(int i=s;i>=e;i--)
#define nl printf("\n")
#define sp printf(" ")
#define pt(val) printf("%d", val)
#define lpt(val) printf("%lld", val)
 
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
 
using namespace std;
 
int n;
int ans ;
 
void backtrack(int grid[][5], int clvl, int sPos, int bomb, int coins){
	// cout<<clvl<<endl;
	if(clvl==-1){
		ans = max(ans, coins);
		return ;
	}
	for(int i=0;i<5;i++){
		if(grid[clvl][i]==2){
			ans = max(ans, coins);
			return ;
		}
	}
 
 
	if(bomb==1){		//if bomb is available to use
		int cl = clvl;
		vector<pii> vec;
		while(cl>=0 && cl>(clvl-5)){
			for(int itr=0;itr<5;itr++){
				if(grid[cl][itr]==2){
					grid[cl][itr] = 0;
					vec.pb({cl, itr});
				}
			}
			cl--;
		}
 
		int add = 0;
		if(sPos!=0){	//moving left
			add = (grid[clvl][sPos-1]==1)?1:0;
			backtrack(grid, clvl-1, sPos-1, 0, coins+add);
		}
		add = (grid[clvl][sPos]==1)?1:0; //not moving
		backtrack(grid, clvl-1, sPos, 0, coins+add);
		if(sPos!=4){	//moving right
			add = (grid[clvl][sPos+1]==1)?1:0;
			backtrack(grid, clvl-1, sPos+1, 0, coins+add);
		}
 
 
		while(vec.size()>0){
			pii temp = vec.back();
			vec.pop_back();
			grid[temp.fi][temp.se] = 2;
		}
 
	}
 
 
	int add = 0;
	if(sPos!=0){	//move left
		add = (grid[clvl][sPos-1]==1)?1:0;
		backtrack(grid, clvl-1, sPos-1, bomb, coins+add);
	}
	add = (grid[clvl][sPos]==1)?1:0;	//stay still
	backtrack(grid, clvl-1, sPos, bomb, coins+add);
	if(sPos!=4){	// move right
		add = (grid[clvl][sPos+1]==1)?1:0;
		backtrack(grid, clvl-1, sPos+1, bomb, coins+add);
	}
 
 
}
 
int main() {
 
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
 
	int t = 1;
 
	int grid[6][5] = {
                                {0,1,1,2,0},
                                {0,2,1,2,1},
                                {0,2,1,1,1},
                                {1,0,1,0,0},
                                {0,0,1,2,2},
                                {1,1,0,0,1}
                          };
      
        // isc(t);
/*	cin>>t;
	while(t-->0){
		cin>>n;
		int grid[n][5];
		for(int i=0;i<n;i++){
			for(int j=0;j<5;j++){
				cin>>grid[i][j];
			}
		}
		ans = 0;
		backtrack(grid, n-1, 2, 1, 0);
		cout<<ans<<endl;
*/	
        ans = 0; 
	backtrack(grid, 5, 2, 1, 0);
		cout<<ans<<endl;
	return 0;
}
 
/* CPP */
