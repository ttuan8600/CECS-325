#include <ctime>
#include <iostream>
#include <stack>

using namespace std;

class Card {
private:
  char rank;
  char suit;

public:
  Card() {
    rank = ' ';
    suit = ' ';
  }

  Card(char r, char s) {
    rank = r;
    suit = s;
  }

  void setCard(char r, char s) {
    rank = r;
    suit = s;
  }

  int getValue() {
    if (rank == 'A') {
      return 1;
    } else if (rank == '2') {
      return 2;
    } else if (rank == '3') {
      return 3;
    } else if (rank == '4') {
      return 4;
    } else if (rank == '5') {
      return 5;
    } else if (rank == '6') {
      return 6;
    } else if (rank == '7') {
      return 7;
    } else if (rank == '8') {
      return 8;
    } else if (rank == '9') {
      return 9;
    } else if (rank == 'T' || rank == 'J' || rank == 'Q' || rank == 'K') {
      return 10;
    } else {
      return 0;
    }
  }

  void display() {
    if (rank == 'T') {
      cout << "10" << suit << ",";
    } else {
      cout << rank << suit << ", ";
    }
  }
};

class Deck {
private:
  Card deck[52];
  int top;

public:
  Deck() {
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'T', 'J', 'Q', 'K'};
    char suits[] = {'S', 'H', 'D', 'C'};
    int k = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        deck[k++] = Card(ranks[j], suits[i]);
      }
    }
    top = 52;
  }

  void refreshDeck() {
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'T', 'J', 'Q', 'K'};
    char suits[] = {'S', 'H', 'D', 'C'};
    int k = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        deck[k++] = Card(ranks[j], suits[i]);
      }
    }
    top = 52;
  }

  Card deal() {
    Card c = deck[top - 1];
    top--;
    return c;
  }

  void shuffle() {
    srand(time(0));
    for (int i = 0; i < top; i++) {
      int x = (rand() % (top - 1));
      Card temp = deck[i];
      deck[i] = deck[x];
      deck[x] = temp;
    }
  }

  bool isEmpty() {
    if (top == 0) {
      return true;
    } else {
      return false;
    }
  }

  void display() {
    for (int i = 0; i < top; i++) {
      if ((i % 13) == 0 && i != 0) {
        cout << endl;
        deck[i].display();
        cout << " ";
      } else {
        deck[i].display();
        cout << " ";
      }
    }
  }
};

Deck deck;
int played = 0;
int play();
int cheat();
bool isFibo(int n);
void displayHand(stack<Card> h);

int main() {
  int choice = 0;
  int games = 0;
  while (choice != 5) {
    cout << "Welcome Fibonacci Solitaire!\n1) New Deck\n2) Display Deck\n3) "
            "Shuffle Deck\n4) Play Solitaire\n5) Exit\n6) Instant Win\n\nChoice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      deck.refreshDeck();
      cout << "\n***New deck created***\n" << endl;
      break;
    case 2:
      cout << "\nDeck: " << endl;
      deck.display();
      cout << endl << endl;
      break;
    case 3:
      cout << "\nShuffling Deck . . ." << endl;
      deck.shuffle();
      cout << "***Deck shuffled***\n" << endl;
      break;
    case 4:
      play();
      break;
    case 5:
      played = 0;
      cout << "\nEnding game!!!" << endl;
      exit(0);
      break;
    case 6:
      cout << "\nPlaying until win..." << endl;
      cout << "\nYou won the game in " << cheat() << " games!" << endl;
      break;
    default:
      cout << "\nInvalid choice !!!\n" << endl;
      break;
    }
  }
}

int cheat(){
  int games = 0;
  int win = play();
  do {
    deck.refreshDeck();
    deck.shuffle();
    play();
    games++;
  }while(win == 1);
  return games;
}

int play() {
  if (deck.isEmpty()) {
    cout << "\nDeck is empty !!!\n" << endl;
    return -1;
  }
  cout << "\nPlaying Fibonacci Solitaire !!!\n" << endl;
  stack<Card> hand;
  int piles = 0;
  int sum = 0;

  while (deck.isEmpty() == false) {
    Card c = deck.deal();
    sum += c.getValue();
    if (isFibo(sum) == true) {
      c.display();
      cout << "Fibo: " << sum << endl;
      piles++;
      sum = 0;
    } else {
      c.display();
    }
  }
  played++;
  if (sum != 0) {
    cout << "\nLast hand value: " << sum << endl;
    cout << "Loser in " << piles << " piles!\n" << endl;
    return 1;
  } else {
    cout << "Winner in " << piles << " piles!" << endl;
    cout << "\n\nGames played: " << played << endl << endl;
    played = 0;
    return 0;
  }
}

bool isFibo(int n) {
  int fib[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
  for (int i = 0; i < (sizeof(fib) / sizeof(int)); i++) {
    if (n == fib[i]) {
      return true;
    }
  }
  return false;
}