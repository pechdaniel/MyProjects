package Model.Statements;

import Model.Expressions.IExpr;
import Model.Pair;
import Model.ProgramState;
import Model.Utilities.Dictionary;
import Model.Utilities.IDictionary;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Exception.VariableNotDefined;
import Model.Utilities.IStack;

public class Call implements IStmt {
    private String fname;
    private List<IExpr> vars;
    private IStmt stmt;

    public Call(String name,List<IExpr> v){fname=name;vars=v;}

    @Override
    public ProgramState execute(ProgramState state)throws IOException {
        if(!state.getProc().exists(fname)) throw new VariableNotDefined("Procedure '"+fname+"' does not exist!");
        IStack<IDictionary<String, Integer>> dic=state.getSyms();
        IStack<IStmt> stack=state.getStack();
        IDictionary<Integer, Integer> heap=state.getHeap();
        Pair pr =state.getProc().getValue(fname);
        stmt=pr.stmt;
        List<String> v=pr.list;
        List<Integer> val=new ArrayList<>();
        for(IExpr exp:vars){
            val.add(exp.evaluate(dic,heap));
        }
        IDictionary<String, Integer> sym = new Dictionary<String, Integer>();
        int i=0;
        for(String stg:v){
            sym.setValue(stg,val.get(i));
            i++;
        }
        dic.add(sym);
        IStmt ret=new Return();
        stack.add(ret);
        stack.add(stmt);
        return null;
    }

    public String toString(){
        return "call "+fname+"("+vars+")";
    }
}
