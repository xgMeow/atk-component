#pragma once
#include <string>
#include <vector>
#include "../../../IAtkObj.h"
class CObjManage;
class CSatellite;
class CMCSSegment;
class IVAMCSSegment;
class IComponentInfo;

///
/// 计算量集合
///
class IATKOBJECT_API IVACalcObjectCollection
{
public:
    IVACalcObjectCollection(const IVACalcObjectCollection&) = delete;
    IVACalcObjectCollection& operator=(const IVACalcObjectCollection&) = delete;

	IVACalcObjectCollection(CSatellite* pSate, CMCSSegment* pcSegment, IVAMCSSegment* pIVAMCSSegment, CObjManage* IAsGObjManage);
	~IVACalcObjectCollection();

	//********************************************************************
	/// 添加计算量条件
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strName   计算量条件名称，例：Eccentricity/Semimajor_Axis
	/// @Return	返回计算量条件属性
	//********************************************************************
	IComponentInfo* Add(std::string strName);

	//********************************************************************
	/// 移除第nIndex个计算量条件
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	nIndex   按添加顺序，移除第nIndex个计算量条件
	/// @Return	
	//********************************************************************
	void Remove(int nIndex);

	//********************************************************************
	/// 移除指定名称的计算量条件
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strName  计算量条件名称，例：Eccentricity
	/// @Return	
	//********************************************************************
	void Remove(std::string strName);

public:
	int                              GetCount();                  //计算量条件个数
	IComponentInfo*                  Item(int nIndex);            //按添加计算量条件顺序，获得第nIndex个计算量条件
	IComponentInfo*                  Item(std::string strName);   //获得指定名称的计算量条件

protected:
	IComponentInfo*                  m_pIComponentInfo;

private:
	CObjManage*                      m_IAsGObjManage;
	CSatellite*                      m_pSate;
	CMCSSegment*                     m_pcSegment;
	IVAMCSSegment*                   m_pIVAMCSSegment;

	std::map<CAsStateCalc*, IComponentInfo*>     m_mapIDIComponentInfo;

	IComponentInfo* SetIComInfo(std::string strName, CAsStateCalc* pCAsStateCalc);

};
