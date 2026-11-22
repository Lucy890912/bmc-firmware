#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int expandSensorBuffer(int **buffer,
                       size_t oldCount,
                       size_t newCount)
{
    //1.在確認 buffer 不為 NULL 之前，不能先存取 *buffer
    //2.雖然目前設定了oldCount和newCount的數值，仍要設定基本限制
    if( buffer==NULL || *buffer == NULL || 
        newCount <= oldCount || newCount == 0 || oldCount == 0){
        fprintf(stderr,"parameter not allowed");
        return -1;
    }

    if(newCount > (SIZE_MAX/sizeof(int))){
        fprintf(stderr,"allocation size overflow");
        return -1;
    }

    int *temp=realloc(*buffer,newCount * sizeof(int));
    // 怕配置失敗先用另一個變數來接，不要直接realloc -> 要做失敗處理
    // realloc() 接收原本由 malloc() 等配置函式回傳的配置區塊位址
    // realloc() 要調整的是 Heap 上的配置區塊，因此要傳入原本配置區塊的位址
    // 在配置成功的情況下，舊區塊會被釋放；若配置失敗，舊區塊則不會被釋放。

    // 如果失敗，原本的配置區塊仍然有效，不能遺失它

    if(temp==NULL){
        fprintf(stderr,"allocation failed");
        return -1;
    }

    for(size_t i = oldCount ; i < newCount ; i++){
        temp[i]=0;
    }

    *buffer=temp;

    return 0;
}

int main(void)
{
    //1.配置buffer空間
    int *buffer=malloc(3*sizeof(*buffer));//動態配置才可以 realloc
    if (buffer != NULL) {
        buffer[0] = 10;
        buffer[1] = 20;
        buffer[2] = 30;
    }else{
        fprintf(stderr,"buffer initialize allocation failed");
        return -1;
    }
    //一行寫完可用
    //if (buffer != NULL) memcpy(buffer, (int[]){10, 20, 30}, 3 * sizeof(*buffer));
    
    size_t buffersize = 3;
    size_t newCount = 6;
    for (size_t i=0;i<buffersize;i++){
        printf("%d ",buffer[i]);
    }
    printf("\n");
    int state = expandSensorBuffer(&buffer,buffersize,newCount);
    if (state==-1){
        //配置失敗還是要記得釋放記憶體
        free(buffer);
        return -1;
    }
    for (size_t i=0;i<newCount;i++){
        printf("%d ",buffer[i]);
    }

    free(buffer);
    buffer=NULL;

    return 0;
}
/*
buffer	    int **	呼叫者 Pointer 的位址
*buffer	    int *	動態配置區塊的位址
**buffer    int	    第一個整數元素
*/