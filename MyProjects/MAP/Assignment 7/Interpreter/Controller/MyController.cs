using System;
using System.Collections.Generic;
using System.Text;
using Interpreter.Model;
using Interpreter.Model.Statements;
using Interpreter.Repository;

namespace Interpreter.Controller
{
    public class MyController
    {
        private myRepositorix repo;

        public MyController(myRepositorix r)
        {
            this.repo = r;
        }

        public void executeOneStep()
        {
            ProgramState p = repo.getCurrentPrgState();
            IStmt stmt = p.Stack.pop();

            stmt.execute(p);
            Console.WriteLine(p);
        }

        public void executeAllSteps()
        {
            ProgramState p = repo.getCurrentPrgState();
            while (!p.Stack.isEmpty())
            {
                this.executeOneStep();
                repo.logPrgState();
            }
        }
    }
}
