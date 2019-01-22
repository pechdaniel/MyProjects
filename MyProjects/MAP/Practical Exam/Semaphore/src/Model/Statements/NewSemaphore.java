package Model.Statements;

import Model.Expressions.IExpr;
import Model.Pair;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;

import java.util.ArrayList;
import java.util.List;

public class NewSemaphore implements IStmt {
    private String var;
    private IExpr expr;

    public NewSemaphore(String s,IExpr e){var=s;expr=e;}

    @Override
    public ProgramState execute(ProgramState state){
        IDictionary<String,Integer> dic=state.getSymTable();
        IDictionary<Integer,Integer> heap=state.getHeap();
        IDictionary<Integer, Pair> semaphore=state.getSemaphore();
        IStack<IStmt> stack=state.getStack();

        Integer number=expr.evaluate(dic,heap);

        int i=1;
        while(true){
            if(semaphore.exists(i))
                i++;
            else break;
        }
        List<Integer> l=new ArrayList<>();
        Pair p=new Pair(number,l);
        semaphore.setValue(i,p);
        dic.setValue(var,i);
        return null;
    }

    public String toString(){
        return "newSemaphore("+var+","+expr+")";
    }
}
