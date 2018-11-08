
[深度优先DFS和广度优先BFS算法](https://www.jianshu.com/p/bff70b786bb6)

**深度优先搜索**

深度优先遍历图的方法是，从图中某顶点v出发：

1. 访问顶点v；
2. 依次从v的未被访问的邻接点出发，对图进行深度优先遍历；直至图中和v有路径相通的顶点都被访问；
3. 若此时图中尚有顶点未被访问，则从一个未被访问的顶点出发，重新进行深度优先遍历，直到图中所有顶点均被访问过为止。

**广度优先搜索**

从图的某一结点出发，首先依次访问该结点的所有邻接顶点 Vi1, Vi2, …, Vin 再按这些顶点被访问的先后次序依次访问与它们相邻接的所有未被访问的顶点，重复此过程，直至所有顶点均被访问为止。

Dijkstra单源最短路径算法和Prim最小生成树算法都采用了和宽度优先搜索类似的思想

**邻接矩阵**

邻接矩阵既可以用来存储无向图，也可以用来存储有向图。该结构实际上就是用一个二维数组（邻接矩阵）来存储顶点的信息和顶点之间的关系（有向图的弧或无向图的边）。



```c
#include <stdio.h>
#include <stdlib.h>
#define maxnum 30 //最大顶点个数
#define false 0
#define true 1

int visited[maxnum]; //被访问
typedef int vertextype; //顶点信息类型 
typedef int infotype; //节点信息类型

typedef struct node
{
    int adjvertex;
    infotype info;
    struct node *next;
} edgenode;//边

typedef struct vnode
{
    vertextype vertex; //顶点数据信息
    edgenode *firstedge; //顶点的所有边（链表头）
} vertexnode;//顶点

typedef struct
{
    vertexnode adjlist[maxnum]; //顶点集合
    int vertexnum, edgenum; //顶点数和弧数
} ALgraph;//图

typedef struct
{
    vertexnode data[maxnum]; //顶点集合
    int front, rear; //前后序号
} seqqueue, *Pseqqueue;//队列的定义

//创建一个图
void create(ALgraph *g)
{
    int i, j, k;
    edgenode *p, *q;
    printf("请输入图的顶点数和弧数(逗号隔开)：\n");
    scanf("%d,%d", &(g->vertexnum), &(g->edgenum));//输入要用逗号隔开
    printf("请输入顶点信息：\n");
    fflush(stdin);
    for(i = 0; i < g->vertexnum; i++)
    {
        scanf("%d", &(g->adjlist[i].vertex));
        g->adjlist[i].firstedge = NULL;
    }
    fflush(stdin);
    printf("请输入边的顶点对应序号：\n");

    for(k=0; k < g->edgenum; k++)
    {
        scanf("%d,%d", &i, &j);
        p = (edgenode *)malloc(sizeof(edgenode));
        p->adjvertex = j;
        if (g->adjlist[i].firstedge == NULL)
            g->adjlist[i].firstedge = p;
        else
        {
            q->next = p;
        }
        q = p;
        p->next = NULL;
    }
}

//一个简单的visit函数即输出函数
void visit(ALgraph g, int v)
{
    printf("%d", g.adjlist[v].vertex);
}

//深度遍历函数
void dfs(ALgraph g, int v)
{
    edgenode *p;
    int w; 
    visit(g, v);

    visited[v] = true; //设置当前订单已被访问

    //依次从v的未被访问的邻接点出发，对图进行深度优先遍历
    for(p = g.adjlist[v].firstedge; p; p = p->next)
    {
        w = p->adjvertex;

        if (!visited[w]) {
            dfs(g, w);
        }
    }
}

void dfstravel(ALgraph g)
{
    int v;
    for(v=0; v < g.vertexnum; v++)
        visited[v] = false;

    for(v=0; v < g.vertexnum; v++)
        if(!visited[v])
            dfs(g,v);
}

// 广度遍历要用到队列，先写队列的基本操作函数
Pseqqueue init()
{
    Pseqqueue q;
    q = (Pseqqueue)malloc(sizeof(seqqueue));

    if(q)
    {
        q->front = 0;
        q->rear = 0;
    }

    return q;
}

//判断队列是否为空
int empty(Pseqqueue q)
{
    if(q && q->front == q->rear)
        return true;
    else
        return false;
}

//进队列
int in(Pseqqueue q, ALgraph g, int v)
{
    if((q->rear + 1) % maxnum == q->front)
    {
        printf("队满");

        return -1;
    }
    else
    {
        q->rear++;
        q->data[q->rear] = g.adjlist[v];

        return 1;
    }
}

//出队列
int out(Pseqqueue q, vertexnode *x)
{
    if(empty(q))
    {
        //printf("队空");
        return -1;
    }
    else
    {
        q->front++;
        *x = q->data[q->front];
        return 1;
    }
}

// 广度优先遍历
void bfs(ALgraph g, int v)
{
    edgenode *p;
    int w;
    vertexnode u;
    Pseqqueue q;

    q = init();
    visit(g, v);
    visited[v] = true;
    in(q, g, v);
    int v1;

    for(v1 = 0; v1 < g.vertexnum; v1++)
        visited[v1] = false;

    while(!empty(q))
    {
        out(q, &u);

        for(p = u.firstedge; p; p = p->next)
        {
            w = p->adjvertex;
            if(!visited[w])
            {
                visit(g, w);
                visited[w] = true;
                in(q, g, w);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ALgraph g;

    //创建图
    create(&g);

    printf("深度优先遍历为");
    dfstravel(g);

    printf("\n广度优先遍历为");
    bfs(g, 0);

    printf("\n");

    return 0;
}
```