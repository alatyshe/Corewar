import ui.Sound;
import java.io.File;

public class Main {

	public static void main(String[] args) throws Exception {

		try {
			Sound		sound = null;

			try {
				sound = new Sound(new File("resources/Bit_Rush_Arcade_Ahri.wav"));
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
