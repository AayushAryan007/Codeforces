// Problem: C. Training Before the Olympiad
// Contest: Codeforces - Good Bye 2023
// URL: https://codeforces.com/contest/1916/problem/C
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
// 
// void solve()
// {
	// int n;
	// cin>>n;
// 	
     // vi v(n), pref(n);
     // int sum=0;
     // int maxp=0;
     // fr(i,0,n){
     	// cin>>v[i];
     	// sum+=v[i];
     	// pref[i]=sum;
     	// if(pref[i]%2!=0){
     		// ;
     	// }
     // }
     // cout<<pref[0]<<" ";
     // fr(i,1,n-1){
     	// if(pref[i]%2==1 and pref[i]!=pref[i+1])
     	// cout<<pref[i]-1<<" ";
     	// // else if(pref[i]==50)   whyyyyyyyyyyyyyyyyyyyyyyyyyy?????????
     	// else if(pref[i]==pref[i+1])
     	// cout<<pref[i]-2<<" ";
     	// else
     	// cout<<pref[i]<<" ";
//      	
     // }
     // if(pref[n-1]%2!=0)
     // cout<<pref[n-1]-1<<endl;
     // else{
     	// cout<<pref[n-1]<<endl;
     // }
// }

// void solve(){
	// ll n;
	// cin>>n;
	// vll v(n),pref(n);
	// ll sum=0;
	// fr(i,0,n){
		// cin>>v[i];
		// sum+=v[i];
		// if(i>0 and sum%2==1){
			// pref[i]=sum-1;
		// } 
		// else{
			// pref[i]=sum;
		// }
	// }
// 	
	// fr(i,0,n-1){
		// if(pref[i]==pref[i+1]){
			// cout<<pref[i]-2<<" ";
		// }
		// else{
		 // cout<<pref[i]<<" ";
		// }
	// }cout<<pref[n-1]<<endl;
// }
// 
// void solve() {
    // int n;
    // cin >> n;
    // int maxi = 0;
    // vector<int> v(n), pref(n);
    // for (int i = 0; i < n; ++i) {
        // cin >> v[i];
        // pref[i] = v[i];
    // }
    // maxi = pref[0];
    // cout << pref[0] << " ";
    // for (int i = 1; i < n; ++i) {
        // maxi = max(maxi, v[i]); // Fixing the typo here by adding the missing parenthesis
        // pref[i] = max(pref[i - 1], int(maxi * 1LL * (i + 1) / 2)); // Ensuring the calculation type matches
        // cout << pref[i] << " ";
    // }
    // cout << endl;
// }
void solve(){
	ll n;
	cin>>n;
	vll v(n),pref(n);
	ll sum=0;
	ll odd=0;
	fr(i,0,n){
		cin>>v[i];
		sum+=v[i];
		if(v[i]%2==1)
		odd++;
		// ll temp=(sum-((odd%3)%2));
		if(i==0)
		cout<<sum<<" ";
		else cout<<sum-(odd/3)-(odd%3==1)<<" ";
		// else if(i>0 and temp%2==1 )
		// cout<<temp-1<<" ";
		// else
		// cout<<sum<<" ";
		
		// if(i>0 and sum%2==1){
			// pref[i]=sum-1;
		// } 
		// else{
			// pref[i]=sum;
		// }
	}
	cout<<endl;
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