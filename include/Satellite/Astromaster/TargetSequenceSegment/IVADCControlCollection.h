#pragma once
#include <string>
#include <map>
#include "../../../IAtkObj.h"
class CAsShooterControl;
class CAsShooterProfile;
class CMCSSequence;
class CMCSSegment;
class CMCSTargetSequence;
class IVAProfile;
class IVADCControl;

///
/// 属性页控制变量属性
///
class IATKOBJECT_API IVADCControlCollection
{
public:
    IVADCControlCollection(const IVADCControlCollection&) = delete;
    IVADCControlCollection& operator=(const IVADCControlCollection&) = delete;

	IVADCControlCollection(CMCSTargetSequence* pcTargetSequence, IVAProfile* pIVAProfile);
	~IVADCControlCollection();

	//********************************************************************
	/// 获得控制变量属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strObjectPath    段名
	/// @Param	strControlPath   控制变量名称 
	/// @Return	控制变量指针
	//********************************************************************
	IVADCControl* GetControlByPaths(std::string strObjectPath, std::string strControlPath);

public:
	int                  GetCount();         //获取控制变量个数
	IVADCControl*        Item(int nIndex);
		
private:
	CMCSTargetSequence*                             m_pcTargetSequence;
	IVAProfile*                                     m_pIVAProfile;
	std::map<CAsShooterControl*, IVADCControl*>     m_mapIVADCControl;

	void GetCSegment(std::string& strObjectPath, CMCSSegment*& pcSegment, CMCSSequence* pcParentSequence);
	void GetCProfile(CAsShooterProfile*& pcProfile);

	friend class IVADCControl;
};
