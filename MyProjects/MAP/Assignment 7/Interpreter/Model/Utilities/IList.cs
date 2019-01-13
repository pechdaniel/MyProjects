using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Linq;

namespace Interpreter.Model.Utilities
{
    public interface IList<T>:IEnumerable
    {
        void add(T x);

        List<T> getElements();

        void remove(T x);
    }
}
