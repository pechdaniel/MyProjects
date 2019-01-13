using System;
using System.Collections.Generic;
using System.Text;
using Interpreter.Model;
using Interpreter.Model.Statements;
using System.IO;

namespace Interpreter.Repository
{
    public class Repository:IRepo
    {
        private List<ProgramState> listPrg = new List<ProgramState>();
        private int current = 0;

        public Repository() { }

        public void addPrg(ProgramState prg)
        {
            listPrg.Add(prg);
        }
        public ProgramState getCurrentPrg()
        {
            return listPrg[current];
        }

        public void logProgramStateExec(string logFilePath)
        {
            //StreamWriter logFile=new StreamWriter(logFilePath,true);
            //logFile.WriteLine(this.getCurrentPrg().ToString());
            //logFile.WriteLine("------------------");
            //logFile.Close();
            ProgramState p = this.getCurrentPrg();
            using (StreamWriter log = File.AppendText("C:\\Users\\pechd\\source\\repos\\Interpreter\\Interpreter\\log.txt"))
            {

                log.WriteLine("Stack:\n");
                foreach (IStmt st in p.Stack)
                {
                    log.WriteLine(st);
                }
                log.WriteLine("SymTable:\n");
                foreach (KeyValuePair<string, int> v in p.SymbolTable)
                {
                    log.WriteLine(v.Key + "->" + v.Value);
                }

                log.WriteLine("Out:");
                foreach (int v in p.Output)
                {
                    log.WriteLine(v);
                }
                log.WriteLine("FileTable:");
                foreach (KeyValuePair<int, StreamReader> kvp in p.FileTab)
                {
                    log.WriteLine(kvp.Key + "->" + kvp.Value);
                }

            }
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            foreach (ProgramState state in listPrg)
            {
                sb.Append(state).Append("\n");
            }
            return sb.ToString();
        }
    }
}
