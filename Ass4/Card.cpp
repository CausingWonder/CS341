// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include "Card.h"

// Static Private Members
std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

/// Public:
// Lifetime Methods
Card::Card() 
{
	suitVal_ = 0;
	faceVal_ = 0;
}

Card::Card(int suit, int face) 
{
	suitVal_ = suit;
	faceVal_ = face;
}

Card::Card(const Card& other)
{
	suitVal_ = other.suitVal_;
	faceVal_ = other.faceVal_;
}

Card::~Card() 
{
}

// Getters
std::string Card::getSuit() const
{
	return SUIT[suitVal_];
}

std::string Card::getFace() const
{
	return FACE[faceVal_];
}	

int Card::getFaceVal() const
{
	return faceVal_;
}

// Overloaded Operators
bool Card::operator==(const Card& other) const
{
    return faceVal_ == other.faceVal_;
}

bool Card::operator<(const Card& other) const
{
    return faceVal_ < other.faceVal_;
}

bool Card::operator>(const Card& other) const
{
    return faceVal_ > other.faceVal_;
}

// Additional Methods
std::string Card::print() const
{
	return (FACE[faceVal_] + " of " + SUIT[suitVal_]);
}

void Card::initialize(int suit, int face)
{
	suitVal_ = suit;
	faceVal_ = face;
}
