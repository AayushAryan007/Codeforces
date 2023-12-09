// Problem: C. Raspberries
// Contest: Codeforces - Codeforces Round 905 (Div. 3)
// URL: https://codeforces.com/contest/1883/problem/C
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

void solve()
{
  ll n,k;
 cin>>n>>k;
 
 map<ll,ll> mp;
 ll x,p=1;
    
    for(int i=0;i<n;i++)
    {
    	cin>>x;
    	p*=x;
    	p%=k;
    	mp[x%k]++;
    }
    
    if(p%k==0)
    {
    	cout<<0<<endl;
    	return;
    }
    
    if(k==2){
    	cout<<1<<endl;
    	return;
    }
    
    if(k==3){
    	if(mp[2])
    	cout<<1<<endl;
    	
    	else
    	   cout<<"2\n";
    }
    
   if(k==4){
     if(mp[3]) cout<<"1\n";
     else if(mp[2] && mp[1]) cout<<"1\n";
     else if(mp[2]) cout<<"2\n";
     else if(mp[1]>1) cout<<"2\n";
     else if(mp[1]) cout<<"3\n";
 }
    
    if(k==5){
     if(mp[4]) cout<<"1\n";
     else if(mp[3]) cout<<"2\n";
     else if(mp[2]) cout<<"3\n";
     else cout<<"4\n";
 }
    
     
}


int main()  
{
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); cout.tie(NULL); // flushes cout  
    
    //start writing below
    ll t;
    cin>>t;
    while(t--)
    {
       solve(); 
    }
 
    return 0;  
}