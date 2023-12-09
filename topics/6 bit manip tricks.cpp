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

//print binary of int ,10 bits
void printBinary(int num){
	for(int i=10;i>=0;i--){
		cout<<((num>>i)&1);
	}
	cout<<endl;
}

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void solve()
{
	

	
// 	

//check if a number is 2 power

int n;
cin>>n;
if(n &(n-1))
	cout<<"not power of 2"<<endl;
	else
	cout<<"power of 2"<<endl;
}
	// LUV ep 49 for more about clear msb lsb
	
	
	// int n;
	// cin>>n;
	
	
	/////////////////////////////////////////////////////////////////////////////
	// //upper to lowercase char vice versa
	// for(char c='A' ; c<='E';c++){
		// cout<<c<<endl;
		// printBinary(int(c));
	// }
	// for(char c='a' ; c<='e';c++){
		// cout<<c<<endl;
		// printBinary(int(c));
	// }
// 	
	// char A='A';
	// char a=A|(1<<5);
	// cout<<a<<endl;
	// cout<<char(a&(~(1<<5)))<<endl;
// 	
	// cout<<char(1<<5)<<endl; //prints space
	// cout<<char('C'|' ')<<endl;//prints lowercase
// 	
	// printBinary(int('_'));
	// cout<<char('c'&'_')<<endl; //prints to uppercase using masking
// 	
	// //observe that second most imp bit (5th) is set in lower case rest is same
// 	
	////////////////////////////////////////////////////////////////////////////////
	// //multiply divide by 2
// 	
	// //n/2
	// cout<<(n>>1)<<endl;
	// //n*2
	// cout<<( n<<1)<<endl;
	// //int binary search (high+low)/w ====(high+low)>>1 is a faster way 
	
	//////////////////////////////////////////////////////////////////////////////////
	//even odd check
    // for(int i=0;i<n;i++){
    	// printBinary(i);
//     	
    	// //check odd even by and 1
    	// if(i&1){
    		// cout<<"ODD"<<endl;
    	// }
    	// else
    	// cout<<"EVEN"<<endl;
    // } 
    ////////////////////////////////////////////////////////////////////////////////// 
    



int main()  
{
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); cout.tie(NULL); // flushes cout  
    
    //start writing below
   
       solve(); 
    
 
    return 0;  
}