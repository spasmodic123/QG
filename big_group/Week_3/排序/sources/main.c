#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sorted.h"

int main()
{
	creat_200000_data();//创建一个二十万数据量的随机数

	while(1){
		system("cls");
		printf("\n\n\n---------------------------\n");
		printf(">>> 1.插入排序.               \n");
		printf(">>> 2.归并排序.               \n");
		printf(">>> 3.快速排序 (递归).           \n");
		printf(">>> 4.计数排序.              \n");
		printf(">>> 5基数排序.              \n\n\n\n");
		printf(">>> 6.快速排序(非递归).              \n");
		printf(">>> 7.冒泡排序优化(1)             \n");
		printf(">>> 8.冒泡排序优化(2).    \n");
		printf(">>> 9.冒泡排序优化(3).       \n");
		printf(">>> 15.退出程序               \n");
		printf("---------------------------\n");


		int num; char c;
		printf("请输入你的选择:");//判断非法输入
		int ret = scanf("%d", &num);//scanf函数的返回值为成功读取的元素的个数,如果是%d,你却输入了一个字母,那么成功读取数目为0
		if (ret < 1) {
			while ((c = getchar()) != EOF && c != '\n');//利用getchar函数,不断读取,清除缓存区域
			printf("输入非法!!!请重新输入   \033[31m应该输入一个整数 \033[0m\n");
			system("pause");
		}
		switch (num)//选择使用哪一个排序方法
		{
			//插入排序///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		case 1:{
			function_name(num);//显示功能名字

			switch (jungle_data_quantity())//选择使用数据的量级
			{
			case 1: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[10000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 10000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);

				int lenght = sizeof(num1) / sizeof(num1[0]);//细节,sizeof函数只能在定义时使用,不能够将数组传进去函数,在调用sizeof判断

				clock_t start = clock();
				insert_sort(num1, lenght, "insert_10000");
				clock_t run_time = clock() - start;
				printf("运算时间为 %dms\n\n", run_time);
				save_data("insert_10000", num1, lenght);//将数据保存到新的文件中
			}break;

			case 2: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num2[50000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 50000; i++) {
					fscanf(fp1, "%d", &num2[i]);
				}
				fclose(fp1);

				int lenght = 50000;

				clock_t start = clock();
				insert_sort(num2, lenght, "insert_10000");
				clock_t run_time = clock() - start;
				printf("运算时间为 %dms\n\n", run_time);
				save_data("insert_10000", num2, lenght);//将数据保存到新的文件中
			}break;

			case 3: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num3[200000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 200000; i++) {
					fscanf(fp1, "%d", &num3[i]);
				}
				fclose(fp1);

				int lenght = 200000;
				printf("\n\t运行中......");
				clock_t start = clock();
				insert_sort(num3, lenght, "insert_10000");
				clock_t run_time = clock() - start;
				printf("运算时间为 %dms\n\n", run_time);
				save_data("insert_10000", num3, lenght);//将数据保存到新的文件中
			}break;
			case 4:
				break;
			case 5: {
				printf("运算中......\n");
				clock_t start = clock();
				int lenght = 100;
				for (int i = 0; i < 100000; i++) {
					FILE* fp1;//先从文件读入数据
					fp1 = fopen("200000_data", "r");
					static int num3[100] = { 0 };//随机的数据读入num数组
					for (int i = 0; i < 100; i++) {
						fscanf(fp1, "%d", &num3[i]);
					}
					fclose(fp1);

					insert_sort(num3, lenght, "insert_10000");
				}
				clock_t run_time = clock() - start;
				printf("运算时间为 %dms\n\n", run_time); system("pause");
			}break;
			default:
				break;
			}
			break;
		}
		///////////归并排序/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		case 2:{
			function_name(num);

			switch (jungle_data_quantity())//选取不同的数量级
			{
			case 1: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[10000] = { 0 };//随机的数据读入num数组
				static int num11[10000];
				for (int i = 0; i < 10000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);

				int lenght = sizeof(num1) / sizeof(num1[0]);

				clock_t start = clock();
				MergeSort(num1, num11, 0, lenght - 1);//排序
				clock_t run_time = clock() - start;

				printf("运算时间为 %dms\n\n", run_time);
				save_data("merge_10000", num1, lenght);//保存新数据
			}break;

			case 2:
			{
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[50000] = { 0 };//随机的数据读入num数组
				static int num11[50000];
				for (int i = 0; i < 50000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);

				int lenght = sizeof(num1) / sizeof(num1[0]);

				clock_t start = clock();
				MergeSort(num1, num11, 0, lenght - 1);//排序
				clock_t run_time = clock() - start;

				printf("运算时间为 %dms\n\n", run_time);
				save_data("merge_50000", num1, lenght);
			}break;

			case 3: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[200000] = { 0 };//随机的数据读入num数组
				static int num11[200000];
				for (int i = 0; i < 200000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);

				int lenght = sizeof(num1) / sizeof(num1[0]);

				clock_t start = clock();
				MergeSort(num1, num11, 0, lenght - 1);//排序
				clock_t run_time = clock() - start;

				printf("运算时间为 %dms\n\n", run_time);
				save_data("merge_200000", num1, lenght);
			}break;
			case 4:
				break;
			case 5: {
				printf("运算中......\n");
				clock_t start = clock();
				for (int k = 0; k < 100000; k++) {//循环100k次
					FILE* fp1;//先从文件读入数据
					fp1 = fopen("200000_data", "r");
					static int num1[100] = { 0 };//随机的数据读入num数组
					static int num11[100];
					for (int i = 0; i < 100; i++) {
						fscanf(fp1, "%d", &num1[i]);
					}
					fclose(fp1);

					int lenght = sizeof(num1) / sizeof(num1[0]);

					MergeSort(num1, num11, 0, lenght - 1);//排序
				}
				clock_t run_time = clock() - start;
				printf("运算时间为 %dms\n\n", run_time); system("pause");
			}break;
			default:
				break;
			}
			break;
		}
		///快速排序////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		case 3: {
			function_name(num);

			switch (jungle_data_quantity())//选择使用数据的量级
			{
			case 1: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[10000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 10000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);

				int lenght = sizeof(num1) / sizeof(num1[0]);//细节,sizeof函数只能在定义时使用,不能够将数组传进去函数,在调用sizeof判断

				clock_t start = clock();
				Quick_Sort(num1, 0, lenght - 1);
				clock_t run_time = clock() - start;

				printf("运算时间为 %dms\n\n", run_time);
				save_data("quick_10000", num1, lenght);
			}break;

			case 2: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num2[50000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 50000; i++) {
					fscanf(fp1, "%d", &num2[i]);
				}
				fclose(fp1);

				int lenght = 50000;

				clock_t start = clock();
				Quick_Sort(num2, 0, lenght - 1);
				clock_t run_time = clock() - start;

				printf("运算时间为 %dms\n\n", run_time);
				save_data("quick_50000", num2, lenght);
			}break;

			case 3: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num3[200000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 200000; i++) {
					fscanf(fp1, "%d", &num3[i]);
				}
				fclose(fp1);

				int lenght = 200000;

				clock_t start = clock();
				Quick_Sort(num3, 0, lenght - 1);
				clock_t run_time = clock() - start;

				printf("运算时间为 %dms\n\n", run_time);
				save_data("quick_200000", num3, lenght);
			}break;
			case 4:
				break;
			case 5: {
				printf("运算中......\n");
				clock_t start = clock();
				for (int k = 0; k < 100000; k++) {//循环100k次
					FILE* fp1;//先从文件读入数据
					fp1 = fopen("200000_data", "r");
					static int num1[100] = { 0 };//随机的数据读入num数组
					for (int i = 0; i < 100; i++) {
						fscanf(fp1, "%d", &num1[i]);
					}
					fclose(fp1);

					int lenght = sizeof(num1) / sizeof(num1[0]);

					Quick_Sort(num1,0,lenght - 1);//排序
				}
				clock_t run_time = clock() - start;
				printf("运算时间为 %dms\n\n", run_time); system("pause");
			}
			default:
				break;
			}
			break;
		}

        ///计数排序///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 4: {
			function_name(num);

			switch (jungle_data_quantity())
			{
			case 1: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[10000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 10000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);
				int lenght = 10000;
				count_sort(num1, 10000, "count_10000");
			}break;
			case 2: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[50000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 50000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);
				int lenght = 50000;
				count_sort(num1, 50000, "count_50000");
			}break;
			case 3: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[200000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 200000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);
				int lenght = 200000;
				count_sort(num1, 200000, "count_200000");
			}break;
			case 4:
				break;
			case 5: {
				printf("运算中......\n");
				clock_t start = clock();
				for (int k = 0; k < 100000; k++) {//循环100k次
					FILE* fp1;//先从文件读入数据
					fp1 = fopen("200000_data", "r");
					static int num1[100] = { 0 };//随机的数据读入num数组
					for (int i = 0; i < 100; i++) {
						fscanf(fp1, "%d", &num1[i]);
					}
					fclose(fp1);

					int lenght = sizeof(num1) / sizeof(num1[0]);

					count_sort_lots(num1, 100, "count_200000");//排序
				}
				clock_t run_time = clock() - start;
				printf("运算时间为 %dms\n\n", run_time); system("pause");
			}break;
			default:
				break;
			}
		}break;

	///基数排序/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 5:{
			function_name(num);

			switch (jungle_data_quantity())
			{
			case 1: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[10000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 10000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);
				int lenght = 10000;
				radio_sort(num1, 10000, "radio_10000");
			}break;
			case 2: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[50000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 50000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);
				int lenght = 50000;
				radio_sort(num1, 50000, "radio_50000");
			}break;
			case 3: {
				FILE* fp1;//先从文件读入数据
				fp1 = fopen("200000_data", "r");
				static int num1[200000] = { 0 };//随机的数据读入num数组
				for (int i = 0; i < 200000; i++) {
					fscanf(fp1, "%d", &num1[i]);
				}
				fclose(fp1);
				int lenght = 200000;
				radio_sort(num1, 200000, "radio_200000");
			}break;
			case 4:
				break;
			case 5: {
				printf("运算中......\n");
				clock_t start = clock();
				for (int k = 0; k < 100000; k++) {//循环100k次
					FILE* fp1;//先从文件读入数据
					fp1 = fopen("200000_data", "r");
					static int num1[100] = { 0 };//随机的数据读入num数组
					for (int i = 0; i < 100; i++) {
						fscanf(fp1, "%d", &num1[i]);
					}
					fclose(fp1);

					int lenght = sizeof(num1) / sizeof(num1[0]);
					radio_sort_lots(num1, 100, "radio_200000");//排序
				}
				clock_t run_time = clock() - start;
				printf("运算时间为 %dms\n\n", run_time); system("pause");
			}
			default:
				break;
			}
		}break;

		case 6: {
			int num[10] = { 8,9,6,7,5,3,4,1,2,0 };
			quicksort_interation(num, 0, 9);
			for (int i = 0; i < 10; i++) {
				printf("%d ", num[i]);
			}printf("\n");
			system("pause");
		}break;
		case 7: {
			int num[10] = { 8,9,6,7,5,3,4,1,2,0 };
			BubbleSort_super1(num, 10);
			for (int i = 0; i < 10; i++) {
				printf("%d ", num[i]);
			}printf("\n");
			system("pause");
		}break;
		case 8: {
			int num[10] = { 8,9,6,7,5,3,4,1,2,0 };
			BubbleSort_super2(num, 10);
			for (int i = 0; i < 10; i++) {
				printf("%d ", num[i]);
			}printf("\n");
			system("pause");
		}break;
		case 9: {
			int num[10] = { 8,9,6,7,5,3,4,1,2,0 };
			BubbleSort_super3(num, 10);
			for (int i = 0; i < 10; i++) {
				printf("%d ", num[i]);
			}printf("\n");
			system("pause");
		}break;
		case 15:
			return;
		default:
			break;
		}
	}



}