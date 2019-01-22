package Model.Expressions;

import Model.Utilities.IDictionary;
import Exception.InvalidOperator;
import Model.Utilities.IStack;

public class BooleanExpr implements IExpr{
    private String operator;
    private IExpr left, right;

    public BooleanExpr(String op, IExpr l, IExpr r){
        operator = op;
        left = l;
        right = r;
    }
    public String getOperator(){return operator;}
    public IExpr getLeft(){return left;}
    public IExpr getRight(){return right;}

    @Override
    public int evaluate(IStack<IDictionary<String, Integer>> dic, IDictionary<Integer, Integer> heap) {
        int left = this.left.evaluate(dic,heap);
        int right = this.right.evaluate(dic,heap);

        switch (operator){
            case "<":
                if(left< right)return 1; else return 0;
            case ">":
                if(left> right)return 1; else return 0;
            case "<=":
                if(left<=right)return 1; else return 0;
            case ">=":
                if(left>=right)return 1; else return 0;
            case "==":
                if(left==right)return 1; else return 0;
            case "!=":
                if(left!=right)return 1; else return 0;

        }
        throw new InvalidOperator("Invalid operator!");
    }

    public String toString(){
        return "" + left + operator + right;
    }
}
