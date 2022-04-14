
/**
 * Group 2
 * Sanjeet Kapadia   2018B4A70137P
 * Lingesh Kumaar    2018B4A70857P
 * Aman Mishra       2018B4A70877P
 * Sidharth Varghese 2019A7PS1133P
 * Edara Bala Mukesh 2019A7PS0081P
 */

#include <stdio.h>

#include "AST/ast.h"
#include "Lexer/lexer.h"
#include "Parser/parser.h"
#include "SymbolTable/symbolTable.h"
#include "TypeChecker/typeChecker.h"

#define OUTFILE "./compiler"

void usageError() {
    printf("Usage error: " OUTFILE " testCase.txt code.asm\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {

    if (argc != 3)
        usageError();

    printf("***************** Compiler Stage 1 - Group 2 *****************\n\n");
    printf(GRN "Status:" RESET "\n");
    printf("Both lexical and syntax analyzer modules implemented\n");
    printf("FIRST and FOLLOW sets automated\n");
    printf("Module works with all 6 testcases\n");
    printf("Error handling and recovery implemented\n");
    printf("Parse tree can be constructed\n");

    int choice;
    for (;;) {
        choice = -1;
        printf(BLU "\n-------------------------------------------------------------"
                   "---------" RESET "\n\n");
        printf("0. Exit\n");
        printf("1. Token list generated by lexer\n");
        printf("2. Parse input testcase file and save parsetree to parsetree out "
               "file\n");
        printf("3. Abstract Syntax Tree\n");
        printf("4. Compute Compression\n");
        printf("5. Symbol Table Info\n");
        printf("6. Global Variables Info\n");
        printf("7. Activation Record Sizes\n");
        printf("8. Record Types and Sizes\n");
        printf("9. Type Checking and Semantic Analysis\n");
        printf("10. Code Generation\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 0:
            lexerCleanup();
            parserCleanup();
            exit(EXIT_SUCCESS);

        case 1:
            runLexerOnInputSourceCode(argv[1]);
            break;

        case 2:
            nary_free(parseInputSourceCode(argv[1]));
            break;

            /* case 4: {
                clock_t start_time, end_time;
                double  total_CPU_time, total_CPU_time_in_seconds;
                start_time = clock();

                nary_free(printParseTree(parseInputSourceCode(argv[1]),
                                         argv[2])); // utilizes the lexer as well

                end_time                  = clock();
                total_CPU_time            = (double)(end_time - start_time);
                total_CPU_time_in_seconds = total_CPU_time / CLOCKS_PER_SEC;

                printf("\nTotal CPU time            = %f\nTotal CPU time in "
                       "seconds = %f\n",
                       total_CPU_time, total_CPU_time_in_seconds);
                break;
            } */

        case 3: {
            Nary_tree pt = parseInputSourceCode(argv[1]);
            if (pt == NULL) {
                printf("source code is not syntatically correct\n");
                printf("cannot print ast\n");

                break;
            }

            AST ast = constructAST(pt);
            print_astRoot(ast);

            break;
        }

        case 4: {
            Nary_tree pt = parseInputSourceCode(argv[1]);
            if (pt == NULL) {
                printf("source code is not syntatically correct\n");

                break;
            }

            printf("\n");

            int count = nary_TreeCount(pt);
            int mem   = count * sizeof(*pt);
            printf("Parse tree Number of nodes = %d Allocated Memory = %d Bytes\n", count, mem);

            AST      ast       = constructAST(pt);
            uint32_t ast_mem   = 0;
            uint32_t ast_nodes = 0;
            computeMemoryAllocated(ast, &ast_mem, &ast_nodes);

            printf("AST Number of nodes = %d Allocated Memory = %d Bytes\n", ast_nodes, ast_mem);

            double compression = (mem - ast_mem) / (double)mem * 100.0;
            printf("Compression percentage = %f\n", compression);

            break;
        }

        case 5: {
            Nary_tree pt = parseInputSourceCode(argv[1]);
            if (pt == NULL) {
                printf("source code is not syntatically correct\n");

                break;
            }

            AST ast = constructAST(pt);
            printSymbolTable(ast);

            break;
        }

        case 6: {
            Nary_tree pt = parseInputSourceCode(argv[1]);
            if (pt == NULL) {
                printf("source code is not syntatically correct\n");

                break;
            }

            AST ast = constructAST(pt);
            printGlobalVars(ast);

            break;
        }

        case 7: {
            Nary_tree pt = parseInputSourceCode(argv[1]);
            if (pt == NULL) {
                printf("source code is not syntatically correct\n");

                break;
            }

            AST ast = constructAST(pt);
            printActivationRecordInfo(ast);

            break;
        }

        case 8: {
            Nary_tree pt = parseInputSourceCode(argv[1]);
            if (pt == NULL) {
                printf("source code is not syntatically correct\n");

                break;
            }

            AST ast = constructAST(pt);
            printRecordInfo(ast);

            break;
        }

        case 9: {
            Nary_tree pt = parseInputSourceCode(argv[1]);
            if (pt == NULL) {
                printf("source code is not syntatically correct\n");

                break;
            }

            printf("\n");

            AST ast = constructAST(pt);
            initRecordInfo(ast);
            constructSymbolTables(ast, false, false);
            initTypeValidator(ast);
            initTypeChecker(ast);

            break;
        }

        case 10:
            printf("TODO\n");
            break;

        default:
            printf(RED "\nInvalid choice" RESET "\n");
        }

        // flush the input buffer, but not with fflush
        char c;
        while ((c = getchar()) != '\n')
            continue;
    }

    return EXIT_SUCCESS;
}
