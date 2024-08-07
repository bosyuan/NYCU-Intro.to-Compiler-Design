#ifndef AST_EXPRESSION_NODE_H
#define AST_EXPRESSION_NODE_H

#include "AST/ast.hpp"
#include "AST/PType.hpp"

class ExpressionNode : public AstNode {
  public:
    ~ExpressionNode() = default;
    ExpressionNode(const uint32_t line, const uint32_t col)
        : AstNode{line, col} {}

    void set_type(PTypeSharedPtr type) { m_type = type; }
    bool isScalarType() { return m_type->isScalarType(); }
    PTypeSharedPtr get_type() { return m_type; }
  protected:
    // for carrying type of result of an expression
    // TODO: for next assignment
    PTypeSharedPtr m_type = nullptr;
};

#endif
