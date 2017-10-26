import enums.FieldSize;
import ui.MyColors;
import ui.Sound;
import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class CoreFrame {

	private static CoreFrame	coreFrame = null;
	private static boolean		stopped = true;
	private static int			itersPerSec = 10;
	private static Sound		sound;
	private static String		winner = null;
	private GameField			field;
	private static boolean		stepIn = false;
	private static boolean		pianoMod = false;
	private static boolean		soundOn = false;

	private CoreFrame() throws Exception {

	}

	public static CoreFrame	getInstance(Sound sound) throws Exception {

		if (CoreFrame.coreFrame == null)
			CoreFrame.coreFrame = new CoreFrame();
		CoreFrame.sound = sound;
		return (CoreFrame.coreFrame);
	}

	public void createFrame() throws Exception {

		Dimension sSize = Toolkit.getDefaultToolkit().getScreenSize();
		JFrame frame = new JFrame("CoreWar");
		frame.setLocation(sSize.width / 8, sSize.height / 40);
		frame.setSize(new Dimension(1920, 1180));
		frame.setMinimumSize(new Dimension(1920, 1180));
		frame.setMaximumSize(new Dimension(sSize.width, 1180));
		frame.setResizable(true);
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		Container container = frame.getContentPane();
		frame.addKeyListener(new KeyListener() {
			public void keyTyped(KeyEvent e) {

			}

			public void keyPressed(KeyEvent e) {

				if (e.getKeyCode() == 32 && !CoreFrame.stopped)
					CoreFrame.stopped = true;
				else if (e.getKeyCode() == 32 && CoreFrame.stopped)
					CoreFrame.stopped = false;

				if (e.getKeyCode() == 67) {
					CoreFrame.pianoMod = !CoreFrame.pianoMod;
				}

				if (CoreFrame.sound != null) {
					if (e.getKeyChar() == 's' && CoreFrame.sound.isPlaying()) {
						CoreFrame.sound.stop();
						CoreFrame.soundOn = false;
					}
					else if (e.getKeyChar() == 's' && !CoreFrame.sound.isPlaying()) {
						CoreFrame.sound.play();
						CoreFrame.soundOn = true;
					}
				}

				if (!CoreFrame.stopped) {
					if (e.getKeyCode() == 107 && CoreFrame.itersPerSec > 9 && CoreFrame.itersPerSec < 100)
						CoreFrame.itersPerSec += 10;
					else if (e.getKeyCode() == 107 && CoreFrame.itersPerSec > 99 && CoreFrame.itersPerSec < 1000)
						CoreFrame.itersPerSec += 100;
					else if (e.getKeyCode() == 107 && CoreFrame.itersPerSec > 999 && CoreFrame.itersPerSec < 2000)
						CoreFrame.itersPerSec += 1000;

					if (e.getKeyCode() == 109 && CoreFrame.itersPerSec > 10 && CoreFrame.itersPerSec <= 100)
						CoreFrame.itersPerSec -= 10;
					else if (e.getKeyCode() == 109 && CoreFrame.itersPerSec > 100 && CoreFrame.itersPerSec <= 1000)
						CoreFrame.itersPerSec -= 100;
					else if (e.getKeyCode() == 109 && CoreFrame.itersPerSec > 100 && CoreFrame.itersPerSec <= 2000)
						CoreFrame.itersPerSec -=1000;
				}
				else {
					if (e.getKeyCode() == 107)
						CoreFrame.stepIn = true;
				}
			}

			public void keyReleased(KeyEvent e) {

			}
		});

		try {
			int i = 0;
			String	playersData;
			Player[]	players = new Player[4];
			playersData = GameField.reader.readLine();
			String[]	playersList = playersData.split(";");

			for (String playerInfo : playersList) {

				String[]	info = playerInfo.split(":");
				players[i] = new Player(info[2], Integer.parseInt(info[0]), Integer.parseInt(info[1]));
				i++;
			}
			GameField	gameField = new GameField(frame, players);
			this.field = gameField;
			container.add(gameField);
			frame.setVisible(true);

			new Thread(() -> {

				try{
					CoreFrame.coreFrame.runBattle(CoreFrame.coreFrame.field);
				}
				catch (Exception e) { System.out.println("ERROR"); }
			}).start();
		}
		catch (IOException e) { System.out.println("ERROR"); }
	}

	private void	setPlayers(GameField gameField) throws Exception {

		int		count = 0;

		while (count < gameField.players.length && gameField.players[count] != null)
			count++;
		if (count == 1) {
			gameField.players[0].startingCell = 0;
		}
		else if (count == 2) {
			gameField.players[0].startingCell = 0;
			gameField.players[1].startingCell = 4096 / 2;
		}
		else if (count == 3) {
			gameField.players[0].startingCell = 0;
			gameField.players[1].startingCell = 4096 / 3;
			gameField.players[2].startingCell = 4096 * 2 / 3;
		}
		else if (count == 4) {
			gameField.players[0].startingCell = 0;
			gameField.players[1].startingCell = 4096 / 4;
			gameField.players[2].startingCell = 4096 * 2 / 4;
			gameField.players[3].startingCell = 4096 * 3 / 4;
		}
	}

	private void	runBattle(GameField gameField) throws Exception {

		int k = 0;

		String		fieldInput = GameField.reader.readLine();
		String[]	startingField = fieldInput.split(" ");

		for (String point : startingField) {

			gameField.gameField.get(k).data = point;
			k++;
		}
  		this.setPlayers(gameField);

		for (Player currentPlayer : gameField.players) {

			if (currentPlayer != null)
				for (int i = currentPlayer.startingCell; i < currentPlayer.startingCell + currentPlayer.length; i++)
					gameField.gameField.get(i).player = currentPlayer.id;
		}

		while (gameField.updateField() != 0) {

			if (CoreFrame.sound != null && !CoreFrame.sound.isPlaying() && CoreFrame.soundOn)
				CoreFrame.sound.play();
			try {
				new Thread(gameField::repaint).start();
				while (CoreFrame.stopped) {if (CoreFrame.stepIn) break;Thread.sleep(1); }
				CoreFrame.stepIn = false;
				Thread.sleep(1000 / itersPerSec);
				if (gameField.cyclesLeft != 0) {
					for (int j = 0; j < 4096; j++) {

						PlacePoint	placePoint = gameField.gameField.get(j);

						if (CoreFrame.itersPerSec < 51)
							placePoint.playSound();
						placePoint.isExecuting = false;
						placePoint.setWritten(false);
						placePoint.carret = 0;
					}
				}
				if (gameField.cyclesLeft != gameField.cyclesToDie)
					gameField.cycles++;
				if (gameField.cyclesLeft > 0)
					gameField.cyclesLeft--;
			}
			catch (Exception e) { System.out.println("ERROR"); }
		}
		System.out.println("Contestant, " + winner + " has won!");
		try { Thread.sleep(60000); }
		catch (InterruptedException ie) { System.out.println("ERROR"); }
		System.exit(0);
	}

	private static class Player {

		private String		name;
		private int			id = 0;
		private long		live = 0;
		private long		processes = 0;
		private int			length;
		private int			startingCell;
		private boolean		isWinner = false;

		private Player(String name, int id, int length) throws Exception {
			this.name = name;
			this.id = id;
			this.length = length;
		}

		private Color	getColor() throws Exception {

			switch (Math.abs(this.id)) {
				case 0 : return (Color.gray);
				case 1 : return (MyColors.player1Data);
				case 2 : return (MyColors.player2Data);
				case 3 : return (MyColors.player3Data);
				case 4 : return (MyColors.player4Data);
			}
			return (Color.gray);
		}
	}

	private static class PlacePoint {

		private int		player;
		private String	data;
		private int		carret = 0;
		private boolean	isExecuting = false;
		private boolean	isWritten = false;
		private int		writeDelay;
		private Sound	sound;
		private boolean	isSoundPlayed = false;

		private PlacePoint(int player, String data, Sound sound) throws Exception {
			this.player = player;
			this.data = data;
			this.sound = sound;
		}

		private Color	getColor(int c, boolean written) throws Exception {

			switch (c) {
				case 0 : return (Color.gray);
				case 1 : return (written ? MyColors.player1Execution : MyColors.player1Data);
				case 2 : return (written ? MyColors.player2Execution : MyColors.player2Data);
				case 3 : return (written ? MyColors.player3Execution : MyColors.player3Data);
				case 4 : return (written ? MyColors.player4Execution : MyColors.player4Data);
			}
			return (Color.gray);
		}

		private void setWritten(boolean written) throws Exception {

			if (written) {
				this.isWritten = true;
				this.writeDelay = 50;
			}
			else {
				if (this.writeDelay > 0)
					this.writeDelay--;
				else
					this.isWritten = false;
			}
		}

		private void	playSound() throws Exception {

			if (!CoreFrame.pianoMod)
				return;
			if (carret == 0 && this.isSoundPlayed)
				this.isSoundPlayed = false;
			if (this.carret != 0 && !this.isSoundPlayed) {
				this.sound.play();
				this.isSoundPlayed = true;
			}
		}
	}

	private static class GameField extends JPanel {

		private int								fieldWidth = FieldSize.SIZE / FieldSize.ROWS;
		private int								fieldHeight = FieldSize.SIZE / fieldWidth;
		private int								frameWidth;
		private int								cellSize = 14;
		private int								offsetSize = 18;
		private short							cyclesToDie;
		private short							nbrLive = 21;
		private short							cyclesDelta = 50;
		private long							cycles;
		private long							cyclesLeft;
		private JFrame							frame;
		private Player[]						players;
		private HashMap<Integer, PlacePoint>	gameField;
		private static BufferedReader			reader;

		static { try { GameField.reader = new BufferedReader(new InputStreamReader(System.in));}catch (Exception e){ System.out.println("ERROR"); }}

		public GameField(JFrame	frame, Player[] players) throws Exception {

			int	id = 0;
			this.frame = frame;
			this.frameWidth = this.frame.getWidth();
			this.players = players;
			this.gameField = new HashMap<>();
			this.cycles = 0;
			this.cyclesToDie = 1536;
			this.cyclesLeft = 1536;

			for (int i = 0; i < this.fieldHeight; i++) {
				int	k;
				for (k = 0; k < this.fieldWidth; k++) {
					this.gameField.put(id, new PlacePoint(0, "00", MySounds.allSounds[k]));
					id++;
				}
			}
		}

		private int		updateField() throws Exception {

			if (CoreFrame.winner != null)
				return (0);
			String		read = reader.readLine();
			long[]		check = new long[4];

			if (read == null)
				return (0);
			if (read.contains("has won")) {

				this.cyclesToDie = 0;
				this.cyclesLeft = 0;
				read = read.substring(0, read.indexOf(' '));
				int		winnerID = Integer.parseInt(read);
				for (Player winner : this.players) {
					if (winner.id == Math.abs(winnerID)) {
						CoreFrame.winner = winner.name;
						winner.isWinner = true;
						break;
					}
				}
				return (1);
			}

			String[]	serviceInfo = read.split(";");

			this.setProcesses(serviceInfo, check);

			for (int i = 0; i < 4; i++) {

				if (this.players[i] != null)
					this.players[i].processes = check[i];
			}
			return (1);
		}

		private void	setProcesses(String[] serviceInfo, long[] check) throws Exception {

			String[]	info;
			int			playerID;
			int			processPlace;
			int			commandLength;
			int			writingStart;
			int			writingLength;

			for (String process : serviceInfo) {

				try
				{
					info = process.split(":");
					playerID = Integer.parseInt(info[0]);
					processPlace = Integer.parseInt(info[1]);
					commandLength = Integer.parseInt(info[2]);

					check[Math.abs(playerID) - 1]++;
					this.gameField.get(processPlace).carret = Math.abs(playerID);
					for (int i = 0; i < commandLength; i++) {

						this.gameField.get(processPlace + i).isExecuting = true;
					}

					if (info.length == 5) {

						if (info[3].equals("l")) {

							this.players[Math.abs(Integer.parseInt(info[4])) - 1].live = this.cycles;
						}
						else {
							writingStart = Integer.parseInt(info[3]);
							writingLength = Integer.parseInt(info[4]);
							StringBuilder	write = new StringBuilder(Integer.toHexString(writingLength));
							if (write.length() < 8)
								while (write.length() < 8)
									write = write.insert(0, '0');
							for (int i = 0; i < 4; i++) {

								int		cID;

								if (writingStart + i < 4096)
									cID = writingStart + i;
								else
									cID = writingStart + i - 4096;
								this.gameField.get(cID).data = write.substring(0, 2);
								write = new StringBuilder(write.substring(2, write.length()));
								this.gameField.get(cID).player = Math.abs(playerID);
								try { this.gameField.get(cID).setWritten(true); }
								catch (Exception e) { System.out.println("ERROR"); }
							}
						}
					}
				}
				catch (NumberFormatException e)
				{
					this.cyclesToDie = Short.parseShort(serviceInfo[0].substring(1, serviceInfo[0].length() - 1));
					if (this.cyclesToDie < 0)
						this.cyclesToDie = 0;
					this.cyclesLeft = this.cyclesToDie;
				}
				catch (NullPointerException ne)
				{
					info = process.split(":");
					playerID = Integer.parseInt(info[0]);
					processPlace = Integer.parseInt(info[1]);
					commandLength = Integer.parseInt(info[2]);

					System.out.println(playerID);
					System.out.println(processPlace);
					System.out.println(commandLength);
					if (info.length == 5) {
						writingStart = Integer.parseInt(info[3]);
						writingLength = Integer.parseInt(info[4]);
						System.out.println(writingStart);
						System.out.println(writingLength);
					}
				}

			}
		}

		protected void	paintComponent(Graphics g) {

			try {
				super.paintComponent(g);
				super.setBackground(Color.BLACK);
			}
			catch (Exception e) { System.out.println("ERROR"); }
			try {
				g.drawImage(new ImageIcon(Main.dirPath + "jvisualisation/resources/CoreWarLogo.jpg").getImage(), this.frameWidth * 5 / 6 + 7, 0, this.frame.getWidth() / 6, 200, null);
			}
			catch (Exception e) {
				System.out.println("Image not found");
			}
			try {
				this.drawSidebar(g);
				this.drawField(g);
			}
			catch (Exception e) { System.out.println("ERROR"); }
		}

		private void	drawPlayer(Player player, int n, Graphics g) throws Exception {

			if (player == null) {
				g.drawString("Player offline", this.frameWidth * 5 / 6 + 5, 220 + n);
				return;
			}

			g.setColor(player.getColor());
			g.drawString("Player " + -player.id + ": " + player.name, this.frameWidth * 5 / 6 + 5, 220 + n);
			g.drawString("Last live: " + player.live, this.frameWidth * 5 / 6 + 15, 240 + n);
			g.drawString("Processes: " + player.processes, this.frameWidth * 5 / 6 + 15, 260 + n);
			if (cyclesToDie == 0) {
				if (player.isWinner) {
					g.setColor(Color.green);
					g.drawString("--WINNER--", this.frameWidth * 5 / 6 + 15, 280 + n);
				}
				else {
					g.setColor(Color.red);
					g.drawString("__LOOSER__", this.frameWidth * 5 / 6 + 15, 280 + n);
				}
			}
			g.setColor(Color.red);
		}

		private void	drawSidebar(Graphics g) throws Exception {

			g.setFont(MyFonts.arcadeFont);
			for (int i = 0; i < 4; i++)
				this.drawPlayer(this.players[i], i * 100, g);
			g.setColor(Color.yellow);
			g.drawString("*******************************************************************************************************************************************************************", this.frameWidth * 5 / 6, 630);
			g.drawString("Cycles to die: " + this.cyclesToDie, this.frameWidth * 5 / 6 + 25, 660);
			g.drawString("Cycles delta: " + this.cyclesDelta, this.frameWidth * 5 / 6 + 25, 690);
			g.drawString("NBR_LIVE: " + this.nbrLive, this.frameWidth * 5 / 6 + 25, 720);
			g.drawString("Current Cycle: " + this.cycles, this.frameWidth * 5 / 6 + 25, 750);
			g.drawString("Cycles left: " + this.cyclesLeft, this.frameWidth * 5 / 6 + 25, 780);
			g.drawString("*******************************************************************************************************************************************************************", this.frameWidth * 5 / 6, 810);
			g.drawString("Cycles per second: ", this.frameWidth * 5 / 6 + 25, 870);
			if (CoreFrame.itersPerSec < 1001)
				g.drawString(String.valueOf(CoreFrame.itersPerSec), this.frameWidth * 5 / 6 + 235, 870);
			else
				g.drawString("native", this.frameWidth * 5 / 6 + 235, 870);
			if (CoreFrame.winner != null) {
				g.setColor(Color.red);
				g.drawString("--- GAME OVER ---", this.frameWidth * 5 / 6 + 55, 1020);
			}
			g.setFont(MyFonts.defaultFont);
		}

		private void	drawField(Graphics g) throws Exception {

			int		widthOffset = 5;
			int		heightOffset = 5;
			int		id = 0;

			g.setFont(MyFonts.defaultFontBold);
			for (int i = 0; i < this.fieldHeight; i++) {

				int	k;
				for (k = 0; k < this.fieldWidth; k++) {

					PlacePoint	placePoint = this.gameField.get(id);

					g.setColor(placePoint.getColor(placePoint.player, false));
					if (placePoint.isExecuting)
						g.setFont(MyFonts.defaultFontBold);
					else
						g.setFont(MyFonts.defaultFont);
					if (placePoint.isWritten)
						g.setColor(placePoint.getColor(placePoint.player, true));
					g.drawString(this.gameField.get(id).data, widthOffset + 3, heightOffset + 12);
					if (placePoint.carret != 0) {
						g.setColor(placePoint.getColor(placePoint.carret, true));
						g.drawRect(widthOffset, heightOffset, this.cellSize + 7, this.cellSize);
					}
					widthOffset += this.offsetSize + 7;
					id++;
				}
				widthOffset = 5;
				heightOffset += this.offsetSize;
			}
		}
	}
}
