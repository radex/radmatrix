// https://github.com/petabyt/font3x3
#ifndef FONT3X3_H
#define FONT3X3_H

struct Font3x3 {
    const char letter;
    const char code[3][4];
};

struct Font3x3 font[] = {
{'A', {
" # ",
"###",
"# #"}},
{'B', {
"## ",
"###",
"###"}},
{'C', {
"###",
"#  ",
"###"}},
{'D', {
"## ",
"# #",
"## "}},
{'E', {
"###",
"## ",
"###"}},
{'F', {
"###",
"## ",
"#  "}},
{'G', {
"## ",
"# #",
"###"}},
{'H', {
"# #",
"###",
"# #"}},
{'I', {
"###",
" # ",
"###"}},
{'J', {
"  #",
"# #",
"###"}},
{'K', {
"# #",
"## ",
"# #"}},
{'L', {
"#  ",
"#  ",
"###"}},
{'M', {
"###",
"###",
"# #"}},
{'N', {
"###",
"# #",
"# #"}},
{'O', {
"###",
"# #",
"###"}},
{'P', {
"###",
"###",
"#  "}},
{'Q', {
"###",
"###",
"  #"}},
{'R', {
"###",
"#  ",
"#  "}},
{'S', {
" ##",
" # ",
"## "}},
{'T', {
"###",
" # ",
" # "}},
{'U', {
"# #",
"# #",
"###"}},
{'V', {
"# #",
"# #",
" # "}},
{'W', {
"# #",
"###",
"###"}},
{'X', {
"# #",
" # ",
"# #"}},
{'Y', {
"# #",
" # ",
" # "}},
{'Z', {
"## ",
" # ",
" ##"}},
{'!', {
"#  ",
"   ",
"#  "}},
{'>', {
"#  ",
" # ",
"#  "}},
{'<', {
" # ",
"#  ",
" # "}},
{'%', {
"  #",
"###",
"#  "}},
{'*', {
" # ",
"## ",
"   "}},
{'+', {
" # ",
"###",
" # "}},
{'-', {
"   ",
"###",
"   "}},
{'.', {
"   ",
"   ",
"#  "}},
{',', {
"   ",
"#  ",
"#  "}},
{'$', {
"###",
" # ",
"###"}},
{'|', {
"#  ",
"#  ",
"#  "}},
{'?', {
"###",
" ##",
" # "}},
{'^', {
" # ",
"# #",
"   "}}
};

#endif
