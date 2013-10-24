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
#define spaus(x) cout << (x) << endl;

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


template <typename T>
T StringToNumber (const string &Text) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
int getInt(string s, int &poz) {
    int len = s.length();
    char c;
    int an = 0;
    bool numberFound = false;
    string str;
    while(poz < len) {
        c = s[poz];
        if ((c >= '0') && (c <= '9')) {
                numberFound = true;
                str = c;
                an = an*10 + StringToNumber<int>(str); 
        }else if (numberFound) {
            break;
        }
        poz++;
    }
    return an;
}


const int MAXN = 1000 + 3;
const int MAXC = 20 + 5;
int n;
//eliminated
bool el[MAXC];
int candInd[MAXN];
int favor[MAXN][MAXC];
string names[MAXC];

struct Number {
    LL u, d;

    Number() {
    }

    Number(LL up, LL down) {
        this->u = up;
        this->d = down;
    }


    LL gcd(LL a, LL b) {
        a = abs(a);
        b = abs(b);
        if (b == 0) return a;
        return gcd(b, a%b);
    }

    LL lcm(LL a, LL b) {
        return a/gcd(a, b)*b;
    }

    void simplify(LL &up, LL &down) {
        LL gcdiv = gcd(up, down);
        up /= gcdiv;
        down /= gcdiv;
    }

    Number& operator=(const Number &number) {
        this->u = number.u;
        this->d = number.d;
        return *this;  // Return a reference to myself.
    }

    Number operator+(const Number number) {
        LL up;
        LL down;
        up = this->u*number.d + number.u*this->d;
        down = this->d*number.d;
        simplify(up, down);
        return Number(up, down);
    }

    Number operator-(const Number number) {
        LL up;
        LL down;
        up = this->u*number.d - number.u*this->d;
        down = this->d*number.d;
        simplify(up, down);
        return Number(up, down);
    }

    Number operator*(const Number number) {
        LL up;
        LL down;
        up = this->u*number.u;
        down = this->d*number.d;
        simplify(up, down);
        return Number(up, down);
    }

    Number operator/(const Number number) {
        LL up;
        LL down;
        up = this->u*number.d;
        down = this->d*number.u;
        simplify(up, down);
        return Number(up, down);
    }

    bool operator>(const Number number) {
        Number rez = (*this)-number;
        return (rez.u > 0 && rez.d > 0);
    }

    bool operator<=(const Number number) {
        Number rez = (*this)-number;
        return (rez.u <= 0 && rez.d > 0);
    }

};

int voteCount[MAXC];
void countVotes(int n, int peop) {
    for (int i = 0; i < MAXC; i++) {
        voteCount[i] = 0;
    }
    int u, votinFor;
    for (int i = 0; i < peop; i++) {
        u = candInd[i]; // prioritetas
        votinFor = favor[i][u]; // zmogaus indeksas
        while(el[votinFor] && u + 1 < n) {
            candInd[i] += 1;
            u = candInd[i];
            votinFor = favor[i][u];
        }
        voteCount[votinFor]++;
    }     
}

int isWin(int totalCand, int peop) {
     Number lim = Number(1,2);
     for (int i = 0; i < totalCand; i++) {
        if (Number(voteCount[i], peop) > lim) {
            return i;
        }
     }
     //no one won yet
     return -1;
}

vector<int> on;
vector<int> off;

void printOn() {
    cout << "People left: " << endl;
    for (int i = 0; i < on.size(); i++) {
        cout << names[on[i]] << " ";
    }
    cout << endl;
}

void printVotecount() {
    cout << "Vote count: " << endl;
    for (int i = 0; i < on.size(); i++) {
        cout << names[on[i]]<< ":" << voteCount[i] << " ";
    }
    cout << endl;
}

int eliminate(int totalCand, int peop) {
    off.clear();
    Number least = Number(2,1);
    Number cur;
    int t;
     for (int i = 0; i < on.size(); i++) {
        t = on[i];
        cur = Number(voteCount[t], peop);
        if (least > cur) {
            least = cur;
        }
     }

     for (int i = 0; i < on.size(); i++) {
        t = on[i];
        cur = Number(voteCount[t], peop);
        if (cur <= least) {
            off.push_back(t);
            el[t] = true; // eliminated
            on.erase(on.begin() + i);
            i -= 1;
        }
     }
     return off.size();
}

int solve(int n, int peop) {
    int elimCount;
    int candLeft = n;
    int won = false;
    on.clear();
    off.clear();
    for (int i = 0; i < n; i++) {
        on.push_back(i);
        el[i] = false;
    }
    do {
        countVotes(n, peop);
        won = isWin(n, peop);  
        elimCount = eliminate(n, peop);
        candLeft -= elimCount;
    }while (candLeft > 0 && (won == -1) && elimCount != 0);
    if (won != -1) {
        on.clear();
        off.clear();
        off.push_back(won);
    }
}

int main () {
    int k = 0;
    string line;
    cin >> k;
    for (int j = 0; j < k; j++) {
        cin >> n;
        getline(cin, names[0]);
        for (int i = 0; i < n; i++) {
            getline(cin, names[i]);
        }
        int poz = 0;
        int peop = 0; 
        while(getline(cin, line) && line != "\n" && line != "") {
            poz = 0;
            candInd[peop] = 0;
            for (int i = 0; i < n; i++) {
                favor[peop][i] = getInt(line, poz); 
                favor[peop][i]--;
            }
            peop++;
        }
        solve(n, peop);
        int t;
        if (j != 0) {
            cout << endl;
        }
        for (int i = 0; i < off.size(); i++) {
            t = off[i];
            cout << names[t] << endl;
        }
    }
    int c = 2;
    spaus(c)
    return 0;
}
