#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t { OROS, COPAS, ESPADAS, BASTOS };

/*
The values for this type start at 0 and increase by one
afterwards until they get to SIETE.
The rank reported by the function Card::get_rank() below is
the value listed here plus one.
E.g:
The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
*/
enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };

class Card {
public:
	// Constructor assigns random rank & suit to card.
	Card();

	// Accessors 
	string get_spanish_suit() const;
	string get_spanish_rank() const;

	/*
	These are the only functions you'll need to code
	for this class. See the implementations of the two
	functions above to get an idea of how to proceed.
	*/
	string get_english_suit() const;
	string get_english_rank() const;

	// Converts card rank to number.
	// The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
	int get_rank() const;

	// Compare rank of two cards. E.g: Eight<Jack is true.
	// Assume Ace is always 1. 
	// Useful if you want to sort the cards.
	bool operator < (Card card2) const;



private:
	suit_t suit;
	rank_t rank;
};

class Hand {
public:
	Hand();	// A vector of Cards

	void add_card(Card carta); //gets another random card
	void displayAll(); //displays the random card specified
	double get_points(); //Points getter
	void clear(); //clears a player's hand before the start of a new round

private:
	vector<Card> hand; //empty Card vector
	double points; //point count which determines who wins the specific round
};


class Player {
public: 

	Player::Player(Hand hand, int m = 0) : money(m) {}; //main constructor: assigns intial amount of money
	size_t get_money() const { return money; } //Money amount getter
	void set_money(size_t m); //Sets the amount of money to any specified variable in order to manipulate later

private:
	size_t money; //keeps track of each player's money
	Hand hand; //allows the player class to use the empty vector of cards
};

//Non-member function which displays specified cards
void display(Card carta);


#endif