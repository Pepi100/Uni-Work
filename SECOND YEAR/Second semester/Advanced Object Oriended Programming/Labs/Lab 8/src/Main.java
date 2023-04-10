import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Scanner;

public class Main {
//    public static void main(String[] args) throws IOException {
//        File file = new File("input.txt");
//
//        Path path = Path.of("input.txt");
//
//        file.createNewFile();
//
//        file.isFile();
//
//        file.isDirectory();
//
//
//        //scriere caracter cu caracter
//        Reader reader = new FileReader(file);
//        Writer writer = new FileWriter("output.txt");
//
//
//        //scriere byte cu byte -> pentru fisiere binare, imagini, etc
//        InputStream inputStream = new FileInputStream(file);
//        OutputStream outputStream = new FileOutputStream("Da.txt");
//
//        int i = reader.read();
//
//        while(i != -1){
//            writer.write(i);
//            i = reader.read();
//        }
//
//        reader.close();
//        writer.close();
////        inputStream.close();
////        outputStream.close();
//
//
//        BufferedInputStream bufferedInputStream = new BufferedInputStream(inputStream);
//
//        bufferedInputStream.readAllBytes();
//
//
//        String content = Files.readString(path);
//
//        //Files.writeString("content2.txt", "dsfgfrfhtjgyuhki");
//        Files.writeString(Path.of("content2.txt"), "dsfgfrfhtjgyuhki");
//
//
//
//        File  f = new File("safd")
//
//        //serializarea
//
////        ObjectOutputStream cos;
////
////        cos.writeObject();
//
//    }



    public static void main(String args[]) throws IOException {


        File f = new File("input.txt");
        Reader reader = new FileReader(f);

        File f2 = new File("output.txt");
        Writer writer = new FileWriter(f2);


        Scanner in = new Scanner(System.in);

        String s = in.nextLine();
        char chr = s.charAt(0);

        int i = reader.read();

        int count = 0;

        while(i != -1){
            if (i == chr){
                count++;
            }
            i = reader.read();
        }

        System.out.println(count);
//        writer.write(count);

        Files.writeString(Path.of("output.txt"), Integer.toString(count));
    }

}