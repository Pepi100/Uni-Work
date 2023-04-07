package model.user;

public class Employee extends User{

    private String department;

    //getters
    public String getDepartment() {
        return department;
    }

    //setters
    public void setDepartment(String department) {
        this.department = department;
    }


    //toString


    @Override
    public String toString() {
        return "Employee{" +
                "department='" + department + '\'' +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                '}';
    }
}
