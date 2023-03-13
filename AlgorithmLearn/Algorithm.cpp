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

	//��һ��ѭ��������ÿһ��Ԫ��
	for (int i = 0; i < ln; ++i)
	{
		//�ڶ���ѭ����ȡ������������
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
			i = k;//����i��ֵ����ֹ�ظ�ȡ�����֣�Ҳ����߱���Ч��

		}
	}

	for (auto it = res.begin(); it != res.end(); ++it)
	{
		cout << *it << endl;
	}
}

void AlgorithmLearn::getAllDigitsInString2(string src)
{
	// ���
	vector<int> numbers;

	if (src.length() == 0)
	{
		return;
	}

	//׼������ 
	vector<string> numStrs;
	string tmp;
	int len = src.length();

	// �����㷨
	for (int i = 0; i <= len - 1; ++i)
	{
		//����
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
		// ����
	}

	//���⴦��
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
		// ѭ��ֹͣ����
		if (vInt.size() == 0)
		{
			break;
		}

		// ���������ͷ���������±���
		if (it == vInt.end())
		{
			it = vInt.begin();
		}

		// ��1�����������һ�ų�����ڵ�������, 
		tar[(*it)] = n;
		it = vInt.erase(it);

		// ��2���ڶ����ó�������������,
		if (it == vInt.end())
		{
			// ���������ͷ���������±���
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
	cout << "Դ�ַ�����";
	printArray(arr, 5);
	bubbleSort(arr, 5, tar);
	cout << "������ַ�����";
	printArray(tar, 5);
}

void AlgorithmLearn::insertSortExample()
{
	int arr[5] = { 3,4,2,1,5 };
	int tar[5] = { 0 };
	cout << "Դ�ַ�����";
	printArray(arr, 5);
	insertSort(arr, 5, tar);
	cout << "������ַ�����";
	printArray(tar, 5);
}

void AlgorithmLearn::selectSortExample()
{
	int arr[5] = { 3,4,2,1,5 };
	int tar[5] = { 0 };
	cout << "Դ�ַ�����";
	printArray(arr, 5);
	selectSort(arr, 5, tar);
	cout << "������ַ�����";
	printArray(tar, 5);
}

void AlgorithmLearn::strOpExample()
{
	char str1[] = "ABC";
	char target[10] = { 0 };
	bool res = false;

	//�ַ�������
	res = diyStrCpy(str1, target, 10);
	cout << "�ַ�����ֵ��ʾ��" << endl;
	cout << "Ŀ��ռ��㹻:" << " result|src|target  "
		<< res << '|' << str1 << '|' << target << endl;
	memset(target, 0, 10);
	res = diyStrCpy(str1, target, 3);
	cout << "Ŀ��ռ䲻��:" << " result|src|target  "
		<< res << '|' << str1 << '|' << target << endl;

	//�ַ�������
	char target2[10] = { "AAA" };
	res = diyStrCat1(target2,10,str1);
	cout << "�ַ���������ʾ��" << endl;
	cout << "Ŀ��ռ��㹻:" << " result|src|target  "
		<< res << '|' << target2 << '|' << str1 << endl;
}

void AlgorithmLearn::str2HighExample()
{
	bool res = false;
	char str[] = "aBcDefg@#";
	char target[20] = { 0 };
	res = diyStr2Low(str, target, 20);
	cout << "�ַ�����Сдת����ʾ��" << endl;
	cout << "��дתСд:" << " result|src|target  "
		<< res << '|' << str << '|' << target << endl;
}

void AlgorithmLearn::diyStr2LowerExExample()
{
	bool res = false;
	char str[] = "aBcDefg";
	char target[20] = { 0 };
	res = diyStr2LowerEx(str, target);
	cout << "�ַ�����Сдת����ʾ��" << endl;
	cout << "��дתСд:" << " result|src|target  "
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
	cout << "�ַ����Ƚ���ʾ��" << endl;
	cout << "�������:" << " result|str1|str2  "
		<< res << '|' << str1 << '|' << str2 << endl;

	res = diyStrCmp(str1, str3);
	cout << "���߲����:" << " result|str1|str2  "
		<< res << '|' << str1 << '|' << str3 << endl;

	res = diyStrCmp(str1, str4);
	cout << "���߲����:" << " result|str1|str2  "
		<< res << '|' << str1 << '|' << str4 << endl;
}

void AlgorithmLearn::binsearchAlg1Example()
{
	int a[8] = { 1,3,6,8,11,15,30,32 };
	int tar = 32;
	int pos = 0;
	cout << "�۰�����㷨��ʾ��" << endl;
	cout << "�����ҵ����򼯺ϣ�" ;
	printArray(a, 8);
	cout << "Ŀ��ֵ��" << tar << endl;
	pos = binsearchAlg2(a, tar, 8);
	cout << "���ҵ���λ�ã�" << pos << endl;
}

bool AlgorithmLearn::bubbleSort(int * pArr, int arrLen, int * pTar)
{
	//׼������
	if (NULL == pArr || NULL == pTar)
	{
		return false;
	}
	
	for (int i = 0; i < arrLen; ++i)
	{
		pTar[i] = pArr[i];
	}
	pTar[arrLen + 1] = 0;
	
	//�����㷨
	//һ��ðһ���ݣ����һ��˳����Ȼ�źã������š�ð�ݴ�����arrLen -1;
	for (int i = 0; i < arrLen - 1; ++i)
	{
		int temp = 0;
		//һ��ѭ�������˶�һ��λ�ã���i������������λ��arrLen-1-i 
		// k�ķ�Χ��1��arrLen-1-i]
		for (int k = 1; k <= arrLen - 1 - i; ++k)
		{
			//�Ƚϴ�С��������ֵ
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


//��4 6��3 2 1  [ѡ������]��ѡ����
bool AlgorithmLearn::insertSort(int * pArr, int arrLen, int * pTar)
{
	//׼������
	if (NULL == pArr || NULL == pTar)
	{
		return false;
	}

	for (int i = 0; i < arrLen; ++i)
	{
		pTar[i] = pArr[i];
	}
	pTar[arrLen + 1] = 0;

	//�����㷨
	//��һ��ѭ����������������Ľ��磨ǰ�������򣬺��������򣩣�ʹ��ǰ��������һ��Ԫ���������ꡣ��Χ�ǡ�0��arrLen-1��.��Ϊ��������ʼ������i+1
	for (int i = 0; i < arrLen - 1; ++i)
	{
		//ֻ�����򼯺���Ԫ�ر����򼯺����һ��Ԫ��С��ʱ�����Ҫ����
		if (pTar[i + 1] < pTar[i])
		{
			int x = pTar[i + 1];//���������Ϊ�ڱ�

			//���ڱ������򼯺ϸ�Ԫ������ȽϽ�����˳���ǴӺ���ǰ���ȴ�ǰ����copy�Ĵ����٣������ִ�����ں��档
			int k = i;
			//�Ƚϴ�С������˳��
			while (x < pTar[k])
			{
				pTar[k + 1] = pTar[k];
				--k;
				//��߽紦��
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
	//׼������
	if (NULL == pArr || NULL == pTar)
	{
		return false;
	}

	for (int i = 0; i < arrLen; ++i)
	{
		pTar[i] = pArr[i];
	}
	pTar[arrLen + 1] = 0;

	//�����㷨
	for (int i = 0;i < arrLen - 1;++i)
	{
		//׼������
		int minNumPos = i;//���λ�ã���׼��
		//������Сֵ�������±�
		for (int k = i; k <= arrLen - 1; ++k)
		{
			//���±��������һ�����������׼���Ǳ���ø���
			if (pTar[k] < pTar[minNumPos])
			{
				minNumPos = k;
			}
		}

		//�ҵ������λ�ã��ʹ�ѡ������Ԫ�ؽ���
		//��������λ���Ǻ�iλ����ͬ�򲻱ؽ���
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
	int pos = -1;//���û�ҵ�Ĭ�Ϸ���-1
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
	//׼������
	int high = len - 1;
	int low = 0;
	int mid = 0;
	int pos = -1;//���û�ҵ�Ĭ�Ϸ���-1
	while ((high - low) != 0)
	{
		//ѭ������
		
		mid = low + (high - low) / 2;// == low + high/2 - low/2 == (low + high)/2
		cout << "a["<< mid << "]=" << digit[mid] << endl;
		if (digit[mid] == tar)
		{
			pos = mid;
			break;
		}
		// ����ѭ������
		else if (tar > digit[mid])
		{	
			low = mid + 1;
		}
		else if (tar < digit[mid])
		{
			high = mid - 1;
		}
	}

	//�߽��������
	if (high == low && digit[high] == tar)
	{
		pos = high;
	}

	return pos;
}

/*
 * �ַ�������
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
	//����source����
	while (source[i] != '\0')
	{
		++i;
	}
	
	if (i < len)
	{
		i = 0;//��ʼ��i
		while ('\0' != source[i])
		{
			target[i] = source[i];
			++i;
		}

		target[i] = '\0';//ע����ӽ�����
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
	//�жϿռ��Ƿ���
	while (str2[k] != '\0')
	{
		++k;
	}
	
	while (str1[i] != '\0')
	{
		++i;//i����λ��Ҳ�ǽ�������λ��
	}
	if (k + i - 1 > len)
	{
		return false;
	}
	
	//׷������
	k = 0;
	while (str2[k] != '\0')
	{
		str1[i++] = str2[k++];
	}

	//׷�ӽ�����
	str1[i] = '\0';

	return false;
}

bool AlgorithmLearn::diyStrCat2(char * str1, char * str2, char * tar, int len)
{
	if (NULL == str1 || NULL == str2 || NULL == tar)
	{
		return false;
	}

	//���������ַ����ĳ���
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

	//tar�ռ��㹻��ʼ����
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

	//д�������
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
	
	//��ӽ�����
	target[i] = '\0';

	return true;
}

/*
 * �ַ�����Сдת��-��д->Сд
 * A��65->10000001
 * a: 97->11000001
 * ��λ������32->0100000
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
* �ַ�����Сдת��-Сд->��д
* A��65->10000001
* a: 97->11000001
* ��λ������95->10111111
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
	
	//�Ƚϵ�str1���һ���ַ�����ͬ
	//���str2��û�н���Ҳ����˵���������
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
/* �����㷨ѧϰ
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

	// ��һ�����ҵ��м�ֵ����Ϊ��������
	while (i < j)
	{
		// �Ӻ���ǰ�ҵ�һ����keyС��ֵ
		while (i < j && pArr[j] > key)
		{
			--j;
		}

		// ����������keyС���ƶ����Ͷ�
		pArr[keyPos] = pArr[j];
		pArr[j] = key;
		keyPos = j;

		// ��ǰ����ұ�key���ֵ
		while (i < j && pArr[i] < key)
		{
			++i;
		}

		// ����������һ����key���Ԫ���ƶ����߶�
		pArr[keyPos] = pArr[i];
		pArr[i] = key;
		keyPos = i;
	}

	// �ڶ������ݹ������������
	quickSortImpl(pArr, keyPos - low + 1, low, keyPos-1);

	// ���������ݹ������ұ�����
	quickSortImpl(pArr, high - keyPos + 1, keyPos+1,high);
}
