package Model.Statements;

import Model.Expressions.*;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;

public class AssignStmt implements IStmt {
    private String id;
    private IExpr expr;

    public AssignStmt(String key, IExpr expression){
        id = key;
        expr = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) {
        IStack<IDictionary<String, Integer>> dic = state.getSyms();
        IDictionary<Integer, Integer> heap=state.getHeap();
        int val = expr.evaluate(dic,heap);
        dic.top().setValue(id, val);
        return null;
    }

    public String toString(){
        return id + "=" + expr;
    }
}
