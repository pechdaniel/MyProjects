package Model.Statements;

import Model.Expressions.BooleanExpr;
import Model.Expressions.IExpr;
import Model.Expressions.NotExpr;
import Model.ProgramState;
import Model.Utilities.IStack;

import java.time.chrono.IsoChronology;

public class RepeatUntilStmt implements IStmt {
    private BooleanExpr expr;
    private IStmt stmt;

    public RepeatUntilStmt(IStmt s,BooleanExpr e){
        this.expr=e;
        this.stmt=s;
    }

    @Override
    public ProgramState execute(ProgramState state){
        IStack<IStmt> stack=state.getStack();
        IExpr expr1=new NotExpr(expr);
        IStmt s=new CompStmt(stmt,new WhileStmt(expr1,stmt));
        stack.add(s);
        return null;
    }
    public String toString(){
        return "repeat "+stmt+" until "+expr;
    }
}
