#ifndef CODEGEN_CODE_GENERATOR_H
#define CODEGEN_CODE_GENERATOR_H

#include "sema/SymbolTable.hpp"
#include "visitor/AstNodeVisitor.hpp"

#include <cstdio>
#include <memory>
#include <string>

class CodeGenerator final : public AstNodeVisitor {
  private:
    const SymbolManager *m_symbol_manager_ptr;
    std::string m_source_file_path;
    std::unique_ptr<FILE> m_output_file;
    std::map<std::string, std::stack<int>> addr_stack;
    std::stack<int> label_base;


  public:
    ~CodeGenerator() = default;
    CodeGenerator(const std::string &source_file_name,
                  const std::string &save_path,
                  const SymbolManager *const p_symbol_manager);

    void visit(ProgramNode &p_program) override;
    void visit(DeclNode &p_decl) override;
    void visit(VariableNode &p_variable) override;
    void visit(ConstantValueNode &p_constant_value) override;
    void visit(FunctionNode &p_function) override;
    void visit(CompoundStatementNode &p_compound_statement) override;
    void visit(PrintNode &p_print) override;
    void visit(BinaryOperatorNode &p_bin_op) override;
    void visit(UnaryOperatorNode &p_un_op) override;
    void visit(FunctionInvocationNode &p_func_invocation) override;
    void visit(VariableReferenceNode &p_variable_ref) override;
    void visit(AssignmentNode &p_assignment) override;
    void visit(ReadNode &p_read) override;
    void visit(IfNode &p_if) override;
    void visit(WhileNode &p_while) override;
    void visit(ForNode &p_for) override;
    void visit(ReturnNode &p_return) override;

    void addrStackPop(const std::string p_name);
    void addrStackPush(const std::string p_name);

    bool is_global_constant;
    bool is_main;
    bool is_lvalue;
    bool is_if;
    bool is_else;
    bool is_while;
    bool is_branch;
    bool is_for;
    bool is_for_head;
    int label_num;
    int current_label;
    int local_addr;
    int parameter_num;
};

#endif
