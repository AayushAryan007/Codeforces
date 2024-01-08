// Problem: C. Number of Pairs
// Contest: Codeforces - Codeforces Round 725 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1538/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h> 
using namespace std;  
#define endl "\n"
#define lo long long
#define dob long double
#define ll long long int
#define mod 1000000007
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fr(i, x, n) for (ll i = x; i < n; i++)
#define nfr(i, x, n) for (int i = x; i > n; i--)
#define sp(x) setprecision(x)
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
#define in(v)  for(auto &item : v) cin>>item;
#define inp(v)  for(auto &item : v) cin>>item.ff>>item.ss;
#define ub(x) upper_bound(x)

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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int lowpowerof2(int n) { return 1LL << (int)log2(n); }
int highpowerof2(int n) { return 1LL << (int)ceil(log2(n)); }
bool ispowerof2(int n) { return (n != 0) && ((n & (n - 1)) == 0); }

// int gcd(int a, int b)
// {
    // // Everything divides 0
    // if (a == 0)
       // return b;
    // if (b == 0)
       // return a;
//   
    // // base case
    // if (a == b)
        // return a;
//   
    // // a is greater
    // if (a > b)
        // return gcd(a-b, b);
    // return gcd(a, b-a);
// }

//prime ll
bool isprime(long long int n)  //to check prime
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)return false;
    }
    return true;
}
//prime int
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
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

// //brute didnt work
// void solve()
// {
     // ll n,l,r;
     // cin>>n>>l>>r;
//     
     // vll v(n);
     // for(ll i=0;i<n;i++){
     	// cin>>v[i];
     // }
     // ll count=0;
     // fr(i,0,n-1){
     	// fr(j,i+1,n){
     		// if(v[i]+v[j]>=l and v[i]+v[j]<=r)
     		// count++;
     	// }
     // }
     // cout<<count<<endl;
// }
// 

// void solve(){
    // ll n,l,r;
	// cin>>n>>l>>r;
	 // vll v(n);
// 	
	 // fr(i,0,n){cin>>v[i];}
	 // sort(all(v));
	 // ll ans=0;
	 // fr(i,0,n){
	 	// ll up=upper_bound(all(v),r-v[i])-v.begin();
	 	// ll down=lower_bound(all(v),l-v[i])-v.begin();
	 	// if(i<up and i>=down){
	 		// down++;
// 	 		
// 	 		
	 	// }
	 	// if(up>down){
	 		// ans=ans+up-down;
	 	// }
// 	 	
	 // }cout<<ans/2<<endl;
// }
void solve()
{
	ll n,l,r;
	cin>>n>>l>>r;
	
	vll v(n);
	fr(i,0,n){
		cin>>v[i];
	}sort(all(v));
	ll ans=0;
	// fr(i,0,n){
		// ll ub=upper_bound(v.begin(),v.end(),r-v[i])-v.begin();
		// ll lb=lower_bound(v.begin(),v.end(),l-v[i])-v.begin();
		// if(i<ub and i>=lb)
		// lb++;
	// ans+=ub-lb;
// 	
	// }
	// cout<<ans/2<<endl;
	fr(i,0,n-1){
		auto lb=lower_bound(v.begin()+i+1,v.end(),l-v[i]);
		auto up=upper_bound(v.begin()+i+1,v.end(),r-v[i]);
		ans+=up-lb;
	}
	cout<<ans<<endl;
	
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
    
    // solve();
 
    return 0;  
}