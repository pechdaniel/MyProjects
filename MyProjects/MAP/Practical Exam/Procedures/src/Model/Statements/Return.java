package Model.Statements;

import Model.ProgramState;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;

public class Return implements IStmt {
    public Return(){}

    @Override
    public ProgramState execute(ProgramState state){
        IStack<IDictionary<String, Integer>> dic=state.getSyms();
        dic.pop();
        return null;
    }

    public String toString(){
        return "return";
    }
}
