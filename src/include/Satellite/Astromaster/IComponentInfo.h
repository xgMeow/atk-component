#pragma once
#include <string>
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "../../IClassInfo.h"

class CObjManage;
class CSatellite;
class CMCSSegment;
class CObjectBase;
class CAsStateCalc;

///
/// 基本属性
///
class IATKOBJECT_API IComponentInfo :public IClassInfo
{
public:
    IComponentInfo(const IComponentInfo&) = delete;
    IComponentInfo& operator=(const IComponentInfo&) = delete;

	IComponentInfo();
	virtual ~IComponentInfo();

	std::string GetDescription() { return m_Description; }

	void SetName(std::string strName) { m_Name = strName; }
	std::string GetName() { return m_Name; }

	void SetUserComment(std::string strUserComment) { m_UserComment = strUserComment; }
	std::string GetUserComment() { return m_UserComment; }

protected:
	std::string     m_Description;   //描述
	std::string     m_Name;          //名称
	std::string     m_UserComment;   //注释

	void SetStateCalcCBName(CAsStateCalc* pcAsStateCalc, std::string strCBName);
	std::string GetStateCalcCBName(CAsStateCalc* pcAsStateCalc);

	void SetStateCalcCSName(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc, std::string strCSName);
	std::string GetStateCalcCSName(CAsStateCalc* pcAsStateCalc);

	void SetStateCalcReference(
		CObjManage* pObjManage,
		CSatellite* pSate,
		CMCSSegment* pcSegment,
		CAsStateCalc* pcAsStateCalc,
		std::string strReference);
	std::string GetStateCalcReference(CAsStateCalc* pcAsStateCalc);

	void SetStateCalcOSName(
		CSatellite* pSate,
		CMCSSegment* pSegment,
		CAsStateCalc* pcAsStateCalc,
		std::string strOtherSegmentName);
	std::string GetStateCalcOSName(CAsStateCalc* pcAsStateCalc);

	void SetStateCalcSSToUse(CAsStateCalc* pcAsStateCalc, EVASegmentState eType);
	EVASegmentState GetStateCalcSSToUse(CAsStateCalc* pcAsStateCalc);

	void SetStateCalcRefVec(CObjManage* pObjManage, CAsStateCalc* pcAsStateCalc, std::string strRefVec);
	std::string GetStateCalcRefVec(CObjManage* pObjManage, CAsStateCalc* pcAsStateCalc);


private:
	void GetVectorParentPath(CObjectBase* pObjBase, std::string& strVecPath);
	   
};
