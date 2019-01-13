using System;
using System.Collections.Generic;
using System.Text;
using Interpreter.Model;

namespace Interpreter.Repository
{
    public interface IRepo
    {
        void addPrg(ProgramState prg);
        ProgramState getCurrentPrg();
        void logProgramStateExec(string logFilePath);
    }
}
