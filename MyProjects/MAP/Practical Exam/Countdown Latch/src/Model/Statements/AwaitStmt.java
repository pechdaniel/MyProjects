package Model.Statements;

import Model.Expressions.IExpr;
import Model.Expressions.VarExpr;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;
import Exception.VariableNotDefined;

public class AwaitStmt implements IStmt {
    private String var;

    public AwaitStmt(String s){var=s;}

    @Override
    public ProgramState execute(ProgramState state){
        IDictionary<String,Integer> dic=state.getSymTable();
        IDictionary<Integer,Integer> heap=state.getHeap();
        IDictionary<Integer, Integer> latch=state.getLatch();
        IStack<IStmt> stack=state.getStack();
        if(!dic.exists(var)) throw new VariableNotDefined("Variable '"+var+"' does not exist in the Symbol Table!");
        IExpr e=new VarExpr(var);
        Integer ev=e.evaluate(dic,heap);

        if(!latch.exists(ev)) throw new VariableNotDefined("Index not found in the Latch Table!");

        if(latch.getValue(ev)!=0){
            stack.add(this);
        }
        return null;
    }

    public String toString(){
        return "await("+var+")";
    }
}
