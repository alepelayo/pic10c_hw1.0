#include <iostream>
#include "cards.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

int main() {

	ofstream gamelog;
	gamelog.open("gamelog.txt");

	srand((int)time(0));
	int starting_balance_player = 100;
	int starting_balance_dealer = 900;

	int gameNum = 0;

	Hand player_uno;
	Hand dealer;

	Player player1(player_uno, starting_balance_player);
	Player dealer1(dealer, starting_balance_dealer);

	while (true) {

		size_t bet;
		char decision;
		++gameNum; //keeps track of how many rounds are being played

		cout << "You have $" << player1.get_money() << ". Enter bet: ";
		cin >> bet;
		if (bet > starting_balance_player) {
			std::cout << "Your bet exceeds your starting balance. Please lower your bet: ";
			cin >> bet;
		}

		gamelog << "------------------------------------------------------------" << endl;
		gamelog << "Game number: " << gameNum << '\t' << '\t' << "Money left: $"
			<< player1.get_money() << endl << "Bet: " << bet << endl;

		Card carta;

		cout << "Your cards:" << endl;
		player_uno.add_card(carta);
		player_uno.displayAll();

		gamelog << "Your cards: " << endl;
		gamelog << "\t" << "\t" << carta.get_spanish_rank() + " de " + carta.get_spanish_suit() +
			"\t" << "(" + carta.get_english_rank() + " of " + carta.get_english_suit() + ")." + "\n";

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

			gamelog << "\t" << "\t" << carta.get_spanish_rank() + " de " + carta.get_spanish_suit() +
				"\t" << "(" + carta.get_english_rank() + " of " + carta.get_english_suit() + ")." + "\n";

		}

		gamelog << "Your total: " << player_uno.get_points() << endl << endl;

		cout << "Dealer's cards: " << endl;
		Card carta2;
		dealer.add_card(carta2);
		display(carta2);



		gamelog << "Dealer's cards: \n";
		gamelog << "\t" << "\t" << carta2.get_spanish_rank() + " de " + carta2.get_spanish_suit() +
			"\t" << "(" + carta2.get_english_rank() + " of " + carta2.get_english_suit() + ")." + "\n";

		while (dealer.get_points() < 6) {
			cout << "New Card:" << endl;
			Card carta3;
			dealer.add_card(carta3);
			display(carta3);
			cout << endl;


			gamelog << "\t" << "\t" << carta3.get_spanish_rank() + " de " + carta3.get_spanish_suit() +
				"\t" << "(" + carta3.get_english_rank() + " of " + carta3.get_english_suit() + ")." + "\n";


			cout << "Dealer Cards: " << endl;
			dealer.displayAll();

			cout << "The dealer's total is " << dealer.get_points() << "." << endl << endl;

		}

		gamelog << "Dealer's total: " << dealer.get_points() << endl << endl;

		cout << "The dealer's total is " << dealer.get_points() << "." << endl << endl; //still trying to figure out how to only show one dealer total

																						//Player wins and Dealer busts
		if ((player_uno.get_points() > dealer.get_points() && player_uno.get_points() <= 7.5) ||
			(dealer.get_points() > 7.5 && player_uno.get_points() <= 7.5)) {

			cout << "The dealer has lost. You win $" << bet << ". " << endl << endl;

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
			(dealer.get_points() <= 7.5 && player_uno.get_points() > 7.5)) {

			cout << "The dealer has won. You lose $" << bet << ". " << endl << endl;

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
			cout << "Both you and the dealer have bust. You both lose $" << bet << ". " << endl << endl;

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
			cout << "There has been a tie. No money will be won or lost." << endl << endl;
		}

		//Ending the game: either player or dealer has gotten to $0
		if (player1.get_money() == 0) {
			cout << "You have $0. GAME OVER!" << endl << "Come back when you have more money." << endl << endl << "Bye!";
			break;
		}

		else if (dealer1.get_money() == 0) {
			cout << "Dealer has $0. YOU WON!" << endl << "Come back soon." << endl << endl << "Bye!";
			break;
		}

		starting_balance_player = player1.get_money();
		starting_balance_dealer = dealer1.get_money();
		player_uno.clear();
		dealer.clear();

	}

	gamelog.close();

	cin.get();
	cin.get();
	return 0;
}


