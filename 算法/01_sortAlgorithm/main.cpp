/******************************************************************************
*
*                             十大排序算法 V1.0
*
* ===========================================================================
*
* 文 件 名：algorithm.h
* 模块名称：十大排序算法
* 功能说明：测试函数入口
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

#define _CRT_SECURE_NO_WARNINGS
#include "sortAlgorithm.h"
#include <map>
#include <string>
#include <chrono>	// 统计运行时间需要

using namespace chrono;

#define RUN_SORT(FUNC)	\
{	\
	auto tStart = system_clock::now();	\
	FUNC;	\
	auto tEnd = system_clock::now();	\
	auto tCost = duration_cast<nanoseconds>(tEnd - tStart);	\
	cout << "耗时: " << tCost.count() << " ns(纳秒).\n" << endl;	\
}

void InitMap(map<int, string>& mp)
{
	mp.insert(make_pair(ALGORITHM_TYPE::BUBLE_SORT, "冒泡排序"));
	mp.insert(make_pair(ALGORITHM_TYPE::SELECT_SORT, "选择排序"));
	mp.insert(make_pair(ALGORITHM_TYPE::INSERT_SORT, "插入排序"));
	mp.insert(make_pair(ALGORITHM_TYPE::QUICK_SORT, "快速排序"));
	mp.insert(make_pair(ALGORITHM_TYPE::HEAP_SORT, "堆排序"));
	mp.insert(make_pair(ALGORITHM_TYPE::COUNT_SORT, "计数排序"));
	mp.insert(make_pair(ALGORITHM_TYPE::HILL_SORT, "希尔排序"));
	mp.insert(make_pair(ALGORITHM_TYPE::CARDINALITY_SORT, "基数排序"));
	mp.insert(make_pair(ALGORITHM_TYPE::BUCKET_SORT, "桶排序"));
	mp.insert(make_pair(ALGORITHM_TYPE::MERGE_SORT, "归并排序"));
}


void test(int algorithmType, map<int, string>& mapAlgorithmType, int seqLen = 10)
{
	cout << "->->->->->->->->->->->->->->->->->->->->->->->->\n";
	// 1、有效性校验
	string sortName = mapAlgorithmType[algorithmType];
	if (strlen(sortName.c_str()) < 1)
	{
		cout << "\n[" << algorithmType << "] 未定义的排序类型！\n";
		return;
	}

	// 2、生成随机序列, 默认10个
	vector<int> vec;
	GenerateDataSeq(vec, seqLen);

	cout << "[" << sortName << "] 前随机序列:" << endl;
	PrintDataSeq(vec);	
	// for_each(vec.cbegin(), vec.cend(), printFunc);	// for_each输出，需引入algorithm,printFunc函数指针

	// 3、排序
	switch (algorithmType)
	{
	case ALGORITHM_TYPE::BUBLE_SORT:
		RUN_SORT(BubbleSort(vec))
			break;
	case ALGORITHM_TYPE::SELECT_SORT:
		RUN_SORT(SelectSort(vec))
			break;
	case ALGORITHM_TYPE::INSERT_SORT:
		RUN_SORT(InsertSort(vec))
			break;
	case ALGORITHM_TYPE::QUICK_SORT:
		RUN_SORT(QuickSort(vec, 0, vec.size() - 1))
			break;
	case ALGORITHM_TYPE::HEAP_SORT:
		RUN_SORT(HeapSort(vec))
			break;
	case ALGORITHM_TYPE::COUNT_SORT:
		RUN_SORT(CountSort(vec))
			break;
	case ALGORITHM_TYPE::HILL_SORT:
		RUN_SORT(HillSort(vec))
			break;
	case ALGORITHM_TYPE::CARDINALITY_SORT:
		RUN_SORT(CardinalitySort(vec))
			break;
	case ALGORITHM_TYPE::BUCKET_SORT:
		RUN_SORT(BucketSort(vec))
			break;
	case ALGORITHM_TYPE::MERGE_SORT:
		RUN_SORT(MergeSort(vec))
			break;
	default:
		break;
	}

	cout << "[" << sortName << "] 后序列:" << endl;
	PrintDataSeq(vec);
}

int main()
{
	map<int, string> mapAlgorithmType;
	InitMap(mapAlgorithmType);

	test(ALGORITHM_TYPE::BUBLE_SORT, mapAlgorithmType, 10);
	test(ALGORITHM_TYPE::SELECT_SORT, mapAlgorithmType, 10);
	test(ALGORITHM_TYPE::INSERT_SORT, mapAlgorithmType, 10);
	test(ALGORITHM_TYPE::QUICK_SORT, mapAlgorithmType, 10);
	test(ALGORITHM_TYPE::COUNT_SORT, mapAlgorithmType, 10);
	test(ALGORITHM_TYPE::HILL_SORT, mapAlgorithmType, 10);	
	test(ALGORITHM_TYPE::CARDINALITY_SORT, mapAlgorithmType);
	test(ALGORITHM_TYPE::MERGE_SORT, mapAlgorithmType);

	getchar();
	return 0;
}