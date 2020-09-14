
#include <stdio.h>

#include <stdlib.h>



#define MAXVEX 9

#define INFINITY 65535



typedef int Patharc[MAXVEX];  //存放最短路径上的结点编号

typedef int ShortPathTable[MAXVEX]; //各节点到源点的路径(经过中间结点)长度



struct MGraph {

	int numVertexes;

	int *vex;

	int arc[MAXVEX][MAXVEX];

};



void ShortestPath_Dijkstra(MGraph *G, int v0, int vv, Patharc *P, ShortPathTable *D)

{

	int v, w, k, min;

	int result[MAXVEX];



	int n = 0;



	for (v = 0; v < G->numVertexes; ++v)

	{

		result[v] = 0;

		(*D)[v] = G->arc[v0][v];  //初始化，其余各节点到源点的距离

		(*P)[v] = -1;

	}

	(*D)[v0] = 0;

	result[v0] = 1; //源点加入

	(*P)[n++] = v0;



	for (v = 0; v < G->numVertexes; ++v)

	{

		min = INFINITY;

		for (w = 0; w < G->numVertexes; ++w) //寻找未加入的所有结点中到源点距离最短的结点k

		{

			if (!result[w] && (*D)[w] < min)

			{

				k = w;

				min = (*D)[w];

			}

		}

		result[k] = 1; //结点k加入

		(*P)[n++] = k;



		//判断是否到达终点

		if (k == vv)

			break;



		for (w = 0; w < G->numVertexes; ++w) //更新其余各节点到源点的距离的距离数组

		{

			//if(!result[w] && (min+G->arc[k][w]<(*D)[w])) //新节点w到源点的距离=k到源点的距离+k到w的距离

			if (!result[w])

			{

				(*D)[w] = min + G->arc[k][w];

				//(*P)[w]=k;

			}

		}

	}

	//输出结果

	printf("\n");

	for (v = 0; v < G->numVertexes; ++v)

	{

		printf("%d-->", (*P)[v]);

	}

}



void main()

{

	MGraph *my_g = (struct MGraph*)malloc(sizeof(struct MGraph));

	int i, j;

	int t = 0;



	int v0 = 0;

	int vv = 8;



	my_g->numVertexes = 9;

	my_g->vex = (int*)malloc(sizeof(char)*my_g->numVertexes);

	if (!my_g->vex) return;

	for (i = 0; i < my_g->numVertexes; ++i)  //一维数组(图中各结点)初始化{0,1,2,3,4,5,6,7,8}  

		my_g->vex[i] = i++;



	for (i = 0; i < my_g->numVertexes; ++i)

		for (j = 0; j < my_g->numVertexes; ++j)

			my_g->arc[i][j] = INFINITY;



	// 无向图的权值二维数组为对称矩阵

	my_g->arc[0][1] = 1;  my_g->arc[0][2] = 5;

	my_g->arc[1][2] = 3;  my_g->arc[1][3] = 7;  my_g->arc[1][4] = 5;

	my_g->arc[2][4] = 1;  my_g->arc[2][5] = 7;

	my_g->arc[3][4] = 2;  my_g->arc[3][6] = 3;

	my_g->arc[4][5] = 3;  my_g->arc[4][6] = 6;  my_g->arc[4][7] = 9;

	my_g->arc[5][7] = 5;

	my_g->arc[6][7] = 2;  my_g->arc[6][8] = 7;

	my_g->arc[7][8] = 4;

	for (i = 0; i < my_g->numVertexes; ++i)

		for (j = 0; j <= i; ++j)

		{

			if (i == j)

			{

				my_g->arc[i][j] = 0;

				continue;

			}

			my_g->arc[i][j] = my_g->arc[j][i];

		}

	for (i = 0; i < my_g->numVertexes; ++i)  //二维数组表示图中各结点间连接边的weight  

	{

		for (j = 0; j < my_g->numVertexes; ++j)

			printf("%5d  ", my_g->arc[i][j]);

		printf("\n");

	}

	printf("\n\n");





	Patharc P;

	ShortPathTable D;

	ShortestPath_Dijkstra(my_g, v0, vv, &P, &D);



	free(my_g->vex);

	//free(my_g->arc);

}
