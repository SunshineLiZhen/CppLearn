#include "stdafx.h"
#include "AlgorithmLearn.h"
#include <vector>
#include <ctype.h>

AlgorithmLearn::AlgorithmLearn()
{
}


AlgorithmLearn::~AlgorithmLearn()
{
}

void AlgorithmLearn::getAllDigitsInString(string src)
{
	int ln = src.length();
	if (ln <= 0) return;

	vector<string> res;

	//第一层循环，遍历每一个元素
	for (int i = 0; i < ln; ++i)
	{
		//第二层循环，取出连续的数字
		if (0 != isdigit(src[i]))
		{
			string oneDigit;
			int k = i;
			do
			{
				oneDigit.push_back(src[k]);
				++k;
			} while (0 != isdigit(src[k]));

			res.push_back(oneDigit);
			i = k;//更新i的值，防止重复取用数字，也能提高遍历效率

		}
	}

	for (auto it = res.begin(); it != res.end(); ++it)
	{
		cout << *it << endl;
	}
}

void AlgorithmLearn::getAllDigitsInString2(string src)
{
	// 输出
	vector<int> numbers;

	if (src.length() == 0)
	{
		return;
	}

	//准备环境 
	vector<string> numStrs;
	string tmp;
	int len = src.length();

	// 具体算法
	for (int i = 0; i <= len - 1; ++i)
	{
		//操作
		if (isdigit(src[i]))
		{
			tmp += src[i];
		}
		else
		{
			if (tmp.length() != 0)
			{
				numStrs.push_back(tmp);
				tmp.clear();
			 } 
		}
		// 更新
	}

	//特殊处理
	if (!tmp.empty())
	{
		numStrs.push_back(tmp);
		tmp.clear();
	}
		for (auto it = numStrs.begin(); it != numStrs.end(); ++it)
		{
			cout << *it << endl;
		}
	
}

void AlgorithmLearn::atoK()
{
	int tar[13] = { 0 };
	int str[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };

	vector<int> vInt;
	for (int i = 12; i >= 0; --i)
	{
		vInt.push_back(i);
	}

	int n = 1;
	auto it = vInt.begin();
	
	while (true)
	{
		// 循环停止条件
		if (vInt.size() == 0)
		{
			break;
		}

		// 数组遍历到头，返回重新遍历
		if (it == vInt.end())
		{
			it = vInt.begin();
		}

		// （1）把最下面的一张抽出来摆到桌子上, 
		tar[(*it)] = n;
		it = vInt.erase(it);

		// （2）第二张拿出来放在最上面,
		if (it == vInt.end())
		{
			// 数组遍历到头，返回重新遍历
			it = vInt.begin();
		}
		else
		{
			it++;
		}
		
		n++;
	}

	printArray(tar,13);
}

void atokIpml(vector<int> v,int i)
{
	if (v.size() == 0)
	{
		return;
	}


}
int getFeibo(int n)
{
	if (0 == n)
	{
		return 0;
	}
	if (1 == n || 2 == n)
	{
		return 1;
	}

	return getFeibo(n - 1) + getFeibo(n - 2);
}
long long int AlgorithmLearn::FeiBo(int n)
{
	int n1 = n - 2;
	long long int first = 1;
	long long int second = 1;
	for (int i = 1; i <= n1; ++i)
	{
		int temp = first + second;
		first = second;
		second = temp;
	}
	return second;
	//return getFeibo(n);
}

float AlgorithmLearn::Fun1(int n)
{
	if (n <= 0)
	{
		return 0.0f;
	}
	else if (1 == n)
	{
		return 1.0f;
	}
	else
	{
		return Fun1(n - 1) + 1 / Fun1(n - 1);
	}
}

float AlgorithmLearn::Fun2(int n)
{
	if (n <= 0)
	{
		return 0.0f;
	}
	else if (1 == n)
	{
		return 1.0f;
	}
	else
	{
		int realN = n - 1;
		int i = 1;
		float result = 1;
		for (int i = 1; i <= realN; ++i)
		{
			result = result + 1 / result;
		}

		return result;
	}
}

