using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.Exceptions
{
    public class FileAlreadyExists : Exception
    {
        public FileAlreadyExists(String msg) : base(msg) { }
    }
}
