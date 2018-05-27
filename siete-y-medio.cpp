#include <iostream>
#include "cards.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

	srand((int)time(0));
	int starting_balance = 100;

	Hand player_uno;
	Hand dealer;

	Player player1(player_uno, starting_balance);
	Player dealer1(dealer, 900);

	//if (player1.get_money() != 0 || player1.get_money() != 900) {
	size_t bet;
	char decision;
	cout << "You have $" << player1.get_money() << ". Enter bet: ";
	cin >> bet;
	if (bet > starting_balance) {
		std::cout << "Your bet exceeds your starting balance. Please lower your bet: ";
		cin >> bet;
	}

	//player_uno.add_card();

	//cout << "Your cards: " << endl;
	//player_uno.display();

	//cout << "Your total is " << player_uno.get_points() << ". Do you want another card (y/n)? ";
	//cin >> decision;

	decision = 'y';


	while (decision == 'y') {
		Card carta;
		cout << "New card:" << endl;
		display(carta);

		cout << "Your cards:" << endl << endl;
		player_uno.add_card(carta);
		player_uno.displayAll();

		cout << "Your total is " << player_uno.get_points() << ". Do you want another card (y/n)? ";
		cin >> decision;
	}

	while (dealer.get_points() < 6) {
		Card carta;
		dealer.add_card(carta);
		dealer.displayAll();
	}


	//do {
	//	std::cout << "Your total is " << player_uno.get_points() << ". Do you want another card (y/n)? ";
	//	cin >> decision;

	//	if (decision == 'y') { //player1 plays all cards before AI

	//		cout << "New card: " << endl;

	//		player_uno.add_card(); //adding a new card


	//		cout << "Your cards: " << endl;
	//		player_uno.display();

	//		cout << player_uno.get_points() << endl;
	//	}

	//	if (decision == 'n') {

	//		cout << "Dealer's cards: " << endl;
	//		dealer.add_card();

	//		dealer.display();

	//		cout << dealer.get_points() << endl;
	//	}

	//		} while (dealer.get_points() < 6);
	//		//while the dealer's hand does not exceed 7 points, they will draw another card






	//size_t player::calcmoney(player, hand dealer) {
	if (player_uno.get_points() > 7.5 && dealer.get_points() <= 7.5) {
		cout << "you lose $ " << bet << ". " << endl;

		//temporary ints for both player and dealer money
		int player_temp = player1.get_money();
		int dealer_temp = dealer1.get_money();

		//changing money amounts for both dealer and player
		player_temp -= bet;
		dealer_temp += bet;

		//setting the new money to private variable
		player1.set_money(player_temp);
		dealer1.set_money(dealer_temp);

	}
	else if (player_uno.get_points() <= 7.5 && dealer.get_points() > 7.5) {
		cout << "you win $ " << bet << ". " << endl;

		//temporary ints for both player and dealer money
		int player_temp = player1.get_money();
		int dealer_temp = dealer1.get_money();

		//changing money amounts for both dealer and player
		player_temp += bet;
		dealer_temp -= bet;

		//setting the new money to private variable
		player1.set_money(player_temp);
		dealer1.set_money(dealer_temp);

	}
	//}


	cin.get();
	cin.get();
	return 0;
}


