#pragma once

/// <summary>
/// 电风扇状态
/// </summary>
enum class FanState
{
	Standby,   //待机状态
	LowGear,   //低档
	MiddleGear,//中档
	HighGear,  //高档
	Error,     //错误状态
	ShutDown   //关机状态
};
