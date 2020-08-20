package src;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import src.flyables.AircraftFactory;
import src.lib.IO;
import src.weather_tower.WeatherTower;

public class Application {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Error: accept one and only one argument");
            return;
        }
        String file = args[0];
        String[] data;
        String line;
        WeatherTower weatherTower = new WeatherTower();
        int simulationCount;
        IO output = new IO();

        if (!output.createFile()) {
            return;
        }
        
        File myObj = new File(file);
        try (
            Scanner myReader = new Scanner(myObj);
        ) {
            if (myReader.hasNextLine()) {
                try {
                    simulationCount = Integer.parseInt(myReader.nextLine());
                    if (simulationCount <= 0) {
                        System.out.println("line 1 need to be a positiv number");
                        return;
                    }
                } catch (NumberFormatException e) {
                    System.out.println(e.getMessage() + "is not a (integer) number");
                    return;
                }
            } else {
                System.out.println("Error: empty file");
                return;
            }

            AircraftFactory factory = new AircraftFactory();
            while (myReader.hasNextLine()) {
                line = myReader.nextLine();
                data = line.split(" ");
                if (data.length != 5) {
                    System.out.println("Error: in " + line);
                    return;
                }
                if (!factory.createAndRegisterFlyable(data, weatherTower)) {
                    return;
                }
            }
            weatherTower.simulate(simulationCount);
            output.writeFile();
        } catch (FileNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
