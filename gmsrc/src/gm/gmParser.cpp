
/*  A Bison parser, made from gmparser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define yyparse gmparse
#define yylex gmlex
#define yyerror gmerror
#define yylval gmlval
#define yychar gmchar
#define yydebug gmdebug
#define yynerrs gmnerrs
#define	KEYWORD_LOCAL	258
#define	KEYWORD_GLOBAL	259
#define	KEYWORD_MEMBER	260
#define	KEYWORD_AND	261
#define	KEYWORD_OR	262
#define	KEYWORD_IF	263
#define	KEYWORD_ELSE	264
#define	KEYWORD_WHILE	265
#define	KEYWORD_FOR	266
#define	KEYWORD_FOREACH	267
#define	KEYWORD_IN	268
#define	KEYWORD_BREAK	269
#define	KEYWORD_CONTINUE	270
#define	KEYWORD_NULL	271
#define	KEYWORD_DOWHILE	272
#define	KEYWORD_RETURN	273
#define	KEYWORD_FUNCTION	274
#define	KEYWORD_TABLE	275
#define	KEYWORD_THIS	276
#define	KEYWORD_TRUE	277
#define	KEYWORD_FALSE	278
#define	KEYWORD_FORK	279
#define	KEYWORD_SWITCH	280
#define	KEYWORD_CASE	281
#define	KEYWORD_DEFAULT	282
#define	IDENTIFIER	283
#define	CONSTANT_HEX	284
#define	CONSTANT_BINARY	285
#define	CONSTANT_INT	286
#define	CONSTANT_CHAR	287
#define	CONSTANT_FLOAT	288
#define	CONSTANT_STRING	289
#define	SYMBOL_ASGN_BSR	290
#define	SYMBOL_ASGN_BSL	291
#define	SYMBOL_ASGN_ADD	292
#define	SYMBOL_ASGN_MINUS	293
#define	SYMBOL_ASGN_TIMES	294
#define	SYMBOL_ASGN_DIVIDE	295
#define	SYMBOL_ASGN_REM	296
#define	SYMBOL_ASGN_BAND	297
#define	SYMBOL_ASGN_BOR	298
#define	SYMBOL_ASGN_BXOR	299
#define	SYMBOL_RIGHT_SHIFT	300
#define	SYMBOL_LEFT_SHIFT	301
#define	SYMBOL_INC	302
#define	SYMBOL_DEC	303
#define	SYMBOL_LTE	304
#define	SYMBOL_GTE	305
#define	SYMBOL_EQ	306
#define	SYMBOL_NEQ	307
#define	TOKEN_ERROR	308



#define YYPARSER
#include "gmConfig.h"
#include "gmCodeTree.h"
#define YYSTYPE gmCodeTreeNode *

extern gmCodeTreeNode * g_codeTree;

#define GM_BISON_DEBUG
#ifdef GM_BISON_DEBUG
#define YYDEBUG 1
#define YYERROR_VERBOSE
#endif // GM_BISON_DEBUG

//
// HELPERS
//

void ATTACH(gmCodeTreeNode * &a_res, gmCodeTreeNode * a_a, gmCodeTreeNode * a_b)
{
  YYSTYPE t = a_a;
  if(t != NULL)
  {
    while(t->m_sibling != NULL)
    {
      t = t->m_sibling;
    }
    t->m_sibling = a_b;
    if(a_b) { a_b->m_parent = t; }
    a_res = a_a;
  }
  else
  {
    a_res = a_b;
  }
}

gmCodeTreeNode * CreateOperation(int a_subTypeType, gmCodeTreeNode * a_left = NULL, gmCodeTreeNode * a_right = NULL)
{
  gmCodeTreeNode * node = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_OPERATION, gmlineno, a_subTypeType);
  node->SetChild(0, a_left);
  node->SetChild(1, a_right);
  return node;
}

gmCodeTreeNode * CreateAsignExpression(int a_subTypeType, gmCodeTreeNode * a_left, gmCodeTreeNode * a_right)
{
  // we need to evaluate the complexety of the l-value... if it is a function call, index or dot to the left of a dot or index, we need to cache
  // into a hidden variable.

  // todo

  gmCodeTreeNode * opNode = CreateOperation(a_subTypeType, a_left, a_right);
  return CreateOperation(CTNOT_ASSIGN, a_left, opNode);
}


#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		291
#define	YYFLAG		-32768
#define	YYNTBASE	77

#define YYTRANSLATE(x) ((unsigned)(x) <= 308 ? yytranslate[x] : 120)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    75,     2,     2,     2,    73,    66,     2,    56,
    57,    71,    69,    76,    70,    58,    72,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    61,    59,    67,
    60,    68,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    62,     2,    63,    65,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    54,    64,    55,    74,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    13,    15,    17,    19,
    22,    26,    32,    39,    45,    52,    56,    60,    64,    70,
    77,    85,    87,    89,    91,    93,    96,   102,   110,   118,
   122,   125,   133,   137,   142,   146,   148,   151,   153,   158,
   162,   164,   167,   169,   171,   177,   183,   190,   198,   206,
   216,   219,   222,   225,   229,   231,   235,   239,   243,   247,
   251,   255,   259,   263,   267,   271,   275,   277,   280,   282,
   284,   288,   290,   294,   296,   300,   302,   306,   308,   312,
   314,   318,   322,   324,   328,   332,   336,   340,   342,   346,
   350,   352,   356,   360,   362,   366,   370,   374,   376,   379,
   382,   385,   387,   389,   391,   393,   395,   400,   404,   409,
   415,   422,   426,   428,   432,   436,   441,   444,   448,   453,
   459,   464,   466,   470,   472,   476,   478,   482,   484,   488,
   490,   493,   495,   497,   499,   501,   505,   507,   509,   511,
   513,   515,   517,   519,   521,   523,   525,   527
};

static const short yyrhs[] = {    78,
     0,    79,     0,    78,    79,     0,    85,     0,    83,     0,
    86,     0,    91,     0,    92,     0,    81,     0,    54,    55,
     0,    54,    78,    55,     0,    19,   117,    56,    57,    80,
     0,    19,   117,    56,   114,    57,    80,     0,    19,    82,
    56,    57,    80,     0,    19,    82,    56,   114,    57,    80,
     0,   117,    58,   117,     0,    82,    58,   117,     0,    84,
   117,    59,     0,    84,   117,    60,    95,    59,     0,    84,
    19,   117,    56,    57,    80,     0,    84,    19,   117,    56,
   114,    57,    80,     0,     3,     0,     4,     0,     5,     0,
    59,     0,    93,    59,     0,     8,    56,    95,    57,    80,
     0,     8,    56,    95,    57,    80,     9,    80,     0,     8,
    56,    95,    57,    80,     9,    86,     0,    24,   117,    80,
     0,    24,    80,     0,    25,    56,    95,    57,    54,    88,
    55,     0,    26,    89,    61,     0,    26,    89,    61,    80,
     0,    27,    61,    80,     0,    87,     0,    88,    87,     0,
    90,     0,    89,    62,    95,    63,     0,    89,    58,   117,
     0,   117,     0,    58,   117,     0,    21,     0,   118,     0,
    10,    56,    95,    57,    80,     0,    17,    56,    95,    57,
    80,     0,    11,    56,    85,    94,    57,    80,     0,    11,
    56,    85,    94,    93,    57,    80,     0,    12,    56,   117,
    13,    95,    57,    80,     0,    12,    56,   117,     6,   117,
    13,    95,    57,    80,     0,    15,    59,     0,    14,    59,
     0,    18,    59,     0,    18,    95,    59,     0,    96,     0,
   108,    60,    96,     0,   108,    35,    96,     0,   108,    36,
    96,     0,   108,    37,    96,     0,   108,    38,    96,     0,
   108,    39,    96,     0,   108,    40,    96,     0,   108,    41,
    96,     0,   108,    42,    96,     0,   108,    43,    96,     0,
   108,    44,    96,     0,    59,     0,    95,    59,     0,    96,
     0,    97,     0,    96,     7,    97,     0,    98,     0,    97,
     6,    98,     0,    99,     0,    98,    64,    99,     0,   100,
     0,    99,    65,   100,     0,   101,     0,   100,    66,   101,
     0,   102,     0,   101,    51,   102,     0,   101,    52,   102,
     0,   103,     0,   102,    67,   103,     0,   102,    68,   103,
     0,   102,    49,   103,     0,   102,    50,   103,     0,   104,
     0,   103,    46,   104,     0,   103,    45,   104,     0,   105,
     0,   104,    69,   105,     0,   104,    70,   105,     0,   106,
     0,   105,    71,   106,     0,   105,    72,   106,     0,   105,
    73,   106,     0,   108,     0,    47,   106,     0,    48,   106,
     0,   107,   106,     0,    69,     0,    70,     0,    74,     0,
    75,     0,   116,     0,   108,    62,    95,    63,     0,   108,
    56,    57,     0,   108,    56,   109,    57,     0,   108,    61,
   117,    56,    57,     0,   108,    61,   117,    56,   109,    57,
     0,   108,    58,   117,     0,    95,     0,   109,    76,    95,
     0,    20,    56,    57,     0,    20,    56,   112,    57,     0,
    54,    55,     0,    54,   112,    55,     0,    54,   112,    76,
    55,     0,    19,    56,   114,    57,    80,     0,    19,    56,
    57,    80,     0,   113,     0,   112,    76,   113,     0,    95,
     0,   117,    60,    95,     0,   115,     0,   114,    76,   115,
     0,   117,     0,   117,    60,    95,     0,   117,     0,    58,
   117,     0,    21,     0,   118,     0,   110,     0,   111,     0,
    56,    95,    57,     0,    28,     0,    29,     0,    30,     0,
    31,     0,    22,     0,    23,     0,    32,     0,    33,     0,
   119,     0,    16,     0,    34,     0,   119,    34,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   128,   135,   139,   146,   150,   154,   158,   162,   166,   173,
   177,   186,   197,   209,   217,   229,   233,   240,   245,   251,
   260,   273,   277,   281,   287,   291,   298,   304,   311,   318,
   324,   329,   338,   343,   349,   357,   361,   368,   372,   376,
   383,   387,   392,   396,   403,   409,   415,   422,   430,   437,
   448,   452,   456,   460,   468,   476,   480,   484,   488,   492,
   496,   500,   504,   508,   512,   516,   524,   528,   535,   542,
   546,   553,   557,   564,   568,   576,   580,   588,   592,   600,
   604,   608,   615,   619,   623,   627,   631,   638,   642,   647,
   655,   659,   664,   672,   676,   681,   686,   694,   698,   702,
   706,   715,   719,   723,   727,   734,   738,   742,   747,   753,
   759,   766,   773,   777,   784,   788,   793,   797,   802,   810,
   816,   824,   828,   835,   839,   846,   850,   857,   862,   871,
   875,   880,   884,   888,   892,   896,   903,   912,   917,   922,
   927,   932,   937,   983,   988,   992,  1000,  1014
};

static const char * const yytname[] = {   "$","error","$undefined.","KEYWORD_LOCAL",
"KEYWORD_GLOBAL","KEYWORD_MEMBER","KEYWORD_AND","KEYWORD_OR","KEYWORD_IF","KEYWORD_ELSE",
"KEYWORD_WHILE","KEYWORD_FOR","KEYWORD_FOREACH","KEYWORD_IN","KEYWORD_BREAK",
"KEYWORD_CONTINUE","KEYWORD_NULL","KEYWORD_DOWHILE","KEYWORD_RETURN","KEYWORD_FUNCTION",
"KEYWORD_TABLE","KEYWORD_THIS","KEYWORD_TRUE","KEYWORD_FALSE","KEYWORD_FORK",
"KEYWORD_SWITCH","KEYWORD_CASE","KEYWORD_DEFAULT","IDENTIFIER","CONSTANT_HEX",
"CONSTANT_BINARY","CONSTANT_INT","CONSTANT_CHAR","CONSTANT_FLOAT","CONSTANT_STRING",
"SYMBOL_ASGN_BSR","SYMBOL_ASGN_BSL","SYMBOL_ASGN_ADD","SYMBOL_ASGN_MINUS","SYMBOL_ASGN_TIMES",
"SYMBOL_ASGN_DIVIDE","SYMBOL_ASGN_REM","SYMBOL_ASGN_BAND","SYMBOL_ASGN_BOR",
"SYMBOL_ASGN_BXOR","SYMBOL_RIGHT_SHIFT","SYMBOL_LEFT_SHIFT","SYMBOL_INC","SYMBOL_DEC",
"SYMBOL_LTE","SYMBOL_GTE","SYMBOL_EQ","SYMBOL_NEQ","TOKEN_ERROR","'{'","'}'",
"'('","')'","'.'","';'","'='","':'","'['","']'","'|'","'^'","'&'","'<'","'>'",
"'+'","'-'","'*'","'/'","'%'","'~'","'!'","','","program","statement_list","statement",
"compound_statement","function_statement","tablemember_expression","var_statement",
"var_type","expression_statement","selection_statement","case_selection_statement",
"case_selection_statement_list","postfix_case_expression","case_expression",
"iteration_statement","jump_statement","assignment_expression","constant_expression_statement",
"constant_expression","logical_or_expression","logical_and_expression","inclusive_or_expression",
"exclusive_or_expression","and_expression","equality_expression","relational_expression",
"shift_expression","additive_expression","multiplicative_expression","unary_expression",
"unary_operator","postfix_expression","argument_expression_list","table_constructor",
"function_constructor","field_list","field","parameter_list","parameter","primary_expression",
"identifier","constant","constant_string_list",""
};
#endif

static const short yyr1[] = {     0,
    77,    78,    78,    79,    79,    79,    79,    79,    79,    80,
    80,    81,    81,    81,    81,    82,    82,    83,    83,    83,
    83,    84,    84,    84,    85,    85,    86,    86,    86,    86,
    86,    86,    87,    87,    87,    88,    88,    89,    89,    89,
    90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
    92,    92,    92,    92,    93,    93,    93,    93,    93,    93,
    93,    93,    93,    93,    93,    93,    94,    94,    95,    96,
    96,    97,    97,    98,    98,    99,    99,   100,   100,   101,
   101,   101,   102,   102,   102,   102,   102,   103,   103,   103,
   104,   104,   104,   105,   105,   105,   105,   106,   106,   106,
   106,   107,   107,   107,   107,   108,   108,   108,   108,   108,
   108,   108,   109,   109,   110,   110,   110,   110,   110,   111,
   111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
   116,   116,   116,   116,   116,   116,   117,   118,   118,   118,
   118,   118,   118,   118,   118,   118,   119,   119
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     1,     1,     1,     1,     2,
     3,     5,     6,     5,     6,     3,     3,     3,     5,     6,
     7,     1,     1,     1,     1,     2,     5,     7,     7,     3,
     2,     7,     3,     4,     3,     1,     2,     1,     4,     3,
     1,     2,     1,     1,     5,     5,     6,     7,     7,     9,
     2,     2,     2,     3,     1,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     1,     2,     1,     1,
     3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
     3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
     1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
     2,     1,     1,     1,     1,     1,     4,     3,     4,     5,
     6,     3,     1,     3,     3,     4,     2,     3,     4,     5,
     4,     1,     3,     1,     3,     1,     3,     1,     3,     1,
     2,     1,     1,     1,     1,     3,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     2
};

static const short yydefact[] = {     0,
    22,    23,    24,     0,     0,     0,     0,     0,     0,   146,
     0,     0,     0,     0,   132,   141,   142,     0,     0,   137,
   138,   139,   140,   143,   144,   147,     0,     0,     0,     0,
     0,    25,   102,   103,   104,   105,     1,     2,     9,     5,
     0,     4,     6,     7,     8,     0,    55,    70,    72,    74,
    76,    78,    80,    83,    88,    91,    94,     0,    98,   134,
   135,   106,   130,   133,   145,     0,     0,     0,     0,    52,
    51,     0,     0,    53,     0,    69,    98,     0,     0,     0,
     0,     0,    31,     0,     0,    99,   100,   117,   124,     0,
   122,   130,     0,   131,     3,     0,     0,    26,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   101,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   148,     0,     0,     0,     0,     0,    54,     0,
     0,   126,   128,     0,     0,     0,     0,   115,     0,    10,
     0,    30,     0,   118,     0,     0,   136,     0,    18,     0,
    71,    73,    75,    77,    79,    81,    82,    86,    87,    84,
    85,    90,    89,    92,    93,    95,    96,    97,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,   108,   113,
     0,   112,    56,     0,     0,     0,     0,    67,     0,     0,
     0,     0,     0,   121,     0,     0,     0,     0,     0,    17,
     0,     0,    16,   116,     0,    11,     0,   119,   123,   125,
     0,     0,   109,     0,     0,   107,    27,    45,     0,     0,
    68,     0,     0,    46,   120,   127,   129,    14,     0,    12,
     0,     0,     0,     0,    19,   114,   110,     0,     0,    47,
     0,     0,     0,    15,    13,     0,     0,    36,     0,    20,
     0,   111,    28,    29,    48,     0,    49,    43,     0,     0,
    38,    41,    44,     0,    32,    37,    21,     0,    42,     0,
    33,     0,    35,    50,    40,    34,     0,    39,     0,     0,
     0
};

static const short yydefgoto[] = {   289,
    37,    38,    83,    39,    79,    40,    41,    42,    43,   258,
   259,   270,   271,    44,    45,    46,   199,    89,    76,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    77,   191,    60,    61,    90,    91,   141,   142,    62,    63,
    64,    65
};

static const short yypact[] = {   399,
-32768,-32768,-32768,   -26,     7,    12,    46,    45,    53,-32768,
    59,   456,   -20,    62,-32768,-32768,-32768,    -7,    67,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   969,   969,   513,   969,
    98,-32768,-32768,-32768,-32768,-32768,   399,-32768,-32768,-32768,
    42,-32768,-32768,-32768,-32768,    71,   124,   126,    69,    70,
    68,    27,   -18,    55,    36,    22,-32768,   969,   514,-32768,
-32768,-32768,-32768,-32768,   102,   969,   969,   570,    98,-32768,
-32768,   969,    81,-32768,    79,   124,    24,   -15,   -34,     8,
   627,   263,-32768,    85,   969,-32768,-32768,-32768,-32768,   -35,
-32768,    86,    88,-32768,-32768,    98,    49,-32768,   969,   969,
   969,   969,   969,   969,   969,   969,   969,   969,   969,   969,
   969,   969,   969,   969,   969,   969,-32768,   969,   969,   969,
   969,   969,   969,   969,   969,   969,   969,   684,    98,   969,
    98,   969,-32768,    90,    92,   741,    10,    93,-32768,    85,
   -31,-32768,   106,   -13,    98,   -11,    98,-32768,   -23,-32768,
   331,-32768,   110,-32768,   798,   969,-32768,   112,-32768,   969,
   126,    69,    70,    68,    27,   -18,   -18,    55,    55,    55,
    55,    36,    36,    22,    22,-32768,-32768,-32768,   124,   124,
   124,   124,   124,   124,   124,   124,   124,   124,-32768,-32768,
   -17,-32768,   124,   113,   108,    85,    85,-32768,   855,   114,
    98,   969,    85,-32768,    85,    98,   969,    85,   -14,-32768,
    85,    -5,-32768,-32768,   969,-32768,   120,-32768,-32768,-32768,
    -9,   117,-32768,   969,   912,-32768,   168,-32768,    85,   122,
-32768,   167,   125,-32768,-32768,-32768,-32768,-32768,    85,-32768,
    85,    84,    85,    -1,-32768,-32768,-32768,     0,     4,-32768,
    85,   969,    85,-32768,-32768,  1019,   123,-32768,   -16,-32768,
    85,-32768,-32768,-32768,-32768,   128,-32768,-32768,    98,    26,
-32768,-32768,-32768,    85,-32768,-32768,-32768,    85,-32768,    98,
    85,   969,-32768,-32768,-32768,-32768,   118,-32768,   183,   187,
-32768
};

static const short yypgoto[] = {-32768,
   107,   -32,   -33,-32768,-32768,-32768,-32768,   130,   -61,   -68,
-32768,-32768,-32768,-32768,-32768,    -6,-32768,   -12,    35,    95,
    99,    91,   101,   104,     9,   -10,    11,    16,   -25,-32768,
     1,   -24,-32768,-32768,   133,  -148,  -140,    -2,-32768,    -4,
   -51,-32768
};


#define	YYLAST		1077


static const short yytable[] = {    75,
    59,    86,    87,   209,    95,   212,   219,    20,    80,   256,
   257,     4,    20,    84,    20,   201,    20,    93,    20,   154,
    20,   144,   202,   145,    92,   205,    94,    18,    19,    66,
   106,   107,   117,   214,    47,    78,    97,    59,   275,   223,
   155,   140,   239,   208,   206,   211,    82,   243,   108,   109,
   152,   241,   215,   134,   135,   261,   262,    82,   224,   138,
    96,   206,    67,   146,   137,   147,   219,    68,    59,    20,
   206,    47,   153,   143,   206,   224,    92,   104,   105,   128,
   244,   129,    59,   280,   131,   132,   281,   282,   176,   177,
   178,   158,   114,   115,   116,   168,   169,   170,   171,   110,
   111,    69,    47,    70,   112,   113,   204,   159,   160,   256,
   257,    71,   166,   167,    72,   190,    47,    81,    95,   195,
   172,   173,    85,   200,   192,    20,   194,   174,   175,    98,
    99,   100,   101,   103,   102,   133,    78,   139,    82,   143,
   210,   143,   213,   220,   157,   156,   196,   222,   197,   203,
    92,    59,   179,   180,   181,   182,   183,   184,   185,   186,
   187,   188,   227,   228,   193,   207,   217,   221,   225,   234,
   226,   235,   231,   242,   238,   245,   249,   240,   251,   252,
   288,   253,   290,   274,   278,    47,   291,   264,   151,   233,
   276,   163,   230,   161,   237,   250,   232,   136,   162,    59,
   248,   143,   164,   236,   273,   254,   165,   255,     0,   260,
    92,   246,   190,   149,     0,   263,   143,   265,     0,   267,
     0,     0,     0,     0,     0,     0,     0,   277,     0,     0,
     0,     0,     0,    47,     0,     0,     0,     0,     0,   266,
   283,     0,     0,     0,   284,     0,     0,   286,     0,     0,
     0,   272,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   279,     1,     2,     3,     0,   287,
     4,     0,     5,     6,     7,   285,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
    20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
    28,     0,     0,     0,     0,     0,    29,   150,    30,     0,
    31,    32,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    33,    34,     1,     2,     3,    35,    36,     4,     0,
     5,     6,     7,     0,     8,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,     0,     0,    20,    21,
    22,    23,    24,    25,    26,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
     0,     0,     0,     0,    29,   216,    30,     0,    31,    32,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
    34,     1,     2,     3,    35,    36,     4,     0,     5,     6,
     7,     0,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,     0,     0,    20,    21,    22,    23,
    24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    27,    28,     0,     0,     0,
     0,     0,    29,     0,    30,     0,    31,    32,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    33,    34,     0,
     0,    10,    35,    36,    73,    14,    15,    16,    17,     0,
     0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    27,    28,     0,     0,     0,     0,     0,    29,
     0,    30,     0,    31,    74,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    33,    34,     0,     0,    10,    35,
    36,    73,    14,    15,    16,    17,     0,     0,     0,     0,
    20,    21,    22,    23,    24,    25,    26,     0,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,     0,    27,
    28,     0,     0,     0,     0,     0,    29,    88,    30,   128,
    31,   129,     0,   130,   131,   132,     0,     0,     0,     0,
     0,    33,    34,     0,     0,    10,    35,    36,    73,    14,
    15,    16,    17,     0,     0,     0,     0,    20,    21,    22,
    23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    27,    28,     0,     0,
     0,     0,     0,    29,     0,    30,     0,    31,    32,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
     0,     0,    10,    35,    36,    73,    14,    15,    16,    17,
     0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
    26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    27,    28,     0,     0,     0,     0,     0,
    29,     0,    30,   148,    31,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    33,    34,     0,     0,    10,
    35,    36,    73,    14,    15,    16,    17,     0,     0,     0,
     0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    27,    28,     0,     0,     0,     0,     0,    29,     0,    30,
   189,    31,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    33,    34,     0,     0,    10,    35,    36,    73,
    14,    15,    16,    17,     0,     0,     0,     0,    20,    21,
    22,    23,    24,    25,    26,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
     0,     0,     0,     0,    29,     0,    30,     0,    31,   198,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
    34,     0,     0,    10,    35,    36,    73,    14,    15,    16,
    17,     0,     0,     0,     0,    20,    21,    22,    23,    24,
    25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
     0,    29,   218,    30,     0,    31,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    33,    34,     0,     0,
    10,    35,    36,    73,    14,    15,    16,    17,     0,     0,
     0,     0,    20,    21,    22,    23,    24,    25,    26,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    27,    28,     0,     0,     0,     0,     0,    29,     0,
    30,   229,    31,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    33,    34,     0,     0,    10,    35,    36,
    73,    14,    15,    16,    17,     0,     0,     0,     0,    20,
    21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
     0,     0,     0,     0,     0,    29,     0,    30,   247,    31,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    33,    34,     0,     0,    10,    35,    36,    73,    14,    15,
    16,    17,     0,     0,     0,     0,    20,    21,    22,    23,
    24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    27,    28,     0,     0,     0,
     0,     0,    29,     0,    30,     0,    31,     0,     0,     0,
     0,     0,     0,     0,    10,     0,     0,    33,    34,   268,
    16,    17,    35,    36,     0,     0,    20,    21,    22,    23,
    24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   269
};

static const short yycheck[] = {    12,
     0,    27,    28,   144,    37,   146,   155,    28,    13,    26,
    27,     8,    28,    18,    28,     6,    28,    30,    28,    55,
    28,    56,    13,    58,    29,    57,    31,    24,    25,    56,
    49,    50,    58,    57,     0,    56,    41,    37,    55,    57,
    76,    57,    57,    57,    76,    57,    54,    57,    67,    68,
    84,    57,    76,    66,    67,    57,    57,    54,    76,    72,
    19,    76,    56,    56,    69,    58,   215,    56,    68,    28,
    76,    37,    85,    78,    76,    76,    81,    51,    52,    56,
   221,    58,    82,    58,    61,    62,    61,    62,   114,   115,
   116,    96,    71,    72,    73,   106,   107,   108,   109,    45,
    46,    56,    68,    59,    69,    70,   140,    59,    60,    26,
    27,    59,   104,   105,    56,   128,    82,    56,   151,   132,
   110,   111,    56,   136,   129,    28,   131,   112,   113,    59,
     7,     6,    64,    66,    65,    34,    56,    59,    54,   144,
   145,   146,   147,   156,    57,    60,    57,   160,    57,    57,
   155,   151,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   196,   197,   130,    60,    57,    56,    56,   203,
    63,   205,    59,    54,   208,    59,     9,   211,    57,    13,
    63,    57,     0,    61,    57,   151,     0,   249,    82,   202,
   259,   101,   199,    99,   207,   229,   201,    68,   100,   199,
   225,   206,   102,   206,   256,   239,   103,   241,    -1,   243,
   215,   224,   225,    81,    -1,   249,   221,   251,    -1,   253,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,   252,
   274,    -1,    -1,    -1,   278,    -1,    -1,   281,    -1,    -1,
    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   269,     3,     4,     5,    -1,   282,
     8,    -1,    10,    11,    12,   280,    14,    15,    16,    17,
    18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
    28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
    48,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,
    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    69,    70,     3,     4,     5,    74,    75,     8,    -1,
    10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
    20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
    -1,    -1,    -1,    -1,    54,    55,    56,    -1,    58,    59,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
    70,     3,     4,     5,    74,    75,     8,    -1,    10,    11,
    12,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
    -1,    -1,    54,    -1,    56,    -1,    58,    59,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
    -1,    16,    74,    75,    19,    20,    21,    22,    23,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    54,
    -1,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    16,    74,
    75,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
    28,    29,    30,    31,    32,    33,    34,    -1,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    -1,    47,
    48,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    56,
    58,    58,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,
    -1,    69,    70,    -1,    -1,    16,    74,    75,    19,    20,
    21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
    -1,    -1,    16,    74,    75,    19,    20,    21,    22,    23,
    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
    54,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    16,
    74,    75,    19,    20,    21,    22,    23,    -1,    -1,    -1,
    -1,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    47,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,
    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    69,    70,    -1,    -1,    16,    74,    75,    19,
    20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
    -1,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
    70,    -1,    -1,    16,    74,    75,    19,    20,    21,    22,
    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
    -1,    54,    55,    56,    -1,    58,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,
    16,    74,    75,    19,    20,    21,    22,    23,    -1,    -1,
    -1,    -1,    28,    29,    30,    31,    32,    33,    34,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,
    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    69,    70,    -1,    -1,    16,    74,    75,
    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,    57,    58,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    69,    70,    -1,    -1,    16,    74,    75,    19,    20,    21,
    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
    -1,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    16,    -1,    -1,    69,    70,    21,
    22,    23,    74,    75,    -1,    -1,    28,    29,    30,    31,
    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    58
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */


