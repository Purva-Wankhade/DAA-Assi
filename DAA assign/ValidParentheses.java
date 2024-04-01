import java.util.Scanner;
import java.util.Stack;

public class ValidParentheses {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else if (c == ')' && !stack.isEmpty() && stack.peek() == '(') {
                stack.pop();
            } else if (c == ']' && !stack.isEmpty() && stack.peek() == '[') {
                stack.pop();
            } else if (c == '}' && !stack.isEmpty() && stack.peek() == '{') {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.isEmpty();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ValidParentheses solution = new ValidParentheses();

        System.out.println("Enter a string of parentheses:");
        String input = scanner.nextLine().trim();

        boolean isValid = solution.isValid(input);

        if (isValid) {
            System.out.println("The input string has valid parentheses.");
        } else {
            System.out.println("The input string does not have valid parentheses.");
        }

        scanner.close();
    }
}
