package sample.TableViews;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.util.List;

public class BarrierTableView {
    private SimpleListProperty<Integer> list;
    private SimpleIntegerProperty lk;
    private SimpleIntegerProperty lv;

    public BarrierTableView(Integer lk, Integer lv, List<Integer> list){
        this.lk=new SimpleIntegerProperty(lk);
        this.lv=new SimpleIntegerProperty(lv);
        this.list=new SimpleListProperty<Integer>(FXCollections.observableList(list));
    }

    public SimpleIntegerProperty lkProperty() {
        return lk;
    }

    public SimpleIntegerProperty lvProperty() {
        return lv;
    }

    public SimpleListProperty<Integer> listProperty(){return list;}

    public void setList(List<Integer> list){
        this.list.set(FXCollections.observableList(list));
    }

    public void setLk(int address) {
        this.lk.set(address);
    }

    public void setLv(int value) {
        this.lv.set(value);
    }

    public int getLk(){return lk.get();}

    public int getLv(){return  lv.get();}
}
