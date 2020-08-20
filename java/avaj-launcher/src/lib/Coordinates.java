package src.lib;

public class Coordinates {
    private int longitude;
    private int latitude;
    private int height;

    static int maxHeight = 100;
    static int minHeight = 0;

    public Coordinates(int longitude, int latitude, int height) {
        this.longitude = longitude;
        this.latitude = latitude;
        this.setHeight(height);
    }

    public void add(Coordinates coordinates) {
        this.latitude = this.getLatitude() + coordinates.getLatitude();
        this.longitude = this.getLongitude() + coordinates.getLongitude();
        this.setHeight(this.getHeight() + coordinates.getHeight());
    }

    public void setHeight(int myHeight) {
        if (myHeight > maxHeight) {
            this.height = maxHeight;
        } else {
            this.height = myHeight;
        }
    }

    public int getLatitude() {
        return this.latitude;
    }

    public int getLongitude() {
        return this.longitude;
    }

    public int getHeight() {
        return this.height;
    }

    public int sum() {
        return this.height + this.longitude + this.latitude;
    }
}
