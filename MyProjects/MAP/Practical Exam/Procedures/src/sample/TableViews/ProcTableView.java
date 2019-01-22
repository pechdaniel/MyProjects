package sample.TableViews;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;

import java.util.List;

public class ProcTableView {
    private SimpleListProperty<String > list;
    private SimpleStringProperty lk;
    private SimpleStringProperty lv;

    public ProcTableView(String lk,List<String> list, String lv){
        this.lk=new SimpleStringProperty(lk);
        this.lv=new SimpleStringProperty(lv);
        this.list=new SimpleListProperty<String >(FXCollections.observableList(list));
    }

    public SimpleStringProperty lkProperty() {
        return lk;
    }

    public SimpleStringProperty lvProperty() {
        return lv;
    }

    public SimpleListProperty<String> listProperty(){return list;}

    public void setList(List<String> list){
        this.list.set(FXCollections.observableList(list));
    }

    public void setLk(String address) {
        this.lk.set(address);
    }

    public void setLv(String value) {
        this.lv.set(value);
    }

    public String getLk(){return lk.get();}

    public String getLv(){return  lv.get();}
}
