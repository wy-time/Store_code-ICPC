#include<stdio.h>

#define MAXN 5001

int n, m;

int milk[MAXN], price[MAXN];

void init();

void sort();

void work();



int main() {

   init();

   sort();

   work();

   return 0;

}
void init() {

   int i;

   scanf("%d %d", &n, &m);

   for (i = 0; i < m; i++)

       scanf("%d %d", price + i, milk + i);

}



void sort() {

   int i, j, temp;

   for (i = 0; i < m; i++)

       for (j = 0; j <= i; j++) {

           if (price[i] < price[j])

            {

                temp = price[i];

                price[i] = price[j];

                price[j] = temp;

                temp = milk[i];

                milk[i] = milk[j];

                milk[j] = temp;

           }

       }
}



void work() {

   int i, sum, total;

    i= 0;

   total = 0;

   while (n > 0)

 {

       if (n > milk[i]) sum = milk[i];

       else sum = n;

       n -= sum;

       total += sum * price[i];

        i++;

    }

   printf("%d\n", total);

    return;

}
