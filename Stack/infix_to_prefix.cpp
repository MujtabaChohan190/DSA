int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1; // Default for non-operators or parenthesis
    }
}



string infixToPrefix(string infix) {
    string prefix = "";
    Stack s(infix.length());

    // Traverse the infix expression from RIGHT to LEFT
    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];

        // If operand, add it to the prefix string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            prefix = c + prefix;
        }
        // If closing parenthesis ')', push it
        else if (c == ')') {
            s.push(c);
        }
        // If opening parenthesis '('
        else if (c == '(') {
            // Pop until ')' is found
            while (!s.isEmpty() && s.top() != ')') {
                char op = s.pop();
                prefix = op + prefix;
            }
            // Remove the ')'
            if (!s.isEmpty() && s.top() == ')') {
                s.pop();
            }
        }
        // If operator
        else {
            // Pop while stack not empty and precedence of top >= current
            while (!s.isEmpty() && precedence(s.top()) > precedence(c)) {
                char op = s.pop();
                prefix = op + prefix;
            }
            s.push(c);
        }
    }

    // Pop remaining operators from stack
    while (!s.isEmpty()) {
        char op = s.pop();
        prefix = op + prefix;
    }

    return prefix;
}


/*We just reversed the traversal direction (for loop goes from right to left).

Instead of appending (postfix += c), we prepend (prefix = c + prefix).

Parentheses handling is mirrored () is pushed, ( causes popping).
n postfix: precedence(current) <= precedence(top)

In prefix: precedence(top) > precedence(current)*/
