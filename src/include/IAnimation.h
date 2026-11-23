#pragma once
#include "IAtkObj.h"
class CObjManage;
struct CObjData;

///
/// 仿真状态
///
class IATKOBJECT_API IAnimation
{
public:
    IAnimation(const IAnimation&) = delete;
    IAnimation& operator=(const IAnimation&) = delete;

	IAnimation(CObjManage* IAsGObjManage);
	~IAnimation();

	//********************************************************************
	/// 仿真暂停
	/// @author	Dong Min
	/// @date	2023-11-3
	//********************************************************************
	void Pause();

	//********************************************************************
	/// 正向仿真开始
	/// @author	Dong Min
	/// @date	2023-11-3
	//********************************************************************
	void PlayForward();

	//********************************************************************
	/// 仿真停止并重置
	/// @author	Dong Min
	/// @date	2023-11-3
	//********************************************************************
	void Rewind();

	//********************************************************************
	/// 仿真重置
	/// @author	Dong Min
	/// @date	2023-11-3
	//********************************************************************
	void Reset();

private:
	CObjManage*     m_IAsGObjManage;
	//int     m_RunState;   //控制仿真线程是否运行. 0=不运行;1=运行;2=暂停;3=反向回放

	void ComputeEph(CObjData* pObjData);

};
