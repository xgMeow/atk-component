/// @file      AgentUtils.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-27

#pragma once

#include "AstGlobal.h"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class JsonValue;

/// @brief 将对象转换为简化的JSON格式
/// @details 包含对象的名称、类型、ID和父作用域ID
/// @param obj 对象指针
/// @return 简化的JSON对象
AST_AI_API JsonValue aObjectToBriefJson(Object* obj);

/// @brief 将对象转换为JSON值
/// @param object 对象
/// @param maxDepth 最大递归深度
/// @return JSON值
AST_AI_API JsonValue aObjectToJson(Object* object, int maxDepth = 20);


/// @brief 获取类的JSON Schema
/// @param cls 类指针
/// @param maxDepth 最大递归深度
/// @return 类的JSON Schema
AST_AI_API JsonValue aClassJsonSchema(Class* cls, int maxDepth = 20);



//--------------
// 智能体工具函数
//--------------

typedef std::string (*FCallTool)(const JsonValue& arguments);

/// @brief 查找类的参数结构定义
/// @return 查找类参数结构定义
JsonValue aFindClassesParamSchema();

/// @brief 查找类
/// @param arguments 查找类参数
/// @return 查找类结果
std::string aFindClasses(const JsonValue& arguments);

/// @brief 创建对象的参数结构定义
/// @return 创建对象参数结构定义
JsonValue aCreateObjectParamSchema();

/// @brief 创建对象
/// @param arguments 创建对象参数
/// @return 创建对象结果
std::string aCreateObject(const JsonValue& arguments);

/// @brief 查找对象的参数结构定义
/// @return 查找对象参数结构定义
JsonValue aFindObjectsParamSchema();

/// @brief 查找对象
/// @param arguments 查找对象参数
/// @return 查找对象结果
std::string aFindObjects(const JsonValue& arguments);

/// @brief 获取对象属性的参数结构定义
/// @return 获取对象属性参数结构定义
JsonValue aGetObjectAttributesParamSchema();

/// @brief 获取对象属性
/// @param arguments 获取对象属性参数
/// @return 获取对象属性结果
std::string aGetObjectAttributes(const JsonValue& arguments);

/// @brief 设置对象属性的参数结构定义
/// @return 设置对象属性参数结构定义
JsonValue aSetObjectAttributeParamSchema();

/// @brief 设置对象属性
/// @param arguments 设置对象属性参数
/// @return 设置对象属性结果
std::string aSetObjectAttribute(const JsonValue& arguments);


/// @brief 显示编辑对话框的参数结构定义
/// @return 显示编辑对话框参数结构定义
JsonValue aShowEditDialogParamSchema();

/// @brief 显示编辑对话框
/// @param arguments 显示编辑对话框参数
/// @return 显示编辑对话框结果
std::string aShowEditDialog(const JsonValue& arguments);


/*! @} */

AST_NAMESPACE_END
