#include <iostream>
#include "cards.h"
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

	srand((int)time(0));
	int const STARTING_BALANCE = 100;
	double current_points = STARTING_BALANCE;

	Hand player_uno;
	Hand dealer;

	Player player1 = Player(STARTING_BALANCE);
	//if (player1.get_money() != 0 || player1.get_money() != 900) {
	int bet;
	char decision;
	cout << "You have $" << player1.get_money() << ". Enter bet: ";
	cin >> bet;
	if (bet > STARTING_BALANCE) {
		cout << "Your bet exceeds your starting balance. Please lower your bet: ";
		cin >> bet;
	}
	////	cout << endl;

	player_uno.add_card();

	cout << "Your cards: " << endl;
	player_uno.display();

	cout << "Your total is " << player_uno.get_points() << ". Do you want another card (y/n)? ";
	cin >> decision;

	if (decision == 'y') { //player1 plays all cards before AI

		cout << "New card: " << endl;

		player_uno.add_card();


		cout << "Your cards: " << endl;
		player_uno.display();

		cout << player_uno.get_points() << endl;

	}

	if (decision == 'n') {

		cout << "Dealer's cards: " << endl;
		cout << dealer.add_card() << endl;

		dealer.display();

		cout << dealer.get_points() << endl;

		//while the dealer's hand does not exceed 7 points, they will draw another card

	}

	////}


	cin.get();
	cin.get();

	return 0;
}