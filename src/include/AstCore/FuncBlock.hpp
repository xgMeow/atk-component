/// @file      FuncBlock.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-16

#pragma once

#include "AstGlobal.h"
#include "DataPort.hpp"
#include "SimTime.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

class SimTime;

/// @brief 函数块/功能块
/// @details 
/// 函数块是一个基本的计算单元，用于执行特定的数学或逻辑操作。
/// 每个函数块都有输入端口和输出端口，用于接收和发送信号。
/// 在函数块中，信号指的是指向数据的指针
/// 
/// 输入和输出信号可以与其他函数块的端口进行连接，形成信号流/数据流。
/// 函数块的具体计算逻辑由派生类实现。
class AST_CORE_API FuncBlock
{
public:
    FuncBlock() = default;
    virtual ~FuncBlock(){};
    A_DISABLE_COPY(FuncBlock);

    /// @brief 计算函数块
    /// @param simTime 仿真时间
    /// @return 错误码
    virtual errc_t run(const SimTime& simTime) = 0;


    /// @brief 获取输入端口
    /// @param ports 输入端口向量
    const std::vector<DataPort>& getInputPorts() const { return inputPorts_; }
    std::vector<DataPort>& getInputPorts() { return inputPorts_; }

    /// @brief 获取输出端口
    /// @param ports 输出端口向量
    const std::vector<DataPort>& getOutputPorts() const { return outputPorts_; }
    std::vector<DataPort>& getOutputPorts() { return outputPorts_; }


    /// @brief 获取输入端口数量
    /// @return 输入端口数量
    size_t getNumInputPorts() const { return inputPorts_.size(); }

    /// @brief 获取输出端口数量
    /// @return 输出端口数量
    size_t getNumOutputPorts() const { return outputPorts_.size(); }

    /// @brief 获取输入端口
    /// @param portName 端口名称
    /// @return 输入端口指针
    DataPort* getInputPort(StringView portName);

    /// @brief 获取输出端口
    /// @param portName 端口名称
    /// @return 输出端口指针
    DataPort* getOutputPort(StringView portName);

    /// @brief 获取输入端口
    /// @param portIndex 端口索引
    /// @return 输入端口指针
    DataPort* getInputPort(size_t portIndex);

    /// @brief 获取输出端口
    /// @param portIndex 端口索引
    /// @return 输出端口指针
    DataPort* getOutputPort(size_t portIndex);

    /// @brief 获取输入端口数据类型
    /// @param portIndex 端口索引
    /// @return 输入端口数据类型
    DataPort::EValueType getInputPortDataType(size_t portIndex);


    /// @brief 获取输出端口数据类型
    /// @param portIndex 端口索引
    /// @return 输出端口数据类型
    DataPort::EValueType getOutputPortDataType(size_t portIndex);

    /// @brief 获取输入端口信号
    /// @param portIndex 端口索引
    /// @return 输入端口信号指针
    void* getInputPortSignal(size_t portIndex);


    /// @brief 获取输出端口信号
    /// @param portIndex 端口索引
    /// @return 输出端口信号指针
    void* getOutputPortSignal(size_t portIndex);


    /// @brief 获取输入端口实数值信号
    /// @param portIndex 端口索引
    /// @return 输入端口实数值信号指针
    double* getInputPortRealSignal(size_t portIndex);


    /// @brief 获取输出端口实数值信号
    /// @param portIndex 端口索引
    /// @return 输出端口实数值信号指针
    double* getOutputPortRealSignal(size_t portIndex);


    /// @brief 获取输入端口宽度
    /// @param portIndex 端口索引
    /// @return 输入端口宽度
    int getInputPortWidth(size_t portIndex);


    /// @brief 获取输出端口宽度
    /// @param portIndex 端口索引
    /// @return 输出端口宽度
    int getOutputPortWidth(size_t portIndex);

    /// @brief 连接函数块的端口
    /// @param src 源函数块
    /// @param srcPortName 源端口名称
    /// @param dst 目标函数块
    /// @param dstPortName 目标端口名称
    /// @return 错误码
    static errc_t connect(FuncBlock* src, StringView srcPortName, FuncBlock* dst, StringView dstPortName);

    /// @brief 连接函数块的端口
    /// @param src 源函数块
    /// @param srcPortIndex 源端口索引
    /// @param dst 目标函数块
    /// @param dstPortIndex 目标端口索引
    /// @return 错误码
    static errc_t connect(FuncBlock* src, size_t srcPortIndex, FuncBlock* dst, size_t dstPortIndex);

protected:
    std::vector<DataPort> inputPorts_{};
    std::vector<DataPort> outputPorts_{};
};

AST_NAMESPACE_END