void AlgorithmLearn::bubbleSortExample()
{
	int arr[5] = { 3,4,2,1,5 };
	int tar[5] = { 0 };
	cout << "源字符串：";
	printArray(arr, 5);
	bubbleSort(arr, 5, tar);
	cout << "排序后字符串：";
	printArray(tar, 5);
}

void AlgorithmLearn::insertSortExample()
{
	int arr[5] = { 3,4,2,1,5 };
	int tar[5] = { 0 };
	cout << "源字符串：";
	printArray(arr, 5);
	insertSort(arr, 5, tar);
	cout << "排序后字符串：";
	printArray(tar, 5);
}

void AlgorithmLearn::selectSortExample()
{
	int arr[5] = { 3,4,2,1,5 };
	int tar[5] = { 0 };
	cout << "源字符串：";
	printArray(arr, 5);
	selectSort(arr, 5, tar);
	cout << "排序后字符串：";
	printArray(tar, 5);
}

void AlgorithmLearn::strOpExample()
{
	char str1[] = "ABC";
	char target[10] = { 0 };
	bool res = false;

	//字符串复制
	res = diyStrCpy(str1, target, 10);
	cout << "字符串赋值演示：" << endl;
	cout << "目标空间足够:" << " result|src|target  "
		<< res << '|' << str1 << '|' << target << endl;
	memset(target, 0, 10);
	res = diyStrCpy(str1, target, 3);
	cout << "目标空间不足:" << " result|src|target  "
		<< res << '|' << str1 << '|' << target << endl;

	//字符串连接
	char target2[10] = { "AAA" };
	res = diyStrCat1(target2,10,str1);
	cout << "字符串连接演示：" << endl;
	cout << "目标空间足够:" << " result|src|target  "
		<< res << '|' << target2 << '|' << str1 << endl;
}

void AlgorithmLearn::str2HighExample()
{
	bool res = false;
	char str[] = "aBcDefg@#";
	char target[20] = { 0 };
	res = diyStr2Low(str, target, 20);
	cout << "字符串大小写转换演示：" << endl;
	cout << "大写转小写:" << " result|src|target  "
		<< res << '|' << str << '|' << target << endl;
}

void AlgorithmLearn::diyStr2LowerExExample()
{
	bool res = false;
	char str[] = "aBcDefg";
	char target[20] = { 0 };
	res = diyStr2LowerEx(str, target);
	cout << "字符串大小写转换演示：" << endl;
	cout << "大写转小写:" << " result|src|target  "
		<< res << '|' << str << '|' << target << endl;
}

void AlgorithmLearn::diyStrCmpExample()
{
	char str1[] = "abcde";
	char str2[] = "abcde";
	char str3[] = "abcdef";
	char str4[] = "abcgh";
	bool res = false;
	res = diyStrCmp(str1, str2);
	cout << "字符串比较演示：" << endl;
	cout << "两者相等:" << " result|str1|str2  "
		<< res << '|' << str1 << '|' << str2 << endl;

	res = diyStrCmp(str1, str3);
	cout << "两者不相等:" << " result|str1|str2  "
		<< res << '|' << str1 << '|' << str3 << endl;

	res = diyStrCmp(str1, str4);
	cout << "两者不相等:" << " result|str1|str2  "
		<< res << '|' << str1 << '|' << str4 << endl;
}

void AlgorithmLearn::binsearchAlg1Example()
{
	int a[8] = { 1,3,6,8,11,15,30,32 };
	int tar = 32;
	int pos = 0;
	cout << "折半查找算法演示：" << endl;
	cout << "带查找的有序集合：" ;
	printArray(a, 8);
	cout << "目标值：" << tar << endl;
	pos = binsearchAlg2(a, tar, 8);
	cout << "查找到的位置：" << pos << endl;
}

