package model.product;


public class Headphones extends Product{

    private  ConnectivityType connectivity;
    private  FitType fit;
    private int headphones_id;

    //getters
    public ConnectivityType getConnectivity() {
        return connectivity;
    }

    public FitType getFit() {
        return fit;
    }

    public int getHeadphones_id() {
        return headphones_id;
    }

    //setters
    public void setConnectivity(ConnectivityType Connectivity) {
        this.connectivity = Connectivity;
    }

    public void setFit(FitType fit) {
        this.fit = fit;
    }

    public void setHeadphones_id(int headphones_id) {
        this.headphones_id = headphones_id;
    }

    @Override
    public String toString() {
        return "Headphones " +product_id +
                "   " + price +
                "   " + brand.getName() +
                "   " + name +
                "   " + fit +
                "   " +connectivity;
    }

}
