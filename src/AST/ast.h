
/**
 * Group 2
 * Sanjeet Kapadia   2018B4A70137P
 * Lingesh Kumaar    2018B4A70857P
 * Aman Mishra       2018B4A70877P
 * Sidharth Varghese 2019A7PS1133P
 * Edara Bala Mukesh 2019A7PS0081P
 */

#ifndef AST_H
#define AST_H

#include "Utils/nary.h"
#include "astDef.h"

AST  constructAST(const Nary_tree pt);
void print_astRoot(AST root);
void computeMemoryAllocated(const AST ast, uint32_t *mem, uint32_t *nodes);
void freeAST(AST ast);

#endif // AST_H
