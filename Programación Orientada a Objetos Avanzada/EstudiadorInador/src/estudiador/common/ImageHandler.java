/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package estudiador.common;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.JPanel;

/**
 *
 * @author Devas
 */
public class ImageHandler {
    public static JPanel getPaneImage(String imgPath){
        BufferedImage image;
        JPanel pane; 
        try {
            image = ImageIO.read(new File(imgPath));
            pane = new JPanel(){
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.drawImage(image, 0, 0, null);
            }};
            return pane;
        } catch (IOException ex) {
            Logger.getLogger(ImageHandler.class.getName()).log(Level.SEVERE, null, ex);
        }
        return new JPanel();
    }
     public static BufferedImage getBuffImage(String imgPath){
        BufferedImage image;
        try {
            image = ImageIO.read(new File(imgPath));
            return image;
        } catch (IOException ex) {
            Logger.getLogger(ImageHandler.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }
    public static void writeImage(BufferedImage img, String route) throws IOException{
        FileOutputStream out = null;
        try {
            out = new FileOutputStream(new File(route));
            ImageIO.write(img, "png", out );
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ImageHandler.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                out.close();
            } catch (IOException ex) {
                Logger.getLogger(ImageHandler.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
