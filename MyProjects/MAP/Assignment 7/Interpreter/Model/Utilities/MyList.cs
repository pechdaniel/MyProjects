using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace Interpreter.Model.Utilities
{
    public class MyList<T>:IList<T>
    {
        private List<T> elements = new List<T>();

        public MyList()
        {
            this.elements = new List<T>();
        }

        public void add(T e)
        {
            elements.Add(e);
        }
        public List<T> getElements()
        {
            return elements;
        }
        public void remove(T e)
        {
            elements.Remove(e);
        }

        public override string ToString()
        {
            StringBuilder buff = new StringBuilder();
            foreach (T el in this.elements)
            {
                buff.Append(el);
                buff.Append(", ");
            }
            buff.Append("\n");
            return buff.ToString();
        }
        public IEnumerator GetEnumerator()
        {
            return elements.GetEnumerator();
        }
    }
}
