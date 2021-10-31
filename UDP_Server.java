import java.io.*;
import java.net.*;

public class UDPS {
	public static void main(String[] args) {
		DatagramSocket skt = null;
		try {
			skt = new DatagramSocket(6788);
			byte[] buffer = new byte[1000];
			while (true) {
				DatagramPacket request = new DatagramPacket(buffer,
						buffer.length);
				skt.receive(request);
				String[] message = (new String(request.getData())).split(" ");

				
				System.out.println("Received Client Request. Enter a message to be sent to Client>> ");
				BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		        String str = br.readLine();
				byte[] sendMsg = str.getBytes();

				DatagramPacket reply = new DatagramPacket(sendMsg,
						sendMsg.length, request.getAddress(), request.getPort());
				skt.send(reply);
			}
		} catch (Exception ex) {
		}
	}
}
