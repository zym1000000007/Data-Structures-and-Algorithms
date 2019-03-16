#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 600  //������������ֵ
#define MAXM 2000  //�ߵĸ��������ֵ
using namespace std;

struct edge { //��
	int u, v, w; //�ߵĶ��㡢Ȩֵ
	int equal;
	int used;
	int del; 
} edges[MAXM]; //�ߵ�����

int parent[MAXN];  //parent[i]Ϊ���� i ���ڼ��϶�Ӧ�����еĸ����
int n, m;  //����������ߵĸ���
int i, j;  //ѭ������
bool first;

void UFset( ) { //��ʼ��
	for( i=1; i<=n; i++ )
		parent[i] = -1;
}

int Find( int x ) { //���Ҳ����ؽڵ� x �������ϵĸ����
	int s; //����λ��
	for( s=x; parent[s]>=0; s=parent[s] );
	while( s!=x ) { //�Ż������Dѹ��·����ʹ�����Ĳ��Ҳ������١�
		int tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}

//��������ͬ���ϵ�Ԫ�ؽ��кϲ���ʹ����������������Ԫ�ض���ͨ
void Union( int R1, int R2 ) {
	int r1 = Find(R1), r2 = Find(R2); //r1 Ϊ R1 �ĸ���㣬r2 Ϊ R2 �ĸ����
	int tmp = parent[r1] + parent[r2]; //�������Ͻ�����֮��(����)
	//��� R2 ������������ > R1 ������������(ע�� parent[r1]�Ǹ���)
	if( parent[r1] > parent[r2] ) { //�Ż������D�D��Ȩ����
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

bool cmp( edge a, edge b ) { //ʵ�ִ�С��������ıȽϺ���
	return a.w <= b.w;
}

int Kruskal( ) {
	int sumweight = 0;  //��������Ȩֵ
	int num = 0;  //��ѡ�õıߵ���Ŀ
	int u, v;  //ѡ�ñߵ���������
	UFset( ); //��ʼ�� parent[]����
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
	int u, v, w; //�ߵ������յ㼰Ȩֵ
	scanf( "%d%d", &n, &m ); //���붥����� n
	for(i=0; i<m; i++ ) {
		scanf( "%d%d%d", &u, &v, &w ); //����ߵ������յ�
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
