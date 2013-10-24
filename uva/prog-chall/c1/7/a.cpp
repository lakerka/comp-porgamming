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


const int BOARD_SIZE = 8;
const int EMPTY = 404;
const int WHITE = 0;
const int BLACK = 1;
const int OTHER_PIECE = 405;
const int MAXN = 15 + 3;
char board[MAXN][MAXN];

int kn[8][2] = {{1, 2}, 
                    {2, 1},
                    {-1, 2},
                    {2, -1},
                    {-2, 1},
                    {1, -2},
                    {-1, -2},
                    {-2, -1}};

bool inRange(int x, int y) {
    if (x >= 1 && x <= BOARD_SIZE && y >= 1 && y <= BOARD_SIZE) {
        return true;
    }else {
        return false;
    }
}

bool tikrink(int x, int y, int puolaSpalva) {
    int dir = -1;
    char king;
    char figures[10] = {'P', 'R', 'B', 'Q', 'N'};
    if (puolaSpalva == WHITE) {
        king = 'k';
    }else {
        king = 'K';
        dir = 1;
        for (int i = 0; i < 5; i++) {
            figures[i] = char(int(figures[i]) + 32);
        }
    }
    char PAWN = figures[0];
    char ROOK = figures[1];
    char BISHOP = figures[2];
    char QUEEN = figures[3];
    char KNIGHT = figures[4];
    if (board[y - dir][x + dir] == PAWN || board[y - dir][x - dir] == PAWN) {
        return true;
    }
    // ok
    char f = 'o';
    int x1 = x - 1, y1 = y;
    //left
    while(inRange(x1, y1)) {
        f = board[y1][x1];
        if (f == QUEEN || f == ROOK) return true;
        x1 -= 1;
        if (f != '.') {
            break;
        } 
    }
    // right
    x1 = x+1; y1 = y;
    while(inRange(x1, y1)) {
        f = board[y1][x1];
        if (f == QUEEN || f == ROOK) return true;
        x1 += 1;
        if (f != '.') {
            break;
        } 
    }
    //down
    x1 = x; y1 = y+1;
    while(inRange(x1, y1)) {
        f = board[y1][x1];
        if (f == QUEEN || f == ROOK) return true;
        y1 += 1;
        if (f != '.') {
            break;
        } 
    }
    //down
    x1 = x; y1 = y-1;
    while(inRange(x1, y1)) {
        f = board[y1][x1];
        if (f == QUEEN || f == ROOK) return true;
        y1 -= 1;
        if (f != '.') {
            break;
        } 
    }
    x1=x+1; y1=y+1;
    while(inRange(x1, y1)) {
        f = board[y1][x1];
        if (f == QUEEN || f == BISHOP) return true;
        x1 += 1;
        y1 += 1;
        if (f != '.') {
            break;
        } 
    }
    x1=x-1; y1=y-1;
    while(inRange(x1, y1)) {
        f = board[y1][x1];
        if (f == QUEEN || f == BISHOP) return true;
        x1 -= 1;
        y1 -= 1;
        if (f != '.') {
            break;
        } 
    }
    x1=x-1; y1=y+1;
    while(inRange(x1, y1)) {
        f = board[y1][x1];
        if (f == QUEEN || f == BISHOP) return true;
        x1 -= 1;
        y1 += 1;
        if (f != '.') {
            break;
        } 
    }

    x1=x+1; y1=y-1;
    while(inRange(x1, y1)) {
        f = board[y1][x1];
        if (f == QUEEN || f == BISHOP) return true;
        x1 += 1;
        y1 -= 1;
        if (f != '.') {
            break;
        } 
    }
    for (int i = 0; i < 8; i++) {
        x1 = x+kn[i][0], y1 = y+kn[i][1];
        if (inRange(x1, y1)) {
            f = board[y1][x1];
            if (f == KNIGHT) {
                return true;
            }
        }
    }
    return false;
}

//white bootom uppercase
//black top

int main () {
    bool isFigure = true;
    char t;
    int game = 1;
    while (isFigure) {
        isFigure = false;
        for (int i = 1; i < 8+1; i++) {
            for (int j = 1; j < 8+1; j++) {
                cin >> board[i][j];
                if (board[i][j] != '.') {
                    isFigure = true;
                }
            }
        }
        if (!isFigure) {
            break;
        }
        int color;
        char figure;
        bool check = false;
        bool whiteMakesCheck = false;
        bool blackMakesCheck = false;
        for (int i = 1; i < 8+1; i++) {
            for (int j = 1; j < 8+1; j++) {
                if (whiteMakesCheck || blackMakesCheck){
                    break;
                }
                if (board[i][j] == '.') continue;
                figure = board[i][j];
                if (figure == 'K' ) {
                    blackMakesCheck = tikrink(j, i, BLACK);
                }else if (figure == 'k') {
                    whiteMakesCheck = tikrink(j, i, WHITE);
                }
            }
        }
        if (whiteMakesCheck) {
            cout << "Game #" << game << ": black king is in check."; 
        }else if (blackMakesCheck) {
            cout << "Game #" << game << ": white king is in check."; 
        }else {
            cout << "Game #" << game << ": no king is in check."; 
        }
        cout << endl;
        game++;
    }
    return 0;
}
