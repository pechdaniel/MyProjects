package sample;

import Controller.Controller;
import Model.Expressions.*;
import Model.ProgramState;
import Model.Statements.*;
import Model.Utilities.*;
import Repository.IRepo;
import Repository.Repository;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;

import javafx.event.ActionEvent;
import javafx.scene.control.cell.PropertyValueFactory;
import sample.TableViews.FileTableView;
import sample.TableViews.HeapTableView;
import sample.TableViews.LockTableView;
import sample.TableViews.SymTableView;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class MyFXController{
    @FXML
    private ListView<String> MenuList;
    private List<Controller> menu=new ArrayList<Controller>();
    @FXML
    private TableView<HeapTableView> HeapTable;
    @FXML
    private TableColumn<HeapTableView,Integer> HeapK;
    @FXML
    private TableColumn<HeapTableView,Integer> HeapV;

    @FXML
    private TableView<LockTableView> LockTable;
    @FXML
    private TableColumn<LockTableView,Integer> LockK;
    @FXML
    private TableColumn<LockTableView,Integer> LockV;

    @FXML
    private TableView<FileTableView> FileTable;
    @FXML
    private TableColumn<FileTableView,Integer> FileK;
    @FXML
    private TableColumn<FileTableView,String> FileV;

    @FXML
    private TableView<SymTableView> SymbolTable;
    @FXML
    private TableColumn<SymTableView,String> SymK;
    @FXML
    private TableColumn<SymTableView,Integer> SymV;

    @FXML
    private TextField ProgramStateText;
    @FXML
    private ListView<Integer> ProgramIDList;
    @FXML
    private ListView<Integer> OutputList;
    @FXML
    private ListView<String> StackList;

    private Controller controller;
    private boolean selected;
    private ProgramState selectedState;
    private Integer id;
    private Integer totalProcesses;
    private List<ProgramState> progList;
    private Lock mylock;

    @FXML
    public void runButtonAction(){
        if(this.selected) {
            Alert a=new Alert(Alert.AlertType.INFORMATION,"The current program has not finished!\nWait for it to terminate.");
            a.show();
            return;
        }
        this.id=1;
        int k=this.MenuList.getSelectionModel().getSelectedIndex();
        this.controller=this.menu.get(k);
        this.selected=true;
        this.totalProcesses=0;
        ExecutorService e= Executors.newFixedThreadPool(2);
        this.controller.setExecutor(e);
        this.progList=new ArrayList<>();
        this.progList=controller.removeCompletedPrg(controller.getRepo().getPrgList());
        this.controller.setPrglist(progList);
        this.oneStep();
    }

    public void updateController(){
        progList=controller.getRepo().getPrgList();
        List<Integer> nr=new ArrayList<Integer>();
        for(ProgramState p:progList){
            nr.add(p.getID());
        }
        ObservableList<Integer> nr1=FXCollections.observableList(nr);
        ProgramIDList.setItems(nr1);
    }

    public void setAllForID(){
        progList=controller.getRepo().getPrgList();
        this.selectedState=controller.getProgramByID(progList,this.id);
        if(selectedState==null) return;
        this.setExeStack();
        this.setOutput();
        this.setHeap();
        this.setFileTable();
        this.setSymTable();
        this.setLockTable();
    }

    public void setLockTable(){
        ObservableList<LockTableView> l=FXCollections.observableArrayList();
        for(Integer k:selectedState.getLock().getElements()){
            l.add(new LockTableView(k,selectedState.getLock().getValue(k)));
        }
        this.LockTable.setItems(l);
    }

    public void setOutput(){
        ObservableList<Integer> out=FXCollections.observableList(selectedState.getOut());
        OutputList.setItems(out);
    }

    public void setExeStack(){
        ObservableList<String> stack=FXCollections.observableList(selectedState.getStackListString());
        StackList.setItems(stack);
    }

    public void setSymTable(){
        ObservableList<SymTableView> l=FXCollections.observableArrayList();
        for(String k:selectedState.getSymTable().getElements()){
            l.add(new SymTableView(k,selectedState.getSymTable().getValue(k)));
        }
        this.SymbolTable.setItems(l);
    }

    public void setFileTable(){
        ObservableList<FileTableView> l=FXCollections.observableArrayList();
        for(Integer k:selectedState.getFileTable().getElements()){
            l.add(new FileTableView(k,selectedState.getFileTable().getValue(k).toString()));
        }
        this.FileTable.setItems(l);
    }

    public void setHeap(){
        ObservableList<HeapTableView> l=FXCollections.observableArrayList();
        for(Integer k:selectedState.getHeap().getElements()){
            l.add(new HeapTableView(k,selectedState.getHeap().getValue(k)));
        }
        this.HeapTable.setItems(l);
    }

    public void modifySelectedID(){
        int k=this.ProgramIDList.getSelectionModel().getSelectedItem();
        this.id=k;
        this.setAllForID();
    }

    public void clearAll(){
        this.selected = false;
        StackList.getItems().clear();
        SymbolTable.getItems().clear();
        HeapTable.getItems().clear();
        OutputList.getItems().clear();
        ProgramStateText.setText("");
        FileTable.getItems().clear();
        ProgramIDList.getItems().clear();
    }

    @FXML
    public void oneStep(){
        try {
            if (!this.selected) {
                Alert a = new Alert(Alert.AlertType.INFORMATION, "Select a statement first!");
                a.show();
                return;
            }
            progList = controller.getRepo().getPrgList();
            this.setAllForID();
            if (progList.size() == 0) {
                this.clearAll();
                controller.exShutdown();
                progList.stream().forEach(e->{controller.closeAllOpenFiles(e);
                    try{controller.getRepo().logProgramStateExec(e);}catch(IOException ex){Alert a = new Alert(Alert.AlertType.ERROR, ex.getMessage());a.show();}});
                Alert a = new Alert(Alert.AlertType.INFORMATION, "The program has been executed successfully!");
                a.show();
                return;
            }

            this.progList= controller.getRepo().getPrgList();
            this.progList.stream().forEach(e->e.setHeapMap(controller.conservativeGarbageCollector(e.getSymTable().getValues(),e.getHeap().getMap())));
            this.controller.oneStepForAllPrgFX(progList);
            this.progList = controller.getRepo().getPrgList();
            this.totalProcesses = controller.processesAdd(controller.getRepo().getPrgList(), totalProcesses);
            this.setAllForID();
            this.controller.setPrglist(controller.removeCompletedPrg(controller.getRepo().getPrgList()));
            this.updateController();

            ProgramStateText.setText(totalProcesses.toString());
        }
        catch(Exception e){
            this.selected=false;
            controller.exShutdown();
            this.clearAll();
            Alert a = new Alert(Alert.AlertType.ERROR, e.getMessage());
            a.show();
        }
    }

    @FXML
    public void initialize(){
        mylock=SelectController.mylock;
        this.controller=SelectController.controller;

        this.HeapK.setCellValueFactory(new PropertyValueFactory<>("address"));
        this.HeapV.setCellValueFactory(new PropertyValueFactory<>("value"));

        this.FileK.setCellValueFactory(new PropertyValueFactory<>("identifier"));
        this.FileV.setCellValueFactory(new PropertyValueFactory<>("file"));

        this.SymK.setCellValueFactory(new PropertyValueFactory<>("variable"));
        this.SymV.setCellValueFactory(new PropertyValueFactory<>("value"));

        this.LockK.setCellValueFactory(new PropertyValueFactory<>("lk"));
        this.LockV.setCellValueFactory(new PropertyValueFactory<>("lv"));


        IStack<IStmt> ExeStack1 = new Stack<>();
        IDictionary<String, Integer> SymTable1 = new Dictionary<String, Integer>();
        IList<Integer> out1 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable1=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap1=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock1=new Dictionary<Integer, Integer>();
        IStmt expr1 = new CompStmt(new AssignStmt("v", new ConstExpr(2)),
                new PrintStmt(new VarExpr("v")));
        ExeStack1.add(expr1);
        ProgramState prgCurrent1 = new ProgramState(ExeStack1, SymTable1, out1,fileTable1,heap1,lock1);
        prgCurrent1.setMylock(mylock);
        IRepo repo1 = new Repository();
        repo1.addPrg(prgCurrent1);
        Controller ctrl1 = new Controller(repo1);

        IStack<IStmt> ExeStack2 = new Stack<>();
        IDictionary<String, Integer> SymTable2 = new Dictionary<String, Integer>();
        IList<Integer> out2 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable2=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap2=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock2=new Dictionary<Integer, Integer>();
        IStmt expr2 = new CompStmt(new AssignStmt("a", new ArithmExpr("+", new ConstExpr(2),
                new ArithmExpr("*", new ConstExpr(3), new ConstExpr(5)))), new CompStmt(new AssignStmt("b",
                new ArithmExpr("+", new VarExpr("a"), new ConstExpr(1))), new PrintStmt(new VarExpr("b"))));
        ExeStack2.add(expr2);
        ProgramState prgCurrent2 = new ProgramState(ExeStack2, SymTable2, out2,fileTable2,heap2,lock2);
        prgCurrent2.setMylock(mylock);
        IRepo repo2 = new Repository();
        repo2.addPrg(prgCurrent2);
        Controller ctrl2 = new Controller(repo2);

        IStack<IStmt> ExeStack3 = new Stack<>();
        IDictionary<String, Integer> SymTable3 = new Dictionary<String, Integer>();
        IList<Integer> out3 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable3=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap3=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock3=new Dictionary<Integer, Integer>();
        IStmt expr3 = new CompStmt(new AssignStmt("a", new ArithmExpr("-", new ConstExpr(2), new ConstExpr(2))),
                new CompStmt(new IfStmt(new VarExpr("a"), new AssignStmt("v", new ConstExpr(2)), new AssignStmt("v",
                        new ConstExpr(3))), new PrintStmt(new VarExpr("v"))));
        ExeStack3.add(expr3);
        ProgramState prgCurrent3 = new ProgramState(ExeStack3, SymTable3, out3,fileTable3,heap3,lock3);
        prgCurrent3.setMylock(mylock);
        IRepo repo3 = new Repository();
        repo3.addPrg(prgCurrent3);
        Controller ctrl3 = new Controller(repo3);

        IStack<IStmt> ExeStack4 = new Stack<>();
        IDictionary<String, Integer> SymTable4 = new Dictionary<String, Integer>();
        IList<Integer> out4 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable4=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap4=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock4=new Dictionary<Integer, Integer>();
        IStmt expr4=new CompStmt(
                new OpenRFileStmt("var_f","C:\\Users\\pechd\\IdeaProjects\\For Stmt\\Example.txt"),new CompStmt(
                new ReadFileStmt(new VarExpr("var_f"),"var_c"),new CompStmt(
                new PrintStmt(new VarExpr("var_c")),new CompStmt(
                new IfStmt(new VarExpr("var_c")
                        ,new CompStmt(new ReadFileStmt(new VarExpr("var_f"),"var_c"),new PrintStmt(new VarExpr("var_c"))),new PrintStmt(new ConstExpr(0))),
                new CloseRFileStmt(new VarExpr("var_f"))))));
        ExeStack4.add(expr4);
        ProgramState prgCurrent4=new ProgramState(ExeStack4,SymTable4,out4,fileTable4,heap4,lock4);
        prgCurrent4.setMylock(mylock);
        IRepo repo4=new Repository();
        repo4.addPrg(prgCurrent4);
        Controller ctrl4=new Controller(repo4);

        IStack<IStmt> ExeStack5 = new Stack<>();
        IDictionary<String, Integer> SymTable5 = new Dictionary<String, Integer>();
        IList<Integer> out5 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable5=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap5=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock5=new Dictionary<Integer, Integer>();
        IStmt expr5 = new CompStmt(
                new AssignStmt("v",new ConstExpr(10)), new CompStmt(
                new New("v",new ConstExpr(20)),new CompStmt(
                new New("a",new ConstExpr(22)),new CompStmt(
                new WH("a",new ConstExpr(30)),new CompStmt(
                new PrintStmt(new VarExpr("a")),new CompStmt(
                new PrintStmt(new RH("a")),new AssignStmt("a",new ConstExpr(0))
        ))))));
        ExeStack5.add(expr5);
        ProgramState prgCurrent5=new ProgramState(ExeStack5,SymTable5,out5,fileTable5,heap5,lock5);
        prgCurrent5.setMylock(mylock);
        IRepo repo5=new Repository();
        repo5.addPrg(prgCurrent5);
        Controller ctrl5=new Controller(repo5);

        IStack<IStmt> ExeStack6 = new Stack<>();
        IDictionary<String, Integer> SymTable6 = new Dictionary<String, Integer>();
        IList<Integer> out6 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable6=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap6=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock6=new Dictionary<Integer, Integer>();
        IStmt expr6 = new CompStmt(new AssignStmt("v",new ConstExpr(7)),
                new CompStmt(new WhileStmt(new ArithmExpr("-",new VarExpr("v"),new ConstExpr(4)),new CompStmt(
                        new PrintStmt(new VarExpr("v")),new AssignStmt("v",new ArithmExpr("-",new VarExpr("v"),new ConstExpr(1)))
                )),new PrintStmt(new VarExpr("v"))));
        ExeStack6.add(expr6);
        ProgramState prgCurrent6 = new ProgramState(ExeStack6, SymTable6, out6,fileTable6,heap6,lock6);
        prgCurrent6.setMylock(mylock);
        IRepo repo6 = new Repository();
        repo6.addPrg(prgCurrent6);
        Controller ctrl6 = new Controller(repo6);

        IStack<IStmt> ExeStack7 = new Stack<>();
        IDictionary<String, Integer> SymTable7 = new Dictionary<String, Integer>();
        IList<Integer> out7 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable7=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap7=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock7=new Dictionary<Integer, Integer>();
        IStmt expr7 = new OpenRFileStmt("var_f","C:\\Users\\pechd\\IdeaProjects\\For Stmt\\Example.txt");
        ExeStack7.add(expr7);
        ProgramState prgCurrent7 = new ProgramState(ExeStack7, SymTable7, out7,fileTable7,heap7,lock7);
        prgCurrent7.setMylock(mylock);
        IRepo repo7 = new Repository();
        repo7.addPrg(prgCurrent7);
        Controller ctrl7 = new Controller(repo7);

        IStack<IStmt> ExeStack8 = new Stack<>();
        IDictionary<String, Integer> SymTable8 = new Dictionary<String, Integer>();
        IList<Integer> out8 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable8=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap8=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock8=new Dictionary<Integer, Integer>();
        IStmt expr8 = new CompStmt(new AssignStmt("v",new ConstExpr(10)),new CompStmt(
                new New("a",new ConstExpr(22)),new CompStmt(
                new forkStmt(new CompStmt(new WH("a",new ConstExpr(30)),new CompStmt(
                        new AssignStmt("v",new ConstExpr(32)),new CompStmt(
                        new PrintStmt(new VarExpr("v")),new PrintStmt(new RH("a"))
                )))),new CompStmt(
                new PrintStmt(new VarExpr("v")),new PrintStmt(new RH("a"))
        ))));
        ExeStack8.add(expr8);
        ProgramState prgCurrent8 = new ProgramState(ExeStack8, SymTable8, out8,fileTable8,heap8,lock8);
        prgCurrent8.setMylock(mylock);
        IRepo repo8 = new Repository();
        repo8.addPrg(prgCurrent8);
        Controller ctrl8 = new Controller(repo8);

        IStack<IStmt> ExeStack9 = new Stack<>();
        IDictionary<String, Integer> SymTable9 = new Dictionary<String, Integer>();
        IList<Integer> out9 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable9=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap9=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock9=new Dictionary<Integer, Integer>();
        IStmt expr9 =new CompStmt( new AssignStmt("v",new ConstExpr(20)),new CompStmt(new ForStmt(new ConstExpr(0),new BooleanExpr("<",new VarExpr("v"),new ConstExpr(3)),new ArithmExpr("+",new VarExpr("v"),new ConstExpr(1)),new forkStmt(new CompStmt(new PrintStmt(new VarExpr("v")),new AssignStmt("v",new ArithmExpr("+",new VarExpr("v"),new ConstExpr(1)))))), new PrintStmt(new ArithmExpr("*",new VarExpr("v"),new ConstExpr(10)))));
        ExeStack9.add(expr9);
        ProgramState prgCurrent9 = new ProgramState(ExeStack9, SymTable9, out9,fileTable9,heap9,lock9);
        prgCurrent9.setMylock(mylock);
        IRepo repo9 = new Repository();
        repo9.addPrg(prgCurrent9);
        Controller ctrl9 = new Controller(repo9);

        IStack<IStmt> ExeStack10 = new Stack<>();
        IDictionary<String, Integer> SymTable10 = new Dictionary<String, Integer>();
        IList<Integer> out10 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable10=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap10=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock10=new Dictionary<Integer, Integer>();
        IStmt expr10 =new CompStmt(new AssignStmt("v",new ConstExpr(0)),new RepeatUntilStmt(new CompStmt(new PrintStmt(new VarExpr("v")),new AssignStmt("v",new ArithmExpr("+",new VarExpr("v"),new ConstExpr(1)))),new BooleanExpr("==",new VarExpr("v"),new ConstExpr(3))));
        ExeStack10.add(expr10);
        ProgramState prgCurrent10 = new ProgramState(ExeStack10, SymTable10, out10,fileTable10,heap10,lock10);
        prgCurrent10.setMylock(mylock);
        IRepo repo10 = new Repository();
        repo10.addPrg(prgCurrent10);
        Controller ctrl10 = new Controller(repo10);

        IStack<IStmt> ExeStack11 = new Stack<>();
        IDictionary<String, Integer> SymTable11 = new Dictionary<String, Integer>();
        IList<Integer> out11 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable11=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap11=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Integer> lock11=new Dictionary<Integer, Integer>();
        IStmt a1=new CompStmt(new New("v1",new ConstExpr(20)),new New("v2",new ConstExpr(30)));
        IStmt a2=new CompStmt(new NewLockStmt("x"),new forkStmt(new CompStmt(new forkStmt(new CompStmt(new LockStmt("x"),new CompStmt(new WH("v1",new ArithmExpr("-",new RH("v1"),new ConstExpr(1))),new UnlockStmt("x")))),new CompStmt(new LockStmt("x"),new CompStmt(new WH("v1",new ArithmExpr("+",new RH("v1"),new ConstExpr(1))),new UnlockStmt("x"))))));
        IStmt a3=new CompStmt(new LockStmt("q"),new forkStmt(new CompStmt(new forkStmt(new CompStmt(new LockStmt("q"),new CompStmt(new WH("v2",new ArithmExpr("+",new RH("v2"),new ConstExpr(5))),new UnlockStmt("q")))),new CompStmt(new AssignStmt("m",new ConstExpr(100)),new CompStmt(new LockStmt("q"),new CompStmt(new WH("v2",new ArithmExpr("+",new RH("v2"),new ConstExpr(1))),new UnlockStmt("q")))))));
        IStmt a4=new CompStmt(new AssignStmt("z",new ConstExpr(200)),new CompStmt(new AssignStmt("z",new ConstExpr(300)),new AssignStmt("z",new ConstExpr(400))));
        IStmt a5=new CompStmt(new LockStmt("x"),new CompStmt(new PrintStmt(new RH("v1")),new CompStmt(new UnlockStmt("x"),new CompStmt(new LockStmt("q"),new CompStmt(new PrintStmt(new RH("v2")),new UnlockStmt("q"))))));
        IStmt expr11=new CompStmt(a1,new CompStmt(a2,new CompStmt(a3,new CompStmt(a4,a5))));
        ExeStack11.add(expr11);
        ProgramState prgCurrent11 = new ProgramState(ExeStack11, SymTable11, out11,fileTable11,heap11,lock11);
        prgCurrent11.setMylock(mylock);
        IRepo repo11 = new Repository();
        repo11.addPrg(prgCurrent11);
        Controller ctrl11 = new Controller(repo11);

        List<String> mylist=new ArrayList<String>();
        mylist.add(expr1.toString());
        mylist.add(expr2.toString());
        mylist.add(expr3.toString());
        mylist.add(expr4.toString());
        mylist.add(expr5.toString());
        mylist.add(expr6.toString());
        mylist.add(expr7.toString());
        mylist.add(expr8.toString());
        mylist.add(expr9.toString());
        mylist.add(expr10.toString());
        mylist.add(expr11.toString());

        ObservableList<String> exp=FXCollections.observableList(mylist);
        this.MenuList.setItems(exp);
        this.MenuList.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        this.MenuList.getSelectionModel().selectIndices(0);
        this.menu.add(ctrl1);
        this.menu.add(ctrl2);
        this.menu.add(ctrl3);
        this.menu.add(ctrl4);
        this.menu.add(ctrl5);
        this.menu.add(ctrl6);
        this.menu.add(ctrl7);
        this.menu.add(ctrl8);
        this.menu.add(ctrl9);
        this.menu.add(ctrl10);
        this.menu.add(ctrl11);
        this.selected=true;
        this.id=1;
        this.totalProcesses=0;
        ExecutorService e= Executors.newFixedThreadPool(2);
        this.controller.setExecutor(e);
        this.progList=new ArrayList<>();
        this.progList=controller.removeCompletedPrg(controller.getRepo().getPrgList());
        this.controller.setPrglist(progList);
        this.oneStep();
    }
}
