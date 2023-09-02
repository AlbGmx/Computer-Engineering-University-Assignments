
public class MatOperations{
    
  public static MatrizInt transposeMat(MatrizInt m1){
    MatrizInt matTransp = new MatrizInt(m1.getColumns(), m1.getRows());
    for(int i=0; i<m1.rows; i++)
      for(int j=0; j<m1.columns; j++)
        matTransp.array[j][i] = m1.array[i][j];
    return matTransp;
  }
  public static MatrizInt addMat(MatrizInt m1, MatrizInt m2){
    MatrizInt matResult = new MatrizInt(m1.getRows(), m2.getColumns());
    for(int i=0; i<matResult.array.length; i++)
      for(int j=0; j<matResult.array[i].length; j++)
        matResult.array[i][j] = m1.array[i][j] + m2.array[i][j];
    return matResult;
  }
  public static MatrizInt substractMat(MatrizInt m1, MatrizInt m2){
    MatrizInt matResult = new MatrizInt(m1.getRows(), m2.getColumns());
    for(int i=0; i<matResult.array.length; i++)
      for(int j=0; j<matResult.array[i].length; j++)
        matResult.array[i][j] = m1.array[i][j] - m2.array[i][j];
    return matResult;
  }

  public static MatrizInt multiplyMat(MatrizInt m1, MatrizInt m2) {
    MatrizInt matResult = new MatrizInt(m1.getRows(), m2.getColumns());
    for (int i = 0; i < m1.array.length; i++) {
      for (int j = 0; j < m2.array[0].length; j++) {
        for (int k = 0; k < m1.array[0].length; k++) {
          matResult.array[i][j] += m1.array[i][k] + m2.array[k][j];
        }
      }
    }
    return matResult;
  }
  
  public static int detMat(MatrizInt m1) {
    if (m1.getColumns() != m1.getRows()) {
      return 0; 
    }
    int det = 0;
    int row = m1.getRows();
    int col = m1.getColumns();
    int sign = 1;
    if (row == 1 & col == 1) {
      return m1.array[0][0];
    }
    for (int column = 0; column < col; column++) {
      MatrizInt subMat = getSubMat(m1, column);
      det += (sign * m1.array[0][column] * detMat(subMat));
      sign *= -1;
    }
    return det;
  }

  public static MatrizInt getSubMat(MatrizInt m1, int column) {
    MatrizInt subMat = new MatrizInt(m1.getRows() - 1, m1.getColumns() - 1);
    int count = 0;
    for (int j = 0; j < m1.getColumns(); j++) {
      if (j == column)
        continue;
      for (int i = 1; i < m1.getRows(); i++) {
        subMat.array[i - 1][count] = m1.array[i][j];
      }
      count++;
    }
    return subMat;
  }

  public static MatrizInt getSubMat(MatrizInt m1, int row, int column) {
    MatrizInt subMat = new MatrizInt(m1.getRows() - 1, m1.getColumns() - 1);
    int count = 0;
    int count2 = 0;
    int sign = -1;
    for (int j = 0; j < m1.getColumns(); j++) {
      for (int i = 0; i < m1.getRows(); i++) {
        sign *= -1;
        if (i == row | j == column) {
          continue;
        } else {
          subMat.array[count2][count] = m1.array[i][j] * sign;
          count++;
          if (count % subMat.getRows() == 0) {
            count2++;
            count = 0;
          }
        }
      }
    }
    return subMat;
  }

