//�����������ǵ�һ�����㵽�����������̾���
#include<stdio.h>
int main() {
	//�����ڽӾ������洢ͼ
	int a[100][100],point,i,j,k,number,t1,t2,t3,u,v,min,book[10]= {0},dis[10];
	//point��ʾ��������number��ʾ����,t1,t2,t3,��ʾt1��t2�ľ���Ϊt3,book�������������Щ��Ŀǰ����̵ľ���,dis���������洢��һ�����㵽���ඥ�����̾���
	int inf=99999999; //�����������ʾ�����
	scanf("%d %d\n",&point,&number);
	for(i=1; i<=point; i++) //����ϰ�������1��ʼ������������a[1]����ʾ��һ������
		for(j=1; j<=point; j++) {
			if(i==j) {
				a[i][j]=0;//��ʼ������ÿ�����㵽����ʱ������Ϊ0������Ϊ�����
			} else {
				a[i][j]=inf;
			}
		}
	//��ʼ�����
	for(i=1; i<=number; i++) {
		scanf("%d %d %d",&t1,&t2,&t3);
		a[t1][t2]=t3;
	}

	for(i=1; i<=point; i++) {
		dis[i]=a[1][i];
	} //���1�Ŷ��㵽���ඥ��ľ���,���ɴ���Ϊinf�������

	book[1]=1;//��ǵ�һ�������Ѿ�����̾���

	//Dijkstra�㷨��ʼ
	for(i=1; i<=point-1; i++) {

		min=inf;
		for(j=1; j<=point; j++) { //�����ǰdis���������һ��������̵ľ���Ķ�����±�
			if(book[j]==0 && dis[j]<min) {
				min=dis[j];
				u=j;//�����������±�
			}
		}

		book[u]=1;

		for(k=1; k<=point; k++) {
			if(a[u][k]<inf) {
				if(dis[k]>dis[u]+a[u][k]) {
					dis[k]=dis[u]+a[u][k];
				}
			}

		}     //���ҵ�����;���ȴ�1�Ŷ���ֱ�ӵ�Ŀ�Ķ���ľ���̣����滻��


	}


	for(i=1; i<=point; i++) {
		printf("1�Ŷ��㵽%d�Ŷ������̾���Ϊ------>%d\n",i,dis[i]);
	}




	return 0;
}
