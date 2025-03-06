grammar LTL;
formula: formula IMPLICATION formula # Implication
    | formula DISJUNCTION formula # Disjunction
    | formula CONJUNCTION formula # Conjunction
    | NOT formula # Negation
    | NEXT formula # Next
    | formula UNTIL formula # Until
    | ALWAYS formula # Always
    | EVENTUALLY formula # Eventually
    | '(' formula ')' # Parenthesis
    ;
EVENTUALLY: 'F';
ALWAYS: 'G';
NEXT: 'X';
UNTIL: 'U';
NOT: '!';
CONJUNCTION: '/\\';
DISJUNCTION: '\\/';
IMPLICATION: '->';