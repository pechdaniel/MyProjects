using System;
using System.Collections.Generic;
using Interpreter.Model.Expressions;
using System.Text;

namespace Interpreter.Model.Statements
{
    public class AssignStmt:IStmt
    {
        private string id;
        private IExpr expr;

        public AssignStmt(string key, IExpr expression)
        {
            id = key;
            expr = expression;
        }

        public ProgramState execute(ProgramState state)
        {
            int val = expr.evaluate(state.SymbolTable);
            state.SymbolTable.setValue(id, val);
            return state;
        }

        public override string ToString()
        {
            return id + "=" + expr;
        }
    }
}
