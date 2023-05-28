package service;

import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Audit
{
    private static Audit instance;
    private static FileWriter writer;
    private static DateTimeFormatter formatter;

    public static void log(String action){
        try {
            writer.append(action);
            writer.append(",");
            writer.append(formatter.format(LocalDateTime.now()));
            writer.append("\n");
            writer.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }


//    singleton

    private  Audit(){
        try{
            writer  = new FileWriter("audit.csv");
            formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        }catch (Exception e){
            System.out.println("Couldn`t open file for audit");
        }
    }

    public static Audit getInstance() {
        if (instance == null) {
            instance = new Audit();
        }
        return instance;
    }

    public static void setFilePath(){

    }

}
