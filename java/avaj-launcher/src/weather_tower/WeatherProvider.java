package src.weather_tower;

import src.lib.Coordinates;

public class WeatherProvider {
    private static WeatherProvider weatherSingleton;
    private static String[] weathers = {"SUN", "RAIN", "SNOW", "FOG"};

    private WeatherProvider() {
        //constructor
    }

    public static WeatherProvider getInstance() {
        if (weatherSingleton == null) {
            weatherSingleton = new WeatherProvider();
        }
        return weatherSingleton;
    }

    public String getCurrentWeather(Coordinates coordinates) {
        int sum;
        
        sum = coordinates.getHeight() + coordinates.getLatitude() + coordinates.getLongitude();
        return WeatherProvider.weathers[this.abs(sum) % 4];
    }

    private int abs(int sum) {
        if (sum < 0) {
            return -sum;
        }

        return sum;
    }
}
