
/**
 * Group 2
 * Sanjeet Kapadia   2018B4A70137P
 * Lingesh Kumaar    2018B4A70857P
 * Aman Mishra       2018B4A70877P
 * Sidharth Varghese 2019A7PS1133P
 * Edara Bala Mukesh 2019A7PS0081P
 */

#ifndef TYPECHECKER_H
#define TYPECHECKER_H

#include "AST/ast.h"
#include "SymbolTable/symbolTable.h"

void initTypeValidator(const AST ast);
void initTypeChecker(const AST ast);

extern bool tc_error;

#endif // TYPECHECKER_H
