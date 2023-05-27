import service.Service;

import java.sql.*;

public class Main {
    public static void main(String[] args) throws SQLException {

        Service service = Service.getInstance();
        Service.run();


    }
}