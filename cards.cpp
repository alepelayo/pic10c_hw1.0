#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}


// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "coins";
		break;
	case COPAS:
		suitName = "cups";
		break;
	case ESPADAS:
		suitName = "spades";
		break;
	case BASTOS:
		suitName = "clubs";
		break;
	default: break;
	}
	return suitName;;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "Ace";
		break;
	case DOS:
		rankName = "Two";
		break;
	case TRES:
		rankName = "Three";
		break;
	case CUATRO:
		rankName = "Four";
		break;
	case CINCO:
		rankName = "Five";
		break;
	case SEIS:
		rankName = "Six";
		break;
	case SIETE:
		rankName = "Seven";
		break;
	case SOTA:
		rankName = "Jack";
		break;
	case CABALLO:
		rankName = "Knight";
		break;
	case REY:
		rankName = "King";
		break;
	default: break;
	}
	return rankName;;
}

// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}

/* *************************************************
Hand class
************************************************* */
Hand::Hand() {
	vector<Card> hand;
}

//adds a random card to the player's hand
void Hand::add_card(Card carta) { 
	hand.push_back(carta);
}

//displays all current cards in player's hand (not specified)
void Hand::displayAll() {
	for (size_t i = 0; i < hand.size(); ++i) {

		cout << "\t" << hand[i].get_spanish_rank() << " de " << hand[i].get_spanish_suit();
		cout << "\t" << right << "(" << hand[i].get_english_rank() << " of " << hand[i].get_english_suit() << ")." << endl;

	}
}

//returns the number of points after making any changes needed
double Hand::get_points() {
	points = 0;
	//goes through the entire hand to make sure any ranks larger than 7 are changed to 0.5
	for (size_t i = 0; i < hand.size(); ++i) {
		if (hand[i].get_rank() > 7) {
			points += 0.5;
		}
		else {
			points += hand[i].get_rank();
		}
	}
	return points;
}

//clear one's hand in order to start a new round
void Hand::clear() {
	hand.clear();
}


/* *************************************************
Player class
************************************************* */

//Sets the money amount to any variable name in order to manipulate during a round
void Player::set_money(size_t m) {
	money = m;
}

//Non-member function which displays specified cards (rather than all based on whose hand)
void display(Card carta) {
	cout << "\t" << carta.get_spanish_rank() << " de " << carta.get_spanish_suit();
	cout << "\t" << right << "(" << carta.get_english_rank() << " of " << carta.get_english_suit() << ")." << endl;
}