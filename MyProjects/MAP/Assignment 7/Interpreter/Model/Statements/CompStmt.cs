using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.Model.Statements
{
    public class CompStmt:IStmt
    {
        private IStmt first, second;

        public CompStmt(IStmt f, IStmt s)
        {
            first = f;
            second = s;
        }

        public ProgramState execute(ProgramState state)
        {
            state.Stack.add(second);
            state.Stack.add(first);

            return state;
        }

        public override string ToString()
        {
            return "(" + first + "; " + second + ")";
        }
    }
}