/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        return(0)
#define YYABORT         return(1)
#define YYERROR         goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (yychar == YYEMPTY && yylen == 1)                          \
    { yychar = (token), yylval = (value);                       \
      yychar1 = YYTRANSLATE (yychar);                           \
      YYPOPSTACK;                                               \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    { yyerror ("syntax error: cannot back up"); YYERROR; }      \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YYPURE
#define YYLEX           yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX           yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX           yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX           yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX           yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int     yychar;                 /*  the lookahead symbol                */
YYSTYPE yylval;                 /*  the semantic value of the           */
                                /*  lookahead symbol                    */

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;                 /*  location data for the lookahead     */
                                /*  symbol                              */
#endif

int yynerrs;                    /*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)      __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;              /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YYSTYPE yyvsa[YYINITDEPTH];   /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;        /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];   /*  the location stack                  */
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval = 0;            /*  the variable used to return         */ // _GD_ '= 0' for VS2017 'error C4703: potentially uninitialized local pointer variable'
                                /*  semantic values from the action     */
                                /*  routines                            */

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;             /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = (short) yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = (int)(yyssp - yyss + 1); // _GD_ cast for 64bit build

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
         the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
         but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
                 &yyss1, size * sizeof (*yyssp),
                 &yyvs1, size * sizeof (*yyvsp),
                 &yyls1, size * sizeof (*yylsp),
                 &yystacksize);
