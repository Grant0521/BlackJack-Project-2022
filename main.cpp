#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Global array of 52 items
vector<int> cardDeck;

// Declares Draw Card Function
int dealCard();

// Declares Blackjack Function
void blackJack(int match);

int main()
{
    string repeat = "yes";
    int match = 1;
    
    while (repeat != "no") {
        blackJack(match);
        match += 1;
        cout << "Would you like to play again? (yes or no)" << endl;
        cin >> repeat;
    }
 
    return 0;
}

// Manages Blackjack game and draws cards with dealCard()
void blackJack(int match){
    // Initialize variables
    int playerSum = 0, dealerSum = 0, playerCard, dealerCard;
    string choice = "yes";
    bool playerBust = false;
    
    // Space out title for repeated matches
    if (match > 1) {
        cout << endl << endl << endl;
    }
    
    // Title
    cout << "-------------BLACK JACK: Match " << match << "-------------" << endl << endl;
    
    // Loop to fill deck vector for number cards & ace
    // Four append statements for the four suits
    for (int i = 1; i < 11; ++i) {
        cardDeck.push_back(i);
        cardDeck.push_back(i);
        cardDeck.push_back(i);
        cardDeck.push_back(i);
    }
    
    // Loop to fill deck vector with face cards
    // Number of suits is accounted for in i incremental value
    for (int i = 0; i < 12; ++i) {
        cardDeck.push_back(10);
    }
    
    // Draw Player initial cards
    playerCard = dealCard();
    cout << "Your cards are " << playerCard;
    playerSum += playerCard;
    playerCard = dealCard();
    playerSum += playerCard;
    cout << " and " << playerCard << " for a total of " << playerSum << "." << endl;
    
    // Draw Dealer initial cards
    dealerCard = dealCard();
    cout << "The dealer's card is a " << dealerCard << "." << endl << endl;
    dealerSum += dealerCard;
    
    cout << "---------------Player's Turn---------------" << endl;
    
    // Loop to deal Player more cards until busting or getting Blackjack
    while ((choice != "no") && (playerSum < 21)) {
        cout << "Would you like another card? (yes or no)" << endl;
        cin >> choice;
        
        if (choice == "no") {
            break;
        }
        
        playerCard = dealCard();
        cout << "You drew a " << playerCard;
        playerSum += playerCard;
        cout << " for a total of " << playerSum << "." << endl << endl;
    }
    
    // Loop to skip Dealer turn if Player busts
    if (playerSum > 21) {
        playerBust = true;
    }
    
    // Loop to deal Dealer more cards
    if (playerBust == false) {
        cout << endl << "---------------Dealer's Turn---------------" << endl;
        while (dealerSum < 17) {
            dealerCard = dealCard();
            cout << "The dealer drew a " << dealerCard;
            dealerSum += dealerCard;
            cout << " for a total of " << dealerSum << "." << endl;
        }
        cout << endl;
    }
    
    cout << "-------------------Results-------------------" << endl;
    
    // If statements to determine outcome
    if (playerBust == true) {
        cout << "Player busted: Dealer Wins!";
    }
    else if (dealerSum > 21) {
        cout << "Dealer busted: Player Wins!";
    }
    else if ((dealerSum == 21) && (playerSum == 21)) {
        cout << "The Player scored " << playerSum << " and the Dealer scored " << dealerSum << "." << endl;
        cout << "Dealer and Player have Blackjack: Tie.";
    }
    else if (dealerSum == 21) {
        cout << "The Player scored " << playerSum << " and the Dealer scored " << dealerSum << "." << endl;
        cout << "Dealer has Blackjack: Dealer Wins!";
    }
    else if (playerSum == 21) {
        cout << "The Player scored " << playerSum << " and the Dealer scored " << dealerSum << "." << endl;
        cout << "Player has Blackjack: Player Wins!";
    }
    else if (playerSum > dealerSum) {
        cout << "The Player scored " << playerSum << " and the Dealer scored " << dealerSum << "." << endl;
        cout << "Player scored higher than Dealer: Player Wins!";
    } 
    else if (playerSum < dealerSum) {
        cout << "The Player scored " << playerSum << " and the Dealer scored " << dealerSum << "." << endl;
        cout << "Dealer scored higher than Player: Dealer Wins!";
    }
    else if (playerSum == dealerSum) {
        cout << "The Player scored " << playerSum << " and the Dealer scored " << dealerSum << "." << endl;
        cout << "Dealer and Player score equal: Tie.";
    }
    
    cout << endl << endl;
    
    // Resets deck for potential next round
    cardDeck.clear();
}

// Draws cards for blackJack()
int dealCard(){
    int chosenCard;
    
    // Sets time to be random
    srand(time(0));

    // Choses card index between 0 & 51
    chosenCard = cardDeck.at(rand() % cardDeck.size());
    cardDeck.erase(cardDeck.begin() + chosenCard);
    
    return chosenCard;
}
