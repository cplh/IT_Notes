/******************************************************************************
*
*                             ʮ�������㷨 V1.0
*
* ===========================================================================
*
* �� �� ����algorithm.h
* ģ�����ƣ������㷨ͷ�ļ�
* ����˵���������㷨��������
* ��    �ߣ�LiuHuan
* �������ڣ�2019-08-16
* �� �� �ţ�1.0
* �޸���ʷ��
*
* �޸�����       ����            ����
* ---------------------------------------------------------------------------
* 2019-08-16   LiuHuan         ��ʼ�汾
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
	BUBLE_SORT,			// ð������
	SELECT_SORT,		// ѡ������
	INSERT_SORT,		// ��������
	QUICK_SORT,			// ��������
	HEAP_SORT,			// ������
	COUNT_SORT,			// ��������
	HILL_SORT,			// ϣ������
	CARDINALITY_SORT,	// ��������
	BUCKET_SORT,		// Ͱ����
	MERGE_SORT,			// �鲢����
};

// ������������
void GenerateDataSeq(vector<int>& vec, const int len);

// ��ӡ����
void PrintDataSeq(const vector<int>& vec);

// ð������
void BubbleSort(vector<int>& vec);

// ѡ������
void SelectSort(vector<int>& vec);

// ��������
void InsertSort(vector<int>& vec);

// ��������
void QuickSort(vector<int>& vec, int left, int right);

// ������
void HeapSort(vector<int>& vec);

// ��������
void CountSort(vector<int>& vec);

// ϣ������
void HillSort(vector<int>& vec);

// ��������
void CardinalitySort(vector<int>& vec);

// Ͱ����
void BucketSort(vector<int>& vec);

// �鲢����
void MergeSort(vector<int>& vec);

#endif