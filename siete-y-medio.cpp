#include <iostream>
#include "cards.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

//just want to check if it notices any changes with this comment

int main() {

	//creating a gamelog.txt which keeps track of each round, including betting value and hands for both dealer and input user
	ofstream gamelog;
	gamelog.open("gamelog.txt");

	srand((int)time(0)); //Random number, or in our case, card generator

	int starting_balance_player = 100; //starting balance for player/input user
	int starting_balance_dealer = 900; //starting balance for dealer

	int gameNum = 0; //keeps count of how many rounds are played for the gamelog.txt

					 //creating a playing hand for both input user and dealer
	Hand player_uno;
	Hand dealer;

	//creating the player themselves, which includes their hand and money amount
	Player player1(player_uno, starting_balance_player);
	Player dealer1(dealer, starting_balance_dealer);

	while (true) {

		size_t bet; //initial bet
		char decision; //input decision on whether the player wishes to add another card to their deck
		++gameNum; //keeps track of how many rounds are being played

				   //the initial start of a round: input user is being asked how much money they wish to bet
		cout << "You have $" << player1.get_money() << ". Enter bet: ";
		cin >> bet;
		if (bet > starting_balance_player) { //making sure that the bet number is valid to play
			std::cout << "Your bet exceeds your starting balance. Please lower your bet: ";
			cin >> bet;
		}

		//outputting game number and bet value in the gamelog.txt file
		gamelog << "------------------------------------------------------------" << endl;
		gamelog << "Game number: " << gameNum << '\t' << '\t' << "Money left: $"
			<< player1.get_money() << endl << "Bet: " << bet << endl;

		Card carta; //creating the player's first card

					//outputting the player's first card
		cout << "Your cards:" << endl;
		player_uno.add_card(carta);
		player_uno.displayAll();

		//outputs the player's first card in the gamelog.txt file
		gamelog << "Your cards: " << endl;
		gamelog << "\t" << "\t" << carta.get_spanish_rank() + " de " + carta.get_spanish_suit() +
			"\t" << "(" + carta.get_english_rank() + " of " + carta.get_english_suit() + ")." + "\n";

		//outputting the player's current point count and asks if they wish to receive another card
		cout << "Your total is " << player_uno.get_points() << ". Do you want another card (y/n)? ";
		cin >> decision;
		cout << endl;

		while (decision == 'y') { //if the player decides to receive another card
			Card carta; //creating another card
			cout << "New card:" << endl;
			display(carta); //outputting that one specific card
			cout << endl;

			cout << "Your cards:" << endl;
			player_uno.add_card(carta); //adding the specific card into the player's hand
			player_uno.displayAll(); //displaying all current cards in player's hand

									 //outputting the player's current point count and asks if they wish to receive another card
			cout << "Your total is " << player_uno.get_points() << ". Do you want another card (y/n)? ";
			cin >> decision;
			cout << endl;

			//outputs all the player's cards in the gamelog.txt file
			gamelog << "\t" << "\t" << carta.get_spanish_rank() + " de " + carta.get_spanish_suit() +
				"\t" << "(" + carta.get_english_rank() + " of " + carta.get_english_suit() + ")." + "\n";

		}

		//outputting player's total points after they finish requesting new cards
		gamelog << "Your total: " << player_uno.get_points() << endl << endl;

		//moves on to the dealer's hand
		cout << "Dealer's cards: " << endl;
		Card carta2; //random first card is made
		dealer.add_card(carta2); //first card is added to dealer's hand
		display(carta2); //displaying the specific card

		if (dealer.get_points() >= 6) {
			cout << "The dealer's total is " << dealer.get_points() << "." << endl << endl;
			//still trying to figure out how to only show one dealer total
		}

		//outputs the dealer's first card in the gamelog.txt file
		gamelog << "Dealer's cards: \n";
		gamelog << "\t" << "\t" << carta2.get_spanish_rank() + " de " + carta2.get_spanish_suit() +
			"\t" << "(" + carta2.get_english_rank() + " of " + carta2.get_english_suit() + ")." + "\n";

		while (dealer.get_points() < 6) { //the dealer will automatically ask for another card if their point total is less than 6
			cout << "New Card:" << endl;
			Card carta3; //creating a new card
			dealer.add_card(carta3); //adding the card to dealer's hand
			display(carta3); //displaying the specific card
			cout << endl;

			//outputs all of the dealer's cards in the gamelog.txt file
			gamelog << "\t" << "\t" << carta3.get_spanish_rank() + " de " + carta3.get_spanish_suit() +
				"\t" << "(" + carta3.get_english_rank() + " of " + carta3.get_english_suit() + ")." + "\n";


			cout << "Dealer Cards: " << endl;
			dealer.displayAll(); //displaying all of the current cards in dealer's hand

			cout << "The dealer's total is " << dealer.get_points() << "." << endl << endl; //displays the totals with the new cards as they are being added

		}

		//outputting dealer's total points after they finish requesting new cards
		gamelog << "Dealer's total: " << dealer.get_points() << endl << endl;

		//Player wins and dealer busts
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

		//Player busts and dealer wins
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

		//Both player and dealer busts. Only the player loses money (house advantage)
		else if (player_uno.get_points() > 7.5 && dealer.get_points() > 7.5) {
			cout << "Both you and the dealer have bust. You both lose $" << bet << ". " << endl << endl;

			//temporary ints for both player and dealer money
			int player_temp = player1.get_money();

			//changing money amounts for both dealer and player
			player_temp -= bet;

			//setting the new money to private variable
			player1.set_money(player_temp);
		}

		//if both the dealer's and player's points are tied in that specific round
		else if (dealer.get_points() == player_uno.get_points()) {
			cout << "There has been a tie. No money will be won or lost." << endl << endl;
		}

		//Ending the game: either player or dealer has gotten to $0
		if (player1.get_money() == 0) { //if the dealer wins the entire game
			cout << "You have $0. GAME OVER!" << endl << "Come back when you have more money." << endl << endl << "Bye!";
			break;
		}

		else if (dealer1.get_money() == 0) { //if the input user wins the entire game
			cout << "Dealer has $0. YOU WON!" << endl << "Come back soon." << endl << endl << "Bye!";
			break;
		}

		//setting the new balances based on the results of the round
		starting_balance_player = player1.get_money();
		starting_balance_dealer = dealer1.get_money();

		//clearing both the player and dealer's hands in order to start a new round
		player_uno.clear();
		dealer.clear();

	}

	//concludes and closes the gamelog.txt file
	gamelog.close();

	cin.get();
	cin.get();
	return 0;
}