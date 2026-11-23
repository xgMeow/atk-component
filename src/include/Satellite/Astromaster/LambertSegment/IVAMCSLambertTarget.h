#pragma once
#include "../IVAMCSSegment.h"
#include "../../../ICEnum.h"
class CObjManage;
class CSatellite;
class CMCSLambertTarget;
class IVALambertState;
class IVAStoppingConditionCollection;
class IVAPropagator;

///
/// 兰勃特段
///
class IATKOBJECT_API IVAMCSLambertTarget : public IVAMCSSegment
{
public:
    IVAMCSLambertTarget(const IVAMCSLambertTarget&) = delete;
    IVAMCSLambertTarget& operator=(const IVAMCSLambertTarget&) = delete;

	IVAMCSLambertTarget(CSatellite* pSate, CMCSLambertTarget* pcLambertTarget, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSLambertTarget();

	//********************************************************************
	/// 移除控制变量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	void DisableControlParameter(EVAControlLambert eParam);

	//********************************************************************
	/// 添加控制变量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	void EnableControlParameter(EVAControlLambert eParam);

	//********************************************************************
	/// 查看控制变量是否添加
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	true-控制变量已添加
	//********************************************************************
	bool IsControlParameterEnabled(EVAControlLambert eParam);

	//********************************************************************
	/// 设置算法参数牛顿迭代次数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	nNewtonMax  牛顿迭代次数
	/// @Return	
	//********************************************************************
	void SetNewtonMax(int nNewtonMax);
	//********************************************************************
	/// 获得算法参数牛顿迭代次数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	牛顿迭代次数
	//********************************************************************
	int GetNewtonMax();

	//********************************************************************
	/// 设置算法参数同伦迭代次数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	nHomtopMax  同伦迭代次数
	/// @Return	
	//********************************************************************
	void SetHomtopMax(int nHomtopMax);
	//********************************************************************
	/// 获得算法参数同伦迭代次数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	同伦迭代次数
	//********************************************************************
	int GetHomtopMax();

	//********************************************************************
	/// 设置算法参数瞄准位置误差
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dIterPosErr  瞄准位置误差，默认单位m
	/// @Return	
	//********************************************************************
	void SetIterPosErr(double dIterPosErr);
	//********************************************************************
	/// 获得算法参数瞄准位置误差
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	瞄准位置误差
	//********************************************************************
	double GetIterPosErr();

	//********************************************************************
	/// 设置算法参数是否最小近拱点高度
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bUsePeriJudge  是否最小近拱点高度
	/// @Return	
	//********************************************************************
	void SetUsePeriJudge(bool bUsePeriJudge);
	//********************************************************************
	/// 获得算法参数是否最小近拱点高度
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	是否最小近拱点高度
	//********************************************************************
	bool GetUsePeriJudge();

	//********************************************************************
	/// 设置算法参数近拱点高度
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dPeriHeight  近拱点高度，默认单位m
	/// @Return	
	//********************************************************************
	void SetPeriHeight(double dPeriHeight);
	//********************************************************************
	/// 获得算法参数近拱点高度
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	近拱点高度
	//********************************************************************
	double GetPeriHeight();

	//********************************************************************
	/// 设置算法参数是否单脉冲
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bIsOnedv  是否单脉冲
	/// @Return	
	//********************************************************************
	void SetIsOnedv(bool bIsOnedv);
	//********************************************************************
	/// 获得算法参数是否单脉冲
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	是否单脉冲
	//********************************************************************
	bool GetIsOnedv();

	//********************************************************************
	/// 设置算法参数是否摄动迭代
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bIsPerturb  是否摄动迭代
	/// @Return	
	//********************************************************************
	void SetIsPerturb(bool bIsPerturb);
	//********************************************************************
	/// 获得算法参数是否摄动迭代
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	是否摄动迭代
	//********************************************************************
	bool GetIsPerturb();

	//********************************************************************
	/// 设置算法参数是否限制为椭圆轨道
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bIsElliptical  是否限制为椭圆轨道
	/// @Return	
	//********************************************************************
	void SetIsElliptical(bool bIsElliptical);
	//********************************************************************
	/// 获得算法参数是否限制为椭圆轨道
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	是否限制为椭圆轨道
	//********************************************************************
	bool GetIsElliptical();

	//********************************************************************
	/// 设置坐标系名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCoordSysName 例如"CentralBody/Earth J2000"
	/// @Return				
	//********************************************************************
	void SetCoordSystemName(std::string strCoordSysName);
	//********************************************************************
	/// 获得坐标系名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	例如"CentralBody/Earth J2000"
	//********************************************************************
	std::string GetCoordSystemName();

	//********************************************************************
	/// 设置坐标类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eCoordType 
	/// @Return				
	//********************************************************************
	void SetCoordType(EVAElementType eCoordType);
	//********************************************************************
	/// 获得坐标类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	坐标类型
	//********************************************************************
	EVAElementType GetCoordType();

	//********************************************************************
	/// 获得段坐标参数属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	段坐标参数属性指针
	//********************************************************************
	IVALambertState* GetLambertState();

	//********************************************************************
	/// 获得停止条件属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	停止条件指针
	//********************************************************************
	IVAStoppingConditionCollection* GetStoppingConditions();

	//********************************************************************
	/// 获得轨道预报属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	轨道预报属性指针
	//********************************************************************
	IVAPropagator* GetPropagator();

	//********************************************************************
	/// 获得控制变量是否可得
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return 控制变量是否可得
	//********************************************************************
	bool GetControlParametersAvailable();


private:
	CObjManage*                         m_IAsGObjManage;
	CSatellite*                         m_pSate;
	CMCSLambertTarget*                  m_pcLambertTarget;

	IVALambertState*                    m_LambertState;    //段坐标参数属性
	IVAStoppingConditionCollection*     m_StoppingConditions;   //停止条件属性
	IVAPropagator*                      m_Propagator;           //轨道预报属性指针

	std::string eTypeToStrName(EVAControlLambert eParam);

};

