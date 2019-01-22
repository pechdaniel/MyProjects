package Model.Statements;

import Model.Expressions.BooleanExpr;
import Model.Expressions.IExpr;
import Model.Expressions.VarExpr;
import Model.ProgramState;
import Model.Utilities.IStack;

public class ForStmt implements IStmt {
    private IExpr expr1,expr2,expr3;
    private IStmt statement;

    public ForStmt(IExpr e1,IExpr e2,IExpr e3,IStmt s){
        this.expr1=e1;
        this.expr2=e2;
        this.expr3=e3;
        this.statement=s;
    }

    @Override
    public ProgramState execute(ProgramState state){
        IStack<IStmt> stack=state.getStack();
        IStmt s=new AssignStmt("v",expr1);
        IStmt s1=new AssignStmt("v",expr3);
        IStmt s2=new WhileStmt(expr2,new CompStmt(statement,s1));
        stack.add(s2);
        stack.add(s);
        return null;
    }

    public String toString(){
        return "for("+"v="+expr1+";"+expr2+";v="+expr3+") {"+statement+"}";
    }
}
