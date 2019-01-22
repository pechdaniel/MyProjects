package Model.Statements;

import Model.Pair;
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
        IStack<IDictionary<String, Integer>> s=new Stack<>();
        IDictionary<String, Integer> k=new Dictionary<>();
        k.setMap(state.getSymTable().copy().getMap());
        s.add(k);
        IList<Integer> o = state.getList();
        IDictionary<Integer, BufferedReader> f=state.getFileTable();
        IDictionary<Integer, Integer> h=state.getHeap();
        IDictionary<String, Pair> p=state.getProc();

        ProgramState prg=new ProgramState(e,s,o,f,h,p);
        prg.setMySym(state.getSymTable().copy());
        prg.setID(state.getAvailable());
        return prg;
    }

    public String toString(){
        return "fork("+stmt+")";
    }
}
