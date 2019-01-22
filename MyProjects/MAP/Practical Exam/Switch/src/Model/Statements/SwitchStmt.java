package Model.Statements;

import Model.Expressions.BooleanExpr;
import Model.Expressions.IExpr;
import Model.ProgramState;
import Model.Utilities.IStack;

public class SwitchStmt implements IStmt {
    private IExpr exp,exp1,exp2;
    private IStmt stmt1,stmt2,stmt3;

    public SwitchStmt(IExpr e,IExpr e1,IStmt s1,IExpr e2,IStmt s2,IStmt s3){
        exp=e;
        exp1=e1;
        exp2=e2;
        stmt1=s1;
        stmt2=s2;
        stmt3=s3;
    }

    @Override
    public ProgramState execute(ProgramState state){
        IStack<IStmt> stack=state.getStack();
        IStmt s=new IfStmt(new BooleanExpr("==",exp,exp1),stmt1,new IfStmt(new BooleanExpr("==",exp,exp2),stmt2,stmt3));
        stack.add(s);
        return null;
    }

    public String toString(){
        return "switch("+exp+")(case "+exp1+":"+stmt1+")(case "+exp2+":"+stmt2+")(default:"+stmt3+")";
    }
}
