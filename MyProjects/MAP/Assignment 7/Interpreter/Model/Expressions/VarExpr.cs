using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.Model.Expressions
{
    public class VarExpr:IExpr
    {
        private string id;

        public VarExpr(string v)
        {
            id = v;
        }

        public int evaluate(Utilities.IDictionary<string, int> dic)
        {
            return dic.getValue(id);
        }

        public override string ToString()
        {
            return id;
        }
    }
}
