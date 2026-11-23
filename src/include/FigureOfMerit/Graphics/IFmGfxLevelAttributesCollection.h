#pragma once
#include "../../IAtkObj.h"
#include <vector>
struct GfxFOMGraphics;
class IFmGfxLevelAttributesElement;

///
/// 分级属性列表
///
class IATKOBJECT_API IFmGfxLevelAttributesCollection
{
public:
    IFmGfxLevelAttributesCollection(const IFmGfxLevelAttributesCollection&) = delete;
    IFmGfxLevelAttributesCollection& operator=(const IFmGfxLevelAttributesCollection&) = delete;

	IFmGfxLevelAttributesCollection(GfxFOMGraphics* pGfxFOMGraphics);
	~IFmGfxLevelAttributesCollection();

	//********************************************************************
	/// 添加分级deg
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	dLevel  分级deg
	/// @return		
	//********************************************************************
	IFmGfxLevelAttributesElement* AddLevel(double dLevel);

	//********************************************************************
	/// 根据步长添加分级deg
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	dStartLevel 开始
	/// @param[in]	dStopLevel 停止
	/// @param[in]	dSetpLevel 步长
	//********************************************************************
	void AddLevelRange(double dStartLevel, double dStopLevel, double dSetpLevel);

	//********************************************************************
	/// 移除所有分级
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 移除 指定分级
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	dLevel  指定分级
	//********************************************************************
	void Remove(double dLevel);

	//********************************************************************
	/// 获取分级个数
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return	分级个数
	//********************************************************************
	int GetCount();

	//********************************************************************
	///  获取指定分级
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	dLevel  指定分级
	/// @return	指定分级
	//********************************************************************
	IFmGfxLevelAttributesElement* Item(double dLevel);

private:
	//获取分级索引
	int GetLevelIndex(double dLevel);

	GfxFOMGraphics*														m_pGfxFOMGraphics;

	std::vector<IFmGfxLevelAttributesElement*>			m_VectorILevelAttribute;
	std::vector<int>															m_VectorColor;
	int																					m_ColorIndex;
};
