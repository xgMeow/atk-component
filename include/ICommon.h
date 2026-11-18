#pragma once
#include "IAtkObject.h"


//********************************************************************
/// 设置调用语言类型 
/// @author	ganshulong
/// @date	2024-07-22
/// @param[in] strCallCodeType 调用语言类型
IATKOBJECT_API void SetCallCodeType(std::string strCallCodeType);

//********************************************************************
/// 获取调用语言类型 
/// @author	ganshulong
/// @date	2024-07-22
/// @return	调用语言类型 
//********************************************************************
IATKOBJECT_API std::string GetCallCodeType();

//********************************************************************
/// 设置保存文件的基础路径，用来兼容处理不同系统/模式/语言情况下，输出位置不统一的问题
/// @author	ganshulong
/// @date	2024-04-25
/// @param[in] strPath 保存文件的基础路径
//********************************************************************
IATKOBJECT_API void SetSaveFileBasePath(std::string strPath);

//********************************************************************
/// 获取保存文件的基础路径，用来兼容处理不同系统/模式/语言情况下，输出位置不统一的问题
/// @author	ganshulong
/// @date	2024-04-25
/// @note 输入：保存文件的基础路径
/// @return	空
//********************************************************************
IATKOBJECT_API std::string GetSaveFileBasePath();
