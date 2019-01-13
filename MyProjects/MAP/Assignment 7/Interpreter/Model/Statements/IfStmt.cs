using System;
using System.Collections.Generic;
using System.Text;
using Interpreter.Model.Expressions;

namespace Interpreter.Model.Statements
{
    public class IfStmt:IStmt
    {
        private IExpr expr;
        private IStmt thenStmt;
        private IStmt elseStmt;

        public IfStmt(IExpr expression, IStmt thenS, IStmt elseS)
        {
            expr = expression;
            thenStmt = thenS;
            elseStmt = elseS;
        }

        public ProgramState execute(ProgramState state)
        {
            int val = expr.evaluate(state.SymbolTable);

            if (val != 0)
                state.Stack.add(thenStmt);
            else
                state.Stack.add(elseStmt);
            return state;
        }

        public override string ToString()
        {
            return "if(" + expr + ") then(" + thenStmt + ")else(" + elseStmt + ")";
        }
    }
}
