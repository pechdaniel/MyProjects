using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.Exceptions
{
    public class InvalidOperator : Exception
    {
        public InvalidOperator(String msg) : base(msg) { }
    }
}
