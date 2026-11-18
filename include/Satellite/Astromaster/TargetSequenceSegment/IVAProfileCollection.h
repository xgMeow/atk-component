#pragma once
#include <string>
#include <vector>
#include <map>
#include "../../../ICEnum.h"
#include "../../../IAtkObj.h"
#include "../IComponentInfo.h"
class CAsShooterProfile;
class CMCSTargetSequence;
class IVAProfile;

///
/// 属性页集合
///
class IATKOBJECT_API IVAProfileCollection : public IComponentInfo
{
public:
    IVAProfileCollection(const IVAProfileCollection&) = delete;
    IVAProfileCollection& operator=(const IVAProfileCollection&) = delete;

	IVAProfileCollection(CMCSTargetSequence* pcTargetSequence);
	~IVAProfileCollection();

	//********************************************************************
	/// 添加瞄准序列段属性页
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strProfileName   属性页名称，使用Differential Corrector，
	///									SQP Optimizer，Evolution Optimizer
	/// @Return	属性页指针		
	//********************************************************************
	IVAProfile* Add(std::string strProfileName);

	//********************************************************************
	/// 添加瞄准序列段属性页
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strProfileName   属性页名称，0 = DifferentialCorrector1，1 = DifferentialCorrector2，
	///									2 = SQPOptimizer，3 = EvolutionOptimizer
	/// @Param	strName          已存在属性页名称
	/// @Param	eDirection       属性页插入位置，0为向前插入，1为向后插入
	/// @Return	属性页指针		
	//********************************************************************
	//IVAProfile* Add2(std::string strProfileName, std::string strName, EVAProfileInsertDirection eDirection);
	//********************************************************************
	/// 添加瞄准序列段属性页
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strProfileName   属性页名称，0 = DifferentialCorrector1，1 = DifferentialCorrector2，
	///									2 = SQPOptimizer，3 = EvolutionOptimizer
	/// @Param	nIndex           已存在属性页序号，从0开始
	/// @Param	eDirection       属性页插入位置，0为向前插入，1为向后插入
	/// @Return	属性页指针		
	//********************************************************************
	//IVAProfile* Add2(std::string strProfileName, int nIndex, EVAProfileInsertDirection eDirection);

	//********************************************************************
	/// 移除瞄准序列段属性页
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strProfileName   属性页名称
	/// @Return			
	//********************************************************************
	void Remove(std::string strProfileName);
	//********************************************************************
	/// 移除瞄准序列段属性页
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	nIndex           属性页序号，从0开始
	/// @Return			
	//********************************************************************
	void Remove(int nIndex);

	//********************************************************************
	/// 移除所有瞄准序列段属性页
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return			
	//********************************************************************
	void RemoveAll();

public:
	std::vector<std::string>     GetAvailableProfiles();      //可设置属性页名称
	int                           GetCount();                  //属性页个数
	IVAProfile*                   Item(std::string strName);
	IVAProfile*                   Item(int nIndex);

private:
	CMCSTargetSequence* m_pcTargetSequence;
	IVAProfile* m_IVAProfile;
	std::map<CAsShooterProfile*, IVAProfile*> m_mapIVAProfile;

	std::string AsNameUnique(CMCSTargetSequence* &pTargetSequence, std::string& strName);
	IVAProfile* SetProfile(CAsShooterProfile* pCAsShoProf, std::string strProfileName, bool bAdd);

	friend class IVAProfile;
};
