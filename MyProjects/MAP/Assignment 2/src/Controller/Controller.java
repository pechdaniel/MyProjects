package Controller;

import Model.ProgramState;
import Model.Statements.IStmt;
import Model.Utilities.Dictionary;
import Model.Utilities.IDictionary;
import Model.Utilities.IStack;
import Repository.IRepo;
import Exception.EmptyStack;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.stream.*;

public class Controller {
    private IRepo repo;

    public Controller(IRepo repo) {
        this.repo = repo;
    }

    public ProgramState oneStep(ProgramState state){
        try{
        IStack<IStmt> stack = state.getStack();
        if(stack.isEmpty())
            throw new EmptyStack("The stack is empty!");
        IStmt currentStmt = stack.pop();
        return currentStmt.execute(state);}
        catch (IOException e){
            System.out.println(e.getMessage());
            System.exit(0);
        }
        return null;
    }
    public Map<Integer,Integer> conservativeGarbageCollector(List<Integer> symTableValues,
                                                      Map<Integer,Integer> heap){
        return heap.entrySet().stream()
                .filter(e->symTableValues.contains(e.getKey()))
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));}

    public ProgramState closeAllOpenFiles(ProgramState prg){
            prg.clearFileFromSym();
            List<BufferedReader> myList=prg.getFileTable().getValues();
            myList.stream().forEach(el->{try{el.close();}catch(IOException e){System.out.println(e.getMessage());}});
            prg.clearFileTable();
            return prg;
    }

    public void allSteps(){
        ProgramState prg = repo.getCurrentPrg();
        try{
        while(!prg.getStack().isEmpty()){
            oneStep(prg);
            prg.setHeapMap(conservativeGarbageCollector(prg.getSymTable().getValues(),prg.getHeap().getMap()));
            this.repo.logProgramStateExec("log");
            System.out.println("-----------");
            System.out.println(prg);
        }}
        catch(IOException e){
            System.out.println(e.getMessage());
        }
        finally {
            prg=this.closeAllOpenFiles(prg);
            System.out.println("-----------");
            System.out.println(prg);
        }
    }

    @Override
    public String toString(){
        return "Controller: " + repo.toString();
    }
}
