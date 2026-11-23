#pragma once
#include "../IVAMCSSegment.h"
class CObjManage;
class CSatellite;
class CMCSRPOSequence;
class IVAPropagator;

///
/// RPOSegment
///
class IATKOBJECT_API IVAMCSRPOSegment : public IVAMCSSegment
{
public:
    IVAMCSRPOSegment(const IVAMCSRPOSegment&) = delete;
    IVAMCSRPOSegment& operator=(const IVAMCSRPOSegment&) = delete;

	IVAMCSRPOSegment(CSatellite* pSate, CMCSRPOSequence* pcRPOSeq, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSRPOSegment();

	//********************************************************************
	/// 设置RPO段参数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strParamName  参数名称
	/// @Param	dResults      参数数值
	/// @Return	
	//********************************************************************
	void SetParameters(std::string strParamName, double dResults);
	void SetParameters(std::string strParamName, std::string dResults);
	//********************************************************************
	/// 获得RPO段参数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Param	strParamName  参数名称，0为微分修正
	/// @Return	参数数值
	//********************************************************************
	double GetParameters(std::string strParamName);

	//********************************************************************
	/// 获得RPO段轨道预报属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	轨道预报属性指针
	//********************************************************************
	IVAPropagator* GetPropagator();

	//********************************************************************
	/// 获得RPO段结果参数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	vecUTC 结果-时间
	/// @Param	vecDVx 结果-DeltaVx
	/// @Param	vecDVy 结果-DeltaVy
	/// @Param	vecDVz 结果-DeltaVz
	/// @Param	nType 输入类型，0-输出到窗口，1-输出到文件，2-仅返回数组
	/// @Return	RPO单次跳跃段是否获取到结果
	//********************************************************************
	bool GetSegmentResult(std::vector<std::string>& vecUTC,
		std::vector<double>& vecDVx,
		std::vector<double>& vecDVy,
		std::vector<double>& vecDVz,
		int nType);

	//********************************************************************
	/// 设置段参考航天器
	/// @Author	Dong Min
	/// @Date	2025-06-19
	/// @Input
	/// @Param	strObjPath   参考航天器路径，例：Satellite/Satellite1
	/// @Return				
	//********************************************************************
	void SetObjReference(std::string strObjPath);

private:
	CMCSRPOSequence*         m_pcMCSRPOSequence;
	IVAPropagator*			 m_Propagator;

	void StrDeleteBlankAndUnderline(std::string& strInOut);

};


