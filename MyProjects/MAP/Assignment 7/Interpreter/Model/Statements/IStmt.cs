using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.Model.Statements
{
    public interface IStmt
    {
        ProgramState execute(ProgramState state);
    }
}
