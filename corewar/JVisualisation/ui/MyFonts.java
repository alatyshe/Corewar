package ui;

import javax.swing.*;
import java.awt.*;
import java.io.File;

public class MyFonts {

	public static final Font	defaultFont = UIManager.getFont("Label.font");
	public static final Font	defaultFontBold = new Font("Label.font", Font.BOLD, 13);
	public static Font 			arcadeFont;

	static {

		try {
//			arcadeFont = new Font(Font.createFont(Font.TRUETYPE_FONT, new File("/nfs/2016/v/vboiko/Downloads/CoreWarVisualizer/ui/ARCADECLASSIC.TTF")).getName(), Font.PLAIN, 40);
		arcadeFont = Font.createFont(Font.TRUETYPE_FONT, new File("resources/ConnectionSerif.otf")).deriveFont(Font.PLAIN, 20);
		}
		catch (Exception e) { System.out.println(e.toString()); }
	}
}
