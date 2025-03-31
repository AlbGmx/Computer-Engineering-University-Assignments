  
public class Validations{
  //Enteros
  public static boolean validarCuadratura(MatrizInt m1, MatrizInt m2){
    if((m1.getRows() == m2.getRows()) && (m1.getColumns() == m2.getColumns()))
      return true;
    else return false;
  }
  public static boolean validarMultiplicabilidad(MatrizInt m1, MatrizInt m2) {
    if (m1.getColumns() == m2.getRows())
      return true;
    else
      return false;
  }
  public static boolean validarInversa(MatrizInt m1) {
    if (m1.getRows() == m1.getColumns() & MatOperations.detMat(m1) != 0)
      return true;
    else {
      return false;
    }
  }
  //Flotantes
  public static boolean validarCuadratura(MatrizFloat m1, MatrizFloat m2){
    if((m1.getRows() == m2.getRows()) && (m1.getColumns() == m2.getColumns()))
      return true;
    else return false;
  }
  public static boolean validarMultiplicabilidad(MatrizFloat m1, MatrizFloat m2){
    if(m1.getColumns() == m2.getRows())
      return true;
    else return false;
  }
  public static boolean validarInversa(MatrizFloat m1) {
    if (m1.getRows() == m1.getColumns() & MatOperations.detMat(m1) != 0)
      return true;
    else {
      return false;
    }
  }
  //Doubles
  public static boolean validarCuadratura(MatrizDouble m1, MatrizDouble m2) {
    if ((m1.getRows() == m2.getRows()) && (m1.getColumns() == m2.getColumns()))
      return true;
    else
      return false;
  }
  public static boolean validarInversa(MatrizDouble m1) {
    if (m1.getRows() == m1.getColumns() & MatOperations.detMat(m1) != 0)
      return true;
    else {
      return false;
    }
  }
  public static boolean validarMultiplicabilidad(MatrizDouble m1, MatrizDouble m2){
    if(m1.getColumns() == m2.getRows())
      return true;
    else return false;
  }
}
    