#include "TimeExpandCount.h"
#include "../Logger.h"

using namespace std;

//定义毫秒级别的时钟类型  
typedef chrono::steady_clock steadyClockType;

TimeExpandCount::TimeExpandCount()
{
}

void TimeExpandCount::StartCount()
{
    m_startTime = chrono::steady_clock::now();
}

int TimeExpandCount::StopCount()
{
    int res;
    try
    {
        steadyClockType::time_point tpEnd = steadyClockType::now();
        res = chrono::duration_cast<chrono::milliseconds>(tpEnd - m_startTime).count();
    }
    catch (exception e)
    {
        Logger::WriteWarn(e.what());
    }
    return res;
}
