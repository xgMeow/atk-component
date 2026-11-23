#pragma once
#include "../IAtkObject.h"

class CObjManage;
struct CObjData;
class IAdvCATMain;
class IAdvCATAdvance;

///
/// 高级接近分析
///
class IATKOBJECT_API IAdvCAT : public IAtkObject
{
public:
    IAdvCAT(const IAdvCAT&) = delete;
    IAdvCAT& operator=(const IAdvCAT&) = delete;

	IAdvCAT(CObjData* pObjData, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~IAdvCAT();

	//********************************************************************
	/// 主配置指针
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @return	
	//********************************************************************
	IAdvCATMain* GetMain();

	//********************************************************************
	/// 高级配置指针
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @return	
	//********************************************************************
		IAdvCATAdvance* GetAdvance();

private:
	IAdvCATMain*              m_AdvCATMain;   //高级接近分析主配置指针
	IAdvCATAdvance*           m_AdvCATAdv;    //高级接近分析高级配置指针

};

