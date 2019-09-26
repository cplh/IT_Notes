/******************************************************************************
*
*                             十大排序算法 V1.0
*
* ===========================================================================
*
* 文 件 名：algorithm.h
* 模块名称：十大排序算法实现
* 功能说明：排序算法函数实现（统一vector实现）
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

#include "sortAlgorithm.h"
#include <time.h>
#include <math.h>

// 随机正负
int Symbol(int flag)
{
	return (flag == 1 ? 1 : -1);
}

// 生成数据序列
void GenerateDataSeq(vector<int>& vec, const int len)
{
	// 注意：随机数种子, time(NULL)的精度只能到秒级
	// 如果启动多个线程且同一秒内完成，有生成同一随机数序列的现象
	// https://blog.csdn.net/yourijing/article/details/52723772

	srand((unsigned int)time(NULL));
	for (size_t i = 0; i < len; i++)
	{
		int num = rand() % 100;
		// int num = Symbol(rand() % 2) * rand() % 100;	// 随机正负
		vec.push_back(num);
	}
}


// 打印数据序列
void PrintDataSeq(const vector<int>& vec)
{
	int cnt = 1;
	for (auto it : vec)
	{
		cout << it << "\t";
		if (cnt++ % 10 == 0)	// 每十个换行输出
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

	// *a = *a ^ *b;    // 位操作法
	// *b = *a ^ *b;
	// *a = *a ^ *b;
	//*a ^= *b ^= *a ^= *b; 和上面等价

	// *a = *a + *b;    // 加减法
	// *b = *a - *b;
	// *a = *a - *b;
}

// ************************************ 冒泡排序
void BubbleSort(vector<int>& vec)
{
	int len = vec.size();
	bool flag = true;	// 标记，避免无意义判断
	for (size_t i = 0; i < len && flag; i++)	// 排序趟数
	{
		flag = false;
		for (size_t j = 0; j < len - i - 1; j++)		// 该趟比较次数
		{
			if (vec[j] > vec[j + 1])
			{
				MySwap(vec, j, j + 1);
				flag = true;
			}
		}
	}
}


// ************************************ 选择排序
// 从待排序序列中找到极值，再安排到已排序序列。
// 和冒泡区别是，冒泡是连续两两比较交换，选择排序是从剩下整个序列里比较交换。
void SelectSort(vector<int>& vec)
{
	int minPos = -1;
	int len = vec.size();
	for (size_t i = 0; i < len - 1; i++)
	{
		minPos = i;
		for (size_t j = i + 1; j < len; j++)	// 待排序区
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


// ************************************ 插入排序
// 从待排序序列中取第一个数，再从后往前遍历已排序序列，找到合适位置插入
void InsertSort(vector<int>& vec)
{
	int len = vec.size();
	// 从下标为1的元素选择合适位置，因为下标为0的元素只有一个，默认有序
	for (size_t i = 1; i < len; i++)
	{
		int insertValue = vec[i];	// 待插入值
		int j = i;
		// 从已排序的右边开始比较，找到比其小的数
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

// ************************************ 快速排序

int partition(vector<int>& vec, int left, int right);
// 快速排序入口
void QuickSort(vector<int>& vec, int left, int right)
{
	if (left < right)
	{
		int partitionIndex = partition(vec, left, right);
		QuickSort(vec, left, partitionIndex - 1);
		QuickSort(vec, partitionIndex + 1, right);
	}
}

// 快排划分子问题
// 所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面
int partition(vector<int>& vec, int left, int right)
{
	int pivot = left;	// 基准值
	int index = left + 1;
	for (size_t i = index; i <= right; i++)	// 比较趟数
	{
		if (vec[i] < vec[pivot])	// 该趟比基准值小则移到基准值前面
		{
			MySwap(vec, i, index);	// index记录移位的次数
			index++;
		}
	}
	MySwap(vec, pivot, index - 1);	// 最后基准值归位
	return index - 1;
}


// ************************************ 计数排序
// 目前仅支持正数序列
void CountSort(vector<int>& vec)
{
	// 先找到最大值
	int max = vec[0];
	for (auto it : vec)		// for (int it : vec)
	{
		if (it >= max)
		{
			max = it;
		}
	}

	// 扫描一遍，记录各元素出现次数,下标为值，存储内容为出现次数
	vector<int> vecCount;
	vecCount.resize(max + 1);	// 注意为何此处只需max + 1即可？
	for (auto it : vec)
	{
		vecCount[it]++;
	}

	// 对出现每个元素，按照出现次数，依次展开到目标数组
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


// ************************************ 希尔排序
void HillSort(vector<int>& vec)
{
	int gap = vec.size() / 3 + 1;

	while (gap > 0)
	{
		// 从gap开始比较
		for (size_t rightPos = gap; rightPos < vec.size(); rightPos++)
		{
			int rightValue = vec[rightPos];
			int leftPos = rightPos - gap;
			while (leftPos >= 0 && vec[leftPos] > rightValue)	// 将前面大的值和后面小的值互换,找到合适位置插入
			{
				vec[leftPos + gap] = vec[leftPos];
				leftPos -= gap;
			}
			vec[leftPos + gap] = rightValue;
		}
		gap = floor(gap / 3);	// 向下取整, 需引入math.h
	}
}


// ************************************ 堆排序
// 构造大顶堆，就是从下往上，从左往右，将每个非叶子结点当做根节点，将其和其子树调整成大顶堆
void heapAdjust(vector<int>& vec, int nodePos, int len)
{
	int largestPos = nodePos;			// 初始是父结点位置, 后面记录值最大结点位置
	int lChildPos = 2 * nodePos + 1;	// 左孩子位置
	int rChildPos = 2 * nodePos + 2;	// 右孩子位置

	// 比较左子树
	if (lChildPos < len && vec[largestPos] < vec[lChildPos])
	{
		largestPos = lChildPos;
	}

	// 比较右子树
	if (rChildPos < len && vec[largestPos] < vec[rChildPos])
	{
		largestPos = rChildPos;
	}

	// 若值最大结点不是之前的根节点, 调整到位了，可以交换
	if (largestPos != nodePos)
	{
		MySwap(vec, nodePos, largestPos);
		heapAdjust(vec, largestPos, len);
	}
}

// 初始构建堆需要比较次数多，所以堆排序不适合序列元素个数少的情况
void buildMaxHeap(vector<int>& vec, int len)
{
	// len个结点二叉树中这些结点都是有孩子的结点	
	for (size_t i = len / 2; i > 0; i--)
	{
		heapAdjust(vec, i, len);
	}
}

// 堆排序入口
// 待排查bug：排完后最后一个元素顺序不对
void HeapSort(vector<int>& vec)
{
	int len = vec.size();
	buildMaxHeap(vec, len);	// 初始构造大顶堆

	for (size_t i = len - 1; i > 0; i--)	// 每次取最后一个元素
	{
		MySwap(vec, 0, i);		// 将栈顶记录和当前未经排序子序列的最后一个记录交换
		heapAdjust(vec, 0, i);	// 剩余元素重新调整堆
	}
}


// ************************************ 归并排序
// 归并排序合并数组
template<typename T>
void Merge(vector<T>& vec, int beginPos, int midPos, int endPos)
{
	int leftLen, rightLen, i, j, k;
	leftLen = midPos - beginPos + 1;
	rightLen = endPos - midPos;
	T* leftArr = new T[leftLen];
	T* rightArr = new T[rightLen];

	// 数组分别保存左右两边数据
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
	// 接下来从左右两数组比较合并
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

	for (; i < leftLen; i++)		// 如果左数组还有剩余，则将剩余元素合并到vec
	{
		vec[k++] = leftArr[i];
	}
	for (; j < rightLen; j++)		// 如果右数组还有剩余，则将剩余元素合并到vec
	{
		vec[k++] = rightArr[j];
	}

	delete[] leftArr;
	delete[] rightArr;
}

// 归并排序核心递归
template<typename T>
void MSort(vector<T>& vec, int beginPos, int endPos)
{
	int midPos;
	if (beginPos < endPos)
	{
		midPos = (beginPos + endPos) / 2;
		MSort(vec, beginPos, midPos);			// 递归拆分左半边数组
		MSort(vec, midPos + 1, endPos);			// 递归拆分右半边数组
		Merge(vec, beginPos, midPos, endPos);	// 合并数组
	}
}

// 归并排序入口
void MergeSort(vector<int>& vec)
{
	int len = vec.size();
	MSort(vec, 0, len - 1);
}

// ************************************ 桶排序
void BucketSort(vector<int>& vec)
{
	int max = vec[0];
	int min = vec[0];
	// 确定元素的最值
	for (auto item : vec)
	{
		max = max > item ? max : item;
		min = min < item ? min : item;
	}

	// 桶数: (max - min) / array.length的结果为数组大小的倍数（最大倍数），以倍数作为桶数
	// 【注意1】当序列大小vec.size()比较小，而元素值很大且分散(max - min比较大)，会造成很多“空桶”, 增加系统开销
	// 比如(0, 13, 19892)——> 很多“空桶”
	// 【注意2】：当待排序序列元素个数很多(vec.size()很大), 但是每个元素却又很小时, 只有一个桶, 这种情况比较耗时
	int bucketNum = (max - min) / vec.size() + 1;

	// 初始化桶, 可以用数组实现, 也可以用vector实现, 这里选取vector实现, 原因下述
	// int** buckets = new int*[bucketNum];	// 数组实现桶，需要二维数组
	vector<vector<int> > vecBucket;	// vector容器实现桶，类似二维数组
	// 桶初始化
	for (size_t i = 0; i < bucketNum; i++)
	{
		vector<int> vecTmp;
		vecBucket.push_back(vecTmp);
	}
	// 用数组实现桶初始化
	// for (size_t i = 0; i < bucketNum; i++)
	// {
	// 	buckets[i] = new int[vec.size()];		// 每个桶最多存放vec.size()个元素
	// }

	// 将待排序元素挨个放入对应桶中
	for (size_t i = 0; i < vec.size(); i++)
	{
		// 和上面【注意】结合看，如果只有1个桶, 要分开处理
		if (bucketNum != 1)
		{
			int bucketIndex = (vec[i] - min) / bucketNum;	// 根据与最小值的差值确定存放在哪个桶, 这样小的数在前面桶, 桶间元素有序, 最后就只需考虑桶内元素排序
			bucketIndex = bucketIndex >= bucketNum ? bucketNum - 1 : bucketIndex;
			vecBucket[bucketIndex].push_back(vec[i]);	// 这是用vector实现桶的好处, 直接“接”在后面自动扩容即可, 数组实现还需代码处理			
		}
		else
		{
			vecBucket[0].push_back(vec[i]);
		}
	}

	vec.clear();
	// 遍历“桶组合”, 给每个桶中元素排序
	// 每个桶元素有序了, 则整个“桶组合”从“编号小”的桶遍历到“编号大”的桶，则为整体有序序列
	for (vector<vector<int> >::iterator iter = vecBucket.begin(); iter != vecBucket.end(); iter++)
	{
		vector<int> vecTmp = *iter;		// *iter也是一个vector, 内部存放了该桶内元素
		if (vecTmp.size() <= 0)
		{
			continue;
		}

		// 对每个桶进行排序, 这里借用选择排序
		// 当n较小时，对稳定性不作要求时宜用选择排序
		SelectSort(vecTmp);
		// InsertSort(vecTmp);	// 有兴趣读者也可以试用插入排序看看耗时
		for (auto it : vecTmp)
		{
			// 每个桶内元素有序后, 重新给vec赋值, 此时vec有序。
			vec.push_back(it);
		}
	}
}

// ************************************ 基数排序
void CardinalitySort(vector<int>& vec)
{
	// 1、确定最大值
	int maxValue = vec[0];
	for (auto it : vec)
	{
		maxValue = maxValue >= it ? maxValue : it;
	}

	// 2、确定最大值位数
	int maxNumLength = 0;
	for (int i = maxValue; i != 0; i /= 10)
	{
		maxNumLength++;
	}

	// 3、借用桶排序思想
	int mod = 10, dev = 1;
	// 根据最大位数, 就有几轮建桶过程, 依次从个位到最高位建桶
	for (size_t i = 0; i < maxNumLength; i++, dev *= 10, mod *= 10)
	{
		vector<vector<int> > vecBucket;		// 该轮的桶
		// 桶初始化, 全为正数只需要十个桶(根据该位“数值”入0 - 9号桶)
		// 若还需考虑负值, 桶个数扩大一倍(20个桶), 前0-9存取负数, 后10-19存取正数
		for (size_t i = 0; i < 20; i++)		
		{
			vector<int> vecTmp;
			vecBucket.push_back(vecTmp);
		}

		// 数据入桶
		for (size_t j = 0; j < vec.size(); j++)
		{
			int bucketIndex = ((vec[j] % mod) / dev) + 10;	// 该位数值即为该入的桶编号, 若考虑负值则桶编号也相应变化
			vecBucket[bucketIndex].push_back(vec[j]);
		}

		vec.clear();
		for (auto itBucket : vecBucket)
		{
			for (auto itNum : itBucket)	// 注意itBucket也是一个vector
			{
				vec.push_back(itNum);
			}
		}
	}
}