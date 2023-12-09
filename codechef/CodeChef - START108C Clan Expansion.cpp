// Problem: Clan Expansion
// Contest: CodeChef - START108C
// URL: https://www.codechef.com/START108C/problems/CLANEXPNSN
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h> 
using namespace std;  
#define endl "\n"
#define lo long long
#define dob long double
#define ll long long int
#define mod 1e9+7
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fr(i, x, n) for (int i = x; i < n; i++)
#define nfr(i, x, n) for (int i = x; i > n; i--)

#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
#define in(v)  for(auto &item : v) cin>>item;
#define inp(v)  for(auto &item : v) cin>>item.ff>>item.ss;

#define ss second
#define ff first
//count set bits\|/
#define bp(a) __builtin_popcount(a)

int binpow(int a, int b)
{
  if(b==0)
  return 1;
  int res=binpow(a,b/2);

  if(b%2)
  return res*res*a;
  else
  return res*res;
}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

bool isprime(long long int n)  //to check prime
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)return false;
    }
    return true;
}


int LIS(vector<int> &a)//returns longest non decreasing subsequence
{
  //lnds[i]=element at which an increasng subsequence of length 'i' ends

  vector<int> lis;
  for(auto &x:a)
  {
    auto it=upper_bound(lis.begin(),lis.end(), x); //upper_bound for non-decreasing
    if(it==lis.end())
    lis.push_back(x);
    else
    *it=x;
  }

  return lis.size();
}
 
 //iota(v.begin(),v.end(),1); assign 1-n incrementation in vector
 void reverse(int arr[], int index, int count)
{
    if (index < count)
    {
        swap(arr[index], arr[count]);
        reverse(arr, index + 1, count - 1);
    }
}

//print binary of int ,10 bits
void printBinary(int num){
	for(int i=10;i>=0;i--){
		cout<<((num>>i)&1);
	}
	cout<<endl;
}

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

// pair<int, int> conquerIsland(int N, const vector<int>& territories) {
    // int minDays = INT_MAX;
    // int conquerorClan = -1;
//   
    // for (int i = 0; i <N; ++i) {
    	// vector<int>x=territories;
        // int days = 0;
        // int flag=1;
//     
        // while(flag){
//         
        	   // flag=0;
        	   // for(int k=0;k<N;k++){
        	    	 // if(x[k]!=x[i] and(x[k+1]==x[i] or x[k-1]==x[i])){  
        	    	// x[k]=x[i];
        	    	// flag=1;
           	   // }
        	   // }
//         	  
//         	  
        	  // days++;
//         	 
//         	  
        // }
//         
//         
//         
//       
        // if (days < minDays) {
            // minDays = days;
            // conquerorClan = territories[i];
        // }
    // }
// 
    // return make_pair(conquerorClan, minDays);
// }
// 
// void solve(int N) {
    // vector<int> territories(N);
    // for (int i = 0; i < N; ++i) {
        // cin >> territories[i];
    // }
// 
    // auto result = conquerIsland(N, territories);
// 
    // cout << result.first << " " << result.second << endl;
// }
    
    void solve(){
    	 int n;
        cin >> n;
        
        
        
        vector<int> l1(n);
        
               unordered_map<int, int> ddd1, ddd2;

         for (int i = 0; i < n; ++i) {
            cin >> l1[i];
            if (ddd1.find(l1[i]) == ddd1.end()) {
               ddd1[l1[i]] = i;
               ddd2[l1[i]] = i;
            } else {
            	
            	
                ddd2[l1[i]] = max(ddd2[l1[i]], (i - ddd1[l1[i]]) / 2);
                ddd1[l1[i]] = i;
            }
        }

        long long minimm = LLONG_MAX;
        int j = 0;

        for (auto &i : ddd2) {
            int k = max(n - 1 - ddd1[i.first], i.second);
            if (k < minimm) {
                j = i.first;
                minimm = k;
            } else if (k == minimm && j > i.first) {
                j = i.first;
            }
        }

        cout << j << " " << minimm << endl;
    }



int main()  
{
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); cout.tie(NULL); // flushes cout  
    
    //start writing below
    int t;
    cin>>t;
    while(t--)
    {
    	
       solve(); 
    }
 
    return 0;  
}