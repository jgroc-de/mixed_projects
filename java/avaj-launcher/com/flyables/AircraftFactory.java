package com.flyables;

import com.misc.Coordinates;
import com.misc.IncorrectFlyableTypeException;

public class AircraftFactory {
    public FlyableInterface newAircraft(
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
}