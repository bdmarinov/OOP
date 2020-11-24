public class Student
{
  
  public Student(int n_fNumber, String n_name, int n_grade)
  {
    setFNumber(n_fNumber);
    setName(n_name);
    setGrade(n_grade);
  }

  public void setFNumber(int n_fNumber)
  {
    fNumber = n_fNumber >= 0 ? n_fNumber : 0;
  }

  public void setName(String n_name)
  {
    name = n_name;
  }

  public void setGrade(int n_grade)
  {
    grade = (n_grade >= 0 && n_grade <= 6) ? n_grade : 2;
  }


  public int getFNumber()
  {
    return fNumber;
  }

  public String getName()
  {
    return name;
  }

  public int getGrade()
  {
    return grade;
  }

  private int fNumber;
  private String name;
  private int grade;
}