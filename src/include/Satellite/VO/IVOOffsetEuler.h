#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
struct CGfxModel;

///
/// 欧拉角
///
class IATKOBJECT_API IVOOffsetEuler
{
public:
    IVOOffsetEuler(const IVOOffsetEuler&) = delete;
    IVOOffsetEuler& operator=(const IVOOffsetEuler&) = delete;

	IVOOffsetEuler(CGfxModel* pGfxModel);
	~IVOOffsetEuler();

	//********************************************************************
	/// 设置三维模型欧拉角1
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dEuler1  欧拉角1
	//********************************************************************
	void SetEuler1(double dEuler1);
	//********************************************************************
	/// 设置三维模型欧拉角1
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	欧拉角1
	//********************************************************************
	double GetEuler1();

	//********************************************************************
	/// 设置三维模型欧拉角2
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dEuler2  欧拉角2
	//********************************************************************
	void SetEuler2(double dEuler2);
	//********************************************************************
	/// 设置三维模型欧拉角2
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	欧拉角2
	//********************************************************************
	double GetEuler2();

	//********************************************************************
	/// 设置三维模型欧拉角3
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dEuler3  欧拉角3
	//********************************************************************
	void SetEuler3(double dEuler3);
	//********************************************************************
	/// 设置三维模型欧拉角3
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	欧拉角3
	//********************************************************************
	double GetEuler3();

private:
	CGfxModel*					m_pGfxModel;		//C对象三维模型指针

};

