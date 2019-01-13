using System;
using System.Collections.Generic;
using System.Text;
using Interpreter.Repository;
using Interpreter.Model.Statements;
using Interpreter.Model;
using Interpreter.Exceptions;
using Interpreter.Model.Utilities;

namespace Interpreter.Controller
{
    public class Controller
    {
        private IRepo repo;

        public Controller(IRepo repo)
        {
            this.repo = repo;
        }

        public ProgramState oneStep(ProgramState state)
        {
            try
            {
                if (state.Stack.isEmpty())
                    throw new EmptyStack("The stack is empty!");
                IStmt currentStmt = state.Stack.pop();
                return currentStmt.execute(state);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
                Environment.Exit(0);
            }
            return state;
        }

        public void allSteps()
        {
            ProgramState prg = repo.getCurrentPrg();
            try
            {
                while (!prg.Stack.isEmpty())
                {
                    prg=oneStep(prg);
                    this.repo.logProgramStateExec("C:\\Users\\pechd\\source\\repos\\Interpreter\\Interpreter\\log.txt");
                    Console.WriteLine("-----------");
                    Console.WriteLine(prg.ToString());
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

        public override string ToString()
        {
            return "Controller: " + repo.ToString();
        }
    }
}
