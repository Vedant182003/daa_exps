#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void print_optimal_parens(int s[MAX_SIZE][MAX_SIZE], int i, int j, char name) {
    if (i == j) {
        printf("%c", name++);
    } else {
        printf("(");
        print_optimal_parens(s, i, s[i][j], name);
        print_optimal_parens(s, s[i][j]+1, j, name+s[i][j]-i+1);
        printf(")");
    }
}

int matrix_chain_order(int p[], int n, char name) {
    int m[MAX_SIZE][MAX_SIZE], s[MAX_SIZE][MAX_SIZE];

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Optimal parenthesization: ");
    print_optimal_parens(s, 1, n, name);
    printf("\n");

    return m[1][n];
}

int main() {
    	int num;
    	printf("Enter the number of matrices: ");
    	scanf("%d", &num);
    	int matrices[num][2];
	int indexes[num+1];
	for(int i = 0 ;i <= num; i++){
		printf("Enter the dimensions of the matrix: ");
		scanf("%d",&indexes[i]);
	}
	int i = 0 ;
	while( i <= num){
		matrices[i][0] = indexes[i];
		matrices[i][1] = indexes[i+1] ;
		i++ ;
	}
    printf("Minimum cost of matrix multiplication: %d\n", matrix_chain_order(indexes, num , 'A'));

    return 0;
}
