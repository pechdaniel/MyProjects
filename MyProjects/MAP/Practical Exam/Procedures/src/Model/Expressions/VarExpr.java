package Model.Expressions;

import Model.Utilities.IDictionary;
import Model.Utilities.IStack;

public class VarExpr implements IExpr {
    private String id;

    public VarExpr(String v){
        id=v;
    }
    @Override
    public int evaluate(IStack<IDictionary<String, Integer>> dic, IDictionary<Integer, Integer> heap){
        return dic.top().getValue(id);
    }

    public String toString(){
        return id;
    }
}
