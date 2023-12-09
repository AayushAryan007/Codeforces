// Problem: B. Monsters
// Contest: Codeforces - Educational Codeforces Round 152 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1849/B
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
#define pq priority_queue
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

// void solve() {
    // ll n, k;
    // cin >> n >> k;
// 
    // auto compare = [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        // if (a.first == b.first) {
            // return a.second > b.second;
        // }
        // return a.first < b.first;
    // };
// 
    // priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(compare)> p(compare);
// 
    // for (ll i = 1; i <= n; i++) {
        // ll x;
        // cin >> x;
        // p.push(make_pair(x, i));
    // }
// 
    // while (!p.empty()) {
        // pair<ll, ll> top = p.top();
        // p.pop(); // Pop the top element
//         
        // ll ind = top.second;
        // ll prin = top.first - k;
// 
        // if (prin <= 0) {
            // cout << ind << " ";
        // } else {
            // p.push({prin, ind}); // Push the updated value back into the priority queue
        // }
    // }
    // cout << endl;
// }
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>ans;
	map<int,vector<int>,greater<int>>mp;
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		if(temp%k==0) ans.pb(i);
		else mp[temp%k].pb(i);
	}
	for(auto x:mp){
		for(auto y:x.second) ans.pb(y);
	}
	for(auto x:ans) cout<<x<<" ";
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