bool AlgorithmLearn::bubbleSort(int * pArr, int arrLen, int * pTar)
{
	//准备工作
	if (NULL == pArr || NULL == pTar)
	{
		return false;
	}
	
	for (int i = 0; i < arrLen; ++i)
	{
		pTar[i] = pArr[i];
	}
	pTar[arrLen + 1] = 0;
	
	//排序算法
	//一次冒一个泡，最后一个顺序自然排好，不用排。冒泡次数是arrLen -1;
	for (int i = 0; i < arrLen - 1; ++i)
	{
		int temp = 0;
		//一次循环向上运动一个位置，第i个数不用最上位置arrLen-1-i 
		// k的范围【1，arrLen-1-i]
		for (int k = 1; k <= arrLen - 1 - i; ++k)
		{
			//比较大小，交换数值
			if (pTar[k - 1] < pTar[k])
			{
				temp = pTar[k];
				pTar[k] = pTar[k - 1];
				pTar[k - 1] = temp;
			}
		}
	}
	return true;
}


//【4 6】3 2 1  [选出集合]备选集合
bool AlgorithmLearn::insertSort(int * pArr, int arrLen, int * pTar)
{
	//准备工作
	if (NULL == pArr || NULL == pTar)
	{
		return false;
	}

	for (int i = 0; i < arrLen; ++i)
	{
		pTar[i] = pArr[i];
	}
	pTar[arrLen + 1] = 0;

	//排序算法
	//第一层循环变量是两个区域的交界（前有序区域，后无序区域），使用前区域的最后一个元素数组坐标。范围是【0，arrLen-1）.因为后区域起始坐标是i+1
	for (int i = 0; i < arrLen - 1; ++i)
	{
		//只有无序集合首元素比有序集合最后一个元素小的时候才需要交换
		if (pTar[i + 1] < pTar[i])
		{
			int x = pTar[i + 1];//这个变量称为哨兵

			//将哨兵和有序集合各元素逐个比较交换，顺序是从后向前（比从前往后copy的次数少），数字大的排在后面。
			int k = i;
			//比较大小，调整顺序
			while (x < pTar[k])
			{
				pTar[k + 1] = pTar[k];
				--k;
				//左边界处理
				if(k < 0)
				{
					break;
				}
			}

			pTar[k + 1] = x;

		}
	}

	for (int i = 1; i <= arrLen - 1; ++i)
	{
		if (pTar[i] < pTar[i - 1])
		{
			int x = pTar[i];
			int k = i;
			while (pTar[k] < pTar[k - 1])
			{
				pTar[k] = pTar[k - 1];
				--k;
				if (k < 0)
				{
					break;
				}
			}
			pTar[k + 1] = x;
		}
	}
	return false;
}

bool AlgorithmLearn::selectSort(int * pArr, int arrLen, int * pTar)
{
	//准备工作
	if (NULL == pArr || NULL == pTar)
	{
		return false;
	}

	for (int i = 0; i < arrLen; ++i)
	{
		pTar[i] = pArr[i];
	}
	pTar[arrLen + 1] = 0;

	//排序算法
	for (int i = 0;i < arrLen - 1;++i)
	{
		//准备工作
		int minNumPos = i;//标兵位置，标准兵
		//查找最小值的数组下标
		for (int k = i; k <= arrLen - 1; ++k)
		{
			//更新标兵，你比我还厉害，还标准，那标兵让给你
			if (pTar[k] < pTar[minNumPos])
			{
				minNumPos = k;
			}
		}

		//找到标兵的位置，和待选区间首元素交换
		//如果标兵的位置是和i位置相同则不必交换
		if (i != minNumPos)
		{
			int temp = pTar[minNumPos];
			pTar[minNumPos] = pTar[i];
			pTar[i] = temp;
		}
		printArray(pTar, 5);
	}
	return false;
}

