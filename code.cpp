#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int N = 0, F = 0, l = 0, r = 0;
	while (!scanf("%d", &N) || N < 0) {
		printf("  Wrong input, try again\n");
		while (getchar() != '\n');
	}
	int *fr = (int*)malloc(N * sizeof(int)), *frfr = (int*)malloc(N * 100 * sizeof(int));
	bool wron = false;
	for (int i = 0; i < N; i++) {
		if (!scanf("%d%d", &fr[i], &F) || fr[i] < 1000 || fr[i] > 9999 || F < 0) {
			printf("  Wrong input, try again\n");
			while (getchar() != '\n');
			i--;
			continue;
		}
		int j = 0;
		for (j; j < F; j++)
			if (!scanf("%d", &frfr[l + j]) || frfr[l + j] < 1000 || frfr[l + j] > 9999) {
				printf("  Wrong input, try again\n");
				while (getchar() != '\n');
				wron = true;
				break;
			}
		if (wron) {
			wron = false;
			i--;
			continue;
		}
		l += j;
		j = F = 0;
	}
	bool nope = false;
	for (int i = 0; i < l; i++) {
		for (int k = 0; k < N || k < i; k++) {
			if (k < N && frfr[i] == fr[k]) {
				nope = true;
				break;
			}
			if (k < i && frfr[i] == frfr[k]) {
				nope = true;
				break;
			}
		}
		if (nope) {
			nope = false;
			frfr[i] = 0;
			continue;
		}
		r++;
	}
	printf("%d\n", r);
	free(fr);
	free(frfr);
	return 0;
}