  public static MatrizFloat inverseMat(MatrizInt m1) {
    MatrizFloat m2 = new MatrizFloat(m1.getRows(), m1.getColumns());
      for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getColumns(); j++) {
          m2.array[i][j] = m1.array[i][j];
        }
      }
    return scalarMultMat(transposeMat(getCofMat(m2)), 1 / detMat(m2));
  }

  public static MatrizInt scalarMultMat(MatrizInt m1, int esc) {
    MatrizInt res = new MatrizInt(m1.getRows(), m1.getColumns());
    for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getColumns(); j++) {
        res.array[i][j] = m1.array[i][j] * esc;
      }
    }

    return res;

  }

  public static MatrizInt getCofMat(MatrizInt m1) {
    MatrizInt cofMat = new MatrizInt(m1.getRows(), m1.getColumns());
    for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getColumns(); j++) {
        cofMat.array[i][j] = detMat(getSubMat(m1, i, j));
      }
    }
    return cofMat;
  }

  //Operaciones con flotantes
  public static MatrizFloat transposeMat(MatrizFloat m1){
    MatrizFloat matTransp = new MatrizFloat(m1.getColumns(), m1.getRows());
    for(int i=0; i<m1.rows; i++)
      for(int j=0; j<m1.columns; j++)
        matTransp.array[j][i] = m1.array[i][j];
    return matTransp;
  }
  public static MatrizFloat addMat(MatrizFloat m1, MatrizFloat m2){
    MatrizFloat matResult = new MatrizFloat(m1.getRows(), m2.getColumns());
    for(int i=0; i<matResult.array.length; i++)
      for(int j=0; j<matResult.array[i].length; j++)
        matResult.array[i][j] = m1.array[i][j] + m2.array[i][j];
    return matResult;
  }  
  public static MatrizFloat substractMat(MatrizFloat m1, MatrizFloat m2){
    MatrizFloat matResult = new MatrizFloat(m1.getRows(), m2.getColumns());
    for(int i=0; i<matResult.array.length; i++)
      for(int j=0; j<matResult.array[i].length; j++)
        matResult.array[i][j] = m1.array[i][j] - m2.array[i][j];
    return matResult;
  }
  
  public static MatrizFloat multiplyMat(MatrizFloat m1, MatrizFloat m2) {
    MatrizFloat matResult = new MatrizFloat(m1.getRows(), m2.getColumns());
    for (int i = 0; i < m1.array.length; i++) {
      for (int j = 0; j < m2.array[0].length; j++) {
        for (int k = 0; k < m1.array[0].length; k++) {
          matResult.array[i][j] += m1.array[i][k] + m2.array[k][j];
        }
      }
    }
    return matResult;
  }
  
  public static float detMat(MatrizFloat m1) {
    if (m1.getColumns() != m1.getRows()) {
      return 0;
    }
    float det = 0;
    int row = m1.getRows();
    int col = m1.getColumns();
    int sign = 1;
    if (row == 1 & col == 1) {
      return m1.array[0][0];
    }
    for (int column = 0; column < col; column++) {
      MatrizFloat subMat = getSubMat(m1, column);
      det += (sign * m1.array[0][column] * detMat(subMat));
      sign *= -1;
    }
    return det;
  }

  public static MatrizFloat getSubMat(MatrizFloat m1, int column) {
    MatrizFloat subMat = new MatrizFloat(m1.getRows() - 1, m1.getColumns() - 1);
    int count = 0;
    for (int j = 0; j < m1.getColumns(); j++) {
      if (j == column)
        continue;
      for (int i = 1; i < m1.getRows(); i++) {
        subMat.array[i - 1][count] = m1.array[i][j];
      }
      count++;
    }
    return subMat;
  }

  public static MatrizFloat getSubMat(MatrizFloat m1, int row, int column) {
    MatrizFloat subMat = new MatrizFloat(m1.getRows() - 1, m1.getColumns() - 1);
    int count = 0;
    int count2 = 0;
    int sign = -1;
    for (int j = 0; j < m1.getColumns(); j++) {
      for (int i = 0; i < m1.getRows(); i++) {
        sign *= -1;
        if (i == row | j == column) {
          continue;
        } else {
          subMat.array[count2][count] = m1.array[i][j] * sign;
          count++;
          if (count % subMat.getRows()== 0) {
            count2++;
            count = 0;
          }
        }
      }
    }
    return subMat;
  }

  public static MatrizFloat inverseMat(MatrizFloat m1) {
    return scalarMultMat(transposeMat(getCofMat(m1)), 1 / detMat(m1));
  }

  public static MatrizFloat scalarMultMat(MatrizFloat m1, float esc) {
    MatrizFloat res = new MatrizFloat(m1.getRows(), m1.getColumns());
    for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getColumns(); j++) {
        res.array[i][j] = m1.array[i][j] * esc;
      }
    }

    return res;

  }

  public static MatrizFloat getCofMat(MatrizFloat m1) {
    MatrizFloat cofMat = new MatrizFloat(m1.getRows(), m1.getColumns());
    for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getColumns(); j++) {
        cofMat.array[i][j] = detMat(getSubMat(m1, i, j));
      }
    }
    return cofMat;
  }

  //Operaciones con Doubles
  public static MatrizDouble transposeMat(MatrizDouble m1){
    MatrizDouble matTransp = new MatrizDouble(m1.getColumns(), m1.getRows());
    for(int i=0; i<m1.rows; i++)
      for(int j=0; j<m1.columns; j++)
        matTransp.array[j][i] = m1.array[i][j];
    return matTransp;
  }
  public static MatrizDouble addMat(MatrizDouble m1, MatrizDouble m2){
    MatrizDouble matResult = new MatrizDouble(m1.getRows(), m2.getColumns());
    for(int i=0; i<matResult.array.length; i++)
      for(int j=0; j<matResult.array[i].length; j++)
        matResult.array[i][j] = m1.array[i][j] + m2.array[i][j];
    return matResult;
  }  
  public static MatrizDouble substractMat(MatrizDouble m1, MatrizDouble m2){
    MatrizDouble matResult = new MatrizDouble(m1.getRows(), m2.getColumns());
    for(int i=0; i<matResult.array.length; i++)
      for(int j=0; j<matResult.array[i].length; j++)
        matResult.array[i][j] = m1.array[i][j] - m2.array[i][j];
    return matResult;
  }
  
  public static MatrizDouble multiplyMat(MatrizDouble m1, MatrizDouble m2) {
    MatrizDouble matResult = new MatrizDouble(m1.getRows(), m2.getColumns());
    for (int i = 0; i < m1.array.length; i++) {
      for (int j = 0; j < m2.array[0].length; j++) {
        for (int k = 0; k < m1.array[0].length; k++) {
          matResult.array[i][j] += m1.array[i][k] + m2.array[k][j];
        }
      }
    }
    return matResult;
  }
 
  public static Double detMat(MatrizDouble m1) {
    if (m1.getColumns() != m1.getRows()) {
      return (double)0;
    }
    double det = 0;
    int row = m1.getRows();
    int col = m1.getColumns();
    int sign = 1;
    if (row == 1 & col == 1) {
      return m1.array[0][0];
    }
    for (int column = 0; column < col; column++) {
      MatrizDouble subMat = getSubMat(m1, column);
      det += (sign * m1.array[0][column] * detMat(subMat));
      sign *= -1;
    }
    return det;
  }

  public static MatrizDouble getSubMat(MatrizDouble m1, int column) {
    MatrizDouble subMat = new MatrizDouble(m1.getRows() - 1, m1.getColumns() - 1);
    int count = 0;
    for (int j = 0; j < m1.getColumns(); j++) {
      if (j == column)
        continue;
      for (int i = 1; i < m1.getRows(); i++) {
        subMat.array[i - 1][count] = m1.array[i][j];
      }
      count++;
    }
    return subMat;
  }

  public static MatrizDouble getSubMat(MatrizDouble m1, int row, int column) {
    MatrizDouble subMat = new MatrizDouble(m1.getRows() - 1, m1.getColumns() - 1);
    int count = 0;
    int count2 = 0;
    int sign = -1;
    for (int j = 0; j < m1.getColumns(); j++) {
      for (int i = 0; i < m1.getRows(); i++) {
        sign *= -1;
        if (i == row | j == column) {
          continue;
        } else {
          subMat.array[count2][count] =(double) m1.array[i][j] * sign;
          count++;
          if (count % subMat.getRows() == 0) {
            count2++;
            count = 0;
          }
        }
      }
    }
    return subMat;
  }

  public static MatrizDouble inverseMat(MatrizDouble m1) {
    return scalarMultMat(transposeMat(getCofMat(m1)), 1 / detMat(m1));
  }

  public static MatrizDouble scalarMultMat(MatrizDouble m1, Double esc) {
    MatrizDouble res = new MatrizDouble(m1.getRows(), m1.getColumns());
    for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getColumns(); j++) {
        res.array[i][j] = m1.array[i][j] * esc;
      }
    }

    return res;

  }

  public static MatrizDouble getCofMat(MatrizDouble m1) {
    MatrizDouble cofMat = new MatrizDouble(m1.getRows(), m1.getColumns());
    for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getColumns(); j++) {
        cofMat.array[i][j] = detMat(getSubMat(m1, i, j));
      }
    }
    return cofMat;
  }

}