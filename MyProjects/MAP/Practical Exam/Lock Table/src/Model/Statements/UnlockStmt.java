package Model.Statements;

import Model.Expressions.IExpr;
import Model.Expressions.VarExpr;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;
import Exception.VariableNotDefined;

public class UnlockStmt implements IStmt {
    private String var;

    public UnlockStmt(String v){this.var=v;}

    @Override
    public ProgramState execute(ProgramState state){
        IDictionary<String,Integer> dic=state.getSymTable();
        IDictionary<Integer,Integer> heap=state.getHeap();
        IDictionary<Integer,Integer> lock=state.getLock();
        IStack<IStmt> stack=state.getStack();
        if(!dic.exists(var)) throw new VariableNotDefined("Variable '"+var+"' does not exist in the Symbol Table!");
        IExpr e=new VarExpr(var);
        Integer ev=e.evaluate(dic,heap);

        if(!lock.exists(ev)) return null;

        if(lock.getValue(ev)==state.getID()) lock.setValue(ev,-1);
        return null;
    }

    public String toString(){
        return "unlock("+var+")";
    }
}
