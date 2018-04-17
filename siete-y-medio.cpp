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

	if (player1.get_money() != 0) {
		int bet;
		cout << "You have $" << player1.get_money() << ". Enter bet: ";
		cin >> bet;
		cout << endl;
		cout << "Your cards: " << endl;
		cout << setw(8) << card1.get_spanish_rank() << " de " << card1.get_spanish_suit(); 
	}
	return 0;
}