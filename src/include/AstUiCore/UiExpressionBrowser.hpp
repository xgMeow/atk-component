/// @file      UiExpressionBrowser.hpp
/// @brief     Expr 表达式选择控件
/// @details   用于选择对象属性表达式和对象计算量表达式，
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-25

#pragma once

#include "AstGlobal.h"
#include "AstScript/Expr.hpp"
#include "AstUtil/Object.hpp"
#include "AstUtil/Attribute.hpp"
#include "AstUtil/SharedPtr.hpp"
#include <QWidget>

class QTreeWidget;
class QTreeWidgetItem;
class QPushButton;

AST_NAMESPACE_BEGIN

class UiObjectTree;
class UiAttributeTree;

class AST_UICORE_API UiExpressionBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit UiExpressionBrowser(QWidget* parent = nullptr);
    UiExpressionBrowser(const UiExpressionBrowser&) = delete;
    UiExpressionBrowser& operator=(const UiExpressionBrowser&) = delete;

    /// @brief 获取选中的表达式，无选中时返回 nullptr
    Expr* selectedExpression() const { return selectedExpr_.get(); }

    /// @brief 以模态对话框形式弹出，返回用户选择的表达式（所有权转移给调用方）
    static Expr* GetExpression(QWidget* parent = nullptr);

signals:
    /// @brief 用户选择了对象属性表达式
    void propertyExpressionSelected(Expr* expr);

    /// @brief 用户选择了对象计算量表达式
    void calculationExpressionSelected(Expr* expr);

private slots:
    void onObjectSelected(Object* object);
    void onPropertySelected(const Attribute& attr);
    void onCalculationSelectionChanged();
    void onPropertyAccepted();
    void onCalculationAccepted();
    void onItemDoubleClicked(QTreeWidgetItem* item, int column);

private:
    void setupUi();
    void refreshCalculationTree();

    UiObjectTree*    objectTree_ = nullptr;
    UiAttributeTree* propertyTree_ = nullptr;
    QTreeWidget*     calculationTree_ = nullptr;
    QPushButton*     propertySelectButton_ = nullptr;
    QPushButton*     calculationSelectButton_ = nullptr;
    WeakPtr<Object>  currentObject_ = nullptr;
    SharedPtr<Expr>  selectedExpr_{}; 
};

AST_NAMESPACE_END