#else
      yyoverflow("parser stack overflow",
                 &yyss1, size * sizeof (*yyssp),
                 &yyvs1, size * sizeof (*yyvsp),
                 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
        {
          yyerror("parser stack overflow");
          return 2;
        }
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
        yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
        fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
        YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
        fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)              /* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;           /* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
        fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
        {
          fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
          /* Give the individual parser a way to print the precise meaning
             of a token, for further debugging info.  */
#ifdef YYPRINT
          YYPRINT (stderr, yychar, yylval);
#endif
          fprintf (stderr, ")\n");
        }
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
               yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
        fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
{
      g_codeTree = yyvsp[0];
    ;
    break;}
case 2:
{
      yyval = yyvsp[0];
    ;
    break;}
case 3:
{
      ATTACH(yyval, yyvsp[-1], yyvsp[0]);
    ;
    break;}
case 4:
{
      yyval = yyvsp[0];
    ;
    break;}
case 5:
{
      yyval = yyvsp[0];
    ;
    break;}
case 6:
{
      yyval = yyvsp[0];
    ;
    break;}
case 7:
{
      yyval = yyvsp[0];
    ;
    break;}
case 8:
{
      yyval = yyvsp[0];
    ;
    break;}
case 9:
{
	  yyval = yyvsp[0];
	;
    break;}
