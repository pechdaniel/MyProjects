package Model.Expressions;

import Model.Utilities.IDictionary;
import Model.Utilities.IStack;

public interface IExpr {
    int evaluate(IStack<IDictionary<String, Integer>> dic, IDictionary<Integer, Integer> heap);
}
