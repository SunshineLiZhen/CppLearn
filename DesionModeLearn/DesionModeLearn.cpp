// DesionModeLearn.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Point
{
public:
    int x;
    int y;
};

class Shape
{
public:
    virtual void Draw() = 0;
    virtual ~Shape();
};

class Line:public Shape
{
private:
    Point m_start;
    Point m_end;
public:
    Line(const Point& start, const Point& end)
    {
        m_start = start;
        m_end = end;
    }

    virtual void Draw()
    {
        // draw line
        cout << "this is Line!" << endl;
    }
};

class Cirle
{
private:
    Point m_center;
    int m_r;
public:
    virtual void Draw()
    {
        // draw line
        cout << "this is Cirle!" << endl;
    }
};

class Rectangle
{
private:
    int m_width;
    int m_height;
public:
    virtual void Draw()
    {
        // draw line
        cout << "this is Rectangle!" << endl;
    }
};

class Form
{
private:
    vector<unique_ptr<Shape>> m_shapes;
public:
    void Draw()
    {
        for(auto it = m_shapes.begin();it != m_shapes.end();++it)
        {
            (*it)->Draw();
        }
    }
};

class NonCopyable
{
public:
    // 禁止copy构造函数
    NonCopyable(const NonCopyable& n) = delete;

    // 禁止赋值构造函数
    NonCopyable& operator = (const NonCopyable& n) = delete;

    NonCopyable() = default;

    int f;
};

/* 子类如果继承了NonCopyable：
*如果子类不显式书写复制构造函数，那么不能调用子类的复制构造函数，编译报错。
* 如果子类显式书写复制构造函数，那么能够调用子类的复制构造函数，但是基类的复制构造函数不会被调用(删除了),基类中的变量不会被复制。
*/
class Sword :public NonCopyable
{
public :
    Sword() = default;

    Sword(const Sword& s)
    {
        std::cout << "sword!\n";

    }
};
int main()
{

    Sword s1;
    s1.f = 10;
    Sword s2(s1);
    std::cout << "Hello World!\n";
}

