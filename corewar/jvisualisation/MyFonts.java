import javax.swing.*;
import java.awt.*;
import java.io.File;

public class MyFonts {

	public static final Font	defaultFont = UIManager.getFont("Label.font");
	public static final Font	defaultFontBold = new Font("Label.font", Font.BOLD, 13);
	public static Font 			arcadeFont;

	static {
		try { arcadeFont = Font.createFont(Font.TRUETYPE_FONT, new File(Main.dirPath + "jvisualisation/resources/ConnectionSerif.otf")).deriveFont(Font.PLAIN, 20); }
		catch (Exception e) { System.out.println(e.toString()); }
	}
}
