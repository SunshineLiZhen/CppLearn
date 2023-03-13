#pragma once
#include <iostream>
#include "ProductDataBase.hpp"

using namespace std;

///////////////////////////////////////////////////////// ���� //////////////////////////////////////////////////
/// <summary>
/// ���󹤳�ģʽ
/// </summary>
class IDbFactory
{
public:
	 virtual shared_ptr<IDBConnection> CreateDBConection() = 0;
	 virtual shared_ptr<IDBCommand> CreateDbCommand() = 0;
	 virtual shared_ptr<IDataReader> CreateDbDataReader() = 0;
};

class SqlDbFactory:public IDbFactory
{
public:
	virtual shared_ptr<IDBConnection> CreateDBConection() override
	{
		return make_shared<SqlDBConnection>();
	}

	virtual shared_ptr<IDBCommand> CreateDbCommand() override
	{
		return make_shared<SqlDBCommand>();
	}

	virtual shared_ptr<IDataReader> CreateDbDataReader() override
	{
		return make_shared<SqlDataReader>();
	}
};

class OracleDbFactory :public IDbFactory
{
public:
	virtual shared_ptr<IDBConnection> CreateDBConection() override
	{
		return make_shared< OracleDBConnection>();
	}

	virtual shared_ptr<IDBCommand> CreateDbCommand() override
	{
		return make_shared< OracleDBCommand>();
	}

	virtual shared_ptr<IDataReader> CreateDbDataReader() override
	{
		return make_shared< OracleDataReader>();
	}
};


class ApplyCaseAFM2
{
private:
	shared_ptr<IDbFactory> m_dbFactroy;
	
public:
	ApplyCaseAFM2(shared_ptr<IDbFactory> dbFactroy)
	{
		m_dbFactroy = dbFactroy;
	}

	void Go()
	{
		shared_ptr<IDBConnection> dbConnection = m_dbFactroy->CreateDBConection();
		dbConnection->ConnectionString("...");

		shared_ptr<IDBCommand> dbCommand = m_dbFactroy->CreateDbCommand();
		dbCommand->SetConnection(dbConnection);// ������
		dbCommand->CommandText("");

		shared_ptr<IDataReader> dbDataReader = m_dbFactroy->CreateDbDataReader();
		dbDataReader->SetCommand(dbCommand);// ������
		dbDataReader->Read();
	}

};