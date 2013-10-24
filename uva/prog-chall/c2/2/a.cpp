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
Card white[MAXN];
Card black[MAXN];
//white = 1; black = 2
const int WHITE = 1;
const int BLACK = 2;
const int TIE = 3;
vector<Card> vectWhite, vectBlack;

void formVector() {
    vectWhite.clear();
    vectBlack.clear();
    for (int i = 0; i < 5; i++) {
        vectWhite.push_back(white[i]);
        vectBlack.push_back(black[i]);
    }
}

vector<Card> exclude(vector<Card> cardsToExclude, vector<Card> initSet) {
    vector<Card> rez;
    bool take;
    for (int j = 0; j < initSet.size(); j++) {
        take = true;
        for (int i = 0; i < cardsToExclude.size(); i++) {
             if (initSet[j] == cardsToExclude[i]) {
                 take = false;
                 break;
             }
        }
        if (take) {
            rez.push_back(initSet[j]);
        }
    }
    return rez;
}

bool compare(Card a, Card b) {
    return (a.value > b.value);
}



int highCard(vector<Card> vWhite, vector<Card> vBlack) {
    sort(vWhite.begin(), vWhite.end(), compare);
    sort(vBlack.begin(), vBlack.end(), compare);
    int sz = min(vWhite.size(), vBlack.size());
   //for (int i = 0; i < sz; i++) {
        //cout << "White: " << vWhite[i].value << endl;    
    //}
    //for (int i = 0; i < sz; i++) {
        //cout << "Black: " << vBlack[i].value << endl;    
    //}
    for (int i = 0; i < sz; i++) {
        if (vBlack[i].value > vWhite[i].value) {
            return BLACK;
            break;
        }else if (vBlack[i].value < vWhite[i].value) {
            return WHITE;
            break;
        }
    }
    return TIE;
}


// find best pair value and remove that pair from vector
int pairValue(vector<Card> &deck) {
    int sz = deck.size();
    int bestVal = 0;
    int ind1, ind2;
    for (int i = 0; i < sz; i++) {
        for (int j = i+1; j < sz; j++) {
            if (deck[i].value == deck[j].value
                    && deck[i].value > bestVal) {
                bestVal = deck[i].value; 
                ind1 = i;
                ind2 = j;
            }
        }
    }
    if (bestVal != 0) {
        deck.erase(deck.begin() + ind2);
        deck.erase(deck.begin() + ind1);
    }
    return bestVal;
}

//checked
int pora(vector<Card> vWhite, vector<Card> vBlack) {
    int whitePairVal = 0, blackPairVal = 0;
    whitePairVal = pairValue(vWhite);
    blackPairVal = pairValue(vBlack);
    if (blackPairVal > whitePairVal) {
        return BLACK;
    }else if (whitePairVal > blackPairVal) {
        return WHITE;
    }else if (whitePairVal != 0 && blackPairVal != 0) {
        return highCard(vWhite, vBlack);
    }
    return 0;
}

bool isAllValuesConsecutive(vector<Card> deck) {
    if (deck.empty()) return false;
    sort(deck.begin(), deck.end(), compare);
    int val = deck[0].value;
    for (int i = 1; i < deck.size(); i++) {
        if (deck[i].value + 1 != val) {
            return false;
        }
        val = deck[i].value;
    }
    return true;
}

int highestValue(vector<Card> deck) {
    int val = 0;
    REP(i, deck.size()) {
        val = max(deck[i].value, val);
    }
    return val;
}

//checked
int straight() {
    formVector();
    bool whiteHasStraight = isAllValuesConsecutive(vectWhite);
    bool blackHasStraight = isAllValuesConsecutive(vectBlack);
    if (whiteHasStraight && !blackHasStraight) {
        return WHITE;
    }else if (blackHasStraight && !whiteHasStraight) {
        return BLACK;
    }else if (blackHasStraight && whiteHasStraight){
        // find card with highest value
        int wv = highestValue(vectWhite); 
        int bv = highestValue(vectBlack);
        if (wv > bv) {
            return WHITE;
        }else if (bv > wv) {
            return BLACK;
        }else {
            return TIE;
        }
    }
    return 0;
    
}

