#include <stdio.h>
#define max 123456789

int find(int x,int *b,int left,int right) {//找第一个大于x
	int i,l=left,r=right,mid;
	while ((l <= left) && (left <= right) && (right <= r)) {
		mid = (left + right) / 2;
		if (b[mid] <= x) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return left;
}

int main(void) {
	int i,j,n,len,index,k;

	scanf("%d",&n);
	int a[n],b[n],c[n],d[n];
	
	for (i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	len = 0;
	b[len] = -max;
	for (i=0; i<n; i++) {
		if (a[i] >= b[len]) {
			len++;
			b[len] = a[i];
			c[i] = len;
		} else {
			index = find(a[i],b,0,len);
			b[index] = a[i];
			c[i] = index;
		}
	}
	printf("maxlen=%d\n",len);
	k = 0;
	for (i=n-1; i>=0; i--) {
		if (c[i] == len) {
			d[k++] = a[i];
			len--;
		}
	}
	for (i=k-1; i>=0; i--) {
		printf("%d ",d[i]);
	}

	return 0;
}
