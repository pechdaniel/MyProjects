package Model.Statements;

import Model.Expressions.IExpr;
import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;

public class NewLatchStmt implements IStmt {
    private String var;
    private IExpr expr;

    public NewLatchStmt(String s,IExpr e){var=s;expr=e;}

    @Override
    public ProgramState execute(ProgramState state){
        IDictionary<String,Integer> dic=state.getSymTable();
        IDictionary<Integer,Integer> heap=state.getHeap();
        IDictionary<Integer, Integer> latch=state.getLatch();
        IStack<IStmt> stack=state.getStack();

        Integer number=expr.evaluate(dic,heap);

        int i=1;
        while(true){
            if(latch.exists(i))
                i++;
            else break;
        }
        latch.setValue(i,number);
        dic.setValue(var,i);
        return null;
    }

    public String toString(){
        return "newLatch("+var+","+expr+")";
    }
}
