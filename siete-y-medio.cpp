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

	Card carta;

	cout << "Your cards:" << endl;
	player_uno.add_card(carta);
	player_uno.displayAll();

	cout << "Your total is " << player_uno.get_points() << ". Do you want another card (y/n)? ";
	cin >> decision;
	cout << endl;

	while (decision == 'y') {
		Card carta;
		cout << "New card:" << endl;
		display(carta);

		cout << "Your cards:" << endl;
		player_uno.add_card(carta);
		player_uno.displayAll();

		cout << "Your total is " << player_uno.get_points() << ". Do you want another card (y/n)? ";
		cin >> decision;
		cout << endl;
	}

	cout << "Dealer's cards: " << endl;
	Card carta2;
	dealer.add_card(carta2);
	display(carta2);

	while (dealer.get_points() < 6) {
		cout << "New Card:" << endl;
		Card carta3;
		dealer.add_card(carta3);
		dealer.displayAll();
	}

	cout << "The dealer's total is " << dealer.get_points() << endl;


	//Player wins and Dealer busts
	if ((player_uno.get_points() > dealer.get_points() && player_uno.get_points() <= 7.5) ||
		(dealer.get_points() > 7.5 && player_uno.get_points() <= 7.5)) {

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

	//Player busts and Dealer wins
	else if ((dealer.get_points() > player_uno.get_points() && dealer.get_points() <= 7.5) ||
		(dealer.get_points() > 7.5 && player_uno.get_points() <= 7.5)) {

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

	//Both Player and Dealer Bust
	else if (player_uno.get_points() > 7.5 && dealer.get_points() > 7.5) {
		cout << "you lose $ " << bet << ". " << endl;

		//temporary ints for both player and dealer money
		int player_temp = player1.get_money();
		int dealer_temp = dealer1.get_money();

		//changing money amounts for both dealer and player
		player_temp -= bet;
		dealer_temp -= bet;

		//setting the new money to private variable
		player1.set_money(player_temp);
		dealer1.set_money(dealer_temp);
	}

	else if (dealer.get_points() == player_uno.get_points()) {
		cout << "There has been a tie. No money will be won or lost." << endl;
	}

	cin.get();
	cin.get();
	return 0;
}