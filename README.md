# Compiler
A simple compiler for the language specifications provided in [Language Specifications.pdf](docs/Language\ Specifications.pdf)

## Requirements
* gcc
* nasm (for compiling the asm file)

## Modules Implemented
* Lexical Analyzer
* Syntax Analyzer (Parser)
* Abstract Syntax Tree Constructor
* Symbol Table Generator
* Type Checker (static type checking)
* Semantic Analyzer
* Code Generator (WIP (Krappa))

All libraries and data structures used in any of the modules can be found in [Utils](src/Utils)

## Compiling the Compiler
All instructions for compiling are defined in the Makefile. Simply run `make`

### Running on a Testcase
`./compiler <path_to_testcase_file> code.asm`

### Generating Machine code from
`nasm -f elf64 code.asm && gcc -no-pie code.o && ./a.out`
