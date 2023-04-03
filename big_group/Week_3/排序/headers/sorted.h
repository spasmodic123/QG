#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void creat_200000_data();

int jungle_data_quantity();//判断选择数据的量级
void save_data(char* filename, int* arr,int lenght);//将数据保存到文件中

void insert_sort(int *a,int lenght,char *filename);//插入排序,传入数组,数组的长度,以及最终保存新的,排序后的文件的文件名
void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex);//归并排序合并的过程
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex);//归并排序拆分的过程
void Quick_Sort(int* arr, int begin, int end);//快速排序
void count_sort(int *arr,int lenght,char*filename);
void radio_sort(int* data, int lenght, char* filename);
int maxbit(int data[], int n);
void function_name(int num);
void count_sort_lots(int* arr, int lenght, char* filename);
void radio_sort_lots(int* data, int lenght, char* filename);

int PUSH(int A, int B);
int POP(int* pl, int* pr);
void quicksort_interation(int* a, int l, int r);

void BubbleSort_super1(int* arr, int size);
void BubbleSort_super2(int* arr, int size);
void BubbleSort_super3(int arr[], int size);