package Model;

import Model.Utilities.*;
import  Model.Statements.*;

import java.io.BufferedReader;
import java.util.Map;
import java.util.stream.Collectors;

public class ProgramState {
    private IStack<IStmt> stack;
    private IDictionary<String, Integer> SymTable;
    private IList<Integer> list;
    private IDictionary<Integer, BufferedReader> FileTable;
    private IDictionary<Integer, Integer> heap;

    public ProgramState(IStack<IStmt> stack, IDictionary<String, Integer> symTable, IList<Integer> list, IDictionary<Integer, BufferedReader> file,IDictionary<Integer, Integer> h) {
        this.stack = stack;
        this.SymTable = symTable;
        this.list = list;
        this.FileTable = file;
        this.heap=h;
    }

    public IStack<IStmt> getStack() {
        return stack;
    }

    public void setStack(IStack<IStmt> stack) {
        this.stack = stack;
    }

    public IDictionary<String, Integer> getSymTable() {
        return SymTable;
    }

    public void setFileTable(IDictionary<Integer, BufferedReader> table) {
        FileTable = table;
    }

    public IDictionary<Integer, BufferedReader> getFileTable() {
        return FileTable;
    }

    public void setHeap(IDictionary<Integer, Integer> table) {
        heap = table;
    }

    public void setHeapMap(Map<Integer, Integer> table) {
        heap.setMap(table);
    }

    public void setFileTableMap(Map<Integer, BufferedReader> table) {
        FileTable.setMap(table);
    }

    public void clearFileTable(){this.FileTable.clear();}

    public void clearFileFromSym(){this.SymTable.setMap(SymTable.getMap().entrySet().stream().
            filter(e->FileTable.getMap().containsKey(e)).collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue)));}

    public IDictionary<Integer, Integer> getHeap() {
        return heap;
    }

    public void setSymTable(IDictionary<String, Integer> symTable) {
        SymTable = symTable;
    }

    public IList<Integer> getList() {
        return list;
    }

    public void setList(IList<Integer> list) {
        this.list = list;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append("\nExeStack:\n");
        for(IStmt s : stack.getElements()) {
            sb.append(s).append("\n");
        }

        sb.append("\nSymTable:\n");
        for(String key : SymTable.getElements()){
            sb.append(key).append(" : ").append(SymTable.getValue(key)).append("\n");
        }

        sb.append("\nOut:\n");
        for(Integer i : list.getElements()){
            sb.append(i).append("\n");
        }

        sb.append("\nHeap:\n");
        for(Integer i : heap.getElements()){
            sb.append(i+" : "+heap.getValue(i)).append("\n");
        }

        sb.append("\nFileTable:\n");
        for(Integer i : FileTable.getElements()){
            sb.append(i+" : "+FileTable.getValue(i)).append("\n");
        }

        return sb.toString();
    }
}
