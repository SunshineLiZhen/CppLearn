#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// 日志类
/// </summary>
class Logger
{
public:
	/// <summary>
	/// 记录调试日志
	/// </summary>
	/// <param name="content">日志内容</param>
	static void WriteDebug(std::string content);

	/// <summary>
	/// 记录信息日志
	/// </summary>
	/// <param name="content">日志内容</param>
	static void WriteInfo(std::string content);

	/// <summary>
	/// 记录警告日志
	/// </summary>
	/// <param name="content">日志内容</param>
	static void WriteWarn(std::string content);

	/// <summary>
	/// 记录异常日志
	/// </summary>
	/// <param name="content">日志内容</param>
	static void WriteException(std::string content);

	/// <summary>
	/// 记录错误日志
	/// </summary>
	/// <param name="content">日志内容</param>
	static void WriteError(std::string content);

};
