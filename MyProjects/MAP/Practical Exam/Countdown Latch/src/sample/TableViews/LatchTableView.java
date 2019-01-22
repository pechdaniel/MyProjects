package sample.TableViews;

import javafx.beans.property.SimpleIntegerProperty;

public class LatchTableView {
    private SimpleIntegerProperty lk;
    private SimpleIntegerProperty lv;

    public LatchTableView(Integer lk,Integer lv){
        this.lk=new SimpleIntegerProperty(lk);
        this.lv=new SimpleIntegerProperty(lv);
    }

    public SimpleIntegerProperty lkProperty() {
        return lk;
    }

    public SimpleIntegerProperty lvProperty() {
        return lv;
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
