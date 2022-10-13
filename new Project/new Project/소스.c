#include <stdio.h>
#include <stdlib.h>

#define MAX 1001
#define N 6      //정점의 갯수
#define INF 9999 //무한대 표시

int visited[MAX];//DFS 알고리즘에거 경로방문 체크용
int nodes[MAX];  //경로 방문 저장
int shortest_nodes[MAX]; //모든 경로중 최단 경로 저장용
int idx = 1;
int min_path; //최단 경로 찾기용(거리가 같다면, 가장 짧은 경로)
int min_dist; //최단 경로 찾기용(거리가 같다면, 가장 짧은 경로)

int flag[N + 1]; //최단거리가 확정된 정점(노드)
int dist[N + 1]; //최단거리값을 저장할 배열

int i, j, k, min, position;

//방향 가중치 그래프의 인접행렬
int data[N + 1][N + 1] = {
    {0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 2, INF, 3, INF, INF},
    {0, INF, 0, 4, 1, 7, INF},
    {0, INF, INF, 0, 4, 1, 3},
    {0, INF, 2, 2, 0, 1, INF},
    {0, INF, INF, 1, INF, 0, 6},
    {0, INF, 3, INF, 8, INF, 0}
};

int main() {
    dist[1] = 0;
    flag[1] = 1;

    for (i = 2; i <= N; i++) {
        flag[i] = 0;
        dist[i] = data[1][i];
    }

}