using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace Interpreter.Model.Utilities
{
    public interface IDictionary<K, V> : IEnumerable
    {
        void setValue(K key, V value);
        Dictionary<K, V> getMap();
        void delete(K key);
        V getValue(K key);
        void clear();
        void setMap(Dictionary<K, V> m);
        List<V> getValues();
        bool exists(K key);
        List<K> getElements();
    }
}
