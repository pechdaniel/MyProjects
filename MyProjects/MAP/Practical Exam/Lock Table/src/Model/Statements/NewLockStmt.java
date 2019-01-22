package Model.Statements;

import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;

public class NewLockStmt implements IStmt {
    private String var;

    public NewLockStmt(String v){this.var=v;}

    @Override
    public ProgramState execute(ProgramState state){
        IDictionary<String,Integer> dic=state.getSymTable();
        IDictionary<Integer,Integer> heap=state.getHeap();
        IDictionary<Integer,Integer> lock=state.getLock();
        IStack<IStmt> stack=state.getStack();

        int i=1;
        while(true){
            if(lock.exists(i))
                i++;
            else break;
        }

        lock.setValue(i,-1);
        dic.setValue(var,i);
        return null;
    }

    public String toString(){
        return "newLock("+var+")";
    }
}
