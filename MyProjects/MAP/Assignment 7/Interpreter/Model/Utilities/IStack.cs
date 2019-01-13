using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace Interpreter.Model.Utilities
{
    public interface IStack<T>:IEnumerable
    {
        void add(T x);
        List<T> getElements();
        bool isEmpty();
        T top();
        T pop();
    }
}
