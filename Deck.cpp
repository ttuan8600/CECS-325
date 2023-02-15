// #include <iostream>
// #include "Deck.h"

// Deck::Deck(){
//   char ranks[] = {'A','2','3','4','5','6', '7','8','9','T','J','Q','K'};
//   char suits[] = {'S', 'H','D', 'C'};
//   int k = 0;
//   for (int i = 0; i < 4; i++){
//     for (int j = 0; j < 13; j++){
//       deck[k++] = Card(ranks[j],suits[i]);
//     }
//   }
//   top = 52;
// }

// void Deck::refreshDeck(){
//   char ranks[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
//   char suits[] = {'S', 'H', 'D', 'C'};
//   int k = 0;
//   for (int i = 0; i < 4; i++){
//     for (int j = 0; j < 13; j++){
//       deck[k++] = Card(ranks[j],suits[i]);
//     }
//   }
//   top = 52;
// }

// Card Deck::deal(){
//   Card c = deck[top-1];
//   top--;
//   return c;
// }

// void Deck::shuffle(){
//   srand(time(0));
//   for (int i = 0; i < top; i++){
//     int x = (rand() % (top-1));
//     Card temp = deck[i];
//     deck[i] = deck[x];
//     deck[x] = temp;
//   }
// }

// bool Deck::isEmpty(){
//   if (top == 0){
//     return true;
//   }else{
//     return false;
//   }
// }

// void Deck::display(){
//   for (int i = 0; i < top; i++){
//     if ((i % 13) == 0 && i != 0){
//       cout<<endl;
//       deck[i].display();
//       cout<<" ";
//     }else{
//       deck[i].display();
//       cout<<" ";
//     }
//   }
// }