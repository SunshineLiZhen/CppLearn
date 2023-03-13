#pragma once
#include <iostream>
#include <map>

using namespace std;

/// <summary>
/// 分割器产品抽象类
/// </summary>
class Font
{
private:
	string m_key;
public:
	Font(string key) :m_key(key) {};
};


class FontFactory
{
private:
	map<string, shared_ptr<Font>> m_fontMap;
public:
	shared_ptr<Font> GetFont(string key)
	{
		auto it = m_fontMap.find(key);

		if (it != m_fontMap.end())
		{
			return it->second;
		}
		else
		{
			auto tmp = make_shared<Font>(key);
			m_fontMap.insert(pair<string,shared_ptr<Font>>(key,tmp));
			return tmp;
		}
	}

};