case 10:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_COMPOUND, gmlineno);
    ;
    break;}
case 11:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_COMPOUND, gmlineno);
      yyval->SetChild(0, yyvsp[-1]);
    ;
    break;}
case 12:
{
      gmCodeTreeNode* func = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_FUNCTION, gmlineno);
      func->SetChild(1, yyvsp[0]);
      

      yyval = gmCodeTreeNode::Create(CTNT_DECLARATION, CTNDT_VARIABLE, gmlineno, (int)GMMACHINE_DEFAULT_FUNCTION);
      yyval->SetChild(0, yyvsp[-3]);
      ATTACH(yyval, yyval, CreateOperation(CTNOT_ASSIGN, yyvsp[-3], func));
   ;
    break;}
case 13:
{
      gmCodeTreeNode* func = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_FUNCTION, gmlineno);
      func->SetChild(0, yyvsp[-2]);
      func->SetChild(1, yyvsp[0]);
      

      yyval = gmCodeTreeNode::Create(CTNT_DECLARATION, CTNDT_VARIABLE, gmlineno, (int)GMMACHINE_DEFAULT_FUNCTION);
      yyval->SetChild(0, yyvsp[-4]);
      ATTACH(yyval, yyval, CreateOperation(CTNOT_ASSIGN, yyvsp[-4], func));
   ;
    break;}
