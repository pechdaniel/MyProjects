using System;
using System.Collections.Generic;
using System.Text;
using Interpreter.Model.Expressions;

namespace Interpreter.Model.Statements
{
    public class PrintStmt:IStmt
    {

        private IExpr expr;

        public PrintStmt(IExpr expression)
        {
            expr = expression;
        }

        public ProgramState execute(ProgramState state)
        {
            int val = expr.evaluate(state.SymbolTable);
            state.Output.add(val);
            return state;
        }

        public override string ToString()
        {
            return "print(" + expr + ")";
        }
    }
}
