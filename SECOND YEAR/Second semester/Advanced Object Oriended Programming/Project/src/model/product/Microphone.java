package model.product;


public class Microphone extends Product {

    private CapsuleType capsule;

    private MicConnectivityType connectivity;


    //getters
    public CapsuleType getCapsule() {
        return capsule;
    }


    public MicConnectivityType getConnectivity() {
        return connectivity;
    }



    //setters
    public void setConnectivity(MicConnectivityType connectivity) {
        this.connectivity = connectivity;
    }

    public void setCapsule(CapsuleType capsule) {
        this.capsule = capsule;
    }


    //toString


    @Override
    public String toString() {
        return "Microphone{" +
                "connectivity=" + connectivity +
                ", price=" + price +
                ", brand=" + brand +
                ", name='" + name + '\'' +
                '}';
    }
}
