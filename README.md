# Model Checker

This is a checker for LTL formulas on a transition system, implemented with C++.
The program is based on antlr4. `antlr4-runtime` is required.

## Input Format

The input format are as follows:

### LTL Formulas

The LTL formulas input should be in a file named `input.txt`. The formulas allows such input:

- Always: `G`
  
- Eventually: `F`
  
- Until: `U`
  
- Next: `X`
  
- conjuction: `/\`
  
- disjunction: `\/`
  
- implication: `->`
  
- not: `!`
  
- true: `true`
  
- false: `false`
  

Moreover, the atom properties should be lowercase letters or words.

the first line of the file should be two numbers: how many formulas to check the persistence , and how many formulas to check with the certain init state in the transition system.

then, followed by several lines of formulas, and several lines of numbers and a formulas. Here is an example.

```
1 3
G(a \/ b)
1 X(a /\ c)
2 !(Fa)
3 c U (!a)
```

### the Transition System

The transition system input should be in a file named `ts.txt`. Here is an example input:

```
6 9
0
0 1 2
a b c
0 1 1
0 0 3
3 2 1
1 2 4
2 2 1
5 0 2
5 1 1
4 0 1
4 1 5
0 1
0 1 2
1 2
0 2
0 2
0 1
```

The first line is two numbers. The first one is the state numbers, and the other one is the transition numbers.

The second line, is the initial states of the transition system.

The third line, is the actions of the transion system.

The fourth line, is the properties.

Then, followed by some lines, which decipts the transitions. Each line means `from` `action` `to`.

Then, followed by some lines, which describe the properties of the states. For example:

```
a b c
transitions...
0 1
0 1 2
1 2
0 2
0 2
0 1
```

`0 1` means state `0` has the property `a`, `b`, `0 1 2` means state `1` has the property `a`, `b`, `c`.

## Output format

For each formula, it will output a boolean. `1` represents yes and `0` denotes no.

## Technical Report

### Parsers

We parse the TS simply in C++.

We parse LTL formulas with antlr4. Then, we build an AST with a visitor.  A formula will be stored as a tree. The relative classes are in `AST/Node.h`.

After that, we try to simplify the formulas, and turned formulas into the formulas composed of: atom properties, `true`, `false`, `!`, `/\`, `U`. The relative implementations are in `Transform/Simplify.cpp`.

### Build the Product System

First, we visit the AST to build the closure, which is implemented with a recursive method.

Then, we sort all the formulas in the clousure by the lengths of formulas. Then, we build the elementary sets by dfs the closure, according to the lengths of formulas, which can easily ensure
the consistent of the elementary set. The implementations are in `Transform/BuildElementarySet.cpp`.

Then, we build the GNBA which accepts the negation of the input formula, and transform the GNBA to its equivalent NBA. The implementations are in `Transform/BuildNBA.cpp`.

Then, we build the product system, and run a nested dfs. Here, we used an on-the-fly algorithm to check the persistence, which is consisted of two layers of DFS. The realization is in `CheckOnProduct/Product.cpp`.
