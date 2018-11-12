// inclure la bibliothèque dédiée à l'afficheur 4 digit
#include "TM1637.h"
// définir les pins de connexion pour la clock et la donnée
#define CLK 8
#define DIO 9
TM1637 tm1637(CLK, DIO); // attacher de manière effective nos pin et notre écran

// définir les caractères disponnibles
int8_t NumTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; //0~9,A,b,C,d,E,F
// définir une variable que l'on va augmenter petit à petit pour calculer en temps
int num = 0;

void setup() {
  // initialiser notre écran et spécifier sa luminosité
  tm1637.init();
  tm1637.set(BRIGHTEST);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop(){

  // calculer le chiffre à afficher pour chaque colone du tableau de numération
  // car même si notre chiffre à moins de 4 valeurs (0 pour les milliers, centaines et dizaines)
  // on veut afficher les zéros précédent notre valeur.
  int milles = int((num /1000)%10);
  int cents = int ((num /100)%10);
  int dizaines = int((num/10)%10);
  int unites = int(num%10);

  tm1637.display(0, NumTab[milles]); // afficher le chiffre des milliers sur l'ensemble de segment le plus à gauche
  tm1637.display(1, NumTab[cents]);
  tm1637.display(2, NumTab[dizaines]);
  tm1637.display(3, NumTab[unites]); // afficher le chiffre des unités sur l'ensemble de segment le plus à droite

  delay(10); // attendre un peu

  num +=1 ; // augmenter la valeur de num de 1
}
