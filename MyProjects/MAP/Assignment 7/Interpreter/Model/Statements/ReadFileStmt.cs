using System;
using System.Collections.Generic;
using System.Text;
using Interpreter.Model.Expressions;
using System.IO;
using Interpreter.Exceptions;
using System.Linq;

namespace Interpreter.Model.Statements
{
    public class ReadFileStmt:IStmt
    {

        private IExpr id;
        private string var;
        public ReadFileStmt(IExpr e, string s) { id = e; var = s; }

        public ProgramState execute(ProgramState state)
        {
            int val = this.id.evaluate(state.SymbolTable);
            if (state.FileTab.exists(val))
            {
                StreamReader b = state.FileTab.getValue(val);
                string line = b.ReadLine();
                int myValue;
                if (line == null)
                    myValue = 0;
                else
                    myValue = int.Parse(line);
                if (state.SymbolTable.exists(this.var))
                {
                    state.SymbolTable.delete(this.var);
                    state.SymbolTable.setValue(this.var, myValue);
                }
                else
                    state.SymbolTable.setValue(this.var, myValue);

            }
            else
                throw new FileNotFoundException("File not found!");
            return state;
        }

        public override string ToString()
        {
            return "ReadFile(" + id + "," + var + ")";
        }
    }
    
}
