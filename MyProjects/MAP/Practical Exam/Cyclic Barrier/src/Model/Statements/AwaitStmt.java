package Model.Statements;

import Model.Expressions.IExpr;
import Model.Expressions.VarExpr;
import Model.Pair;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;
import Exception.VariableNotDefined;

import java.util.List;

public class AwaitStmt implements IStmt {
    private String var;

    public AwaitStmt(String s){var=s;}

    @Override
    public ProgramState execute(ProgramState state){
        IDictionary<String,Integer> dic=state.getSymTable();
        IDictionary<Integer,Integer> heap=state.getHeap();
        IDictionary<Integer, Pair> barrier=state.getBarrier();
        IStack<IStmt> stack=state.getStack();
        if(!dic.exists(var)) throw new VariableNotDefined("Variable '"+var+"' does not exist in the Symbol Table!");
        IExpr e=new VarExpr(var);
        Integer ev=e.evaluate(dic,heap);

        if(!barrier.exists(ev)) throw new VariableNotDefined("Index not found in the Barrier Table!");

        Pair p=barrier.getValue(ev);
        Integer len=p.list.size();
        Integer n=p.nr;
        Integer id=state.getID();

        state.getMylock().lock();
        boolean yes=false;
        for(Integer i:p.list)
            if(i.equals(id)){
                yes=true;
                break;
            }


        if(n>len){
            if(yes){
                stack.add(this);
            }
            else
            {
                p.list.add(id);
                stack.add(this);
            }
        }
        state.getMylock().unlock();
        return null;
    }

    public String toString(){
        return "await("+var+")";
    }
}
