using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.Exceptions
{
    public class VariableNotDefined : Exception
    {
        public VariableNotDefined(String msg) : base(msg) { }
    }
}
