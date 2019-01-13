using System;
using System.Collections.Generic;
using Interpreter.Model.Utilities;
using Interpreter.Model.Statements;
using System.Text;
using System.IO;
using System.Linq;

namespace Interpreter.Model
{
    public class ProgramState
    {
        private IStack<IStmt> stack;
        private Utilities.IDictionary<string, int> SymTable;
        private Utilities.IList<int> list;
        private Utilities.IDictionary<int, StreamReader> FileTable;


        public ProgramState(IStack<IStmt> stack, Utilities.IDictionary<string, int> symTable, Utilities.IList<int> list, Utilities.IDictionary<int, StreamReader> file)
        {
            this.stack = stack;
            this.SymTable = symTable;
            this.list = list;
            this.FileTable = file;
        }

        public Utilities.IDictionary<string, int> SymbolTable
        {
            get { return this.SymTable; }
            set { this.SymTable = value; }
        }

        public Utilities.IDictionary<int, StreamReader> FileTab
        {
            get { return this.FileTable; }
            set { this.FileTable = value; }
        }

        public Utilities.IStack<IStmt> Stack
        {
            get { return this.stack; }
            set { this.stack = value; }
        }

        public Utilities.IList<int> Output
        {
            get { return this.list; }
            set { this.list = value; }
        }

        //public IStack<IStmt> getStack()
        //{
        //    return stack;
        //}
        //
        //public void setStack(IStack<IStmt> stack)
        //{
        //    this.stack = stack;
        //}
        //
        //public Utilities.IDictionary<string, int> getSymTable()
        //{
        //    return SymTable;
        //}
        //
        //public void setFileTable(Utilities.IDictionary<int, StreamReader> table)
        //{
        //    FileTable = table;
        //}
        //
        //public Utilities.IDictionary<int, StreamReader> getFileTable()
        //{
        //    return FileTable;
        //}
        //
        //public void setFileTableMap(Dictionary<int, StreamReader> table)
        //{
        //    FileTable.setMap(table);
        //}
        //
        //public void setSymTable(Utilities.IDictionary<string, int> symTable)
        //{
        //    SymTable = symTable;
        //}
        //
        //public Utilities.IList<int> getList()
        //{
        //    return list;
        //}
        //
        //public void setList(Utilities.IList<int> list)
        //{
        //    this.list = list;
        //}

        public override string ToString()
        {
            StringBuilder buff = new StringBuilder();
            buff.Append("\nExeStack:\n");
            buff.Append(this.stack);
            buff.Append("\nSymbolTable:\n");
            buff.Append(this.SymTable);
            buff.Append("\nOutput:\n");
            buff.Append(this.list);
            buff.Append("\nFile Table:\n");
            buff.Append(this.FileTable);
            return buff.ToString();
        }
    }
}
