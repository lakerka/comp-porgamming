#include <tr1/unordered_map>
#include <streambuf>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <fstream>
 
using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#define oo 0x3F3F3F3F
#ifdef DEBUG
#define cvar(x) cerr << "<" << #x << ": " << x << ">"
#define evar(x) cvar (x) << endl
template<class T> void DISP (const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP (#x " to " #n, x, n)
#else
#define cvar(...) ({})
#define evar(...) ({})
#define disp(...) ({})
#endif
#ifdef WIN32
#define fmt64 "%I64d"
#else
#define fmt64 "%lld"
#endif
#define MKP make_pair
#define Px first
#define Py second
#define PB push_back
#define LEN length()
#define SIZE size()
#define sz_m(x) (int)((x).size ())
#define iter(x) (x).begin (), (x).end ()
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef set<int> SI;
typedef set<string> SS;
typedef pair<int, int> PII;
typedef pair<string, int> PSI;

template<class T> inline bool chkmin (T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax (T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr (T x) {return x * x;}

//read all file
//void read() {
  //ifstream in("calfflac.in");
  //string init((istreambuf_iterator<char>(in)),
                  //istreambuf_iterator<char>());
  //cout << init << endl;
  //in.close();
//}

const string OUT = ".out";
const string IN = ".in";

LL gcd(LL a, LL b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

LL lcm(LL a, LL b) {
	return a/gcd(a, b)*b;
}

//const int MAXP = int(1e6);
//const int MAXPRIME = int(1e5);
//int prime[MAXPRIME];
//int isPrime[MAXP];
//void erastoten() {
	//int i;
	//isPrime[2];
	//for(int i = 3; i < MAXP; i+= 2) {
		//isPrime[i] = true;
	//}
	//int j;
	//for (i = 3; i < MAXP; i += 2) {
		//if (isPrime[i]) {
			//j = i+i;
			//while(j < MAXP) {
				//isPrime[j] = false;	
				//j += i;
			//}
		//}
	//}
//}

const int MAXN = int(3*1e3) + 3;
int n;
int is[MAXN];

const string FILENAME = "";
int main () {
    int f, s; 
    while (cin >> n) {
        cin >> f;
        int val;
        for (int i = 1; i < n; i++) {
            cin >> s;
            val = abs(f-s);
            if (val < n) {
                is[abs(f-s)] = true;
            }
            f = s;
        }
        bool joly = true;
        for (int i = 1; i < n; i++) {
            if (!is[i]) {
                joly = false;
            }
            is[i] = false;
        }
        if (joly) {
            cout << "Jolly" << endl;
        }else {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}
