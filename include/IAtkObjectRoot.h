#pragma once
#include "IAtkObject.h"

class CObjManage;
struct CObjData;
class IAnimation;
class IScenario;
class IATKBatchCrdnTransform;
class ICat;
class IConstellDesign;
class IAtkObjectCoverage;

///
/// 根对象
///
class IATKOBJECT_API  IAtkObjectRoot :public IAtkObject
{
public:
    IAtkObjectRoot(const IAtkObjectRoot&) = delete;
    IAtkObjectRoot& operator=(const IAtkObjectRoot&) = delete;

	IAtkObjectRoot();
	IAtkObjectRoot(CObjManage* pIAsGObjManage);
	~IAtkObjectRoot();

	//********************************************************************
	/// 新建场景
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strSceName  场景名称
	/// @param[in]	strCentralBodyName  中心天体名称
	//********************************************************************
	void NewScenario(const std::string& strSceName, std::string strCentralBodyName = "");

	//********************************************************************
	/// 关闭场景
	/// @author	Dong Min
	/// @date	2023-11-3
	//********************************************************************
	void CloseScenario();

	//********************************************************************
	/// 加载场景文件
	/// @author	Dong Min
	/// @date	2023-11-3
	//********************************************************************
	void LoadScenario(const std::string& strFilePath);

        //********************************************************************
	/// 通过路径得到当前对象
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strTruncPath  截断路径，例："Satellite/Satelite1"
	/// @return	对象属性
	//********************************************************************
	IAtkObject* GetObjectFromPath(const std::string& strTruncPath);

        //********************************************************************
	/// 判断对象是否存在
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strTruncPath  截断路径，例："Satellite/Satelite1"
	/// @return	true-对象存在
	//********************************************************************
	bool ObjectExists(const std::string& strTruncPath);

        //********************************************************************
	/// 保存场景
	/// @author	Gan Shu Long
	/// @date	2023-12-6
	//********************************************************************
	void SaveScenario();
	void SaveScenario(std::string strFilePath);

	//********************************************************************
	/// 输出数据报告
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in] 	pIAtkObject  对象指针
	/// @param[in] 	strStyle     报告类型
	/// @param[in] 	strStartUTC  开始时间
	/// @param[in] 	strStopUTC   结束时间
	/// @param[in] 	fileNamePrefix   附加后缀名
	/// @return	输出报告路径
	//********************************************************************
	std::string OutputDataReport(IAtkObject* pIAtkObject, std::string strStyle, const std::string& strStartUTC, const std::string& strStopUTC, std::string fileNamePrefix = "");

        //********************************************************************
	/// 输出数据报告
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @note 参数 pIAtkObject：对象指针
	/// @note 参数 strStartUTC：开始时间
	/// @note 参数 strStopUTC：结束时间
	/// @note 参数 pos：报告位置
	/// @note 参数 vel：报告速度
	/// @note 取值：返回数据是否成功
	//********************************************************************
	//bool OutputJ2000Report(IAtkObject* pIAtkObject, std::vector<std::string>& dateTime, std::vector<std::vector<double>>& pos, std::vector<std::vector<double>>& vel);

	//********************************************************************
	/// 根据给定时间输出数据报告
	/// @author	Dong Min
	/// @date	2025-05-12
	/// @param[in] 	pIAtkObject  对象指针
	/// @param[in] 	dateTime  时间
	/// @param[in] 	posCBI   惯性系位置/固体系位置
	/// @param[in] 	velCBI   惯性系速度/固体系速度
	/// @return	返回数据是否成功
	//********************************************************************
	bool OutputPosVelCBI(IAtkObject* pIAtkObject, std::string dateTime, std::vector<double>& posCBI, std::vector<double>& velCBI);
	bool OutputPosVelCBF(IAtkObject* pIAtkObject, std::string dateTime, std::vector<double>& posCBF, std::vector<double>& velCBF);
	bool OutputPosVelJ2000(IAtkObject* pIAtkObject, std::string dateTime, std::vector<double>& pos, std::vector<double>& vel);

	//********************************************************************
	/// 根据给定信息输出数据
	/// @author	Dong Min
	/// @date	2025-05-12
	/// @param[in] 	pIAtkObject  对象指针/对象路径，例：Satellite/Satellite1
	/// @param[in] 	eDataType    数据类型
	/// @param[in] 	strStartTime  开始时间
	/// @param[in] 	strStopTime   结束时间
	/// @param[in] 	dStepSec   步长
	/// @param[out] 	vecEpoch  时间 
	/// @param[out] 	vecData  数据 
	/// @return	返回数据是否成功
	//********************************************************************
	bool OutputOrbitDataCBF(IAtkObject* pIAtkObject,
		EDataType eDataType,
		std::string strStartTime,
		std::string strStopTime,
		double dStepSec,
		std::vector<std::string>& vecEpoch,
		std::vector<std::vector<double>>& vecData);

	bool OutputOrbitDataCBF(std::string strObjPath,
		EDataType eDataType,
		std::string strStartTime,
		std::string strStopTime,
		double dStepSec,
		std::vector<std::string>& vecEpoch,
		std::vector<std::vector<double>>& vecData);

	//********************************************************************
	/// 通过路径得到当前对象
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @note 参数 strTruncPath：截断路径，例："Satellite/Satelite1"
	/// @return	对象属性
	//********************************************************************
	IScenario* GetCurrentScenario();

	//********************************************************************
	/// 获取仿真操作指针
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	仿真操作指针
	//********************************************************************
	IAnimation* GetAnimation();

	//********************************************************************
	/// 批量坐标转换
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	批量坐标转换操作指针
	//********************************************************************
	IATKBatchCrdnTransform* GetBatchCrdnTransform();

	//********************************************************************
	/// 接近分析
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	接近分析操作指针
	//********************************************************************
	ICat* GetCat();

	//********************************************************************
	/// 星座设计
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @return	星座设计操作指针
	//********************************************************************
	IConstellDesign* GetConstellDesign();

	//********************************************************************
	/// 覆盖性
	/// @author	Gan Shu Long
	/// @date	2026-09-30
	/// @return	覆盖性操作指针
	//********************************************************************
	IAtkObjectCoverage* GetObjectCoverage();

private:
	bool                                 bNewObjManage;

	//IAtkObject*                        m_CurrentObject;
	IScenario*                           m_CurrentScenario;   //场景信息
	IAnimation*                          m_Animation;		 //多继承转成员
	IATKBatchCrdnTransform*              m_BatchCrdnTransform;   //批量坐标转换
	ICat*                                m_Cat;   //批量坐标转换
	IConstellDesign*                     m_ConstellDesign;   //星座设计
	IAtkObjectCoverage*					 m_ObjectCoverage;	//覆盖性

	// 递归加载场景对象
	bool LoadObject(CObjData* pObjData, IAtkObject* pParentIAtkObj);
	// 新建对象
	IAtkObject* NewIObject(CObjData* pObjData);
	// 删除对象
	void DeIObject(IAtkObject* pParentIAtkObj);
	// 递归查找I对象
	void InitIObject();
	// 递归查找对象
	void GetObject(std::string strObjPath, IAtkObjectCollection* pParentObj, IAtkObject* &pIObj);

	friend class IAtkObject;
};


//********************************************************************
/// 此接口仅向脚本工具提供使用，请不要随意调用
/// @author	Dong Min
/// @date	2025-11-25
/// @return	保证脚本工具使用一个Root指针
//********************************************************************
IATKOBJECT_API IAtkObjectRoot* GetIAtkObjectRoot();


