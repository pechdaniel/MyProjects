using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Model.Utilities
{
    public class MyStack<T>:IStack<T>
    {
        private Stack<T> elements = new Stack<T>();

        public MyStack()
        {
            this.elements = new Stack<T>();
        }

        public void add(T e)
        {
            elements.Push(e);
        }
        public List<T> getElements()
        {
            return elements.ToList();
        }
        public bool isEmpty()
        {
            return elements.Any();
        }
        public T top()
        {
            return elements.First();
        }
        public T pop()
        {
            return elements.Pop();
        }

        public IEnumerator GetEnumerator()
        {
            return elements.GetEnumerator();
        }
        public override string ToString()
        {
            StringBuilder buff = new StringBuilder();

            foreach (T el in this.elements)
            {
                buff.Append(el + "\n");

            }
            buff.Append("\n");
            return buff.ToString();
        }
    }
}
