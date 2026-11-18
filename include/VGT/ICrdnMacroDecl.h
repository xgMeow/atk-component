#pragma once
typedef int err_t;

//基础类型参数设置获取接口
#define IATKOBJECT_VGT_SETGET_DECL(PARAMETERNAME,PARAMETERCLASS)                         \
err_t Set##PARAMETERNAME(PARAMETERCLASS PARAMETER);                                      \
PARAMETERCLASS Get##PARAMETERNAME();

//角度类型参数设置获取接口 deg<->rad
#define IATKOBJECT_VGT_SETGET_DEG_DECL(PARAMETERNAME,PARAMETERCLASS)                     \
err_t Set##PARAMETERNAME(PARAMETERCLASS PARAMETER);                                      \
PARAMETERCLASS Get##PARAMETERNAME();

//CTimeAbs类型参数设置获取接口
#define IATKOBJECT_VGT_SETGET_CTIMEABS_DECL(PARAMETERNAME)                               \
err_t Set##PARAMETERNAME(std::string strCTimeAbs);                                       \
std::string Get##PARAMETERNAME();

//中心天体类型参数设置获取接口 string<->CCelestialBody
#define IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(PARAMETERNAME)                            \
err_t Set##PARAMETERNAME(std::string strCentralBodyPath);                                \
std::string Get##PARAMETERNAME();

//VGT类型参数设置获取接口 string<->CVGTBase
#define IATKOBJECT_VGT_SETGET_VGT_DECL(PARAMETERNAME)                                    \
err_t Set##PARAMETERNAME(std::string strVGTPath);                                        \
std::string Get##PARAMETERNAME();