package View.Command;

import Controller.Controller;

public class RunExample extends Command{
    private Controller contro;
    public RunExample(String key,String descr,Controller c){
        super(key,descr);
        this.contro=c;
    }

    @Override
    public void execute(){
        try{
            contro.allSteps();
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
