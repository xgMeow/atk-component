#pragma once
#include <vector>
#include <string>
#include "../IAtkObj.h"
#include "../ICEnum.h"
class CCrdnTfm;

///
/// 批量坐标转换
///
class IATKOBJECT_API IATKBatchCrdnTransform
{
public:
    IATKBatchCrdnTransform(const IATKBatchCrdnTransform&) = delete;
    IATKBatchCrdnTransform& operator=(const IATKBatchCrdnTransform&) = delete;

	IATKBatchCrdnTransform();
	~IATKBatchCrdnTransform();

	//********************************************************************
	/// 设置 时间类型
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @param[in]	eTimeType  时间类型
	///	    eUTCTIME 历元时间
	///	    eRELATIVETIME 相对时间
	//********************************************************************
	void SetTimeType(ETimeType eTimeType);

	//********************************************************************
	/// 获取 时间类型
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @return	时间类型
	//********************************************************************
	ETimeType GetTimeType();

	//********************************************************************
	/// 设置 历元时间格式类型
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @param[in]	strUTCTimeType  历元时间格式类型
	///     "UTCG_MM"
	///     "UTCG"
	///     "BJT"
	///     "BDT"
	///     "BDTG"
	///     "GPS"
	///     "GPSG"
	///     "TDTG"
	///     "JDate"
	///     "ModJDate"
	///     "EpSec"
	//********************************************************************
	void SetUTCTimeType(std::string strUTCTimeType);

	//********************************************************************
	/// 获取 历元时间格式类型
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @return	历元时间格式类型
	//********************************************************************
	std::string GetUTCTimeType();

	//********************************************************************
	/// 设置 相对时间初试时间
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @param[in]	strRelativeTimeStart  相对时间初试时间
	/// @note 返回值：RELATIVE
	//********************************************************************
	void SetRelativeTimeStart(std::string strRelativeTimeStart);

	//********************************************************************
	/// 获取 相对时间初试时间
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @return	相对时间初试时间
	//********************************************************************
	std::string GetRelativeTimeStart();

	//********************************************************************
	/// 设置 转换参数列表
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @param[in]	vectorParams  转换参数列表，{ePosition，eVelocity} =>（时间，位置，速度）
	///     时间必须第一列，不需要设置
	///     ePOSITION	位置
	///     eVELOCITY	速度
	/// @return	
	//********************************************************************
	bool SetCrdnTransformParam(std::vector<EDataSequence> vectorParams);

	//********************************************************************
	/// 获取 转换参数列表
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @return	转换参数列表
	//********************************************************************
	std::vector<EDataSequence> GetCrdnTransformParam();

	//********************************************************************
	/// 设置 长度单位
	/// @author	Gan Shu Long
	/// @date	2026-07-04
	/// @param[in]	strUnit  长度单位
	//********************************************************************
	void SetDistanceUnit(std::string strUnit);

	//********************************************************************
	/// 获取 长度单位
	/// @author	Gan Shu Long
	/// @date	2026-07-07
	/// @return	长度单位
	//********************************************************************
	std::string GetDistanceUnit();

	//********************************************************************
	/// 设置 时间单位
	/// @author	Gan Shu Long
	/// @date	2026-07-04
	/// @param[in]	strUnit  时间单位
	//********************************************************************
	void SetTimeUnit(std::string strUnit);

	//********************************************************************
	/// 获取 时间单位
	/// @author	Gan Shu Long
	/// @date	2026-07-07
	/// @return	时间单位
	//********************************************************************
	std::string GetTimeUnit();

	//********************************************************************
	/// 设置 批量坐标转换源坐标系
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @param[in]	strCentralBody  中心天体
	/// @param[in]	strCoordinateSystem  系统
	/// @return	设置 是否成功
	//********************************************************************
	bool SetSrcCoordinate(std::string strCentralBody, std::string strCoordinateSystem);

	//********************************************************************
	/// 获取 批量坐标转换源坐标系中心天体
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @return	中心天体
	//********************************************************************
	std::string GetSrcCentralBody();

	//********************************************************************
	/// 获取 批量坐标转换源坐标系系统
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @return	系统
	//********************************************************************
	std::string GetSrcCoordinateSystem();

	//********************************************************************
	/// 设置 批量坐标转换目标坐标系
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @param[in]	strCentralBody  中心天体
	/// @param[in]	strCoordinateSystem  系统
	/// @return	
	//********************************************************************
	bool SetDstCoordinate(std::string strCentralBody, std::string strCoordinateSystem);

	//********************************************************************
	/// 获取 批量坐标转换源目标坐标系中心天体
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @return	中心天体
	//********************************************************************
	std::string GetDstCentralBody();

	//********************************************************************
	/// 获取 批量坐标转换源目标坐标系系统
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @return	系统
	//********************************************************************
	std::string GetDstCoordinateSystem();
	
	//********************************************************************
	/// 设置 导入文件类型
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @param[in]	eImportFileType  导入文件类型
	///	    eTxt 文本
	///	    eEPHEMERIS 星历      //导入星历文件时，默认就是相对时间
	/// @return	
	//********************************************************************
	bool SetImportFileType(EImportExportFileType eImportFileType);

	//********************************************************************
	/// 获取 导入文件类型
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @return	导入文件类型
	//********************************************************************
	EImportExportFileType GetImportFileType();

	//********************************************************************
	/// 设置 导入文件路径 
	/// 注意：导入星历文件内的时间单位坐标系，会覆盖原本的时间单位坐标系设置
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @param[in]	strImportFilePath  导入文件路径
	//********************************************************************
	void SetImportFilePath(std::string strImportFilePath);

	//********************************************************************
	/// 获取 导入文件路径
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @return	导入文件路径
	//********************************************************************
	std::string GetImportFilePath();

	//********************************************************************
	/// 设置 导出文件类型
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @param[in]	eExportFileType  导出文件类型
	///	    eTxt 文本
	///	    eEPHEMERIS 星历
	/// @return	
	//********************************************************************
	bool SetExportFileType(EImportExportFileType eExportFileType);

	//********************************************************************
	/// 获取 导出文件类型
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @return	导出文件类型
	//********************************************************************
	EImportExportFileType GetExportFileType();

	//********************************************************************
	/// 批量坐标转换为批量坐标转换数据保存到文件
	/// @author	Gan Shu Long
	/// @date	2026-07-03
	/// @param[in]	strExportFilePath  导出文件路径
	/// @return	
	//********************************************************************
	bool Export(std::string strExportFilePath);

private:
	CCrdnTfm*		m_pCCrdnTfm;						//计算内核
	std::string	    m_strUTCTimeType;					//暂存一份历元时间格式，切换回历元时间时使用
};
