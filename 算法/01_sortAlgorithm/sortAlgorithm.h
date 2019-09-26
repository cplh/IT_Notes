/******************************************************************************
*
*                             十大排序算法 V1.0
*
* ===========================================================================
*
* 文 件 名：algorithm.h
* 模块名称：排序算法头文件
* 功能说明：排序算法函数声明
* 作    者：LiuHuan
* 创建日期：2019-08-16
* 版 本 号：1.0
* 修改历史：
*
* 修改日期       姓名            内容
* ---------------------------------------------------------------------------
* 2019-08-16   LiuHuan         初始版本
*
******************************************************************************/

// #pragma once
#ifndef __ALGORITHM_H
#define __ALGORITHM_H

#include <iostream>
#include <vector>
using namespace std;

enum ALGORITHM_TYPE
{
	BUBLE_SORT,			// 冒泡排序
	SELECT_SORT,		// 选择排序
	INSERT_SORT,		// 插入排序
	QUICK_SORT,			// 快速排序
	HEAP_SORT,			// 堆排序
	COUNT_SORT,			// 计数排序
	HILL_SORT,			// 希尔排序
	CARDINALITY_SORT,	// 基数排序
	BUCKET_SORT,		// 桶排序
	MERGE_SORT,			// 归并排序
};

// 生成数据序列
void GenerateDataSeq(vector<int>& vec, const int len);

// 打印数据
void PrintDataSeq(const vector<int>& vec);

// 冒泡排序
void BubbleSort(vector<int>& vec);

// 选择排序
void SelectSort(vector<int>& vec);

// 插入排序
void InsertSort(vector<int>& vec);

// 快速排序
void QuickSort(vector<int>& vec, int left, int right);

// 堆排序
void HeapSort(vector<int>& vec);

// 计数排序
void CountSort(vector<int>& vec);

// 希尔排序
void HillSort(vector<int>& vec);

// 基数排序
void CardinalitySort(vector<int>& vec);

// 桶排序
void BucketSort(vector<int>& vec);

// 归并排序
void MergeSort(vector<int>& vec);

#endif