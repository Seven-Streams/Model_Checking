#include "AST/Bkornblume.h"
#include "AST/Node.h"
#include "Transform/NBA.h"
#include "Transform/Transformer.h"
#include "Translate/TSParser.h"
#include "antlr4-runtime.h"
#include "grammar/LTLLexer.h"
#include "grammar/LTLParser.h"
#include <any>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include "ANTLRInputStream.h"
#include "CheckOnProduct/Product.h"