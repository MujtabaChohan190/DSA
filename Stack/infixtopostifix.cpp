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
            prefix += c;
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



string infixToPostfix(string infix) {
    string postfix = "";
    Stack s(infix.length());

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            // If it's an operand, add it to the output string
            postfix += c;
        } else if (c == '(') {
            // If it's an opening parenthesis, push it to the stack
            s.push(c);
        } else if (c == ')') {
            // If it's a closing parenthesis, pop and output from the stack
            // until an opening parenthesis is encountered
            while (!s.isEmpty() && s.top() != '(') {
                char op = s.pop();
                postfix += op;
            }
            if (s.top() == '(') {
                // Pop the opening parenthesis
                s.pop();
            }
        } else {
            // If it's an operator
            // Pop operators from the stack while the stack is not empty AND
            // the precedence of the top operator is greater than or equal to
            // the precedence of the current operator
            while (!s.isEmpty() && precedence(c) <= precedence(s.top())) {
                char op = s.pop();
                postfix += op;
            }
            // Push the current operator onto the stack
            s.push(c);
        }
    }

    // After the loop, pop all the remaining operators from the stack
    while (!s.isEmpty()) {
        char op = s.pop();
        postfix += op;
    }

    return postfix;
}
