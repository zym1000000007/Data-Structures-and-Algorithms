#include <stdio.h>

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//分治法把数组分成两份
int patition(int *a, int left,int right) {
	int j = left;    //用来遍历数组
	int i = j - 1;    //用来指向小于基准元素的位置
	int key = a[right];    //基准元素
	//从左到右遍历数组，把小于等于基准元素的放到左边，大于基准元素的放到右边
	for (; j < right; ++j) {
		if (a[j] < key)//去掉==后速度快了很多！！！
			swap(&a[j], &a[++i]);
	}
	//把基准元素放到中间
	swap(&a[right], &a[++i]);
	//返回数组中间位置
	return i;
}

void quickSort(int *a,int left,int right) {
	if (left>=right)
		return;
	int mid = patition(a,left,right);
	quickSort(a, left, mid - 1);
	quickSort(a, mid + 1, right);
}

int main(void) {
	int i,j,n;

	scanf("%d",&n);
	int a[n];

	for (i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}

	quickSort(a,0,n-1);
	for (i=0; i<n; i++) {
		printf("%d",a[i]);
	}

	return 0;
}
