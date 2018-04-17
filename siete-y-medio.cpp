#include <iostream>
#include "cards.h"
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {

	srand((int)time(0));
	int STARTING_BALANCE = 100;
	Card card1;

	Player player1 = Player(STARTING_BALANCE);

	//if (player1.get_money() != 0) {
		int bet;
		cout << "You have $" << player1.get_money() << ". Enter bet: ";
		cin >> bet;
		cout << endl;
		if(bet > STARTING_BALANCE) {
			cout << "Your bet exceeds your starting balance. Please lower your bet: ";
			cin >> bet;
		}

		cout << "Your cards: " << endl;
		display(card1);
		cout << "Your total is " << ranktopoints(card1) << ". Do you want another card (y/n)?";
	//}
	return 0;
}