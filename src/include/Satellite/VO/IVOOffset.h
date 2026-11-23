#pragma once
#include "../../IAtkObj.h"
struct CGfxModel;
class IVOOffsetLabel;
class IVOOffsetTrans;
class IVOOffsetEuler;

///
/// 三维模型
///
class IATKOBJECT_API IVOOffset
{
public:
    IVOOffset(const IVOOffset&) = delete;
    IVOOffset& operator=(const IVOOffset&) = delete;

	IVOOffset(CGfxModel* pGfxModel);
	~IVOOffset();

	//********************************************************************
	/// 获得三维模型欧拉角属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	三维模型欧拉角属性指针		
	//********************************************************************
	IVOOffsetEuler* GetEuler();

	//********************************************************************
	/// 获得三维模型标签偏移量属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	三维模型标签偏移量属性指针		
	//********************************************************************
	IVOOffsetLabel* GetLabel();

	//********************************************************************
	/// 获得三维模型平移补偿属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	三维模型平移补偿属性指针		
	//********************************************************************
	IVOOffsetTrans* GetTranslational();

private:
	CGfxModel*          m_pGfxModel;

	IVOOffsetEuler*     m_Euler;           //欧拉角
	IVOOffsetLabel*     m_Label;           //标签偏移量
	IVOOffsetTrans*     m_Translational;   //平移补偿
};

