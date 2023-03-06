package Model;

public class Produs {
    String nume;
    float pret;

    public Produs(String nume, float pret) {
        this.nume = nume;
        this.pret = pret;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public float getPret() {
        return pret;
    }

    public void setPret(float pret) {
        this.pret = pret;
    }


    @Override
    public String toString() {
        return "Nume produs: " + nume + "\n" + "Pret: " + pret + " lei.\n";
    }
}
