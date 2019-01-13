using System;
using System.Collections.Generic;
using System.IO;
using Interpreter.Model.Expressions;
using System.Text;

namespace Interpreter.Model.Statements
{
    public class CloseRFileStmt:IStmt
    {
        private IExpr id;

        public CloseRFileStmt(IExpr e) { id = e; }

        public ProgramState execute(ProgramState state)
        {
            int val = id.evaluate(state.SymbolTable);
            if(state.FileTab.exists(val)) {
                StreamReader b = state.FileTab.getValue(val);
            b.Close();
                state.FileTab.delete(val);
            }
            else throw new FileNotFoundException("File not found!");
            return state;
        }

        public override string ToString()
        {
            return "close(" + id + ")";
        }
    }
}
