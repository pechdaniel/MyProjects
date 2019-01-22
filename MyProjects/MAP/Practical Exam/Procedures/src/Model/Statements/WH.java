package Model.Statements;

import Model.Expressions.IExpr;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Exception.VariableNotDefined;
import Model.Utilities.IStack;

public class WH implements IStmt {
    private String var;
    private IExpr expr;
    public WH(String s, IExpr e){ var=s; expr=e; }

    @Override
    public ProgramState execute(ProgramState state){
        IStack<IDictionary<String, Integer>> dic=state.getSyms();
        IDictionary<Integer,Integer> heap=state.getHeap();
        if(!dic.top().exists(var))
            throw new VariableNotDefined("Variable not found!");
        int addr=dic.top().getValue(var);
        if(!heap.exists(addr))
            throw new VariableNotDefined("Variable not found!");
        int val=expr.evaluate(dic,heap);
        heap.delete(addr);
        heap.setValue(addr,val);
        return null;
    }

    public String toString(){ return "wR("+var+","+expr+")"; }
}
