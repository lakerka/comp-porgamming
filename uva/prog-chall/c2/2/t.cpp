#include <tr1/unordered_map>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
 
using namespace std;

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



const int MAXN = 5 + 3;
struct Card {
    char color;
    int value;
    Card() {
    }
    Card(char color, int value) {
        this->color = color;
        this->value = value;
    }
    bool operator==(const Card card) {
        if (this->color == card.color
                && this->value == card.value) {
            return true;
        }
        return false;
    }
};
string col[4] = {"C","D","H","S"};
string val[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
string c[52];
set<int> deck;
vector<string> tests;

int main () {
    //for (int i = 0; i < 13; i++) {
        //cout << val[i] << endl;
    //}

    //for (int j = 0; j < 4; j++) {
        //cout << color[j] << endl;
    //}
    int k = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            c[k] = val[i]+col[j];
            k++;
        }
    }
    const int MAXT = 500;

    srand (time(NULL));
    /* generate secret number between 1 and 10: */
    int index;
    for (int i = 0; i < MAXT; i++) {
        deck.clear();
        //cout << random_integer << endl; 
        int sz = 0;
        string rez = "";
        set<int>::iterator it;

        while(deck.size() < 10) {
            index = rand() % 52;
            deck.insert(index); 
            if (sz != deck.size()) {
                sz++;
                string card = c[index];
                if (sz != 1) {
                    rez += " ";
                }
                rez += card;
            }
        } 
        cout << rez << endl;
    }

    return 0;
}
