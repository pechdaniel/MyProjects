using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.Model.Expressions
{
    public class ConstExpr:IExpr
    {
        private int number;

        public ConstExpr(int nr)
        {
            number = nr;
        }

        public int evaluate(Utilities.IDictionary<string, int> dic)
        {
            return number;
        }

        public override string ToString()
        {
            return "" + number;
        }
    }
}
