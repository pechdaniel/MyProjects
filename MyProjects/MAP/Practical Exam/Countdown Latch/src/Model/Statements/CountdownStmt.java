package Model.Statements;

import Model.Expressions.IExpr;
import Model.Expressions.VarExpr;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IList;
import Model.Utilities.IStack;
import Exception.VariableNotDefined;

import java.util.List;

public class CountdownStmt implements IStmt {
    private String var;

    public CountdownStmt(String s){var=s;}

    @Override
    public ProgramState execute(ProgramState state){
        IDictionary<String,Integer> dic=state.getSymTable();
        IDictionary<Integer,Integer> heap=state.getHeap();
        IDictionary<Integer, Integer> latch=state.getLatch();
        IList<Integer> list=state.getList();
        IStack<IStmt> stack=state.getStack();
        if(!dic.exists(var)) throw new VariableNotDefined("Variable '"+var+"' does not exist in the Symbol Table!");
        IExpr e=new VarExpr(var);
        Integer ev=e.evaluate(dic,heap);

        if(!latch.exists(ev)) {return null;}
        if(latch.getValue(ev)>0){
            latch.setValue(ev,latch.getValue(ev)-1);
            list.add(state.getID());
        }
        return null;
    }

    public String toString(){
        return "countdwon("+var+")";
    }
}