int AlgorithmLearn::binsearchAlg1(int * digit, int tar, int len)
{
	if (NULL == digit)
	{
		return -1;
	}

	int newN = len;
	int* pNewH = digit;
	int halfValue = len/2;
	int pos = -1;//如果没找到默认返回-1
	while (newN != 0)
	{
		cout << *(pNewH + halfValue) << endl;
		if (*(pNewH + halfValue) == tar)
		{
			pos = (pNewH - digit) + halfValue;
			break;
		}
		else if (tar > *(pNewH + halfValue))
		{
			newN = newN - halfValue - 1;
			pNewH = pNewH + halfValue + 1;
			halfValue = newN / 2;
		}
		else if (tar < *(pNewH + halfValue))
		{
			newN = halfValue;
			halfValue = newN / 2;
		}
	}

	return pos;
}

int AlgorithmLearn::binsearchAlg2(int * digit, int tar, int len)
{
	if (NULL == digit)
	{
		return -1;
	}
	int a[8] = { 1,3,6,8,11,15,30,32 };
	//准备工作
	int high = len - 1;
	int low = 0;
	int mid = 0;
	int pos = -1;//如果没找到默认返回-1
	while ((high - low) != 0)
	{
		//循环操作
		
		mid = low + (high - low) / 2;// == low + high/2 - low/2 == (low + high)/2
		cout << "a["<< mid << "]=" << digit[mid] << endl;
		if (digit[mid] == tar)
		{
			pos = mid;
			break;
		}
		// 更新循环变量
		else if (tar > digit[mid])
		{	
			low = mid + 1;
		}
		else if (tar < digit[mid])
		{
			high = mid - 1;
		}
	}

	//边界情况处理
	if (high == low && digit[high] == tar)
	{
		pos = high;
	}

	return pos;
}

/*
 * 字符串拷贝
 */
bool AlgorithmLearn::diyStrCpy(char * source, char * target,int len)
{
	if (NULL == source)
	{
		return false;
	}

	if (NULL == target)
	{
		return false;
	}

	int i = 0;
	//计算source长度
	while (source[i] != '\0')
	{
		++i;
	}
	
	if (i < len)
	{
		i = 0;//初始化i
		while ('\0' != source[i])
		{
			target[i] = source[i];
			++i;
		}

		target[i] = '\0';//注意添加结束符
	}
	else
	{
		return false;
	}

	return true;
}

bool AlgorithmLearn::diyStrCat1(char * str1, int len,char * str2)
{
	if (NULL == str1)
	{
		return false;
	}

	if (NULL == str2)
	{
		return false;
	}

	int i = 0;
	int k = 0;
	//判断空间是否够用
	while (str2[k] != '\0')
	{
		++k;
	}
	
	while (str1[i] != '\0')
	{
		++i;//i最后的位置也是结束符的位置
	}
	if (k + i - 1 > len)
	{
		return false;
	}
	
	//追加数据
	k = 0;
	while (str2[k] != '\0')
	{
		str1[i++] = str2[k++];
	}

	//追加结束符
	str1[i] = '\0';

	return false;
}

bool AlgorithmLearn::diyStrCat2(char * str1, char * str2, char * tar, int len)
{
	if (NULL == str1 || NULL == str2 || NULL == tar)
	{
		return false;
	}

	//计算两个字符串的长度
	int i = 0;
	int k = 0;
	while (str1[i] != '\0')
	{
		++i;
	}
	while (str2[k] != '\0')
	{
		++i;
		++k;
	}
	
	if (i >= len)
	{
		return false;
	}

	//tar空间足够开始复制
	i = 0;
	k = 0;
	while (str1[k] != '\0')
	{
		tar[i] = str1[k];
		++i;
	}
	k = 0;
	while (str2[k] != '\0')
	{
		tar[i] = str2[k];
		++i;
		++k;
	}

	//写入结束符
	tar[i] = '\0';

	return false;
}

bool AlgorithmLearn::diyStr2Low(char * str, char * target, int len)
{
	if (str == NULL || target == NULL)
	{
		return false;
	}

	int i = 0;
	while (str[i] != '\0')
	{
		++i;
	}

	if (i >= len) 
	{
		return false;
	}

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			target[i] = str[i] + 32;
		}
		else
		{
			target[i] = str[i];
		}
		++i;
	}
	
	//添加结束符
	target[i] = '\0';

	return true;
}

