/*
 * Copyright 2004-2016 Cray Inc.
 * Other additional copyright holders may be indicated within.
 *
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 *
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _PARSER_H_
#define _PARSER_H_

class BlockStmt;
class UseStmt;

#include "symbol.h"

extern int         chplLineno;
extern bool        chplParseString;
extern const char* chplParseStringMsg;

extern ModTag      currentModuleType;
extern bool        currentFileNamedOnCommandLine;

extern int         yystartlineno;
extern const char* yyfilename;
extern BlockStmt*  yyblock;

ModuleSymbol*      parseFile(const char* filename,
                             ModTag      modtype,
                             bool        namedOnCommandLine = false);

ModuleSymbol*      parseMod(const char* modname,
                            ModTag      modtype);

BlockStmt*         parseString(const char* string,
                               const char* filename,
                               const char* msg);

void               addModuleToParseList(const char* name,
                                        UseStmt*   newUse);

void               parseDependentModules(ModTag modtype);

#endif
