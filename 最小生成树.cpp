#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 600  //顶点个数的最大值
#define MAXM 2000  //边的个数的最大值
using namespace std;

struct edge { //边
	int u, v, w; //边的顶点、权值
	int equal;
	int used;
	int del; 
} edges[MAXM]; //边的数组

int parent[MAXN];  //parent[i]为顶点 i 所在集合对应的树中的根结点
int n, m;  //顶点个数、边的个数
int i, j;  //循环变量
bool first;

void UFset( ) { //初始化
	for( i=1; i<=n; i++ )
		parent[i] = -1;
}

int Find( int x ) { //查找并返回节点 x 所属集合的根结点
	int s; //查找位置
	for( s=x; parent[s]>=0; s=parent[s] );
	while( s!=x ) { //优化方案―压缩路径，使后续的查找操作加速。
		int tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}

//将两个不同集合的元素进行合并，使两个集合中任两个元素都连通
void Union( int R1, int R2 ) {
	int r1 = Find(R1), r2 = Find(R2); //r1 为 R1 的根结点，r2 为 R2 的根结点
	int tmp = parent[r1] + parent[r2]; //两个集合结点个数之和(负数)
	//如果 R2 所在树结点个数 > R1 所在树结点个数(注意 parent[r1]是负数)
	if( parent[r1] > parent[r2] ) { //优化方案――加权法则
		parent[r1] = r2;
		parent[r2] = tmp;
	} else {
		parent[r2] = r1;
		parent[r1] = tmp;
	}
}

//int cmp(const void *a,const void *b) {
//	edge aa = *(const edge *)a;
//	edge bb = *(const edge *)b;
//	return aa.w - bb.w;
//}

bool cmp( edge a, edge b ) { //实现从小到大排序的比较函数
	return a.w <= b.w;
}

int Kruskal( ) {
	int sumweight = 0;  //生成树的权值
	int num = 0;  //已选用的边的数目
	int u, v;  //选用边的两个顶点
	UFset( ); //初始化 parent[]数组
	for( i=0; i<m; i++ ) {
		if (edges[i].del == 1) {
			continue;
		}
		u = edges[i].u;
		v = edges[i].v;
		if( Find(u) != Find(v) ) {
//			printf( "%d %d %d\n", u, v, edges[i].w );
			sumweight += edges[i].w;
			num++;
			Union( u, v );
			if (first) {
				edges[i].used = 1;
			}
		}
		if( num>=n-1 ) break;
	}
//	printf( "weight of MST is %d\n", sumweight );
	return sumweight;
}
int main( ) {
	int i,j;
	int u, v, w; //边的起点和终点及权值
	scanf( "%d%d", &n, &m ); //读入顶点个数 n
	for(i=0; i<m; i++ ) {
		scanf( "%d%d%d", &u, &v, &w ); //读入边的起点和终点
		edges[i].u = u;
		edges[i].v = v;
		edges[i].w = w;
		edges[i].equal = 0;
		edges[i].del = 0;
		edges[i].used = 0;
	}
//	printf("\n");
	for (i=0;i<m;i++) {
		for (j=0;j<m;j++) {
			if (i==j) {
				continue;
			}
			if (edges[j].w == edges[i].w) {
				edges[i].equal = 1;
			}
		}
	}
	sort(edges,edges+m,cmp);
	first = true;
	int weight1 = Kruskal(),weight2;
	first = false;
	printf("%d\n",weight1);
	for (i=0;i<m;i++) {
//		printf("i=%d use=%d\n",i,edges[i].used);
		if ((edges[i].used == 1) && (edges[i].equal == 1)) {
			edges[i].del = 1;
			weight2 = Kruskal();
			if (weight2 == weight1) {
				printf("No");
				break;
			}
			edges[i].del = 0;
		}
	}
	if (i == m) {
		printf("Yes");
	}
	
	return 0;
}
