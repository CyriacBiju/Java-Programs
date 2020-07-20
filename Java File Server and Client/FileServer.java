import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class FileServer extends Thread {
	
	private ServerSocket ss;
	
	public FileServer(int port) {
		try {
            ss = new ServerSocket(port);
            System.out.println("Server started.....");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void run() {
		while (true) {
			try {
                Socket clientSock = ss.accept();
				System.out.println("\nNew Client connected..");
				DataInputStream dis = new DataInputStream(clientSock.getInputStream());
				String option = dis.readUTF();
				if(option.equalsIgnoreCase("get")){
					sendFile(clientSock);
				}
				else{
					saveFile(clientSock);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	private void saveFile(Socket clientSock) throws IOException {
		DataInputStream dis = new DataInputStream(clientSock.getInputStream());
		String fileName = dis.readUTF();
		FileOutputStream fos = new FileOutputStream(fileName);
		byte[] buffer = new byte[4096];
		System.out.println("Saving file...");
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
        System.out.println("Read " + totalRead + " bytes.");
		System.out.println("File copied to Server");
		fos.close();
		dis.close();
	}
	
	private void sendFile(Socket clientSock) throws IOException{
		DataOutputStream dos = new DataOutputStream(clientSock.getOutputStream());
		DataInputStream dis = new DataInputStream(clientSock.getInputStream());
		String file = dis.readUTF();
        FileInputStream fis = new FileInputStream(file);
        long size;
        byte[] buffer = new byte[4096];
        try{
            File fileToSend = new File(file);
			size = fileToSend.length();
			dos.writeUTF("File Found");
			System.out.println("Sending file...");
            System.out.println("File size is "+ size);
            dos.writeLong(size);
            while (fis.read(buffer) > 0) {
                dos.write(buffer);
            }
        }
        catch(FileNotFoundException fnf){
			System.out.println(fnf);
			dos.writeUTF("File not Found");
        }
		
		fis.close();
		dos.close();	
	}

	public static void main(String[] args) {
		FileServer fs = new FileServer(5050);
		fs.start();
	}

}