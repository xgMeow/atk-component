#pragma once
#include <string>
#include "../../../IAtkObj.h"
class CObjManage;
class CMCSSegment;
class CMCSManeuver;
class IVAMCSSegment;
class IVAStoppingConditionCollection;

///
/// 机动段有限推力轨道预报高级设置
///
class IATKOBJECT_API IVAManeuverFinitePropagator
{
public:
    IVAManeuverFinitePropagator(const IVAManeuverFinitePropagator&) = delete;
    IVAManeuverFinitePropagator& operator=(const IVAManeuverFinitePropagator&) = delete;

	IVAManeuverFinitePropagator(CMCSSegment* pcSegment, IVAMCSSegment* pIVAMCSSegment, CObjManage* IAsGObjManage);
	~IVAManeuverFinitePropagator();

	//********************************************************************
	/// 设置轨道预报中心天体名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strPropagatorName   轨道预报中心天体名称
	/// @Return				
	//********************************************************************
	void SetPropagatorName(std::string strPropagatorName);
	//********************************************************************
	/// 获得轨道预报中心天体名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	轨道预报中心天体名称
	//********************************************************************
	std::string GetPropagatorName();

	//********************************************************************
	/// 设置引力场模型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strGravModel   引力场模型
	/// @Return				
	//********************************************************************
	void SetGravModel(std::string strGravModel);
	//********************************************************************
	/// 获得引力场模型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	引力场模型
	//********************************************************************
	std::string GetGravModel();

	//********************************************************************
	/// 设置引力场次数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	nMaxOrder   引力场次数
	/// @Return				
	//********************************************************************
	void SetMaxOrder(int nMaxOrder);
	//********************************************************************
	/// 获得引力场次数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	引力场次数
	//********************************************************************
	int GetMaxOrder();

	//********************************************************************
	/// 设置引力场阶数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	nMaxDegree  引力场阶数
	/// @Return				
	//********************************************************************
	void SetMaxDegree(int nMaxDegree);
	//********************************************************************
	/// 获得引力场阶数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	引力场阶数
	//********************************************************************
	int GetMaxDegree();

	//********************************************************************
	/// 设置大气阻力摄动使用情况
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bUseDrag   大气阻力摄动使用情况
	/// @Return				
	//********************************************************************
	void SetUseDrag(bool bUseDrag);
	//********************************************************************
	/// 获得大气阻力摄动使用情况
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	大气阻力摄动使用情况
	//********************************************************************
	bool GetUseDrag();

	//********************************************************************
	/// 设置大气阻力摄动大气模型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strAtmModel   大气阻力摄动大气模型
	/// @Return				
	//********************************************************************
	void SetAtmModel(std::string strAtmModel);
	//********************************************************************
	/// 获得大气阻力摄动大气模型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	大气阻力摄动大气模型
	//********************************************************************
	std::string GetAtmModel();

	//********************************************************************
	/// 设置太阳辐射通量/地磁指数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bUseFluxGeoFile   太阳辐射通量/地磁指数
	/// @Return				
	//********************************************************************
	void SetUseFluxGeoFile(bool bUseFluxGeoFile);
	//********************************************************************
	/// 获得太阳辐射通量/地磁指数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	太阳辐射通量/地磁指数
	//********************************************************************
	bool GetUseFluxGeoFile();

	//********************************************************************
	/// 设置每日F10.7
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	nDailyF10p7   每日F10.7
	/// @Return				
	//********************************************************************
	void SetDailyF10p7(double nDailyF10p7);
	//********************************************************************
	/// 获得每日F10.7
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	每日F10.7
	//********************************************************************
	double GetDailyF10p7();

	//********************************************************************
	/// 设置平均F10.7
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	nF10p7   平均F10.7
	/// @Return				
	//********************************************************************
	void SetF10p7(double nF10p7);
	//********************************************************************
	/// 获得平均F10.7
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	平均F10.7
	//********************************************************************
	double GetF10p7();

	//********************************************************************
	/// 设置地磁指数Ap
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	nAp   地磁指数Ap
	/// @Return				
	//********************************************************************
	void SetAp(double nAp);
	//********************************************************************
	/// 获得地磁指数Ap
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	地磁指数Ap
	//********************************************************************
	double GetAp();

	//********************************************************************
	/// 设置太阳光压摄动
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bUseSRP   太阳光压摄动
	/// @Return				
	//********************************************************************
	void SetUseSRP(bool bUseSRP);
	//********************************************************************
	/// 获得太阳光压摄动
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	太阳光压摄动
	//********************************************************************
	bool GetUseSRP();

	//********************************************************************
	/// 设置三体摄动 天体使用情况
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Param	bUseGravity   三体摄动 天体使用情况
	/// @Return				
	//********************************************************************
	void SetUseTBGravity(std::string strCBName, bool bUseGravity);
	//********************************************************************
	/// 获得三体摄动 天体使用情况
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Return	三体摄动 天体使用情况
	//********************************************************************
	bool GetUseTBGravity(std::string strCBName);

	//********************************************************************
	/// 设置三体摄动类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Param	nGravType   三体摄动类型
	/// @Return				
	//********************************************************************
	void SetTBGravType(std::string strCBName, int nGravType);
	//********************************************************************
	/// 获得三体摄动类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Return	三体摄动类型
	//********************************************************************
	int GetTBGravType(std::string strCBName);

	//********************************************************************
	/// 设置三体摄动模式
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Param	strGravModel   三体摄动模式
	/// @Return				
	//********************************************************************
	void SetTBGravModel(std::string strCBName, std::string strGravModel);
	//********************************************************************
	/// 获得三体摄动类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Return	三体摄动类型
	//********************************************************************
	std::string GetTBGravModel(std::string strCBName);

	//********************************************************************
	/// 设置三体摄动阶数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Param	nGravDegree   三体摄动阶数
	/// @Return				
	//********************************************************************
	void SetTBGravDegree(std::string strCBName, int nGravDegree);
	//********************************************************************
	/// 获得三体摄动阶数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Return	三体摄动阶数
	//********************************************************************
	int GetTBGravDegree(std::string strCBName);

	//********************************************************************
	/// 设置三体摄动次数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Param	nGravOrder   三体摄动次数
	/// @Return				
	//********************************************************************
	void SetTBGravOrder(std::string strCBName, int nGravOrder);
	//********************************************************************
	/// 获得三体摄动次数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Return	三体摄动次数
	//********************************************************************
	int GetTBGravOrder(std::string strCBName);

	//********************************************************************
	/// 设置三体摄动引力常数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Param	nGravValue   引力常数
	/// @Return				
	//********************************************************************
	void SetTBGravValue(std::string strCBName, double nGravValue);
	//********************************************************************
	/// 获得三体摄动引力常数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName          三体摄动 三体名称
	/// @Return	三体摄动引力常数
	//********************************************************************
	double GetTBGravValue(std::string strCBName);

	//********************************************************************
	/// 获得停止条件属性操作指针
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	停止条件属性操作指针
	//********************************************************************
	IVAStoppingConditionCollection* GetStoppingConditions();

private:
	CMCSManeuver*                       m_pcManeuver;
	IVAMCSSegment*                      m_pIVAMCSSegment;
	CObjManage*                         m_IAsGObjManage;

	IVAStoppingConditionCollection*     m_StoppingConditions;   //预报停止条件

	int GetTBGravityID(std::string strThirdBody);

};
