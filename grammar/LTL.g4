grammar LTL;
formula: 
    NOT formula # Not 
    | ALWAYS formula # Always
    | EVENTUALLY formula # Eventually
    | NEXT formula # Next    
    | formula UNTIL formula # Until
    | formula IMPLICATION formula # Implication
    | formula DISJUNCTION formula # Disjunction
    | formula CONJUNCTION formula # Conjunction
    | TRUE # True
    | FALSE # False
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
TRUE: 'true';
FALSE: 'false';
ATOM: [a-z]+;
WS: [ \t\r\n]+ -> skip;