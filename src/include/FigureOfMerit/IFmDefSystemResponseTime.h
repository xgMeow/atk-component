#pragma once
#include "../IAtkObj.h"
#include "IFmDefCompute.h" 
#include <string>

///
/// 品质因子定义：系统响应时间
///
class IATKOBJECT_API IFmDefSystemResponseTime :public IFmDefCompute
{
public:
    IFmDefSystemResponseTime(const IFmDefSystemResponseTime&) = delete;
    IFmDefSystemResponseTime& operator=(const IFmDefSystemResponseTime&) = delete;

	IFmDefSystemResponseTime(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefSystemResponseTime();

	//********************************************************************
	/// 获得 支持的计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-11
	/// @return 支持的计算类型
	//********************************************************************
	std::vector<std::string> GetComputeSupportedTypes() override;

	//********************************************************************
	/// 获得 是否支持计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-11
	/// @param[in]	eFmCompute  计算类型
	/// @return	bool 是否支持计算类型	
	//********************************************************************
	bool IsComputeTypeSupported(EFmCompute eFmCompute) override;

	//********************************************************************
	/// 设置 指令对象路径
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	strCommandStationPath  指令对象路径
	//********************************************************************
	void SetCommandStationPath(std::string strCommandStationPath);

	//********************************************************************
	/// 获得  指令对象路径
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 指令对象路径
	//********************************************************************
	std::string GetCommandStationPath();

	//********************************************************************
	/// 设置 接收对象路径
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	strReceiveStationPath  接收对象路径
	//********************************************************************
	void SetReceiveStationPath(std::string strReceiveStationPath);

	//********************************************************************
	/// 获得  接收对象路径
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 接收对象路径
	//********************************************************************
	std::string GetReceiveStationPath();

	//********************************************************************
	/// 设置 指令准备时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	dCommandPrepTime  指令准备时间
	//********************************************************************
	void SetCommandPrepTime(double dCommandPrepTime);

	//********************************************************************
	/// 获得  指令准备时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 指令准备时间
	//********************************************************************
	double GetCommandPrepTime();

	//********************************************************************
	/// 设置 指令传输时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	dCommandTime  指令传输时间
	//********************************************************************
	void SetCommandTime(double dCommandTime);

	//********************************************************************
	/// 获得  指令传输时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 指令传输时间
	//********************************************************************
	double GetCommandTime();

	//********************************************************************
	/// 设置 数据准备时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	dPreCollectionTime  数据准备时间
	//********************************************************************
	void SetPreCollectionTime(double dPreCollectionTime);

	//********************************************************************
	/// 获得  数据准备时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 数据准备时间
	//********************************************************************
	double GetPreCollectionTime();

	//********************************************************************
	/// 设置 数据收集时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	dCollectionTime  数据收集时间
	//********************************************************************
	void SetCollectionTime(double dCollectionTime);

	//********************************************************************
	/// 获得  数据收集时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 数据收集时间
	//********************************************************************
	double GetCollectionTime();

	//********************************************************************
	/// 设置 数据处理时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	dPostCollectionTime  数据处理时间
	//********************************************************************
	void SetPostCollectionTime(double dPostCollectionTime);

	//********************************************************************
	/// 获得  数据处理时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 数据处理时间
	//********************************************************************
	double GetPostCollectionTime();

	//********************************************************************
	/// 设置 下传时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	dDownlinkTime  下传时间
	//********************************************************************
	void SetDownlinkTime(double dDownlinkTime);

	//********************************************************************
	/// 获得  下传时间
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 下传时间
	//********************************************************************
	double GetDownlinkTime();

	//********************************************************************
	/// 设置 是否允许交叉传输
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	bAllowForwardCrosslink  是否允许交叉传输
	//********************************************************************
	void SetAllowForwardCrosslink(bool bAllowForwardCrosslink);

	//********************************************************************
	/// 获得  是否允许交叉传输
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 是否允许交叉传输
	//********************************************************************
	bool GetAllowForwardCrosslink();

	//********************************************************************
	/// 设置 步长
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	dTimeStep  步长
	//********************************************************************
	void SetTimeStep(double dTimeStep);

	//********************************************************************
	/// 获得  步长
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 步长
	//********************************************************************
	double GetTimeStep();
};
