#pragma once
#include "../IAtkObj.h"
#include "IFmDefinitionData.h" 

///
/// 品质因子定义数据：最小重数
///
class IATKOBJECT_API IFmDefDataMinAssets :public IFmDefinitionData
{
public:
    IFmDefDataMinAssets(const IFmDefDataMinAssets&) = delete;
    IFmDefDataMinAssets& operator=(const IFmDefDataMinAssets&) = delete;

	IFmDefDataMinAssets(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefDataMinAssets();

	//********************************************************************
	/// 设置  最小重数
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	nMinAssets 最小重数
	//********************************************************************
	void SetMinAssets(int nMinAssets);

	//********************************************************************
	/// 获得 最小重数
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	最小重数
	//********************************************************************
	int GetMinAssets();
};