/*
 * 字符串大小写转换-大写->小写
 * A：65->10000001
 * a: 97->11000001
 * 按位或运算32->0100000
 */
bool AlgorithmLearn::diyStr2LowerEx(char * source, char * target)
{
	if (source == NULL || target == NULL)
	{
		return false;
	}

	int i = 0;
	while (source[i] != '\0')
	{
		target[i] = source[i] | 32;
		++i;
	}
	target[i] = '\0';

	return true;
}

/*
* 字符串大小写转换-小写->大写
* A：65->10000001
* a: 97->11000001
* 按位与运算95->10111111
*/
bool AlgorithmLearn::diyStr2UpperEx(char * source, char * target)
{
	if (source == NULL || target == NULL)
	{
		return false;
	}

	int i = 0;
	while (source[i] != '\0')
	{
		target[i] = source[i] & 95;
		++i;
	}
	target[i] = '\0';

	return true;
}

bool AlgorithmLearn::diyStrCmp(char * str1, char * str2)
{
	if (NULL == str1 || NULL == str2)
	{
		return false;
	}

	int i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
		++i;
	}
	
	//比较到str1最后一个字符都相同
	//如果str2还没有结束也不能说明两者相等
	if (str1[i] != str2[i])
	{
		return false;
	}

	return true;
}

bool AlgorithmLearn::diyStrSeparate(char * source, char separator, char target[][20])
{
	if (NULL == source || NULL == target)
	{
		return false;
	}

	int i = 0;
	int k = 0;
	int n = 0;
	while (source[i] != '\0')
	{
		if (source[i] != separator)
		{
			target[n][k] = source[i];
			k++;
			i++;
		}
		else
		{
			target[n][k] = '\0';
			n++;
			i++;
			k = 0;
		}
	}

	target[n][i] = '\0';
	return true;
}

void AlgorithmLearn::printArray(int * pArr, int arrLen)
{
	for (int i = 0; i < arrLen; ++i)
	{
		cout << pArr[i] << " ";
	}
	cout << endl;
}

/****************************************************************************************************/
/* 排序算法学习
 */
/****************************************************************************************************/
void SortAlgorithmLearn::quickSortExample()
{
	int arr[10] = { 2,4,9,3,1,6,5,8,7,0 };
	int tar[10] = { 0 };
	quickSort(arr, 10, tar);

	for (int i = 0; i < 10; ++i)
	{
		cout << tar[i] << " ";
	}
	cout << endl;
}

bool SortAlgorithmLearn::quickSort(int * pArr, int arrLen, int * pTar)
{
	if (NULL == pArr || NULL == pTar)
	{
		return false;
	}
	
	int i = 0;
	for (i = 0; i < arrLen; ++i)
	{
		pTar[i] = pArr[i];
	}

	quickSortImpl(pTar, arrLen, 0, arrLen - 1);
}

void SortAlgorithmLearn::quickSortImpl(int * pArr, int arrLen, int low, int high)
{
	if (low >= high)
	{
		return;
   }

	int i = low;
	int j = high;
	int key = pArr[low];
	int keyPos = low;

	// 第一步：找到中间值，分为两个区间
	while (i < j)
	{
		// 从后向前找第一个比key小的值
		while (i < j && pArr[j] > key)
		{
			--j;
		}

		// 交换，将比key小的移动到低端
		pArr[keyPos] = pArr[j];
		pArr[j] = key;
		keyPos = j;

		// 从前向后找比key大的值
		while (i < j && pArr[i] < key)
		{
			++i;
		}

		// 交换，将第一个比key大的元素移动到高端
		pArr[keyPos] = pArr[i];
		pArr[i] = key;
		keyPos = i;
	}

	// 第二步：递归排序左边区间
	quickSortImpl(pArr, keyPos - low + 1, low, keyPos-1);

	// 第三步：递归排序右边区间
	quickSortImpl(pArr, high - keyPos + 1, keyPos+1,high);
}
