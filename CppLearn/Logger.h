#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// ��־��
/// </summary>
class Logger
{
public:
	/// <summary>
	/// ��¼������־
	/// </summary>
	/// <param name="content">��־����</param>
	static void WriteDebug(std::string content);

	/// <summary>
	/// ��¼��Ϣ��־
	/// </summary>
	/// <param name="content">��־����</param>
	static void WriteInfo(std::string content);

	/// <summary>
	/// ��¼������־
	/// </summary>
	/// <param name="content">��־����</param>
	static void WriteWarn(std::string content);

	/// <summary>
	/// ��¼�쳣��־
	/// </summary>
	/// <param name="content">��־����</param>
	static void WriteException(std::string content);

	/// <summary>
	/// ��¼������־
	/// </summary>
	/// <param name="content">��־����</param>
	static void WriteError(std::string content);

};
