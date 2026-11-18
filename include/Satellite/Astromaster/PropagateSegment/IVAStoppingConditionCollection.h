#pragma once
#include <string>
#include <vector>
#include "../../../ICEnum.h"
#include "../../../IAtkObj.h"
class CObjManage;
class CMCSSegment;
class CMCSHold;
class CMCSPropagate;
class CAsStopCondition;
class IVAMCSSegment;
class IVAStoppingConditionElement;

///
/// 停止条件元素集合
///
class IATKOBJECT_API IVAStoppingConditionCollection
{
public:
    IVAStoppingConditionCollection(const IVAStoppingConditionCollection&) = delete;
    IVAStoppingConditionCollection& operator=(const IVAStoppingConditionCollection&) = delete;

	IVAStoppingConditionCollection(CMCSSegment* pcSegment, IVAMCSSegment* pIVAMCSSegment, CObjManage* IAsGObjManage, int nType);
	~IVAStoppingConditionCollection();

	//********************************************************************
	/// 添加停止条件
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strConditionName  停止条件名称,Duration/Altitude/Apoapsis/Argument_of_Latitude/AscendingNode/DescendingNode/
	///                           Epoch/Longitude/Latitude/Mean_Anomaly/Periapsis/R_Magnitude/True_Anomaly/
    ///                           X-Y_Plane_Cross/Y-Z_Plane_Cross/Z-X_Plane_Cross/AscToDesc/DescToAsc/StateCalc
	/// @Return	停止条件属性
	//********************************************************************
	IVAStoppingConditionElement* Add(std::string strConditionName);

	//********************************************************************
	/// 移除停止条件
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	nIndex  按添加顺序排序，从0开始
	/// @Return	
	//********************************************************************
	void Remove(int nIndex);

	//********************************************************************
	/// 移除停止条件
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strName  停止条件名称
	/// @Return	
	//********************************************************************
	void Remove(std::string strName);

	int GetCount();	//集合中停止条件个数
	IVAStoppingConditionElement* Item(int nIndex);                //通过序号获得停止条件属性
	IVAStoppingConditionElement* Item(std::string strName);       //通过名称获得停止条件属性

private:	
	CObjManage*                                   m_IAsGObjManage;
	int                                           m_nType;                       //集合中停止条件个数
	CMCSHold*                                     m_pcHold;
	CMCSPropagate*                                m_pcPropagate;
	CMCSFollow*                                   m_pcFollow;
	IVAMCSSegment*                                m_pIVAMCSSegment;


	std::map<CAsStopCondition*,IVAStoppingConditionElement*>     m_mapIDStoppingCondition;

	void Init();
	std::string strNameToString(std::string strConditionName);
	std::string AsNameUnique(CMCSPropagate* &pPropagate, std::string& strName);
	std::string AsNameUnique(CMCSHold* &pHold, std::string& strName);
	std::string AsNameUnique(CMCSFollow* &pFollow, int nType, std::string& strName);

	//判断停止条件是否存在
	bool IsCSCExist(std::vector<CAsStopCondition*> pcSC, std::string strConditionName, CAsStopCondition* &pSC);

	friend class IVAStoppingConditionElement;
};
