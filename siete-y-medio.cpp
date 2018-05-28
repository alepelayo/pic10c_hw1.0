#include <iostream>
#include "cards.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

	srand((int)time(0));
<<<<<<< HEAD
	int starting_balance_player = 100;
	int starting_balance_dealer = 100;
=======
	int STARTING_BALANCE = 100;
>>>>>>> experimental

	Hand player_uno;
	Hand dealer;

<<<<<<< HEAD
	Player player1(player_uno, starting_balance_player);
	Player dealer1(dealer, starting_balance_dealer);
=======
	Player player1(player_uno, STARTING_BALANCE);
	Player dealer1(dealer, STARTING_BALANCE);
>>>>>>> experimental

while (dealer1.get_money() != 0 || player1.get_money() != 0) {

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
		cout << endl;

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
		display(carta3);
		cout << endl;
		cout << "Dealer Cards: " << endl;
		dealer.displayAll();
		cout << "Dealer's total is " << dealer.get_points() << "." << endl;
	}

	cout << "The dealer's total is " << dealer.get_points() << endl << endl;


	//Player wins and Dealer busts
	if ((player_uno.get_points() > dealer.get_points() && player_uno.get_points() <= 7.5) ||
		(dealer.get_points() > 7.5 && player_uno.get_points() <= 7.5)) {

		cout << "The dealer has lost. You win $ " << bet << ". " << endl << endl;

		//temporary ints for both player and dealer money
		int player_temp = player1.get_money();
		int dealer_temp = dealer1.get_money();

		<< << << < HEAD
			//changing money amounts for both dealer and player
			player_temp += bet;
		dealer_temp -= bet;
		== == == =
			player_uno.add_card(); //adding a new card
		>> >> >> > experimental

			//setting the new money to private variable
			player1.set_money(player_temp);
		dealer1.set_money(dealer_temp);

	}

	//Player busts and Dealer wins
	else if ((dealer.get_points() > player_uno.get_points() && dealer.get_points() <= 7.5) ||
		(dealer.get_points() <= 7.5 && player_uno.get_points() > 7.5)) {

		cout << "The dealer has won. You lose $ " << bet << ". " << endl << endl;

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
		cout << "Both you and the dealer have bust. You both lose $ " << bet << ". " << endl << endl;

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

	//Player and Dealer have the same number of points
	else if (dealer.get_points() == player_uno.get_points()) {
		cout << "There has been a tie. No money will be won or lost." << endl << endl;
	}

	//setting everything to scratch (in both the hand the starting balance) before the next round is set
	starting_balance_player = player1.get_money();
	starting_balance_dealer = dealer1.get_money();
	player_uno.clear();
	dealer.clear();

}


	cin.get();
	cin.get();
	return 0;
}