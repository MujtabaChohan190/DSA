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
