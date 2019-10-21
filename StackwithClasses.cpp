{\rtf1\ansi\ansicpg1252\cocoartf2509
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fmodern\fcharset0 Courier;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs36 \cf2 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #define STACK_MAX 100\
\pard\pardeftab720\sl420\partightenfactor0
\cf2 \
class Stack \{\
\
    private:\
        int        data[STACK_MAX];\
        int        size;\
\
    public:\
        Stack() \{       // Constructor\
            size = 0;\
        \}\
\
        ~Stack() \{ \}    // Destructor\
\
        int Top() \{\
\
            if (size == 0) \{\
                fprintf(stderr, "Error: stack empty\\n");\
                return -1;\
            \}\
            return data[size-1];\
        \}\
\
        void Push(int d) \{\
\
            if (size < STACK_MAX)\
                data[size++] = d;\
            else\
                fprintf(stderr, "Error: stack full\\n");\
        \}\
\
        void Pop() \{\
\
            if (size == 0)\
                fprintf(stderr, "Error: stack empty\\n");\
            else\
                size--;\
        \}\
\};\
}