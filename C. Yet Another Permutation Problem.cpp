// Problem: C. Yet Another Permutation Problem
// Contest: Codeforces - Codeforces Round 893 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1858/C
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
// 



// void solve(){
	// int n;
	// cin>>n;
// 	
	// vector<int> v(n);
// 	
	// iota(v.begin(),v.end(),1);
	// cout<<1<<" ";
	// v.erase(v.begin()+1);
	// for(int i=1;i<n;i++){
		// if(i*2<n){
			// cout<<i*2<<" ";
			// i=i*2;
			// v.erase(v.begin()+i);
		// }
// 		
	// }
// 	
	// for(int num:v){
		// cout<<num<<" ";
	// }cout<<endl;
// }
// 

// void solve(){
	// int n;
	// cin>>n;
	// vector<int> v(n+1);
// 	
	// for(int i=0;i<n;i++){
		// v.pb(i+1);
	// }
// 	
	// int i=1;
	// v.erase(v.begin()+1);
	// cout<<1<<" "; 
	// while(i<=n or v.size()>0){
		// if(i*2<=n){
			// cout<<i*2<<" ";
			// auto it=find(v.begin(),v.end(),i*2)
			// i*=2;
		// }
		// else (i=1)
	// }
// 	
// 	
// 	
// }

void solve(){
	int n;
	cin>>n;
	
	vector<int> v(n+2,0);
	
	for(int i=1;i<=n;i++){
		
		int x=i;
		while(x<=n and v[x]==0){
			cout<<x<<" ";
			v[x]=1;
			x*=2;
		}
	}
	cout<<endl;
}


// 1 2 4 3 5 
// 1 2 
// 1 2 4 3 6 5 7 
// 1 2 4 8 3 6 5 10 7 9 
// each number if <n has next nuumber as its gcd else nect number in 1 to n 
// 

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