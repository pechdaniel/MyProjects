using System;
using System.Collections.Generic;
using System.Linq;
using System.Collections;
using System.Text;
using Interpreter.Exceptions;

namespace Interpreter.Model.Utilities
{
    public class MyDictionary<K, V> : IDictionary<K, V>
    {
        private Dictionary<K, V> elements = new Dictionary<K, V>();

        public MyDictionary()
        {
            this.elements = new Dictionary<K, V>();
        }

        public IEnumerator GetEnumerator()
        {
            return elements.GetEnumerator();
        }

        public void setValue(K key, V value)
        {
            elements.Add(key, value);
        }

        public void delete(K key)
        {
            elements.Remove(key);
        }

        public bool exists(K key)
        {
            return elements.ContainsKey(key);
        }

        public V getValue(K key)
        {
            if (!exists(key))
                throw new VariableNotDefined("Variable is missing!");
            return elements[key];
        }

        public void clear()
        {
            this.elements.Clear();
        }

        public List<V> getValues()
        {
            return elements.Values.ToList();
        }

        public void setMap(Dictionary<K, V> m) { elements = m; }

        public List<K> getElements()
        {
            return elements.Keys.ToList();
        }

        public Dictionary<K, V> getMap() { return this.elements; }

        public override string ToString()
        {
            StringBuilder buff = new StringBuilder();
            foreach (KeyValuePair<K, V> pair in this.elements)
            {
                buff.Append(pair.Key);
                buff.Append(":");
                buff.Append(pair.Value);
                buff.Append("\n");
            }
            buff.Append("\n");
            return buff.ToString();
        }
    }
}
