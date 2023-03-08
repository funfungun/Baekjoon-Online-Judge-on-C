//c언어로 쉽게 풀어쓴 자료구조 p.382, p.387 참고

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 1000//최대 정점 수
#define MAX_QUEUE_SIZE 1000

//bfs에 사용할 큐 정의
typedef int element;
typedef struct
{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void queue_init(QueueType *q)
{
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        return;
        
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q)
{
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    
    return q->queue[q->front];
}

//정점 번호가 1번부터 시작하므로 +1
//방문 여부를 표시할 배열 선언
int visited_dfs[MAX_VERTICES+1];
int visited_bfs[MAX_VERTICES+1];

//그래프 정의
typedef struct
{
    int n;//정점의 개수
    int adj_mat[MAX_VERTICES+1][MAX_VERTICES+1];//인접 행렬로 간선 존재 여부 표시
}GraphType;

//그래프 초기화 함수
void graph_init(GraphType *g)
{
    g->n = 0;
    
    for(int r=1; r<=MAX_VERTICES; r++)
        for(int c=1; c<=MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

//정점 삽입 함수
void insert_vertex(GraphType *g, int v)
{
    if(((g->n) + 1) > MAX_VERTICES)//정점의 개수를 추가하려고 하는데
        return;//최대 정점 수보다 많아질 경우 오류
        
    g->n++;//정점의 개수 추가
}

//간선 삽입 함수
void insert_edge(GraphType *g, int start, int end)
{
    if(start > g->n || end > g->n)//정점 번호가 정점의 개수의 숫자보다 크면 오류
        return;//정점 번호가 1번부터 시작하므로 크면 오류, 0번부터 시작하면 같아도 오류
    
    //1이면 간선 o, 0이면 간선 x.
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

//깊이 우선 탐색
void dfs(GraphType *g, int v)
{
    visited_dfs[v] = TRUE;//일단 방문했다고 표시
    printf("%d ", v);
    
    for(int w=1; w<=g->n; w++)//남은 모든 정점에 대해서
        if(g->adj_mat[v][w] && !visited_dfs[w])//시작 정점과 서로 인접해 있고, 아직 방문하지 않았으면 
            dfs(g, w);//그 정점에서 dfs를 다시
}

//너비 우선 탐색
void bfs(GraphType *g, int v)
{
    QueueType q;
    queue_init(&q);
    
    visited_bfs[v] = TRUE;//일단 방문했다고 표시
    printf("%d ", v);
    
    enqueue(&q, v);//큐에 시작 정점을 일단 삽입
    
    while(!is_empty(&q))//큐가 공백이 될 때까지
    {
        v = dequeue(&q);//일단 큐에서 정점을 삭제
        
        for(int w=1; w<=g->n; w++)//남은 모든 정점에 대해서
        {
            if(g->adj_mat[v][w] && !visited_bfs[w])//시작 정점과 서로 인접해 있고, 아직 방문하지 않았으면
            {
                visited_bfs[w] = TRUE;//일단 방문했다고 표시
                printf("%d ", w);
                enqueue(&q, w);//큐에 방문한 정점을 삽입
            }
        }
    }    
}

int main()
{
    int N,M,V;
    scanf("%d %d %d", &N, &M, &V);
    
    GraphType *g1;
    g1 = (GraphType *)malloc(sizeof(GraphType));
    
    GraphType *g2;
    g2 = (GraphType *)malloc(sizeof(GraphType));
    
    graph_init(g1);
    graph_init(g2);
    
    for(int i=1; i<=N; i++)
    {
        insert_vertex(g1, i);
        insert_vertex(g2, i);
    }
        
    for(int i=0; i<M; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        
        insert_edge(g1, a, b);
        insert_edge(g2, a, b);
    }
    
    dfs(g1, V);
    printf("\n");
    bfs(g2, V);
    
    free(g1);
    free(g2);
    
    return 0;
}