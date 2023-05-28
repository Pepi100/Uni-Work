package model.product;


public class Microphone extends Product {

    private CapsuleType capsule;

    private MicConnectivityType connectivity;

    private int microphone_id;


    //getters
    public CapsuleType getCapsule() {
        return capsule;
    }


    public MicConnectivityType getConnectivity() {
        return connectivity;
    }

    public int getMicrophone_id() {
        return microphone_id;
    }
//setters


    public void setMicrophone_id(int microphone_id) {
        this.microphone_id = microphone_id;
    }

    public void setConnectivity(MicConnectivityType connectivity) {
        this.connectivity = connectivity;
    }

    public void setCapsule(CapsuleType capsule) {
        this.capsule = capsule;
    }


    //toString


    @Override
    public String toString() {
        return "Microphone" +product_id +
                "   " + price +
                "   " + brand.getName() +
                "   " + name +
                "   " + capsule +
                "   " +connectivity;
    }
}
