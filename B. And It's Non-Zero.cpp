// Problem: B. And It's Non-Zero
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/problemset/problem/1615/B
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
// 
// long long powi(long long base, long long exponent) {
    // long long result = 1;
    // while (exponent > 0) {
        // if (exponent % 2 == 1) {
            // result *= base;
        // }
        // base *= base;
        // exponent /= 2;
    // }
    // return result;
// }

//i power of number function
int powi(int base, int exponent) {
     int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
// int minElementsToDelete(int l, int r) {
    // int result = 0;
// 
    // // Find the leftmost set bit position in l and r
    // int leftmostSetBitL = 0, leftmostSetBitR = 0;
    // int tempL = l, tempR = r;
// 
    // while (tempL > 0) {
        // leftmostSetBitL += 1;
        // tempL >>= 1;
    // }
// 
    // while (tempR > 0) {
        // leftmostSetBitR += 1;
        // tempR >>= 1;
    // }
// 
    // // If leftmost set bit position is different, delete all elements
    // if (leftmostSetBitL != leftmostSetBitR) {
        // result = r - l + 1;
    // } else {
        // // Find the rightmost set bit position in l and r
        // int rightmostSetBitL = 0, rightmostSetBitR = 0;
        // tempL = l, tempR = r;
// 
        // while ((tempL & 1) == 0) {
            // rightmostSetBitL += 1;
            // tempL >>= 1;
        // }
// 
        // while ((tempR & 1) == 0) {
            // rightmostSetBitR += 1;
            // tempR >>= 1;
        // }
// 
        // // Count the number of unset bits between leftmost and rightmost set bits
        // int unsetBitsCount = leftmostSetBitL - rightmostSetBitL - 1;
        // result = std::max(0, r - l + 1 - (1 << unsetBitsCount));
    // }
// 
    // return result;
// }
// void solve()
// {
    // int l,r;
    // cin>>l>>r; 
    // int result = minElementsToDelete(l, r);
       // cout << result <<endl;
// }


//pre calculations

ll N = 2e5 + 1;
vector<vector<ll>> arr(N, vector<ll>(19, 0));

void pp() {
	
 fr(i,0,19)
    arr[0][i]=0;
    fr(i, 1, N ) {
        ll in = 0;
        ll x = i;
        while (x > 0) {
            arr[i][in] = x % 2 + arr[i - 1][in];
            x /= 2;
            in++;
        }
    }
}

void solve() {
    ll l, r;
    cin >> l >> r;

    ll m = LONG_LONG_MIN;

    fr(i, 0, 19) {
        m = max(m, arr[r][i] - arr[l - 1][i]);
    }
    cout << r - l + 1 - m << endl;
}

int main()  
{
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); cout.tie(NULL); // flushes cout  
    
    //start writing below
    pp();
    int t;
    cin>>t;
    while(t--)
    {
       solve(); 
    }
    
    // solve();
 
    return 0;  
}