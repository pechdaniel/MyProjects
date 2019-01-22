package Model.Statements;

import Model.ProgramState;
import Model.Utilities.IStack;

public class SleepStmt implements IStmt {
    private Integer nr;

    public SleepStmt(Integer i){nr=i;}

    @Override
    public ProgramState execute(ProgramState state){
        IStack<IStmt> stack=state.getStack();
        if(nr!=0)
            stack.add(new SleepStmt(nr-1));
        return null;
    }

    public String toString(){
        return "seleep("+nr+")";
    }
}
