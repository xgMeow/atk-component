#pragma once
#include <string>
#include <vector>
#include <map>
#include "../../ICEnum.h"
#include "../../IAtkObj.h"
class CObjManage;
class CSatellite;
class CMCSSegment;
class CAsState;
class IVAMCSSegment;
class ISatellite;
class IVAState;

///
/// 段集合
///
class IATKOBJECT_API IVAMCSSegmentCollection
{
public:
    IVAMCSSegmentCollection(const IVAMCSSegmentCollection&) = delete;
    IVAMCSSegmentCollection& operator=(const IVAMCSSegmentCollection&) = delete;

	IVAMCSSegmentCollection(CSatellite* pSate, CMCSSequence* pRootSeq, ISatellite* pISate, CObjManage* IAsGObjManage, std::string strParentSegmentName, bool bMainSequence);
	~IVAMCSSegmentCollection();

	//********************************************************************
	/// 插入段
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eSegmentType  段类型
	/// @Param	strSegmentName  插入段名称
	/// @Param	strSegmentToInsertBefore  插入段位置，向后插入使用"-"，向前插入使用段名称
	/// @Return	段属性
	//********************************************************************
	IVAMCSSegment* Insert(EVASegmentType eSegmentType, std::string strSegmentName, std::string strSegmentToInsertBefore);

	//********************************************************************
	/// 通过名称插入段
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strSegmentName  插入段的名称
	/// @Param	strSegmentToInsertBefore  插入段位置，向后插入使用"-"，向前插入使用段名称
	/// @Return	段属性
	//********************************************************************
	IVAMCSSegment* InsertByName(std::string strSegmentName, std::string strSegmentToInsertBefore);

	//********************************************************************
	/// 移除指定名称的段
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strSegmentNameToRemove  段名称
	/// @Return	
	//********************************************************************
	void Remove(std::string strSegmentNameToRemove);

	//********************************************************************
	/// 移除所有段
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	
	//********************************************************************
	void RemoveAll();

public:
	int                GetCount();                  //子段个数，包括根节点
	IVAMCSSegment*     Item(int nIndex);            //按添加段顺序，获得第nIndex个段
	IVAMCSSegment*     Item(std::string strName);   //获得指定名称的段

private:
	CObjManage*                               m_IAsGObjManage;
	CSatellite*                               m_pSate;
	ISatellite*                               m_pISate;
	CMCSSequence*                             m_pRootSeq;
	std::string                               m_strParentSegmentName;
	bool                                      m_bMainSequence;

	//std::vector<IVAMCSSegment*>               m_vecIVAMCSSegment;
	std::map<std::string, IVAMCSSegment*>     m_mapSegments;
	std::map<long long, IVAMCSSegment*>       m_mapIDSegments;

	std::string eTypeToString(EVASegmentType eSegmentType);
	EVASegmentType GetTypeFromString(std::string strSegmentName);
	IVAMCSSegment* GetIVAMCSSegment(CMCSSegment* pNewSeg, EVASegmentType eSegmentType, std::string strSequenceName, double dEpochSec);
	std::string AsNameUnique(CMCSSequence* pcSequence, std::string& strName);

	//内核已存在对象，新建二次开发对象
	IVAMCSSegment* InsertExist(EVASegmentType eSegmentType, std::string strSegmentName, std::string strSegmentToInsertBefore, bool bExist);

	friend class IVAMCSSegment;

};
