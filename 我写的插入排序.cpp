#include<stdio.h>
void InsertSort(int *a, int n) {
	int tmp = 0,k;
	for (int j = 1; j < n; j++) {
		int i = j - 1;
		if (a[i] > a[j]) {
			tmp = a[j];
			a[j] = a[i];
			while ((tmp < a[i-1]) && (i > 0)) {
				a[i] = a[i-1];
				i--;
			}
//			printf("i=%d tmp=%d j=%d\n",i,tmp,j);
			a[i] = tmp;
		}
		for (k=0; k<n; k++) {
			printf("%d ",a[k]);
		}
		printf("\n");
	}
}
int main() {
	int a[100],n,i;
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
//    int n = sizeof(a)/sizeof(int);
	InsertSort(a, n);
//    printf("???????:");
	for (i = 0; i < n; i++) {
		printf(" %d", a[i]);
	}
	printf("\n");
	return 0;
}
