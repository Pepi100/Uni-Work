package model.user;

public class Employee extends User{

    private String department;
    private int employee_id;

    //getters
    public String getDepartment() {
        return department;
    }

    public int getEmployee_id() {
        return employee_id;
    }

    //setters
    public void setDepartment(String department) {
        this.department = department;
    }

    public void setEmployee_id(int employee_id) {
        this.employee_id = employee_id;
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
