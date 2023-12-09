// Problem: Maximal Expression
// Contest: CodeChef - START107C
// URL: https://www.codechef.com/START107C/problems/MAXIMALEXP
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

ll go(ll n, ll x, ll k) {
    return (x % k) * ((n - x) % k);
}
void solve() {
        ll n, k;
    cin >> n >> k;
    ll x = 0, ans = -1;

    ll now = n % k;
    now /= 2;
    if (ans < go(n, now, k)) {
        ans = go(n, now, k);
        x = now;
    }

    vector<ll> candidates = {n - 1, k - 1, (n % k) / 2 + 1};
    now = *min_element(candidates.begin(), candidates.end());
    if (ans < go(n, now, k)) {
        ans = go(n, now, k);
        x = now;
    }

    candidates = {n - 1, k - 1, n % k + (k - n % k) / 2};
    now = *min_element(candidates.begin(), candidates.end());
    if (ans < go(n, now, k)) {
        ans = go(n, now, k);
        x = now;
    }

    candidates = {n - 1, k - 1, n % k + (k - n % k) / 2 + 1};
    now = *min_element(candidates.begin(), candidates.end());
    if (ans < go(n, now, k)) {
        ans = go(n, now, k);
        x = now;
    }

    cout << x << endl;
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