case 14:
{
      gmCodeTreeNode* func = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_FUNCTION, gmlineno);
      func->SetChild(1, yyvsp[0]);
      
      ATTACH(yyval, yyval, CreateOperation(CTNOT_ASSIGN, yyvsp[-3], func));
   ;
    break;}
case 15:
{
      gmCodeTreeNode* func = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_FUNCTION, gmlineno);
      func->SetChild(0, yyvsp[-2]);
      func->SetChild(1, yyvsp[0]);
      
      ATTACH(yyval, yyval, CreateOperation(CTNOT_ASSIGN, yyvsp[-4], func));
   ;
    break;}
case 16:
{
      yyval = CreateOperation(CTNOT_DOT, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 17:
{
      yyval = CreateOperation(CTNOT_DOT, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 18:
{
      yyval = gmCodeTreeNode::Create(CTNT_DECLARATION, CTNDT_VARIABLE, gmlineno, (int)(gmptr) yyvsp[-2]);
      yyval->SetChild(0, yyvsp[-1]);
    ;
    break;}
case 19:
{
      yyval = gmCodeTreeNode::Create(CTNT_DECLARATION, CTNDT_VARIABLE, gmlineno, (int)(gmptr) yyvsp[-4]);
      yyval->SetChild(0, yyvsp[-3]);
      ATTACH(yyval, yyval, CreateOperation(CTNOT_ASSIGN, yyvsp[-3], yyvsp[-1]));
    ;
    break;}
case 20:
{
      gmCodeTreeNode* func = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_FUNCTION, gmlineno);
      func->SetChild(1, yyvsp[0]);

      yyval = gmCodeTreeNode::Create(CTNT_DECLARATION, CTNDT_VARIABLE, gmlineno, (int)(gmptr) yyvsp[-5]);
      yyval->SetChild(0, yyvsp[-3]);
      ATTACH(yyval, yyval, CreateOperation(CTNOT_ASSIGN, yyvsp[-3], func));
    ;
    break;}
case 21:
{
      gmCodeTreeNode* func = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_FUNCTION, gmlineno);
      func->SetChild(0, yyvsp[-2]);
      func->SetChild(1, yyvsp[0]);

      yyval = gmCodeTreeNode::Create(CTNT_DECLARATION, CTNDT_VARIABLE, gmlineno, (int)(gmptr) yyvsp[-6]);
      yyval->SetChild(0, yyvsp[-4]);
      ATTACH(yyval, yyval, CreateOperation(CTNOT_ASSIGN, yyvsp[-4], func));
    ;
    break;}
case 22:
{
      yyval = (YYSTYPE) CTVT_LOCAL;
    ;
    break;}
case 23:
{
      yyval = (YYSTYPE) CTVT_GLOBAL;
    ;
    break;}
case 24:
{
      yyval = (YYSTYPE) CTVT_MEMBER;
    ;
    break;}
case 25:
{
      yyval = NULL;
    ;
    break;}
case 26:
{
      yyval = yyvsp[-1];
    ;
    break;}
case 27:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_IF, (yyvsp[-2]) ? yyvsp[-2]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
      yyval->SetChild(1, yyvsp[0]);
    ;
    break;}
case 28:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_IF, (yyvsp[-4]) ? yyvsp[-4]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-4]);
      yyval->SetChild(1, yyvsp[-2]);
      yyval->SetChild(2, yyvsp[0]);
    ;
    break;}
