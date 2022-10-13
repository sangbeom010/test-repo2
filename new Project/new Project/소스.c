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

    printf("초기상태의 D배열 출력: \n");
    for (k = 1; k <= N; k++) {
        printf("Dist[%d]:%d, ", k, dist[k]);
    }
    printf("\n");
    for (i = 1; i < N; i++) { // N-1번 반복
        printf("\n");
        min = INF;
        //Vmin 찾기
        for (j = 1; j <= N; j++) {
            if (min > dist[j] && flag[j] == 0) {
                min = dist[j];
                position = j;
            }
        }
        printf("selected Vmin is %d node  ", position);

        //선택된 Vmin을 확정
        flag[position] = 1;

        //D배열 갱신
        for (j = 1; j <= N; j++) {
            if (dist[j] > data[position][j] + dist[position] && data[position][j] != INF) {
                dist[j] = data[position][j] + dist[position];
            }
        }
        for (k = 1; k <= N; k++) {
            printf("Dist[%d]:%d, ", k, dist[k]);
        }
    }

    printf("\n\n");

    //1에서 1~6 각 노드별 모든 경로와 거리를 출력하고, 최단 거리 출력
    for (int i = 1; i <= N; i++) {
        //DFS알고리즘에서 사용하는 경로 방문용 배열 초기화, 출력용 경로저장용 배열 초기화
        for (int j = 1; j <= N; j++) {
            nodes[j] = 0;
            visited[j] = 0;
        }
        min_path = INF; min_dist = INF;
        idx = 1;
        nodes[idx] = 1;
        idx++;
        //DFS 알고리즘을 활용한 모든 경로와 거리 출력
        printf("> Node: %d, All paths\n", i);
        DFS(1, i);
        printf("## 1~%d: distance = %d, path: %d", i, dist[i], shortest_nodes[1]);
        for (int i = 2; i <= N; i++) {
            if (shortest_nodes[i] == INF || shortest_nodes[i] == 0) continue;
            printf(", %d", shortest_nodes[i]);
        }
        printf("\n\n");
    }
}


void DFS(int start_node, int dest_node) {
    int there, sum_dist, path_cnt;

    visited[start_node] = 1; //경로 방문 체크용

}