
#include "TM1637.h"
#define CLK 8//pins definitions for TM1637 and can be changed to other ports
#define DIO 9
TM1637 tm1637(CLK, DIO);
// available characters
int8_t NumTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; //0~9,A,b,C,d,E,F

int num = 0;
void setup()
{
  tm1637.init();
  tm1637.set(BRIGHTEST);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}
void loop()
{


  int milles = int((num /1000)%10);
  int cents = int ((num /100)%10);
  int dizaines = int((num/10)%10);
  int unites = int(num%10);



  tm1637.display(0, NumTab[milles]);
  tm1637.display(1, NumTab[cents]);
  tm1637.display(2, NumTab[dizaines]);
  tm1637.display(3, NumTab[unites]);
  delay(10);
    num +=1 ;

}
