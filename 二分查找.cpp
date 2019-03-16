#include <stdio.h>
 
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

int find2(int x,int *b,int left,int right) {//找第一个大于等于x 
	int i,l=left,r=right,mid;
	while ((l <= left) && (left <= right) && (right <= r)) {
		mid = (left + right) / 2;
		if (b[mid] < x) {
			left = mid + 1; 
		} else {
			right = mid - 1;
		}
	}
	return left;
}

int find3(int x,int *b,int left,int right) {//找最后一个小于等于x 
	int i,l=left,r=right,mid;
	while ((l <= left) && (left <= right) && (right <= r)) {
		mid = (left + right) / 2;
		if (b[mid] <= x) {
			left = mid + 1; 
		} else {
			right = mid - 1;
		}
	}
	return right;
}

int find4(int x,int *b,int left,int right) {//找最后一个小于x 
	int i,l=left,r=right,mid;
	while ((l <= left) && (left <= right) && (right <= r)) {
		mid = (left + right) / 2;
		if (b[mid] < x) {
			left = mid + 1; 
		} else {
			right = mid - 1;
		}
	}
	return right;
}

int main(void) {
	int i,n=16;
	int a[n] = {1,2,3,3,4,6,6,6,6,7,7,8,8,8,8,8};
	for (i=0;i<n;i++) {
		printf("i=%d a=%d\n",i,a[i]);
	}
	printf("%d\n",find(6,a,0,9));
	printf("%d\n",find2(6,a,0,9));
	printf("%d\n",find3(6,a,0,9));
	printf("%d\n",find4(6,a,0,9));
	return 0;
}
