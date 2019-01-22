package Model.Expressions;

import Model.Utilities.IDictionary;
import Model.Utilities.IStack;

public class ConstExpr implements IExpr {
    private int number;

    public ConstExpr(int nr){
        number=nr;
    }

    @Override
    public int evaluate(IStack<IDictionary<String, Integer>> dic, IDictionary<Integer, Integer> heap) {
        return number;
    }

    public String toString(){
        return "" + number;
    }
}
