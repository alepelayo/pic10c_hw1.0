## Assignment 1: "_Siete y Medio_" Card Game

This is a rendition of the class card game "siete y medio" 
(seven and a half) in which the player is playing against the dealer.

### Possible Outcomes when playing include:

Winning a round (winning intial bet amount):

- The player comes closer to 7 1/2 than the dealer
- The player is below 7 1/2 and the dealer busts

Losing a round (losing intial bet amount):
	
- The dealer comes closer to 7 1/2 than the player
- The dealer is below 7 1/2 and the player busts
- Both the dealer and player bust: this is known as the *house advantage*

Ending in a tie (initial bet is neither won nor lost):

- Both the dealer and player have the same total and do not bust

### Game Mechanics:

Unlike the more common game of Blackjack (also known as 21), the *'Spanish
Baraja'* being used only goes up to 7 before jumping to 10, or the **sota**,
11, or the **caballo**, and 12, or the **rey**.

| Name:   | As | Dos | Tres | Cuatro | Cinco | Seis | Siete | Sota | Caballo | Rey |
|--- | ---| ---|--- |---| ---| ---| ---| ---| ---| ---|
|Rank: | 1 | 2 | 3 | 4 | 5| 6| 7| 10 | 11 | 12 |
|Point value:| 1 | 2 | 3 | 4 | 5| 6| 7| 1/2 | 1/2 | 1/2 |

Each game begins with a simply question of how much the player wishes to bet.
Once the player inputs a sufficient bet amount, their first card is drawn as
well as the number of points they currently have with their initial card.

Player's points are updated whenever they wish to add another card to their hand. 
Once they no longer wish to add cards to their hand, the game automatically shifts 
to the dealer's turn. The same process is repeated with the dealer's hand, except it 
is done almost instantly, since the dealer can automatically answer whether they wish 
to add more cards to their hand. 

Once the dealer reaches a specific number of points, all their cards and points will be displayed 
similarly to the player's. The player's and dealer's points are then compared to determine the 
winners of that specific round. Money amount for both the player and dealer are updated and a new
round begins automatically.

## gamelog.txt file

At the end of every round, the gamelog.txt file records both the player's and dealer's hands and final
points in addition to the initial bet amount and round number.  


Original assignment description: 

- http://pic.ucla.edu/~rsalazar/pic10c/assignments/hw1/index.html
