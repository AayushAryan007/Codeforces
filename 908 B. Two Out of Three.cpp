// Problem: B. Two Out of Three
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
// void solve() {
    // int n;
    // cin >> n;
// 
    // int arr[n];
    // int flag = 1;
    // int flag2 = 0;
    // map<int, int> m;
// 
    // for (int i = 0; i < n; i++) {
        // cin >> arr[i];
// 
        // m[arr[i]]++;
//         
        // if (m[arr[i]] >= 2) {
            // flag2 = 1;
        // }
    // }
    // for(const auto& i:m){
    	// if(i.second>3 and i.second%2!=0){
    		// cout<<-1<<endl;
    		// return;
    	// }
    // }
// 
    // if (m.size() <= 1 or n<=3) {
        // cout << -1 << endl;
        // return;
    // } else {
        // for (int i = 0; i < n; i++) {
            // if (m[arr[i]] == 3 || m[arr[i]] == 2) {
                // cout << 1 << " ";
                // m[arr[i]]--;
            // } else {
                // cout << 2 << " ";
                // m[arr[i]]--;
            // }
        // }
        // cout << endl;
    // }
// }
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> frequency;
    for (int i = 0; i < n; i++) {
        frequency[a[i]]++;
    }

    int repeatingCount = 0;
    for (auto x : frequency) {
        if (x.second > 1) {
            repeatingCount++;
        }
    }

    if (repeatingCount <= 1) {
        cout << -1 << endl;
    } else {
        vector<int> selectedValues;
        for (auto x : frequency) {
            if (x.second > 1) {
                selectedValues.push_back(x.first);
                if (selectedValues.size() == 2) {
                    break;
                }
            }
        }

        int first = selectedValues[0], second = selectedValues[1];
        map<int, int> valueMap;
        valueMap[first] = 1;  // 1 - 2
        valueMap[second] = 2; // 2 - 3

        for (int i = 0; i < n; i++) {
            if (a[i] == first) {
                cout << valueMap[first] << " ";
                valueMap[first] = 3 - valueMap[first];
            } else if (a[i] == second) {
                cout << valueMap[second] << " ";
                valueMap[second] = 5 - valueMap[second];
            } else {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }
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