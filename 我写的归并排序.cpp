#include <stdio.h>
#include <stdlib.h>

const int max=123456789;
int len[200];

int* hebing(int *a,int na,int *b,int nb) {
	int i=0,j=0,k=0;
//	int na = len
//	int nb = sizeof(b)/sizeof(b[0]);
//	printf("na=%d nb=%d\n",na,nb);
	int *c = (int*)malloc((na+nb-1)*sizeof(int));
//	printf("SIZE=%d\n",sizeof(c)/sizeof(c[0]));
	while (k < na+nb-1) {
//	while ((i < na) && (j < nb)) {
		if (a[i] > b[j]) {
			c[k++] = b[j++];
		} else {
			c[k++] = a[i++];
		}
	}
	c[k] = max;
//	printf("SIZE=%d\n",sizeof(c)/sizeof(c[0]));
	free(a);
	free(b);
	return c;
}

void merge(int *a,int n) {
	int i,j,k,l,I;
	int *c[n];
	for (i=0 ; i<n; i++) {
		c[i] = (int*)malloc(2*sizeof(int));
		c[i][0] = a[i];
		c[i][1] = max;
		len[i] = 2;
	}
	while (i > 1) {
		j = 0;
		k = 0;
		while (k < i-1) {
			c[j] = hebing(c[k],len[k],c[k+1],len[k+1]);
			len[j++] = len[k++] + len[k++] - 1;
//			printf("j=%d k=%d\n",j,k);
		}
		if (k == i-1) {
			c[j] = c[k];
			len[j++] = len[k++];
		}
		i = j;
//		printf("i=%d\n",i);
		for (I=0; I<i; I++) {
			for (l=0; l<len[I]-1; l++) {
				printf("%d ",c[I][l]);
			}
		}
		printf("\n");
//		system("pause");
	}
}

int main(void) {
	int i,j,n;
	int *a = (int*)malloc(200*sizeof(int));

	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	merge(a,n);
//	for (i = 0; i < n; i++) {
//		printf(" %d", a[i]);
//	}
//	printf("\n");

	return 0;
}
