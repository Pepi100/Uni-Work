package model.product;


public class Headphones extends Product{

    private  ConnectivityType Connectivity;
    private  FitType fit;

    //getters
    public ConnectivityType getConnectivity() {
        return Connectivity;
    }

    public FitType getFit() {
        return fit;
    }

    //setters
    public void setConnectivity(ConnectivityType Connectivity) {
        this.Connectivity = Connectivity;
    }

    public void setFit(FitType fit) {
        this.fit = fit;
    }


    @Override
    public String toString() {
        return "Headphones{" +
                "Connectivity=" + Connectivity +
                ", fit=" + fit +
                ", price=" + price +
                ", brand=" + brand +
                ", name='" + name + '\'' +
                '}';
    }
}
