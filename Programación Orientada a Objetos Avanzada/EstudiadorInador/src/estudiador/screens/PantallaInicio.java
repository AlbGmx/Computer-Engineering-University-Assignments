/*
 * This is an academic project.
 */
package estudiador.screens;
import java.awt.BorderLayout;
import javax.swing.*;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import estudiador.common.ImageHandler;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;

/**
 *
 * @author Devas
 */
public class PantallaInicio extends JPanel{
    StartScreen parentFrame;
    
    private final javax.swing.JButton btnMatrix;
    private final javax.swing.JButton btnProgra;
    private final javax.swing.JButton btnSignal;
    private final javax.swing.JMenu jMenu1;
    private final javax.swing.JMenu jMenu2;
    private final javax.swing.JPanel pnTitle;
    private final javax.swing.JMenuBar mnuPrinc;
    private final javax.swing.JPanel pnIcon;
    private final javax.swing.JPanel pnMatrix;
    private final javax.swing.JPanel pnProgra;
    private final javax.swing.JPanel pnSignals;
    private final javax.swing.JPanel pnNombre;
    @Override
    public void paintComponent(Graphics g) {
        try {
            BufferedImage img = ImageIO.read(new File("./contentFiles/Images/fullBackground.jpg"));
                g.drawImage(img, 0, 0, null);
        }   catch (IOException ex) {
            Logger.getLogger(PantallaInicio.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    public PantallaInicio(StartScreen parentFrame) {
        this.parentFrame = parentFrame;
        pnIcon = new javax.swing.JPanel();
        pnNombre = new javax.swing.JPanel();
        pnTitle = new javax.swing.JPanel();
        pnSignals = new javax.swing.JPanel();
        pnProgra = new javax.swing.JPanel();
        pnMatrix = new javax.swing.JPanel();
        btnSignal = new javax.swing.JButton();
        btnProgra = new javax.swing.JButton();
        btnMatrix = new javax.swing.JButton();
        mnuPrinc = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenu2 = new javax.swing.JMenu();
        

        //pnIcon.setBorder(javax.swing.BorderFactory.createLineBorder(null));
        pnIcon.setLayout(new BorderLayout());
        pnIcon.add(ImageHandler.getPaneImage("./contentFiles/Images/logo_double.png"));
        
        pnNombre.setPreferredSize(new Dimension(585,244));
        pnNombre.setLayout(new BorderLayout());
        pnNombre.add(ImageHandler.getPaneImage("./contentFiles/Images/nombre.png"));
        
        pnSignals.setPreferredSize(new Dimension(270, 244));
        pnProgra.setPreferredSize(new Dimension(270, 244));
        pnMatrix.setPreferredSize(new Dimension(270, 244));
        pnSignals.setLayout(new BorderLayout());
        pnSignals.add(ImageHandler.getPaneImage("./contentFiles/Images/functions2.png"));
        pnProgra.removeAll();
        pnProgra.setLayout(new BorderLayout());
        pnProgra.add(ImageHandler.getPaneImage("./contentFiles/Images/programacion.png."));
        pnMatrix.setLayout(new BorderLayout());
        pnMatrix.add(ImageHandler.getPaneImage("./contentFiles/Images/matrix.png."));

        btnSignal.setText("Señales");
        btnSignal.addActionListener((ActionEvent e) -> {
            parentFrame.insertContent(new PantallaSignal(parentFrame));
        });

        btnProgra.setText("Programación");
        btnProgra.addActionListener((ActionEvent e) -> {
            parentFrame.insertContent(new PantallaProga(parentFrame));
        });

        btnMatrix.setText("Matrices");
        btnMatrix.addActionListener((ActionEvent e) -> {
            parentFrame.insertContent(new PantallaMatrix(parentFrame));
        });

        javax.swing.GroupLayout thisLayout = new javax.swing.GroupLayout(this);
        this.setLayout(thisLayout);
        thisLayout.setHorizontalGroup(thisLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(thisLayout.createSequentialGroup()
                .addGap(33, 33, 33)
                .addGroup(thisLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(pnIcon, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(pnSignals, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(31, 31, 31)
                .addGroup(thisLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(thisLayout.createSequentialGroup()
                        .addComponent(pnProgra, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(31, 31, 31)
                        .addComponent(pnMatrix, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(pnNombre, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, thisLayout.createSequentialGroup()
                .addGap(133, 133, 133)
                .addComponent(btnSignal)
                .addGap(219, 219, 219)
                .addComponent(btnProgra)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 180, Short.MAX_VALUE)
                .addComponent(btnMatrix)
                .addGap(140, 140, 140))
        );
        thisLayout.setVerticalGroup(thisLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(thisLayout.createSequentialGroup()
                .addGap(33, 33, 33)
                .addGroup(thisLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(pnIcon, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(pnNombre, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(47, 47, 47)
                .addGroup(thisLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(pnProgra, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(pnSignals, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(pnMatrix, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(thisLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnMatrix)
                    .addComponent(btnSignal)
                    .addComponent(btnProgra))
                .addContainerGap(41, Short.MAX_VALUE))
        );
        
    }
}
