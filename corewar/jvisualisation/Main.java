import ui.Sound;
import java.io.*;

public class Main {

	public static String	dirPath;

	public static void main(String[] args) throws Exception {

		try
		{
			String myJarPath = Main.class.getProtectionDomain().getCodeSource().getLocation().getPath();
			dirPath = myJarPath.substring(0, myJarPath.lastIndexOf('/') + 1);
		}
		catch(Exception e)
		{
			System.out.println("ERROR");
		}
		try {
			Sound		sound = null;

			try {
				sound = new Sound(new File(dirPath + "jvisualisation/resources/Bit_Rush_Arcade_Ahri.wav"));
			}
			catch (Exception e) {
				System.out.println("Music not found");
			}

			CoreFrame	coreFrame = CoreFrame.getInstance(sound);
			coreFrame.createFrame();
		}
		catch (Exception e) {
			System.out.println("ERROR");
		}
	}
}
