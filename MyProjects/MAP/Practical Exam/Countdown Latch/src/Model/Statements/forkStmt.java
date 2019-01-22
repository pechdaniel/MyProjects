package Model.Statements;

import Model.ProgramState;
import Model.Utilities.*;

import java.io.BufferedReader;

public class forkStmt implements IStmt {
    private IStmt stmt;

    public forkStmt(IStmt s){stmt=s;}

    @Override
    public ProgramState execute(ProgramState state){
        IStack<IStmt> e = new Stack<>();
        e.add(stmt);
        IDictionary<String, Integer> s = state.getSymTable().copy();
        IList<Integer> o = state.getList();
        IDictionary<Integer, BufferedReader> f=state.getFileTable();
        IDictionary<Integer, Integer> h=state.getHeap();
        IDictionary<Integer, Integer> l=state.getLatch();
        ProgramState prg=new ProgramState(e,s,o,f,h,l);
        prg.setMylock(state.getMylock());

        prg.setID(state.getAvailable());
        return prg;
    }

    public String toString(){
        return "fork("+stmt+")";
    }
}
