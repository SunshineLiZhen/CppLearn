#pragma once
#include <iostream>


using namespace std;

///////////////////////////////////////////////////////// ��Ʒ //////////////////////////////////////////////////
/// <summary>
/// ��Ʒ����
/// </summary>
class IDBConnection
{
public:
	virtual void ConnectionString(string str) = 0;
};

class IDBCommand
{
public:
	virtual void SetConnection(shared_ptr<IDBConnection> conn) = 0;
	virtual void CommandText(string str) = 0;

	virtual void ExcecuteReadeer(string str) = 0;

};

class IDataReader
{
public:
	virtual void SetCommand(shared_ptr<IDBCommand>  comm) = 0;

	virtual void Read() = 0;
};

/// <summary>
/// ������Ʒ
/// </summary>
class SqlDBConnection :public IDBConnection
{

};

class SqlDBCommand :public IDBCommand
{

};

class SqlDataReader :public IDataReader
{

};

class OracleDBConnection :public IDBConnection
{

};

class OracleDBCommand :public IDBCommand
{

};

class OracleDataReader :public IDataReader
{

};