
public class Matriz{
    int columns;
    int rows;
    public Matriz(int rows, int columns){
        setRows(rows);
        setColumns(columns);
    }
    public void setRows(int rows){
        this.rows = rows;
    }
    public void setColumns(int columns){
        this.columns = columns;
    }
    public int getRows(){
        return rows;
    }
    public int getColumns(){
        return columns;
    }
}