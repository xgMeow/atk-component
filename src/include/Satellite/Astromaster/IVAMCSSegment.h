#pragma once
#include <string>
#include "../../ICEnum.h"
#include "IComponentInfo.h"
class CObjManage;
class CSatellite;
class CMCSSegment;
struct AsTEvent;
class IVAState;
class IVAMCSSegmentProperties;
class IVACalcObjectCollection;
class IVAMCSSegmentCollection;

///
/// 段
///
class IATKOBJECT_API IVAMCSSegment : public IComponentInfo
{
public:
    IVAMCSSegment(const IVAMCSSegment&) = delete;
    IVAMCSSegment& operator=(const IVAMCSSegment&) = delete;

	IVAMCSSegment(CSatellite* pSate, CMCSSegment* pSegment, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSSegment();

	//********************************************************************
	/// 获得约束条件的属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strResultName   约束条件名称，例：Eccentricity
	/// @Return	约束条件属性值
	//********************************************************************
	//std::string GetResultValue(std::string strResultName);

	//********************************************************************
	/// 获得约束条件的属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strResultName   约束条件名称，例：Eccentricity
	/// @Return	约束条件属性值
	//********************************************************************
	//IVAState* Run();

	//********************************************************************
	/// 获得结束状态属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	结束状态属性
	//********************************************************************
	IVAState* GetFinalState();

	//********************************************************************
	/// 获得初始状态属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	初始状态属性
	//********************************************************************
	IVAState* GetInitialState();

	//********************************************************************
	/// 获得段属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	段属性指针
	//********************************************************************
	IVAMCSSegmentProperties* GetProperties();

	//********************************************************************
	/// 获得段类型
	/// @Author	Dong Min
	/// @Date	2025-05-27
	/// @Return	段类型
	//********************************************************************
	EVASegmentType               GetType();

	//********************************************************************
	/// 获得段约束操作指针
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	段约束操作指针
	//********************************************************************
	IVACalcObjectCollection*     GetResults();        //约束条件

private:
	CSatellite*                  m_pSate;
	CMCSSegment*                 m_pSegment;
	IVAMCSSegmentCollection*     m_pISegColl;
	CObjManage*                  m_IAsGObjManage;

	IVAState*                    m_FinalState;     //结束状态属性
	IVAState*                    m_InitialState;   //初始状态属性
	IVAMCSSegmentProperties*     m_Properties;     //段属性
	IVACalcObjectCollection*     m_Results;        //约束条件

	void RemoveSequenceSubSegment(IVAMCSSegment* self);
	static void HandleSegment(IVAMCSSegment* self, const AsTEvent& event_);

};
