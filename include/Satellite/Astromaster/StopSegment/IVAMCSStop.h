#pragma once
#include "../IVAMCSSegment.h"
class CObjManage;
class CSatellite;
class CMCSStop;

///
/// 停止段
///
class IATKOBJECT_API IVAMCSStop : public IVAMCSSegment
{
public:
    IVAMCSStop(const IVAMCSStop&) = delete;
    IVAMCSStop& operator=(const IVAMCSStop&) = delete;

	IVAMCSStop(CSatellite* pSate, CMCSStop* pcStop, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSStop();

	//********************************************************************
	/// 设置该段是否使任务控制序列停止
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bEnabled  该段是否使任务控制序列停止
	/// @Return	
	//********************************************************************
	void SetEnabled(bool bEnabled);
	//********************************************************************
	/// 获得该段是否使任务控制序列停止
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	该段是否使任务控制序列停止
	//********************************************************************
	bool GetEnabled();

private:
	CMCSStop*     m_pcStop;
};
