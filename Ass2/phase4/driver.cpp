// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include <iostream>
#include <iomanip>

#include "card.h" 
#include "standardDeck.h"

#define ROUNDS 50
#define DATA 2

void war(int* roundData); // A round of the game, updates its rounds data in scoreBoard
void initialize_tableTop(StandardDeck& fromDeck, StandardDeck& toDeck1, StandardDeck& toDeck2); // Initializes the player decks from one complete deck
bool equal_topTwo_cards(StandardDeck& deck); // Returns true if the top two cards of the deck have the same faceVal_
void output_statistics(int scoreBoard[][DATA]); // Outputs to the user the game statistics. Finds final winner, each players wins, and each players avg points

int main() 
{
	int scoreBoard[ROUNDS][DATA]; // [round][winner, points]
	int roundData[DATA]; // [winner, points]
	
	for (int i = 0; i < ROUNDS; i++)
	{
		std::cout << "Round " << i+1 << " ";
		war(roundData);
		std::cout << "Winner " << roundData[0] << " Points " << roundData[1] << std::endl;

		scoreBoard[i][0] = roundData[0];
		scoreBoard[i][1] = roundData[1];
	}

	output_statistics(scoreBoard);

	return 0;
};

void war(int* roundData) 
{
	bool gameOver = false;
	bool turnOver = false;
	int count_cards(0);

	// Setup the game
	StandardDeck* battleground = new StandardDeck();
	StandardDeck* player1 = new StandardDeck();
	StandardDeck* player2 = new StandardDeck();

	initialize_tableTop(*battleground, *player1, *player2);


	// Game Play Loop
	while (!gameOver)
	{
		// Player1 Turn
		while (!turnOver)
		{
			// Player1 Plays Card
			battleground->addCard(player1->dealCard());
			

			if (equal_topTwo_cards(*battleground)) // Checking if player1 wins battleground 
			{
				player1->mergeDecks(*battleground); 
			}
			else if (player1->isEmpty()) // End Game Condition - Player2 Wins
			{
				roundData[0] = 2;
				roundData[1] = player2->getNumCards();
			
				turnOver = true;
				gameOver = true;
			}
			else
			{
				turnOver = true;
			}
		}
		
		// Reset End Turn Condition
		turnOver = false;

		// Player2 Turn
		while (!turnOver)
		{
			// Player2 Plays Card
			battleground->addCard(player2->dealCard());
			

			if (equal_topTwo_cards(*battleground)) // Checking if player2 wins battleground 
			{
				player2->mergeDecks(*battleground); 
			}
			else if (player2->isEmpty()) // End Game Condition - Player1 Wins
			{
				roundData[0] = 1;
				roundData[1] = player1->getNumCards();
			
				turnOver = true;
				gameOver = true;
			}
			else
			{
				turnOver = true;
			}
		}

		// Reset End Turn Condition
		turnOver = false;

		// Check for lost cards
		count_cards = battleground->getNumCards() + player1->getNumCards() + player2->getNumCards();
		if (count_cards != DECK_SIZE)
		{
			std::cout << "ERROR-game_play_loop: Lost cards" << std::endl;
			
			// Free Heap Memory
			delete battleground;
			delete player1;
			delete player2;
		}

	}

	// Free Heap Memory
	delete battleground;
	delete player1;
	delete player2;
};

void initialize_tableTop(StandardDeck& fromDeck, StandardDeck& toDeck1, StandardDeck& toDeck2)
{
	fromDeck.initializeDeck();
	fromDeck.shuffle();

	while (fromDeck.getNumCards() > 1)
	{
		toDeck1.addCard(fromDeck.dealCard());
		toDeck2.addCard(fromDeck.dealCard());
	} 
};

bool equal_topTwo_cards(StandardDeck& deck)
{
	bool result = false;

	if (deck.getNumCards() < 2)
	{
		result = false;
	}
	else
	{
		Card topCard = deck.dealCard();
		Card secondCard = deck.dealCard();

		result = (topCard.getFace() == secondCard.getFace());

		// LIFO - temp cards were stored on the stack
		deck.addCard(secondCard);
		deck.addCard(topCard);
	}

	return result;
};

void output_statistics(int scoreBoard[][DATA])
{
	int wins_player1 = 0, wins_player2 = 0;
	int totalPoints_player1 = 0, totalPoints_player2 = 0;

	// Collect Data
	for (int i = 0; i < ROUNDS; i++)
	{
		if (scoreBoard[i][0] == 1)
		{
			wins_player1++;
			totalPoints_player1 += scoreBoard[i][1];
		}
		else if (scoreBoard[i][0] == 2)
		{
			wins_player2++;
			totalPoints_player2 += scoreBoard[i][1];
		}
		else
		{
			std::cout << "ERROR-output_statistics: " << scoreBoard[i][0] << std::endl;
		}
	}

	// Output Data
	if (wins_player1 == wins_player2)
	{
		std::cout << "Player1 and Player2 tied with " << wins_player1 << " victory's." << std::endl;
	}
	else 
	{
		std::cout << (wins_player1 > wins_player2 ? "Player1" : "Player2") << " won with " << (wins_player1 > wins_player2 ? wins_player1 : wins_player2) << " victory's" << std::endl;
	}
	std::cout << "Player1 average score: " << std::fixed << std::setprecision(2) << (float)totalPoints_player1/wins_player1 << std::endl;
	std::cout << "Player2 average score: " << std::fixed << std::setprecision(2) << (float)totalPoints_player2/wins_player2 << std::endl;
};