#include <stdio.h>

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//���η�������ֳ�����
int patition(int *a, int left,int right) {
	int j = left;    //������������
	int i = j - 1;    //����ָ��С�ڻ�׼Ԫ�ص�λ��
	int key = a[right];    //��׼Ԫ��
	//�����ұ������飬��С�ڵ��ڻ�׼Ԫ�صķŵ���ߣ����ڻ�׼Ԫ�صķŵ��ұ�
	for (; j < right; ++j) {
		if (a[j] < key)//ȥ��==���ٶȿ��˺ܶ࣡����
			swap(&a[j], &a[++i]);
	}
	//�ѻ�׼Ԫ�طŵ��м�
	swap(&a[right], &a[++i]);
	//���������м�λ��
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
