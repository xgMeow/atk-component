/// @file      MissionIcons.hpp
/// @brief     任务段图标提供器
/// @details   从 data/icons/ 加载 SVG 图标，统一管理图标路径
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-23

#pragma once

#include "AstGlobal.h"
#include <QIcon>
#include <QCoreApplication>
#include <QString>

AST_NAMESPACE_BEGIN

/// @brief 根据图标名加载 data/icons/ 下的 SVG 图标
inline QIcon missionIcon(const QString& name)
{
    QString path = QCoreApplication::applicationDirPath() + "/data/icons/" + name + ".svg";
    return QIcon(path);
}

AST_NAMESPACE_END
