#include<stdio.h>
#include<stdlib.h>

#define MIN -10001

typedef struct{
    int* Data;
    int Size;
}MinHeap;

void creatMinHeap(MinHeap* H, int N);
void insertMinHeap(MinHeap* H, int data);

int main(void){
    
    int i, data, idx;
    int N, M;
    MinHeap H;
    
    scanf("%d %d", &N, &M);
    
    creatMinHeap(&H , N);
    
    // 读入 N 个数，创建最小堆
     for(i = 0; i < N; i++){
        scanf("%d", &data);
        insertMinHeap(&H, data);
     }
    
    // 打印路径
    for(i = 0; i < M; i++){
        scanf("%d", &idx);
        printf("%d", H.Data[idx]);
        for(; idx / 2 > 0; idx /= 2)
            printf(" %d", H.Data[idx / 2]);
        printf("\n");
    }
    
    return 0;
}

void creatMinHeap(MinHeap* H, int N){
    H->Data = malloc(sizeof(int) * (N + 1));
    
    H->Size = 0;
    H->Data[0] = MIN; //设置哨兵
}

void insertMinHeap(MinHeap* H, int data){
    // 不需要判满
    int i;
    
    i = ++H->Size;
    for(; H->Data[i / 2] > data; i /= 2){
        H->Data[i] = H->Data[i / 2];
    }
    H->Data[i] = data;
}
