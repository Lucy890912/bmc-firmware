#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //SIZE_MAX
void destroySensorBuffer(int **buffer)
{
    // TODO: 檢查參數
    if( buffer==NULL || *buffer==NULL){
        return;
    }

    // TODO: 釋放記憶體
    else{
        free(*buffer);
    // TODO: 將呼叫者的 Pointer 設為 NULL
        *buffer=NULL;
    }

    
}

int main(void)
{
    // TODO: malloc 配置 3 個 int
    size_t buffersize=3;
    // 溢位檢查的元素大小，應該與 malloc() 使用的元素大小一致
    if( buffersize > SIZE_MAX/sizeof(int) ){
            fprintf(stderr,"allocation size overflow");
            return EXIT_FAILURE;
    }    
    int *buffer=malloc(buffersize*sizeof(*buffer));
    // 不能*buffer==NULL，此時 *buffer 是讀取未初始化資料，屬於未定義行為
    if( buffer == NULL ){
        fprintf(stderr,"malloc failed");
        return EXIT_FAILURE;
    }


    // TODO: 初始化 10、20、30
    
    for(size_t i=0 ; i < buffersize ; i++){
        buffer[i]=(int)(i+1)*10;
    }

    // TODO: 呼叫 destroySensorBuffer()
    destroySensorBuffer(&buffer);

    // TODO: 驗證 Pointer 是否為 NULL
    if( buffer==NULL ){
        printf("buffer point to NULL");
    }

    // TODO: 再次呼叫 destroySensorBuffer()
    destroySensorBuffer(&buffer);

    // TODO: 測試其他 NULL 情況
    destroySensorBuffer(&buffer);
    destroySensorBuffer(NULL);

    return EXIT_SUCCESS;
}