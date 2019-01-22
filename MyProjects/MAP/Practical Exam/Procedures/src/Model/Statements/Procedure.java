package Model.Statements;

import Model.Pair;
import Model.ProgramState;
import Model.Utilities.IDictionary;

import java.util.List;

public class Procedure implements IStmt {
    private String name;
    private List<String> vars;
    private IStmt stmt;

    public Procedure(String n, List<String> l, IStmt s){name=n;vars=l;stmt=s;}

    @Override
    public ProgramState execute(ProgramState state){
        IDictionary<String, Pair> proc=state.getProc();
        Pair p=new Pair(vars,stmt);
        proc.setValue(name,p);
        return null;
    }

    public String toString(){
        return ""+name+"("+vars+")"+stmt;
    }
}
