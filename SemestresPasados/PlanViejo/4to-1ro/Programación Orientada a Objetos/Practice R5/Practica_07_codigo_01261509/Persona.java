public class  Persona{
    String name = "";
    String firstLastName = "";
    String secondLastName = "";
    String personaRFC = "";
    int year;
    int month;
    int day;

    public Persona(String name, String firstLastName, String secondLastName, int year, int month, int day){
        setName(name.toUpperCase());
        setFirstLastName(firstLastName.toUpperCase());
        setSecondLastName(secondLastName.toUpperCase());
        setYear(year);
        setMonth(month);
        setDay(day);
        setPersonaRFC(RFC.generateRFC(name.toUpperCase(), firstLastName.toUpperCase(), secondLastName.toUpperCase(), year, month, day));
    }

    public void setPersonaRFC(String rfc){
        this.personaRFC = rfc;
    }

    public String getPersonaRFC(){
        return personaRFC;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setFirstLastName(String lastName){
        this.firstLastName = lastName;
    }

    public void setSecondLastName(String lastName){
        this.secondLastName = lastName;
    }

    public void setYear(int year){
        this.year = year;
    }

    public void setMonth(int month){
        this.month = month;
    }

    public void setDay(int day){
        this.day = day;
    }

    public String getName(){
        return name;
    }

    public String getFirstLastName(){
        return firstLastName;
    }

    public String getSecondLastName(){
        return secondLastName;
    }

    public int getYear(){
        return year;
    }

    public int getMonth(){
        return month;
    }
    
    public int getDay(){
        return day;
    }
}