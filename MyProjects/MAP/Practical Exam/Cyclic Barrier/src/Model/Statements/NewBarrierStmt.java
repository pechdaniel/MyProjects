package Model.Statements;

import Model.Expressions.IExpr;
import Model.Pair;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;

import java.util.ArrayList;
import java.util.List;

public class NewBarrierStmt implements IStmt {
    private String var;
    private IExpr expr;

    public NewBarrierStmt(String s,IExpr e){var=s;expr=e;}

    @Override
    public ProgramState execute(ProgramState state){
        IDictionary<String,Integer> dic=state.getSymTable();
        IDictionary<Integer,Integer> heap=state.getHeap();
        IDictionary<Integer, Pair> barrier=state.getBarrier();
        IStack<IStmt> stack=state.getStack();

        Integer number=expr.evaluate(dic,heap);

        state.getMylock().lock();
        int i=1;
        while(true){
            if(barrier.exists(i))
                i++;
            else break;
        }


        List<Integer> l=new ArrayList<>();
        Pair p=new Pair(number,l);
        barrier.setValue(i,p);
        state.getMylock().unlock();
        dic.setValue(var,i);
        return null;
    }

    public String toString(){
        return "newBarrier("+var+","+expr+")";
    }
}
