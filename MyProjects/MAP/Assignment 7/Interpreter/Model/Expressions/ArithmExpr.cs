using System;
using System.Collections.Generic;
using Interpreter.Exceptions;
using System.Text;

namespace Interpreter.Model.Expressions
{
    public class ArithmExpr:IExpr
    {
        private IExpr left, right;
        private string oper;

        public ArithmExpr(string op, IExpr l, IExpr r)
        {
        oper = op;
            left = l;
            right = r;
        }

        public int evaluate(Utilities.IDictionary<string, int> dic)
        {
            int left = this.left.evaluate(dic);
            int right = this.right.evaluate(dic);

            switch (oper){
            case "+":
                return left + right;
            case "-":
                return left - right;
            case "*":
                return left * right;
            case "/":
                if (right == 0)
                    throw new DivisionByZero("Division by 0 is not allowed!");
                return left / right;
            }
            throw new InvalidOperator("Invalid operator!");
        }

        public override string ToString()
        {
            return "" + left + oper +right;
        }
    }
}
