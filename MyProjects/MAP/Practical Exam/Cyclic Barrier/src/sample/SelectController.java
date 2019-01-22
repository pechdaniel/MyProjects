package sample;

import Controller.Controller;
import Model.Expressions.*;
import Model.Pair;
import Model.ProgramState;
import Model.Statements.*;
import Model.Utilities.*;
import Repository.IRepo;
import Repository.Repository;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class SelectController {
    @FXML private ListView<String> MenuList;
    private List<Controller> menu=new ArrayList<Controller>();
    public static Controller controller;
    public static Lock mylock;

    public static Lock getMylock(){return mylock;}

    @FXML
    public void runMe(){
        try{
            Integer k=this.MenuList.getSelectionModel().getSelectedIndex();
            this.controller=menu.get(k);
            Stage primaryStage=new Stage();
            Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
            primaryStage.setTitle("Program");
            primaryStage.setScene(new Scene(root, 970,579));
            primaryStage.initModality(Modality.APPLICATION_MODAL);
            primaryStage.show();}
        catch(Exception e){
            Alert a = new Alert(Alert.AlertType.ERROR, e.getMessage());
            a.show();
        }
    }

    @FXML
    public void initialize(){
        mylock=new ReentrantLock();
        IStack<IStmt> ExeStack1 = new Stack<>();
        IDictionary<String, Integer> SymTable1 = new Dictionary<String, Integer>();
        IList<Integer> out1 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable1=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap1=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Pair> barrier1=new Dictionary<>();
        IStmt expr1 = new CompStmt(new AssignStmt("v", new ConstExpr(2)),
                new PrintStmt(new VarExpr("v")));
        ExeStack1.add(expr1);
        ProgramState prgCurrent1 = new ProgramState(ExeStack1, SymTable1, out1,fileTable1,heap1,barrier1);
        prgCurrent1.setMylock(mylock);
        IRepo repo1 = new Repository();
        repo1.addPrg(prgCurrent1);
        Controller ctrl1 = new Controller(repo1);

        IStack<IStmt> ExeStack2 = new Stack<>();
        IDictionary<String, Integer> SymTable2 = new Dictionary<String, Integer>();
        IList<Integer> out2 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable2=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap2=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Pair> barrier2=new Dictionary<>();
        IStmt expr2 = new CompStmt(new AssignStmt("a", new ArithmExpr("+", new ConstExpr(2),
                new ArithmExpr("*", new ConstExpr(3), new ConstExpr(5)))), new CompStmt(new AssignStmt("b",
                new ArithmExpr("+", new VarExpr("a"), new ConstExpr(1))), new PrintStmt(new VarExpr("b"))));
        ExeStack2.add(expr2);
        ProgramState prgCurrent2 = new ProgramState(ExeStack2, SymTable2, out2,fileTable2,heap2,barrier2);
        prgCurrent2.setMylock(mylock);
        IRepo repo2 = new Repository();
        repo2.addPrg(prgCurrent2);
        Controller ctrl2 = new Controller(repo2);

        IStack<IStmt> ExeStack3 = new Stack<>();
        IDictionary<String, Integer> SymTable3 = new Dictionary<String, Integer>();
        IList<Integer> out3 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable3=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap3=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Pair> barrier3=new Dictionary<>();
        IStmt expr3 = new CompStmt(new AssignStmt("a", new ArithmExpr("-", new ConstExpr(2), new ConstExpr(2))),
                new CompStmt(new IfStmt(new VarExpr("a"), new AssignStmt("v", new ConstExpr(2)), new AssignStmt("v",
                        new ConstExpr(3))), new PrintStmt(new VarExpr("v"))));
        ExeStack3.add(expr3);
        ProgramState prgCurrent3 = new ProgramState(ExeStack3, SymTable3, out3,fileTable3,heap3,barrier3);
        prgCurrent3.setMylock(mylock);
        IRepo repo3 = new Repository();
        repo3.addPrg(prgCurrent3);
        Controller ctrl3 = new Controller(repo3);

        IStack<IStmt> ExeStack4 = new Stack<>();
        IDictionary<String, Integer> SymTable4 = new Dictionary<String, Integer>();
        IList<Integer> out4 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable4=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap4=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Pair> barrier4=new Dictionary<>();
        IStmt expr4=new CompStmt(
                new OpenRFileStmt("var_f","C:\\Users\\pechd\\IdeaProjects\\Exam\\Cyclic Barrier\\Example.txt"),new CompStmt(
                new ReadFileStmt(new VarExpr("var_f"),"var_c"),new CompStmt(
                new PrintStmt(new VarExpr("var_c")),new CompStmt(
                new IfStmt(new VarExpr("var_c")
                        ,new CompStmt(new ReadFileStmt(new VarExpr("var_f"),"var_c"),new PrintStmt(new VarExpr("var_c"))),new PrintStmt(new ConstExpr(0))),
                new CloseRFileStmt(new VarExpr("var_f"))))));
        ExeStack4.add(expr4);
        ProgramState prgCurrent4=new ProgramState(ExeStack4,SymTable4,out4,fileTable4,heap4,barrier4);
        prgCurrent4.setMylock(mylock);
        IRepo repo4=new Repository();
        repo4.addPrg(prgCurrent4);
        Controller ctrl4=new Controller(repo4);

        IStack<IStmt> ExeStack5 = new Stack<>();
        IDictionary<String, Integer> SymTable5 = new Dictionary<String, Integer>();
        IList<Integer> out5 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable5=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap5=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Pair> barrier5=new Dictionary<>();
        IStmt expr5 = new CompStmt(
                new AssignStmt("v",new ConstExpr(10)), new CompStmt(
                new New("v",new ConstExpr(20)),new CompStmt(
                new New("a",new ConstExpr(22)),new CompStmt(
                new WH("a",new ConstExpr(30)),new CompStmt(
                new PrintStmt(new VarExpr("a")),new CompStmt(
                new PrintStmt(new RH("a")),new AssignStmt("a",new ConstExpr(0))
        ))))));
        ExeStack5.add(expr5);
        ProgramState prgCurrent5=new ProgramState(ExeStack5,SymTable5,out5,fileTable5,heap5,barrier5);
        prgCurrent5.setMylock(mylock);
        IRepo repo5=new Repository();
        repo5.addPrg(prgCurrent5);
        Controller ctrl5=new Controller(repo5);

        IStack<IStmt> ExeStack6 = new Stack<>();
        IDictionary<String, Integer> SymTable6 = new Dictionary<String, Integer>();
        IList<Integer> out6 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable6=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap6=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Pair> barrier6=new Dictionary<>();
        IStmt expr6 = new CompStmt(new AssignStmt("v",new ConstExpr(7)),
                new CompStmt(new WhileStmt(new ArithmExpr("-",new VarExpr("v"),new ConstExpr(4)),new CompStmt(
                        new PrintStmt(new VarExpr("v")),new AssignStmt("v",new ArithmExpr("-",new VarExpr("v"),new ConstExpr(1)))
                )),new PrintStmt(new VarExpr("v"))));
        ExeStack6.add(expr6);
        ProgramState prgCurrent6 = new ProgramState(ExeStack6, SymTable6, out6,fileTable6,heap6,barrier6);
        prgCurrent6.setMylock(mylock);
        IRepo repo6 = new Repository();
        repo6.addPrg(prgCurrent6);
        Controller ctrl6 = new Controller(repo6);

        IStack<IStmt> ExeStack7 = new Stack<>();
        IDictionary<String, Integer> SymTable7 = new Dictionary<String, Integer>();
        IList<Integer> out7 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable7=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap7=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Pair> barrier7=new Dictionary<>();
        IStmt expr7 = new OpenRFileStmt("var_f","C:\\Users\\pechd\\IdeaProjects\\Exam\\Cyclic Barrier\\Example.txt");
        ExeStack7.add(expr7);
        ProgramState prgCurrent7 = new ProgramState(ExeStack7, SymTable7, out7,fileTable7,heap7,barrier7);
        prgCurrent7.setMylock(mylock);
        IRepo repo7 = new Repository();
        repo7.addPrg(prgCurrent7);
        Controller ctrl7 = new Controller(repo7);

        IStack<IStmt> ExeStack8 = new Stack<>();
        IDictionary<String, Integer> SymTable8 = new Dictionary<String, Integer>();
        IList<Integer> out8 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable8=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap8=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Pair> barrier8=new Dictionary<>();
        IStmt expr8 = new CompStmt(new AssignStmt("v",new ConstExpr(10)),new CompStmt(
                new New("a",new ConstExpr(22)),new CompStmt(
                new forkStmt(new CompStmt(new WH("a",new ConstExpr(30)),new CompStmt(
                        new AssignStmt("v",new ConstExpr(32)),new CompStmt(
                        new PrintStmt(new VarExpr("v")),new PrintStmt(new RH("a"))
                )))),new CompStmt(
                new PrintStmt(new VarExpr("v")),new PrintStmt(new RH("a"))
        ))));
        ExeStack8.add(expr8);
        ProgramState prgCurrent8 = new ProgramState(ExeStack8, SymTable8, out8,fileTable8,heap8,barrier8);
        prgCurrent8.setMylock(mylock);
        IRepo repo8 = new Repository();
        repo8.addPrg(prgCurrent8);
        Controller ctrl8 = new Controller(repo8);

        IStack<IStmt> ExeStack9 = new Stack<>();
        IDictionary<String, Integer> SymTable9 = new Dictionary<String, Integer>();
        IList<Integer> out9 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable9=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap9=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Pair> barrier9=new Dictionary<>();
        IStmt expr9 =new CompStmt( new AssignStmt("v",new ConstExpr(20)),new CompStmt(new ForStmt(new ConstExpr(0),new BooleanExpr("<",new VarExpr("v"),new ConstExpr(3)),new ArithmExpr("+",new VarExpr("v"),new ConstExpr(1)),new forkStmt(new CompStmt(new PrintStmt(new VarExpr("v")),new AssignStmt("v",new ArithmExpr("+",new VarExpr("v"),new ConstExpr(1)))))), new PrintStmt(new ArithmExpr("*",new VarExpr("v"),new ConstExpr(10)))));
        ExeStack9.add(expr9);
        ProgramState prgCurrent9 = new ProgramState(ExeStack9, SymTable9, out9,fileTable9,heap9,barrier9);
        prgCurrent9.setMylock(mylock);
        IRepo repo9 = new Repository();
        repo9.addPrg(prgCurrent9);
        Controller ctrl9 = new Controller(repo9);

        IStack<IStmt> ExeStack10 = new Stack<>();
        IDictionary<String, Integer> SymTable10 = new Dictionary<String, Integer>();
        IList<Integer> out10 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable10=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap10=new Dictionary<Integer, Integer>();
        IDictionary<Integer, Pair> barrier10=new Dictionary<>();
        IStmt expr10 =new CompStmt(new AssignStmt("v",new ConstExpr(0)),new RepeatUntilStmt(new CompStmt(new PrintStmt(new VarExpr("v")),new AssignStmt("v",new ArithmExpr("+",new VarExpr("v"),new ConstExpr(1)))),new BooleanExpr("==",new VarExpr("v"),new ConstExpr(3))));
        ExeStack10.add(expr10);
        ProgramState prgCurrent10 = new ProgramState(ExeStack10, SymTable10, out10,fileTable10,heap10,barrier10);
        prgCurrent10.setMylock(mylock);
        IRepo repo10 = new Repository();
        repo10.addPrg(prgCurrent10);
        Controller ctrl10 = new Controller(repo10);

        IStack<IStmt> ExeStack11 = new Stack<>();
        IDictionary<String, Integer> SymTable11 = new Dictionary<String, Integer>();
        IList<Integer> out11 = new MyList<Integer>();
        IDictionary<Integer, BufferedReader> fileTable11=new Dictionary<Integer, BufferedReader>();
        IDictionary<Integer, Integer> heap11=new Dictionary<Integer, Integer>();
        IDictionary<Integer,Pair> barrier11=new Dictionary<>();
        IStmt a1=new CompStmt(new New("v1",new ConstExpr(2)),new New("v2",new ConstExpr(3)));
        IStmt a2=new CompStmt(new New("v3",new ConstExpr(4)),new NewBarrierStmt("cnt",new RH("v2")));
        IStmt a3=new CompStmt(new forkStmt(new CompStmt(new AwaitStmt("cnt"),new WH("v1",new ArithmExpr("*",new RH("v1"),new ConstExpr(10))))),new PrintStmt(new RH("v1")));
        IStmt a4=new CompStmt(new forkStmt(new CompStmt(new AwaitStmt("cnt"),new WH("v2",new ArithmExpr("*",new RH("v2"),new ConstExpr(10))))),new CompStmt(new WH("v2",new ArithmExpr("*",new RH("v2"),new ConstExpr(10))),new PrintStmt(new RH("v2"))));
        IStmt a5=new CompStmt(new AwaitStmt("cnt"),new PrintStmt(new RH("v3")));
        IStmt a6=new CompStmt(new New("v1",new ConstExpr(2)),new CompStmt(new New("v2",new ConstExpr(3)),new CompStmt(new New("v3",new ConstExpr(4)),new CompStmt(new NewBarrierStmt("cnt",new RH("v2")),new CompStmt(new forkStmt(new CompStmt(new AwaitStmt("cnt"),new CompStmt(new WH("v1",new ArithmExpr("*",new RH("v1"),new ConstExpr(10))),new PrintStmt(new RH("v1"))))),new CompStmt(new forkStmt(new CompStmt(new AwaitStmt("cnt"),new CompStmt(new WH("v2",new ArithmExpr("*",new RH("v2"),new ConstExpr(10))),new CompStmt(new WH("v2",new ArithmExpr("*",new RH("v2"),new ConstExpr(10))),new PrintStmt(new RH("v2"))))) ),new CompStmt(new AwaitStmt("cnt"),new PrintStmt(new RH("v3")))))))));
        IStmt expr11=a6;
        ExeStack11.add(expr11);
        ProgramState prgCurrent11 = new ProgramState(ExeStack11, SymTable11, out11,fileTable11,heap11,barrier11);
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

        ObservableList<String> exp= FXCollections.observableList(mylist);
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

    }
}
