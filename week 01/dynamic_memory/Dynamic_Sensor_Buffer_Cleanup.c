#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //SIZE_MAX
void destroySensorBuffer(int **buffer)
{
    if( buffer==NULL || *buffer==NULL){
        return;
    }else{
        free(*buffer);
        *buffer=NULL;
    }
}

int main(void)
{
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
    
    for(size_t i=0 ; i < buffersize ; i++){
        buffer[i]=(int)(i+1)*10;
    }

    destroySensorBuffer(&buffer);

    if( buffer==NULL ){
        printf("buffer point to NULL");
    }

    destroySensorBuffer(&buffer);
    destroySensorBuffer(&buffer);
    destroySensorBuffer(NULL);

    return EXIT_SUCCESS;
}