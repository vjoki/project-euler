#include <stdio.h>

unsigned round_ui(double a)
{
   if ((a - (unsigned)a) >= 0.5)
      return (unsigned)a+1;
   return (unsigned)a;
}

unsigned card_score(char card[3])
{
   char c = card[0];
   if (c<58)
      return (c - '0') -1;
   else if (c=='T')
      return 9;
   else if (c=='J')
      return 10;
   else if (c=='Q')
      return 11;
   else if (c=='K')
      return 12;
   else if (c=='A')
      return 13;
}

unsigned card_pair_score(char h[5][3]) {
   unsigned i, c[14] = { 0 };
   for(i=0;i<5;i++)
      c[card_score(h[i])]++;
   
   unsigned p = 0, twop = 0, fullh = 0;
   for(i=1;i<14;i++) {
      if (c[i]>1) {
         if (c[i]==2) {
            p++;
            twop += i;
         } else if (c[i]==3)
            fullh += i;
         else if (c[i]==4)
            return 91 + i; // 4 of a kind
      }
   }
   
   if (fullh>0 && twop>0)
      return 78 + round_ui(twop*0.2+fullh*0.8); // full house
   else if (p==2)
      return 26 + round_ui(twop/2); // 2pair
   else if (twop>0)
      return 13 + twop; // pair
   else if (fullh>0)
      return 39 + fullh; // 3same
   
   return 0;
}

int compar(const void *a, const void *b)
{
   unsigned scorea = card_score((char*)a);
   unsigned scoreb = card_score((char*)b);
   if (scorea < scoreb) return -1;
   else if (scorea == scoreb) return 0;
   else return 1;
}

unsigned hand_score(char h[5][3])
{
   unsigned char samesuit = 0;
   unsigned score = 0;
   
   qsort(h[0], 5, sizeof(h[0])/sizeof(*h[0]), compar);
   
   score = card_pair_score(h);
   if (score > 90)
      return score; // 4 of a kind, cant be any higher without being a straight

   if(      h[0][1] == h[1][1] 
         && h[0][1] == h[2][1] 
         && h[0][1] == h[3][1] 
         && h[0][1] == h[4][1])
      samesuit = 1;
   
   if (samesuit==1) {
      if (     h[0][0] == 'T' && h[1][0] == 'J' 
            && h[2][0] == 'Q' && h[3][0] == 'K' 
            && h[4][0] == 'A')
         score = 118; // royal flush
      
      else if (card_score(h[0]) == card_score(h[1])-1 
            && card_score(h[1]) == card_score(h[2])-1 
            && card_score(h[2]) == card_score(h[3])-1 
            && card_score(h[3]) == card_score(h[4])-1)
         score = 104 + card_score(h[4]); // straight flush
      else
         score = 65 + card_score(h[4]); // flush
   } else {
      if (     card_score(h[0]) == card_score(h[1])-1 
            && card_score(h[1]) == card_score(h[2])-1 
            && card_score(h[2]) == card_score(h[3])-1 
            && card_score(h[3]) == card_score(h[4])-1)
         score = 52 + card_score(h[4]); // straight
   }
   
   if (score==0)
      score = card_score(h[4]); // highest card
   
   return score;
}

/*
void print_hand_name(unsigned score)
{
   if (score == 118)
      printf(" royal flush\n");
   else if (score > 104)
      printf(" straight flush\n");
   else if (score > 91)
      printf(" four of a kind\n");
   else if (score > 78)
      printf(" full house\n");
   else if (score > 65)
      printf(" flush\n");
   else if (score > 52)
      printf(" straight\n");
   else if (score > 39)
      printf(" three of a kind\n");
   else if (score > 26)
      printf(" two pairs\n");
   else if (score > 13)
      printf(" one pair\n");
   else if (score > 0)
      printf(" high card\n");
}
*/

int main (int argc, char* argv[])
{
   if (argc!=2) {
      printf("Usage: %s <input file>",argv[0]);
      return 1;
   }
   char h[2][5][3] = {'\0'};
   unsigned idx = 0, card = 0, player = 0;
   unsigned p1win = 0, p2win = 0; 
   
   FILE *f;
   int ch;
   f = fopen(argv[1], "rb");
   if (f != NULL) {
      while (ch != EOF) {
         ch = fgetc(f);
         if (ch == EOF)
            break;
         else if (ch == '\n') {
            unsigned p1 = hand_score(h[0]);
            unsigned p2 = hand_score(h[1]);
            
            if (p1 > p2)
               p1win++;
            else if (p1 < p2)
               p2win++;
            else {
               unsigned z;
               for(z=4;z>=0;z--) {
                  p1 = card_score(h[0][z]);
                  p2 = card_score(h[1][z]);
                  if (p1 != p2)
                     break;
               }
               
               if (p1 > p2)
                  p1win++;
               else if (p1 < p2)
                  p2win++;
            }
            if (p1 > 118 || p2 > 118)
               printf("%u == %u %s %s\n", p1, p2, h[0][0], h[1][0]);
               
            player = 0;
            card = 0;
            idx = 0;
            continue;
         } else if (ch == ' ') {
            if (card<4)
               card++;
            else {
               player++;
               card = 0;
            }
            idx = 0;
         } else
            h[player][card][idx++] = ch;
      }
      if (fclose(f) != 0)
         return 1;
   }
   printf("hands: %u | p1 wins: %u, p2 wins: %u\n",p1win+p2win,p1win,p2win);
   return 0;
}