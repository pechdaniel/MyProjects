using System;
using System.Collections.Generic;
using System.Text;
using Interpreter.Model;

namespace Interpreter.Repository
{
    public interface myRepositorix
    {
        ProgramState getCurrentPrgState();

        void logPrgState();
    }
}
