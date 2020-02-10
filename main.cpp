#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Card {
protected:
    enum Suit { Diamonds, Clubs, Hearts, Spades };
    Suit m_suit;
    enum Rank {_2 = 2, _3, _4, _5, _6, _7, _8, _9, _10, J = 10, Q = 10, K = 10, A = 11 };
    Rank m_rank;
    bool Faceup = 0;
public:
    Card(Suit s, Rank r, bool face) : m_suit(s), m_rank(r), Faceup(face) {}

    void Flip() { Faceup = !(Faceup); }

    int getValue() const {
        int value = 0;
        if (Faceup) value = m_rank;
        return m_rank;
    }
};

class Hand {
private:
    vector<Card*> m_hand;
public:

    void Add(Card* new_card) { m_hand.push_back(new_card); }

    void Clear() { m_hand.clear(); }

    int getTotal() const{
        int count = 0;
        for (int i = 0; i < m_hand.size(); i++) {
            if ((count > 10) && (m_hand[i]->getValue() == 11)) count++;
            else count += m_hand[i]->getValue();
        }
        return count;
    }
};

class GenericPlayer:public Hand{
private:
    string name;
public:
    virtual bool isHitting() const = 0;
    bool is Busted() const{}
    void Bust() const;
    };

int main(){


}
