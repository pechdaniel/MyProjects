package Model.Statements;

import Model.Expressions.IExpr;
import Model.Expressions.VarExpr;
import Model.Pair;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;
import Exception.VariableNotDefined;

public class AquireStmt implements IStmt {
    private String var;

    public AquireStmt(String s){var=s;}

    @Override
    public ProgramState execute(ProgramState state){
        IDictionary<String,Integer> dic=state.getSymTable();
        IDictionary<Integer,Integer> heap=state.getHeap();
        IDictionary<Integer, Pair> semaphore=state.getSemaphore();
        IStack<IStmt> stack=state.getStack();
        if(!dic.exists(var)) throw new VariableNotDefined("Variable '"+var+"' does not exist in the Symbol Table!");
        IExpr e=new VarExpr(var);
        Integer ev=e.evaluate(dic,heap);

        if(!semaphore.exists(ev)) throw new VariableNotDefined("Index not found in the Semaphore Table!");

        Pair p=semaphore.getValue(ev);
        Integer len=p.list.size();
        Integer n=p.nr;
        Integer id=state.getID();
        boolean yes=false;
        for(Integer i:p.list)
            if(i==id){
                yes=true;
                break;
            }
        if(n>len){
            if(yes){
                return null;
            }
            else
            {
                p.list.add(id);
                return null;
            }
        }
        else stack.add(this);
        return null;
    }

    public String toString(){
        return "aquire("+var+")";
    }
}
