/// @file      SimulationAPI.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-18

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

class FuncBlock;

/// @brief 获取函数块输入端口数量
/// @details 参考 simulink API的 ssGetNumInputPorts 函数
/// @param block 函数块指针
/// @return 输入端口数量
AST_CORE_CAPI size_t aGetNumInputPorts(FuncBlock* block);



/// @brief 获取函数块输出端口数量
/// @details 参考 simulink API的 ssGetNumOutputPorts 函数
/// @param block 函数块指针
/// @return 输出端口数量
AST_CORE_CAPI size_t aGetNumOutputPorts(FuncBlock* block);



/// @brief 获取函数块输入端口数据类型
/// @details 参考 simulink API的 ssGetInputPortDataType 函数
/// @param block 函数块指针
/// @param portIndex 输入端口索引
/// @return 数据类型
AST_CORE_CAPI int aGetInputPortDataType(FuncBlock* block, size_t portIndex);



/// @brief 获取函数块输出端口数据类型
/// @details 参考 simulink API的 ssGetOutputPortDataType 函数
/// @param block 函数块指针
/// @param portIndex 输出端口索引
/// @return 数据类型
AST_CORE_CAPI int aGetOutputPortDataType(FuncBlock* block, size_t portIndex);


/// @brief 获取函数块输入端口的信号(指向数据的指针)
/// @details 参考 simulink API的 ssGetInputPortSignal 函数
/// @param block 函数块指针
/// @param portIndex 输入端口索引
/// @return 信号(指向数据的指针)
AST_CORE_CAPI const void* aGetInputPortSignal(FuncBlock* block, size_t portIndex);


/// @brief 获取函数块输出端口的信号(指向数据的指针)
/// @details 参考 simulink API的 ssGetOutputPortSignal 函数
/// @param block 函数块指针
/// @param portIndex 输出端口索引
/// @return 信号(指向数据的指针)
AST_CORE_CAPI void* aGetOutputPortSignal(FuncBlock* block, size_t portIndex);



/// @brief 获取函数块输入端口的实数值信号
/// @details 参考 simulink API的 ssGetInputPortRealSignal 函数
/// @param block 函数块指针
/// @param portIndex 输入端口索引
/// @return 实数值指针
AST_CORE_CAPI double* aGetInputPortRealSignal(FuncBlock* block, size_t portIndex);



/// @brief 获取函数块输出端口的实数值信号
/// @details 参考 simulink API的 ssGetOutputPortRealSignal 函数
/// @param block 函数块指针
/// @param portIndex 输出端口索引
/// @return 实数值指针
AST_CORE_CAPI double* aGetOutputPortRealSignal(FuncBlock* block, size_t portIndex);



/// @brief 获取函数块输入端口的宽度
/// @details 参考 simulink API的 ssGetInputPortWidth 函数
/// @param block 函数块指针
/// @param portIndex 输入端口索引
/// @return 端口宽度
AST_CORE_CAPI int aGetInputPortWidth(FuncBlock* block, size_t portIndex);


/// @brief 获取函数块输出端口的宽度
/// @details 参考 simulink API的 ssGetOutputPortWidth 函数
/// @param block 函数块指针
/// @param portIndex 输出端口索引
/// @return 端口宽度
AST_CORE_CAPI int aGetOutputPortWidth(FuncBlock* block, size_t portIndex);


// -----------------
// 扩展接口
// -----------------


/// @brief 设置函数块输入端口的实数值信号
/// @param block 函数块指针
/// @param portIndex 输入端口索引
/// @param signal 信号(指向数据的指针)
/// @return 错误码
AST_CORE_CAPI errc_t aSetInputPortRealSignal(FuncBlock* block, size_t portIndex, double* signal);


/// @brief 设置函数块输出端口的实数值信号
/// @param block 函数块指针
/// @param portIndex 输出端口索引
/// @param signal 信号(指向数据的指针)
/// @return 错误码
AST_CORE_CAPI errc_t aSetOutputPortRealSignal(FuncBlock* block, size_t portIndex, double* signal);


AST_NAMESPACE_END
