using System;
using Interpreter.Model.Statements;
using Interpreter.Model.Expressions;
using Interpreter.Model.Utilities;
using Interpreter.Model;
using Interpreter.Repository;
using Interpreter.Controller;
using System.IO;
using Interpreter.View;

namespace Interpreter
{
    class Program
    {
        static void Main(string[] args)
        {
            IStack<IStmt> ExeStack4 = new MyStack<IStmt>();
            Interpreter.Model.Utilities.IDictionary<string, int> SymTable4 = new MyDictionary<string, int>();
            IList<int> out4 = new MyList<int>();
            Model.Utilities.IDictionary<int, StreamReader> fileTable4 = new MyDictionary<int, StreamReader>();
            IStmt expr4 = new CompStmt(
                    new OpenRFileStmt("var_f", "C:\\Users\\pechd\\source\\repos\\Interpreter\\Interpreter\\Example.txt"), new CompStmt(
                            new ReadFileStmt(new VarExpr("var_f"), "var_c"), new CompStmt(
                                    new PrintStmt(new VarExpr("var_c")), new CompStmt(
                                            new IfStmt(new VarExpr("var_c")
                                                    , new CompStmt(new ReadFileStmt(new VarExpr("var_f"), "var_c"), new PrintStmt(new VarExpr("var_c"))), new PrintStmt(new ConstExpr(0))),
                    new CloseRFileStmt(new VarExpr("var_f"))))));
            ExeStack4.add(expr4);
            ProgramState prgCurrent4 = new ProgramState(ExeStack4, SymTable4, out4, fileTable4);
            myRepositorix repo4 = new PrgRepo(prgCurrent4);
            Controller.MyController ctrl4 = new Controller.MyController(repo4);
            //IRepo repo4 = new Repository.Repository();
            //repo4.addPrg(prgCurrent4);
            //Controller.Controller ctrl4 = new Controller.Controller(repo4);

            TextMenu menu = new TextMenu();
            menu.addCommand(new ExitCommand("0", "exit"));
            menu.addCommand(new RunExample("1", expr4.ToString(), ctrl4));
            menu.show();

            //IExeStack<Statement> exeStack = new Stack<Statement>();
            //Model.ADT.IDictionary<string, int> symbolTable = new DictionaryC<string, int>();
            //IOutput<int> messages = new Output<int>();
            //IFileTable<int, FileData> fd = new FileTable<int, FileData>();

            //Statement s = new CompoundStatement(new AssignStatement("v", new ConstantExpression(2)), new PrintStatement(new VariableExpression("v")));
            //exeStack.Push(s);
            //PrgState state = new PrgState(symbolTable, exeStack, messages, fd);
            //IPrgRepository repo = new PrgRepository(state);
            //Controller.Controller ctrl = new Controller.Controller(repo);

            //IExeStack<Statement> exeStack1 = new Stack<Statement>();
            //Model.ADT.IDictionary<string, int> symbolTable1 = new DictionaryC<string, int>();
            //IOutput<int> messages1 = new Output<int>();
            //IFileTable<int, FileData> fd1 = new FileTable<int, FileData>();

            //Statement s1 = new CompoundStatement(
            //               new CompoundStatement(
            //                       new CompoundStatement(
            //                               new OpenFileStatement("var_f", "C:\\Users\\pechd\\source\\repos\\Lab7\\Lab7\\Example.txt"),

            //                               new ReadFileStatement(new VariableExpression("var_f"), "var_c")
            //                       ),
            //                       new CompoundStatement(
            //                               new PrintStatement(new VariableExpression("var_c")),
            //                               new IfStatement(
            //                                       new VariableExpression("var_c"),
            //                                       new PrintStatement(new ConstantExpression(0))
            //                                      , new CompoundStatement(
            //                                               new ReadFileStatement(new VariableExpression("var_f"), "var_c"),
            //                                               new PrintStatement(new VariableExpression("var_c")))))), new CloseFileStatement(new VariableExpression("var_f")));

            //exeStack1.Push(s1);
            //PrgState state1 = new PrgState(symbolTable1, exeStack1, messages1, fd1);
            //IPrgRepository repo1 = new PrgRepository(state1);
            //Controller.Controller ctrl1 = new Controller.Controller(repo1);

            //TextMenu menu = new TextMenu();
            //menu.addCommand(new ExitCommand("0", "exit"));
            //menu.addCommand(new RunExample("1", s.ToString(), ctrl));
            //menu.addCommand(new RunExample("2", s1.ToString(), ctrl1));
            //menu.show();
        }
    }
}
