package Model;

import Model.Statements.IStmt;

import java.util.List;

public class Pair {
    public List<String> list;
    public IStmt stmt;
    public Pair(List<String> l,IStmt s){list=l;stmt=s;}
}
