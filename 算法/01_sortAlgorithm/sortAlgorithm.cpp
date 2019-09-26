/******************************************************************************
*
*                             ʮ�������㷨 V1.0
*
* ===========================================================================
*
* �� �� ����algorithm.h
* ģ�����ƣ�ʮ�������㷨ʵ��
* ����˵���������㷨����ʵ�֣�ͳһvectorʵ�֣�
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

#include "sortAlgorithm.h"
#include <time.h>
#include <math.h>

// �������
int Symbol(int flag)
{
	return (flag == 1 ? 1 : -1);
}

// ������������
void GenerateDataSeq(vector<int>& vec, const int len)
{
	// ע�⣺���������, time(NULL)�ľ���ֻ�ܵ��뼶
	// �����������߳���ͬһ������ɣ�������ͬһ��������е�����
	// https://blog.csdn.net/yourijing/article/details/52723772

	srand((unsigned int)time(NULL));
	for (size_t i = 0; i < len; i++)
	{
		int num = rand() % 100;
		// int num = Symbol(rand() % 2) * rand() % 100;	// �������
		vec.push_back(num);
	}
}


// ��ӡ��������
void PrintDataSeq(const vector<int>& vec)
{
	int cnt = 1;
	for (auto it : vec)
	{
		cout << it << "\t";
		if (cnt++ % 10 == 0)	// ÿʮ���������
		{
			cout << "\n";
		}
	}
	cout << "\n\n";
}


void MySwap(vector<int>& vec, int posA, int posB)
{
	int temp = vec[posA];
	vec[posA] = vec[posB];
	vec[posB] = temp;

	// *a = *a ^ *b;    // λ������
	// *b = *a ^ *b;
	// *a = *a ^ *b;
	//*a ^= *b ^= *a ^= *b; ������ȼ�

	// *a = *a + *b;    // �Ӽ���
	// *b = *a - *b;
	// *a = *a - *b;
}

// ************************************ ð������
void BubbleSort(vector<int>& vec)
{
	int len = vec.size();
	bool flag = true;	// ��ǣ������������ж�
	for (size_t i = 0; i < len && flag; i++)	// ��������
	{
		flag = false;
		for (size_t j = 0; j < len - i - 1; j++)		// ���˱Ƚϴ���
		{
			if (vec[j] > vec[j + 1])
			{
				MySwap(vec, j, j + 1);
				flag = true;
			}
		}
	}
}


// ************************************ ѡ������
// �Ӵ������������ҵ���ֵ���ٰ��ŵ����������С�
// ��ð�������ǣ�ð�������������ȽϽ�����ѡ�������Ǵ�ʣ������������ȽϽ�����
void SelectSort(vector<int>& vec)
{
	int minPos = -1;
	int len = vec.size();
	for (size_t i = 0; i < len - 1; i++)
	{
		minPos = i;
		for (size_t j = i + 1; j < len; j++)	// ��������
		{
			if (vec[minPos] > vec[j])
			{
				minPos = j;
			}
		}

		if (minPos != i)
		{
			MySwap(vec, minPos, i);
		}
	}
}


// ************************************ ��������
// �Ӵ�����������ȡ��һ�������ٴӺ���ǰ�������������У��ҵ�����λ�ò���
void InsertSort(vector<int>& vec)
{
	int len = vec.size();
	// ���±�Ϊ1��Ԫ��ѡ�����λ�ã���Ϊ�±�Ϊ0��Ԫ��ֻ��һ����Ĭ������
	for (size_t i = 1; i < len; i++)
	{
		int insertValue = vec[i];	// ������ֵ
		int j = i;
		// ����������ұ߿�ʼ�Ƚϣ��ҵ�����С����
		while (j > 0 && insertValue < vec[j - 1])
		{
			vec[j] = vec[j - 1];
			j--;
		}

		if (i != j)
		{
			vec[j] = insertValue;
		}
	}
}

// ************************************ ��������

int partition(vector<int>& vec, int left, int right);
// �����������
void QuickSort(vector<int>& vec, int left, int right)
{
	if (left < right)
	{
		int partitionIndex = partition(vec, left, right);
		QuickSort(vec, left, partitionIndex - 1);
		QuickSort(vec, partitionIndex + 1, right);
	}
}

// ���Ż���������
// ����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬����Ԫ�رȻ�׼ֵ��İ��ڻ�׼�ĺ���
int partition(vector<int>& vec, int left, int right)
{
	int pivot = left;	// ��׼ֵ
	int index = left + 1;
	for (size_t i = index; i <= right; i++)	// �Ƚ�����
	{
		if (vec[i] < vec[pivot])	// ���˱Ȼ�׼ֵС���Ƶ���׼ֵǰ��
		{
			MySwap(vec, i, index);	// index��¼��λ�Ĵ���
			index++;
		}
	}
	MySwap(vec, pivot, index - 1);	// ����׼ֵ��λ
	return index - 1;
}


// ************************************ ��������
// Ŀǰ��֧����������
void CountSort(vector<int>& vec)
{
	// ���ҵ����ֵ
	int max = vec[0];
	for (auto it : vec)		// for (int it : vec)
	{
		if (it >= max)
		{
			max = it;
		}
	}

	// ɨ��һ�飬��¼��Ԫ�س��ִ���,�±�Ϊֵ���洢����Ϊ���ִ���
	vector<int> vecCount;
	vecCount.resize(max + 1);	// ע��Ϊ�δ˴�ֻ��max + 1���ɣ�
	for (auto it : vec)
	{
		vecCount[it]++;
	}

	// �Գ���ÿ��Ԫ�أ����ճ��ִ���������չ����Ŀ������
	vec.clear();
	for (size_t i = 0; i < vecCount.size(); i++)
	{
		int occurTimes = vecCount[i];
		while (occurTimes--)
		{
			vec.push_back(i);
		}
	}
}


// ************************************ ϣ������
void HillSort(vector<int>& vec)
{
	int gap = vec.size() / 3 + 1;

	while (gap > 0)
	{
		// ��gap��ʼ�Ƚ�
		for (size_t rightPos = gap; rightPos < vec.size(); rightPos++)
		{
			int rightValue = vec[rightPos];
			int leftPos = rightPos - gap;
			while (leftPos >= 0 && vec[leftPos] > rightValue)	// ��ǰ����ֵ�ͺ���С��ֵ����,�ҵ�����λ�ò���
			{
				vec[leftPos + gap] = vec[leftPos];
				leftPos -= gap;
			}
			vec[leftPos + gap] = rightValue;
		}
		gap = floor(gap / 3);	// ����ȡ��, ������math.h
	}
}


// ************************************ ������
// ����󶥶ѣ����Ǵ������ϣ��������ң���ÿ����Ҷ�ӽ�㵱�����ڵ㣬����������������ɴ󶥶�
void heapAdjust(vector<int>& vec, int nodePos, int len)
{
	int largestPos = nodePos;			// ��ʼ�Ǹ����λ��, �����¼ֵ�����λ��
	int lChildPos = 2 * nodePos + 1;	// ����λ��
	int rChildPos = 2 * nodePos + 2;	// �Һ���λ��

	// �Ƚ�������
	if (lChildPos < len && vec[largestPos] < vec[lChildPos])
	{
		largestPos = lChildPos;
	}

	// �Ƚ�������
	if (rChildPos < len && vec[largestPos] < vec[rChildPos])
	{
		largestPos = rChildPos;
	}

	// ��ֵ����㲻��֮ǰ�ĸ��ڵ�, ������λ�ˣ����Խ���
	if (largestPos != nodePos)
	{
		MySwap(vec, nodePos, largestPos);
		heapAdjust(vec, largestPos, len);
	}
}

// ��ʼ��������Ҫ�Ƚϴ����࣬���Զ������ʺ�����Ԫ�ظ����ٵ����
void buildMaxHeap(vector<int>& vec, int len)
{
	// len��������������Щ��㶼���к��ӵĽ��	
	for (size_t i = len / 2; i > 0; i--)
	{
		heapAdjust(vec, i, len);
	}
}

// ���������
// ���Ų�bug����������һ��Ԫ��˳�򲻶�
void HeapSort(vector<int>& vec)
{
	int len = vec.size();
	buildMaxHeap(vec, len);	// ��ʼ����󶥶�

	for (size_t i = len - 1; i > 0; i--)	// ÿ��ȡ���һ��Ԫ��
	{
		MySwap(vec, 0, i);		// ��ջ����¼�͵�ǰδ�����������е����һ����¼����
		heapAdjust(vec, 0, i);	// ʣ��Ԫ�����µ�����
	}
}


// ************************************ �鲢����
// �鲢����ϲ�����
template<typename T>
void Merge(vector<T>& vec, int beginPos, int midPos, int endPos)
{
	int leftLen, rightLen, i, j, k;
	leftLen = midPos - beginPos + 1;
	rightLen = endPos - midPos;
	T* leftArr = new T[leftLen];
	T* rightArr = new T[rightLen];

	// ����ֱ𱣴�������������
	for (i = 0; i < leftLen; i++)
	{
		leftArr[i] = vec[beginPos + i];
	}

	for (j = 0; j < rightLen; j++)
	{
		rightArr[j] = vec[midPos + 1 + j];
	}

	i = j = 0;
	k = beginPos;
	// ������������������ȽϺϲ�
	while (i < leftLen && j < rightLen)
	{
		if (leftArr[i] <= rightArr[j])
		{
			vec[k++] = leftArr[i++];
		}
		else
		{
			vec[k++] = rightArr[j++];
		}
	}

	for (; i < leftLen; i++)		// ��������黹��ʣ�࣬��ʣ��Ԫ�غϲ���vec
	{
		vec[k++] = leftArr[i];
	}
	for (; j < rightLen; j++)		// ��������黹��ʣ�࣬��ʣ��Ԫ�غϲ���vec
	{
		vec[k++] = rightArr[j];
	}

	delete[] leftArr;
	delete[] rightArr;
}

// �鲢������ĵݹ�
template<typename T>
void MSort(vector<T>& vec, int beginPos, int endPos)
{
	int midPos;
	if (beginPos < endPos)
	{
		midPos = (beginPos + endPos) / 2;
		MSort(vec, beginPos, midPos);			// �ݹ�����������
		MSort(vec, midPos + 1, endPos);			// �ݹ����Ұ������
		Merge(vec, beginPos, midPos, endPos);	// �ϲ�����
	}
}

// �鲢�������
void MergeSort(vector<int>& vec)
{
	int len = vec.size();
	MSort(vec, 0, len - 1);
}

// ************************************ Ͱ����
void BucketSort(vector<int>& vec)
{
	int max = vec[0];
	int min = vec[0];
	// ȷ��Ԫ�ص���ֵ
	for (auto item : vec)
	{
		max = max > item ? max : item;
		min = min < item ? min : item;
	}

	// Ͱ��: (max - min) / array.length�Ľ��Ϊ�����С�ı���������������Ա�����ΪͰ��
	// ��ע��1�������д�Сvec.size()�Ƚ�С����Ԫ��ֵ�ܴ��ҷ�ɢ(max - min�Ƚϴ�)������ɺܶࡰ��Ͱ��, ����ϵͳ����
	// ����(0, 13, 19892)����> �ܶࡰ��Ͱ��
	// ��ע��2����������������Ԫ�ظ����ܶ�(vec.size()�ܴ�), ����ÿ��Ԫ��ȴ�ֺ�Сʱ, ֻ��һ��Ͱ, ��������ȽϺ�ʱ
	int bucketNum = (max - min) / vec.size() + 1;

	// ��ʼ��Ͱ, ����������ʵ��, Ҳ������vectorʵ��, ����ѡȡvectorʵ��, ԭ������
	// int** buckets = new int*[bucketNum];	// ����ʵ��Ͱ����Ҫ��ά����
	vector<vector<int> > vecBucket;	// vector����ʵ��Ͱ�����ƶ�ά����
	// Ͱ��ʼ��
	for (size_t i = 0; i < bucketNum; i++)
	{
		vector<int> vecTmp;
		vecBucket.push_back(vecTmp);
	}
	// ������ʵ��Ͱ��ʼ��
	// for (size_t i = 0; i < bucketNum; i++)
	// {
	// 	buckets[i] = new int[vec.size()];		// ÿ��Ͱ�����vec.size()��Ԫ��
	// }

	// ��������Ԫ�ذ��������ӦͰ��
	for (size_t i = 0; i < vec.size(); i++)
	{
		// �����桾ע�⡿��Ͽ������ֻ��1��Ͱ, Ҫ�ֿ�����
		if (bucketNum != 1)
		{
			int bucketIndex = (vec[i] - min) / bucketNum;	// ��������Сֵ�Ĳ�ֵȷ��������ĸ�Ͱ, ����С������ǰ��Ͱ, Ͱ��Ԫ������, ����ֻ�迼��Ͱ��Ԫ������
			bucketIndex = bucketIndex >= bucketNum ? bucketNum - 1 : bucketIndex;
			vecBucket[bucketIndex].push_back(vec[i]);	// ������vectorʵ��Ͱ�ĺô�, ֱ�ӡ��ӡ��ں����Զ����ݼ���, ����ʵ�ֻ�����봦��			
		}
		else
		{
			vecBucket[0].push_back(vec[i]);
		}
	}

	vec.clear();
	// ������Ͱ��ϡ�, ��ÿ��Ͱ��Ԫ������
	// ÿ��ͰԪ��������, ��������Ͱ��ϡ��ӡ����С����Ͱ����������Ŵ󡱵�Ͱ����Ϊ������������
	for (vector<vector<int> >::iterator iter = vecBucket.begin(); iter != vecBucket.end(); iter++)
	{
		vector<int> vecTmp = *iter;		// *iterҲ��һ��vector, �ڲ�����˸�Ͱ��Ԫ��
		if (vecTmp.size() <= 0)
		{
			continue;
		}

		// ��ÿ��Ͱ��������, �������ѡ������
		// ��n��Сʱ�����ȶ��Բ���Ҫ��ʱ����ѡ������
		SelectSort(vecTmp);
		// InsertSort(vecTmp);	// ����Ȥ����Ҳ�������ò������򿴿���ʱ
		for (auto it : vecTmp)
		{
			// ÿ��Ͱ��Ԫ�������, ���¸�vec��ֵ, ��ʱvec����
			vec.push_back(it);
		}
	}
}

// ************************************ ��������
void CardinalitySort(vector<int>& vec)
{
	// 1��ȷ�����ֵ
	int maxValue = vec[0];
	for (auto it : vec)
	{
		maxValue = maxValue >= it ? maxValue : it;
	}

	// 2��ȷ�����ֵλ��
	int maxNumLength = 0;
	for (int i = maxValue; i != 0; i /= 10)
	{
		maxNumLength++;
	}

	// 3������Ͱ����˼��
	int mod = 10, dev = 1;
	// �������λ��, ���м��ֽ�Ͱ����, ���δӸ�λ�����λ��Ͱ
	for (size_t i = 0; i < maxNumLength; i++, dev *= 10, mod *= 10)
	{
		vector<vector<int> > vecBucket;		// ���ֵ�Ͱ
		// Ͱ��ʼ��, ȫΪ����ֻ��Ҫʮ��Ͱ(���ݸ�λ����ֵ����0 - 9��Ͱ)
		// �����迼�Ǹ�ֵ, Ͱ��������һ��(20��Ͱ), ǰ0-9��ȡ����, ��10-19��ȡ����
		for (size_t i = 0; i < 20; i++)		
		{
			vector<int> vecTmp;
			vecBucket.push_back(vecTmp);
		}

		// ������Ͱ
		for (size_t j = 0; j < vec.size(); j++)
		{
			int bucketIndex = ((vec[j] % mod) / dev) + 10;	// ��λ��ֵ��Ϊ�����Ͱ���, �����Ǹ�ֵ��Ͱ���Ҳ��Ӧ�仯
			vecBucket[bucketIndex].push_back(vec[j]);
		}

		vec.clear();
		for (auto itBucket : vecBucket)
		{
			for (auto itNum : itBucket)	// ע��itBucketҲ��һ��vector
			{
				vec.push_back(itNum);
			}
		}
	}
}