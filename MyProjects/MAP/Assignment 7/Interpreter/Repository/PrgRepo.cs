using System;
using System.Collections.Generic;
using System.Text;
using Interpreter.Model;
using Interpreter.Model.Statements;
using System.IO;

namespace Interpreter.Repository
{
    public class PrgRepo:myRepositorix
    {
        private ProgramState p;
        public PrgRepo(ProgramState p)
        {
            this.p = p;
        }

        public ProgramState getCurrentPrgState()
        {
            return this.p;
        }
        public void logPrgState()
        {
            ProgramState p = this.getCurrentPrgState();

            using (StreamWriter log = File.AppendText("C:\\Users\\pechd\\source\\repos\\Lab7\\Lab7\\log.txt"))
            {

                log.WriteLine("Stack:\n");
                foreach (IStmt st in p.Stack)
                {
                    log.WriteLine(st);
                }
                log.WriteLine("SymbolTable:\n");
                foreach (KeyValuePair<string, int> v in p.SymbolTable)
                {
                    log.WriteLine(v.Key + "->" + v.Value);
                }

                log.WriteLine("Output list:");
                foreach (int v in p.Output)
                {
                    log.WriteLine(v);
                }
                log.WriteLine("File Table:");
                foreach (KeyValuePair<int, StreamReader> kvp in p.FileTab)
                {
                    log.WriteLine(kvp.Key + "->" + kvp.Value);
                }

            }

        }
    }
}
