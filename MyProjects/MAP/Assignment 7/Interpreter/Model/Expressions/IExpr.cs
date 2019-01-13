using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.Model.Expressions
{
    public interface IExpr
    {
        int evaluate(Utilities.IDictionary<string , int> dic);
    }
}
