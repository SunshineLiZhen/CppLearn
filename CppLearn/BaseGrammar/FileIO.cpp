#include "stdafx.h"
#include "FileIO.h"
#include <iostream>
#include <fstream>

using namespace std;

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}

void FileIO::outStreamExaple()
{
	ofstream myFile("G:\\workspace\\1.txt",ios::out);//����˵�����ļ���ַ���򿪷�ʽ
	myFile << "hello china!" << endl;
	myFile.close();
}

void FileIO::inputStreamExample()
{
	char c = 0;
	ifstream myFile("G:\\workspace\\1.txt",ios::in);
	myFile >> c;
	myFile.close();
	cout << c << endl;
}
