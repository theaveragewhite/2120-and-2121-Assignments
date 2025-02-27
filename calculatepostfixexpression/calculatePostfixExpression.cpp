#include <string>
#include <stack>
#include <sstream>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string

bool isOperator(const string& c)
{
  return c == "*" || c == "/" || c == "%" || c == "+" || c == "-";
}


int calculatePostfixExpression(string expression[], int length)
{
  stack <int> numChange;
  int num1;
  int num2;
  int result;
  int i = 0;
  for (i = 0; i < length; i++)
  {
    //Checks if the expression is a number
    if(isdigit(expression[i][0]))
    {
      //This pushes the expression onto the stack and changes the string to an int
      numChange.push(stoi(expression[i]));
    }
    else if(isOperator(expression[i]))
    {
      if(numChange.size() < 2)
      {
        return 0;
      }
      //Pops the top element from the stack and assigns it to num1
      num1 = numChange.top();
      numChange.pop();

      num2 = numChange.top();
      numChange.pop();

      if(expression[i] == "*")
      {
        //Pushes the result onto the stack
        result = num1 * num2;
        numChange.push(result);
      }
      else if(expression[i] == "/")
      {
        if(num2 == 0)
        {
          return 0;
        }
        //num1 and num2 here are switched due to operations
        result = num2 / num1;
        numChange.push(result);
      }
      else if(expression[i] == "%")
      {
        if(num2 == 0)
        {
          return 0;
        }
        //num1 and num2 here are switched due to operation
        result = num2 % num1;
        numChange.push(result);
      }
      else if(expression[i] == "+")
      {
        result = num1 + num2;
        numChange.push(result);
      }
      else if(expression[i] == "-")
      {
        //num1 and num2 here are switched due to operation
        result = num2 - num1;
        numChange.push(result);
      }
      else
      {
        return 0;
      }
    }
  }
  if(numChange.size() == 1)
  {
    //Returns the top element from the stack
    return numChange.top();
  }
  if(!numChange.empty())
  {
    return 0;
  }
  return 0;
}