case 29:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_IF, (yyvsp[-4]) ? yyvsp[-4]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-4]);
      yyval->SetChild(1, yyvsp[-2]);
      yyval->SetChild(2, yyvsp[0]);
    ;
    break;}
case 30:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_FORK, (yyvsp[-1]) ? yyvsp[-1]->m_lineNumber : gmlineno );
      yyval->SetChild(0, yyvsp[0] );
      yyval->SetChild(1, yyvsp[-1] );
    ;
    break;}
case 31:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_FORK, (yyvsp[0]) ? yyvsp[0]->m_lineNumber : gmlineno );
      yyval->SetChild(0, yyvsp[0] );
    ;
    break;}
case 32:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_SWITCH, (yyvsp[-4]) ? yyvsp[-4]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-4]);
      yyval->SetChild(1, yyvsp[-1]);
    ;
    break;}
case 33:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_CASE, (yyvsp[-1]) ? yyvsp[-1]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-1]);
    ;
    break;}
case 34:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_CASE, (yyvsp[-2]) ? yyvsp[-2]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
      yyval->SetChild(1, yyvsp[0]);
    ;
    break;}
case 35:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_DEFAULT, (yyvsp[0]) ? yyvsp[0]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[0]);
    ;
    break;}
case 36:
{
      yyval = yyvsp[0];
    ;
    break;}
case 37:
{
      ATTACH(yyval, yyvsp[-1], yyvsp[0]);
    ;
    break;}
case 38:
{
      yyval = yyvsp[0];
    ;
    break;}
case 39:
{
      yyval = CreateOperation(CTNOT_ARRAY_INDEX, yyvsp[-3], yyvsp[-1]);
    ;
    break;}
case 40:
{
      yyval = CreateOperation(CTNOT_DOT, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 41:
{
      yyval = yyvsp[0];
    ;
    break;}
case 42:
{
      yyval = yyvsp[0];
      yyval->m_flags |= gmCodeTreeNode::CTN_MEMBER;
    ;
    break;}
case 43:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_THIS, gmlineno);
    ;
    break;}
case 44:
{
      yyval = yyvsp[0];
    ;
    break;}
case 45:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_WHILE, (yyvsp[-2]) ? yyvsp[-2]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
      yyval->SetChild(1, yyvsp[0]);
    ;
    break;}
case 46:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_DOWHILE, (yyvsp[-2]) ? yyvsp[-2]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
      yyval->SetChild(1, yyvsp[0]);
    ;
    break;}
case 47:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_FOR, (yyvsp[-3]) ? yyvsp[-3]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-3]);
      yyval->SetChild(1, yyvsp[-2]);
      yyval->SetChild(3, yyvsp[0]);
    ;
    break;}
case 48:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_FOR, (yyvsp[-4]) ? yyvsp[-4]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-4]);
      yyval->SetChild(1, yyvsp[-3]);
      yyval->SetChild(2, yyvsp[-2]);
      yyval->SetChild(3, yyvsp[0]);
    ;
    break;}
case 49:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_FOREACH, (yyvsp[-2]) ? yyvsp[-2]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
      yyval->SetChild(1, yyvsp[-4]);
      yyval->SetChild(3, yyvsp[0]);
    ;
    break;}
case 50:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_FOREACH, (yyvsp[-2]) ? yyvsp[-2]->m_lineNumber : gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
      yyval->SetChild(1, yyvsp[-4]);
      yyval->SetChild(2, yyvsp[-6]);
      yyval->SetChild(3, yyvsp[0]);
    ;
    break;}
case 51:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_CONTINUE, gmlineno);
    ;
    break;}
case 52:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_BREAK, gmlineno);
    ;
    break;}
case 53:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_RETURN, gmlineno);
    ;
    break;}
case 54:
{
      yyval = gmCodeTreeNode::Create(CTNT_STATEMENT, CTNST_RETURN, gmlineno);
      yyval->SetChild(0, yyvsp[-1]);
    ;
    break;}
