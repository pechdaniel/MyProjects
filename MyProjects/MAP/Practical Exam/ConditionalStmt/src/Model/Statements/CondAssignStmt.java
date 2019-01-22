package Model.Statements;

import Model.Expressions.IExpr;
import Model.ProgramState;
import Model.Utilities.IStack;

public class CondAssignStmt implements IStmt {
    private String v;
    private IExpr exp1,exp2,exp3;

    public CondAssignStmt(String v,IExpr e1,IExpr e2,IExpr e3){
        this.v=v;
        this.exp1=e1;
        this.exp2=e2;
        this.exp3=e3;
    }

    @Override
    public ProgramState execute(ProgramState state){
        IStack<IStmt> stack=state.getStack();
        IStmt s=new IfStmt(this.exp1,new AssignStmt(this.v,this.exp2),new AssignStmt(this.v,this.exp3));
        stack.add(s);
        return null;
    }

    public String toString(){
        return v+"="+exp1+"?"+exp2+":"+exp3;
    }
}
