#include <stdio.h>

void ShellSort(int A[], int n) {
	int h = 0,k;
	while (h <= n) {                        
		h = 3 * h + 1;
	}
	while (h >= 1) {
		printf("h=%d\n",h); 
		for (int i = h; i < n; i++) {
			int j = i - h;
			int get = A[i];
			while (j >= 0 && A[j] > get) {
				A[j + h] = A[j];
				j = j - h;
			}
			A[j + h] = get;
			for (k=0; k<n; k++) {
				printf("%d ",A[k]);
			}
			printf("\n");
		}
		h = (h - 1) / 3;                 
	}
}

int main() {
	int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };
	int n = sizeof(A) / sizeof(int);
	ShellSort(A, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
