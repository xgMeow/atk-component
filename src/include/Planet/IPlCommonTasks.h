#pragma once
#include "../IAtkObj.h"
#include "IPlPosCentralBody.h"
class IPlanet;


///
/// 公共任务
///
class IATKOBJECT_API IPlCommonTasks
{
public:
    IPlCommonTasks(const IPlCommonTasks&) = delete;
    IPlCommonTasks& operator=(const IPlCommonTasks&) = delete;

	IPlCommonTasks(IPlanet* pIPlanet);
	~IPlCommonTasks();

	//********************************************************************
	/// 使用中心体指定地球,并指定所需的中心体
	/// @author	Gan Shu Long
	/// @date	2024-01-25
	/// @return	IPlPosCentralBody* 中心体指针
	//********************************************************************
	IPlPosCentralBody* SetPositionSourceCentralBody(std::string centralBodyName);

private:
	IPlanet* m_pIPlanet;
};

