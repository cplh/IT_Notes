/******************************************************************************
*
*                             ʮ�������㷨 V1.0
*
* ===========================================================================
*
* �� �� ����algorithm.h
* ģ�����ƣ�ʮ�������㷨
* ����˵�������Ժ������
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

#define _CRT_SECURE_NO_WARNINGS
#include "sortAlgorithm.h"
#include <map>
#include <string>
#include <chrono>	// ͳ������ʱ����Ҫ

using namespace chrono;

#define RUN_SORT(FUNC)	\
{	\
	auto tStart = system_clock::now();	\
	FUNC;	\
	auto tEnd = system_clock::now();	\
	auto tCost = duration_cast<nanoseconds>(tEnd - tStart);	\
	cout << "��ʱ: " << tCost.count() << " ns(����).\n" << endl;	\
}

void InitMap(map<int, string>& mp)
{
	mp.insert(make_pair(ALGORITHM_TYPE::BUBLE_SORT, "ð������"));
	mp.insert(make_pair(ALGORITHM_TYPE::SELECT_SORT, "ѡ������"));
	mp.insert(make_pair(ALGORITHM_TYPE::INSERT_SORT, "��������"));
	mp.insert(make_pair(ALGORITHM_TYPE::QUICK_SORT, "��������"));
	mp.insert(make_pair(ALGORITHM_TYPE::HEAP_SORT, "������"));
	mp.insert(make_pair(ALGORITHM_TYPE::COUNT_SORT, "��������"));
	mp.insert(make_pair(ALGORITHM_TYPE::HILL_SORT, "ϣ������"));
	mp.insert(make_pair(ALGORITHM_TYPE::CARDINALITY_SORT, "��������"));
	mp.insert(make_pair(ALGORITHM_TYPE::BUCKET_SORT, "Ͱ����"));
	mp.insert(make_pair(ALGORITHM_TYPE::MERGE_SORT, "�鲢����"));
}


void test(int algorithmType, map<int, string>& mapAlgorithmType, int seqLen = 10)
{
	cout << "->->->->->->->->->->->->->->->->->->->->->->->->\n";
	// 1����Ч��У��
	string sortName = mapAlgorithmType[algorithmType];
	if (strlen(sortName.c_str()) < 1)
	{
		cout << "\n[" << algorithmType << "] δ������������ͣ�\n";
		return;
	}

	// 2�������������, Ĭ��10��
	vector<int> vec;
	GenerateDataSeq(vec, seqLen);

	cout << "[" << sortName << "] ǰ�������:" << endl;
	PrintDataSeq(vec);	
	// for_each(vec.cbegin(), vec.cend(), printFunc);	// for_each�����������algorithm,printFunc����ָ��

	// 3������
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

	cout << "[" << sortName << "] ������:" << endl;
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