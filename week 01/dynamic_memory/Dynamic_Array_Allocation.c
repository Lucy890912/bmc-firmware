#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int *createSensorArray(size_t count)
{
    if (count == 0){
        fprintf(stderr, "count == 0\n");
        return NULL;
    }
    if (count > (SIZE_MAX/sizeof(int)) ){
        //對size_t，乘法結果永遠不可能大於 SIZE_MAX，因為 SIZE_MAX 本來就是該型態可表示的最大值
        fprintf(stderr, "allocation size overflow\n");
        return NULL;
    }
    if((count-1)>(INT_MAX/10)){
        fprintf(stderr, "int overflow\n");
        return NULL;
    }
    int *s=malloc(count*sizeof(int));
    //也可以寫int *s = malloc(count * sizeof(*s));
    //如果未來將 s 的型別改成其他資料型別，sizeof(*s) 會自動對應
    if (s == NULL){
        fprintf(stderr, "memory allocation failed\n");
        return NULL;
    }
    
    for(size_t i=0;i<count;i++){ //要用i和count比較，型別要一樣
        s[i]=(int)i*10; 
        //s內型別為int，i型別為size_t，強制轉型為相同型別
        //size_t 是 Unsigned Integer Type，而 int 是 Signed Integer Type
        //(int)i 不是為了讓索引與陣列型態一致才必須使用，而是為了讓後續乘法使用 int 運算
    }
    return s;
}

int main(void)
{
    size_t count=5;
    int *sensorData=createSensorArray(count);
    if (sensorData!=NULL){
        for(size_t i=0;i<count;i++){
            printf("%d ",*(sensorData+i));
        }
    }else{
        return EXIT_FAILURE;
    }
    free(sensorData);
    sensorData=NULL;
    return EXIT_SUCCESS;
}