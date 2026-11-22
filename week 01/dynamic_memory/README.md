# Dynamic Memory Management
本次練習主要學習 C 語言的動態記憶體管理（Dynamic Memory Management），透過模擬 Sensor Data Buffer 的建立、擴充與釋放，理解 Heap Memory、Pointer、Double Pointer 及 Memory Safety 的重要觀念。
## Topics
- malloc()  - Dynamic Memory Allocation
- realloc() — Dynamic Memory Reallocation
- free()    — Memory Deallocation
- Double Pointers (int **)
- Memory Safety
- Integer Overflow

# 1.Dynamic Array Allocation

## Objective
使用 malloc() 動態配置 Sensor Array，並安全地初始化與釋放記憶體。

## Requirements

1.實作 int *createSensorArray(size_t count)。
2.根據 count 動態配置整數陣列。
3.將每個元素初始化為 i * 10。
4.處理 count == 0。
5.檢查記憶體配置大小是否溢位。
6.避免初始化時發生 Signed Integer Overflow。
7.檢查 malloc() 是否成功。
8.使用 free() 釋放記憶體。

## 2.Dynamic Sensor Buffer Expansion

## Objective
使用 realloc() 擴充 Sensor Buffer，保留原始資料，並初始化新增的記憶體空間。

## Requirements

1.實作 expandSensorBuffer()。
2.使用 Double Pointer 修改呼叫者的 Pointer。
3.檢查輸入參數是否合法。
4.使用 realloc() 擴充 Buffer。
5.保留原始 Sensor Data。
6.將新增的元素初始化為 0。
7.處理配置失敗，避免 Memory Leak。
8.檢查 Allocation Size Overflow。

# 3. Dynamic Sensor Buffer Cleanup
實作 destroySensorBuffer()，安全釋放動態配置的記憶體。
## Objective
實作安全的 Sensor Buffer Cleanup Function，釋放動態記憶體並將呼叫者的 Pointer 設為 NULL。

## Requirements

1.實作 void destroySensorBuffer(int **buffer)。
2.檢查 buffer 與 *buffer 是否為 NULL。
3.使用 free() 釋放記憶體。
4.將呼叫者的 Pointer 設為 NULL。
5.確保重複呼叫 Cleanup Function 不會造成錯誤。
6.測試 NULL Pointer 的情況。