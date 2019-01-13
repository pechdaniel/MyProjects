using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.Exceptions
{
    public class EmptyStack : Exception
    {
        public EmptyStack(String msg) : base(msg) { }
    }
}
