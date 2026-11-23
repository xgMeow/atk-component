/// @file      XmlSerializer.hpp
/// @brief     XML序列化器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-30

#pragma once

#include "Serializer.hpp"

AST_NAMESPACE_BEGIN

/// @brief XML序列化器
class AST_UTIL_API XmlSerializer : public Serializer {
public:
    errc_t serialize(Object* object, std::string& output) override;
    errc_t deserialize(const std::string& input, Object* object) override;
};

AST_NAMESPACE_END