//checked
int twoPair() {
    formVector();
    vector<Card> w, b;
    w = vectWhite;
    b = vectBlack;
    //cout << "size: " << w.size() << endl;
    int wf = pairValue(w);
    //for (int i = 0; i < w.size(); i++) {
        //cout << w[i].value << endl;
    //}
    //cout << "size: " << w.size() << endl;
    int ws = pairValue(w);
    //cout << "size: " << w.size() << endl;
    int bf = pairValue(b), bs = pairValue(b);
    //cout << "white: " << wf << " " << ws << endl;
    //cout << "black: " << bf << " " << bs << endl;

    // tikrinam ar pas viena yra dvi poros o pas kita nera
    if (wf != 0 && ws != 0 && (bf == 0 || bs == 0)) {
        return WHITE;
    }else if (bf != 0 && bs != 0 && (wf == 0 || ws == 0)) {
        return BLACK;
    }
    //tikrinam ar apskritai yra dvi poros pas ka nors
    if ((wf == 0 || ws == 0) && (bf == 0 || bs == 0)) {
        return 0;
    }

    // zinom kad pas juos abu tikrai yra poros
    if (wf > bf 
            || ((wf == bf) && (ws > bs)) ) {
        return WHITE;
    }else if (wf < bf 
            || ((wf == bf) && (ws < bs)) ) {
        return BLACK;
    }else if (wf == bf && ws == bs) {
        if (w[0].value > b[0].value) {
            return WHITE;
        }else if (b[0].value > w[0].value) {
            return BLACK;
        }else if (w[0].value == b[0].value) {
            return TIE;
        }
    }
    return 0;
}

//checked
int threeOfAKind() {
    int tWhiteVal = 0, tBlackVal = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                if (white[i].value == white[j].value 
                        && white[j].value == white[k].value) {
                    tWhiteVal = max(white[i].value, tWhiteVal);
                }
                if (black[i].value == black[j].value
                       && black[j].value == black[k].value) {
                    tBlackVal = max(black[i].value, tBlackVal);
                }
            }
        }
    }
    if (tWhiteVal > tBlackVal) {
        return WHITE;
    }else if (tBlackVal > tWhiteVal) {
        return BLACK;
    }else if (tWhiteVal != 0 && tBlackVal != 0) {
        return TIE;
    }
    return 0;
}

bool isFlush(vector<Card> deck) {
    if (deck.empty()) return 0;
    char deckColor = deck[0].color;
    int cardCountWithSameSuit = 0;
    REP(i, deck.size()) {
        if (deck[i].color == deckColor) {
            cardCountWithSameSuit++;
        }
    }
    if (cardCountWithSameSuit == 5) {
        return true;
    }else {
        return false;
    }
}
//checked
int flush() {
    formVector();
    bool blackHasFlush = isFlush(vectBlack);
    bool whiteHasFlush = isFlush(vectWhite);
    if (whiteHasFlush && !blackHasFlush) {
        return WHITE;
    }else if (blackHasFlush && !whiteHasFlush) {
        return BLACK;
    }else if (whiteHasFlush && blackHasFlush) {
        return highCard(vectWhite, vectBlack);
    }
    return 0;
}

int fullHouseValue(vector<Card> deck) {
    int val = 0;
    int sz = deck.size();
    vector<int> pr;
    for (int i = 0; i < sz; i++) {
        for (int j = i+1; j < sz; j++) {
            for (int k = j+1; k < sz; k++) {
                int v1 = deck[i].value, v2 = deck[j].value, v3 = deck[k].value; 
                if (v1 == v2 && v1 == v3) {
                    pr.clear();
                    for (int c = 0; c < sz; c++) {
                        if (c != i && c != j && c!=k) {
                            pr.push_back(deck[c].value);
                        }    
                    }
                    if (pr.size() >= 2)  {
                        if (pr[0] == pr[1]) {
                            val = max(v1, val);
                        }
                    }
                }
            }
        }
    }
    return val;
}

//checked
int fullHouse() {
    formVector();
    int whiteFullHouseVal = fullHouseValue(vectWhite);
    int blackFullHouseVal = fullHouseValue(vectBlack);
    if (whiteFullHouseVal > blackFullHouseVal) {
        return WHITE;
    }else if (blackFullHouseVal > whiteFullHouseVal){
        return BLACK;
    }else if (blackFullHouseVal != 0 && whiteFullHouseVal != 0){
        return TIE;
    }
    return 0;
}

int fourOfAKindValue(vector<Card> deck) {
    int deckVal = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                for (int c = k+1; c < 5; c++) {
                    int v1 = deck[i].value, v2 = deck[j].value, 
                        v3 = deck[k].value, v4 = deck[c].value; 
                    if (v1 == v2 
                            && v3 == v4
                            && v1 == v3) {
                        deckVal = max(v1, deckVal);
                    }
                }
            }
        }
    }
    return deckVal;
}

