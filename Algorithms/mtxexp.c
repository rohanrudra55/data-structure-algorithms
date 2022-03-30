#include<stdio.h>
void multiply(int a[3][3], int b[3][3], int x) {
	int mul[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < x; j++) {
			mul[i][j] = 0;
			for (int k = 0; k < 3; k++)
				mul[i][j] += a[i][k] * b[k][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < x; j++) {
			a[i][j] = mul[i][j];
			// printf("%d\t", a[i][j]);
		}
		// printf("\n");
	}
}

int power(int F[3][3], int n) {
	int G[3][3] = {{0, 1, 0}, {0, 0, 1}, {1 , 1, 0}};
	if (n == 1)
		return F[0][0] + F[0][1];

	power(F, n / 2);

	multiply(F, F, 3);

	if (n % 2 != 0)
		multiply(F, G, 3);

	return F[0][0] + F[0][1] ;
}
int main() {
	printf("Enter the n:\t");
	int n;
	scanf("%d", &n);
	int F[3][3] = {{0, 1, 0}, {0, 0, 1}, {1 , 1, 0}};
	int V[3][3] = {{3, 0, 0}, {0, 0, 0}, {2, 0, 0}};

	if (n == 1)
		printf("3");
	else if (n == 2)
		printf("0");
	else if (n == 3)
		printf("2");
	else {
		power(F, n - 1);
		multiply(F, V, 1);
		printf("P(N): %d", F[0][0]);
	}

	return 0;

}