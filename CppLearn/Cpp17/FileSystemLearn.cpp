#include "FileSystemLearn.h"
#include <iostream>
#include <filesystem>


using namespace std;
using namespace std::filesystem;

void FileSystemLearn::simpleTest()
{
	//����ļ��д�����
	path str("C:\\Windows");
	if (!exists(str))
	{
		cout << "Path is not exist!  " << str << endl;
	}

	// �ļ������
	directory_entry entry(str);		
	if (entry.status().type() == file_type::directory)	//��������C++11��ǿö������
	{
		cout << "��·����һ��Ŀ¼" << endl;
	}

	//�ļ��������
	directory_iterator list(str);	        
	for (auto& it : list)
	{
		cout << it.path().filename() << endl;	//ͨ���ļ���ڣ�it����ȡpath�����ٵõ�path������ļ�������֮���
	}
}

void FileSystemLearn::FileOperate()
{
	path file1("./xxx.jpg");
	bool res = exists(file1);
	if (res)
	{
		remove(file1);
	}
	cout << "res:" << res << endl;

	vector v{ 1,2,3 };

}