case 55:
{
      yyval = yyvsp[0];
      if(yyval)
      {
        yyval->m_flags |= gmCodeTreeNode::CTN_POP;
      }
    ;
    break;}
case 56:
{
      yyval = CreateOperation(CTNOT_ASSIGN, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 57:
{
      yyval = CreateAsignExpression(CTNOT_SHIFT_RIGHT, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 58:
{
      yyval = CreateAsignExpression(CTNOT_SHIFT_LEFT, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 59:
{
      yyval = CreateAsignExpression(CTNOT_ADD, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 60:
{
      yyval = CreateAsignExpression(CTNOT_MINUS, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 61:
{
      yyval = CreateAsignExpression(CTNOT_TIMES, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 62:
{
      yyval = CreateAsignExpression(CTNOT_DIVIDE, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 63:
{
      yyval = CreateAsignExpression(CTNOT_REM, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 64:
{
      yyval = CreateAsignExpression(CTNOT_BIT_AND, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 65:
{
      yyval = CreateAsignExpression(CTNOT_BIT_OR, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 66:
{
      yyval = CreateAsignExpression(CTNOT_BIT_XOR, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 67:
{
      yyval = NULL;
    ;
    break;}
case 68:
{
      yyval = yyvsp[-1];
    ;
    break;}
case 69:
{
      yyval = yyvsp[0];
    ;
    break;}
case 70:
{
      yyval = yyvsp[0];
    ;
    break;}
case 71:
{
      yyval = CreateOperation(CTNOT_OR, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 72:
{
      yyval = yyvsp[0];
    ;
    break;}
case 73:
{
      yyval = CreateOperation(CTNOT_AND, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 74:
{
      yyval = yyvsp[0];
    ;
    break;}
case 75:
{
      yyval = CreateOperation(CTNOT_BIT_OR, yyvsp[-2], yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 76:
{
      yyval = yyvsp[0];
    ;
    break;}
case 77:
{
      yyval = CreateOperation(CTNOT_BIT_XOR, yyvsp[-2], yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 78:
{
      yyval = yyvsp[0];
    ;
    break;}
case 79:
{
      yyval = CreateOperation(CTNOT_BIT_AND, yyvsp[-2], yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 80:
{
      yyval = yyvsp[0];
    ;
    break;}
case 81:
{
      yyval = CreateOperation(CTNOT_EQ, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 82:
{
      yyval = CreateOperation(CTNOT_NEQ, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 83:
{
      yyval = yyvsp[0];
    ;
    break;}
case 84:
{
      yyval = CreateOperation(CTNOT_LT, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 85:
{
      yyval = CreateOperation(CTNOT_GT, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 86:
{
      yyval = CreateOperation(CTNOT_LTE, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 87:
{
      yyval = CreateOperation(CTNOT_GTE, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 88:
{
      yyval = yyvsp[0];
    ;
    break;}
case 89:
{
      yyval = CreateOperation(CTNOT_SHIFT_LEFT, yyvsp[-2], yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 90:
{
      yyval = CreateOperation(CTNOT_SHIFT_RIGHT, yyvsp[-2], yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 91:
{
      yyval = yyvsp[0];
    ;
    break;}
case 92:
{
      yyval = CreateOperation(CTNOT_ADD, yyvsp[-2], yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 93:
{
      yyval = CreateOperation(CTNOT_MINUS, yyvsp[-2], yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 94:
{
      yyval = yyvsp[0];
    ;
    break;}
case 95:
{
      yyval = CreateOperation(CTNOT_TIMES, yyvsp[-2], yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 96:
{
      yyval = CreateOperation(CTNOT_DIVIDE, yyvsp[-2], yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 97:
{
      yyval = CreateOperation(CTNOT_REM, yyvsp[-2], yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 98:
{
      yyval = yyvsp[0];
    ;
    break;}
case 99:
{
      yyval = CreateOperation(CTNOT_PRE_INC, yyvsp[0]);
    ;
    break;}
case 100:
{
      yyval = CreateOperation(CTNOT_PRE_DEC, yyvsp[0]);
    ;
    break;}
case 101:
{
      yyval = yyvsp[-1];
      yyval->SetChild(0, yyvsp[0]);
      yyval->ConstantFold();
    ;
    break;}
case 102:
{
      yyval = CreateOperation(CTNOT_UNARY_PLUS);
    ;
    break;}
case 103:
{
      yyval = CreateOperation(CTNOT_UNARY_MINUS);
    ;
    break;}
case 104:
{
      yyval = CreateOperation(CTNOT_UNARY_COMPLEMENT);
    ;
    break;}
case 105:
{
      yyval = CreateOperation(CTNOT_UNARY_NOT);
    ;
    break;}
case 106:
{
      yyval = yyvsp[0];
    ;
    break;}
case 107:
{
      yyval = CreateOperation(CTNOT_ARRAY_INDEX, yyvsp[-3], yyvsp[-1]);
    ;
    break;}
case 108:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CALL, gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
    ;
    break;}
case 109:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CALL, gmlineno);
      yyval->SetChild(0, yyvsp[-3]);
      yyval->SetChild(1, yyvsp[-1]);
    ;
    break;}
case 110:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CALL, gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
      yyval->SetChild(2, yyvsp[-4]);
    ;
    break;}
case 111:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CALL, gmlineno);
      yyval->SetChild(0, yyvsp[-3]);
      yyval->SetChild(1, yyvsp[-1]);
      yyval->SetChild(2, yyvsp[-5]);
    ;
    break;}
case 112:
{
      yyval = CreateOperation(CTNOT_DOT, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 113:
{
      yyval = yyvsp[0];
    ;
    break;}
case 114:
{
      ATTACH(yyval, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 115:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_TABLE, gmlineno);
    ;
    break;}
case 116:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_TABLE, gmlineno);
      yyval->SetChild(0, yyvsp[-1]);
    ;
    break;}
case 117:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_TABLE, gmlineno);
    ;
    break;}
case 118:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_TABLE, gmlineno);
      yyval->SetChild(0, yyvsp[-1]);
    ;
    break;}
case 119:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_TABLE, gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
    ;
    break;}
case 120:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_FUNCTION, gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
      yyval->SetChild(1, yyvsp[0]);
    ;
    break;}
case 121:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_FUNCTION, gmlineno);
      yyval->SetChild(1, yyvsp[0]);
    ;
    break;}
case 122:
{
      yyval = yyvsp[0];
    ;
    break;}
case 123:
{
      ATTACH(yyval, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 124:
{
      yyval = yyvsp[0];
    ;
    break;}
case 125:
{
      yyval = CreateOperation(CTNOT_ASSIGN_FIELD, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 126:
{
      yyval = yyvsp[0];
    ;
    break;}
case 127:
{
      ATTACH(yyval, yyvsp[-2], yyvsp[0]);
    ;
    break;}
case 128:
{
      yyval = gmCodeTreeNode::Create(CTNT_DECLARATION, CTNDT_PARAMETER, gmlineno);
      yyval->SetChild(0, yyvsp[0]);
    ;
    break;}
case 129:
{
      yyval = gmCodeTreeNode::Create(CTNT_DECLARATION, CTNDT_PARAMETER, gmlineno);
      yyval->SetChild(0, yyvsp[-2]);
      yyval->SetChild(1, yyvsp[0]);
    ;
    break;}
case 130:
{
      yyval = yyvsp[0];
    ;
    break;}
case 131:
{
      yyval = yyvsp[0];
      yyval->m_flags |= gmCodeTreeNode::CTN_MEMBER;
    ;
    break;}
case 132:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_THIS, gmlineno);
    ;
    break;}
case 133:
{
      yyval = yyvsp[0];
    ;
    break;}
case 134:
{
      yyval = yyvsp[0];
    ;
    break;}
case 135:
{
      yyval = yyvsp[0];
    ;
    break;}
case 136:
{
      yyval = yyvsp[-1];
    ;
    break;}
case 137:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_IDENTIFIER, gmlineno);
      yyval->m_data.m_string = (char *) gmCodeTree::Get().Alloc((int)strlen(gmtext) + 1);
      strcpy(yyval->m_data.m_string, gmtext);
    ;
    break;}
case 138:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CONSTANT, gmlineno, CTNCT_INT);
      yyval->m_data.m_iValue = strtoul(gmtext + 2, NULL, 16);
    ;
    break;}
case 139:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CONSTANT, gmlineno, CTNCT_INT);
      yyval->m_data.m_iValue = strtoul(gmtext + 2, NULL, 2);
    ;
    break;}
case 140:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CONSTANT, gmlineno, CTNCT_INT);
      yyval->m_data.m_iValue = (gmint)strtoll(gmtext, NULL, 10);
    ;
    break;}
case 141:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CONSTANT, gmlineno, CTNCT_INT);
      yyval->m_data.m_iValue = 1;
    ;
    break;}
case 142:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CONSTANT, gmlineno, CTNCT_INT);
      yyval->m_data.m_iValue = 0;
    ;
    break;}
case 143:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CONSTANT, gmlineno, CTNCT_INT);

      char * c = (char *) gmCodeTree::Get().Alloc((int)strlen(gmtext) + 1);
      strcpy(c, gmtext);
      int result = 0;
      int shr = 0;

      while(*c)
      {
        if(c[0] == '\'')
        {
          ++c;
          continue;
        }
        else if(c[0] == '\\')
        {
          if(shr) result <<= 8;
          switch(c[1])
          {
            case 'a' : result |= (unsigned char) '\a'; break;
            case 'b' : result |= (unsigned char) '\b'; break;
            case 'f' : result |= (unsigned char) '\f'; break;
            case 'n' : result |= (unsigned char) '\n'; break;
            case 'r' : result |= (unsigned char) '\r'; break;
            case 't' : result |= (unsigned char) '\t'; break;
            case 'v' : result |= (unsigned char) '\v'; break;
            case '\'' : result |= (unsigned char) '\''; break;
            case '\"' : result |= (unsigned char) '\"'; break;
            case '\\' : result |= (unsigned char) '\\'; break;
            default: result |= (unsigned char) c[1];
          }
          ++shr;
          c += 2;
          continue;
        }
        if(shr) result <<= 8;
        result |= (unsigned char) *(c++);
        ++shr;
      }

      if(shr > 4 && gmCodeTree::Get().GetLog()) gmCodeTree::Get().GetLog()->LogEntry("truncated char, line %d", gmlineno);

      yyval->m_data.m_iValue = result;
    ;
    break;}
case 144:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CONSTANT, gmlineno, CTNCT_FLOAT);
      yyval->m_data.m_fValue = (gmfloat)atof(gmtext);
    ;
    break;}
case 145:
{
      yyval = yyvsp[0];
    ;
    break;}
case 146:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CONSTANT, gmlineno, CTNCT_NULL);
      yyval->m_data.m_iValue = 0;
    ;
    break;}
case 147:
{
      yyval = gmCodeTreeNode::Create(CTNT_EXPRESSION, CTNET_CONSTANT, gmlineno, CTNCT_STRING);
      yyval->m_data.m_string = (char *) gmCodeTree::Get().Alloc((int)strlen(gmtext) + 1);
      strcpy(yyval->m_data.m_string, gmtext);
      if(gmtext[0] == '"')
      {
        gmProcessDoubleQuoteString(yyval->m_data.m_string);
      }
      else if(gmtext[0] == '`')
      {
        gmProcessSingleQuoteString(yyval->m_data.m_string);
      }
    ;
    break;}
case 148:
{
      yyval = yyvsp[-1];
      int alen = (int)strlen(yyval->m_data.m_string);
      int blen = (int)strlen(gmtext);
      char * str = (char *) gmCodeTree::Get().Alloc(alen + blen + 1);
      if(str)
      {
        memcpy(str, yyvsp[-1]->m_data.m_string, alen);
        memcpy(str + alen, gmtext, blen);
        str[alen + blen] = '\0';
        if(str[alen] == '"')
        {
          gmProcessDoubleQuoteString(str + alen);
        }
        else if(str[alen] == '`')
        {
          gmProcessSingleQuoteString(str + alen);
        }
        yyval->m_data.m_string = str;
      }
    ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */


  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
        fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
        {
          int size = 0;
          char *msg;
          int x, count;

          count = 0;
          /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
          for (x = (yyn < 0 ? -yyn : 0);
               x < (int)(sizeof(yytname) / sizeof(char *)); x++) //_GD_
            if (yycheck[x + yyn] == x)
              size += (int)strlen(yytname[x]) + 15, count++; // _GD_ add cast for 64bit build
          //_GD_ msg = (char *) malloc(size + 15);
          msg = GM_NEW( char [size + 15] );
          if (msg != 0)
            {
              strcpy(msg, "parse error");

              if (count < 5)
                {
                  count = 0;
                  for (x = (yyn < 0 ? -yyn : 0);
                       x < (sizeof(yytname) / sizeof(char *)); x++)
                    if (yycheck[x + yyn] == x)
                      {
                        strcat(msg, count == 0 ? ", expecting `" : " or `");
                        strcat(msg, yytname[x]);
                        strcat(msg, "'");
                        count++;
                      }
                }
              yyerror(msg);
              //_GD_ free(msg);
              delete [] msg;
            }
          else
            yyerror ("parse error; also virtual memory exceeded");
        }
      else
#endif /* YYERROR_VERBOSE */
        yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
        YYABORT;

#if YYDEBUG != 0
      if (yydebug)
        fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
        fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
        goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}


#include <stdio.h>











