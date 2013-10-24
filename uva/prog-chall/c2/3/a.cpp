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


const int MAXN = 200 + 3;

int n, p;

const string FILENAME = "";
int main () {
    set<int> lostDays;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        lostDays.clear();
        scanf("%d", &n);
        scanf("%d", &p);
        int hartal;
        for (int i = 0; i < p; i++) {
            scanf("%d", &hartal);
            int k = 1;
            int val;
            while (hartal*k <= n) {
                val = hartal*k;
                if (val % 7 != 6) {
                    lostDays.insert(val);
                }
                k++;
                if (k % 7 == 0) {
                    k++;
                }
            }
        }
        //set<int>::iterator it;
        //cout << endl;
        //for (it=lostDays.begin(); it!=lostDays.end(); ++it)
            //cout << ' ' << *it;
        //cout << endl;
        int lostDaysCount = lostDays.size();
        cout << lostDaysCount << endl;
    }
    lostDays.clear();
    return 0;
}
