import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.Socket;

public class FileClient {
	
	private Socket s;
	
	public FileClient(String host, int port, String option, String file) {
		try {
            s = new Socket(host, port);
            DataOutputStream dos = new DataOutputStream(s.getOutputStream());
            dos.writeUTF(option);
            if(option.equalsIgnoreCase("send")){
                sendFile(file);
            }
			else{
                getFile(file);
            }
		} catch (Exception e) {
			e.printStackTrace();
		}		
	}
	
	public void sendFile(String file) throws IOException {
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        FileInputStream fis = new FileInputStream(file);
        long size;
        byte[] buffer = new byte[4096];
        dos.writeUTF(file);
        long startTime = System.nanoTime();
        try{
            File fileToSend = new File(file);
            size = fileToSend.length();
            System.out.println("File size is "+ size);
            dos.writeLong(size);
            while (fis.read(buffer) > 0) {
                dos.write(buffer);
            }
        }
        catch(FileNotFoundException fnf){
            System.out.println(fnf);
        }
		fis.close();
        dos.close();
        long endTime = System.nanoTime();
        long duration = endTime - startTime;
        System.out.println("Total time taken: " + Math.toIntExact(duration/1000000) + "ms");	
	}
    
    public void getFile(String file) throws IOException {
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        DataInputStream dis = new DataInputStream(s.getInputStream());
        FileOutputStream fos = new FileOutputStream(file);
        dos.writeUTF(file);
        long startTime = System.nanoTime();
        String filestatus = dis.readUTF();
        if(filestatus.equalsIgnoreCase("File Found")){
            byte[] buffer = new byte[4096];
            long filesize = dis.readLong(); // Send file size in separate msg
            int read = 0;
            long totalRead = 0;
            int remaining = buffer.length;
            while((read = dis.read(buffer, 0, remaining)) > 0) {
                totalRead += read;
                filesize -= read;
                fos.write(buffer, 0, read);
                if(Math.toIntExact(filesize) < remaining){
                    remaining = Math.toIntExact(filesize);
                }
            }
            System.out.println("Recieved " + totalRead + " bytes.");
            System.out.println("File " + file + " Recieved");
        }
        else{
            System.out.println("File " + file + " not found");
        }
		fos.close();
        dis.close();
        long endTime = System.nanoTime();
        long duration = endTime - startTime;
        System.out.println("Total time taken: " + Math.toIntExact(duration/1000000) + "ms");	
    }
    
	public static void main(String[] args) {
        if(args.length < 2){
            System.out.println("Usage: java FileClient get|send file");
            System.out.println("eg:java FileClient send video.mp4");
            System.exit(-1);
        }
        String option = args[0];
        String fileName = args[1];
		FileClient fc = new FileClient("localhost", 5050, option, fileName);
	}

}