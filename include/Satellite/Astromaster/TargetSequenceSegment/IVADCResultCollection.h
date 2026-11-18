#pragma once
#include <string>
#include <vector>
#include "../../../IAtkObj.h"
class CAsShooterProfile;
class CMCSSequence;
class CMCSSegment;
class CMCSTargetSequence;
class IVADCResult;
class IVAProfile;

///
/// 属性页约束集合
///
class IATKOBJECT_API IVADCResultCollection
{
public:
    IVADCResultCollection(const IVADCResultCollection&) = delete;
    IVADCResultCollection& operator=(const IVADCResultCollection&) = delete;

	IVADCResultCollection(CMCSTargetSequence* pcTargetSequence, IVAProfile* pIVAProfile);
	~IVADCResultCollection();

	//********************************************************************
	/// 获得约束属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strObjectPath    段名
	/// @Param	strResultPath    约束名称 
	/// @Return	约束指针		
	//********************************************************************
	IVADCResult* GetResultByPaths(std::string strObjectPath, std::string strResultPath);

public:
	int                           GetCount();        //获取约束个数
	IVADCResult*                  Item(int nIndex);

private:
	CMCSTargetSequence*           m_pcTargetSequence;
	IVAProfile*                   m_pIVAProfile;
	std::vector<IVADCResult*>     m_vecIVADCResult;

	void GetCSegment(std::string& strObjectPath, CMCSSegment*& pcSegment, CMCSSequence* pcParentSequence);
	void GetCProfile(CAsShooterProfile*& pcProfile);

	friend class IVADCResult;
};
