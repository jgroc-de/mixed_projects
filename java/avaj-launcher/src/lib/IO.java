package src.lib;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class IO {
    static String name = "simulation.txt";
    static ArrayList<String> log = new ArrayList<>();

    public static void writeAndSave(String line) {
        System.out.println(line);
        IO.log.add(line);
    }

    public boolean createFile() {
        try {
            File myObj = new File(IO.name);
            if (!myObj.createNewFile() && myObj.delete()) {
                return this.createFile();
            }
        } catch (IOException e) {
            System.out.println(e.getMessage() + "An error occurred.");
            return false;
        }

        return true;
    }

    public void writeFile() {
        try (
                FileWriter myWriter = new FileWriter(IO.name);
        ) {
            for (String line: IO.log) {
                myWriter.append(line + "\n");
            }
        } catch (IOException e) {
            System.out.println(e.getMessage() + "An error occurred.");
            e.printStackTrace();
        }
    }
}