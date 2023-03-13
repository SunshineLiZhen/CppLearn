// DataScructLearn.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/// <summary>
/// 从0....n-1中随机等概率的输出m个不重复的数
/// </summary>
/// <param name="n"></param>
/// <param name="m"></param>
void knuth(int n, int m)
{
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++) 
    {
        int rd = rand();
        //cout << "rd:" << rd << endl;
        if ( rd% (n -i) < m)
        {


            cout << i << endl;
            m--;
        }
    }
}

void RandTest()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << rand() << endl;
    }
}

int main()
{
    int i;
 
    int&& j = 3;
    int& k = j;
    vector<int> vi(1000);
    int& ri = vi[0];
    cout << "k" << k;
    std::cout << "Hello World!\n";
    return 0;
}

