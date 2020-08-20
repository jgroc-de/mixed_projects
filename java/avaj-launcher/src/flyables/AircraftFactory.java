package src.flyables;

import src.lib.Coordinates;
import src.weather_tower.WeatherTower;

public class AircraftFactory {
    public Flyable newAircraft(
        String type,
        String name,
        int longitude,
        int latitude,
        int height
    ) throws IncorrectFlyableTypeException {
        Coordinates coordinate = new Coordinates(longitude, latitude, height);
        
        switch (type) {
            case "Helicopter":
                return new Helicopter(name, coordinate);
            case "Baloon":
                return new Balloon(name, coordinate);
            case "JetPlane":
                return new JetPlane(name, coordinate);
            default:
                throw new IncorrectFlyableTypeException("flyable type does not exist");
        }
    }

    public boolean createAndRegisterFlyable(String[] data, WeatherTower weatherTower) {
        Flyable flyable;
        int latitude;
        int longitude;
        int height;

        try {
            longitude = Integer.parseInt(data[2]);
            latitude =  Integer.parseInt(data[3]);
            height = Integer.parseInt(data[4]);
            flyable = this.newAircraft(
                    data[0],
                    data[1],
                    longitude,
                    latitude,
                    height
            );
            flyable.registerTower(weatherTower);
            return true;
        } catch (NumberFormatException e) {
            System.out.println("error:" + e.getMessage());
            return false;
        } catch (IncorrectFlyableTypeException e) {
            System.out.println("error:" + data[0] + ": " + e.getMessage());
            return false;
        }
    }
}
