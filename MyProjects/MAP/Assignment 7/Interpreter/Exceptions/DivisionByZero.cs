using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.Exceptions
{
    public class DivisionByZero : Exception
    {
        public DivisionByZero(String msg) : base(msg) { }
    }
}