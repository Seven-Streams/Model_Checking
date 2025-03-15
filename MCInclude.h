#include "AST/Bkornblume.h"
#include "AST/Node.h"
#include "Transform/Transformer.h"
#include "antlr4-runtime.h"
#include "grammar/LTLLexer.h"
#include "grammar/LTLParser.h"
#include <any>
#include <fstream>
#include <iostream>
#include <set>
#include "Translate/TSParser.h"
#include "Transform/NBA.h"