package Model.Statements;

import Model.Expressions.IExpr;
import Model.Expressions.VarExpr;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Exception.VariableNotDefined;
import Model.Utilities.IStack;
import java.io.IOException;

public class LockStmt implements IStmt {
    private String var;

    public LockStmt(String v){this.var=v;}

    @Override
    public ProgramState execute(ProgramState state)throws IOException {
        IDictionary<String,Integer> dic=state.getSymTable();
        IDictionary<Integer,Integer> heap=state.getHeap();
        IDictionary<Integer,Integer> lock=state.getLock();
        IStack<IStmt> stack=state.getStack();
        if(!dic.exists(var)) throw new VariableNotDefined("Variable '"+var+"' does not exist in the Symbol Table!");
        IExpr e=new VarExpr(var);
        Integer ev=e.evaluate(dic,heap);

        if(!lock.exists(ev)) throw new VariableNotDefined("Index not found in the Lock Table!");

        if(lock.getValue(ev)==-1) {lock.setValue(ev,state.getID());return null;}

        stack.add(this);
        return null;
    }

    public String toString(){
        return "lock("+var+")";
    }
}
