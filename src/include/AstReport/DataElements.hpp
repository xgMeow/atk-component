/// @file      DataElements.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-06

#pragma once

#include "AstGlobal.h"
#include "DataElement.hpp"
#include "AstUtil/Dimension.hpp"
#include "AstUtil/VariantVector.hpp"
#include <map>
#include <vector>
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 数据元素容器
class DataElements;

namespace detail
{
    /// @brief 生成成员变量提取函数
    /// @tparam T 数据类类型
    /// @tparam MemberType 成员变量类型
    /// @tparam Member 成员变量指针
    template<typename T, typename MemberType, MemberType T::*Member>
    ElementExtractFunc makeExtractFunc()
    {
        return [](const VariantVector& data, VariantVector& element) -> errc_t
        {
            auto span = data.asSpan<const T>();
            if (!span.data()) return -1;
            using ElementType = typename std::remove_cv<typename std::remove_reference<MemberType>::type>::type;
            element.reset<ElementType>(span.size());
            auto* out = element.as<ElementType>();
            if (!out) return -1;
            for (size_t i = 0; i < span.size(); ++i)
                out[i] = span[i].*Member;
            return 0;
        };
    }

    /// @brief 生成成员函数(getter)提取函数
    /// @tparam T 数据类类型
    /// @tparam Ret getter 返回值类型
    /// @tparam Getter const 成员函数指针
    template<typename T, typename Ret, Ret (T::*Getter)() const>
    ElementExtractFunc makeExtractFunc()
    {
        return [](const VariantVector& data, VariantVector& element) -> errc_t
        {
            auto span = data.asSpan<const T>();
            if (!span.data()) return -1;
            using ElementType = typename std::remove_cv<typename std::remove_reference<Ret>::type>::type;
            element.reset<ElementType>(span.size());
            auto* out = element.as<ElementType>();
            if (!out) return -1;
            for (size_t i = 0; i < span.size(); ++i)
                out[i] = (span[i].*Getter)();
            return 0;
        };
    }
} // namespace detail


/// @brief 数据元素容器
class DataElements
{
public:
    DataElements() = default;
    ~DataElements() = default;

    /// @brief 获取数据元素
    const DataElement* getElement(StringView name) const;
    const DataElement* find(StringView name) const{return getElement(name);}

    /// @brief 获取所有数据元素
    const std::vector<DataElement>& getElements() const { return elements_; }

    /// @brief 添加数据元素
    void addElement(const DataElement& element);

    /// @brief 添加别名
    /// @param alias 别名
    /// @param name 数据元素名称
    void addAlias(const char* alias, const char* name);

    /// @brief 添加数据元素（成员变量版本）
    /// @tparam T 数据类类型
    /// @tparam MemberType 成员变量类型
    /// @tparam Member 成员变量指针
    template<typename T, typename MemberType, MemberType T::*Member>
    void addElement(const char* name, Dimension dimension = Dimension::Unit())
    {
        DataElement element;
        element.setName(name);
        element.setDimension(dimension);
        element.setExtractFunc(detail::makeExtractFunc<T, MemberType, Member>());
        addElement(element);
    }

    /// @brief 添加数据元素（const 成员函数版本）
    /// @tparam T 数据类类型
    /// @tparam Ret getter 返回值类型
    /// @tparam Getter const 成员函数指针
    template<typename T, typename Ret, Ret (T::*Getter)() const>
    void addElement(const char* name, Dimension dimension = Dimension::Unit())
    {
        DataElement element;
        element.setName(name);
        element.setDimension(dimension);
        element.setExtractFunc(detail::makeExtractFunc<T, Ret, Getter>());
        addElement(element);
    }

private:
    std::vector<DataElement> elements_{};                            ///< 数据元素列表
    std::vector<std::pair<std::string, std::string>> aliasMap_{};    ///< 别名映射
};

const int i = sizeof(DataElements);

/*! @} */

AST_NAMESPACE_END
