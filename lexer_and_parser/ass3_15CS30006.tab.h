/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_ASS3_15CS30006_TAB_H_INCLUDED
# define YY_YY_ASS3_15CS30006_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    UNSIGNED = 258,
    BREAK = 259,
    RETURN = 260,
    VOID = 261,
    CASE = 262,
    FLOAT = 263,
    SHORT = 264,
    CHAR = 265,
    FOR = 266,
    SIGNED = 267,
    WHILE = 268,
    GOTO = 269,
    BOOL = 270,
    CONTINUE = 271,
    IF = 272,
    DEFAULT = 273,
    DO = 274,
    INT = 275,
    SWITCH = 276,
    DOUBLE = 277,
    LONG = 278,
    MATRIX = 279,
    OPENBRCSQ = 280,
    CLOSEBRCSQ = 281,
    OPENBRCCIR = 282,
    CLOSEBRCCIR = 283,
    OPENBRCCUR = 284,
    CLOSEBRCCUR = 285,
    DOT = 286,
    POINTSTO = 287,
    PLUSPLUS = 288,
    MINUSMINUS = 289,
    AND = 290,
    STAR = 291,
    PLUS = 292,
    MINUS = 293,
    NEGATE = 294,
    NOT = 295,
    DIVIDE = 296,
    PERCENT = 297,
    LESSLESS = 298,
    GREATGREAT = 299,
    LESS = 300,
    GREAT = 301,
    LESSEQUAL = 302,
    GREATEQUAL = 303,
    EQUALEQUAL = 304,
    NOTEQUAL = 305,
    XOR = 306,
    OR = 307,
    ANDAND = 308,
    OROR = 309,
    QUESTION = 310,
    EQUALS = 311,
    MULTIPLYEQUALS = 312,
    DIVIDEEQUALS = 313,
    MODEQUALS = 314,
    PLUSEQUALS = 315,
    MINUSEQUALS = 316,
    LESSLESSEQUALS = 317,
    GREATGREATEQUALS = 318,
    ANDEQUALS = 319,
    XOREQUALS = 320,
    OREQUALS = 321,
    COMMA = 322,
    HASH = 323,
    DOTINVERTEDCOMMA = 324,
    COLON = 325,
    SEMICOLON = 326,
    IDENTIFIER = 327,
    CONSTANT = 328,
    STRINGLITERAL = 329,
    ELSE = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASS3_15CS30006_TAB_H_INCLUDED  */
