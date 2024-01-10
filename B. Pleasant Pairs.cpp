// Problem: B. Pleasant Pairs
// Contest: Codeforces - Codeforces Round 728 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1541/B
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

// void solve() {
    // ll n;
    // cin >> n;
    // vector<ll> v(n);
    // vector<pair<int,int>> vp;
    // for (ll i = 0; i < n; ++i) {
        // cin >> v[i];
        // // vp[i].first=v[i];
        // // vp[i].second=i+1;
// //       
        // vp.push_back({v[i],i+1});  
    // }   
//     
    // sort(all(vp));
//     
    // ll count = 0;
//       
    // for (ll i = 0; i < n - 1; ++i) {
        // for (ll j = i + 1; j < n; ++j) {
//         	
        	// if(i*j>2*n){
        		// break;
        	// }
           // else {
//             	
            	// if(v[i]*v[j]==i+j+2)
            	// count++;
            // }
            // // if(vp[i].second*vp[j].second>2*n)
            // // break;
            // // else{
            	// // if(vp[i].first*vp[j].first==vp[i].second+vp[j].second)
            	// // count++;
            // // }
        // }
    // }
    // cout << count << endl;
// }
// 

void solve(){
	
	ll n;
	cin>>n;
	
	vll v(n);
	
	map<ll,ll> m;
	fr(i,0,n){
		cin>>v[i];
		m[v[i]]=i+1;
	}
	ll ans=0;
	for(ll i=1;i<=2*n;i++){
		for(ll j=i+1;j<=2*n;j++){
			if(i*j>2*n) break;
			
			ll prod=i*j;
			auto ind1=m.find(i);
			auto ind2=m.find(j);
			if(ind1==m.end() or ind2==m.end()) continue;
			
			if((*ind1).ss + (*ind2).ss==prod) ans++;
		}
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