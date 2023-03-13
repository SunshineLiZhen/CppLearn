#pragma once
#include <iostream>
#include "ProductDataBase.hpp"

using namespace std;

///////////////////////////////////////////////////////// �򵥹��� //////////////////////////////////////////////////

/// <summary>
/// ��������
/// </summary>

class IDBConnectionFactoryAF
{
public:
	virtual shared_ptr<IDBConnection> CreateSplitter() = 0;

};

class IDBCommandFactoryAF
{
public:
	virtual shared_ptr<IDBCommand> CreateSplitter() = 0;

};

class IDBDataReaderFactoryAF
{
public:
	virtual shared_ptr<IDataReader> CreateSplitter() = 0;
};


/// �����๤��
/// sql
class SqlDBConnectionFactory :public IDBConnectionFactoryAF
{
public:
	virtual shared_ptr<IDBConnection> CreateSplitter() override
	{
		return make_shared<SqlDBConnection>();
	}
};

class SqlDBCommandFactory :public IDBCommandFactoryAF
{
public:
	virtual shared_ptr<IDBCommand> CreateSplitter() override
	{
		return make_shared<SqlDBCommand>();
	}
};

class SqlDBDataReaderFactory :public IDBDataReaderFactoryAF
{
public:
	virtual shared_ptr<IDataReader> CreateSplitter() override
	{
		return make_shared<SqlDataReader>();
	}
};

/// oracle
class OracleDBConnectionFactory :public IDBConnectionFactoryAF
{
public:
	virtual shared_ptr<IDBConnection> CreateSplitter() override
	{
		return make_shared<SqlDBConnection>();
	}
};

class OracleDBCommandFactory :public IDBCommandFactoryAF
{
public:
	virtual shared_ptr<IDBCommand> CreateSplitter() override
	{
		return make_shared<SqlDBCommand>();
	}
};

class OracleDBDataReaderFactory :public IDBDataReaderFactoryAF
{
public:
	virtual shared_ptr<IDataReader> CreateSplitter() override
	{
		return make_shared<SqlDataReader>();
	}
};



/// ʹ�ð��� ///
/// ��������
/// ���ݿ��ж��֣�����sql��oracle.�����紫����connection,command,datareader���������Ķ�������һ�����ݿ⣬�����ڶ�����ݿ�
/// �����ͳ������ˡ�
class ApplyCaseAFM
{
private:
	shared_ptr<IDBConnectionFactoryAF> m_dbConnectionFactroy;
	shared_ptr<IDBCommandFactoryAF> m_dbCommandFactory;
	shared_ptr<IDBDataReaderFactoryAF> m_dbDataReaderFactory;
public:
	ApplyCaseAFM(shared_ptr<IDBConnectionFactoryAF> connectionFactory, shared_ptr<IDBCommandFactoryAF> commandFactory, shared_ptr<IDBDataReaderFactoryAF> datareaderFactory)
	{
		m_dbConnectionFactroy = connectionFactory;
		m_dbCommandFactory = commandFactory;
		m_dbDataReaderFactory = datareaderFactory;
	}

	void Go()
	{
		shared_ptr<IDBConnection> dbConnection = m_dbConnectionFactroy->CreateSplitter();
		dbConnection->ConnectionString("...");

		shared_ptr<IDBCommand> dbCommand = m_dbCommandFactory->CreateSplitter();
		dbCommand->SetConnection(dbConnection);// ������
		dbCommand->CommandText("");

		shared_ptr<IDataReader> dbDataReader = m_dbDataReaderFactory->CreateSplitter();
		dbDataReader->SetCommand(dbCommand);// ������
		dbDataReader->Read();
	}

};