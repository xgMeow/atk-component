/// @file      MockStringView.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2.12.2025

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include <string>
#if _HAS_CXX17
#include <string_view>
#endif

AST_NAMESPACE_BEGIN

AST_MOCK_API int aMockSizeStringConstRef(const std::string& str);
AST_MOCK_API int aMockSizeStringValue(std::string str);
AST_MOCK_API int aMockSizeStringView(StringView str);
AST_MOCK_API int aMockSizeStringViewRef(const StringView& str);

AST_MOCK_API const std::string& aMockStringValue();


AST_MOCK_API int aMockSetStringConstRef(const std::string& str);
AST_MOCK_API int aMockSetStringValue(std::string str);
AST_MOCK_API int aMockSetStringView(StringView str);
AST_MOCK_API int aMockSetStringViewRef(const StringView& str);


AST_MOCK_API int aMockCallByStringConstRef();
AST_MOCK_API int aMockCallByStringValue();
AST_MOCK_API int aMockCallByStringView();
AST_MOCK_API int aMockCallByStringConstRef(const std::string& str);
AST_MOCK_API int aMockCallByStringValue(std::string str);
AST_MOCK_API int aMockCallByStringView(StringView str);
AST_MOCK_API int aMockCallByStringViewRef(const StringView& str);
AST_MOCK_API int aMockCallByCharPtr(const char* str, size_t size);






#if _HAS_CXX17
AST_MOCK_CAPI int aMockSetStringViewStd(StringView str);
#endif

AST_NAMESPACE_END