//checked
int fourOfAKind() {
    formVector();
    int blackVal = fourOfAKindValue(vectBlack);
    int whiteVal = fourOfAKindValue(vectWhite);
    if (whiteVal > blackVal) {
        return WHITE;
    }else if (blackVal > whiteVal) {
        return BLACK;
    }else if (blackVal != 0 && whiteVal != 0) {
        return TIE;
    }
    return 0;
}

int straightFlushValue(vector<Card> deck) {
    if (deck.empty()) {
        return 0;
    }
    sort(deck.begin(), deck.end(), compare);
    char deckColor = deck[0].color;
    int flushValue = deck[0].value;
    int prevValue = deck[0].value;
    for (int i = 1; i < deck.size(); i++) {
        if ( deck[i].color != deckColor
                || (prevValue-1 != deck[i].value) ) {
            flushValue = 0;
            break;
        }    
        prevValue = deck[i].value;
    }
    return flushValue;
}
//checked
int straightFlush() {
    formVector();
    int whiteFlushValue = straightFlushValue(vectWhite);
    int blackFlushValue = straightFlushValue(vectBlack);
    if (whiteFlushValue > blackFlushValue) {
        return WHITE;
    }else if (blackFlushValue > whiteFlushValue) {
        return BLACK;
    }else if (blackFlushValue != 0 && whiteFlushValue != 0) {
        return TIE;
    }
    return 0;
}

//bool doPrint  = true;
bool doPrint = false;

int solve() {
    int winner = 0;
    winner = straightFlush();
    if (winner != 0) {
        if (doPrint)
        cout << "Straight flush!" << endl;
        return winner;
    }  
    winner = fourOfAKind();
    if (winner != 0) {
        if (doPrint)
        cout << "Four of a kind!" << endl;
        return winner;
    }  

    winner = fullHouse();
    if (winner != 0) {
        if (doPrint)
        cout << "Full house!" << endl;
        return winner;
    }  

    winner = flush();
    if (winner != 0) {
        if (doPrint)
        cout << "Flush!" << endl;
        return winner;
    }  
    winner = straight();
    if (winner != 0) {
        if (doPrint)
        cout << "Straight!" << endl;
        return winner;
    }  
    winner = threeOfAKind();
    if (winner != 0) {
        if (doPrint)
        cout << "Three of a kind!" << endl;
        return winner;
    }  
    winner = twoPair();
    if (winner != 0) {
        if (doPrint)
        cout << "Two pairs!" << endl;
        return winner;
    }
    formVector();  
    winner = pora(vectWhite, vectBlack);
    if (winner != 0) {
        if (doPrint)
        cout << "one pair!" << endl;
        return winner;
    }
    formVector();
    winner = highCard(vectWhite, vectBlack);
    if (winner != 0) {
        if (doPrint)
        cout << "high card!" << endl;
        return winner;
    }  
    return 0;
}


int main () {
    map<char, int> relation;
    char fig[] = {'T', 'J', 'Q', 'K', 'A'};
    for (int i = 1; i < 10; i++) {
        relation[char(i + 48)] = i;
    }
    for (int i = 0; i < sizeof(fig); i++) {
        relation[ fig[i] ] = 10 + i;
    }
    int winner;
    char s[40];
    bool first = true;
    while(fgets(s,40,stdin)) {
        for (int i = 0; i < 5; i++) {
            black[i] = Card(s[3*i + 1], relation[ s[3*i] ]);
            white[i] = Card(s[3*5 + 3*i + 1], relation[ s[3*5 + 3*i] ]);
        }

        if (doPrint) {
            cout << "============================" << endl;
            cout << "Black cards: " << endl;
            for (int i = 0; i < 5; i++) {
                cout << "color: " << black[i].color << " value: " << black[i].value << endl;
            }
            cout << "White cards: " << endl;
            for (int i = 0; i < 5; i++) {
                    cout << "color: " << white[i].color << " value: " << white[i].value << endl;
            }
        }
        formVector();
        winner = solve();
        //if (!first) {
            //cout << endl;
        //}
        if (winner == WHITE) {
            cout << "White wins.";
        }else if (winner == BLACK) {
            cout << "Black wins.";
        }else {
            cout << "Tie.";
        }
        cout << endl;
        first = false;
    }
    return 0;
}
