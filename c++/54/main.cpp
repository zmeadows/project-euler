/* 
 * File:   main.cpp
 * Author: Zak
 *
 * Created on January 3, 2011, 6:38 AM
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 
 */

enum val { two, three, four, five, six, seven,
           eight, nine, ten, jack, queen, king, ace };
enum st { diamond, heart, club, spade };

struct card {
    val value;
    st suit;
    bool operator < (const card& testCard) const {
        return (value < testCard.value);
    }
};

typedef vector<card> hand;

enum handValue { highCard, onePair, twoPairs, threeofaKind, straight,
                 plainFlush, fullHouse, fourofaKind, straightFlush, royalFlush };

val charToVal(char cardValue)
{
    switch (cardValue)
    {
        case '2':
            return two;
            break;
        case '3':
            return three;
            break;
        case '4':
            return four;
            break;
        case '5':
            return five;
            break;
        case '6':
            return six;
            break;
        case '7':
            return seven;
            break;
        case '8':
            return eight;
            break;
        case '9':
            return nine;
            break;
        case 'T':
            return ten;
            break;
        case 'J':
            return jack;
            break;
        case 'Q':
            return queen;
            break;
        case 'K':
            return king;
            break;
        case 'A':
            return ace;
            break;
    }
}

st charToSuit(char cardSuit)
{
    switch (cardSuit)
    {
        case 'D':
            return diamond;
            break;
        case 'H':
            return heart;
            break;
        case 'C':
            return club;
            break;
        case 'S':
            return spade;
            break;
    }
}


void printHand(hand testHand)
{
    for (int i = 0; i < 5; ++i){
        cout << "( " << testHand[i].value << " " << testHand[i].suit << ") ";
    }

    cout << endl;
}

handValue getHandValue(hand testHand)
{
    bool typeFound;

    // Royal Flush
    typeFound = true;
    for (int a = 1; a < 5; ++a){
        if (testHand[0].value != ten ||
                testHand[a].suit != testHand[0].suit ||
                testHand[a].value != testHand[0].value + a){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return royalFlush; }

    // Straight Flush
    typeFound = true;
    for (int a = 1; a < 5; ++a){
        if (testHand[a].suit != testHand[0].suit ||
                testHand[a].value != testHand[0].value + a){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return straightFlush; }

    // Four of a Kind
    typeFound = true;
    for (int a = 0; a < 3; ++a){
        if (testHand[a].value != testHand[a+1].value){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return fourofaKind; }

    typeFound = true;
    for (int a = 1; a < 4; ++a){
        if (testHand[a].value != testHand[a+1].value){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return fourofaKind; }

    // Full House
    typeFound = true;
    if (testHand[0].value != testHand[1].value){
        typeFound = false;
    }
    for (int a = 2; a < 4; ++a){
        if (testHand[a].value != testHand[a+1].value){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return fullHouse; }

    typeFound = true;
    if (testHand[3].value != testHand[4].value){
        typeFound = false;
    }
    for (int a = 0; a < 2; ++a){
        if (testHand[a].value != testHand[a+1].value){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return fullHouse; }

     // Flush
    typeFound = true;
    for (int a = 1; a < 5; ++a){
        if (testHand[a].suit != testHand[0].suit){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return plainFlush; }

    // Straight
    typeFound = true;
    for (int a = 1; a < 5; ++a){
        if (testHand[a].value != testHand[0].value + a){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return straight; }

    // Three of a Kind
    typeFound = true;
    for (int a = 0; a < 2; ++a){
        if (testHand[a].value != testHand[a+1].value){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return threeofaKind; }

    typeFound = true;
    for (int a = 1; a < 3; ++a){
        if (testHand[a].value != testHand[a+1].value){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return threeofaKind; }

    typeFound = true;
    for (int a = 2; a < 4; ++a){
        if (testHand[a].value != testHand[a+1].value){
            typeFound = false;
            break;
        }
    }
    if (typeFound) { return threeofaKind; }

    // Two Pairs
    if (testHand[0].value == testHand[1].value &&
            testHand[2].value == testHand[3].value){
            return twoPairs;
    }

    if (testHand[0].value == testHand[1].value &&
            testHand[3].value == testHand[4].value){
            return twoPairs;
    }

    if (testHand[1].value == testHand[2].value &&
            testHand[3].value == testHand[4].value){
            return twoPairs;
    }

    // One Pair
    if (testHand[0].value == testHand[1].value){
            return onePair;
    }

    if (testHand[1].value == testHand[2].value){
            return onePair;
    }

    if (testHand[2].value == testHand[3].value){
            return onePair;
    }

    if (testHand[3].value == testHand[4].value){
            return onePair;
    }
    
    return highCard;
}

bool compareHighCards(hand playerOneHand, hand playerTwoHand)
{
    if (playerOneHand[4].value > playerTwoHand[4].value){
        return true;
    }else{
        return false;
    }
}

bool comparePairHands(hand playerOneHand, hand playerTwoHand)
{
    val oneVal;
    val twoVal;
    for (int i = 0; i < 4; ++i){
        if (playerOneHand[i].value == playerOneHand[i+1].value){
            oneVal = playerOneHand[i].value;
            playerOneHand.erase(playerOneHand.begin()+i);
            break;
        }
    }
    for (int i = 0; i < 4; ++i){
        if (playerTwoHand[i].value == playerTwoHand[i+1].value){
            twoVal = playerTwoHand[i].value;
            playerTwoHand.erase(playerTwoHand.begin()+i);
            break;
        }
    }

    if (oneVal == twoVal){
    for (int i = 3; i >= 0; --i){
        if (playerOneHand[i].value != playerTwoHand[i].value){
            return (playerOneHand[i].value > playerTwoHand[i].value);
        }
    }
    }
    return (oneVal > twoVal);
}

bool compareHands(hand handOne, hand handTwo)
{
        if (getHandValue(handTwo) == getHandValue(handOne) &&
                getHandValue(handOne) == highCard){
            return compareHighCards(handOne, handTwo);
        }
        if (getHandValue(handTwo) == getHandValue(handOne) &&
                getHandValue(handOne) == onePair){
            return comparePairHands(handOne, handTwo);
        }

        return (getHandValue(handOne) > getHandValue(handTwo));
}

int main(int argc, char** argv) {

    ifstream handlog ("poker.txt");
    string line;
    static int totalWins(0);

    for (int i = 0; i < 1000; ++i){

        getline(handlog, line);
        istringstream lineStream(line);
        static int q;

        hand handOne, handTwo;
        for (q = 0; lineStream && q < 10; q++){
            char* n;
            card holdCard;
            lineStream >> n;
            holdCard.value = charToVal(n[0]);
            holdCard.suit = charToSuit(n[1]);
            if (q < 5)
                handOne.push_back(holdCard);
            else
                handTwo.push_back(holdCard);
            //cout << holdCard.value << " " << holdCard.suit << endl;
        }

        sort (handOne.begin(), handOne.end());
        sort (handTwo.begin(), handTwo.end());

        if (compareHands(handOne, handTwo))
            ++totalWins;
    }

    cout << totalWins << endl;
    return 0;
}

