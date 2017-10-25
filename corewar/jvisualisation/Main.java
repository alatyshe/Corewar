import ui.Sound;
import java.io.*;

public class Main {

	public static String	dirPath;

	public static void main(String[] args) throws Exception {

		String myJarPath = Main.class.getProtectionDomain().getCodeSource().getLocation().getPath();
		dirPath = myJarPath.substring(0, myJarPath.lastIndexOf('/') + 1);
		try {
			Sound		sound = null;

			try {
				sound = new Sound(new File(dirPath + "resources/Bit_Rush_Arcade_Ahri.wav"));
				sound.play(true);
			}
			catch (Exception e) {
				System.out.println("Music not found");
			}

			CoreFrame	coreFrame = CoreFrame.getInstance(sound);
			coreFrame.createFrame();
		}
		catch (Exception e) {
			System.out.println("ERROR");
			System.out.println(e);
		}
	}
}
