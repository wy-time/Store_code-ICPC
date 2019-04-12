#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


const int len_max = 2000;
int poi[4][2];
int main() {
	int cont = 0;
	for ( int wid = len_max ; wid >= 3 ; --wid) {
		// int x_mov = 0;
		// int y_mov = 0;
		// int len = 1;

		for (int len = 1 ; len < len_max ; ++len) {

			for (int x_mov = 0 ; len * 2 + x_mov < wid ; ++x_mov) {
				for (int y_mov = 0 ; len * 2 + y_mov < wid ; ++y_mov) {
					poi[0][0] = x_mov + len;
					poi[0][1] = y_mov;

					poi[1][0] = x_mov;
					poi[1][1] = y_mov + len;

					poi[2][0] = x_mov + 2 * len;
					poi[2][1] = y_mov + len;

					poi[3][0] = x_mov + len;
					poi[3][1] = y_mov + len * 2;

					printf("%d\n", wid);
					int poi_ind = 0;
					for (int x_ind = 0 ; x_ind < wid ; ++x_ind) {
						for (int y_ind = 0 ; y_ind < wid ; ++y_ind) {
							if (poi_ind < 4) {
								if (y_ind == poi[poi_ind][0] && x_ind == poi[poi_ind][1])
								{
									printf("1");
									poi_ind++;
								}
								else {
									printf("0");
								}

							} else {
								printf("0");
							}
							if (y_ind == (wid - 1)) {
								printf("\n");
							} else {
								printf(" ");
							}
						}
					}
					cont++;
					if (cont > 100000)
					{
						return 0;
					}
				}
			}
		}
	}
	return 0;
}