//这个代码求的是第一个顶点到其他顶点的最短距离
#include<stdio.h>
int main() {
	//采用邻接矩阵来存储图
	int a[100][100],point,i,j,k,number,t1,t2,t3,u,v,min,book[10]= {0},dis[10];
	//point表示顶点数，number表示边数,t1,t2,t3,表示t1到t2的距离为t3,book数组用来标记哪些点目前是最短的距离,dis数组用来存储第一个顶点到其余顶点的最短距离
	int inf=99999999; //假设这个数表示无穷大
	scanf("%d %d\n",&point,&number);
	for(i=1; i<=point; i++) //本人习惯数组从1开始，这样可以用a[1]来表示第一个顶点
		for(j=1; j<=point; j++) {
			if(i==j) {
				a[i][j]=0;//初始化，当每个顶点到自身时，距离为0，否则为无穷大
			} else {
				a[i][j]=inf;
			}
		}
	//开始读入边
	for(i=1; i<=number; i++) {
		scanf("%d %d %d",&t1,&t2,&t3);
		a[t1][t2]=t3;
	}

	for(i=1; i<=point; i++) {
		dis[i]=a[1][i];
	} //存放1号顶点到其余顶点的距离,不可达则为inf（无穷大）

	book[1]=1;//标记第一个顶点已经是最短距离

	//Dijkstra算法开始
	for(i=1; i<=point-1; i++) {

		min=inf;
		for(j=1; j<=point; j++) { //求出当前dis数组中离第一个顶点最短的距离的顶点的下标
			if(book[j]==0 && dis[j]<min) {
				min=dis[j];
				u=j;//记下这个点的下标
			}
		}

		book[u]=1;

		for(k=1; k<=point; k++) {
			if(a[u][k]<inf) {
				if(dis[k]>dis[u]+a[u][k]) {
					dis[k]=dis[u]+a[u][k];
				}
			}

		}     //若找到其他途径比从1号顶点直接到目的顶点的距离短，则替换掉


	}


	for(i=1; i<=point; i++) {
		printf("1号顶点到%d号顶点的最短距离为------>%d\n",i,dis[i]);
	}




	return 0;
}
