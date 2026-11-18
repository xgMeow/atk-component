#pragma once
#include <codecvt>
#include <iomanip>
#include "ICEnum.h"
#include "IAtkObject.h"
#include "IAtkObjectRoot.h"
#include "IAtkObjectCollection.h"
#include "Sensor/ISnPattern.h"
#include "Sensor/ISnPointing.h"
#include "Sensor/ISnPtFixed.h"
#include "Sensor/IOrientation.h"
#include "Facility/IFacility.h"
#include "Facility/IPosition.h"
#include "Facility/ICartesian.h"
#include "Facility/IGeodetic.h"
#include "AccessConstraints/IAccessConstraintCollection.h"
#include "Satellite/PassBreak/IVePassBreak.h"
#include "Satellite/PassBreak/IVeDefinition.h"
#include "Satellite/PassBreak/IVeBreakAngle.h"
#include "Satellite/Attitude/IVeOrbitAttitudeStandard.h"
#include "Satellite/Attitude/IVeAttitude.h"
#include "Satellite/Attitude/IVeAttProfile.h"
#include "Satellite/HPOP/IVeInitialState.h"
#include "Satellite/OrbitState/IOrbitState.h"
#include "Satellite/Attitude/IVeStandardBasic.h"
#include "Satellite/Propagator/IVePropagatorHPOP.h"
#include "Satellite/PassBreak/IVeBreakAngleBreakByLatOrLon.h"
#include "Satellite/OrbitState/IOrbitStateCartesian.h"
class CObjManage;
class CSatellite;
class CMCSRPOSequence;
class CMCSSequence;
class CMCSSegment;
class CMCSInitialState;
class CMCSHold;
class CMCSLambertTarget;
class CAsStopCondition;
class CAsStateCalc;
class IVAMCSSegment;
class IVAMCSSegmentCollection;
class IVADriverMCS;

const double COM_KM_COEF = 1000.0;
//
/////<获得对象指针
//void GetObjPtr(IAtkObjectRoot* pIAtkObjectRoot, IAtkObject* &pIAtkObject, CObjData* pScenData, CObjData* pObjData, const std::string strObjName, CObjManage* IAsGObjManage);
//
/////<设置根对象信息
//void GetObjRootPtr(IAtkObjectRoot* &pIAtkObjectRoot, IScenario* pIScen);
//
/////<设置对象子对象信息
//void GetObjChildren(IAtkObject* &pIAtkObject, CObjData* pObjData, const std::string strObjName, CObjManage* IAsGObjManage);
//
/////<设置对象是否有子对象
//void SetHasChildren(IAtkObject* &pIAtkObject, CObjData* pObjData);
//
/////<设置对象属性
//void SetIObjProperty(IAtkObject* &pIAtkObject, IScenario* &pIScen, CObjData* pScenData, CObjData* pObjData, CObjManage* IAsGObjManage);
//
/////<设置场景对象属性
//void GetIScenPtr(IScenario* &pIScen, CObjData* pScenData, CObjManage* IAsGObjManage, IAtkObjectRoot* pIAtkObjectRoot);


///<<递归调用获取属性路径对应操作段
void GetSegmentFromAttPath(CMCSSequence* pcSequence, const std::string& strParentSegment, const std::string& strSegment, CMCSSegment* &pcSegment, bool& bInside);

void GetSegmentFromParentAndName(CMCSSequence* pcSequence, const std::string& strParentSegment, const std::string& strSegment, CMCSSegment* &pcSegment, bool& bInside);

void GetSegmentFromName(CMCSSequence* pcSequence, const std::string& strSegment, CMCSSegment* &pcSegment, bool& bInside);

void GetParentSegmentFromAttPath(CMCSSequence* pcSequence, const std::string& strParentSegment, CMCSSegment* &pcSegment, bool& bInside);

//获得I接口段的父段，若父段为根节点，返回为空
IVAMCSSegment* GetIParentSequence(IVAMCSSegment* pISubSegment, CObjManage* IAsGObjManage);
void GetIParentSequenceByPtr(IVAMCSSegment* &pIParentSegment, IVADriverMCS* pIVADriverMCS, IVAMCSSegment* pISubSegment, IVAMCSSegmentCollection* pIVAMCSSegmentCollection);

///<设置初始段坐标系
bool SetIniCoordSystem(std::string strCoordSysName, CMCSInitialState* pcInitialState);

///<设置停止条件坐标系
bool SetSCCoordSystem(std::string strCoordSysName, CAsStopCondition* pStopCondition);

///<设置保持段坐标系
bool SetHolCoordSystem(std::string strHoldFrameName, CMCSHold* pcHold);

///<设置兰勃特段坐标系
bool SetLambCoordSystem(std::string strCoordSysName, CMCSLambertTarget* pcLambert);

///<设置约束条件坐标系
bool SetResCoordSystem(std::string strCoordSysName, CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);

///<获得RPO段运行结果
bool GetRPOSegmentResult(CMCSRPOSequence* pcRPOSequence,
	std::vector<std::string>& strUTC,
	std::vector<double>& dDVx,
	std::vector<double>& dDVy,
	std::vector<double>& dDVz,
	int nType);

//设置I接口控制变量个数
bool SetIControlCount(IVAMCSSegment* pISubSegment, bool bSetActive, CObjManage* IAsGObjManage);

//获取某对象类型是否支持某接口
bool GetIObjIsSupportInterface(EATKObjectType objType, std::string strInterfaceName);

//获取某类是否支持某类型
bool GetIObjClassIsSupportType(EATKObjectType objType, std::string strClassName, int eType);

//获得保存目录
std::string GetSaveDir();

std::string DeleteEndInvalidZero(std::string strNum);
