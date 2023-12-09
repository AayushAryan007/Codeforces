// Problem: A. Channel
// Contest: Codeforces - Pinely Round 2 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1863/A
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
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void solve()
{
     int  n,a,q;
     cin>>n>>a>>q;
     
     string s;
     cin>>s;
     
     int f=0;
     
     int plus=0,minus=0,read=0;
     read=a;
      if(a==n){
     	cout<<"YES"<<endl;
     	return;
     }
     for(int i=0;i<q;i++)
     {
     	if(s[i]=='+')
     	{plus++;
     	read++;
     	a++;}
     	
     	else
    {
    	minus++;
    	read--;
    }
     	
     	
     	if(read==n){
     		f=1;
     		break;
     	}}
     	
     	if(f==1)
     	{
     		cout<<"YES"<<endl;
     		
     	}
     	else{
     		if(a>=n)
     		{
     			cout<<"MAYBE"<<endl;
     		}
     		else{
     			cout<<"NO"<<endl;
     		}
     	}
     
     
     
    
     
     
     // if((a==n)||(plus>minus and a+plus>=n))
     // {
      // cout<<"YES"<<endl;
      // return;
     // }
     // if(plus==minus and a+plus>=n)
     // {
     	// cout<<"MAYBE"<<endl;
     	// return;
     // }
     // if(a==0){
     	// cout<<"NO"<<endl;
     // return;
     // }
//      
     // if(a+plus+minus<n and a+q<n)
     // {cout<<"NO"<<endl;
     // return;}
//      
     // else
     // {
     	// cout<<"NO"<<endl;
     	// return;
     // }
//      
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