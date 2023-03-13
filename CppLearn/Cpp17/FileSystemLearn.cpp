#include "FileSystemLearn.h"
#include <iostream>
#include <filesystem>


using namespace std;
using namespace std::filesystem;

void FileSystemLearn::simpleTest()
{
	//检查文件夹存在性
	path str("C:\\Windows");
	if (!exists(str))
	{
		cout << "Path is not exist!  " << str << endl;
	}

	// 文件夹入口
	directory_entry entry(str);		
	if (entry.status().type() == file_type::directory)	//这里用了C++11的强枚举类型
	{
		cout << "该路径是一个目录" << endl;
	}

	//文件入口容器
	directory_iterator list(str);	        
	for (auto& it : list)
	{
		cout << it.path().filename() << endl;	//通过文件入口（it）获取path对象，再得到path对象的文件名，将之输出
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
