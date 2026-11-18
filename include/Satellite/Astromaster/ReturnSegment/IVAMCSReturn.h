#pragma once
#include "../../../ICEnum.h"
#include "../IVAMCSSegment.h"
class CObjManage;
class CSatellite;
class CMCSReturn;

///
/// 返回段
///
class IATKOBJECT_API IVAMCSReturn : public IVAMCSSegment
{
public:
    IVAMCSReturn(const IVAMCSReturn&) = delete;
    IVAMCSReturn& operator=(const IVAMCSReturn&) = delete;

	IVAMCSReturn(CSatellite* pSate, CMCSReturn* pcReturn, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSReturn();

	//********************************************************************
	/// 设置该段是否返回控制变量到他的父级段
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eReturnControl 
	/// @Return	
	//********************************************************************
	void SetReturnControlToParentSequence(EVAReturnControl eReturnControl);
	//********************************************************************
	/// 获得该段是否返回控制变量到他的父级段
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	该段是否返回控制变量到他的父级段
	//********************************************************************
	EVAReturnControl GetReturnControlToParentSequence();

private:
	CMCSReturn*          m_pcReturn;

};
