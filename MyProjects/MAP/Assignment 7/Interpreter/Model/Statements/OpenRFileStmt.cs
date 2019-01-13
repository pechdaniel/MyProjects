using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Interpreter.Exceptions;

namespace Interpreter.Model.Statements
{
    public class OpenRFileStmt:IStmt
    {
        private string var;
        private string path;

        public OpenRFileStmt(string v, string s) { var = v; path = s; }

        public ProgramState execute(ProgramState state)
        {
            StreamReader b = new StreamReader(path,true);

            if(!state.SymbolTable.exists(var)) {
                int i = 0;
                while(true){
                    if(state.FileTab.exists(i))
                        i++;
                    else break;
                }
            state.SymbolTable.setValue(var, i);
                state.FileTab.setValue(i, b);
            }
            else throw new FileAlreadyExists("File already exists!");
            return state;
        }

        public override string ToString()
        {
            return "OpenFile(" + var + "," + path + ")";
        }
    }
}
